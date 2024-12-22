#include "constants.h"
#include "window.h"
#include <raylib.h>
#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

void draw(config_t* config) {
    BeginDrawing();

    Color background = {.r = 2, .g = 46, .b = 58, .a = 255};
    ClearBackground(background);

    GuiGroupBox((Rectangle){ 20, 20, 276, 312 }, "STANDARD");
    GuiTextBox((Rectangle){ 30, 67, 120, 24 }, "TEXT 1", 128, false);
    GuiTextBox((Rectangle){ 30, 37, 120, 24 }, "TEXT 2", 128, false);

    for (int i = 0; i < config->objects; i++) {
        body_t* body = config->bodies[i];
        DrawCircle(body->x * M_TO_PX, body->y * M_TO_PX, body->size * M_TO_PX, body->color);
    }

    EndDrawing();
}

void window_init(sconfig_t *config) {
    InitWindow(config->width, config->height, "neophys");
    SetTargetFPS(60);
    GuiLoadStyle("./static/style.rgs");
    GuiSetStyle(DEFAULT, TEXT_SIZE, 20);
}

void window_close() {
    CloseWindow();
}
