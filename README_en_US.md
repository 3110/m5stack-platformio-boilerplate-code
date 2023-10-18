# Boilerplate Code for M5Stack in PlatformIO IDE Environment

The Boilerplate Code for M5Stack enables you to compile and execute your code immediately in [PlatformIO IDE](https://platformio.org/platformio-ide) Environment, just like writing `setup()` and `loop()` in [Arduino IDE](https://www.arduino.cc/en/software).

## Supported Devices

| Device Type     | Environment Name                                               | Notes                                                                                                                                                                        |
| :-------------- | :------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| M5Stack BASIC   | env:m5stack-basic                                              |                                                                                                                                                                              |
| M5Stack Fire    | env:m5stack-fire                                               |                                                                                                                                                                              |
| M5Stack M5GO    | env:m5stack-m5go                                               |                                                                                                                                                                              |
| M5Stack CORE2   | env:m5stack-core2                                              |                                                                                                                                                                              |
| M5Stack CORES3  | env:m5stack-cores3 <br> env:m5stack-cores3-m5unified           | with the M5Stack's library<br>with [M5Unified](https://github.com/m5stack/M5Unified). USB CDC On Boot is enabled                                                             |
| M5StickC        | env:m5stack-c                                                  |                                                                                                                                                                              |
| M5StickC Plus   | env:m5stack-c-plus                                             |                                                                                                                                                                              |
| M5ATOM Matrix   | env:m5stack-atom-matrix <br> env:m5stack-atom-matrix-m5unified | with the M5stack's library<br>with [M5Unified](https://github.com/m5stack/M5Unified)                                                                                         |
| M5ATOM Lite     | env:m5stack-atom-lite <br> env:m5stack-atom-lite-m5unified     | with the M5stack's library<br>with [M5Unified](https://github.com/m5stack/M5Unified)                                                                                         |
| M5ATOM Echo     | env:m5stack-atom-echo <br> env:m5stack-atom-echo-m5unified     | with the M5stack's library<br>with [M5Unified](https://github.com/m5stack/M5Unified)                                                                                         |
| M5ATOM U        | env:m5stack-atom-u <br> env:m5stack-atom-u-m5unified           | with the M5stack's library<br>with [M5Unified](https://github.com/m5stack/M5Unified)                                                                                         |
| M5ATOMS3        | env:m5stack-atoms3 <br> env:m5stack-atoms3-m5unified           | with the M5Stack's library<br>with [M5Unified](https://github.com/m5stack/M5Unified). USB CDC On Boot is enabled                                                             |
| M5ATOMS3 Lite   | env:m5stack-atoms3-lite <br> env:m5stack-atoms3-lite-m5unified | with the M5Stack's library<br>with [M5Unified](https://github.com/m5stack/M5Unified). USB CDC On Boot is enabled                                                             |
| M5ATOMS3 U      | env:m5stack-atoms3-u <br> env:m5stack-atoms3-u-m5unified       | with the M5Stack's library<br>with [M5Unified](https://github.com/m5stack/M5Unified). USB CDC On Boot is enabled                                                             |
| M5Stack CoreInk | env:m5stack-core-ink                                           |                                                                                                                                                                              |
| M5Stack Paper   | env:m5stack-paper                                              |                                                                                                                                                                              |
| M5StampS3       | env:m5stack-stamps3 <br> env:m5stack-stamps3-m5unified         | without the M5Stack's library<br>with [M5Unified](https://github.com/m5stack/M5Unified). USB CDC On Boot is enabled                                                          |
| M5Capsule       | env:m5stack-capsule-m5unified                                  | with [M5Unified](https://github.com/m5stack/M5Unified). USB CDC On Boot is enabled                                                                                           |
| M5Dial          | env:m5stack-dial<br>env:m5stack-dial-m5unified                 | with the M5Stack's library(based on [M5Unified](https://github.com/m5stack/M5Unified))<br>with [M5Unified](https://github.com/m5stack/M5Unified). USB CDC On Boot is enabled |

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
; default-envs = m5stack-fire
; default-envs = m5stack-m5go
; default_envs = m5stack-core2
; default_envs = m5stack-cores3
; default_envs = m5stack-cores3-m5unified
; default_envs = m5stick-c
; default_envs = m5stick-c-plus
; default_envs = m5stack-atom-matrix
; default_envs = m5stack-atom-lite
; default_envs = m5stack-atom-echo
; default_envs = m5stack-atom-u
; default_envs = m5stack-atom-matrix-m5unified
; default_envs = m5stack-atom-lite-m5unified
; default_envs = m5stack-atom-echo-m5unified
; default_envs = m5stack-atom-u-m5unified
; default_envs = m5stack-atoms3
; default_envs = m5stack-atoms3-lite
; default_envs = m5stack-atoms3-u
; default_envs = m5stack-atoms3-m5unified
; default_envs = m5stack-atoms3-lite-m5unified
; default_envs = m5stack-atoms3-u-m5unified
; default_envs = m5stack-coreink
; default_envs = m5stack-paper
; default_envs = m5stack-stamps3
; default_envs = m5stack-stamps3-m5unified
; default_envs = m5stack-capsule-m5unified
```

### Third Party Libraries

If you want to use third party libraries, add them to the `lib_deps` in the `[env]` section of `platformio.ini`.

```ini
lib_deps =
    fastled/FastLED
```

### Writing Codes

Write your code in the `setup()` and `loop()` in `main.cpp`. The `main.hpp` enables you to include the device-specific header files for your device.

To improve readability because of the varying arguments for `M5.begin()`, I have defined the `M5_BEGIN` macro. Please refer to `main.hpp` for the specific definition. Furthermore, to accommodate the absence of `M5.update()` in the M5Stack's library for CoreS3, I have also defined the `M5_UPDATE` macro for seamless compatibility.

Note: When using `SD.h` or `SPIFFS.h` with M5Unified, make sure to include them before the `#include "main.hpp"` statement.

```c++
// clang-format off
#include <SPIFFS.h>
#include "main.hpp"
// clang-format on
```

### Upload to Devices

Execute "PlatformIO: Upload" by clicking the right arrow icon located in the VSCode status bar.
