#ifndef __MATRIX4_H_INCLUDED__
#define __MATRIX4_H_INCLUDED__

#include <iostream>

namespace math
{
	struct Vector3f;

	struct Matrix4
	{
		Matrix4();
		Matrix4(float* mat4);
		Matrix4(const float value0, const float value1, const float value2, const float value3, const float value4, const float value5, const float value6, const float value7, const float value8, const float value9, const float value10, const float value11, const float value12, const float value13, const float value14, const float value15);
		~Matrix4() = default;

		Matrix4				operator =(const Matrix4& rMat4);
		Matrix4				operator *=(const Matrix4& rMat4);
		float&				operator [](uint8_t pos);
		const float&		operator [](uint8_t pos) const;

		Matrix4 InverseSample(); // Do not use
		Matrix4 Transpose() const;

		static Matrix4 Transpose(Matrix4 mat4);
		static Matrix4 Translate(const float x, const float y, const float z);
		static Matrix4 Translate(const Vector3f pos);
		static Matrix4 Scale(const float x, const float y, const float z);
		static Matrix4 Scale(const Vector3f size);
		static Matrix4 RotateX(const float angle);
		static Matrix4 RotateY(const float angle);
		static Matrix4 RotateZ(const float angle);
		static Matrix4 Perspective(const float degFov, const int windowWidth, const int windowHeight, const float near, const float far);
		static Matrix4 Orthographic(float left, float right, float top, float bottom, float near, float far);
		//static Matrix4 FPSViewRH(const float posX, const float posY, const float posZ, const float xRotDegAngle, const float yRotDegAngle);
		//static Matrix4 FPSViewRH(const Vector3f camPos, const float xRotDegAngle, const float yRotDegAngle);

		const static Matrix4 _identity;

		float _value[16];

	private:
		void CheckIfIndexIsOutOfRange(size_t idx, const char* msg) const;
	};

    bool			    operator ==(const Matrix4& lMat4, const Matrix4& rMat4);
	bool			    operator !=(const Matrix4& lMat4, const Matrix4& rMat4);
	__forceinline Matrix4			operator *(const Matrix4& lMat4, const Matrix4& rMat4)
	{
		Matrix4 mat4 = Matrix4();

		for (unsigned int i = 0; i < 4; ++i)
			for (unsigned int j = 0; j < 4; ++j)
				for (unsigned int k = 0; k < 4; ++k)
					mat4[(4 * i) + j] += lMat4[(4 * i) + k] * rMat4[(4 * k) + j];


		return mat4;
	}
	std::ostream&    operator <<(std::ostream& os, const Matrix4& mat4);
}//namespace math

#endif // !__MATRIX4_H_INCLUDED__