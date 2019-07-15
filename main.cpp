#include <iostream>

#include <glew.h>
#include <glfw3.h>
#include <ext.hpp>
#include "gl_utilities.h"

const int WINDOW_WIDTH = 500;
const int WINDOW_HEIGHT = 500;

const int CUBE_VERTICE_COUNT = 108;
float cube_vertices[108] = {
        -1.0f, 1.0f, -1.0f, -1.0f, -1.0f, -1.0f, 1.0f, -1.0f, -1.0f,
        1.0f, -1.0f, -1.0f, 1.0f, 1.0f, -1.0f, -1.0f, 1.0f, -1.0f,
        1.0f, -1.0f, -1.0f, 1.0f, -1.0f, 1.0f, 1.0f, 1.0f, -1.0f,
        1.0f, -1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0, 1.0f, -1.0f,
        1.0f, -1.0f, 1.0f, -1.0f, -1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
        -1.0f, -1.0f, 1.0f, -1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
        -1.0f, -1.0f, 1.0f, -1.0f, -1.0f, -1.0f, -1.0f, 1.0f, 1.0f,
        -1.0f, -1.0f, -1.0f, -1.0f, 1.0f, -1.0f, -1.0f, 1.0f, 1.0f,
        -1.0f, -1.0f, 1.0f, 1.0f, -1.0f, 1.0f, 1.0f, -1.0f, -1.0f,
        1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, 1.0f,
        -1.0f, 1.0f, -1.0f, 1.0f, 1.0f, -1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f, -1.0f, 1.0f, 1.0f, -1.0f, 1.0f, -1.0f
};

GLuint vertex_arrays[1];
GLuint vertex_buffers[1];
GLuint shader_program;

float cube_x = 0.0f, cube_y = 0.0f, cube_z = -4.0f;
float view_x = 0.0f, view_y = 0.0f, view_z = 0.0f;

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_A && action == GLFW_PRESS) view_x -= 0.10f;
    if (key == GLFW_KEY_S && action == GLFW_PRESS) view_z += 0.10f;
    if (key == GLFW_KEY_D && action == GLFW_PRESS) view_x += 0.10f;
    if (key == GLFW_KEY_W && action == GLFW_PRESS) view_z -= 0.10f;
    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) view_y += 0.10f;
}

int main() {

    if (!glfwInit()) exit(EXIT_FAILURE);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    GLFWwindow *window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "OpenGL", NULL, NULL);
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) exit(EXIT_FAILURE);

    glfwSwapInterval(1);

    shader_program = shader_maker::create_shader_program();

    glGenVertexArrays(1, vertex_arrays);
    glBindVertexArray(vertex_arrays[0]);

    glGenBuffers(1, vertex_buffers);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffers[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cube_vertices), cube_vertices, GL_STATIC_DRAW);

    glfwSetKeyCallback(window, key_callback);

    while (!glfwWindowShouldClose(window)) {

//        glClear(GL_DEPTH_BUFFER_BIT);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shader_program);

        glBindBuffer(GL_ARRAY_BUFFER, vertex_buffers[0]);

        // Letting OpenGL find attribute location
        GLint pos_location = glGetAttribLocation(shader_program, "position");
        glVertexAttribPointer(pos_location, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glEnableVertexAttribArray(pos_location);

        // Define model and view matrix
        glm::mat4 model_matrix = glm::translate(glm::mat4(1.0f), glm::vec3(cube_x, cube_y, cube_z));
        glm::mat4 view_matrix = glm::translate(glm::mat4(1.0f), glm::vec3(-view_x, -view_y, -view_z));

        // Define rotation matrix
        glm::mat4 rotation_y_matrix = glm::rotate(glm::mat4(1.0f), (float) glfwGetTime() * 2.0f, glm::vec3(0.0, 1.0, 0.0));
        glm::mat4 rotation_x_matrix = glm::rotate(glm::mat4(1.0f), (float) glfwGetTime(), glm::vec3(1.0, 0.0, 0.0));
        glm::mat4 rotation_matrix = rotation_y_matrix;
        glm::mat4 perspective_matrix = glm::perspective(1.0472f, (float) WINDOW_WIDTH / (float) WINDOW_HEIGHT, 0.0f, 1000.0f);

        // Get rotation matrix location in vertex shader
        GLuint view_matrix_location = glGetUniformLocation(shader_program, "view_matrix");
        GLuint model_matrix_location = glGetUniformLocation(shader_program, "model_matrix");
        GLuint rotation_matrix_location = glGetUniformLocation(shader_program, "rotation_matrix");
        GLuint perspective_location = glGetUniformLocation(shader_program, "perspective_matrix");

        // Set value of rotation matrix in vertex shader
        glUniformMatrix4fv(model_matrix_location, 1, GL_FALSE, glm::value_ptr(model_matrix));
        glUniformMatrix4fv(view_matrix_location, 1, GL_FALSE, glm::value_ptr(view_matrix));
        glUniformMatrix4fv(rotation_matrix_location, 1, GL_FALSE, glm::value_ptr(rotation_matrix));
        glUniformMatrix4fv(perspective_location, 1, GL_FALSE, glm::value_ptr(perspective_matrix));

//        glEnable(GL_DEPTH_TEST);
//        glDepthFunc(GL_LEQUAL);

        // Must enable culling to avoid inside-out objects
        glEnable(GL_CULL_FACE);
        glFrontFace(GL_CW);

        glDrawArrays(GL_TRIANGLES, 0, CUBE_VERTICE_COUNT / 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}