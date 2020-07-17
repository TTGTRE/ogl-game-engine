//
// Created by Tre on 6/29/2020.
//

#ifndef OGLEXPERIMENTS_MODEL_H
#define OGLEXPERIMENTS_MODEL_H

#include <glew.h>
#include <vector>
#include "../engine/Types.h"

class Model {
    GLuint vboIndex;
    float *bufferData;
    int arrayLen;
public:
    static std::vector<Model *> MODEL_VECTOR;

public:
    Model() = default;

    Model(UInt vboIndex, float *bufferData, int arrayLen);

    float *getBufferData() const;

    int getNumVertices() const;

    UInt getVboIndex() const;
};


#endif //OGLEXPERIMENTS_MODEL_H
