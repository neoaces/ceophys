#pragma once
#include <stdio.h>
#include "rigid_body.h"

typedef struct ScreenConfig {
    int width;
    int height;
} sconfig_t;

typedef struct AppConfig {
    sconfig_t window_config;
    size_t objects;
    body_t** bodies;
} config_t;


