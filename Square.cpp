//
// Created by Tre on 6/15/2020.
//

#include "Square.h"

Square::Square(int x, int y) : Shape(x, y) {

}

float Square::VERTICES[30] = {
        -0.5f, 0.5f, 1.0f, 0.0f, 0.0f, // Top-left
        0.5f, 0.5f, 0.0f, 1.0f, 0.0f, // Top-right
        0.5f, -0.5f, 0.0f, 0.0f, 1.0f, // Bottom-right

        0.5f, -0.5f, 0.0f, 0.0f, 1.0f, // Bottom-right
        -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, // Bottom-left
        -0.5f, 0.5f, 1.0f, 0.0f, 0.0f  // Top-left
};