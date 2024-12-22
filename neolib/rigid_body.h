#pragma once
#include <raylib.h>

typedef enum Shape {
    Circle,
    Square,
} shape_e;

typedef struct Body {
    float x;
    float y;
    float size; // Size in m
    shape_e shape;
    Color color;
} body_t;