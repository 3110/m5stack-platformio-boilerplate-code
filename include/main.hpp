#pragma once

#if defined(USE_M5STACK_OFFICIAL) || defined(USE_M5UNIFIED)
#define M5DEV M5
#endif

#if defined(USE_M5UNIFIED) && !defined(USE_M5STACK_OFFICIAL)
// clang-format off
#include <M5Unified.h>
#if defined(USE_FASTLED)
#define FASTLED_INTERNAL
#include <FastLED.h>
#endif
// clang-format on
inline void M5_BEGIN(void) {
    M5DEV.begin();
}
inline void M5_BEGIN(m5::M5Unified::config_t& cfg) {
    M5DEV.begin(cfg);
}
#elif defined(ARDUINO_M5STACK_BASIC) || defined(ARDUINO_M5STACK_FIRE) || \
    defined(ARDUINO_M5STACK_M5GO)
#include <M5Stack.h>
inline void M5_BEGIN(bool LCDEnable = true, bool SDEnable = true,
                     bool SerialEnable = true, bool I2CEnable = false) {
    M5DEV.begin(LCDEnable, SDEnable, SerialEnable, I2CEnable);
}
#elif defined(ARDUINO_M5STACK_PAPER)
#include <M5EPD.h>
inline void M5_BEGIN(bool TouchEnable = true, bool SDEnable = true,
                     bool SerialEnable = true, bool BatteryADCEnable = true,
                     bool I2CEnable = false) {
    M5DEV.begin(TouchEnable, SDEnable, SerialEnable, BatteryADCEnable,
                I2CEnable);
}
#elif defined(ARDUINO_M5STACK_CORE2)
#include <M5Core2.h>
inline void M5_BEGIN(bool LCDEnable = true, bool SDEnable = true,
                     bool SerialEnable = true, bool I2CEnable = false,
                     mbus_mode_t mode = kMBusModeOutput) {
    M5DEV.begin(LCDEnable, SDEnable, SerialEnable, I2CEnable, mode);
}
#elif defined(ARDUINO_M5STACK_CORES3)
#undef M5DEV
#define M5DEV CoreS3
#include <M5CoreS3.h>
inline void M5_BEGIN(void) {
    M5DEV.begin();
}
inline void M5_BEGIN(m5::M5Unified::config_t& cfg) {
    M5DEV.begin(cfg);
}
#elif defined(ARDUINO_M5STICK_C)
#include <M5StickC.h>
inline void M5_BEGIN(bool LCDEnable = true, bool PowerEnable = true,
                     bool SerialEnable = true) {
    M5DEV.begin(LCDEnable, PowerEnable, SerialEnable);
}
#elif defined(ARDUINO_M5SICK_C_PLUS)
#include <M5StickCPlus.h>
inline void M5_BEGIN(bool LCDEnable = true, bool PowerEnable = true,
                     bool SerialEnable = true) {
    M5DEV.begin(LCDEnable, PowerEnable, SerialEnable);
}
#elif defined(ARDUINO_M5STACK_ATOM)
#include <M5Atom.h>
inline void M5_BEGIN(bool SerialEnable = true, bool I2CEnable = true,
                     bool DisplayEnable = false) {
    M5DEV.begin(SerialEnable, I2CEnable, DisplayEnable);
    // https://twitter.com/wakwak_koba/status/1553162622479974400
    pinMode(0, OUTPUT);
    digitalWrite(0, LOW);
}
#elif defined(ARDUINO_M5STACK_ATOMS3)
#include <M5AtomS3.h>
#undef M5DEV
#define M5DEV AtomS3
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
    return M5DEV.begin(InkEnable, WireEnable, SpeakerEnable);
}
#elif defined(ARDUINO_M5STACK_STAMPS3)
#define FASTLED_INTERNAL
#include <FastLED.h>
#if defined(ARDUINO_M5STACK_DIAL) && defined(USE_M5STACK_OFFICIAL)
#include <M5Dial.h>
#undef M5DEV
#define M5DEV M5Dial
inline void M5_BEGIN(bool enableEncoder = false, bool enableRFID = false) {
    M5DEV.begin(enableEncoder, enableRFID);
}
inline void M5_BEGIN(m5::M5Unified::config_t cfg, bool enableEncoder = false,
                     bool enableRFID = false) {
    M5DEV.begin(cfg, enableEncoder, enableRFID);
}
#elif defined(ARDUINO_M5STACK_CARDPUTER) && defined(USE_M5STACK_OFFICIAL)
#include <M5Cardputer.h>
#undef M5DEV
#define M5DEV M5Cardputer
inline void M5_BEGIN(void) {
    M5DEV.begin();
}
inline void M5_BEGIN(m5::M5Unified::config_t& cfg) {
    M5DEV.begin(cfg);
}
#elif defined(ARDUINO_M5STACK_DIN_METER) && defined(USE_M5STACK_OFFICIAL)
#include <M5DinMeter.h>
#undef M5DEV
#define M5DEV DinMeter
inline void M5_BEGIN(void) {
    M5DEV.begin();
    M5DEV.Lcd.setRotation(1);
}
inline void M5_BEGIN(m5::M5Unified::config_t& cfg) {
    M5DEV.begin(cfg);
}
#else
#include <Arduino.h>
inline void M5_BEGIN(void) {
}
#endif
#elif defined(ARDUINO_M5STACK_NANOC6)
#include <M5NanoC6.h>
#undef M5DEV
#define M5DEV NanoC6
#if defined(USE_BLUE_LED)
inline void setLED(bool on) {
    digitalWrite(M5NANO_C6_BLUE_LED_PIN, on ? HIGH : LOW);
}
#endif
#if defined(USE_RGB_LED)
#include <Adafruit_NeoPixel.h>
#define NUM_LEDS 1
Adafruit_NeoPixel RGB_LED(NUM_LEDS, M5NANO_C6_RGB_LED_DATA_PIN,
                          NEO_GRB + NEO_KHZ800);
inline void setRGB(uint8_t r, uint8_t g, uint8_t b, bool show = true) {
    RGB_LED.setPixelColor(0, RGB_LED.Color(r, g, b));
    if (show) {
        RGB_LED.show();
    }
}
#endif
inline void M5_BEGIN(void) {
    M5DEV.begin();
#if defined(USE_RGB_LED)
    pinMode(M5NANO_C6_RGB_LED_PWR_PIN, OUTPUT);
    digitalWrite(M5NANO_C6_RGB_LED_PWR_PIN, HIGH);
    RGB_LED.begin();
#endif
#if defined(USE_BLUE_LED)
    pinMode(M5NANO_C6_BLUE_LED_PIN, OUTPUT);
#endif
}
#endif

inline void M5_UPDATE(void) {
#if defined(USE_M5STACK_OFFICIAL) || defined(USE_M5UNIFIED)
    M5DEV.update();
#endif
}

#if defined(USE_M5UNIFIED)
#define M5DEV_LOGE M5_LOGE
#define M5DEV_LOGW M5_LOGW
#define M5DEV_LOGI M5_LOGI
#define M5DEV_LOGD M5_LOGD
#define M5DEV_LOGV M5_LOGV
#else
#define M5DEV_LOGE(format, ...) log_e("[%s] " format, "M5BP", ##__VA_ARGS__)
#define M5DEV_LOGW(format, ...) log_w("[%s] " format, "M5BP", ##__VA_ARGS__)
#define M5DEV_LOGI(format, ...) log_i("[%s] " format, "M5BP", ##__VA_ARGS__)
#define M5DEV_LOGD(format, ...) log_d("[%s] " format, "M5BP", ##__VA_ARGS__)
#define M5DEV_LOGV(format, ...) log_v("[%s] " format, "M5BP", ##__VA_ARGS__)
#endif
