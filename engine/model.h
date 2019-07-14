//
// Created by Tre on 7/13/2019.
//

#ifndef OGLEXPERIMENTS_MODEL_H
#define OGLEXPERIMENTS_MODEL_H


#include <ext.hpp>
#include <iostream>

namespace engine {
    class model {
    public:
        float x, y, z;
        model(float x, float y, float z) : x(x), y(y), z(z) {

        }

        float loc_x() {
            return x;
        }

        float loc_y() {
            return y;
        }

        float loc_z() {
            return z;
        }

    };
}

#endif //OGLEXPERIMENTS_MODEL_H
