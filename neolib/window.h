#pragma once
#include "app.h"

/**
 * @brief Draws the current iteration. Does not handle physics
 * 
 * @param config Global program configuration
 */
void draw(config_t* config);

/**
 * @brief Initializes the current window. Config must be initialized beforehand.
 * 
 * @param config Global window configuration
 */
void window_init(sconfig_t *config);

/**
 * @brief Destroys the current window.
 * 
 */
void window_close();