//
// Created by Tre on 6/15/2020.
//

#include "Shape.h"

Shape::Shape(float const vertices[], float scale) : vertices(vertices),
                                                    scale(scale),
                                                    colorRgb{1, 0, 1} {
}

Shape::Shape(float const vertices[], float red, float green, float blue, float scale) : vertices(vertices),
                                                                                        colorRgb{red, green, blue},
                                                                                        scale(scale) {
}

Triple<float> *Shape::getColor() {
    return &colorRgb;
}

void Shape::setColor(float red, float green, float blue) {
    colorRgb.first = red, colorRgb.second = green, colorRgb.third = blue;
}

float Shape::getScale() const {
    return scale;
}

float const *Shape::getVertices() const {
    return vertices;
}