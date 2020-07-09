//
// Created by Tre on 6/20/2020.
//

#include "Entity.h"
#include "model/ModelLoader.h"

Entity::Entity(float x, float y, float scale) : x(x),
                                                y(y),
                                                scale(scale) {
    color = Color(1.0f, 1.0f, 1.0f);
}

//TODO This method should throw an exception
void Entity::setModelIndex(unsigned int index) {
    model = Model::MODEL_VECTOR[index];
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

Model *Entity::getModel() {
    return model;
}