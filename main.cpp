#include <glew.h>
#include <glfw3.h>
#include <iostream>
#include "engine/Cube.h"
#include "engine/Graphics.h"
#include "engine/TextureLoader.h"

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

    Graphics graphics(window, WINDOW_WIDTH, WINDOW_HEIGHT);
    graphics.createShaderProgram("vertex_shader.glsl", "fragment_shader.glsl");

    // Load textures
    //FIXME Last loaded texture is used on all models.
    // Setting the texture of a model doesn't affect it's texture.
    //TODO Automatic texture unit allocation.
    Texture *defaultTexture = TextureLoader::loadTexture("default_texture.jpg", GL_TEXTURE0);
    Texture *brickTexture = TextureLoader::loadTexture("brick.png", GL_TEXTURE1);
    std::cout << "Finished loading textures." << std::endl;

    Cube *cube1 = new Cube(-1.0f, 0.0f, -5.0f);
    Cube *cube2 = new Cube(1.0f, 0.0f, -5.0f);
    cube2->setTexture(defaultTexture);
    cube1->setTexture(brickTexture);

    std::vector<Cube *> cubes;
    cubes.push_back(cube1);
    cubes.push_back(cube2);

    while (!glfwWindowShouldClose(window)) {
        auto it = cubes.begin();
        while (it != cubes.end()) {
            (*it)->setRotation((float) glfwGetTime());
            it++;
        }

        graphics.draw(cubes);
    }

    delete(cube1);
    delete(cube2);

    glfwTerminate();
}