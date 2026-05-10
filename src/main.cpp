// clang-format off
#include "main.hpp"
// clang-format on

void setup(void) {
    M5_BEGIN();
    M5DEV_LOGI("Hello, M5Stack!");
#ifdef BUILD_REPO
    M5DEV_LOGI("repo:  " BUILD_REPO);
#endif
#ifdef BUILD_SHA
    M5DEV_LOGI("sha:   " BUILD_SHA);
#endif
#ifdef BUILD_TAG
    M5DEV_LOGI("tag:   " BUILD_TAG);
#endif
#ifdef BUILD_DATE
    M5DEV_LOGI("built: " BUILD_DATE);
#endif
#ifdef BUILD_FIRMWARE_URI
    M5DEV_LOGI("uri:   " BUILD_FIRMWARE_URI);
#endif
}

void loop(void) {
    M5_UPDATE();
}
