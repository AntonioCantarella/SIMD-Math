#pragma once
#include "ITestable.h"
#include "Vector3fv.h"

class SseVectorTest : ITestable
{
public:
	void Prepare() override
	{

	}

	void Execute() override
	{
		Vector3fv v(12.f, 36.f, 85.f);
		Vector3fv f(12.f, 36.f, 85.f);
		float res;

		for (size_t i = 0; i < 200'000; ++i)
			res = Vector3fv::DotV2(v, f);//v + f;
		
		//std::cout << "Vector3fv res = " << res << std::endl;
	}

	void Finalize() override
	{

	}
};
