//
// Created by Tre on 7/14/2019.
//

#ifndef OGLEXPERIMENTS_DRAWHANDLE_H
#define OGLEXPERIMENTS_DRAWHANDLE_H


#include <vector>
#include "Model.h"
#include "ShaderHandle.h"

namespace Engine {

    class DrawHandle {

        int width, height;

    public:

        DrawHandle(int width, int height) : width(width), height(height) {}

        DrawHandle() = default;

        void setResolution(int width, int height);

        void draw();
    };
}


#endif //OGLEXPERIMENTS_DRAWHANDLE_H
