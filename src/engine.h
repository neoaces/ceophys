#pragma once
#include <neolib/hmap.h>
#include <stdlib.h> // IWYU pragma: keep

typedef struct SystemState {
    float time_step;
    float del_time;
    node_t* bodies;
} systemstate_t;

systemstate_t* system_init(float time_step);
void system_destroy(systemstate_t* state);
