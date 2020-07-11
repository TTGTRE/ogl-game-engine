//
// Created by Tre on 7/10/2020.
//

#ifndef OGLEXPERIMENTS_GLUTILITIES_H
#define OGLEXPERIMENTS_GLUTILITIES_H

#include <glew.h>
#include <cstdint>

#define VBO_COUNT 10

namespace GLUtilities {

    extern GLuint vboArray[VBO_COUNT];
    extern bool buffersReady;

    void generateBuffers();

    void fillBuffer(uint8_t index, unsigned int bufferSize, float *bufferData);
}

#endif //OGLEXPERIMENTS_GLUTILITIES_H
