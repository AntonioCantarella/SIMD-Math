#include "Matrix4.h"
#include "Vector3f.h"
#include "MathGeneric.h"

#include <stdexcept>

namespace math
{
	Matrix4::Matrix4()
	{
		//*this = Matrix4::identity;

		for (unsigned int i = 0; i < 16; ++i)
			_value[i] = 0.f;
	}

	Matrix4::Matrix4(float* mat4)
	{
		for (unsigned int i = 0; i < 16; ++i)
			_value[i] = mat4[i];
	}

	Matrix4::Matrix4(const float value0, const float value1, const float value2, const float value3, const float value4, const float value5, const float value6, const float value7, const float value8, const float value9, const float value10, const float value11, const float value12, const float value13, const float value14, const float value15)
	{
		_value[0] = value0;
		_value[1] = value1;
		_value[2] = value2;
		_value[3] = value3;
		_value[4] = value4;
		_value[5] = value5;
		_value[6] = value6;
		_value[7] = value7;
		_value[8] = value8;
		_value[9] = value9;
		_value[10] = value10;
		_value[11] = value11;
		_value[12] = value12;
		_value[13] = value13;
		_value[14] = value14;
		_value[15] = value15;
	}

	const Matrix4 Matrix4::_identity =
	{
		1.f, 0.f, 0.f, 0.f,
		0.f, 1.f, 0.f, 0.f,
		0.f, 0.f, 1.f, 0.f,
		0.f, 0.f, 0.f, 1.f
	};

	Matrix4 Matrix4::operator =(const Matrix4& rMat4)
	{
		for (unsigned int i = 0; i < 16; ++i)
		{
			_value[i] = rMat4._value[i];
		}

		return *this;
	}

	bool operator==(const Matrix4& lMat4, const Matrix4& rMat4)
	{
		for (unsigned int i = 0; i < 16; ++i)
				if (!ApproximatelyEqual(lMat4[i], rMat4[i], 0.001f))
					return false;

		return true;
	}

	bool operator!=(const Matrix4& lMat4, const Matrix4& rMat4)
	{
		return !(lMat4 == rMat4);
	}

	/*Matrix4 operator *(const Matrix4& lMat4, const Matrix4& rMat4)
	{
		Matrix4 mat4 = Matrix4();

		for (unsigned int i = 0; i < 4; ++i)
			for (unsigned int j = 0; j < 4; ++j)
				for (unsigned int k = 0; k < 4; ++k)
					mat4[(4 * i) + j] += lMat4[(4 * i) + k] * rMat4[(4 * k) + j];
		
		
		return mat4;
	}*/

	Matrix4 Matrix4::operator *=(const Matrix4& rMat4)
	{
		*this = *this * rMat4;// *(*this);
		return *this;
	}

	float& Matrix4::operator[](uint8_t pos)
	{
		CheckIfIndexIsOutOfRange(pos, "Matrix4::operator[] Error: the given index is > 15.");
		return _value[pos];
	}

	const float& Matrix4::operator[](uint8_t pos) const
	{
		CheckIfIndexIsOutOfRange(pos, "Matrix4::operator[] Error: the given index is > 15.");
		return _value[pos];
	}

	std::ostream&   operator <<(std::ostream& os, const Matrix4& mat4)
	{
		os << " | " << mat4._value[0] << "    " << mat4._value[1] << "    " << mat4._value[2] << "    " << mat4._value[3] << " | " << std::endl;
		os << " | " << mat4._value[4] << "    " << mat4._value[5] << "    " << mat4._value[6] << "    " << mat4._value[7] << " | " << std::endl;
		os << " | " << mat4._value[8] << "    " << mat4._value[9] << "    " << mat4._value[10] << "    " << mat4._value[11] << " | " << std::endl;
		os << " | " << mat4._value[12] << "    " << mat4._value[13] << "    " << mat4._value[14] << "    " << mat4._value[15] << " | " << std::endl;

		return os;
	}

	Matrix4 Matrix4::InverseSample()
	{
		Matrix4 mat4 = *this;

		for (unsigned int i = 12; i < 15; ++i)
			mat4._value[i] *= -1;

		std::swap(mat4._value[1], mat4._value[4]);
		std::swap(mat4._value[2], mat4._value[8]);
		std::swap(mat4._value[6], mat4._value[9]);

		return mat4;
	}

	Matrix4 Matrix4::Transpose() const
	{
		Matrix4 mat4 = *this;

		std::swap(mat4._value[1], mat4._value[4]);
		std::swap(mat4._value[2], mat4._value[8]);
		std::swap(mat4._value[3], mat4._value[12]);
		std::swap(mat4._value[6], mat4._value[9]);
		std::swap(mat4._value[7], mat4._value[13]);
		std::swap(mat4._value[11], mat4._value[14]);

		return mat4;
	}

	Matrix4 Matrix4::Transpose(Matrix4 mat4)
	{
		std::swap(mat4._value[1], mat4._value[4]);
		std::swap(mat4._value[2], mat4._value[8]);
		std::swap(mat4._value[3], mat4._value[12]);
		std::swap(mat4._value[6], mat4._value[9]);
		std::swap(mat4._value[7], mat4._value[13]);
		std::swap(mat4._value[11], mat4._value[14]);

		return mat4;
	}

	Matrix4 Matrix4::Translate(const float x, const float y, const float z)
	{
		return
		{
			1.f,	0.f,	0.f,	0.f,
			0.f,	1.f,	0.f,	0.f,
			0.f,	0.f,	1.f,	0.f,
			x,		y,		z,		1.f
		};
	}

	Matrix4 Matrix4::Translate(const Vector3f pos)
	{
		return
		{
			1.f,	0.f,	0.f,	0.f,
			0.f,	1.f,	0.f,	0.f,
			0.f,	0.f,	1.f,	0.f,
			pos._x, pos._y, pos._z, 1.f
		};
	}

	Matrix4 Matrix4::Scale(const float x, const float y, const float z)
	{
		return
		{
			x,		0.f,	0.f,	0.f,
			0.f,	y,		0.f,	0.f,
			0.f,	0.f,	z,		0.f,
			0.f,	0.f,	0.f,	1.f
		};
	}

	Matrix4 Matrix4::Scale(const Vector3f size)
	{
		return
		{
			size._x,	0.f,		0.f,		0.f,
			0.f,		size._y,	0.f,		0.f,
			0.f,		0.f,		size._z,	0.f,
			0.f,		0.f,		0.f,		1.f
		};
	}

	Matrix4 Matrix4::RotateX(const float angle)
	{
		float rad_angle = DegToRad(angle);

		return
		{
			1.f,		0.f,						0.f,						0.f,
			0.f,		std::cos(rad_angle),		(std::sin(rad_angle)),		0.f,
			0.f,		-std::sin(rad_angle),		std::cos(rad_angle),		0.f,
			0.f,		0.f,						0.f,						1.f
		};
	}

	Matrix4 Matrix4::RotateY(const float angle)
	{
		float rad_angle = DegToRad(angle);

		return
		{
			std::cos(rad_angle),	0.f,		-std::sin(rad_angle),		0.f,
			0.f,					1.f,		0.f,						0.f,
			std::sin(rad_angle),	0.f,		std::cos(rad_angle),		0.f,
			0.f,					0.f,		0.f,						1.f
		};
	}

	Matrix4 Matrix4::RotateZ(const float angle)
	{
		float rad_angle = DegToRad(angle);

		return
		{
			std::cos(rad_angle),	std::sin(rad_angle),	0.f,	0.f,
			-std::sin(rad_angle),	std::cos(rad_angle),	0.f,	0.f,
			0.f,					0.f,					1.f,	0.f,
			0.f,					0.f,					0.f,	1.f
		};
	}

	Matrix4 Matrix4::Perspective(const float degFov, const int windowWidth, const int windowHeight, const float near, const float far)
	{
		float aspect_ratio = static_cast<float>(windowWidth) / static_cast<float>(windowHeight);
		float rad_fov = DegToRad(degFov);
		float focal_distance = 1.f / std::tan(rad_fov / 2.f);
		float NDC_normalization = 1.f / (near - far);

		return
		{
			(focal_distance / aspect_ratio),		0.f,					0.f,										0.f,
			0.f,									focal_distance,			0.f,										0.f,
			0.f,									0.f,					(near + far) * NDC_normalization,			-1.f,
			0.f,									0.f,					(near * far * 2.f) * NDC_normalization,		0.f
		};
	}

	Matrix4 Matrix4::Orthographic(float left, float right, float top, float bottom, float near, float far)
	{
		return
		{
			(2.0f / (right - left)),	0.0f,						0.0f,						-(right + left) / (right - left),
			0.0f,						(2.0f / (top - bottom)),	0.0f,						-(top + bottom) / (top - bottom),
			0.0f,						0.0f,						(-2.0f / (far - near)),		-(far + near) / (far - near),
			0.0f,						0.0f,						0.0f,						1.0f
		};
	}
	
	void Matrix4::CheckIfIndexIsOutOfRange(size_t idx, const char* msg) const
	{
		if (idx > 15)
			throw std::out_of_range(msg);
	}

}//namespace math