//
// Created by Tre on 6/20/2020.
//

#ifndef OGLEXPERIMENTS_ENTITY_H
#define OGLEXPERIMENTS_ENTITY_H

#include <memory>
#include "Triple.h"
#include "Color.h"
#include "model/Model.h"

class Entity {
protected:
    UInt modelIndex;
private:
    float x;
    float y;
    float width;
    float height;
    Color color;
    Model const *model;
public:
    float getX() const;

    float getY() const;

    float getWidth() const;

    void setWidth(float width);

    float getHeight() const;

    void setHeight(float height);

    Color const &getColor() const;

    void setColor(Color const &color);

    Model const *getModel() const;

protected:
    Entity(UInt modelIndex, float x, float y, float width, float height);

    void setModel(Model const *model);
};


#endif //OGLEXPERIMENTS_ENTITY_H
