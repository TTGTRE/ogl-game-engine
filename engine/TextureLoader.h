//
// Created by Tre on 7/28/2019.
//

#ifndef OGLEXPERIMENTS_TEXTURELOADER_H
#define OGLEXPERIMENTS_TEXTURELOADER_H

#include "Texture.h"

namespace TextureLoader {

    Texture *loadTexture(const char *texturePath, int textureUnit);
}

#endif //OGLEXPERIMENTS_TEXTURELOADER_H
