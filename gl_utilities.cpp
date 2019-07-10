#include <fstream>
#include <iostream>
#include "gl_utilities.h"

using namespace std;

namespace shader_reader {
    string read_shader_source(const char *file_path) {
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

namespace shader_error_checker {
    void print_shader_log(GLuint shader) {
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

    void print_program_log(GLuint program) {
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

    bool check_opengl_error() {
        bool foundError = false;
        int glErr = glGetError();
        while (glErr != GL_NO_ERROR) {
            std::cout << "glError: " << glErr << std::endl;
            foundError = true;
            glErr = glGetError();
        }
        return foundError;
    }
}

namespace shader_maker {
    GLuint create_shader_program() {
        GLuint vertex_shader;
        GLuint fragment_shader;
        GLuint shader_program;

        vertex_shader = glCreateShader(GL_VERTEX_SHADER);
        fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);

        std::string vertex_shader_string = shader_reader::read_shader_source("vertex_shader.glsl");
        std::string fragment_shader_string = shader_reader::read_shader_source("fragment_shader.glsl");

        const char *vertex_shader_source = vertex_shader_string.c_str();
        const char *fragment_shader_source = fragment_shader_string.c_str();

        glShaderSource(vertex_shader, 1, &vertex_shader_source, NULL);
        glShaderSource(fragment_shader, 1, &fragment_shader_source, NULL);

        glCompileShader(vertex_shader);
        glCompileShader(fragment_shader);

        shader_program = glCreateProgram();
        glAttachShader(shader_program, vertex_shader);
        glAttachShader(shader_program, fragment_shader);
        glLinkProgram(shader_program);

        return shader_program;
    }
}

