#include "solver.h"

float rk4_solve(float x, float u, float (*f) (float, float)) {
    float k1 = f(x, u);
    float k2 = f(x + 0.5f * k1, u);
    float k3 = f(x + 0.5f * k2, u);
    float k4 = f(x + k3, u);
    return (1.0f / 6.0f) * (k1 + 2.0f * k2 + 2.0f * k3 + k4);
}