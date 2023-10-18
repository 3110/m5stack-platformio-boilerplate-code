[In English](README_en_US.md)

# PlatformIO IDE 向け M5Stack 定型コード環境

[Arduino IDE](https://www.arduino.cc/en/software) 環境と同じように [PlatformIO IDE](https://platformio.org/platformio-ide) 環境でも `setup()`と`loop()`の中身を書いてすぐにコンパイルして実行できます。

## 対応機種

| 機種名          | 環境名                                                         | 備考                                                                                                                                                                |
| :-------------- | :------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| M5Stack BASIC   | env:m5stack-basic                                              |                                                                                                                                                                     |
| M5Stack Fire    | env:m5stack-fire                                               |                                                                                                                                                                     |
| M5Stack M5GO    | env:m5stack-m5go                                               |                                                                                                                                                                     |
| M5Stack CORE2   | env:m5stack-core2                                              |                                                                                                                                                                     |
| M5Stack CORES3  | env:m5stack-cores3 <br> env:m5stack-cores3-m5unified           | 公式ライブラリを使用<br>[M5Unified](https://github.com/m5stack/M5Unified) を使用。USB CDC On Boot が有効                                                            |
| M5StickC        | env:m5stack-c                                                  |                                                                                                                                                                     |
| M5StickC Plus   | env:m5stack-c-plus                                             |                                                                                                                                                                     |
| M5ATOM Matrix   | env:m5stack-atom-matrix <br> env:m5stack-atom-matrix-m5unified | 公式ライブラリを使用<br>[M5Unified](https://github.com/m5stack/M5Unified) を使用                                                                                    |
| M5ATOM Lite     | env:m5stack-atom-lite <br> env:m5stack-atom-lite-m5unified     | 公式ライブラリを使用<br>[M5Unified](https://github.com/m5stack/M5Unified) を使用                                                                                    |
| M5ATOM Echo     | env:m5stack-atom-echo <br> env:m5stack-atom-echo-m5unified     | 公式ライブラリを使用<br>[M5Unified](https://github.com/m5stack/M5Unified) を使用                                                                                    |
| M5ATOM U        | env:m5stack-atom-u <br> env:m5stack-atom-u-m5unified           | 公式ライブラリを使用<br>[M5Unified](https://github.com/m5stack/M5Unified) を使用                                                                                    |
| M5ATOMS3        | env:m5stack-atoms3 <br> env:m5stack-atoms3-m5unified           | 公式ライブラリを使用<br>[M5Unified](https://github.com/m5stack/M5Unified) を使用。USB CDC On Boot が有効                                                            |
| M5ATOMS3 Lite   | env:m5stack-atoms3-lite <br> env:m5stack-atoms3-lite-m5unified | 公式ライブラリを使用<br>[M5Unified](https://github.com/m5stack/M5Unified) を使用。USB CDC On Boot が有効                                                            |
| M5ATOMS3 U      | env:m5stack-atoms3-u <br> env:m5stack-atoms3-u-m5unified       | 公式ライブラリを使用<br>[M5Unified](https://github.com/m5stack/M5Unified) を使用。USB CDC On Boot が有効                                                            |
| M5Stack CoreInk | env:m5stack-core-ink                                           |                                                                                                                                                                     |
| M5Stack Paper   | env:m5stack-paper                                              |                                                                                                                                                                     |
| M5StampS3       | env:m5stack-stamps3 <br> env:m5stack-stamps3-m5unified         | 公式ライブラリはなし<br>[M5Unified](https://github.com/m5stack/M5Unified) を使用。USB CDC On Boot が有効                                                            |
| M5Capsule       | env:m5stack-capsule-m5unified                                  | [M5Unified](https://github.com/m5stack/M5Unified) を使用。USB CDC On Boot が有効                                                                                    |
| M5Dial          | env:m5stack-dial <br> env:m5stack-dial-m5unified               | 公式ライブラリを使用（[M5Unified](https://github.com/m5stack/M5Unified)ベース）<br>[M5Unified](https://github.com/m5stack/M5Unified)を使用。USB CDC On Boot が有効  |

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

### 外部ライブラリの追加

外部ライブラリを使用する場合は，`[env]`セクションにある`lib_deps`に追加します。

```ini
lib_deps =
    fastled/FastLED
```

### コードの記述

`main.cpp`の`setup()`，`loop()`にコードを書きます。必要なヘッダファイルは`main.hpp`で環境名に合わせて実機に合ったヘッダファイルをインクルードするようにしています。

各機種で`M5.begin()`の引数がまちまちでわかりにくいので，`M5_BEGIN`というマクロを定義しています。定義内容に関しては`main.hpp`を参照してください。
また，CoreS3の公式ライブラリでは`M5.update()`が定義されていないので，各機種共通で扱えるように`M5_UPDATE`というマクロで吸収しています。

注意：M5Unified で`SD.h`や`SPIFFS.h`を使用する場合は，`#include "main.hpp"`より前に入れてください。

```c++
// clang-format off
#include <SPIFFS.h>
#include "main.hpp"
// clang-format on
```

### 実機へのアップロード

PlatformIO: Upload（VSCode のステータスバーにある → ボタン）を実行します。
