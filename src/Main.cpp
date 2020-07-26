#include <glew.h>
#include <glfw3.h>
#include <vector>
#include <thread>
#include "engine/Entity.h"
#include "engine/OpenGL.h"
#include "SquareEntity.h"
#include "engine/Canvas.h"
#include "ResourceManager.h"

#define CANVAS_WIDTH 600
#define CANVAS_HEIGHT 600
#define SLEEP_DUR 20
#define VAO_COUNT 1

GLuint vaoArray[VAO_COUNT];

Canvas *canvas;

std::vector<Entity> entities;

void init(GLFWwindow *window) {

    //TODO Move this to a different module
    glGenVertexArrays(VAO_COUNT, vaoArray);
    glBindVertexArray(vaoArray[0]);

    canvas = new Canvas(CANVAS_WIDTH, CANVAS_HEIGHT);

    // Model loading & texture loading
    ResourceManager::loadResources();

    // Entity loading
    entities.emplace_back(SquareEntity(100, 100, 50, 50));
    entities.emplace_back(SquareEntity(100, 400, 200, 50));
}

void display(GLFWwindow *window, double currentTime) {

    canvas->clear();

    for (Entity const &entity : entities) {
        canvas->setColor(entity.getColor());
        canvas->setTexture(entity.getTexture());
        canvas->draw(entity.getModel(), entity.getX(), entity.getY(), entity.getWidth(), entity.getHeight());
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_DUR));
}

int main() {

    if (!glfwInit()) {
        exit(EXIT_FAILURE);
    }
    glfwWindowHint(GLFW_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_VERSION_MINOR, 3);
    GLFWwindow *window = glfwCreateWindow(CANVAS_WIDTH, CANVAS_HEIGHT, "2D Game Engine", NULL, NULL);
    glfwMakeContextCurrent(window);
    if (glewInit() != GLEW_OK) {
        exit(EXIT_FAILURE);
    }

    glfwSwapInterval(1);

    init(window);

    while (!glfwWindowShouldClose(window)) {
        display(window, glfwGetTime());
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}