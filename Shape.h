//
// Created by Tre on 6/15/2020.
//

#ifndef OGLEXPERIMENTS_SHAPE_H
#define OGLEXPERIMENTS_SHAPE_H

#include "Triple.h"

class Shape {
    float scale;
    float const *vertices;
    Triple<float> colorRgb;
protected:
    Shape(float const vertices[], float scale = 1.0);

    Shape(float const vertices[], float red = 1.0, float blue = 1.0, float green = 1.0, float scale = 1.0);

public:

    void setColor(float red, float green, float blue);

    Triple<float> *getColor();

    float getScale() const;

    float const *getVertices() const;

    virtual int getVerticeCount() const = 0;
};

#endif //OGLEXPERIMENTS_SHAPE_H
