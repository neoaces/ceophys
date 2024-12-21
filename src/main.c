#include <neolib/window.h>
#include <neolib/neolib.h>
#include <raylib.h>
#include <stdio.h>

int main() {
    sconfig_t config = {.width = 1920, .height = 1080};
    
    window_init(&config);

    // Main game loop
    while (!WindowShouldClose()) {
        draw();
    }

    window_close();

    return 0;
}