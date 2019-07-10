#ifndef OGLEXPERIMENTS_GL_UTILITIES_H
#define OGLEXPERIMENTS_GL_UTILITIES_H

#include <string>
#include <glew.h>

using namespace std;

namespace shader_reader {
    string read_shader_source(const char *filePath);
}

namespace shader_error_checker {
    void print_shader_log(GLuint shader);
    void print_program_log(GLuint program);
    bool check_opengl_error();
}

namespace shader_maker {
    GLuint create_shader_program();
}

#endif //OGLEXPERIMENTS_GL_UTILITIES_H
