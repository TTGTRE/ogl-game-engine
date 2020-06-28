//
// Created by Tre on 6/26/2020.
//

#ifndef OGLEXPERIMENTS_DRAWABLEOBJECT_H
#define OGLEXPERIMENTS_DRAWABLEOBJECT_H


#include <glew.h>

class DrawableObject {

    int verticeCount;
    float x, y;

public:
    DrawableObject(int verticeCount);

    int getX();

    int getY();

    int getVerticeCount();

    virtual GLint getDrawMethod() = 0;
};


#endif //OGLEXPERIMENTS_DRAWABLEOBJECT_H
