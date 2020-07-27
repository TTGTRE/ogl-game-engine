//
// Created by Tre on 6/20/2020.
//

#include "Entity.h"

Entity::Entity(Model &model, Texture &texture) : model(&model), texture(&texture), x(0), y(0), width(10), height(10) {
    color = Color(1.0f, 1.0f, 1.0f);
}

float Entity::getX() const {
    return x;
}

void Entity::setX(int x) {
    this->x = x;
}

float Entity::getY() const {
    return y;
}

void Entity::setY(int y) {
    this->y = y;
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

void Entity::setTexture(Texture &texture) {
    this->texture = &texture;
}