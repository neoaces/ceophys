#define CIMGUI_DEFINE_ENUMS_AND_STRUCTS
#define GL_SILENCE_DEPRECATION
#include <GLFW/glfw3.h>
#include <neolog/neolog.h>
#include "cimgui/cimgui.h"
#include "engine.h"
#include "window.h"

static nlog_logger_t log_config = {.LogLevel = DEBUG, .process_name = "neophys::window"};

int render(windowconfig_t* config, systemstate_t* state) {
    if (!glfwWindowShouldClose(config->window))
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
	    igSliderFloat("Timestep (del s)", &state->time_step, 0.0f, 1.0f, "%.3f", 0);
	    igEnd();
	}

	// render
	igRender();
	glfwMakeContextCurrent(config->window);
	
	glViewport(0, 0, (int)config->ioptr->DisplaySize.x, (int)config->ioptr->DisplaySize.y);
	
	glClearColor(config->clearColor.x, config->clearColor.y, config->clearColor.z, config->clearColor.w);
	glClear(GL_COLOR_BUFFER_BIT);
	
	ImGui_ImplOpenGL3_RenderDrawData(igGetDrawData());
	
	glfwSwapBuffers(config->window); // Swaps rendering buffer with screen buffer
    }

    else {
	nlog_log(&log_config, DEBUG, "GLFW called to close. Calling window::window_destroy().");
	window_destroy(config);
	return 1;
    }

    return 0;
}

void run(windowconfig_t* config, systemstate_t* state) {
    while(render(config, state) == 0) {};
}
