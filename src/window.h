#pragma once
#define CIMGUI_DEFINE_ENUMS_AND_STRUCTS
#define CIMGUI_USE_GLFW
#define CIMGUI_USE_OPENGL3
#include <GLFW/glfw3.h>
#include <cimgui/cimgui.h>
#include <cimgui/generator/output/cimgui_impl.h>
#include <neolib/engine.h>

typedef struct WindowConfig {
    GLFWwindow* window;
    ImGuiIO* ioptr;
    ImVec4 clearColor;
} windowconfig_t;

windowconfig_t* window_init(systemstate_t* state);
void window_destroy(windowconfig_t* config);
