//
// Created by Tre on 6/29/2020.
//

#ifndef OGLEXPERIMENTS_BUFFER_H
#define OGLEXPERIMENTS_BUFFER_H

#include <glew.h>
#include <vector>
#include "../Types.h"

class Buffer {
    UInt index;
    float *data;
    int dataLen;
public:
    Buffer() = default;

    Buffer(float *data, UInt dataLen);

    float *getData() const;

    int getDataLen() const;

    UInt getIndex() const;

    static Buffer *Buffer::load(String path);
};


#endif //OGLEXPERIMENTS_BUFFER_H
