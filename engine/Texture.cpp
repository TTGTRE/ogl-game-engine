//
// Created by Tre on 7/28/2019.
//

#include <glew.h>
#include "Texture.h"

Texture::Texture(int textureUnit, GLuint textureObj) : textureUnit(textureUnit), textureObj(textureObj) {

}

int Texture::getTextureUnit() {
    return textureUnit;
}

GLuint Texture::getTextureObject() {
    return textureObj;
}