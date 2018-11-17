#ifndef __VECTOR3f_H_INCLUDED__
#define __VECTOR3f_H_INCLUDED__

#include <iostream>

namespace math
{
	struct Vector3f
	{
		float _x, _y, _z;

		Vector3f();
		Vector3f(const float x, const float y, const float z);
		Vector3f(const Vector3f&) = default;
		~Vector3f() = default;

		Vector3f    operator =(const Vector3f& rVec3);
		Vector3f    operator +=(const Vector3f& rVec3);
		Vector3f    operator -=(const Vector3f& rVec3);

		__forceinline static float	Dot(const Vector3f& leftVector, const Vector3f& rightVector)
		{
			return ((leftVector._x * rightVector._x) + (leftVector._y * rightVector._y) + (leftVector._z * rightVector._z));
		}
	};

	__forceinline Vector3f	operator +(const Vector3f& lVec3, const Vector3f& rVec3)
	{
		Vector3f res = Vector3f();

		res._x = lVec3._x + rVec3._x;
		res._y = lVec3._y + rVec3._y;
		res._z = lVec3._z + rVec3._z;

		return res;
	}
	Vector3f		operator -(const Vector3f& lVec3, const Vector3f& rVec3);
	std::ostream&   operator <<(std::ostream& os, const Vector3f& rVec3);

} // namespace math

#endif //__VECTOR3f_H_INCLUDED__
