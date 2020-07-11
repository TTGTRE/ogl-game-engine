//
// Created by Tre on 7/9/2020.
//

#ifndef OGLEXPERIMENTS_SQUAREENTITY_H
#define OGLEXPERIMENTS_SQUAREENTITY_H

#include "Entity.h"

class SquareEntity : public Entity {

public:
    SquareEntity(float x, float y, float scale = WorldProperties::getEntityWorldScale());
};


#endif //OGLEXPERIMENTS_SQUAREENTITY_H
