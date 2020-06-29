//
// Created by Tre on 6/26/2020.
//

#ifndef OGLEXPERIMENTS_LINEOBJECT_H
#define OGLEXPERIMENTS_LINEOBJECT_H


#include "DrawableObject.h"

class LineObject : public DrawableObject {

public:
    LineObject();

    void draw();

    GLint getDrawMethod() override;
};


#endif //OGLEXPERIMENTS_LINEOBJECT_H
