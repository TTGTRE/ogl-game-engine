//
// Created by Tre on 7/6/2020.
//

#ifndef OGLEXPERIMENTS_COLOR_H
#define OGLEXPERIMENTS_COLOR_H

#include "Triple.h"

struct Color : private Triple<float> {
    using Triple<float>::operator[];

    Color(float r, float g, float b);

    float getRed();

    float getGreen();

    float getBlue();
};


#endif //OGLEXPERIMENTS_COLOR_H
