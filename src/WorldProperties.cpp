//
// Created by Tre on 7/10/2020.
//

#include "WorldProperties.h"

float WorldProperties::entityWorldScale = 1.0f;

float WorldProperties::getEntityWorldScale() {
    return entityWorldScale;
}

void WorldProperties::setEntityWorldScale(float scale) {
    entityWorldScale = scale;
}