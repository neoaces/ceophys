#include <assert.h>
#include <glad/gl.h>
#include <neolog/neolog.h>
#include <stdlib.h>
#include <stdio.h>
#include "window.h"
#include "cimgui/cimgui.h"

static const nlog_logger_t logger_config = {.LogLevel = DEBUG, .process_name = "neolib"};

windowconfig_t* window_init() {
    windowconfig_t* config = malloc(sizeof(windowconfig_t));

    if (!glfwInit()) {
	nlog_logerr(&logger_config, "GLFW did not initialize. Aborting.", -1);
    }

    // Set GLFW defaults
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);

    config->window = glfwCreateWindow(800, 800, "neophys", NULL, NULL);
    
    if (!config->window) {
	glfwTerminate();
	nlog_logerr(&logger_config, "Window did not initialize properly.", 100);
    }
    
    glfwMakeContextCurrent(config->window);
    gladLoadGL(glfwGetProcAddress);
    glfwSwapInterval(1);

    igCreateContext(NULL);
    config->ioptr = igGetIO();

    const char *glsl_version = "#version 150"; // Recommended version for MacOS TODO: change to 130 for other platforms
    ImGui_ImplGlfw_InitForOpenGL(config->window, true); 
    ImGui_ImplOpenGL3_Init(glsl_version);

    // TODO allow customization of background
    config->clearColor.x = 0.45f;
    config->clearColor.y = 0.55f;
    config->clearColor.z = 0.60f;
    config->clearColor.w = 1.00f;
    
    assert(config->ioptr != NULL);
    assert(config->window != NULL);
    
    return config;
};

void window_destroy(windowconfig_t* config) {
    // clean up
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    igDestroyContext(NULL);

    glfwDestroyWindow(config->window);
    glfwTerminate();   
}

