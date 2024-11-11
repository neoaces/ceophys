#include "constants.h"
#include "models.h"
#include <stdlib.h> // IWYU pragma: keep

force_t* GravityForce(rigidbody_t** bodies, size_t n_bodies) {
    force_t* g = malloc(sizeof(force_t));
    g->bodies = bodies;
    g->n_bodies = n_bodies;
    g->f = _gravity_force;
    
    return g;
}

float _gravity_force(rigidbody_t* state) {
    return -1.0f * state->m * G_CONSTANT;
}