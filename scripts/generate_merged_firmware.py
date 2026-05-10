from __future__ import annotations

import os
import re
import shlex
import subprocess
from typing import Any

from SCons.Script import DefaultEnvironment  # type: ignore[import-untyped]

env: Any = DefaultEnvironment()


def get_project_option(name, default=None):
    try:
        value = env.GetProjectOption(name)
    except Exception:
        return default

    if value is None:
        return default

    if isinstance(value, str):
        value = env.subst(value).strip()
        if value == "":
            return default

    return value


def split_list(value):
    if value is None:
        return []
    if isinstance(value, (list, tuple)):
        return list(value)
    return [item.strip() for item in re.split(r"[,\s]+", str(value)) if item.strip()]


def sanitize_filename_part(value):
    return re.sub(r"[^A-Za-z0-9._-]+", "_", str(value)).strip("_")


def sanitize_project_name(value):
    return sanitize_filename_part(str(value).replace("-", "_"))


def normalize_version(value):
    value = str(value).strip()
    return value[1:] if value.startswith("v") else value


def read_version_from_file(path, pattern):
    with open(path, "r", encoding="utf-8") as f:
        content = f.read()

    match = re.search(pattern, content)
    if not match:
        raise RuntimeError(f"Version is not found in {path}")

    return normalize_version(match.group(1))


def resolve_version():
    explicit_version = get_project_option("custom_firmware_version")
    if explicit_version:
        return normalize_version(explicit_version)

    version_file = get_project_option("custom_firmware_version_file")
    if version_file:
        pattern = get_project_option(
            "custom_firmware_version_regex",
            r"v?(\d+\.\d+\.\d+(?:[-+][0-9A-Za-z.-]+)?)",
        )

        project_dir = env.subst("$PROJECT_DIR")
        src_dir = env.subst("$PROJECT_SRC_DIR")

        candidates = []
        if os.path.isabs(version_file):
            candidates.append(version_file)
        else:
            candidates.append(os.path.join(src_dir, version_file))
            candidates.append(os.path.join(project_dir, version_file))

        for candidate in candidates:
            if os.path.exists(candidate):
                return read_version_from_file(candidate, pattern)

        raise RuntimeError(f"Version file is not found: {version_file}")

    github_ref_name = os.environ.get("GITHUB_REF_NAME", "")
    match = re.match(r"^v?(\d+\.\d+\.\d+(?:[-+][0-9A-Za-z.-]+)?)$", github_ref_name)
    if match:
        return normalize_version(match.group(1))

    return "dev"


def resolve_chip():
    chip = get_project_option("custom_firmware_chip")
    if chip:
        return chip.lower().replace("-", "")

    chip = get_project_option("board_build.mcu")
    if chip:
        return chip.lower().replace("-", "")

    board_config = env.BoardConfig()
    chip = board_config.get("build.mcu", None)
    if chip:
        return str(chip).lower().replace("-", "")

    raise RuntimeError(
        "Could not determine chip type. "
        "Please set custom_firmware_chip, for example: custom_firmware_chip = esp32s3"
    )


def generate_merged_firmware(target, source, env):
    project_dir = env.subst("$PROJECT_DIR")
    build_dir = env.subst("$BUILD_DIR")
    pioenv = env.subst("$PIOENV")
    progname = env.subst("$PROGNAME")

    firmware_dir = get_project_option("custom_firmware_dir", "firmware")
    if not os.path.isabs(firmware_dir):
        firmware_dir = os.path.join(project_dir, firmware_dir)
    os.makedirs(firmware_dir, exist_ok=True)

    firmware_name = get_project_option(
        "custom_firmware_name",
        os.path.basename(project_dir),
    )
    firmware_target = get_project_option("custom_firmware_target")
    if firmware_target is None:
        firmware_target = env.subst("$PIOENV")
    firmware_suffix = get_project_option("custom_firmware_suffix", "bin")
    firmware_version = resolve_version()
    firmware_env = get_project_option("custom_firmware_env")
    if firmware_env is None:
        firmware_env = pioenv
    output_filename = "{name}_{env}_firmware_{version}.{suffix}".format(
        name=sanitize_project_name(firmware_name),
        env=sanitize_filename_part(firmware_env),
        version=sanitize_filename_part(firmware_version),
        suffix=sanitize_filename_part(firmware_suffix),
    )
    output_path = os.path.join(firmware_dir, output_filename)

    app_bin = os.path.join(build_dir, f"{progname}.{firmware_suffix}")

    if not os.path.exists(app_bin):
        raise RuntimeError(f"Application binary is not found: {app_bin}")

    extra_images = env.get("FLASH_EXTRA_IMAGES", [])
    if not extra_images:
        raise RuntimeError("FLASH_EXTRA_IMAGES is empty. Cannot build merged firmware.")

    chip = resolve_chip()

    cmd = [
        env.subst("$PYTHONEXE"),
        env.subst("$UPLOADER"),
        "--chip",
        chip,
        "merge_bin",
        "-o",
        output_path,
    ]

    flash_mode = get_project_option("custom_firmware_flash_mode")
    flash_freq = get_project_option("custom_firmware_flash_freq")
    flash_size = get_project_option("custom_firmware_flash_size")

    if flash_mode:
        cmd.extend(["--flash-mode", flash_mode])
    if flash_freq:
        cmd.extend(["--flash-freq", flash_freq])
    if flash_size:
        cmd.extend(["--flash-size", flash_size])

    for address, image in extra_images:
        cmd.extend([str(address), env.subst(image)])

    cmd.extend([env.subst("$ESP32_APP_OFFSET"), app_bin])

    print("Generating merged firmware:")
    print(" ".join(shlex.quote(part) for part in cmd))

    subprocess.check_call(cmd)

    print(f"Merged firmware generated: {output_path}")


firmware_suffix = get_project_option("custom_firmware_suffix", "bin")
app_bin = os.path.join("$BUILD_DIR", f"${{PROGNAME}}.{firmware_suffix}")

dependencies = [app_bin]
dependencies.extend(split_list(get_project_option("custom_firmware_dependencies")))

env.AddCustomTarget(
    name="firmware",
    dependencies=dependencies,
    actions=[generate_merged_firmware],
    title="Generate merged firmware",
    description="Generate a single merged firmware image for distribution",
)
