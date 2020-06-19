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
    Square(float scale = 1.0f, Color color = BLUE);

    virtual int getVerticeCount() const override;
};

#endif //OGLEXPERIMENTS_SQUARE_H
