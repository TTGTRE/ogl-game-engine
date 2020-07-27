//
// Created by Tre on 7/9/2020.
//

#include "SquareEntity.h"
#include "ResourceManager.h"

SquareEntity::SquareEntity() : Entity(*ResourceManager::SQUARE_MODEL, *ResourceManager::SPACE_TEXTURE) {

}