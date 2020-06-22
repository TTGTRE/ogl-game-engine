#include<glew.h>
#include <glfw3.h>
#include <vector>
#include "ShaderUtils.cpp"
#include "ModelInfo.cpp"
#include "SquareEntity.h"
#include "TextureUtils.h"

#define VAO_COUNT 1
#define VBO_COUNT 20

GLuint shaderProgram;
GLuint vaoArray[VAO_COUNT];
GLuint vboArray[VBO_COUNT];

std::vector<SquareEntity *> squareEntities;

GLuint spaceTexture;

void init(GLFWwindow *window) {
    shaderProgram = createShaderProgram("vertex_shader.glsl", "fragment_shader.glsl");
    glGenVertexArrays(VAO_COUNT, vaoArray);
    glBindVertexArray(vaoArray[0]);

    // Entity loading
    squareEntities.emplace_back(new SquareEntity(2, 1, 0.25));
    squareEntities.emplace_back(new SquareEntity(1, 2, 0.25));

    glGenBuffers(2, vboArray);

    // Model loading
    glBindBuffer(GL_ARRAY_BUFFER, vboArray[Model::SQUARE_VERTEX_BUFFER_INDEX]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Model::SQUARE_VERTICES), Model::SQUARE_VERTICES, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, vboArray[Model::SQUARE_TEXTURE_BUFFER_INDEX]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Model::SQUARE_TEX_COORDS), Model::SQUARE_TEX_COORDS, GL_STATIC_DRAW);

    // Texture loading
    spaceTexture = TextureUtils::loadTexture("../res/texture.jpg");
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

    GLint xPosLoc = glGetUniformLocation(shaderProgram, "xPos");
    GLint yPosLoc = glGetUniformLocation(shaderProgram, "yPos");
    GLuint scaleLoc = glGetUniformLocation(shaderProgram, "scale");

    for (SquareEntity *squareEntity : squareEntities) {
        glUniform1f(xPosLoc, squareEntity->getX());
        glUniform1f(yPosLoc, squareEntity->getY());
        glUniform1f(scaleLoc, squareEntity->getScale());

        glDrawArrays(GL_TRIANGLES, 0, Model::SQUARE_NUM_VERTICES);
    }
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