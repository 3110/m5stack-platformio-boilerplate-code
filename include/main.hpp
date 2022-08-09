#pragma once

#if defined(TARGET_M5STACK_BASIC)
#include <M5Stack.h>
#elif defined(TARGET_M5STACK_CORE2)
#include <M5Core2.h>
#elif defined(TARGET_M5STICK_C_PLUS)
#include <M5StickCPlus.h>
#elif defined(TARGET_M5STACK_ATOM)
#include <M5Atom.h>
#elif defined(TARGET_M5STACK_CORE_INK)
#include <M5CoreInk.h>
#elif defined(TARGET_M5STACK_PAPER)
#include <M5EPD.h>
#endif
