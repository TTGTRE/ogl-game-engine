#ifndef OGLEXPERIMENTS_GL_UTILITIES_H
#define OGLEXPERIMENTS_GL_UTILITIES_H

#include <string>
#include <glew.h>

using namespace std;

namespace ShaderReader {
    string readShaderSource(const char *filePath);
}

namespace ShaderErrorChecker {
    void printShaderLog(GLuint shader);
    void printProgramLog(GLuint program);
    bool checkOpenGLError();
    bool getCompileStatus(GLuint shader);
}

namespace ShaderMaker {
    GLuint createShaderProgram();
}

#endif //OGLEXPERIMENTS_GL_UTILITIES_H
