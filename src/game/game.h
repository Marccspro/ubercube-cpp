#ifndef GAME_H
# define GAME_H

# include "shader.h"

class Game
{
public:
	Game();
	~Game();

	void update();
	void render(Shader *shader);
	void render_gui(Shader *shader);
};

#endif
