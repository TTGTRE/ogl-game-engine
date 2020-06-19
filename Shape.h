//
// Created by Tre on 6/15/2020.
//

#ifndef OGLEXPERIMENTS_SHAPE_H
#define OGLEXPERIMENTS_SHAPE_H

#include "Color.h"

class Shape {
    float scale;
    float const *vertices;
    Color color;
public:
    Shape(float const vertices[], float scale = 1.0f, Color color = BLUE);

    float getScale() const;

    float const *getVertices() const;

    virtual int getVerticeCount() const = 0;
};

#endif //OGLEXPERIMENTS_SHAPE_H
