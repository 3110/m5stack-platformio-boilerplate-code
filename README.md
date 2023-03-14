# PlatformIO IDE 向け M5Stack 定型コード環境

[Arduino IDE](https://www.arduino.cc/en/software) 環境のように [PlatformIO IDE](https://platformio.org/platformio-ide) 環境でも `setup()`と`loop()`の中身を書いてすぐにコンパイルして実行できる環境です。

## 対応機種

| 機種名                    | 環境名                                               | 備考                                                                                                     |
| :------------------------ | :--------------------------------------------------- | -------------------------------------------------------------------------------------------------------- |
| M5Stack BASIC             | env:m5stack-basic                                    |                                                                                                          |
| M5Stack CORE2             | env:m5stack-core2                                    |                                                                                                          |
| M5StickC                  | env:m5stack-c                                        |                                                                                                          |
| M5StickC Plus             | env:m5stack-c-plus                                   |                                                                                                          |
| M5ATOM Lite/Matrix/Echo/U | env:m5stack-atom <br> env:m5stack-atom-m5unified     | 公式ライブラリを使用<br>[M5Unified](https://github.com/m5stack/M5Unified) を使用                         |
| M5ATOMS3/Lite             | env:m5stack-atoms3 <br> env:m5stack-atoms3-m5unified | 公式ライブラリを使用<br>[M5Unified](https://github.com/m5stack/M5Unified) を使用。USB CDC On Boot が有効 |
| M5Stack CoreInk           | env:m5stack-core-ink                                 |                                                                                                          |
| M5Stack Paper             | env:m5stack-paper                                    |                                                                                                          |

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

#### 環境名の設定

「Switch PlatformIO Project Environment」（VSCode のステータスバーにある）で機種に合った環境名を設定します。

`platformio.ini`の`[platformio]`セクションで`default_envs`を明示的に指定することでも環境を設定できます（既に書いてあるので，いずれかのコメントを外す）。以下の例では`m5stack-basic`を指定しています。

```platformio.ini
[platformio]
default_envs = m5stack-basic
; default_envs = m5stack-core2
; default_envs = m5stick-c
; default_envs = m5stick-c-plus
; default_envs = m5stack-atom
; default_envs = m5stack-atom-m5unified
; default_envs = m5stack-atoms3
; default_envs = m5stack-atoms3-m5unified
; default_envs = m5stack-coreink
; default_envs = m5stack-paper
```

### コードの記述

`main.cpp`の`setup()`，`loop()`にコードを書きます。必要なヘッダファイルは`main.hpp`で環境名に合わせて実機に合ったヘッダファイルをインクルードするようにしています。

### 実機へのアップロード

PlatformIO: Upload（VSCode のステータスバーにある → ボタン）を実行します。
