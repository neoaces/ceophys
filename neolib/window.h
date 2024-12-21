#pragma once
#include <raylib.h>

typedef struct ScreenConfig {
    int width;
    int height;
} sconfig_t;

void window_init(sconfig_t *config) {
    InitWindow(config->width, config->height, "neophys");
    SetTargetFPS(60);
}

void window_close() {
    CloseWindow();
}