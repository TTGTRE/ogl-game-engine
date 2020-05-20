#include <glew.h>
#include <glfw3.h>
#include <iostream>
#include "ShaderUtils.cpp"

#define numVAOs 1

GLuint renderingProgram;
GLuint vao[numVAOs];

GLuint createShaderProgram() {
    std::string vShaderSource = ShaderReader::readShaderSource("vertex_shader.glsl");
    std::string fShaderSource = ShaderReader::readShaderSource("fragment_shader.glsl");

    GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
    GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);

    const char *vshader_str = vShaderSource.c_str();
    const char *fshader_str = fShaderSource.c_str();

    glShaderSource(vShader, 1, &vshader_str, NULL);
    glShaderSource(fShader, 1, &fshader_str, NULL);
    glCompileShader(vShader);
    glCompileShader(fShader);

    ShaderErrorChecker::getCompileStatus(vShader);
    ShaderErrorChecker::getCompileStatus(fShader);

    GLuint vfProgram = glCreateProgram();
    glAttachShader(vfProgram, vShader);
    glAttachShader(vfProgram, fShader);
    glLinkProgram(vfProgram);

    ShaderErrorChecker::checkOpenGLError();

    return vfProgram;
}

void init(GLFWwindow *window) {
    renderingProgram = createShaderProgram();
    glGenVertexArrays(numVAOs, vao);
    glBindVertexArray(vao[0]);
}

float x = 0.0f; //location of triangle on x axis
float inc = 0.01f; //offset for moving the triangle
void display(GLFWwindow *window, double currentTime) {
    glClear(GL_DEPTH_BUFFER_BIT);

    //clear background to black each time
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(renderingProgram);
    x += inc;
    if (x > 1.0f)inc = -0.01f;
    if (x < -1.0f)inc = 0.01f; //switch to moving the triangle to the right
    GLuint offsetLoc = glGetUniformLocation(renderingProgram, "offset"); //get ptr to "offset"
    glProgramUniform1f(renderingProgram, offsetLoc, x); //send value in "x" to "offset"
    glDrawArrays(GL_TRIANGLES, 0, 3);
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