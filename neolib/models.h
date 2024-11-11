#pragma once
#include "constants.h"
#include "rigid_body.h"
#include <stdio.h> // IWYU pragma: keep

typedef struct Force {
    rigidbody_t** bodies;
    size_t n_bodies;

    float (*f) (rigidbody_t*); // Takes in a function pointer to calculate the forces on each object
} force_t;

force_t* GravityForce(rigidbody_t** bodies, size_t n_bodies);
float _gravity_force(rigidbody_t* state);