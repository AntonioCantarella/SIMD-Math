#pragma once

#include "ITestable.h"
#include "Matrix4fv.h"

class SseMatrixTest : ITestable
{
public:
	void Prepare() override
	{

	}

	void Execute() override
	{
		Matrix4fv m1 = Matrix4fv(Vector4fv(1.f, 2.f, 3.f, 4.f),
			Vector4fv(1.f, 2.f, 3.f, 4.f), 
			Vector4fv(1.f, 2.f, 3.f, 4.f), 
			Vector4fv(1.f, 2.f, 3.f, 4.f));

		Matrix4fv m2 = Matrix4fv(Vector4fv(1.f, 2.f, 3.f, 4.f),
			Vector4fv(1.f, 2.f, 3.f, 4.f),
			Vector4fv(1.f, 2.f, 3.f, 4.f),
			Vector4fv(1.f, 2.f, 3.f, 4.f));

		for (size_t i = 0; i < 2000; ++i)
			m1 * m2;
										 //std::cout << "Vector3fv res = " << res << std::endl;
	}

	void Finalize() override
	{

	}
};
