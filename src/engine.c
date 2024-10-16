#include <neolog/neolog.h>
#include "engine.h"

static nlog_logger_t log_config = {.LogLevel = DEBUG, "neophys::engine"};

systemstate_t* system_init(float time_step) {
    systemstate_t* state = malloc(sizeof(systemstate_t));
    state->time_step = time_step;

    nlog_log(&log_config, DEBUG, "System initialized with timestep %f", time_step);

    return state;
}

void system_destroy(systemstate_t* state) {
    free(state);
}
