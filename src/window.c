#include <assert.h>
#include <glad/gl.h>
#include <math.h>
#include <neolib/engine.h>
#include <neolib/constants.h>
#include <neolog/neolog.h>
#include <stdlib.h>
#include <stdio.h>
#include "window.h"
#include "cimgui/cimgui.h"

static nlog_logger_t logger_config = {.LogLevel = DEBUG, .process_name = "neophys::window"};

// Vertex Shader source code
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"uniform float size;\n"
"uniform float width;\n"
"uniform float height;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, size * aPos.z, 1.0);\n"
"}\0";

//Fragment Shader source code
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"uniform vec4 color;\n"
"void main()\n"
"{\n"
"   FragColor = color;\n"
"}\n\0";

windowconfig_t* window_init(systemstate_t* state) {
    windowconfig_t* config = malloc(sizeof(windowconfig_t));

    if (!glfwInit()) {
        nlog_logerr(&logger_config, "GLFW did not initialize. Aborting.", -1);
    }

    // Set GLFW defaults
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);

    config->window = glfwCreateWindow(1920, 1080, "neophys", NULL, NULL);
    
    if (!config->window) {
	    glfwTerminate();
	    nlog_logerr(&logger_config, "Window did not initialize properly.", 100);
    }
    
    glfwMakeContextCurrent(config->window);
    gladLoadGL(glfwGetProcAddress);
    glfwSwapInterval(1);

    // CREATE SHADER
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    // Attach Vertex Shader source to the Vertex Shader Object
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    // Compile the Vertex Shader into machine code
    glCompileShader(vertexShader);

    // Create Fragment Shader Object and get its reference
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    // Attach Fragment Shader source to the Fragment Shader Object
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    // Compile the Vertex Shader into machine code
    glCompileShader(fragmentShader);

    // Create Shader Program Object and get its reference
    state->shader_obj = glCreateProgram();
    // Attach the Vertex and Fragment Shaders to the Shader Program
    glAttachShader(state->shader_obj, vertexShader);
    glAttachShader(state->shader_obj, fragmentShader);
    // Wrap-up/Link all the shaders together into the Shader Program
    glLinkProgram(state->shader_obj);

    // Delete the now useless Vertex and Fragment Shader objects
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    
    float circle[CIRCLE_RES*2] = {0.0f, 0.0f};
    generate_circle(state, circle);
    
    // Generate the state->VAO and state->VBO with only 1 object each
    glGenVertexArrays(1, &state->VAO);
    glGenBuffers(1, &state->VBO);

    // Make the state->VAO the current Vertex Array Object by binding it
    glBindVertexArray(state->VAO);

    // Bind the state->VBO specifying it's a GL_ARRAY_BUFFER
    glBindBuffer(GL_ARRAY_BUFFER, state->VBO);
    // Introduce the vertices into the state->VBO
    glBufferData(GL_ARRAY_BUFFER, sizeof(circle), circle, GL_DYNAMIC_DRAW);

    // Configure the Vertex Attribute so that OpenGL knows how to read the state->VBO
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    // Enable the Vertex Attribute so that OpenGL knows to use it
    glEnableVertexAttribArray(0);

    // Bind both the state->VBO and state->VAO to 0 so that we don't accidentally modify the VAO and VBO we created
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    state->size = 50.0f;
    state->width = 3420.0f;
    state->height = 2082.0f;

    state->particle_color[0] = 1.0f;
    state->particle_color[1] = 0.3f;
    state->particle_color[2] = 0.3f;
    state->particle_color[3] = 1.0f;

    // Exporting variables to shaders
    glUseProgram(state->shader_obj);
    glUniform1f(glGetUniformLocation(state->shader_obj, "size"), state->size);
    glUniform1f(glGetUniformLocation(state->shader_obj, "width"), state->width);
    glUniform1f(glGetUniformLocation(state->shader_obj, "height"), state->height);
    glUniform4f(glGetUniformLocation(state->shader_obj, "color"), state->particle_color[0], state->particle_color[1], state->particle_color[2], state->particle_color[3]);

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