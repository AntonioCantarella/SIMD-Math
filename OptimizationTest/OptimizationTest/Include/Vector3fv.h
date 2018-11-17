#pragma once

#include "MacroHelper.h"
#include <xmmintrin.h>

struct Vector3fv
{
	__m128 _value;

	FORCE_INLINE explicit Vector3fv();
	FORCE_INLINE explicit Vector3fv(__m128 value) : _value(value) {}
	FORCE_INLINE explicit Vector3fv(const float x, const float y, const float z);

	FORCE_INLINE float __vectorcall x() const;
	FORCE_INLINE float __vectorcall y() const;
	FORCE_INLINE float __vectorcall z() const;
	

	void __vectorcall SetX(float x);
	void __vectorcall SetY(float y);
	void __vectorcall SetZ(float z);
	

	FORCE_INLINE static float __vectorcall Dot(Vector3fv leftVector, Vector3fv rightVector);
	FORCE_INLINE static float __vectorcall DotV2(Vector3fv leftVector, Vector3fv rightVector);
	
};

FORCE_INLINE Vector3fv __vectorcall operator +(Vector3fv lVec3, Vector3fv rVec3);
FORCE_INLINE Vector3fv __vectorcall operator -(Vector3fv lVec3, Vector3fv rVec3);
std::ostream&   operator <<(std::ostream& os, const Vector3fv& rVec3);

#include "Vector3fv.inl"