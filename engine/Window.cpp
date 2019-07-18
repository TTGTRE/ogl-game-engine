//
// Created by Tre on 7/17/2019.
//

#include <cstdlib>
#include <glew.h>
#include <glfw3.h>
#include "Window.h"

Window::Window(const char *title, int width, int height) : title(title), width(width), height(height) {
    if (!glfwInit()) exit(EXIT_FAILURE);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    window = glfwCreateWindow(width, height, title, NULL, NULL);
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) exit(EXIT_FAILURE); // TODO Not exactly window related? Move to different class?

    glfwSwapInterval(1);

    // TODO Add default shader program if one isn't specified?

    graphics = new Graphics(window, width, height);
}

void Window::destroy() {
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}

bool Window::exists() {
    return !glfwWindowShouldClose(window);
}

const char *Window::getTitle() {
    return title;
}

int Window::getWidth() {
    return width;
}

int Window::getHeight() {
    return height;
}

Graphics *Window::getGraphics() {
    return graphics;
}
