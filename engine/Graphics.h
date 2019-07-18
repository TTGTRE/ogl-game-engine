//
// Created by Tre on 7/16/2019.
//

#ifndef OGLEXPERIMENTS_GRAPHICS_H
#define OGLEXPERIMENTS_GRAPHICS_H


#include <glfw3.h>
#include <vector>
#include "Cube.h"

class Graphics {

    GLFWwindow *window;
    int width, height;
    GLuint shaderProgram;
    GLuint vaos[1], vbos[2];

public:
    Graphics(GLFWwindow *window, int width, int height);

    void createShaderProgram(const char *vertexPath, const char *fragmentPath);

    void draw(std::vector<Cube *> cubes);
};


#endif //OGLEXPERIMENTS_GRAPHICS_H
