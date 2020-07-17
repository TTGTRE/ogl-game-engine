//
// Created by Tre on 7/13/2020.
//

#include "OpenGL.h"
#include <glew.h>
#include <iostream>
#include <fstream>

GLuint OpenGL::vboArray[VBO_COUNT];
bool OpenGL::buffersReady;

Shader OpenGL::vertexShader;
Shader OpenGL::fragmentShader;
ShaderProgram OpenGL::shaderProgram;

void OpenGL::generateBuffers() {
    if (!buffersReady) {
        glGenBuffers(VBO_COUNT, vboArray);
        buffersReady = true;
    }
}

void OpenGL::fillBuffer(UInt index, UInt bufferSize, float *bufferData) {
    glBindBuffer(GL_ARRAY_BUFFER, vboArray[index]);
    glBufferData(GL_ARRAY_BUFFER, bufferSize, bufferData, GL_STATIC_DRAW);
}

UInt OpenGL::fillLastAvailableBuffer(UInt bufferSize, float *bufferData) {
    UInt bufferIndex;
    for (bufferIndex = VBO_COUNT - 1; bufferIndex > 0; bufferIndex--) {
        if (vboArray[bufferIndex] == 0) {
            fillBuffer(bufferIndex, bufferSize, bufferData);
            return bufferIndex;
        }
    }
    std::cout << "No available buffers." << std::endl;
    exit(EXIT_SUCCESS);
}

void OpenGL::setVertexShader(String path) {
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    std::string ss = OpenGL::readShaderSource(path);
    String shaderString = ss.c_str();
    glShaderSource(vertexShader, 1, &shaderString, NULL);
    glCompileShader(vertexShader);
    bool vertex_status = OpenGL::getCompileStatus(vertexShader);
    std::cout << "Vertex compile status: " << vertex_status << std::endl;
    OpenGL::checkOpenGLError();
}

void OpenGL::setFragmentShader(String path) {
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    std::string ss = OpenGL::readShaderSource(path);
    String shaderString = ss.c_str();
    glShaderSource(fragmentShader, 1, &shaderString, NULL);
    glCompileShader(fragmentShader);
    bool vertex_status = OpenGL::getCompileStatus(fragmentShader);
    std::cout << "Fragment compile status: " << vertex_status << std::endl;
    OpenGL::checkOpenGLError();
}

std::string OpenGL::readShaderSource(const char *filePath) {
    std::string content;
    std::ifstream file_stream(filePath, std::ios::in);
    std::string line = "";
    while (!file_stream.eof()) {
        getline(file_stream, line);
        content.append(line + "\n");
    }
    file_stream.close();
    return content;
}

void OpenGL::printShaderLog(GLuint shader) {
    int len = 0;
    int chWrittn = 0;
    char *log;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &len);
    if (len > 0) {
        log = (char *) malloc(len);
        glGetShaderInfoLog(shader, len, &chWrittn, log);
        std::cout << "Shader Info Log: " << log << std::endl;
        free(log);
    }

}

void OpenGL::createShaderProgram() {
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    checkOpenGLError();
    printProgramLog(shaderProgram);
}

void OpenGL::printProgramLog(GLuint program) {
    int len = 0;
    int chWrittn = 0;
    char *log;
    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &len);
    if (len > 0) {
        log = (char *) malloc(len);
        glGetProgramInfoLog(program, len, &chWrittn, log);
        std::cout << "Program Info Log: " << log << std::endl;
        free(log);
    }
}

bool OpenGL::checkOpenGLError() {
    bool foundError = false;
    int glErr = glGetError();
    while (glErr != GL_NO_ERROR) {
        std::cout << "glError: " << glErr << std::endl;
        foundError = true;
        glErr = glGetError();
    }
    return foundError;
}

bool OpenGL::getCompileStatus(GLuint shader) {
    GLint status;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    return status;
}

void OpenGL::useDefaultShaderProgram() {
    glUseProgram(shaderProgram);
}

template<>
void OpenGL::setUniform<float>(String uniform, float value) {
    GLuint location = glGetUniformLocation(shaderProgram, uniform);
    glUniform1f(location, value);
}

template<>
void OpenGL::setUniform<float>(String uniform, float value1, float value2, float value3) {
    GLuint location = glGetUniformLocation(shaderProgram, uniform);
    glUniform3f(location, value1, value2, value3);
}