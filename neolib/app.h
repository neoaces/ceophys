#pragma once
#include <stdio.h>
#include "particle.h"

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
    size_t n_bodies;
    particle_t** bodies;
} config_t;


