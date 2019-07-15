//
// Created by Tre on 7/14/2019.
//

#include <string>
#include <iostream>
#include "ShaderHandle.h"
#include "../GLUtilities.h"

Engine::ShaderHandle::ShaderHandle(const char *vertexPath, const char *fragmentPath) {
    vertexShaderObject = glCreateShader(GL_VERTEX_SHADER);
    fragmentShaderObject = glCreateShader(GL_FRAGMENT_SHADER);

    std::string vertexShaderString = ShaderReader::readShaderSource(vertexPath);
    std::string fragmentShaderString = ShaderReader::readShaderSource(fragmentPath);

    const char *vertexShaderSource = vertexShaderString.c_str();
    const char *fragmentShaderSource = fragmentShaderString.c_str();

    glShaderSource(vertexShaderObject, 1, &vertexShaderSource, NULL);
    glShaderSource(fragmentShaderObject, 1, &fragmentShaderSource, NULL);

    int compileStatus;

    glCompileShader(vertexShaderObject);
    ShaderErrorChecker::checkOpenGLError();
    glGetShaderiv(vertexShaderObject, GL_COMPILE_STATUS, &compileStatus);
    if (compileStatus != 1) {
        std::cout << "Vertex compilation failed." << std::endl;
        ShaderErrorChecker::printShaderLog(vertexShaderObject);
    }

    glCompileShader(fragmentShaderObject);
    ShaderErrorChecker::checkOpenGLError();
    glGetShaderiv(fragmentShaderObject, GL_COMPILE_STATUS, &compileStatus);
    if (compileStatus != 1) {
        std::cout << "Fragment compilation failed." << std::endl;
        ShaderErrorChecker::printShaderLog(fragmentShaderObject);
    }

    shaderProgramObject = glCreateProgram();

    glAttachShader(shaderProgramObject, vertexShaderObject);
    glAttachShader(shaderProgramObject, fragmentShaderObject);

    glLinkProgram(shaderProgramObject);

    ShaderErrorChecker::checkOpenGLError();
    glGetProgramiv(shaderProgramObject, GL_LINK_STATUS, &compileStatus);
    if (compileStatus != 1) {
        std::cout << "Program linkage failed." << std::endl;
        ShaderErrorChecker::printProgramLog(shaderProgramObject);
    }

    std::cout << "Finished linking program." << std::endl;
}

GLuint Engine::ShaderHandle::getShaderProgram() {
    return shaderProgramObject;
}

GLuint Engine::ShaderHandle::getVertexShader() {
    return vertexShaderObject;
}

GLuint Engine::ShaderHandle::getFragmentShader() {
    return fragmentShaderObject;
}