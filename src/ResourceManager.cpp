//
// Created by Tre on 7/22/2020.
//

#include "ResourceManager.h"

void ResourceManager::loadResources() {
    SPACE_TEXTURE = Texture::load("../res/texture.jpg");
    STARS_TEXTURE = Texture::load("../res/texture2.jpg");
    SQUARE_MODEL = new Model(Buffer::load("../res/square_model.txt"));
    TRIANGLE_MODEL = new Model(Buffer::load("../res/triangle_model.txt"));
}

Model *ResourceManager::SQUARE_MODEL = nullptr;
Model *ResourceManager::TRIANGLE_MODEL = nullptr;
Texture *ResourceManager::SPACE_TEXTURE = nullptr;
Texture *ResourceManager::STARS_TEXTURE = nullptr;