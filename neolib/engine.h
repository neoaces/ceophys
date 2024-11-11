#pragma once
#include "constants.h"
#include "models.h"
#include "rigid_body.h" 
#include <stdlib.h> // IWYU pragma: keep

typedef struct SystemState {
    float del_time;

    unsigned int VAO;
    unsigned int VBO;
    unsigned int shader_obj;
    float width;
    float height;

    // Configuration
    float time_step;
    float particle_size;
    float particle_color[4];
    
    rigidbody_t** bodies; // Store as pointers; I predict that we will need to move around bodies a lot.
    size_t n_bodies;
    
    force_t** forces;
    size_t n_forces;
} systemstate_t;

systemstate_t* system_init(float time_step, _Bool gravity);
void system_destroy(systemstate_t* state);
void add_body(systemstate_t* state, double mass, double s[2], double v[2]);
void step(systemstate_t* state, int n_force, float (*force[n_force]) (float, float));
void generate_circle(rigidbody_t* body, systemstate_t* state, float circle[CIRCLE_RES * 2]);