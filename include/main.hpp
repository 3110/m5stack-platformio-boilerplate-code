#pragma once

#if defined(USE_M5UNIFIED) && !defined(USE_M5STACK_OFFICIAL)
// clang-format off
#include <M5Unified.h>
#if defined(USE_FASTLED)
#define FASTLED_INTERNAL
#include <FastLED.h>
#endif
// clang-format on
inline void M5_BEGIN(void) {
    M5.begin();
}
inline void M5_BEGIN(m5::M5Unified::config_t& cfg) {
    M5.begin(cfg);
}
#elif defined(ARDUINO_M5STACK_BASIC) || defined(ARDUINO_M5STACK_FIRE) || \
    defined(ARDUINO_M5STACK_M5GO)
#include <M5Stack.h>
inline void M5_BEGIN(bool LCDEnable = true, bool SDEnable = true,
                     bool SerialEnable = true, bool I2CEnable = false) {
    M5.begin(LCDEnable, SDEnable, SerialEnable, I2CEnable);
}
#elif defined(ARDUINO_M5STACK_PAPER)
#include <M5EPD.h>
inline void M5_BEGIN(bool TouchEnable = true, bool SDEnable = true,
                     bool SerialEnable = true, bool BatteryADCEnable = true,
                     bool I2CEnable = false) {
    M5.begin(TouchEnable, SDEnable, SerialEnable, BatteryADCEnable, I2CEnable);
}
#elif defined(ARDUINO_M5STACK_CORE2)
#include <M5Core2.h>
inline void M5_BEGIN(bool LCDEnable = true, bool SDEnable = true,
                     bool SerialEnable = true, bool I2CEnable = false,
                     mbus_mode_t mode = kMBusModeOutput) {
    M5.begin(LCDEnable, SDEnable, SerialEnable, I2CEnable, mode);
}
#elif defined(ARDUINO_M5STACK_CORES3)
#include <M5CoreS3.h>
inline void M5_BEGIN(bool LCDEnable = true, bool SerialEnable = true,
                     bool I2CEnable = false) {
    M5.begin(LCDEnable, SerialEnable, I2CEnable);
}
#elif defined(ARDUINO_M5STICK_C)
#include <M5StickC.h>
inline void M5_BEGIN(bool LCDEnable = true, bool PowerEnable = true,
                     bool SerialEnable = true) {
    M5.begin(LCDEnable, PowerEnable, SerialEnable);
}
#elif defined(ARDUINO_M5SICK_C_PLUS)
#include <M5StickCPlus.h>
inline void M5_BEGIN(bool LCDEnable = true, bool PowerEnable = true,
                     bool SerialEnable = true) {
    M5.begin(LCDEnable, PowerEnable, SerialEnable);
}
#elif defined(ARDUINO_M5STACK_ATOM)
#include <M5Atom.h>
inline void M5_BEGIN(bool SerialEnable = true, bool I2CEnable = true,
                     bool DisplayEnable = false) {
    M5.begin(SerialEnable, I2CEnable, DisplayEnable);
    // https://twitter.com/wakwak_koba/status/1553162622479974400
    pinMode(0, OUTPUT);
    digitalWrite(0, LOW);
}
#elif defined(ARDUINO_M5STACK_ATOMS3)
#include <M5AtomS3.h>
inline void M5_BEGIN(bool LEDEnable = false) {
    AtomS3.begin(LEDEnable);
}
inline void M5_BEGIN(m5::M5Unified::config_t cfg, bool LEDEnable = false) {
    AtomS3.begin(cfg, LEDEnable);
}
#elif defined(ARDUINO_M5STACK_COREINK)
#include <M5CoreInk.h>
inline int M5_BEGIN(bool InkEnable = true, bool WireEnable = false,
                    bool SpeakerEnable = false) {
    return M5.begin(InkEnable, WireEnable, SpeakerEnable);
}
#elif defined(ARDUINO_M5STACK_STAMPS3)
#define FASTLED_INTERNAL
#include <FastLED.h>
#if defined(ARDUINO_M5STACK_DIAL) && defined(USE_M5STACK_OFFICIAL)
#include <M5Dial.h>
inline void M5_BEGIN(bool enableEncoder = false, bool enableRFID = false) {
    M5Dial.begin(enableEncoder, enableRFID);
}
inline void M5_BEGIN(m5::M5Unified::config_t cfg, bool enableEncoder = false,
                     bool enableRFID = false) {
    M5Dial.begin(cfg, enableEncoder, enableRFID);
}
#else
#include <Arduino.h>
inline void M5_BEGIN(void) {
}
#endif
#endif

inline void M5_UPDATE(void) {
#if defined(ARDUINO_M5STACK_CORES3) || \
    (defined(ARDUINO_M5STACK_STAMPS3) && !defined(ARDUINO_M5STACK_DIAL))
#elif defined(ARDUINO_M5STACK_ATOMS3) && defined(USE_M5STACK_OFFICIAL)
    AtomS3.update();
#else
    M5.update();
#endif
}
