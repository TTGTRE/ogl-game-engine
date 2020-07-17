#include <glew.h>
#include <glfw3.h>
#include <vector>
#include "Entity.h"
#include "engine/OpenGL.h"
#include "model/ModelLoader.h"
#include "SquareEntity.h"
#include "Canvas.h"
#include "TriangleEntity.h"

#define CANVAS_WIDTH 600
#define CANVAS_HEIGHT 600
#define VAO_COUNT 1

GLuint vaoArray[VAO_COUNT];

Canvas *canvas;
std::vector<Entity *> entities;

void init(GLFWwindow *window) {

    //TODO Move this to a different module
    glGenVertexArrays(VAO_COUNT, vaoArray);
    glBindVertexArray(vaoArray[0]);

    canvas = new Canvas(CANVAS_WIDTH, CANVAS_HEIGHT);
    canvas->setScale(0.1f);

    // Model loading
    ModelLoader::load("../res/square_model.txt");
    ModelLoader::load("../res/triangle_model.txt");

    // Entity loading
    entities.emplace_back(new SquareEntity(0.0f, 0.0f));
    entities.emplace_back(new SquareEntity(1.0f, 1.0f));
    entities[1]->setColor(Color(1.0f, 0.0f, 0.0f));
}

void display(GLFWwindow *window, double currentTime) {

    canvas->clear();

    for (Entity *entity : entities) {
        canvas->setColor(entity->getColor());
        canvas->draw(entity->getModel(), entity->getX(), entity->getY());
    }
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