#pragma once
#include "ITestable.h"
#include "Vector3f.h"

class NonSSEVectorTest : ITestable
{
public:
	void Prepare() override
	{

	}

	void Execute() override
	{
		math::Vector3f v(12.f, 36.f, 85.f);
		math::Vector3f f(12.f, 36.f, 85.f);
		float res;

		for (size_t i = 0; i < 200'000; ++i)
			res = math::Vector3f::Dot(v, f); 
		
	}

	void Finalize() override
	{

	}
};
