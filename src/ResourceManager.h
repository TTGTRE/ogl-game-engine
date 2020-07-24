//
// Created by Tre on 7/22/2020.
//

#ifndef OGLEXPERIMENTS_RESOURCEMANAGER_H
#define OGLEXPERIMENTS_RESOURCEMANAGER_H


#include "engine/buffer/Buffer.h"
#include "engine/texture/Texture.h"
#include "engine/model/Model.h"

class ResourceManager {
public:
    static void loadResources();
    static Model *SQUARE_MODEL;
    static Model *TRIANGLE_MODEL;
    static Texture *SPACE_TEXTURE;
    static Texture *STARS_TEXTURE;
};


#endif //OGLEXPERIMENTS_RESOURCEMANAGER_H
