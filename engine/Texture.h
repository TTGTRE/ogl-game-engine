//
// Created by Tre on 7/28/2019.
//

#ifndef OGLEXPERIMENTS_TEXTURE_H
#define OGLEXPERIMENTS_TEXTURE_H


class Texture {

    int textureUnit;
    GLuint textureObj;

public:
    Texture(int textureUnit, GLuint textureObj);

    int getTextureUnit();

    GLuint getTextureObject();
};


#endif //OGLEXPERIMENTS_TEXTURE_H
