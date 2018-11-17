#pragma once

#include "MacroHelper.h"
#include "Vector4fv.h"
#include <xmmintrin.h>

struct Matrix4fv
{
	Vector4fv _value[4];

	FORCE_INLINE Matrix4fv();
	FORCE_INLINE Matrix4fv(Vector4fv row1, Vector4fv row2, Vector4fv row3, Vector4fv row4);
	
	FORCE_INLINE Matrix4fv __vectorcall Transpose() const;
};

FORCE_INLINE Matrix4fv	__vectorcall operator *(const Matrix4fv lMat4, const Matrix4fv rMat4);

#include "Matrix4fv.inl"