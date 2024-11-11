#include <math.h>
#include <neolog/neolog.h>
#include <string.h>
#include "engine.h"
#include "neolib/constants.h"
#include "neolib/models.h"
#include "rigid_body.h"

// NOTE: we determine the window coordinates from -960, 960 and -540, 540.
// This maps to 19.20m in width, and 10.80m in length.

static nlog_logger_t log_config = {.LogLevel = DEBUG, "neophys::engine"};

systemstate_t* system_init(float time_step, _Bool gravity) {
    systemstate_t* state = malloc(sizeof(systemstate_t));

    state->time_step = time_step;
    state->bodies = malloc(sizeof(rigidbody_t) * MAX_BODIES);
    state->n_bodies = 0;
    state->forces = malloc(sizeof(force_t) * MAX_FORCES);
    state->n_forces = 0;

    add_body(state, 20, NULL, NULL);

    if (gravity) {
        state->forces[0] = GravityForce(state->bodies, state->n_bodies);
        state->n_forces++;
    }
    
    nlog_log(&log_config, DEBUG, "System initialized with timestep %f", time_step);

    return state;
}

void system_destroy(systemstate_t* state) {
    free(state);
}

void generate_circle(rigidbody_t* body, systemstate_t* state, float circle[CIRCLE_RES * 2]) {
    circle[0] = (body->s[0]) / (state->width / 2.0f);
    circle[1] = (body->s[1]) / (state->height / 2.0f);
    
    for (int i = 0; i < CIRCLE_RES - 2; i++) {
	    circle[(i+1)*2 + 0] = (state->particle_size * cosf(i*2*M_PI / (CIRCLE_RES - 3)) + body->s[0])/(state->width / 2.0f);
	    circle[(i+1)*2 + 1] = (state->particle_size * sinf(i*2*M_PI / (CIRCLE_RES - 3)) + body->s[1])/(state->height / 2.0f);
    }
    
    nlog_log(&log_config, DEBUG, "Current circle coordinates: %f, %f", state->bodies[0]->s[0], state->bodies[0]->s[1]);
}

void step(systemstate_t* state, int n_force, float (*force[n_force]) (float, float)) {

}

void add_body(systemstate_t* state, double mass, double s[2], double v[2]) {
    rigidbody_t* body = malloc(sizeof(rigidbody_t));
    
    if (s == NULL) {
        memset(body->s, 0, 2);
    } if (v == NULL) {
        memset(body->v, 0, 2);
    }

    state->bodies[(state->n_bodies)++] = body;

}