#pragma once

#if defined(TARGET_M5STACK_BASIC)
#include <M5Stack.h>
inline void M5_BEGIN(bool LCDEnable = true, bool SDEnable = true,
                     bool SerialEnable = true, bool I2CEnable = false) {
    M5.begin(LCDEnable, SDEnable, SerialEnable, I2CEnable);
}
#elif defined(TARGET_M5STACK_CORE2)
#include <M5Core2.h>
inline void M5_BEGIN(bool LCDEnable = true, bool SDEnable = true,
                     bool SerialEnable = true, bool I2CEnable = false,
                     mbus_mode_t mode = kMBusModeOutput) {
    M5.begin(LCDEnable, SDEnable, SerialEnable, I2CEnable, mode);
}
#elif defined(TARGET_M5STICK_C)
#include <M5StickC.h>
inline void M5_BEGIN(bool LCDEnable = true, bool PowerEnable = true,
                     bool SerialEnable = true) {
    M5.begin(LCDEnable, PowerEnable, SerialEnable);
}
#elif defined(TARGET_M5STICK_C_PLUS)
#include <M5StickCPlus.h>
inline void M5_BEGIN(bool LCDEnable = true, bool PowerEnable = true,
                     bool SerialEnable = true) {
    M5.begin(LCDEnable, PowerEnable, SerialEnable);
}
#elif defined(TARGET_M5STACK_ATOM)
#include <M5Atom.h>
inline void M5_BEGIN(bool SerialEnable = true, bool I2CEnable = true,
                     bool DisplayEnable = false) {
    M5.begin(SerialEnable, I2CEnable, DisplayEnable);
    // https://twitter.com/wakwak_koba/status/1553162622479974400
    pinMode(0, OUTPUT);
    digitalWrite(0, LOW);
}
#elif defined(TARGET_M5STACK_ATOMS3)
#include <M5AtomS3.h>
inline void M5_BEGIN(bool LCDEnable = true, bool SerialEnable = true,
                     bool I2CEnable = true, bool LEDEnable = false) {
    M5.begin(LCDEnable, SerialEnable, I2CEnable, LEDEnable);
}
#elif defined(TARGET_M5STACK_ATOMS3_M5UNIFIED)
// clang-format off
#include <M5Unified.h>
#include <FastLED.h>
// clang-format on
inline void M5_BEGIN(void) {
    M5.begin();
}
inline void M5_BEGIN(m5::M5Unified::config_t& cfg) {
    M5.begin(cfg);
}
#elif defined(TARGET_M5STACK_CORE_INK)
#include <M5CoreInk.h>
inline int M5_BEGIN(bool InkEnable = true, bool WireEnable = false,
                    bool SpeakerEnable = false) {
    return M5.begin(InkEnable, WireEnable, SpeakerEnable);
}
#elif defined(TARGET_M5STACK_PAPER)
#include <M5EPD.h>
inline void M5_BEGIN(bool TouchEnable = true, bool SDEnable = true,
                     bool SerialEnable = true, bool BatteryADCEnable = true,
                     bool I2CEnable = false) {
    M5.begin(TouchEnable, SDEnable, SerialEnable, BatteryADCEnable, I2CEnable);
}
#endif
