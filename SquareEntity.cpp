//
// Created by Tre on 6/20/2020.
//

#include "SquareEntity.h"

SquareEntity::SquareEntity(float x, float y, float scale) : x(x), y(y), scale(scale) {

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