//
// Created by Tre on 7/12/2020.
//

#include "Canvas.h"
#include "OpenGL.h"

Canvas::Canvas(UInt width, UInt height) : width(width), height(height) {
    OpenGL::setVertexShader("vertex_shader.glsl");
    OpenGL::setFragmentShader("fragment_shader.glsl");
    OpenGL::createShaderProgram();

    projectionMatrix = glm::ortho(0.0f, static_cast<float>(width), static_cast<float>(height), 0.0f, -1.0f, 1.0f);
}

void Canvas::setColor(Color const &color) {
    this->color = color;
}

void Canvas::draw(Model &model, float x, float y, float width, float height) {
    OpenGL::useDefaultShaderProgram();

    UInt verticeBufferIndex = model.getVertices().getIndex();
    UInt textureBufferIndex = model.getTextureCoords().getIndex();

    glBindBuffer(GL_ARRAY_BUFFER, OpenGL::vboArray[verticeBufferIndex]);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, OpenGL::vboArray[textureBufferIndex]);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(1);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, model.getTexture().getId());

    OpenGL::setUniform<float>(OpenGL::Uniform::COLOR, color[0], color[1], color[2]);
    OpenGL::setUniform<glm::mat4>(OpenGL::Uniform::PROJECTION, projectionMatrix);

    glm::mat4 modelMatrix = glm::mat4(1.0f);
    modelMatrix = glm::translate(modelMatrix, glm::vec3(x, y, 0.0f));
    modelMatrix = glm::scale(modelMatrix, glm::vec3(width, height, 1.0f));
    OpenGL::setUniform<glm::mat4>(OpenGL::Uniform::MODEL, modelMatrix);

    glDrawArrays(GL_TRIANGLES, 0, model.getVertices().getDataLen());
}

void Canvas::clear() {
    glClear(GL_DEPTH_BUFFER_BIT);
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
}