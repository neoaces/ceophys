#pragma once
#include "engine.h"
#include "window.h"

/**
 * @brief Runs the main rendering loops. Takes care of the window as well as the engine renderer. Not meant to be used without run().
 *
 * @param config Window config
 * @return Returns 0 on correct execution.
 */
int render(windowconfig_t* config);

/**
 * @brief Runs the app loop.
 *
 * @param config Window config
 */
void run(windowconfig_t* config, systemstate_t* state);
