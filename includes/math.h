#ifndef MATH_H
# define MATH_H

namespace math
{
    class vec3
    {
    public:
        float x;
        float y;
        float z;

		vec3();
		vec3(float x, float y, float z);
		vec3(vec3 vec);

		~vec3();
    }

    class mat4
    {
    public:
        float m[4 * 4];

		mat4();
		~mat4();

		mat4 identity();

		mat4 translate(vec3 pos);
		mat4 rotate(float angle, float x, float y, float z);
		mat4 scale(vec3 scale);

		mat4 perpective(float fov, float aspect, float near, float far);

		mat4 mul(mat4 m);
    }

    class quat
    {
    public:
        float x;
        float y;
        float z;
        float w;

		quat();
		~quat();

		mat4 to_matrix();
		quat mul(quat q);
    }
}

#endif
