//
// Created by Tre on 6/29/2020.
//

#include <fstream>
#include <iostream>
#include <vector>
#include "ModelLoader.h"

unsigned int ModelLoader::index = 0;

bool ModelLoader::initialized;

GLuint ModelLoader::vboArray[VBO_COUNT];

Model *ModelLoader::load(std::string filePath) {
    if (!initialized) {
        glGenBuffers(VBO_COUNT, vboArray);
    }
    std::ifstream stream(filePath, std::ios::in);
    if (!stream)
        std::cout << "Error opening file: " << filePath << "\n";
    auto *floatVec = new std::vector<float>();
    float f = 0;
    while (stream >> f)
        floatVec->push_back(f);
    floatVec->shrink_to_fit();
    stream.close();
    glBindBuffer(GL_ARRAY_BUFFER, vboArray[index]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * floatVec->size(), floatVec->data(), GL_STATIC_DRAW);
    Model *model = new Model(index, floatVec->data(), floatVec->size());
    index++;
    return model;
}