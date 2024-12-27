#include <stdlib.h>
#include "constants.h"
#include "engine.h"
#include "raylib.h"
#include "particle.h"

void engine_init(config_t* config) {
    // TEST IMPLEMENTATION: add a body by default

    particle_t** bodies = calloc(64, sizeof(particle_t*));
    particle_t* test_body = malloc(sizeof(particle_t));

    test_body->x.x = config->window_config.width / 20.0f;
    test_body->x.y = config->window_config.height / 20.0f;
    test_body->color = BLACK;
    test_body->shape = Circle;
    test_body->size = 3.0f;

    bodies[0] = test_body;

    config->bodies = bodies;
    config->n_bodies = 1;
}