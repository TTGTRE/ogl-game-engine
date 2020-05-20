#include <glew.h>
#include <glfw3.h>
#include <iostream>

const int WINDOW_WIDTH = 500;
const int WINDOW_HEIGHT = 500;

int main() {

    if (!glfwInit()) std::cout << "Failed to initialize GLFW." << std::endl;

    glfwWindowHint(GLFW_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_VERSION_MINOR, 3);
    GLFWwindow *window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Window", NULL, NULL);
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    if (glewInit() != GLEW_OK) std::cout << "Error initializing GLEW." << std::endl;

    glfwTerminate();
}