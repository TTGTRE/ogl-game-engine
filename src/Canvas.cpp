//
// Created by Tre on 7/12/2020.
//

#include "Canvas.h"
#include "engine/OpenGL.h"

Canvas::Canvas(UInt width, UInt height) : width(width), height(height), scale(1.0f) {
    OpenGL::setVertexShader("vertex_shader.glsl");
    OpenGL::setFragmentShader("fragment_shader.glsl");
    OpenGL::createShaderProgram();

    projectionMatrix = glm::ortho(0.0f, static_cast<float>(width), static_cast<float>(height), 0.0f, -1.0f, 1.0f);
}

void Canvas::setScale(float scale) {
    this->scale = scale;
}

UInt Canvas::getGridVerticeBufferSize() const {
    return ((1.0f / scale * 2 * 2) * 2 * 2);
}

void Canvas::setColor(Color const &color) {
    this->color = color;
}

void Canvas::draw(Model const *model, float x, float y, float width, float height) {
    OpenGL::useDefaultShaderProgram();

    UInt vboIndex = model->getVboIndex();

    glBindBuffer(GL_ARRAY_BUFFER, OpenGL::vboArray[vboIndex]);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(0);

    OpenGL::setUniform<float>(OpenGL::Uniform::X_POS, x * 2);
    OpenGL::setUniform<float>(OpenGL::Uniform::Y_POS, y * 2);
    OpenGL::setUniform<float>(OpenGL::Uniform::WIDTH, width);
    OpenGL::setUniform<float>(OpenGL::Uniform::HEIGHT, height);
    OpenGL::setUniform<float>(OpenGL::Uniform::SCALE, scale);
    OpenGL::setUniform<float>(OpenGL::Uniform::COLOR, color[0], color[1], color[2]);
    OpenGL::setUniform<glm::mat4>(OpenGL::Uniform::PROJECTION, projectionMatrix);

    glDrawArrays(GL_TRIANGLES, 0, model->getNumVertices());
}

void Canvas::clear() {
    glClear(GL_DEPTH_BUFFER_BIT);
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
}