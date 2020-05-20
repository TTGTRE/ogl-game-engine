//
// Created by Tre on 7/15/2019.
//

#ifndef OGLEXPERIMENTS_CUBE_H
#define OGLEXPERIMENTS_CUBE_H

#include "Texture.h"

class Cube {

    float x, y, z;
    float rotation = 0.0f;
    Texture *texture;

public:

    static float VERTEX_ARRAY[108];

    Cube(float x, float y, float z);

    float getX();

    float getY();

    float getZ();

    float getRotation();

    void setRotation(float rotation);

    void setTexture(Texture *texture);

    Texture *getTexture();
};


#endif //OGLEXPERIMENTS_CUBE_H
