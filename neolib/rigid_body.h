#pragma once
#include "vec2.h"

typedef enum RigidShape {
    Circle = 0,
    Square = 1,
} shape_e;

typedef struct RigidBody {
    shape_e shape;
    float m;
    vec2 s;
    vec2 v;
    vec2 f; // This is our force accumulator, that collects all the forces in the x and y direction.
} rigidbody_t;