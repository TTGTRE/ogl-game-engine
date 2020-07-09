//
// Created by Tre on 6/29/2020.
//

#include "Model.h"

Model::Model(unsigned int index, float *bufferData, int arrayLen) : index(index),
                                                                    bufferData(bufferData),
                                                                    arrayLen(arrayLen) {
    MODEL_VECTOR.emplace_back(this);
}

float *Model::getBufferData() const {
    return bufferData;
}

int Model::getNumVertices() const {
    return arrayLen;
}

GLuint Model::getBufferIndex() const {
    return index;
}

GLuint Model::nextIndex = 0;
std::vector<Model *> Model::MODEL_VECTOR;