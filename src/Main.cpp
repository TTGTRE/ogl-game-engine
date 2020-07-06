#include <glew.h>
#include <glfw3.h>
#include <vector>
#include "ShaderUtils.h"
#include "ModelInfo.cpp"
#include "SquareEntity.h"
#include "TextureUtils.h"
#include "model/ModelLoader.h"
#include "Buffers.h"

#define VAO_COUNT 1
#define VBO_COUNT 3

GLuint shaderProgram;
GLuint vaoArray[VAO_COUNT];
GLuint vboArray[VBO_COUNT];

std::vector<SquareEntity *> squareEntities;

GLint spaceTexture;
GLint xPosLoc, yPosLoc, scaleLoc;

void init(GLFWwindow *window) {

    ModelLoader modelLoader;
    Model *squareModel = modelLoader.load("../res/square_model.txt");
    printf("vertice buffer size: %d, num vertices: %d\n", squareModel->getNumVertices() * sizeof(float),
           squareModel->getNumVertices());

    printf("The scale is %f\nThe number of grid vertices is %d\nThe size of the grid vertice buffer is: %d\n",
           EngineConstants::COORDINATE_GRID_SCALE,
           EngineConstants::GRID_VERTICE_COUNT, EngineConstants::GRID_VERTICE_BUFFER_SIZE);

    shaderProgram = createShaderProgram("vertex_shader.glsl", "fragment_shader.glsl");
    glGenVertexArrays(VAO_COUNT, vaoArray);
    glBindVertexArray(vaoArray[0]);

    // Entity loading
    squareEntities.push_back(new SquareEntity(1, 1));

    glGenBuffers(VBO_COUNT, vboArray);

    // Model loading
    glBindBuffer(GL_ARRAY_BUFFER, vboArray[ModelInfo::SQUARE_VERTEX_BUFFER_INDEX]);
    glBufferData(GL_ARRAY_BUFFER, squareModel->getNumVertices() * sizeof(float), squareModel->getVerticeArray(),
                 GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, vboArray[ModelInfo::SQUARE_TEXTURE_BUFFER_INDEX]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(ModelInfo::SQUARE_TEX_COORDS), ModelInfo::SQUARE_TEX_COORDS, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, vboArray[ModelInfo::GRID_VERTEX_BUFFER_INDEX]);
    glBufferData(GL_ARRAY_BUFFER, EngineConstants::GRID_VERTICE_BUFFER_SIZE_BYTES, Buffers::getCoordinateGridBuffer(),
                 GL_STATIC_DRAW);

    // Texture loading
    spaceTexture = TextureUtils::loadTexture("../res/texture.jpg");

    // Define uniform variables
    xPosLoc = glGetUniformLocation(shaderProgram, "xPos");
    yPosLoc = glGetUniformLocation(shaderProgram, "yPos");
    scaleLoc = glGetUniformLocation(shaderProgram, "scale");
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

    for (SquareEntity *squareEntity : squareEntities) {
        glUniform1f(xPosLoc, squareEntity->getX() - .5f - (1.0f / EngineConstants::COORDINATE_GRID_SCALE) + 1);
        glUniform1f(yPosLoc, -squareEntity->getY() - .5f + (1.0f / EngineConstants::COORDINATE_GRID_SCALE));
        glUniform1f(scaleLoc, squareEntity->getScale());
        glDrawArrays(GL_TRIANGLES, 0, ModelInfo::SQUARE_NUM_VERTICES);
    }

    // Get ready to draw grid
    glUniform1f(xPosLoc, 0);
    glUniform1f(yPosLoc, 0);
    glUniform1f(scaleLoc, 1);

    glBindBuffer(GL_ARRAY_BUFFER, vboArray[2]);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, NULL);

    glDrawArrays(GL_LINES, 0, EngineConstants::GRID_VERTICE_BUFFER_SIZE);
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