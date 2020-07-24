//
// Created by Tre on 7/23/2020.
//

#ifndef OGLEXPERIMENTS_MODEL_H
#define OGLEXPERIMENTS_MODEL_H


#include "../buffer/Buffer.h"
#include "../texture/Texture.h"

class Model {
    Buffer *data;
    Texture *texture;
public:
    Model(Buffer *data, Texture *texture);
    ~Model();
    Buffer &getData() const;
    Texture &getTexture() const;
};


#endif //OGLEXPERIMENTS_MODEL_H
