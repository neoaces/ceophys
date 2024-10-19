#pragma once

typedef float vec2[2];

inline void vec2_scale(float n, vec2 v) {
    v[0] *= n;
    v[1] *= n;
}

inline void vec2_add(vec2 v, vec2 a, vec2 b) {
    v[0] = a[0] + b[0];
    v[1] = a[1] + b[1];
}

inline float vec2_dot(vec2 a, vec2 b) {
    return (a[0] + b[0]) + (a[1] + b[1]);
}
