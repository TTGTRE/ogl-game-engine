//
// Created by Tre on 6/15/2020.
//

#include "Square.h"

Square::Square(float scale, Color color) : Shape(vertices, scale, color) {}

int Square::getVerticeCount() const {
    return NUM_VERTICES;
}