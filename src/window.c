#include <glad/gl.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <neolog/neolog.h>
#include <stdlib.h>
#include "window.h"

static const nlog_logger_t logger_config = {.LogLevel = DEBUG, .process_name = "neolib"};

void _error_callback(int error, const char* description) {
    nlog_log(&logger_config, ERROR, "GLFW ERROR %d, %s", error, description);
}

void window_init() {
    glfwSetErrorCallback(_error_callback);

    if (!glfwInit()) {
	nlog_logerr(&logger_config, "GLFW did not intitalize correctly.", 1);
    }
    nlog_log(&logger_config, DEBUG, "GLFW successfully initialized.");

    // Set 4.2 version and CORE profile (only profile on MacOS)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(640, 480, "neophys", NULL, NULL);

    if (!window) {
	glfwTerminate();
	nlog_logerr(&logger_config, "GLFW window did not initialize correctly", 1); 
    }

    glfwMakeContextCurrent(window);
    gladLoadGL(glfwGetProcAddress);
    glfwSwapInterval(1);

    while (!glfwWindowShouldClose(window)) {
	int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        const float ratio = width / (float) height;
 
        glViewport(640, 480, width, height);
        glClear(GL_COLOR_BUFFER_BIT);
 
        glfwSwapBuffers(window);
	glfwPollEvents();
    }
};

void window_destroy() {
    glfwTerminate();
};


