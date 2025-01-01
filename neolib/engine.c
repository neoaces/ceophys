#include <stdlib.h>
#include "constants.h"
#include "engine.h"
#include "solver.h"
#include "app.h"
#include "force.h"
#include "raylib.h"
#include "particle.h"
#include <neolog.h>

LOGGER_CONFIG LOG_CONF = {DEBUG, "neolib::engine"};

config_t* engine_init() {
    config_t* config = malloc(sizeof(config_t));
    sconfig_t window_config = {.width = 1600, .height = 1000};

    config->window_config = window_config;

    // TEST IMPLEMENTATION 1: add a body by default
    particle_t** bodies = calloc(64, sizeof(particle_t*));
    particle_t* test_particle = malloc(sizeof(particle_t));
    test_particle->x.x = config->window_config.width / 20.0f;
    test_particle->x.y = config->window_config.height / 20.0f;
    test_particle->v.x = 0.0f;
    test_particle->v.y = 0.0f;
    test_particle->color = BLACK;
    test_particle->shape = Circle;
    test_particle->size = 3.0f;
    test_particle->mass = 13.3f;

    bodies[0] = test_particle;

    config->bodies = bodies;
    config->n_bodies = 1;

    // TEST IMPL. 2: add the gravity force by default.
    force_t** forces = calloc(64, sizeof(force_t*));
    force_t* test_force = malloc(sizeof(force_t));
    test_force->affected = calloc(64, sizeof(particle_t*));

    test_force->f = FORCES[GRAVITY];
    test_force->affected[0] = test_particle;
    test_force->n_affected = 1;

    forces[0] = test_force;

    config->forces = forces;
    config->n_forces = 1;
    
    return config;
}

void engine_iterf(config_t* sys) {
    for (int i = 0; i < sys->n_forces; i++) {
        apply_f(sys->forces[i]);
    }
}

void engine_step(config_t* sys) {
    // 1. Zero all force accumulators
    for (int i = 0; i < sys->n_bodies; i++) {
        float current_force = sys->bodies[i]->f;
        
        if (sys->bodies[i]->GUI_F != current_force && current_force != 0.0f) {
           sys->bodies[i]->GUI_F = current_force;
        }

        sys->bodies[i]->f = 0;
    }

    // 2. Collision detection
    engine_detect_collisions(sys);

    // 3. Calculate forces for all objects
    engine_iterf(sys);

    // 4. Solve
    engine_solve(sys);
};

void _system_to_arr(config_t* sys, float* x0, int len) {
    for (int i = 0; i < (len / 4); i++) {
        *(x0++) = (sys->bodies[i]->x.x);
        *(x0++) = (sys->bodies[i]->x.y);
        *(x0++) = (sys->bodies[i]->v.x);
        *(x0++) = (sys->bodies[i]->v.y);
    }
}

void engine_solve(config_t *config) {
    int dim = get_dim(config);
    
    float x0[dim], dxdt[dim];
    _system_to_arr(config, x0, dim);
    
    float dt = GetFrameTime();
    solve_particle(x0, dxdt, dim, dt, config->bodies);

    for (int i = 0; i < (dim / 4); i++) {
        config->bodies[i]->x.x += dxdt[0] * dt;
        config->bodies[i]->x.y += dxdt[1] * dt;
        config->bodies[i]->v.x += dxdt[2] * dt;
        config->bodies[i]->v.y += dxdt[3] * dt;
    }

    nlog_log(&LOG_CONF, DEBUG, "STATE: [%f, %f, %f, %f] with dt %.04f",
        config->bodies[0]->x.x,
        config->bodies[0]->x.y,
        config->bodies[0]->v.x,
        config->bodies[0]->v.y,
        dt
    );
}


void engine_detect_collisions(config_t* config) {
    // TEST: simple collision detection with walls
    
};