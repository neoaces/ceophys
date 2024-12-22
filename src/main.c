#include <neolib/neolib.h>

int main() {
    sconfig_t window_config = {.width = 1600, .height = 1000};
    config_t config = {.window_config = window_config, 0 , NULL};
    
    window_init(&config.window_config);
    engine_init(&config);

    // Main game loop
    while (!WindowShouldClose()) {
        draw(&config); // Might cause segfault
    }

    window_close();

    return 0;
}