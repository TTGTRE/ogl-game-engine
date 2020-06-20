#include<glew.h>
#include <glfw3.h>
#include <vector>
#include <SOIL2.h>
#include "ShaderUtils.cpp"
#include "Shape.h"
#include "Square.h"

#define VAO_COUNT 1
#define VBO_COUNT 20
#define SCALE_UNIFORM "uScale"

GLuint loadTexture(char const *texImagePath) {
    GLuint textureID;
    textureID = SOIL_load_OGL_texture(texImagePath, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
    return textureID;
}

GLuint shaderProgram;
GLuint vaoArray[VAO_COUNT];
//TODO Could put VBO's in container?
GLuint vboArray[VBO_COUNT];

// The total number of shapes in memory
std::vector<Shape *> shapeVector;

GLuint spaceTexture;

void init(GLFWwindow *window) {
    shaderProgram = createShaderProgram("vertex_shader.glsl", "fragment_shader.glsl");
    glGenVertexArrays(VAO_COUNT, vaoArray);
    glBindVertexArray(vaoArray[0]);

    shapeVector.emplace_back(new Square(1, 1, 0, 1));

    glGenBuffers(2, vboArray);
    glBindBuffer(GL_ARRAY_BUFFER, vboArray[0]);
    glBufferData(GL_ARRAY_BUFFER, shapeVector[0]->getVerticeCount() * sizeof(float), shapeVector[0]->getVertices(),
                 GL_STATIC_DRAW);

    float texCoords[] = {
            // First top left half of square
            0, 0,
            1, 0,
            0, 1,
            // Second bottom left half of square
            0, 1,
            1, 0,
            1, 1
    };

    glBindBuffer(GL_ARRAY_BUFFER, vboArray[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(texCoords), texCoords, GL_STATIC_DRAW);

    spaceTexture = loadTexture("../res/texture.jpg");
}

void display(GLFWwindow *window, double currentTime) {
    glClear(GL_DEPTH_BUFFER_BIT);

    //clear background to black each time
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(shaderProgram);

    glBindBuffer(GL_ARRAY_BUFFER, vboArray[0]);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, vboArray[1]);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(1);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, spaceTexture);

    glDrawArrays(GL_TRIANGLES, 0, 12);
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