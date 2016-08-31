#include <iostream>
#include <GLFW/glfw3.h>
#include "display.h"

int     main(int argc, char **argv)
{
    Display *display = new Display("ubercube", 1280, 720);

    while (!display->is_closed())
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



        if (display->was_resized())
            glViewport(0, 0, display->get_width(), display->get_height());
        display->update();
    }

    delete display;
    return (0);
}
