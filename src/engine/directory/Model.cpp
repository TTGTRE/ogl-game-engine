//
// Created by Tre on 7/23/2020.
//

#include "Model.h"

Model::Model(Buffer *vertices, Buffer *textureCoords, Texture *texture) : vertices(vertices),
                                                                          textureCoords(textureCoords),
                                                                          texture(texture) {

}

Model::~Model() {
    delete vertices;
    delete textureCoords;
}

Buffer &Model::getVertices() const {
    return *vertices;
}

Buffer &Model::getTextureCoords() const {
    return *textureCoords;
}

Texture &Model::getTexture() const {
    return *texture;
}