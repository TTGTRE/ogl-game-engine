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
#include "model/Model.h"
#include "Entity.h"

class Canvas {

    UInt width;
    UInt height;
    Color color;
    Texture *texture;

    glm::mat4 projectionMatrix;

public:
    explicit Canvas(UInt width, UInt height);
    ~Canvas();

    void setColor(Color const &color);
    /**
     * Draw a model on the screen applying x and y transforms to it.
     */
    void setTexture(Texture &texture);
    void draw(Model &model, float x, float y, float width, float height);
    void clear();
};


#endif //OGLEXPERIMENTS_CANVAS_H
