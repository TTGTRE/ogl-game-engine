//
// Created by Tre on 6/29/2020.
//

#include "Model.h"

Model::Model(float *verticeArray, int arrayLength) : verticeArray(verticeArray), arrayLength(arrayLength) {

}

float *Model::getVerticeArray() const {
    return verticeArray;
}

int Model::getNumVertices() const {
    return arrayLength;
}