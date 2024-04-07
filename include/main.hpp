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
inline void M5_BEGIN(void) {
    CoreS3.begin();
}
inline void M5_BEGIN(m5::M5Unified::config_t& cfg) {
    CoreS3.begin(cfg);
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
#elif defined(ARDUINO_M5STACK_CARDPUTER) && defined(USE_M5STACK_OFFICIAL)
#include <M5Cardputer.h>
inline void M5_BEGIN(void) {
    M5Cardputer.begin();
    M5Cardputer.Lcd.setRotation(1);
}
inline void M5_BEGIN(m5::M5Unified::config_t& cfg) {
    M5Cardputer.begin(cfg);
}
#else
#include <Arduino.h>
inline void M5_BEGIN(void) {
}
#endif
#elif defined(ARDUINO_M5STACK_NANOC6)
#include <M5NanoC6.h>
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
    NanoC6.begin();
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
#if defined(ARDUINO_M5STACK_ATOMS3) && defined(USE_M5STACK_OFFICIAL)
    AtomS3.update();
#elif defined(ARDUINO_M5STACK_CORES3) && defined(USE_M5STACK_OFFICIAL)
    CoreS3.update();
#elif defined(ARDUINO_M5STACK_NANOC6) && defined(USE_M5STACK_OFFICIAL)
    NanoC6.update();
#elif defined(ARDUINO_M5STACK_STAMPS3) && defined(USE_M5STACK_OFFICIAL)
#if defined(AROUND_M5STACK_DIAL)
    M5Dial.update();
#elif defined(ARDUINO_M5STACK_CARDPUTER)
    M5Cardputer.update();
#else
    // M5.update() is not implemented
#endif
#else
    M5.update();
#endif
}
