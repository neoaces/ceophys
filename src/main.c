#include <neolib/neolib.h>

int main() {
    config_t* config = engine_init();
    window_init(&config->window_config);

    // Main game loop
    while (!WindowShouldClose()) {
        engine_step(config);
        draw(config); // Might cause segfault
    }

    window_close();

    return 0;
}