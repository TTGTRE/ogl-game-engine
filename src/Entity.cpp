//
// Created by Tre on 6/20/2020.
//

#include "Entity.h"
#include "model/ModelLoader.h"

Entity::Entity(uint8_t modelIndex, float x, float y, float scale) : modelIndex(modelIndex),
                                                                    x(x),
                                                                    y(y),
                                                                    scale(scale) {
    color = Color(1.0f, 1.0f, 1.0f);
    model = Model::MODEL_VECTOR[modelIndex];
}

float Entity::getX() const {
    return x;
}

float Entity::getY() const {
    return y;
}

float Entity::getScale() const {
    return scale;
}

Color &Entity::getColor() {
    return color;
}

void Entity::setColor(Color const &color) {
    this->color = color;
}

Model const *Entity::getModel() {
    return model;
}

void Entity::setModel(Model const *model) {
    this->model = model;
}