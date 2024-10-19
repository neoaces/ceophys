#include <neolog/neolog.h>
#include "app.h"
#include <neolib/engine.h>
#include "window.h"

int main(void) {
    systemstate_t* state = system_init(0.05);
    
    windowconfig_t* config = window_init(state);
    run(config, state);
    system_destroy(state);
    
    return 0;
}