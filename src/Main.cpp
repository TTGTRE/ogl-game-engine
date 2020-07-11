#include <glew.h>
#include <glfw3.h>
#include <vector>
#include "ShaderUtils.h"
#include "Entity.h"
#include "model/ModelLoader.h"
#include "SquareEntity.h"
#include "GLUtilities.h"
#include "Buffers.h"

#define VAO_COUNT 1

GLuint shaderProgram;
GLuint vaoArray[VAO_COUNT];

std::vector<Entity *> entities;

GLint xPosLoc, yPosLoc, scaleLoc, colorLoc;

void init(GLFWwindow *window) {

    WorldProperties::setEntityWorldScale(0.1f);

    shaderProgram = createShaderProgram("vertex_shader.glsl", "fragment_shader.glsl");
    glGenVertexArrays(VAO_COUNT, vaoArray);
    glBindVertexArray(vaoArray[0]);

    // Model loading
    ModelLoader::load("../res/square_model.txt");

    // Entity loading
    entities.emplace_back(new SquareEntity(1.0f, 1.0f));

    glBindBuffer(GL_ARRAY_BUFFER, GLUtilities::vboArray[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * GRID_VERTICE_BUFFER_SIZE, Buffers::getCoordinateGridBuffer(),
                 GL_STATIC_DRAW);

    // Define uniform variables
    xPosLoc = glGetUniformLocation(shaderProgram, "xPos");
    yPosLoc = glGetUniformLocation(shaderProgram, "yPos");
    scaleLoc = glGetUniformLocation(shaderProgram, "scale");
    colorLoc = glGetUniformLocation(shaderProgram, "uColor");
}

void display(GLFWwindow *window, double currentTime) {
    glClear(GL_DEPTH_BUFFER_BIT);

    //clear background to black each time
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(shaderProgram);

    for (Entity *entity : entities) {

        GLuint bufferIndex = entity->getModel()->getVboIndex();

        glBindBuffer(GL_ARRAY_BUFFER, GLUtilities::vboArray[bufferIndex]);

        glVertexAttribPointer(bufferIndex, 2, GL_FLOAT, GL_FALSE, 0, NULL);
        glEnableVertexAttribArray(bufferIndex);
        <<<<<<< HEAD

        glUniform1f(xPosLoc, entity->getX() - .5f - (1.0f / WorldProperties::getEntityWorldScale()) + 1);
        glUniform1f(yPosLoc, -entity->getY() - .5f + (1.0f / WorldProperties::getEntityWorldScale()));
        glUniform1f(scaleLoc, entity->getScale());
        glUniform3f(colorLoc, entity->getColor().getRed(), entity->getColor().getGreen(),
                    entity->getColor().getBlue());
        glDrawArrays(GL_TRIANGLES, 0, entity->getModel()->getNumVertices());
    }

    glUniform1f(xPosLoc, 0);
    glUniform1f(yPosLoc, 0);
    glUniform1f(scaleLoc, 1);
    glUniform3f(colorLoc, 1, 1, 1);

    glBindBuffer(GL_ARRAY_BUFFER, GLUtilities::vboArray[1]);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, NULL);

    glDrawArrays(GL_LINES, 0, GRID_VERTICE_BUFFER_SIZE);
}

int main() {

    if (!glfwInit()) {
        exit(EXIT_FAILURE);
    }
    glfwWindowHint(GLFW_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_VERSION_MINOR, 3);
    GLFWwindow *window = glfwCreateWindow(600, 600, "2D Game Engine", NULL, NULL);
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