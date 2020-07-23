//
// Created by Tre on 7/22/2020.
//

#include <SOIL2.h>
#include <iostream>
#include "Texture.h"

Texture::Texture(GLuint id) : id(id) {

}

GLuint Texture::getId() const {
    return id;
}

Texture *Texture::load(String path) {
    GLuint id = SOIL_load_OGL_texture(
            path,
            SOIL_LOAD_AUTO,
            SOIL_CREATE_NEW_ID,
            SOIL_FLAG_INVERT_Y
    );
    if (id == 0) std::cout << "Could not find texture " << path << std::endl;
    return new Texture(id);
}