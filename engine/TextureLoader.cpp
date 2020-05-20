//
// Created by Tre on 7/28/2019.
//

#include <glew.h>
#include <SOIL2.h>
#include <iostream>
#include "Texture.h"

namespace TextureLoader {

    Texture *loadTexture(const char *texturePath, int textureUnit) {

        GLuint textureObj = SOIL_load_OGL_texture(texturePath, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
        if (textureObj == 0) std::cout << "Failed to load texture." << std::endl;
        std::cout << "Loaded texture " << texturePath << std::endl;

        return new Texture(textureUnit, textureObj);
    }
}
