#include <glew.h>
#include <glfw3.h>
#include <iostream>
#include "ShaderUtils.cpp"
#include "Shape.h"
#include "Square.h"

#define numVAOs 1
#define numVBOs 2

GLuint renderingProgram;
GLuint vao[numVAOs];
GLuint vbo[numVBOs];

GLuint createShaderProgram() {
    std::string vShaderSource = readShaderSource("vertex_shader.glsl");
    std::string fShaderSource = readShaderSource("fragment_shader.glsl");

    GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
    GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);

    const char *vshader_str = vShaderSource.c_str();
    const char *fshader_str = fShaderSource.c_str();

    glShaderSource(vShader, 1, &vshader_str, NULL);
    glShaderSource(fShader, 1, &fshader_str, NULL);
    glCompileShader(vShader);
    glCompileShader(fShader);

    getCompileStatus(vShader);
    getCompileStatus(fShader);

    GLuint vfProgram = glCreateProgram();
    glAttachShader(vfProgram, vShader);
    glAttachShader(vfProgram, fShader);
    glLinkProgram(vfProgram);

    checkOpenGLError();

    return vfProgram;
}

void init(GLFWwindow *window) {
    renderingProgram = createShaderProgram();
    glGenVertexArrays(numVAOs, vao);
    glBindVertexArray(vao[0]);
    glGenBuffers(numVBOs, vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Square::VERTICES) / sizeof(float), Square::VERTICES, GL_STATIC_DRAW);
}

void display(GLFWwindow *window, double currentTime) {
    glClear(GL_DEPTH_BUFFER_BIT);

    //clear background to black each time
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(renderingProgram);
    glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(0);

    glDrawArrays(GL_TRIANGLES, 0, sizeof(Square::VERTICES) / sizeof(float));
}

int main() {

    if (!glfwInit()) {
        exit(EXIT_FAILURE);
    }
    glfwWindowHint(GLFW_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_VERSION_MINOR, 3);
    GLFWwindow *window = glfwCreateWindow(600, 600, "Chapter2-program1", NULL, NULL);
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