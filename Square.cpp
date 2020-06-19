//
// Created by Tre on 6/15/2020.
//

#include "Square.h"

Square::Square(float scale) : Shape(vertices, scale, 1, 1, 1) {

}

Square::Square(float red, float blue, float green, float scale) : Shape(
        vertices, red, blue, green, scale) {

}

int Square::getVerticeCount() const {
    return NUM_VERTICES;
}