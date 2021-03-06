#include "transform.h"

maths::mat4 Transform::to_matrix()
{
	maths::mat4 translationMatrix = maths::mat4::translate(m_pos.m_x, m_pos.m_y, m_pos.m_z);
	maths::mat4 rotationMatrix = m_rot.to_matrix();
	maths::mat4 scaleMatrix = maths::mat4::scale(m_scale.m_x, m_scale.m_y, m_scale.m_z);
	maths::mat4 parentMatrix = maths::mat4::identity();

	maths::mat4 transformationMatrix = parentMatrix.mul(translationMatrix.mul(rotationMatrix.mul(scaleMatrix)));

	return (transformationMatrix);
};

void Transform::rotate(maths::vec3 axis, float angle)
{
	m_rot = maths::quat(axis, TO_RADIANS(angle)).mul(m_rot).normalize();
};

void Transform::translate(maths::vec3 axis, float speed)
{
	m_pos.add(axis.mul(speed));
};
