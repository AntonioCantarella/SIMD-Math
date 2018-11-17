#pragma once
#include <emmintrin.h>
#include "ITestable.h"

class VectorTest : ITestable
{
public:

	void SetX(const float _x)
	{
		m = _mm_move_ss(m, _mm_set_ss(_x));
	}

	void SetY(const float _y)
	{
		__m128 t = _mm_move_ss(m, _mm_set_ss(_y));
		t = _mm_shuffle_ps(t, t, _MM_SHUFFLE(3, 2, 0, 0));
		m = _mm_move_ss(t, m);

	}

	void SetZ(const float _z)
	{
		__m128 t = _mm_move_ss(m, _mm_set_ss(_z));
		t = _mm_shuffle_ps(t, t, _MM_SHUFFLE(3, 0, 1, 0));
		m = _mm_move_ss(t, m);

	}

	void Prepare() override
	{

	}

	void Execute() override
	{
		SetX(12.f);
		SetY(12.f);
		SetZ(12.f);
	}

	void Finalize() override
	{

	}

	__m128 m;
};
