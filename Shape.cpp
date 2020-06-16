//
// Created by Tre on 6/15/2020.
//

#include "Shape.h"

Shape::Shape(int x, int y) : x(x), y(y) {

}

int Shape::getX() const {
    return x;
}

int Shape::getY() const {
    return y;
}