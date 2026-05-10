[In English](README_en_US.md)

# PlatformIO IDE 向け M5Stack 定型コード環境

[Arduino IDE](https://www.arduino.cc/en/software) 環境と同じように [PlatformIO IDE](https://platformio.org/platformio-ide) 環境でも `setup()`と`loop()`の中身を書いてすぐにコンパイルして実行できます。
## 対応機種

| 機種名               | 環境名                                                        | 備考                                                                                                                                                                                                                                 |
| :------------------- | :------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| M5Stack BASIC        | env:m5stack-basic                                              | [公式ライブラリ](https://github.com/m5stack/M5Stack)を使用。                                                                                                                                                                           |
| M5Stack Fire         | env:m5stack-fire                                               | [公式ライブラリ](https://github.com/m5stack/M5Stack)を使用。                                                                                                                                                                           |
| M5Stack M5GO         | env:m5stack-m5go                                               | [公式ライブラリ](https://github.com/m5stack/M5Stack)を使用。                                                                                                                                                                           |
| M5Stack CORE2        | env:m5stack-core2 <br> env:m5stack-core2-m5unified             | [公式ライブラリ](https://github.com/m5stack/M5Core2)を使用（ライブラリ廃止予定）。<br>[M5Unified](https://github.com/m5stack/M5Unified)を使用。                                                                                        |
| M5Stack CORES3       | env:m5stack-cores3 <br> env:m5stack-cores3-m5unified           | [公式ライブラリ](https://github.com/m5stack/M5CoreS3)を使用。<br>[M5Unified](https://github.com/m5stack/M5Unified) を使用。USB CDC On Boot が有効。                                                                                    |
| M5StickC             | env:m5stick-c                                                  | [公式ライブラリ](https://github.com/m5stack/M5StickC)を使用。                                                                                                                                                                          |
| M5StickC Plus        | env:m5stick-c-plus                                             | [公式ライブラリ](https://github.com/m5stack/M5StickC-Plus)を使用。                                                                                                                                                                     |
| M5StickC Plus2       | env:m5stick-c-plus2-m5unified                                  | [M5Unified](https://github.com/m5stack/M5Unified) を使用。                                                                                                                                                                             |
| M5StickS3            | env:m5stick-s3                                                 | 公式ライブラリはなし。<br> [M5Unified](https://github.com/m5stack/M5Unified)，[M5PM1](https://github.com/m5stack/M5PM1) を使用。USB CDC On Boot が有効。                                                                               |
| M5ATOM Matrix        | env:m5stack-atom-matrix <br> env:m5stack-atom-matrix-m5unified | [公式ライブラリ](https://github.com/m5stack/M5Atom)を使用。<br>[M5Unified](https://github.com/m5stack/M5Unified) を使用。                                                                                                              |
| M5ATOM Lite          | env:m5stack-atom-lite <br> env:m5stack-atom-lite-m5unified     | [公式ライブラリ](https://github.com/m5stack/M5Atom)を使用。<br>[M5Unified](https://github.com/m5stack/M5Unified) を使用。                                                                                                              |
| M5ATOM Echo          | env:m5stack-atom-echo <br> env:m5stack-atom-echo-m5unified     | [公式ライブラリ](https://github.com/m5stack/M5Atom)を使用。<br>[M5Unified](https://github.com/m5stack/M5Unified) を使用。                                                                                                              |
| M5ATOM U             | env:m5stack-atom-u <br> env:m5stack-atom-u-m5unified           | [公式ライブラリ](https://github.com/m5stack/M5Atom)を使用。<br>[M5Unified](https://github.com/m5stack/M5Unified) を使用。                                                                                                              |
| M5ATOMS3             | env:m5stack-atoms3 <br> env:m5stack-atoms3-m5unified           | [公式ライブラリ](https://github.com/m5stack/M5AtomS3)を使用（[M5Unified](https://github.com/m5stack/M5Unified)ベース）。USB CDC On Boot が有効。<br>[M5Unified](https://github.com/m5stack/M5Unified) を使用。USB CDC On Boot が有効。 |
| M5ATOMS3R            | env:m5stack-atoms3r-m5unified                                  | [M5Unified](https://github.com/m5stack/M5Unified) を使用。USB CDC On Boot が有効。                                                                                                                                                     |
| M5ATOM EchoS3R       | env:m5stack-atom-echos3r-m5unified                             | [M5Unified](https://github.com/m5stack/M5Unified) を使用。USB CDC On Boot が有効。                                                                                                                                                     |
| M5ATOMS3 Lite        | env:m5stack-atoms3-lite <br> env:m5stack-atoms3-lite-m5unified | [公式ライブラリ](https://github.com/m5stack/M5AtomS3)を使用（[M5Unified](https://github.com/m5stack/M5Unified)ベース）。USB CDC On Boot が有効。<br>[M5Unified](https://github.com/m5stack/M5Unified) を使用。USB CDC On Boot が有効。 |
| M5ATOMS3 U           | env:m5stack-atoms3-u <br> env:m5stack-atoms3-u-m5unified       | [公式ライブラリ](https://github.com/m5stack/M5AtomS3)を使用（[M5Unified](https://github.com/m5stack/M5Unified)ベース）。USB CDC On Boot が有効。<br>[M5Unified](https://github.com/m5stack/M5Unified) を使用。USB CDC On Boot が有効。 |
| M5Stack CoreInk      | env:m5stack-coreink                                            | [公式ライブラリ](https://github.com/m5stack/M5Core-Ink)を使用。                                                                                                                                                                        |
| M5Stack Paper        | env:m5stack-paper                                              | [公式ライブラリ](https://github.com/m5stack/M5EPD)を使用。                                                                                                                                                                             |
| M5Stack PaperS3      | env:m5stack-papers3                                            | 公式ライブラリはなし。<br>[M5Unified](https://github.com/m5stack/M5Unified) を使用。                                                                                                                                                   |
| M5StampS3            | env:m5stack-stamps3 <br> env:m5stack-stamps3-m5unified         | 公式ライブラリはなし。<br>[M5Unified](https://github.com/m5stack/M5Unified) を使用。USB CDC On Boot が有効。                                                                                                                           |
| M5Capsule            | env:m5stack-capsule-m5unified                                  | [M5Unified](https://github.com/m5stack/M5Unified) を使用。USB CDC On Boot が有効。                                                                                                                                                     |
| M5Dial               | env:m5stack-dial <br> env:m5stack-dial-m5unified               | [公式ライブラリ](https://github.com/m5stack/M5Dial)を使用（[M5Unified](https://github.com/m5stack/M5Unified)ベース）。<br>[M5Unified](https://github.com/m5stack/M5Unified)を使用。USB CDC On Boot が有効。                            |
| M5Cardputer          | env:m5stack-cardputer                                          | [公式ライブラリ](https://github.com/m5stack/M5Cardputer)を使用（[M5Unified](https://github.com/m5stack/M5Unified)ベース）。USB CDC On Boot が有効。                                                                                    |
| M5DinMeter           | env:m5stack-din-meter                                          | [公式ライブラリ](https://github.com/m5stack/M5DinMeter)を使用（[M5Unified](https://github.com/m5stack/M5Unified)ベース）。USB CDC On Boot が有効。                                                                                     |
| M5StampP4            | env:m5stack-stampp4                                            | 公式ライブラリはなし。<br>[M5Unified](https://github.com/m5stack/M5Unified) を使用。                                                                                                                                                   |
| M5NanoC6             | env:m5stack-nanoc6                                             | [公式ライブラリ](https://github.com/m5stack/M5NanoC6)を使用。プラットフォームは[pioarduino](https://github.com/pioarduino/platform-espressif32)を使用。                                                                                |
| M5NanoH2             | env:m5stack-nanoh2                                             | プラットフォームは[pioarduino](https://github.com/pioarduino/platform-espressif32)を使用。                                                                                                                                             |
| M5Stack Tab5         | env:m5stack-tab5                                               | [M5Unified](https://github.com/m5stack/M5Unified) を使用。プラットフォームは[pioarduino](https://github.com/pioarduino/platform-espressif32)を使用。                                                                                   |
| M5Stack Chain DualKey| env:m5stack-chain-dualkey                                      | [M5Unified](https://github.com/m5stack/M5Unified) を使用。USB CDC On Boot が有効。                                                                                                                                                     |
| M5Stack BASIC w/LLM  | env:m5stack-basic-m5unified-llm                                | [M5Unified](https://github.com/m5stack/M5Unified) を使用。                                                                                                                                                                             |
| M5Stack Core2 w/LLM  | env:m5stack-core2-m5unified-llm                                | [M5Unified](https://github.com/m5stack/M5Unified) を使用。                                                                                                                                                                             |
| M5Stack CoreS3 w/LLM | env:m5stack-cores3-m5unified-llm                               | [M5Unified](https://github.com/m5stack/M5Unified) を使用。                                                                                                                                                                             |

## 事前準備

### コード整形の設定

コードの整形は`.vscode/settings.json`で`"C_Cpp.clang_format_style": "file"`にしているため，`.clang-format`で設定できます。ご自身の好きな設定に変更してください。

### 環境設定

#### 接続ポートの設定

`platformio.ini`の`[platformio]`セクションにある`upload_port`と`monitor_port`のコメントを外し，`upload_port`に設定するポートを実機が接続しているポートに変更します。

```platformio.ini
upload_port = COM16
monitor_port = ${env.upload_port}
```

※PlatformIO IDE [v3.0.0](https://github.com/platformio/platformio-vscode-ide/releases/tag/v3.0.0)より，ステータスバーからポートの切り替えができるようになりました。

#### 環境の設定

「Switch PlatformIO Project Environment」（VSCode のステータスバーにある）で機種に合った環境名を設定します。

`platformio.ini`の`[platformio]`セクションで`default_envs`を明示的に指定することでも環境を設定できます（既に書いてあるので，いずれかのコメントを外す）。以下の例では`m5stack-basic`を指定しています。

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

### 外部ライブラリの追加

外部ライブラリを使用する場合は，`[env]`セクションにある`lib_deps`に追加します。

```ini
lib_deps =
    fastled/FastLED
```

### コードの記述

`main.cpp`の`setup()`，`loop()`にコードを書きます。必要なヘッダファイルは`main.hpp`で環境名に合わせて実機に合ったヘッダファイルをインクルードするようにしています。

各機種で`M5.begin()`の引数がまちまちでわかりにくく，`CoreS3.begin()`のように機種固有の名前が付いている場合もあるので，`M5_BEGIN`と`M5_UPDATE`というマクロで差異を吸収しています。
また，機種によっては`M5`のインスタンスに機種固有の名前（M5Stack CoreS3 の公式ライブラリの場合は`M5`ではなく`CoreS3`）がついている場合があるので，どの場合でも同じ`M5DEV`でアクセスできるように設定しています。

共通の書き方でログの出力をするために，`M5DEV_LOGE()`，`M5DEV_LOGW()`，`M5DEV_LOGI()`，`M5DEV_LOGD()`，`M5DEV_LOGV()`を定義しました。

それぞれの定義内容に関しては`main.hpp`を参照してください。

注意：M5Unified で`SD.h`や`SPIFFS.h`を使用する場合は，`#include "main.hpp"`より前に入れてください。

```c++
// clang-format off
#include <SPIFFS.h>
#include "main.hpp"
// clang-format on
```

### 実機へのアップロード

PlatformIO: Upload（VSCode のステータスバーにある → ボタン）を実行します。

### ファームウェアファイルの生成

この boilerplate には，配布用の merged firmware を生成するための PlatformIO custom target が含まれています。

次のコマンドを実行すると，指定した PlatformIO environment 用のファームウェアファイルを生成できます。

```sh
pio run -e m5stack-basic -t firmware
```

VSCode の PlatformIO 拡張機能を使っている場合は、PlatformIO の Project Tasks から対象の environment を選び、**Custom** にある **Generate merged firmware** を実行しても同じファームウェアファイルを生成できます。

これは、次のコマンドを実行するのと同じです。

```sh
pio run -e <environment> -t firmware
```

生成されるファームウェアファイルは，デフォルトでは `firmware/` ディレクトリに出力されます。

ファイル名は次の形式になります。

```text
プロジェクト名_env名_firmware_バージョン.bin
```

例：

```text
my_project_m5stack-basic_firmware_0.1.0.bin
```

プロジェクト名を明示したい場合は，`platformio.ini` の `[env]` セクションで `custom_firmware_name` を指定します。指定しない場合は，プロジェクトディレクトリ名が使用されます。

```ini
[env]
custom_firmware_name = my_project
```

ファームウェアのバージョンは，次の優先順位で決まります。

1. `custom_firmware_version`
2. `custom_firmware_version_file` と `custom_firmware_version_regex` によるファイルからの抽出
3. GitHub Actions 実行時の Git tag 名
4. `dev`

バージョンを直接指定する場合は，次のように設定します。

```ini
[env]
custom_firmware_version = 0.1.0
```

ファイルから正規表現でバージョンを抽出する場合は，次のように設定します。

```ini
[env]
custom_firmware_version_file = main.cpp
custom_firmware_version_regex = "v(\d+\.\d+\.\d+)"
```

`custom_firmware_version` を指定した場合は，ファイルから抽出する設定よりも優先されます。

### GitHub Actions でファームウェアを生成する

この boilerplate には，GitHub 上でファームウェアをビルドするための GitHub Actions workflow も含まれています。

この workflow は，boilerplate 本体のファームウェアを配布するためというより，この boilerplate から作成された派生プロジェクトが，自分のプロジェクト用ファームウェアを GitHub 上で生成・配布しやすくするためのものです。

使い方は次のとおりです。

1. GitHub の **Actions** タブを開く
2. **Build merged firmware** workflow を選ぶ
3. `platformio_envs` にビルドしたい PlatformIO environment 名を JSON 配列で指定する
4. workflow を実行する
5. 実行結果から生成された artifact をダウンロードする

たとえば，`m5stack-basic` と `m5stack-atom-matrix` のファームウェアを生成する場合は，次のように指定します。

```json
["m5stack-basic","m5stack-atom-matrix"]
```

この場合，GitHub Actions 上で次のようなコマンドが実行されます。

```sh
pio run -e m5stack-basic -t firmware
pio run -e m5stack-atom-matrix -t firmware
```

生成された `.bin` ファイルは，environment ごとに artifact としてアップロードされます。

たとえば `m5stack-basic` の場合，artifact 名は次のようになります。

```text
firmware-m5stack-basic
```

artifact をダウンロードすると，その中に次のようなファームウェアファイルが含まれます。

```text
my_project_m5stack-basic_firmware_0.1.0.bin
```

派生プロジェクトで標準的にビルドしたい environment が決まっている場合は，`.github/workflows/build-firmware.yml` の `platformio_envs` の `default` を変更してください。

```yaml
default: '["m5stack-basic"]'
```

複数の environment を標準にしたい場合は，次のように指定できます。

```yaml
default: '["m5stack-basic","m5stack-atom-matrix"]'
```
