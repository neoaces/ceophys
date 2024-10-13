#define CIMGUI_DEFINE_ENUMS_AND_STRUCTS
#define CIMGUI_USE_GLFW
#define CIMGUI_USE_OPENGL3
#define IMGUI_IMPL_OPENGL_ES3
#include <cimgui/cimgui.h>
#include <cimgui_impl.h>
#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <neolog/neolog.h>
#include <stdlib.h>
#include <stdio.h>
#include "window.h"

static const nlog_logger_t logger_config = {.LogLevel = DEBUG, .process_name = "neolib"};

void window_init() {
    GLFWwindow* window;

    if (!glfwInit()) {
	exit(-1);
    }

    // Set GLFW defaults
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);

    window = glfwCreateWindow(800, 800, "neophys", NULL, NULL);
    if (!window) {
	glfwTerminate();
	nlog_logerr(&logger_config, "Window did not initialize properly.", 100);
    }
    
    glfwMakeContextCurrent(window);
    gladLoadGL(glfwGetProcAddress);
    glfwSwapInterval(1);

    igCreateContext(NULL);
    ImGuiIO* ioptr = igGetIO();
    const char *glsl_version = "#version 150";
    ImGui_ImplGlfw_InitForOpenGL(window, true); 
    ImGui_ImplOpenGL3_Init(glsl_version);

    bool showDemoWindow = true;
    bool showAnotherWindow = false;
    ImVec4 clearColor;
    clearColor.x = 0.45f;
    clearColor.y = 0.55f;
    clearColor.z = 0.60f;
    clearColor.w = 1.00f;

    // main event loop
    bool quit = false;
    while (!glfwWindowShouldClose(window))
    {
	glfwPollEvents();

	// start imgui frame
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	igNewFrame();

	if (showDemoWindow)
	    igShowDemoWindow(&showDemoWindow);

	// show a simple window that we created ourselves.
	{
	    static float f = 0.0f;
	    static int counter = 0;

	    igBegin("Hello, world!", NULL, 0);
	    igText("This is some useful text");
	    igCheckbox("Demo window", &showDemoWindow);
	    igCheckbox("Another window", &showAnotherWindow);

	    igSliderFloat("Float", &f, 0.0f, 1.0f, "%.3f", 0);
	    igColorEdit3("clear color", (float *)&clearColor, 0);

	    ImVec2 buttonSize;
	    buttonSize.x = 0;
	    buttonSize.y = 0;
	    if (igButton("Button", buttonSize))
		counter++;
	    igSameLine(0.0f, -1.0f);
	    igText("counter = %d", counter);

	    igText("Application average %.3f ms/frame (%.1f FPS)",
		    1000.0f / igGetIO()->Framerate, igGetIO()->Framerate);
	    igEnd();
	}

	if (showAnotherWindow) 
	{
	    igBegin("imgui Another Window", &showAnotherWindow, 0);
	    igText("Hello from imgui");
	    ImVec2 buttonSize;
	    buttonSize.x = 0;
	    buttonSize.y = 0;
	    if (igButton("Close me", buttonSize)) {
		showAnotherWindow = false;
	    }
	    igEnd();
	}

	// render
	igRender();
	glfwMakeContextCurrent(window);
	glViewport(0, 0, (int)ioptr->DisplaySize.x, (int)ioptr->DisplaySize.y);
	glClearColor(clearColor.x, clearColor.y, clearColor.z, clearColor.w);
	glClear(GL_COLOR_BUFFER_BIT);
	ImGui_ImplOpenGL3_RenderDrawData(igGetDrawData());
#ifdef IMGUI_HAS_DOCK
	if (ioptr->ConfigFlags & ImGuiConfigFlags_ViewportsEnable) 
	{
	    GLFWwindow *backup_current_window = glfwGetCurrentContext();
	    igUpdatePlatformWindows();
	    igRenderPlatformWindowsDefault(NULL, NULL);
	    glfwMakeContextCurrent(backup_current_window);
	}
#endif
	glfwSwapBuffers(window);
    }

    // clean up
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    igDestroyContext(NULL);

    glfwDestroyWindow(window);
    glfwTerminate();   
};

void window_destroy() {
};


