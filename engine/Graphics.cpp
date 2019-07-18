//
// Created by Tre on 7/16/2019.
//

#include <glew.h>
#include <cstdlib>
#include <ext.hpp>
#include <iostream>
#include <SOIL2.h>
#include "Graphics.h"
#include "../gl_utilities.h"

GLuint textureObj = 0;
float textureArray[2 * 3] = {
        0.0f, 0.0f,
        1.0f, 0.0f,
        0.0f, 1.0f,
};

Graphics::Graphics(GLFWwindow *window, int width, int height) : window(window), width(width), height(height) {
    glGenVertexArrays(1, vaos);
    glBindVertexArray(vaos[0]);

    glGenBuffers(2, vbos);
    glBindBuffer(GL_ARRAY_BUFFER, vbos[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Cube::VERTEX_ARRAY), Cube::VERTEX_ARRAY, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, vbos[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(textureArray), textureArray, GL_STATIC_DRAW);

    textureObj = SOIL_load_OGL_texture("texture.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
    if (textureObj == 0) std::cout << "Couldn't find texture." << std::endl;
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureObj);
}

void Graphics::createShaderProgram(const char *vertexPath, const char *fragmentPath) {
    shaderProgram = ShaderMaker::createShaderProgram(vertexPath, fragmentPath); // TODO Allow for more shader programs
}

void Graphics::draw(std::vector<Cube *> cubes) {

    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(shaderProgram);

    std::vector<Cube *>::iterator it = cubes.begin();
    while(it != cubes.end()) {

        glBindBuffer(GL_ARRAY_BUFFER, vbos[0]);
        GLint pos_location = glGetAttribLocation(shaderProgram, "position");
        glVertexAttribPointer(pos_location, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glEnableVertexAttribArray(pos_location);

        glBindBuffer(GL_ARRAY_BUFFER, vbos[1]);
        GLint texCoordLocation = glGetAttribLocation(shaderProgram, "vTexCoord");
        glVertexAttribPointer(texCoordLocation, 2, GL_FLOAT, GL_FALSE, 0, 0);
        glEnableVertexAttribArray(texCoordLocation);

        // Define model and view matrix
        glm::mat4 model_matrix = glm::translate(glm::mat4(1.0f), glm::vec3((*it)->getX(), (*it)->getY(), (*it)->getZ()));
        glm::mat4 view_matrix = glm::translate(glm::mat4(1.0f),
                                               glm::vec3(0.0f, 0.0f, 0.0f)); // TODO Dynamic view location

        // Define rotation matrix
        glm::mat4 rotation_matrix = glm::rotate(glm::mat4(1.0f), (*it)->getRotation(), glm::vec3(0.0, 1.0, 0.0));
        glm::mat4 perspective_matrix = glm::perspective(1.0472f, (float) width / (float) height, 0.0f, 1000.0f);

        // Get rotation matrix location in vertex shader
        GLuint view_matrix_location = glGetUniformLocation(shaderProgram, "view_matrix");
        GLuint model_matrix_location = glGetUniformLocation(shaderProgram, "model_matrix");
        GLuint rotation_matrix_location = glGetUniformLocation(shaderProgram, "rotation_matrix");
        GLuint perspective_location = glGetUniformLocation(shaderProgram, "perspective_matrix");

        // Set value of rotation matrix in vertex shader
        glUniformMatrix4fv(model_matrix_location, 1, GL_FALSE, glm::value_ptr(model_matrix));
        glUniformMatrix4fv(view_matrix_location, 1, GL_FALSE, glm::value_ptr(view_matrix));
        glUniformMatrix4fv(rotation_matrix_location, 1, GL_FALSE, glm::value_ptr(rotation_matrix));
        glUniformMatrix4fv(perspective_location, 1, GL_FALSE, glm::value_ptr(perspective_matrix));

        // Must enable culling to avoid inside-out objects
        glEnable(GL_CULL_FACE);
        glFrontFace(GL_CW);

        glDrawArrays(GL_TRIANGLES, 0, sizeof(Cube::VERTEX_ARRAY) / sizeof(*Cube::VERTEX_ARRAY) / 3);

        it++;
    }

    glfwSwapBuffers(window);
    glfwPollEvents();
}