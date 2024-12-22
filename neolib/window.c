#include "constants.h"
#include "window.h"
#include <raylib.h>
#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

void draw(config_t* config) {
    BeginDrawing();
    ClearBackground(WHITE);
    
    for (int i = 0; i < config->objects; i++) {
        body_t* body = config->bodies[i];
        DrawCircle(body->x * M_TO_PX, body->y * M_TO_PX, body->size * M_TO_PX, body->color);
    }
    
    GuiLabel((Rectangle){ 20, 20, 300, 20 }, "neophys - a physics engine simulator");
    GuiGroupBox((Rectangle){ 20, 60, 276, 312 }, "STANDARD");
    GuiLabel((Rectangle){ 30, 75, 200, 20 }, "object 1");
    GuiSliderBar((Rectangle){ 30, 95, 200, 20 }, "", " X", &config->bodies[0]->x, 0.0f, (config->window_config.width / 10.0f));
    GuiSliderBar((Rectangle){ 30, 125, 200, 20 }, "", " Y", &config->bodies[0]->y, 0.0f, (config->window_config.height / 10.0f));


    EndDrawing();
}

void window_init(sconfig_t *config) {
    InitWindow(config->width, config->height, "neophys");
    SetTargetFPS(60);
    GuiSetStyle(DEFAULT, TEXT_SIZE, 15);
    SetWindowState(FLAG_WINDOW_UNDECORATED); // Removes all decoration from window
}

void window_close() {
    CloseWindow();
}
