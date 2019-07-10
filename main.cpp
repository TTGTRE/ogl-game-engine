#include <iostream>

#include <glew.h>
#include <glfw3.h>
#include "gl_utilities.h"

const int WINDOW_WIDTH = 500;
const int WINDOW_HEIGHT = 500;

float triangle_vertices[9] = {
        0.0f, 1.0f, 0.0f, // Top
        -1.0f, 0.0f, 0.0f, // Left
        1.0f, 0.0f, 0.0f, // Right
};

GLuint vertex_arrays[1];
GLuint vertex_buffers[1];
GLuint shader_program;

//void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
//    if (key == GLFW_KEY_E && action == GLFW_PRESS) {
//        std::cout << "e key pressed." << std::endl;
//    }
//}

int main() {

    if (!glfwInit()) exit(EXIT_FAILURE);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    GLFWwindow *window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "OpenGL", NULL, NULL);
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) exit(EXIT_FAILURE);

    glfwSwapInterval(1);

    // Register key callback
//    glfwSetKeyCallback(window, key_callback);

    shader_program = shader_maker::create_shader_program();

    glGenVertexArrays(1, vertex_arrays);
    glBindVertexArray(vertex_arrays[0]);

    glGenBuffers(1, vertex_buffers);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffers[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(triangle_vertices), triangle_vertices, GL_STATIC_DRAW);

    while (!glfwWindowShouldClose(window)) {

        glClearColor(0.0, 1.0, 1.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shader_program);
        glPointSize(10.0f);
        glDrawArrays(GL_POINTS, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}