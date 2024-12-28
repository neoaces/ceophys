#pragma once
#include "particle.h"
#include "pconstants.h"

typedef float (*ForceFunc) (particle_t*);

typedef enum ForceType {
    GRAVITY = 0,
} forcetype_t;

/**
 * @brief Represents a force on one or more particles
 * 
 */
typedef struct Force {
    particle_t** affected;
    size_t n_affected;
    float (*f)(particle_t*);
} force_t;
// FUTURE: expand the functions into a custom runtime jump-table

void apply_f(force_t* force);

/* 
 * IN-BUILT FORCES 
*/

float force_gravity(particle_t* particle);

/*
*  JUMP TABLE
*/
static const ForceFunc FORCES[1] = {
    &force_gravity,
};
