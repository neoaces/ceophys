#include <math.h>
#include <neolog/neolog.h>
#include "engine.h"
#include "neolib/constants.h"
#include "rigid_body.h"

// NOTE: we determine the window coordinates from -960, 960 and -540, 540.
// This maps to 19.20m in width, and 10.80m in length.

static nlog_logger_t log_config = {.LogLevel = DEBUG, "neophys::engine"};

systemstate_t* system_init(float time_step) {
    systemstate_t* state = malloc(sizeof(systemstate_t));
    state->time_step = time_step;
    rigidbody_t* body = malloc(sizeof(rigidbody_t));
    body->s[0] = 0.0f;
    body->s[1] = 0.0f;
    body->v[0] = 0.0f;
    body->v[1] = 0.0f;
    state->body = body;

    nlog_log(&log_config, DEBUG, "System initialized with timestep %f", time_step);

    return state;
}

void system_destroy(systemstate_t* state) {
    free(state);
}

void generate_circle(systemstate_t* state, float circle[CIRCLE_RES * 2]) {
    circle[0] = (state->body->s[0]) / (state->width / 2.0f);
    circle[1] = (state->body->s[1]) / (state->height / 2.0f);
    for (int i = 0; i < CIRCLE_RES-2; i++) {
	    circle[(i+1)*2 + 0] = (state->size * cosf(i*2*M_PI / (CIRCLE_RES - 3)) + state->body->s[0])/(state->width / 2.0f);
	    circle[(i+1)*2 + 1] = (state->size * sinf(i*2*M_PI / (CIRCLE_RES - 3)) + state->body->s[1])/(state->height / 2.0f);
    }
    nlog_log(&log_config, DEBUG, "Scalar used in x: %f", state->width/2.0f);
}