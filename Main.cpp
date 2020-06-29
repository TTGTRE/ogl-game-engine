#include<glew.h>
#include <glfw3.h>
#include <vector>
#include "ShaderUtils.cpp"
#include "ModelInfo.cpp"
#include "SquareEntity.h"
#include "TextureUtils.h"
#include "DrawableObject.h"
#include "LineObject.h"

#define VAO_COUNT 1
#define VBO_COUNT 3
#define COORDINATE_GRID_SCALE 0.1f

GLuint shaderProgram;
GLuint vaoArray[VAO_COUNT];
GLuint vboArray[VBO_COUNT];

std::vector<SquareEntity *> squareEntities;
std::vector<DrawableObject *> drawableObjects;

int const GRID_VERTICE_COUNT = 1.0f / COORDINATE_GRID_SCALE * 2 * 2;
int const GRID_VERTICE_BUFFER_SIZE = GRID_VERTICE_COUNT * 2 * 2;
float gridVerticeBuffer[GRID_VERTICE_BUFFER_SIZE];

GLint spaceTexture;
GLint xPosLoc, yPosLoc, scaleLoc;

void init(GLFWwindow *window) {

    printf("The scale is %f\nThe number of grid vertices is %d\nThe size of the grid vertice buffer is: %d\n",
           COORDINATE_GRID_SCALE,
           GRID_VERTICE_COUNT, GRID_VERTICE_BUFFER_SIZE);

    shaderProgram = createShaderProgram("vertex_shader.glsl", "fragment_shader.glsl");
    glGenVertexArrays(VAO_COUNT, vaoArray);
    glBindVertexArray(vaoArray[0]);

    // Entity loading
    drawableObjects.emplace_back(new LineObject);

    squareEntities.emplace_back(new SquareEntity(2, 2, COORDINATE_GRID_SCALE));
    squareEntities.emplace_back(new SquareEntity(1, 0, COORDINATE_GRID_SCALE));
    squareEntities.emplace_back(new SquareEntity(0, 0, COORDINATE_GRID_SCALE));

    glGenBuffers(VBO_COUNT, vboArray);

    // Model loading
    glBindBuffer(GL_ARRAY_BUFFER, vboArray[Model::SQUARE_VERTEX_BUFFER_INDEX]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Model::SQUARE_VERTICES), Model::SQUARE_VERTICES, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, vboArray[Model::SQUARE_TEXTURE_BUFFER_INDEX]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Model::SQUARE_TEX_COORDS), Model::SQUARE_TEX_COORDS, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, vboArray[Model::GRID_VERTEX_BUFFER_INDEX]);

    // Algorithm to generate grid
    int c = 1;
    float currentY = 1.0f;
    for (int i = 0; i < GRID_VERTICE_BUFFER_SIZE / 2; i += 2) {
        if (i % 4 == 0) {
            gridVerticeBuffer[i] = -1.0f;
        } else {
            gridVerticeBuffer[i] = 1.0f;
        }
        gridVerticeBuffer[i + 1] = currentY;
        if (c % 2 == 0) {
            currentY -= COORDINATE_GRID_SCALE;
        }
        printf("x: %f, y: %f c: %d\n", gridVerticeBuffer[i], gridVerticeBuffer[i + 1], c);
        c++;
    }

    int d = 1;
    float currentX = 1.0f;
    for (int i = GRID_VERTICE_BUFFER_SIZE / 2; i < GRID_VERTICE_BUFFER_SIZE; i += 2) {
        if (i % 4 == 0) {
            gridVerticeBuffer[i + 1] = -1.0f;
        } else {
            gridVerticeBuffer[i + 1] = 1.0f;
        }
        gridVerticeBuffer[i] = currentX;
        if (d % 2 == 0) {
            currentX -= COORDINATE_GRID_SCALE;
        }
        printf("x : %f, y: %f, d: %d\n", gridVerticeBuffer[i], gridVerticeBuffer[i + 1], d);
        d++;
    }

    glBufferData(GL_ARRAY_BUFFER, sizeof(gridVerticeBuffer), gridVerticeBuffer, GL_STATIC_DRAW);

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
        glUniform1f(xPosLoc, squareEntity->getX() - .5f);
        glUniform1f(yPosLoc, squareEntity->getY() - .5f);
        glUniform1f(scaleLoc, squareEntity->getScale());
        glDrawArrays(GL_TRIANGLES, 0, Model::SQUARE_NUM_VERTICES);
    }

    // Get ready to draw grid
    glUniform1f(xPosLoc, 0);
    glUniform1f(yPosLoc, 0);
    glUniform1f(scaleLoc, 1);

    glBindBuffer(GL_ARRAY_BUFFER, vboArray[2]);
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