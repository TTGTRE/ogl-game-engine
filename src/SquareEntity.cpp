//
// Created by Tre on 6/20/2020.
//

#include "SquareEntity.h"
#include "model/ModelLoader.h"

SquareEntity::SquareEntity(float x, float y, float scale) : x(x),
                                                            y(y),
                                                            scale(scale) {
    color = Color(1.0f, 1.0f, 1.0f);
    model = *ModelLoader::load("../res/square_model.txt");
}

float SquareEntity::getX() const {
    return x;
}

float SquareEntity::getY() const {
    return y;
}

float SquareEntity::getScale() const {
    return scale;
}

Color &SquareEntity::getColor() {
    return color;
}

void SquareEntity::setColor(Color const &color) {
    this->color = color;
}

Model &SquareEntity::getModel() {
    return model;
}