#include "constants.h"
#include "window.h"
#include <_printf.h>
#include <raylib.h>
#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

void draw(config_t* config) {
BeginDrawing();
    ClearBackground(WHITE);
    
    for (int i = 0; i < config->n_bodies; i++) {
        particle_t* body = config->bodies[i];
        DrawCircle(body->x.x * M_TO_PX, body->x.y * M_TO_PX, body->size * M_TO_PX, body->color);
    }
    
    GuiLabel((Rectangle){ 20, 20, 300, 20 }, "neophys - a physics engine simulator");
    GuiGroupBox((Rectangle){ 20, 60, 276, 312 }, "STANDARD");
    GuiLabel((Rectangle){ 30, 75, 200, 20 }, "OBJECT 1");
    GuiSliderBar((Rectangle){ 30, 95, 200, 20 }, "", " X", &config->bodies[0]->x.x, 0.0f, (config->window_config.width / 10.0f));
    GuiSliderBar((Rectangle){ 30, 125, 200, 20 }, "", " Y", &config->bodies[0]->x.y, 0.0f, (config->window_config.height / 10.0f));
    GuiLabel((Rectangle){ 30, 165, 600, 20 }, TextFormat("# OF BODIES: %d", config->n_bodies));
    GuiLabel((Rectangle){ 30, 190, 600, 20 }, TextFormat("# OF FORCES: %d", config->n_forces));
    GuiLabel((Rectangle){ 30, 215, 600, 20 }, TextFormat("FORCE: %.4fN", config->bodies[0]->f));
    GuiLabel((Rectangle){ 30, 240, 600, 20 }, TextFormat("MASS: %fkg", config->bodies[0]->mass));

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
