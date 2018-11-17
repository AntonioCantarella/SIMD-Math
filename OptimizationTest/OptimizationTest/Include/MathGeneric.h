#ifndef __MATHGENERIC_H_INCLUDED__
#define __MATHGENERIC_H_INCLUDED__


namespace math
{
	struct Vector3f;
	struct Matrix4;
	class Quaternion;

	float		DegToRad(const float& degreeAngle);
	float		RadToDeg(const float& radiansAngle);
	Vector3f	DegToRad(const Vector3f& degreeAngle);
	Vector3f	RadToDeg(const Vector3f& radiansAngle);
	bool		ApproximatelyEqual(const float& a, const float& b, const float epsilon);
	bool		ApproximatelyEqual(const Vector3f& vecA, const Vector3f& vecB, const float epsilon);
	Matrix4		FPSViewRH(const float posX, const float posY, const float posZ, const float xRotDegAngle, const float yRotDegAngle);
	Matrix4		FPSViewRH(const Vector3f camPos, const float xRotDegAngle, const float yRotDegAngle);
	Matrix4		LookAtRH(const Vector3f eye, Vector3f target, Vector3f up);
}//namespace math

#endif // __MATHGENERIC_H_INCLUDED__