//
// Created by Tre on 6/26/2020.
//
#include <glew.h>
#include "LineObject.h"

LineObject::LineObject() : DrawableObject(2) {

}

void LineObject::draw() {

}

GLint LineObject::getDrawMethod() {
    return GL_LINES;
}
