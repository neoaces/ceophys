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
	exit(-1);
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

    const char *glsl_version = "#version 150";
    ImGui_ImplGlfw_InitForOpenGL(config->window, true); 
    ImGui_ImplOpenGL3_Init(glsl_version);

    bool showDemoWindow = true;
    bool showAnotherWindow = false;
    
    ImVec4 clearColor = {.x = 0.45f, .y = 0.55f, .z = 0.60f, .w = 1.00f};

    // main event loop
    bool quit = false;
    while (!glfwWindowShouldClose(config->window))
    {
	glfwPollEvents();

	// start imgui frame
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	igNewFrame();

	{
	    igBegin("Hello, world!", NULL, 0);
	    igText("Application average %.3f ms/frame (%.1f FPS)",
		    1000.0f / igGetIO()->Framerate, igGetIO()->Framerate);
	    igEnd();
	}

	// render
	igRender();
	glfwMakeContextCurrent(config->window);
	
	glViewport(0, 0, (int)config->ioptr->DisplaySize.x, (int)config->ioptr->DisplaySize.y);
	
	glClearColor(clearColor.x, clearColor.y, clearColor.z, clearColor.w);
	glClear(GL_COLOR_BUFFER_BIT);
	
	ImGui_ImplOpenGL3_RenderDrawData(igGetDrawData());
	
	glfwSwapBuffers(config->window); // Swaps rendering buffer with screen buffer
    }

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

