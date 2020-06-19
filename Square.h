//
// Created by Tre on 6/15/2020.
//

#ifndef OGLEXPERIMENTS_SQUARE_H
#define OGLEXPERIMENTS_SQUARE_H

#include "Shape.h"

class Square : public Shape {
    static int constexpr NUM_VERTICES = 12;
    float const vertices[NUM_VERTICES] = {-0.5f, 0.5f,
                                          0.5f, 0.5f,
                                          -0.5f, -0.5f,
                                          -0.5f, -0.5f,
                                          0.5f, 0.5f,
                                          0.5f, -0.5f};
public:
    Square(float scale);

    Square(float red = 1.0, float blue = 1.0, float green = 1.0, float scale = 1.0);

    virtual int getVerticeCount() const override;
};

#endif //OGLEXPERIMENTS_SQUARE_H
