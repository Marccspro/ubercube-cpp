#include <GL/glew.h>
#include "display.h"
#include "shader.h"
#include "maths.h"
#include "game/game.h"

int     main(int argc, char **argv)
{
    Display *display = new Display("ubercube", 1280, 720);
	Shader *shader = new Shader("shaders/main.vert", "shaders/main.frag");
	Game *game = new Game();

    while (!display->is_closed())
    {
		game->update();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		shader->bind();
		shader->setUniform((char*)"projectionMatrix", maths::mat4::perspective(70.0f, (float)display->get_width() / (float)display->get_height(), 0.1f, 1000.0f));

		game->render(shader);
		game->render_gui(shader);

		if (display->was_resized())
            glViewport(0, 0, display->get_width(), display->get_height());
        display->update();
    }

    delete display;
    delete shader;
    delete game;

    return (0);
}
