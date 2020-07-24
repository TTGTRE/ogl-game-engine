//
// Created by Tre on 7/23/2020.
//

#include "Model.h"

Model::Model(Buffer *data, Texture *texture) : data(data), texture(texture) {

}

Model::~Model() {
    delete data;
}

Buffer &Model::getData() const {
    return *data;
}

Texture &Model::getTexture() const {
    return *texture;
}