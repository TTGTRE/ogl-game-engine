//
// Created by Tre on 6/20/2020.
//

#include <SOIL2.h>
#include "TextureUtils.h"

GLuint TextureUtils::loadTexture(char const *texImagePath) {
    GLuint textureID;
    textureID = SOIL_load_OGL_texture(texImagePath, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
    return textureID;
}

