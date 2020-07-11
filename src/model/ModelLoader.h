//
// Created by Tre on 6/29/2020.
//

#ifndef OGLEXPERIMENTS_MODELLOADER_H
#define OGLEXPERIMENTS_MODELLOADER_H


#include <string>
#include "Model.h"

class ModelLoader {
    static GLuint index;
public:
    static Model *load(std::string filePath);
};


#endif //OGLEXPERIMENTS_MODELLOADER_H
