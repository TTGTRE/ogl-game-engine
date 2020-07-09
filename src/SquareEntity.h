//
// Created by Tre on 6/20/2020.
//

#ifndef OGLEXPERIMENTS_SQUAREENTITY_H
#define OGLEXPERIMENTS_SQUAREENTITY_H

#include <memory>
#include "EngineConstants.h"
#include "Triple.h"
#include "Color.h"
#include "model/Model.h"

class SquareEntity {
    float x, y;
    float scale;
    Color color;
    Model *model;
public:
    SquareEntity(float x, float y, float scale = EngineConstants::COORDINATE_GRID_SCALE);

    float getX() const;

    float getY() const;

    float getScale() const;

    Color &getColor();

    void setColor(Color const &color);

    Model *getModel();
};


#endif //OGLEXPERIMENTS_SQUAREENTITY_H
