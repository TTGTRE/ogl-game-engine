//
// Created by Tre on 6/29/2020.
//

#include "Model.h"
#include "../GLUtilities.h"

Model::Model(GLuint vboIndex, float *bufferData, int arrayLen) : vboIndex(vboIndex),
                                                                 bufferData(bufferData),
                                                                 arrayLen(arrayLen) {
    MODEL_VECTOR.emplace_back(this);
    GLUtilities::generateBuffers();
    GLUtilities::fillBuffer(vboIndex, sizeof(float) * arrayLen, bufferData);
}

float *Model::getBufferData() const {
    return bufferData;
}

int Model::getNumVertices() const {
    return arrayLen;
}

GLuint Model::getVboIndex() const {
    return vboIndex;
}

std::vector<Model *> Model::MODEL_VECTOR;