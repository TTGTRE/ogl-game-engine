//
// Created by Tre on 7/23/2020.
//

#ifndef OGLEXPERIMENTS_MODEL_H
#define OGLEXPERIMENTS_MODEL_H


#include "../buffer/Buffer.h"
#include "../texture/Texture.h"

class Model {
    Buffer *vertices;
    Buffer *textureCoords;
    Texture *texture;
public:
    Model(Buffer *vertices, Buffer *textureCoords, Texture *texture);
    ~Model();
    Buffer &getVertices() const;
    Buffer &getTextureCoords() const;
    Texture &getTexture() const;
};


#endif //OGLEXPERIMENTS_MODEL_H
