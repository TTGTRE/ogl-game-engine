//
// Created by Tre on 7/17/2020.
//

#include "TriangleEntity.h"
#include "ResourceManager.h"

TriangleEntity::TriangleEntity() : Entity(*ResourceManager::TRIANGLE_MODEL, *ResourceManager::STARS_TEXTURE) {
}