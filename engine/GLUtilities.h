#ifndef OGLEXPERIMENTS_GLUTILITIES_H
#define OGLEXPERIMENTS_GLUTILITIES_H

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
    GLuint createShaderProgram(const char *vertexPath, const char *fragmentPath);
}

#endif //OGLEXPERIMENTS_GLUTILITIES_H
