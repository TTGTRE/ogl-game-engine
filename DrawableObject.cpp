//
// Created by Tre on 6/26/2020.
//

#include "DrawableObject.h"

DrawableObject::DrawableObject(int verticeCount) : verticeCount(verticeCount) {

}

int DrawableObject::getX() {
    return x;
}

int DrawableObject::getY() {
    return y;
}

int DrawableObject::getVerticeCount() {
    return verticeCount;
}

GLint DrawableObject::getDrawMethod() {
    return GL_LINES;
}