//
// Created by Tre on 6/20/2020.
//

#include "Entity.h"
#include "model/ModelLoader.h"

Entity::Entity(UInt modelIndex, float x, float y, float width, float height) : modelIndex(modelIndex), x(x), y(y), width(width), height(height) {
    color = Color(1.0f, 1.0f, 1.0f);
    model = Model::MODEL_VECTOR[modelIndex];
}

float Entity::getX() const {
    return x;
}

float Entity::getY() const {
    return y;
}

float Entity::getWidth() const {
    return width;
}

void Entity::setWidth(float width) {
    this->width = width;
}

float Entity::getHeight() const {
    return height;
}

void Entity::setHeight(float height) {
    this->height = height;
}

Color const &Entity::getColor() const {
    return color;
}

void Entity::setColor(Color const &color) {
    this->color = color;
}

Model const *Entity::getModel() const {
    return model;
}

void Entity::setModel(Model const *model) {
    this->model = model;
}