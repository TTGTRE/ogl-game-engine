//
// Created by Tre on 7/14/2019.
//

#ifndef OGLEXPERIMENTS_SHADERHANDLE_H
#define OGLEXPERIMENTS_SHADERHANDLE_H

#include <glew.h>

namespace Engine {

    class ShaderHandle {

        GLuint shaderProgramObject, vertexShaderObject, fragmentShaderObject;

    public:
        ShaderHandle(const char *vertexPath, const char *fragmentPath);

        ShaderHandle() = default;

        GLuint getShaderProgram();

        GLuint getVertexShader();

        GLuint getFragmentShader();
    };
}


#endif //OGLEXPERIMENTS_SHADERHANDLE_H
