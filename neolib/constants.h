#pragma once
#include <raylib.h>
#include <stdio.h>

// COORDINATE SYSTEM.
// We work with 10px = 1m.
// Thus the space looks like 160m * 100m.
static const float PX_TO_M = 0.1f;
static const float M_TO_PX = 10.0f;
static const size_t MAX_BODIES = 64;