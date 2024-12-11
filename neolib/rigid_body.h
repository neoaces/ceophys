#pragma once
#include "vec2.h"

typedef enum RigidShape {
    Circle = 0,
    Square = 1,
} shape_e;

typedef struct RigidBody {
    shape_e shape;
    float m;
    union { // Holds the size of the rigid body. Currently only supports circles and squares 
        float r;
        struct {float x; float y;};
    };
    vec2 s;
    vec2 v;
    vec2 f; // This is our force accumulator, that collects all the forces in the x and y direction.
} rigidbody_t;

typedef struct Boundary {
    float x;
    float y;
    float w;
    float h;
} bounds_t;

bounds_t get_bounds(rigidbody_t *body) {
    bounds_t bounds;
    switch (body->shape) {
        case Circle:
            bounds.x = body->s[0];
            bounds.y = body->s[1];
            bounds.w = body->r;
            bounds.h = body->r;
            break;
        case Square:
            bounds.x = body->s[0];
            bounds.y = body->s[1];
            bounds.w = body->x;
            bounds.h = body->y;
            break;
    }

    return bounds;
}

// TODO: add functions to get vertices of bounds