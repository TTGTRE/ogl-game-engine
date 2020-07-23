//
// Created by Tre on 6/20/2020.
//

#include "Entity.h"

Entity::Entity(float x, float y, float width, float height) : x(x),
                                                              y(y),
                                                              width(width),
                                                              height(height) {
    color = Color(1.0f, 1.0f, 1.0f);
}

Entity::~Entity() {
    delete model;
    delete texture;
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

Model &Entity::getModel() const {
    return *model;
}

void Entity::setModel(Model *model) {
    this->model = model;
}

Texture &Entity::getTexture() const {
    return *texture;
}