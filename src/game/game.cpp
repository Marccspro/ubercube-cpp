#include "game.h"
#include "maths.h"

GLuint vao, vbo, ibo;

Game::Game()
{
	maths::vec3 vertices[4];

	vertices[0] = maths::vec3(-5, -1, -5);
	vertices[1] = maths::vec3(5, -1, -5);
	vertices[2] = maths::vec3(5, -1, 5);
	vertices[3] = maths::vec3(-5, -1, 5);

	int indices[6];

	indices[0] = 0;
	indices[1] = 1;
	indices[2] = 2;

	indices[3] = 0;
	indices[4] = 2;
	indices[5] = 3;

	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ibo);

	glBindVertexArray(vao);

	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glBindVertexArray(0);
}

Game::~Game()
{

}

void Game::update()
{

}

void Game::render(Shader *shader)
{
	shader->setUniform((char*)"modelViewMatrix", maths::mat4::translate(0, 0, 0));

	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void Game::render_gui(Shader *shader)
{

}
