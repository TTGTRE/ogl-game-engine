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

class Canvas {

    UInt width;
    UInt height;
    float scale;
    Color color;

public:
    explicit Canvas(UInt width, UInt height);

    void setScale(float scale);
    void setColor(Color const &Color);
    /**
     * Draw a model on the screen applying x and y transforms to it.
     */
    void draw(Model const *model, float x, float y);
    void drawGrid();
    void clear();

protected:
    UInt getGridVerticeBufferSize() const;
};


#endif //OGLEXPERIMENTS_CANVAS_H
