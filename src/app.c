#define CIMGUI_DEFINE_ENUMS_AND_STRUCTS
#define GL_SILENCE_DEPRECATION
#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <neolib/engine.h>
#include <neolog/neolog.h>
#include "cimgui/cimgui.h"
#include "window.h"

static nlog_logger_t log_config = {.LogLevel = DEBUG, .process_name = "neophys::window"};

int render(windowconfig_t* config, systemstate_t* state) {
    if (!glfwWindowShouldClose(config->window)) {
		glfwPollEvents();
		glClear(GL_COLOR_BUFFER_BIT);
		// start imgui frame
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		igNewFrame();

		int display_w, display_h;
		glfwGetFramebufferSize(config->window, &display_w, &display_h);
		float aspect = (float) display_w / (float) display_h;
		glViewport(0, 0, display_w, display_h);
		
		if (state->width != display_w || state->height != display_h) {
			state->width = display_w;
			state->height = display_h;
		}


		glUseProgram(state->shader_obj);
	    // Bind the state->VBO specifying it's a GL_ARRAY_BUFFER
		glBindBuffer(GL_ARRAY_BUFFER, state->VBO);
		
		float circle[CIRCLE_RES * 2];
		generate_circle(state, circle);
		nlog_log(&log_config, DEBUG, "Current screen X component: %f", state->width);
		// Introduce the vertices into the state->VBO
		glBufferData(GL_ARRAY_BUFFER, sizeof(circle), circle, GL_STATIC_DRAW);	
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		// Bind the VAO so OpenGL knows to use it
		glBindVertexArray(state->VAO);
		// Only draw the triangle if the ImGUI checkbox is ticked
		// Draw the triangle using the GL_TRIANGLES primitive
		glDrawArrays(GL_TRIANGLE_FAN, 0, 32);
		glBindVertexArray(0);

		{
			igBegin("Hello, world!", NULL, 0);
			igText("Width: %d, Height: %d", display_w, display_h);
			igText("Application average %.3f ms/frame (%.1f FPS)",
				1000.0f / igGetIO()->Framerate, igGetIO()->Framerate);
			igSliderFloat("Timestep (del s)", &state->time_step, 0.015f, 1.0f, "%.3f", 0);
			igSliderFloat("Size of circle", &state->size, 0.0f, display_h, "%.3f", 0);
			igText("Fill Color");
			igSliderFloat("R:", &state->particle_color[0], 0.0f, 1.0f, "%.2f", 0);
			igSliderFloat("G:", &state->particle_color[1], 0.0f, 1.0f, "%.2f", 0);
			igSliderFloat("B:", &state->particle_color[2], 0.0f, 1.0f, "%.2f", 0);
			igSliderFloat("A:", &state->particle_color[3], 0.0f, 1.0f, "%.2f", 0);
			igSliderFloat("Circle X:", &state->body->s[0], -(display_w / 2.0f), display_w / 2.0f, "%.2f", 0);
			igSliderFloat("Circle Y:", &state->body->s[1], -(display_h / 2.0f), display_h / 2.0f, "%.2f", 0);
			
			igEnd();
		}

		// Export variables to shader
		glUseProgram(state->shader_obj);
		glUniform1f(glGetUniformLocation(state->shader_obj, "size"), state->size);
		glUniform4f(glGetUniformLocation(state->shader_obj, "color"), state->particle_color[0], state->particle_color[1], state-> particle_color[2], state->particle_color[3]);

		// render
		igRender();
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