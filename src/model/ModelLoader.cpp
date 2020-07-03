//
// Created by Tre on 6/29/2020.
//

#include <fstream>
#include <iostream>
#include "ModelLoader.h"

Model *ModelLoader::load(std::string filePath) {
    std::ifstream stream(filePath, std::ios::binary);
    if (!stream) {
        std::cout << "Error opening file: " << filePath << "\n";
    }

    stream.seekg(0, std::ios::end);
    std::streamoff numBytes = stream.tellg();
    stream.seekg(0, std::ios::beg);
    float *arr = new float[(numBytes / sizeof(float))];
    for (int i = 0; !stream.eof(); i++) {
        float f = 0;
        stream >> f;
        arr[i] = f;
        std::cout << f << std::endl;
    }
    stream.close();

    return new Model(arr, numBytes / sizeof(float));
}