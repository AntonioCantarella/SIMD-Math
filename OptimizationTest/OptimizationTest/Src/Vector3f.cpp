#include "../Include/Vector3f.h"

namespace math
{
	Vector3f::Vector3f()
	{
		_x = 0.f;
		_y = 0.f;
		_z = 0.f;
	}

	Vector3f::Vector3f(const float x, const float y, const float z)
	{
		_x = x;
		_y = y;
		_z = z;
	}

	Vector3f Vector3f::operator =(const Vector3f& rVec3)
	{
		_x = rVec3._x;
		_y = rVec3._y;
		_z = rVec3._z;

		return *this;
	}

	/*Vector3f operator +(const Vector3f& lVec3, const Vector3f& rVec3)
	{
		Vector3f res = Vector3f();

		res._x = lVec3._x + rVec3._x;
		res._y = lVec3._y + rVec3._y;
		res._z = lVec3._z + rVec3._z;

		return res;
	}*/

	Vector3f Vector3f::operator +=(const Vector3f& rVec3)
	{
		_x += rVec3._x;
		_y += rVec3._y;
		_z += rVec3._z;

		return *this;
	}

	Vector3f operator -(const Vector3f& lVec3, const Vector3f& rVec3)
	{
		Vector3f res = Vector3f();

		res._x = lVec3._x - rVec3._x;
		res._y = lVec3._y - rVec3._y;
		res._z = lVec3._z - rVec3._z;

		return res;
	}

	Vector3f Vector3f::operator -=(const Vector3f& rVec3)
	{
		_x -= rVec3._x;
		_y -= rVec3._y;
		_z -= rVec3._z;

		return *this;
	}

	Vector3f operator *(const Vector3f& lVec3, const Vector3f& rVec3)
	{
		Vector3f res = Vector3f();

		res._x = (lVec3._y * rVec3._z) - (lVec3._z * rVec3._y);
		res._y = (lVec3._z * rVec3._x) - (lVec3._x * rVec3._z);
		res._z = (lVec3._x * rVec3._y) - (lVec3._y * rVec3._x);

		return res;
	}

	Vector3f operator *(const Vector3f& lVec3, const float& scalar)
	{
		Vector3f res = Vector3f();

		res._x = lVec3._x * scalar;
		res._y = lVec3._y * scalar;
		res._z = lVec3._z * scalar;

		return res;
	}

	std::ostream& operator <<(std::ostream& os, const Vector3f& rVec3)
	{
		os << "( " << rVec3._x << ", " << rVec3._y << ", " << rVec3._z << " )";

		return os;
	}

	/*float Vector3f::Dot(const Vector3f& leftVector, const Vector3f& rightVector)
	{
		return ((leftVector._x * rightVector._x) + (leftVector._y * rightVector._y) + (leftVector._z * rightVector._z));
	}*/

} //namespace math