//
// Created by Tre on 5/20/2020.
//

#include <string>
#include <iostream>
#include <fstream>
#include <glew.h>

using namespace std;

string readShaderSource(const char *file_path) {
    string content;
    ifstream file_stream(file_path, ios::in);
    string line = "";
    while (!file_stream.eof()) {
        getline(file_stream, line);
        content.append(line + "\n");
    }
    file_stream.close();
    return content;
}

void printShaderLog(GLuint shader) {
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

void printProgramLog(GLuint program) {
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

bool checkOpenGLError() {
    bool foundError = false;
    int glErr = glGetError();
    while (glErr != GL_NO_ERROR) {
        std::cout << "glError: " << glErr << std::endl;
        foundError = true;
        glErr = glGetError();
    }
    return foundError;
}

bool getCompileStatus(GLuint shader) {
    GLint status;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    return status;
}

GLuint createShaderProgram(const char *vertexPath, const char *fragmentPath) {
    GLuint vertexShader;
    GLuint fragmentShader;
    GLuint shaderProgram;

    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    std::string vertex_shader_string = readShaderSource(vertexPath);
    std::string fragment_shader_string = readShaderSource(fragmentPath);

    const char *vertex_shader_source = vertex_shader_string.c_str();
    const char *fragment_shader_source = fragment_shader_string.c_str();

    glShaderSource(vertexShader, 1, &vertex_shader_source, NULL);
    glShaderSource(fragmentShader, 1, &fragment_shader_source, NULL);

    glCompileShader(vertexShader);
    bool vertex_status = getCompileStatus(vertexShader);
    std::cout << "Vertex compile status: " << vertex_status << std::endl;

    glCompileShader(fragmentShader);
    bool fragment_status = getCompileStatus(fragmentShader);
    std::cout << "Fragment compile status: " << fragment_status << std::endl;

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    return shaderProgram;
}