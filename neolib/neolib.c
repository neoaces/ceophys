#include "neolib.h"
#include <raylib.h>

#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

void draw() {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    GuiButton((Rectangle){ 24, 24, 120, 25 }, "#191#Show Message");
    DrawCircle(120, 120, 20, BLACK); 
    EndDrawing();
}