//
// Created by Tre on 7/9/2020.
//

#include "SquareEntity.h"
#include "ResourceManager.h"

SquareEntity::SquareEntity(float x, float y, float width, float height) : Entity(x, y, width, height) {
    setModel(ResourceManager::SQUARE_MODEL);
}