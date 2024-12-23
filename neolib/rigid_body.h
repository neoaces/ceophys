#pragma once
#include <stddef.h>
#include <raylib.h>
#include "vec2.h"

/**
 * @brief Type of shape, used with struct Body
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
typedef struct Body {
    vec2 x;
    vec2 v;
    float* f; // Force accumulator
    size_t nf; // Number of forces currently in the accumulator
    float size;
    float mass; // m [kg]
    shape_e shape;
    Color color;
} body_t;