#pragma once

#include "ITestable.h"
#include "Matrix4.h"

class NonSSEMatrixTest : ITestable
{
public:
	void Prepare() override
	{

	}

	void Execute() override
	{
		math::Matrix4 m1 = math::Matrix4::_identity; 

		math::Matrix4 m2 = math::Matrix4::_identity;

		for (size_t i = 0; i < 2000; ++i)
			m1 * m2;
	}

	void Finalize() override
	{

	}
};
