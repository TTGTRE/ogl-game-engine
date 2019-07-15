//
// Created by Tre on 7/15/2019.
//

#ifndef OGLEXPERIMENTS_MODELBUFFER_H
#define OGLEXPERIMENTS_MODELBUFFER_H

#include <vector>
#include "BasicModel.h"

class ModelBuffer {

    std::vector<BasicModel *> modelVector;

public:

    void addModel(BasicModel *model) {
        modelVector.push_back(model);
    }

    BasicModel *getModel(int index) {
        return modelVector[index];
    }
};


#endif //OGLEXPERIMENTS_MODELBUFFER_H
