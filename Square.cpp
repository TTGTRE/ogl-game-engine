//
// Created by Tre on 6/15/2020.
//

#include "Square.h"

Square::Square(int x, int y) : Shape(x, y) {

}

float Square::VERTICES[12] = {
        -0.5f, 0.5f,
        0.5f, 0.5f,
        -0.5f, -0.5f,
        -0.5f, -0.5f,
        0.5f, 0.5f,
        0.5f, -0.5f
};