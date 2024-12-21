#pragma once

typedef enum Shape {
    Circle,
    Square,
} shape_e;

typedef struct Body {
    float x;
    float y;
    shape_e shape;
} body_t;