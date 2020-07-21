//
// Created by Tre on 7/12/2020.
//

#ifndef OGLEXPERIMENTS_CANVAS_H
#define OGLEXPERIMENTS_CANVAS_H

#include <glew.h>
#include <vector>
#include "model/Model.h"
#include "engine/Types.h"
#include "Color.h"
#include "glm.hpp"
#include "ext.hpp"

class Canvas {

    UInt width;
    UInt height;
    float scale;
    Color color;

    glm::mat4 projectionMatrix;

public:
    explicit Canvas(UInt width, UInt height);

    void setScale(float scale);
    void setColor(Color const &color);
    /**
     * Draw a model on the screen applying x and y transforms to it.
     */
    void draw(Model const *model, float x, float y, float width, float height);
    void clear();

protected:
    UInt getGridVerticeBufferSize() const;
};


#endif //OGLEXPERIMENTS_CANVAS_H
