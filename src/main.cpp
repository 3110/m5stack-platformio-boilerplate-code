// clang-format off
#include "main.hpp"
// clang-format on

void setup(void) {
    M5_BEGIN();
    M5DEV_LOGI("Hello, M5Stack!");
}

void loop(void) {
    M5_UPDATE();
}
