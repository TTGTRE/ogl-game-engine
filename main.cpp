#include <iostream>

#include <glew.h>
#include <glfw3.h>
#include <ext.hpp>
#include <SOIL2.h>
#include "gl_utilities.h"
#include "engine/Cube.h"
#include "engine/Graphics.h"
#include "engine/Window.h"

GLuint shader_program;

int main() {

    Window window("A Title", 500, 500);
    Graphics *graphics = window.getGraphics();
    graphics->createShaderProgram("vertex_shader.glsl", "fragment_shader.glsl");

    Cube *cube1 = new Cube(-1.0f, 0.0f, -5.0f);
    Cube *cube2 = new Cube(1.0f, 0.0f, -5.0f);

    std::vector<Cube *> cubes;
    cubes.push_back(cube1);
    cubes.push_back(cube2);

    while (window.exists()) {

        auto it = cubes.begin();
        while (it != cubes.end()) {
            (*it)->setRotation((float) glfwGetTime());
            it++;
        }

        graphics->draw(cubes);
    }

    delete(cube1);
    delete(cube2);

    window.destroy();
}