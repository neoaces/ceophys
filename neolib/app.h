#pragma once
#include <stdio.h>
#include "particle.h"
#include "force.h"

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
    particle_t** bodies;
    int n_bodies;
    force_t** forces;
    int n_forces;
} config_t;


