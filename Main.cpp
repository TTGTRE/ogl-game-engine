#include <glew.h>
#include <glfw3.h>
#include <vector>
#include "ShaderUtils.cpp"
#include "Shape.h"
#include "Square.h"

#define numVAOs 1
#define VBO_MAX 20

char const *SCALE_UNIFORM = "uScale";
char const *COLOR_UNIFORM = "uColor";

GLuint shaderProgram;
GLuint vao[numVAOs];
//TODO Could put VBO's in container?
GLuint vboArray[VBO_MAX];

// The total number of shapes in memory
std::vector<Shape *> shapeVector;

void init(GLFWwindow *window) {
    shaderProgram = createShaderProgram("vertex_shader.glsl", "fragment_shader.glsl");
    glGenVertexArrays(numVAOs, vao);
    glBindVertexArray(vao[0]);

    //TODO Populate shape vector
    shapeVector.emplace_back(new Square(1, 1, 0, 1));
    shapeVector.emplace_back(new Square(1, 0, 1, 0.2));

    glGenBuffers(static_cast<GLsizei>(shapeVector.size()), vboArray);
    for (int i = 0; i < shapeVector.size(); i++) {
        printf("Generating a buffer for shape: %d (%s)\n", i, typeid(*(shapeVector[i])).name());
        glBindBuffer(GL_ARRAY_BUFFER, vboArray[i]);
        glBufferData(GL_ARRAY_BUFFER, shapeVector[i]->getVerticeCount() * sizeof(float), shapeVector[i]->getVertices(),
                     GL_STATIC_DRAW);
    }
}

void display(GLFWwindow *window, double currentTime) {
    glClear(GL_DEPTH_BUFFER_BIT);

    //clear background to black each time
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(shaderProgram);

    for (int i = 0; i < shapeVector.size(); i++) {
        glBindBuffer(GL_ARRAY_BUFFER, vboArray[i]);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, NULL);
        glEnableVertexAttribArray(0);

        //TODO Offload these to a function
        GLint scaleLocation = glGetUniformLocation(shaderProgram, SCALE_UNIFORM);
        glUniform1f(scaleLocation, shapeVector[i]->getScale());

        GLint colorLocation = glGetUniformLocation(shaderProgram, "uColor");
        Triple<float> shapeColor = *(shapeVector[i]->getColor());
        glUniform3f(colorLocation, shapeColor[0], shapeColor[1], shapeColor[2]);

        glDrawArrays(GL_TRIANGLES, 0, shapeVector[i]->getVerticeCount());
    }
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