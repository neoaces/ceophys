#pragma once
#include <stddef.h>
#include <raylib.h>
#include "vec2.h"

/**
 * @brief Type of shape, used with struct Particle
 * 
 */
typedef enum Shape {
    Circle,
    Square,
    Anchor, // Shape, no real size
} shape_e;

/**
 * @brief Represents a 2D rigid body in coordinate space.
 * 
 * Note that both the coordinates and size are in metres. Use the appropriate constants in constants.h to convert.
 */
// TODO: Convert coordinates to be based off the bottom left origin
typedef struct Particle {
    vec2 x;
    vec2 v;
    float GUI_F; // Take last value of f non-zero.
    float f; // Force accumulator
    size_t nf; // Number of forces currently in the accumulator
    float size;
    float mass; // m [kg]
    shape_e shape;
    Color color;
} particle_t;