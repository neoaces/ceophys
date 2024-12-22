#pragma once
#include <raylib.h>

/**
 * @brief Type of shape, used with struct Body
 * 
 */
typedef enum Shape {
    Circle,
    Square,
} shape_e;

/**
 * @brief Represents a 2D rigid body in coordinate space.
 * 
 * Note that both the coordinates and size are in metres. Use the appropriate constants in constants.h to convert.
 */
// TODO: Convert coordinates to be based off the bottom left origin
typedef struct Body {
    float x;
    float y;
    float size;
    shape_e shape;
    Color color;
} body_t;