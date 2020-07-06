//
// Created by Tre on 6/29/2020.
//

#ifndef OGLEXPERIMENTS_MODEL_H
#define OGLEXPERIMENTS_MODEL_H


#include <glew.h>

class Model {

    float *verticeArray;
    int arrayLength;

public:
    Model(float *verticeArray, int arrayLength);

    float *getVerticeArray() const;

    int getNumVertices() const;
};


#endif //OGLEXPERIMENTS_MODEL_H
