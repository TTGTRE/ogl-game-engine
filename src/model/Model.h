//
// Created by Tre on 6/29/2020.
//

#ifndef OGLEXPERIMENTS_MODEL_H
#define OGLEXPERIMENTS_MODEL_H


#include <glew.h>
#include <vector>

class Model {

    unsigned int index;
    float *bufferData;
    int arrayLen;

    static GLuint nextIndex;

public:
    //TODO Should be accessed through getter method
    static std::vector<Model *> MODEL_VECTOR;

public:
    Model() = default;

    Model(unsigned int index, float *bufferData, int arrayLen);

    float *getBufferData() const;

    int getNumVertices() const;

    unsigned int getBufferIndex() const;
};


#endif //OGLEXPERIMENTS_MODEL_H
