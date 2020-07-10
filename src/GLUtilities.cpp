//
// Created by Tre on 7/10/2020.
//

#include "GLUtilities.h"

GLuint GLUtilities::vboArray[VBO_COUNT];
bool GLUtilities::buffersReady;

void GLUtilities::generateBuffers() {
    if (!buffersReady) {
        glGenBuffers(VBO_COUNT, vboArray);
        buffersReady = true;
    }
}

void GLUtilities::fillBuffer(uint8_t index, unsigned int bufferSize, float *bufferData) {
    glBindBuffer(GL_ARRAY_BUFFER, vboArray[index]);
    glBufferData(GL_ARRAY_BUFFER, bufferSize, bufferData, GL_STATIC_DRAW);
}