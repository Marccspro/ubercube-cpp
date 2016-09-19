#version 330

out vec4 out_color;

in vec3 v_position;

void main(void)
{
	out_color = vec4(normalize(v_position), 1);
}
