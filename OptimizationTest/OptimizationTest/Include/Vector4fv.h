#pragma once

#include "MacroHelper.h"
#include <xmmintrin.h>
#include <iostream>

struct Vector4fv
{
	__m128 _value;

	FORCE_INLINE explicit Vector4fv();
	FORCE_INLINE explicit Vector4fv(__m128 value) : _value(value) {}
	FORCE_INLINE explicit Vector4fv(const float x, const float y, const float z, const float w);
	

	FORCE_INLINE float __vectorcall x() const;
	FORCE_INLINE float __vectorcall y() const;
	FORCE_INLINE float __vectorcall z() const;
	FORCE_INLINE float __vectorcall w() const;
	

	void __vectorcall SetX(float x);
	void __vectorcall SetY(float y);
	void __vectorcall SetZ(float z);
	void __vectorcall SetW(float w);
	
	FORCE_INLINE static float __vectorcall Dot(Vector4fv leftVector, Vector4fv rightVector);
};

FORCE_INLINE Vector4fv __vectorcall operator +(Vector4fv lVec3, Vector4fv rVec3);
FORCE_INLINE Vector4fv __vectorcall operator -(Vector4fv lVec3, Vector4fv rVec3);
std::ostream&   operator <<(std::ostream& os, const Vector4fv& rVec3);

#include "Vector4fv.inl"