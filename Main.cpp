#include <glew.h>
#include <glfw3.h>
#include <vector>
#include "ShaderUtils.cpp"
#include "Shape.h"
#include "Square.h"

#define numVAOs 1
#define VBO_MAX 20

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
    shapeVector.emplace_back(new Square());
    shapeVector.emplace_back(new Square(0.5f));

    glGenBuffers(shapeVector.size(), vboArray);
    for (int i = 0; i < shapeVector.size(); i++) {
        printf("Generating a buffer for shape: %d (%s)", i, typeid(*(shapeVector[i])).name());
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

//        glm::vec2 scaled = glm::vec2(1.0f) * glm::vec2(0.5f, 0.5f);
//        GLint scaleLoc = glGetUniformLocation(shaderProgram, "scale");
//        glUniform2f(scaleLoc, scaled[0], scaled[1]);

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