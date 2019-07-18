#include <fstream>
#include <iostream>
#include "gl_utilities.h"

using namespace std;

namespace ShaderReader {
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
}

namespace ShaderErrorChecker {
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
}

namespace ShaderMaker {
    GLuint createShaderProgram(const char *vertexPath, const char *fragmentPath) {
        GLuint vertex_shader;
        GLuint fragment_shader;
        GLuint shader_program;

        vertex_shader = glCreateShader(GL_VERTEX_SHADER);
        fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);

        std::string vertex_shader_string = ShaderReader::readShaderSource(vertexPath);
        std::string fragment_shader_string = ShaderReader::readShaderSource(fragmentPath);

        const char *vertex_shader_source = vertex_shader_string.c_str();
        const char *fragment_shader_source = fragment_shader_string.c_str();

        glShaderSource(vertex_shader, 1, &vertex_shader_source, NULL);
        glShaderSource(fragment_shader, 1, &fragment_shader_source, NULL);


        glCompileShader(vertex_shader);
        bool vertex_status = ShaderErrorChecker::getCompileStatus(vertex_shader);
        std::cout << "Vertex compile status: " << vertex_status << std::endl;

        glCompileShader(fragment_shader);
        bool fragment_status = ShaderErrorChecker::getCompileStatus(fragment_shader);
        std::cout << "Fragment compile status: " << fragment_status << std::endl;

        shader_program = glCreateProgram();
        glAttachShader(shader_program, vertex_shader);
        glAttachShader(shader_program, fragment_shader);
        glLinkProgram(shader_program);

        return shader_program;
    }
}

