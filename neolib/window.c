#include "window.h"
#include <raylib.h>
#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

void draw(config_t* config) {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    GuiGroupBox((Rectangle){ 20, 20, 276, 312 }, "STANDARD");
    GuiTextBox((Rectangle){ 30, 67, 120, 24 }, "TEXT 1", 128, false);
    GuiTextBox((Rectangle){ 30, 37, 120, 24 }, "TEXT 2", 128, false);

    for (int i = 0; i < config->objects; i++) {
        body_t* body = config->bodies[i];
        DrawCircle(body->x * 10.0f, body->y * 10.0f, body->size * 10.0f, body->color);
    }

    EndDrawing();
}

void window_init(sconfig_t *config) {
    InitWindow(config->width, config->height, "neophys");
    SetTargetFPS(60);
    GuiSetStyle(DEFAULT, TEXT_SIZE, 15);
}

void window_close() {
    CloseWindow();
}
