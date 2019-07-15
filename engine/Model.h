//
// Created by Tre on 7/13/2019.
//

#ifndef OGLEXPERIMENTS_MODEL_H
#define OGLEXPERIMENTS_MODEL_H


#include <ext.hpp>
#include <iostream>

namespace Engine {
    class Model {
    public:
        float x, y, z;
        Model(float x, float y, float z) : x(x), y(y), z(z) {

        }

        float getX() {
            return x;
        }

        float getY() {
            return y;
        }

        float getZ() {
            return z;
        }

    };
}

#endif //OGLEXPERIMENTS_MODEL_H
