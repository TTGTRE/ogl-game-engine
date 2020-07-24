//
// Created by Tre on 7/17/2020.
//

#include "TriangleEntity.h"
#include "ResourceManager.h"

TriangleEntity::TriangleEntity(float x, float y, float width, float height) : Entity(x, y, width, height) {
    setModel(ResourceManager::TRIANGLE_MODEL);
    setTexture(*ResourceManager::STARS_TEXTURE);
}