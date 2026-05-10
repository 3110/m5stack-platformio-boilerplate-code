# Boilerplate Code for M5Stack in PlatformIO IDE Environment

The Boilerplate Code for M5Stack enables you to compile and execute your code immediately in [PlatformIO IDE](https://platformio.org/platformio-ide) Environment, just like writing `setup()` and `loop()` in [Arduino IDE](https://www.arduino.cc/en/software).

## Supported Devices

| Device Type          | Environment Name                                               | Notes                                                                                                                                                                                                                                                   |
| :------------------- | :------------------------------------------------------------- | :------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| M5Stack BASIC        | env:m5stack-basic                                              | with [the official M5Stack library](https://github.com/m5stack/M5Stack)                                                                                                                                                                                 |
| M5Stack Fire         | env:m5stack-fire                                               | with [the official M5Stack library](https://github.com/m5stack/M5Stack)                                                                                                                                                                                 |
| M5Stack M5GO         | env:m5stack-m5go                                               | with [the official M5Stack library](https://github.com/m5stack/M5Stack)                                                                                                                                                                                 |
| M5Stack CORE2        | env:m5stack-core2 <br> env:m5stack-core2-m5unified             | with [the official M5Stack library](https://github.com/m5stack/M5Core2)(Deprecated)<br>with [M5Unified](https://github.com/m5stack/M5Unified).                                                                                                          |
| M5Stack CORES3       | env:m5stack-cores3 <br> env:m5stack-cores3-m5unified           | with [the official M5Stack library](https://github.com/m5stack/M5CoreS3)<br>with [M5Unified](https://github.com/m5stack/M5Unified). USB CDC On Boot is enabled.                                                                                         |
| M5StickC             | env:m5stick-c                                                  | with [the official M5Stack library](https://github.com/m5stack/M5StickC)                                                                                                                                                                                |
| M5StickC Plus        | env:m5stick-c-plus                                             | with [the official M5Stack library](https://github.com/m5stack/M5StickC-Plus)                                                                                                                                                                           |
| M5StickC Plus2       | env:m5stick-c-plus2-m5unified                                  | with [M5Unified](https://github.com/m5stack/M5Unified).                                                                                                                                                                                                 |
| M5StickS3            | env:m5stick-s3                                                 | the official M5Stack library is missing. <br>with [M5Unified](https://github.com/m5stack/M5Unified) and [M5PM1](https://github.com/m5stack/M5PM1). USB CDC On Boot is enabled.                                                                          |
| M5ATOM Matrix        | env:m5stack-atom-matrix <br> env:m5stack-atom-matrix-m5unified | with [the official M5stack library](https://github.com/m5stack/M5Atom)<br>with [M5Unified](https://github.com/m5stack/M5Unified)                                                                                                                        |
| M5ATOM Lite          | env:m5stack-atom-lite <br> env:m5stack-atom-lite-m5unified     | with [the official M5stack library](https://github.com/m5stack/M5Atom)<br>with [M5Unified](https://github.com/m5stack/M5Unified)                                                                                                                        |
| M5ATOM Echo          | env:m5stack-atom-echo <br> env:m5stack-atom-echo-m5unified     | with [the official M5stack library](https://github.com/m5stack/M5Atom)<br>with [M5Unified](https://github.com/m5stack/M5Unified)                                                                                                                        |
| M5ATOM U             | env:m5stack-atom-u <br> env:m5stack-atom-u-m5unified           | with [the official M5stack library](https://github.com/m5stack/M5Atom)<br>with [M5Unified](https://github.com/m5stack/M5Unified)                                                                                                                        |
| M5ATOMS3             | env:m5stack-atoms3 <br> env:m5stack-atoms3-m5unified           | with [the official M5Stack library](https://github.com/m5stack/M5AtomS3)(based on [M5Unified](https://github.com/m5stack/M5Unified)). USB CDC On Boot is enabled<br>with [M5Unified](https://github.com/m5stack/M5Unified). USB CDC On Boot is enabled. |
| M5ATOMS3R            | env:m5stack-atoms3r-m5unified                                  | with [M5Unified](https://github.com/m5stack/M5Unified). USB CDC On Boot is enabled.                                                                                                                                                                     |
| M5ATOM EchoS3R       | env:m5stack-atom-echos3r-m5unified                             | with [M5Unified](https://github.com/m5stack/M5Unified). USB CDC On Boot is enabled.                                                                                                                                                                     |
| M5ATOMS3 Lite        | env:m5stack-atoms3-lite <br> env:m5stack-atoms3-lite-m5unified | with [the official M5Stack library](https://github.com/m5stack/M5AtomS3)(based on [M5Unified](https://github.com/m5stack/M5Unified)). USB CDC On Boot is enabled<br>with [M5Unified](https://github.com/m5stack/M5Unified). USB CDC On Boot is enabled. |
| M5ATOMS3 U           | env:m5stack-atoms3-u <br> env:m5stack-atoms3-u-m5unified       | with [the official M5Stack library](https://github.com/m5stack/M5AtomS3)(based on [M5Unified](https://github.com/m5stack/M5Unified)). USB CDC On Boot is enabled<br>with [M5Unified](https://github.com/m5stack/M5Unified). USB CDC On Boot is enabled. |
| M5Stack CoreInk      | env:m5stack-coreink                                            | with [the official M5Stack library](https://github.com/m5stack/M5Core-Ink)                                                                                                                                                                              |
| M5Stack Paper        | env:m5stack-paper                                              | with [the official M5Stack library](https://github.com/m5stack/M5EPD)                                                                                                                                                                                   |
| M5Stack PaperS3      | env:m5stack-papers3                                            | the official M5Stack library is missing.<br>with [M5Unified](https://github.com/m5stack/M5Unified).                                                                                                                                                     |
| M5StampS3            | env:m5stack-stamps3 <br> env:m5stack-stamps3-m5unified         | the official M5Stack library is missing.<br>with [M5Unified](https://github.com/m5stack/M5Unified). USB CDC On Boot is enabled.                                                                                                                         |
| M5Capsule            | env:m5stack-capsule-m5unified                                  | with [M5Unified](https://github.com/m5stack/M5Unified). USB CDC On Boot is enabled.                                                                                                                                                                     |
| M5Dial               | env:m5stack-dial<br>env:m5stack-dial-m5unified                 | with [the official M5Stack library](https://github.com/m5stack/M5Dial)(based on [M5Unified](https://github.com/m5stack/M5Unified))<br>with [M5Unified](https://github.com/m5stack/M5Unified). USB CDC On Boot is enabled.                               |
| M5Cardputer          | env:m5stack-cardputer                                          | with [the official M5Stack library](https://github.com/m5stack/M5Cardputer)(based on [M5Unified](https://github.com/m5stack/M5Unified)). USB CDC On Boot is enabled.                                                                                    |
| M5DinMeter           | env:m5stack-din-meter                                          | with [the official M5Stack library](https://github.com/m5stack/M5DinMeter)(based on [M5Unified](https://github.com/m5stack/M5Unified)). USB CDC On Boot is enabled.                                                                                     |
| M5StampP4            | env:m5stack-stampp4                                            | the official M5Stack library is missing.<br>with [M5Unified](https://github.com/m5stack/M5Unified).                                                                                                                                                     |
| M5NanoC6             | env:m5stack-nanoc6                                             | with [the official M5stack library](https://github.com/m5stack/M5NanoC6) and [pioarduino](https://github.com/pioarduino/platform-espressif32)                                                                                                           |
| M5NanoH2             | env:m5stack-nanoh2                                             | with [pioarduino](https://github.com/pioarduino/platform-espressif32)                                                                                                                                                                                   |
| M5Stack Tab5         | env:m5stack-tab5                                               | with [M5Unified](https://github.com/m5stack/M5Unified) and [pioarduino](https://github.com/pioarduino/platform-espressif32).                                                                                                                            |
| M5Stack Chain DualKey| env:m5stack-chain-dualkey                                      | with [M5Unified](https://github.com/m5stack/M5Unified). USB CDC On Boot is enabled.                                                                                                                                                                     |
| M5Stack BASIC w/LLM  | env:m5stack-basic-m5unified-llm                                | with [M5Unified](https://github.com/m5stack/M5Unified).                                                                                                                                                                                                 |
| M5Stack Core2 w/LLM  | env:m5stack-core2-m5unified-llm                                | with [M5Unified](https://github.com/m5stack/M5Unified).                                                                                                                                                                                                 |
| M5Stack CoreS3 w/LLM | env:m5stack-core3-m5unified-llm                                | with [M5Unified](https://github.com/m5stack/M5Unified).                                                                                                                                                                                                 |

## Preparation

### Code Formatter Settings

Since the `"C_Cpp.clang_format_style"` is set to `"file"` in the `.vscode/settings.json`, you can change the code formatter settings to your preferred settings in `.clang-format`.

### Configuration

#### Connection Port

Uncomment `upload_port` and `monitor_port` in the `[platformio]` section of `platformio.ini`, and change the value of `upload_port` to the actual port where your device is connected.

```platformio.ini
upload_port = COM16
monitor_port = ${env.upload_port}
```

Note: From [PlatformIO IDE](https://platformio.org/platformio-ide) [v3.0.0](https://github.com/platformio/platformio-vscode-ide/releases/tag/v3.0.0), you can switch connection ports from the status bar.

### Environment

Set the appropriate environment name for your device using the "Switch PlatformIO Project Environment" option found in the VSCode status bar.

You can also set the environment by explicitly specifying the `default_envs` in the `[platformio]` section of `platformio.ini`. Since there are already written, just uncomment one of them. In the example below, `m5stack-basic` is specified.

```platformio.ini
[platformio]
default_envs = m5stack-basic
; default_envs = m5stack-fire
; default_envs = m5stack-m5go
; default_envs = m5stack-core2
; default_envs = m5stack-cores3
; default_envs = m5stack-cores3-m5unified
; default_envs = m5stick-c
; default_envs = m5stick-c-plus
; default_envs = m5stick-c-plus2-m5unified
; default_envs = m5stick-s3
; default_envs = m5stack-atom-matrix
; default_envs = m5stack-atom-lite
; default_envs = m5stack-atom-echo
; default_envs = m5stack-atom-u
; default_envs = m5stack-atom-matrix-m5unified
; default_envs = m5stack-atom-lite-m5unified
; default_envs = m5stack-atom-echo-m5unified
; default_envs = m5stack-atom-u-m5unified
; default_envs = m5stack-atoms3
; default_envs = m5stack-atoms3r-m5unified
; default_envs = m5stack-atom-echos3r-m5unified
; default_envs = m5stack-atoms3-lite
; default_envs = m5stack-atoms3-u
; default_envs = m5stack-atoms3-m5unified
; default_envs = m5stack-atoms3-lite-m5unified
; default_envs = m5stack-atoms3-u-m5unified
; default_envs = m5stack-coreink
; default_envs = m5stack-paper
; default_envs = m5stack-papers3
; default_envs = m5stack-stamps3
; default_envs = m5stack-stamps3-m5unified
; default_envs = m5stack-capsule-m5unified
; default_envs = m5stack-dial
; default_envs = m5stack-dial-m5unified
; default_envs = m5stack-cardputer
; default_envs = m5stack-din-meter
; default_envs = m5stack-stampp4
; default_envs = m5stack-nanoc6
; default_envs = m5stack-nanoh2
; default_envs = m5stack-tab5
; default_envs = m5stack-chain-dualkey

; default_envs = m5stack-basic-m5unified-llm
; default_envs = m5stack-core2-m5unified-llm
; default_envs = m5stack-cores3-m5unified-llm
```

### Third Party Libraries

If you want to use third party libraries, add them to the `lib_deps` in the `[env]` section of `platformio.ini`.

```ini
lib_deps =
    fastled/FastLED
```

### Writing Codes

Write your code in the `setup()` and `loop()` in `main.cpp`. The `main.hpp` enables you to include the device-specific header files for your device.

I have defined the `M5_BEGIN()` and `M5_UPDATE()` macros to manage the diverse and sometimes confusing arguments for `M5.begin()` across different models; this includes instances where model-specific names such as `CoreS3.begin()` are utilized. Additionally, depending on the model, the `M5` instance may be named specifically for that model (for instance, in the official library for the M5Stack CoreS3, it is referred to as `CoreS3` rather than `M5`). Therefore, it is set up to be accessed by the uniform identifier `M5DEV` in all cases.

To unify the format of logging output, the macros `M5DEV_LOGE()`, `M5DEV_LOGW()`, `M5DEV_LOGI()`, `M5DEV_LOGD()`, and `M5DEV_LOGV()` have been defined.

For detailed definitions, please consult `main.hpp`.

Note: When using `SD.h` or `SPIFFS.h` with M5Unified, make sure to include them before the `#include "main.hpp"` statement.

```c++
// clang-format off
#include <SPIFFS.h>
#include "main.hpp"
// clang-format on
```

### Upload to Devices

Execute "PlatformIO: Upload" by clicking the right arrow icon located in the VSCode status bar.

### Generating firmware files

This boilerplate includes a PlatformIO custom target for generating a merged firmware image for distribution.

Run the following command to generate firmware for a specific PlatformIO environment.

```sh
pio run -e m5stack-basic -t firmware
```

If you are using the PlatformIO extension for VSCode, you can also generate the same firmware file from the PlatformIO Project Tasks view. Select the target environment, then run **Custom** > **Generate merged firmware**.

This is equivalent to running:

```sh
pio run -e <environment> -t firmware
```

The generated firmware file is written to the `firmware/` directory by default.

The firmware filename uses the following format:

```text
project_name_environment_name_firmware_version.bin
```

Example:

```text
my_project_m5stack-basic_firmware_0.1.0.bin
```

To specify the project name used in the firmware filename, set `custom_firmware_name` in the `[env]` section of `platformio.ini`. If omitted, the project directory name is used.

```ini
[env]
custom_firmware_name = my_project
```

The firmware version is resolved in the following order:

1. `custom_firmware_version`
2. `custom_firmware_version_file` + `custom_firmware_version_regex`
3. Git tag name when running on GitHub Actions
4. `dev`

To specify the version directly, use:

```ini
[env]
custom_firmware_version = 0.1.0
```

To extract the version from a file using a regular expression, use:

```ini
[env]
custom_firmware_version_file = main.cpp
custom_firmware_version_regex = "v(\d+\.\d+\.\d+)"
```

When `custom_firmware_version` is specified, it takes priority over the version extracted from a file.

### Building firmware with GitHub Actions

This boilerplate also includes a GitHub Actions workflow for building firmware on GitHub.

The workflow is mainly intended for projects created from this boilerplate. It allows derived projects to build and distribute their own firmware artifacts on GitHub without requiring users to install PlatformIO locally.

To use it:

1. Open the **Actions** tab on GitHub.
2. Select the **Build merged firmware** workflow.
3. Set `platformio_envs` to the PlatformIO environments you want to build, using a JSON array.
4. Run the workflow.
5. Download the generated artifacts from the workflow result.

For example, to build firmware for `m5stack-basic` and `m5stack-atom-matrix`, enter:

```json
["m5stack-basic","m5stack-atom-matrix"]
```

The workflow will run commands like:

```sh
pio run -e m5stack-basic -t firmware
pio run -e m5stack-atom-matrix -t firmware
```

The generated `.bin` files are uploaded as artifacts for each environment.

For example, the artifact name for `m5stack-basic` will be:

```text
firmware-m5stack-basic
```

After downloading the artifact, it will contain a firmware file such as:

```text
my_project_m5stack-basic_firmware_0.1.0.bin
```

If a derived project has specific environments that should be built by default, edit `.github/workflows/build-firmware.yml` and change the `default` value of `platformio_envs`.

```yaml
default: '["m5stack-basic"]'
```

To build multiple environments by default, use:

```yaml
default: '["m5stack-basic","m5stack-atom-matrix"]'
```
