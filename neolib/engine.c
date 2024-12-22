#include <stdlib.h>
#include "constants.h"
#include "engine.h"
#include "raylib.h"
#include "rigid_body.h"

void engine_init(config_t* config) {
    // TEST IMPLEMENTATION: add a body by default
    config->objects = 1;

    body_t** bodies = calloc(64, sizeof(body_t*));

    body_t* test_body = malloc(sizeof(body_t));
    test_body->x = config->window_config.width / 20.0f;
    test_body->y = config->window_config.height / 20.0f;
    test_body->color = WHITE;
    test_body->shape = Circle;
    test_body->size = 3.0f;

    bodies[0] = test_body;

    config->bodies = bodies;
}