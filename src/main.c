#include <neolib/hmap.h>
#include <neolog/neolog.h>
#include "app.h"
#include "engine.h"
#include "window.h"

static const nlog_logger_t logger_config = {.LogLevel = DEBUG, "neophys"};

int main(void) {
    systemstate_t* state = system_init(0.05);
    windowconfig_t* config = window_init();
    run(config, state);
    system_destroy(state);
    
    return 0;
}
