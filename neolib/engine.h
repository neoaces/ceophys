#pragma once
#include "constants.h"
#include "rigid_body.h" 
#include <stdlib.h> // IWYU pragma: keep

typedef struct SystemState {
    float time_step;
    float del_time;
    unsigned int VAO;
    unsigned int VBO;
    unsigned int shader_obj;
    float size;
    float particle_color[4];
    rigidbody_t* body;

    float width;
    float height;
} systemstate_t;

systemstate_t* system_init(float time_step);
void system_destroy(systemstate_t* state);
void add_body(systemstate_t* state);
void step(systemstate_t* state);
void generate_circle(systemstate_t* state, float circle[CIRCLE_RES * 2]);