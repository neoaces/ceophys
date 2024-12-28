#pragma once
#include "app.h"

/**
 * @brief Initializes the physics engine.
 * 
 * @param config Global program configuration
 */
config_t* engine_init();
void engine_step(config_t* config);