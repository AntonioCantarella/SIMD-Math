#define PI 3.14159265f

#include <cmath>

#include "MathGeneric.h"
#include "Vector3f.h"
#include "Matrix4.h"
//#include "../Include/Quaternion.h"

//#include "../../../Thirdparty/UnitTestOnly/glm/glm/glm.hpp"
//#include "../../../Thirdparty/UnitTestOnly/glm/glm/gtc/matrix_transform.inl"


namespace math
{
	float DegToRad(const float& degreeAngle)
	{
		return (degreeAngle * PI) / 180.f;
	}

	float RadToDeg(const float& radiansAngle)
	{
		return (radiansAngle * 180.f) / PI;
	}

	Vector3f DegToRad(const Vector3f& degreeAngle)
	{
		return Vector3f(DegToRad(degreeAngle._x), DegToRad(degreeAngle._y), DegToRad(degreeAngle._z));
	}

	Vector3f RadToDeg(const Vector3f& radiansAngle)
	{
		return Vector3f(RadToDeg(radiansAngle._x), RadToDeg(radiansAngle._y), RadToDeg(radiansAngle._z));
	}

	bool ApproximatelyEqual(const float& a, const float& b, const float epsilon)
	{
		return fabs(a - b) < epsilon;
	}

	bool ApproximatelyEqual(const Vector3f& vecA, const Vector3f& vecB, const float epsilon)
	{
		if (ApproximatelyEqual(vecA._x, vecB._x, epsilon) && ApproximatelyEqual(vecA._y, vecB._y, epsilon) && ApproximatelyEqual(vecA._z, vecB._z, epsilon))
			return true;

		return false;
	}

	Matrix4 FPSViewRH(const float posX, const float posY, const float posZ, const float xRotDegAngle, const float yRotDegAngle)
	{
		float cos_yaw = cos(DegToRad(yRotDegAngle));
		float sin_yaw = sin(DegToRad(yRotDegAngle));
		float cos_pitch = cos(DegToRad(xRotDegAngle));
		float sin_pitch = sin(DegToRad(xRotDegAngle));
		Vector3f cam_pos = Vector3f(posX, posY, posZ);

		Vector3f cam_x_axe = Vector3f(cos_yaw, 0.f, -sin_yaw);
		Vector3f cam_y_axe = Vector3f(sin_yaw * sin_pitch, cos_pitch, cos_yaw * sin_pitch);
		Vector3f cam_z_axe = Vector3f(sin_yaw * cos_pitch, -sin_pitch, cos_pitch * cos_yaw);

		return
		{
			cam_x_axe._x,						cam_y_axe._x,						cam_z_axe._x,						0.f,
			cam_x_axe._y,						cam_y_axe._y,						cam_z_axe._y,						0.f,
			cam_x_axe._z,						cam_y_axe._z,						cam_z_axe._z,						0.f,
			-Vector3f::Dot(cam_x_axe, cam_pos),	-Vector3f::Dot(cam_y_axe, cam_pos),	-Vector3f::Dot(cam_z_axe, cam_pos),	1.f
		};
	}

	Matrix4 FPSViewRH(const Vector3f camPos, const float xRotDegAngle, const float yRotDegAngle)
	{
		float cos_yaw = cos(DegToRad(yRotDegAngle));
		float sin_yaw = sin(DegToRad(yRotDegAngle));
		float cos_pitch = cos(DegToRad(xRotDegAngle));
		float sin_pitch = sin(DegToRad(xRotDegAngle));

		Vector3f cam_x_axe = Vector3f(cos_yaw, 0.f, -sin_yaw);
		Vector3f cam_y_axe = Vector3f(sin_yaw * sin_pitch, cos_pitch, cos_yaw * sin_pitch);
		Vector3f cam_z_axe = Vector3f(sin_yaw * cos_pitch, -sin_pitch, cos_pitch * cos_yaw);

		return
		{
			cam_x_axe._x,						cam_y_axe._x,						cam_z_axe._x,						0.f,
			cam_x_axe._y,						cam_y_axe._y,						cam_z_axe._y,						0.f,
			cam_x_axe._z,						cam_y_axe._z,						cam_z_axe._z,						0.f,
			-Vector3f::Dot(cam_x_axe, camPos),	-Vector3f::Dot(cam_y_axe, camPos),	-Vector3f::Dot(cam_z_axe, camPos),	1.f
		};
	}

	/*Matrix4	LookAtRH(const Vector3f eye, Vector3f target, Vector3f up)
	{
		Vector3f dir = (eye - target).Normalize();
		Vector3f rAxis = (up * dir).Normalize();
		Vector3f upAxis = (dir * rAxis);

		Matrix4 m1	{
						rAxis._x,		rAxis._y,		rAxis._z,		0.f,
						upAxis._x,		upAxis._y,		upAxis._z,		0.f,
						dir._x,			dir._y,			dir._z,			0.f,
						0.f,			0.f,			0.f,			1.f
					};

		Matrix4 m2
		{
			1.f,		0.f,		0.f,		-eye._x,
			0.f,		1.f,		0.f,		-eye._y,
			0.f,		0.f,		1.f,		-eye._z,
			0.f,		0.f,		0.f,		1.f
		};

		Matrix4 res_auto = (m1 * m2).Transpose();

		return res_auto;
	}*/

}//namespace math