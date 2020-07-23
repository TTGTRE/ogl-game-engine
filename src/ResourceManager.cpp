//
// Created by Tre on 7/22/2020.
//

#include "ResourceManager.h"

void ResourceManager::loadResources() {
    SPACE_TEXTURE = Texture::load("../res/texture.jpg");
    STARS_TEXTURE = Texture::load("../res/texture2.jpg");
    SQUARE_TEX_COORDS = Buffer::load("../res/square_tex_coords.txt");
    TRIANGLE_TEX_COORDS = Buffer::load("../res/triangle_tex_coords.txt");
    SQUARE_MODEL = new Model(Buffer::load("../res/square_model.txt"), SQUARE_TEX_COORDS, SPACE_TEXTURE);
    TRIANGLE_MODEL = new Model(Buffer::load("../res/triangle_model.txt"), TRIANGLE_TEX_COORDS, STARS_TEXTURE);
}

Model *ResourceManager::SQUARE_MODEL = nullptr;
Model *ResourceManager::TRIANGLE_MODEL = nullptr;
Buffer *ResourceManager::SQUARE_TEX_COORDS = nullptr;
Buffer *ResourceManager::TRIANGLE_TEX_COORDS = nullptr;
Texture *ResourceManager::SPACE_TEXTURE = nullptr;
Texture *ResourceManager::STARS_TEXTURE = nullptr;