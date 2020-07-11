//
// Created by Tre on 6/20/2020.
//

#ifndef OGLEXPERIMENTS_ENTITY_H
#define OGLEXPERIMENTS_ENTITY_H

#include <memory>
#include "Triple.h"
#include "Color.h"
#include "model/Model.h"
#include "WorldProperties.h"

class Entity {
protected:
    uint8_t modelIndex;
private:
    float x, y;
    float scale;
    Color color;
    Model const *model;
public:
    float getX() const;

    float getY() const;

    float getScale() const;

    Color &getColor();

    void setColor(Color const &color);

    Model const *getModel();

protected:
    Entity(uint8_t modelIndex, float x, float y, float scale = WorldProperties::getEntityWorldScale());

    void setModel(Model const *model);
};


#endif //OGLEXPERIMENTS_ENTITY_H
