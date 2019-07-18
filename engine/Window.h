//
// Created by Tre on 7/17/2019.
//

#ifndef OGLEXPERIMENTS_WINDOW_H
#define OGLEXPERIMENTS_WINDOW_H


#include "Graphics.h"

class Window {

    GLFWwindow *window;
    const char *title;
    int width, height;
    Graphics *graphics;

public:
    Window(const char *title, int width, int height);

    void destroy();

    bool exists();

    const char *getTitle();

    int getWidth();

    int getHeight();

    Graphics *getGraphics();
};


#endif //OGLEXPERIMENTS_WINDOW_H
