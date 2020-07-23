//
// Created by Tre on 7/12/2020.
//

#ifndef OGLEXPERIMENTS_CANVAS_H
#define OGLEXPERIMENTS_CANVAS_H

#include <glew.h>
#include <vector>
#include "Types.h"
#include "Color.h"
#include "glm.hpp"
#include "ext.hpp"
#include "buffer/Buffer.h"
#include "directory/Model.h"

class Canvas {

    UInt width;
    UInt height;
    Color color;

    glm::mat4 projectionMatrix;

public:
    explicit Canvas(UInt width, UInt height);

    void setColor(Color const &color);
    /**
     * Draw a model on the screen applying x and y transforms to it.
     */
    void draw(Model &model, float x, float y, float width, float height);
    void clear();
};


#endif //OGLEXPERIMENTS_CANVAS_H
