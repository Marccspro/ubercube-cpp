#version 330

layout (location = 0) in vec3 in_position;

uniform mat4 projectionMatrix;
uniform mat4 modelViewMatrix;

out vec3 v_position;

void main(void)
{
	v_position = in_position;
	gl_Position = projectionMatrix * modelViewMatrix * vec4(in_position, 1.0);
}
