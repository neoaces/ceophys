#pragma once
#include "app.h"
// Using RK4

typedef float (*SolverFunc) (float, float*, float*); // t, x, x'

int get_dim(config_t* sys);
void _get_arr(float* x, float* dxdt, float n, particle_t** p);
float solve_particle(float* x0, float* xp, int len, float dt, particle_t** p);