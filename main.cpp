#include <iostream>
#include <glew.h>
#include <glfw3.h>
#include <ext.hpp>
#include <vector>
#include "GLUtilities.h"
#include "engine/Model.h"
#include "engine/DrawHandle.h"
#include "engine/ShaderHandle.h"

const int WINDOW_WIDTH = 500;
const int WINDOW_HEIGHT = 500;

int main() {

    Engine::DrawHandle drawHandle(500, 500);

    if (!glfwInit()) exit(EXIT_FAILURE);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    GLFWwindow *window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "OpenGL", NULL, NULL);
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) exit(EXIT_FAILURE);

    glfwSwapInterval(1);

    while (!glfwWindowShouldClose(window)) {
        drawHandle.draw();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}