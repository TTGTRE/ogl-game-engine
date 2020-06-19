//
// Created by Tre on 6/15/2020.
//

#include "Shape.h"

Shape::Shape(float const vertices[], float scale, Color color) : vertices(vertices),
                                                                 scale(scale),
                                                                 color(color) {

}

float Shape::getScale() const {
    return scale;
}

float const *Shape::getVertices() const {
    return vertices;
}