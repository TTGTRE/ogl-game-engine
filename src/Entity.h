//
// Created by Tre on 6/20/2020.
//

#ifndef OGLEXPERIMENTS_ENTITY_H
#define OGLEXPERIMENTS_ENTITY_H

#include <memory>
#include "EngineConstants.h"
#include "Triple.h"
#include "Color.h"
#include "model/Model.h"

class Entity {
    float x, y;
    float scale;
    Color color;
    Model *model;

public:
    float getX() const;

    float getY() const;

    float getScale() const;

    Color &getColor();

    void setColor(Color const &color);

    Model *getModel();

protected:
    Entity(float x, float y, float scale = EngineConstants::COORDINATE_GRID_SCALE);

    //TODO Make this method part of the constructor
    void setModelIndex(unsigned int index);
};


#endif //OGLEXPERIMENTS_ENTITY_H
