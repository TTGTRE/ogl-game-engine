//
// Created by Tre on 6/29/2020.
//

#ifndef OGLEXPERIMENTS_MODELLOADER_H
#define OGLEXPERIMENTS_MODELLOADER_H


#include <string>
#include "Model.h"

#define VBO_COUNT 10

class ModelLoader {
public:
    static GLuint vboArray[];
private:
    static unsigned int index;
    static bool initialized;
public:
    static Model *load(std::string filePath);
};


#endif //OGLEXPERIMENTS_MODELLOADER_H
