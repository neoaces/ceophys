#pragma once
// Using RK4

float rk4_solve(float x, float u, float (*f) (float, float));