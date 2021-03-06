#ifndef SHADER_H
# define SHADER_H

# include "gl_utils.h"
# include "maths.h"

using namespace maths;

class Shader
{
private:
	GLuint	m_program;

	GLuint	create_program(const char *vertex_source, const char *fragment_source);
	GLuint	create_shader(const char *source, int shader);

	GLuint 	getUniformLocation(char *name);

public:
	Shader(const char *vertex_path, const char *fragment_path);
	~Shader();

	void 	setUniform(char *name, GLint v);
	void 	setUniform(char *name, GLfloat v);
	void 	setUniform(char *name, vec3 v);
	void 	setUniform(char *name, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
	void 	setUniform(char *name, mat4 v);

	inline void bind() { glUseProgram(m_program); };
	inline void unbind() { glUseProgram(0); };

	inline int get_program() { return (m_program); }
};

#endif
