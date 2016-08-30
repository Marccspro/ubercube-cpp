#include <iostream>
#include <GLFW/glfw3.h>
#include "display.h"

int     main(int argc, char **argv)
{
    Display *display = new Display("ubercube", 1280, 720);

    while (!display->isClosed())
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        

        if (display->wasResized())
            glViewport(0, 0, display->getWidth(), display->getHeight());
        display->update();
    }

    delete display;
    return (0);
}
