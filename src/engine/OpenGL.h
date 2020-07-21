//
// Created by Tre on 7/13/2020.
//

#ifndef OGLEXPERIMENTS_OPENGL_H
#define OGLEXPERIMENTS_OPENGL_H

#include <cstdint>
#include <string>
#include <fwd.hpp>
#include "Types.h"

#define VBO_COUNT 10

namespace OpenGL {

    extern GLuint vboArray[VBO_COUNT];
    extern bool buffersReady;

    void generateBuffers();

    void fillBuffer(UInt index, UInt bufferSize, float *bufferData);

    UInt fillLastAvailableBuffer(UInt bufferSize, float *bufferData);

    namespace Uniform {
        static String X_POS = "xPos";
        static String Y_POS = "yPos";
        static String WIDTH = "uWidth";
        static String HEIGHT = "uHeight";
        static String SCALE = "scale";
        static String COLOR = "uColor";
        static String PROJECTION = "uProjection";
    }

    extern Shader vertexShader;
    extern Shader fragmentShader;
    extern ShaderProgram shaderProgram;

    void setVertexShader(String path);

    void setFragmentShader(String path);

    void createShaderProgram();

    void useDefaultShaderProgram();

    void printShaderLog(Shader shader);

    void printProgramLog(ShaderProgram program);

    bool checkOpenGLError();

    bool getCompileStatus(Shader shader);

    std::string readShaderSource(const char *filePath);

    template<class T>
    void setUniform(String uniform, float value);

    template<class T>
    void setUniform(String uniform, float value1, float value2, float value3);

    template<class T>
    void setUniform(String uniform, glm::mat4 matrix4f);
}


#endif //OGLEXPERIMENTS_OPENGL_H
