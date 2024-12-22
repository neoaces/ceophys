#pragma once
#include <stdio.h>
#include "rigid_body.h"

/**
 * @brief Configuration for the raylib window
 * Currently only contains the width and height of the window.
 */
typedef struct ScreenConfig {
    int width;
    int height;
} sconfig_t;

/**
 * @brief Configuration for the current app.
 * 
 */
// TODO: Should be named as the engine state, or should be adequately abstracted.
typedef struct AppConfig {
    sconfig_t window_config;
    size_t objects;
    body_t** bodies;
} config_t;


