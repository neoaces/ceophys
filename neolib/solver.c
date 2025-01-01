#include "solver.h"
#include "app.h"
#include "force.h"
#include "neolib/particle.h"

int get_dim(config_t* sys) {
    return 4 * sys->n_bodies;
}

/**
 * @brief Returns the state [dx/dt, dy/dt, dvx/dt, dvy/dt] for a given particle p.
 * 
 * @param x Two-dim position vector
 * @param v Two-dim velocity vector
 * @param dxdt Destination vector
 * @param p Particle affected
 */
void _get_arr(float* x, float* dxdt, float n, particle_t** p) {
    for (int i = 0; i < n; i++) {
        // x += 2; // Jump two indices forward, we only need the velocity.
        
        *(dxdt++) = x[4 * i + 2];
        *(dxdt++) = x[4 * i + 3];
        *(dxdt++) = 0.0f; // Keep the x force 0 for now.
        *(dxdt++) = p[i]->f / p[i]->mass; // The current force_gravity() only returns the acceleration.
    }
}

float solve_particle(float* x0, float* xp, int len, float dt, particle_t** p) {
    int n = len / 4; // Number of particles (in order to abstract out 2d physics.)
    
    float k1[n], k2[n], k3[n], k4[n], temp[n]; // These will hold the k1-k4 values for each element x and v.
    // k1
    _get_arr(x0, k1, n, p);
    for (int i = 0; i < n; i++) { k1[i] *= dt; };

    // k2
    for (int i = 0; i < n; i++) { temp[i] = x0[i] + k1[i] / 2.0f; }
    _get_arr(temp, k2, n, p);
    for (int i = 0; i < n; i++) { k2[i] *= dt; };

    // k3
    for (int i = 0; i < n; i++) { temp[i] = x0[i] + k2[i] / 2.0f; }
    _get_arr(temp, k3, n, p);
    for (int i = 0; i < n; i++) { k3[i] *= dt; };

    // k4
    for (int i = 0; i < n; i++) { temp[i] = x0[i] + k3[i]; }
    _get_arr(temp, k4, n, p);
    for (int i = 0; i < n; i++) { k4[i] *= dt; };

    // Update all the relevant vectors.
    for (int i = 0; i < len; i++) {
        xp[i] = (k1[i] / 6.0f) + (k2[i] / 3.0f) + (k3[i] / 3.0f) + (k4[i] / 6.0f);
    }
};