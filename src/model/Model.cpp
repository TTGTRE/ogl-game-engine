//
// Created by Tre on 6/29/2020.
//

#include "Model.h"

Model::Model(float *verticeArray) : verticeArray(verticeArray) {

}

float *Model::getVerticeArray() const {
    return verticeArray;
}