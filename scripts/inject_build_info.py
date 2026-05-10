from __future__ import annotations

import os
import re
import subprocess
from datetime import datetime, timezone
from typing import Any

from SCons.Script import DefaultEnvironment  # type: ignore[import-untyped]

env: Any = DefaultEnvironment()


def sanitize_filename_part(value):
    return re.sub(r"[^A-Za-z0-9._-]+", "_", str(value)).strip("_")


def sanitize_project_name(value):
    return sanitize_filename_part(str(value).replace("-", "_"))


def normalize_version(value):
    value = str(value).strip()
    return value[1:] if value.startswith("v") else value


def define_str(name, value):
    env.Append(CPPDEFINES=[(name, '\\"' + value + '\\"')])


def inject():
    # Git SHA — skip silently if not in a git repo
    try:
        sha = subprocess.check_output(
            ["git", "rev-parse", "--short", "HEAD"],
            stderr=subprocess.DEVNULL,
        ).decode().strip()
        if sha:
            define_str("BUILD_SHA", sha)
    except Exception:
        pass

    # Build date — always available
    define_str("BUILD_DATE", datetime.now(timezone.utc).strftime("%Y-%m-%dT%H:%M:%SZ"))

    # CI-only: repo, tag, firmware URI
    github_repository = os.environ.get("GITHUB_REPOSITORY", "")
    github_server = os.environ.get("GITHUB_SERVER_URL", "https://github.com")
    github_ref_name = os.environ.get("GITHUB_REF_NAME", "")

    if github_repository:
        define_str("BUILD_REPO", f"{github_server}/{github_repository}")

    tag_match = re.match(r"^v?(\d+\.\d+\.\d+(?:[-+][0-9A-Za-z.-]+)?)$", github_ref_name)
    if tag_match:
        tag = github_ref_name
        define_str("BUILD_TAG", tag)

        if github_repository:
            version = normalize_version(tag)
            project_dir = env.subst("$PROJECT_DIR")
            firmware_name = sanitize_project_name(os.path.basename(project_dir))
            pioenv = sanitize_filename_part(env.subst("$PIOENV"))
            firmware_version = sanitize_filename_part(version)
            filename = f"{firmware_name}_{pioenv}_firmware_{firmware_version}.bin"
            uri = f"{github_server}/{github_repository}/releases/download/{tag}/{filename}"
            define_str("BUILD_FIRMWARE_URI", uri)


inject()
