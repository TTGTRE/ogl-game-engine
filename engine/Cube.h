//
// Created by Tre on 7/15/2019.
//

#ifndef OGLEXPERIMENTS_CUBE_H
#define OGLEXPERIMENTS_CUBE_H

class Cube {

    float x, y, z;
    float rotation = 0.0f;
    float scale = 1.0f;

public:

    static float VERTEX_ARRAY[108];

    Cube(float x, float y, float z);

    float getX();

    float getY();

    float getZ();

    float getRotation();

    float setRotation(float rotation);

    float getScale();

    float setScale(float scale);
};


#endif //OGLEXPERIMENTS_CUBE_H
