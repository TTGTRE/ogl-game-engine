//
// Created by Tre on 7/22/2020.
//

#ifndef OGLEXPERIMENTS_TEXTURE_H
#define OGLEXPERIMENTS_TEXTURE_H


#include "../Types.h"

class Texture {
    GLuint id;
public:
    explicit Texture(GLuint id);
    GLuint getId() const;

    static Texture *load(std::string const &path);
};


#endif //OGLEXPERIMENTS_TEXTURE_H
