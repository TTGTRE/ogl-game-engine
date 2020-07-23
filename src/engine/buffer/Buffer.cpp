//
// Created by Tre on 6/29/2020.
//

#include <fstream>
#include <iostream>
#include "Buffer.h"
#include "../OpenGL.h"

Buffer::Buffer(float *data, UInt dataLen) : data(data), dataLen(dataLen) {
    OpenGL::generateBuffers();
    index = OpenGL::fillBuffer(sizeof(float) * dataLen, data);
}

float *Buffer::getData() const {
    return data;
}

int Buffer::getDataLen() const {
    return dataLen;
}

UInt Buffer::getIndex() const {
    return index;
}

Buffer *Buffer::load(String path) {
    std::ifstream stream(path, std::ios::in);
    if (!stream)
        std::cout << "Error opening file: " << path << "\n";
    auto *floatVec = new std::vector<float>();
    float f = 0;
    while (stream >> f)
        floatVec->push_back(f);
    floatVec->shrink_to_fit();
    stream.close();
    return new Buffer(floatVec->data(), floatVec->size());
}