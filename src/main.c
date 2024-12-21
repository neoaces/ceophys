#include "window.h"
#include <raylib.h>
#include <stdio.h>

int main() {
    sconfig_t config = {.width = 800, .height = 450};
    
    window_init(&config);

    // Main game loop
    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawCircle(120, 120, 20, BLACK); 
        EndDrawing();
    }

    window_close();

    return 0;
}