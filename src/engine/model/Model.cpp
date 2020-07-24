//
// Created by Tre on 7/23/2020.
//

#include "Model.h"

Model::Model(Buffer *data) : data(data) {

}

Model::~Model() {
    delete data;
}

Buffer &Model::getData() const {
    return *data;
}