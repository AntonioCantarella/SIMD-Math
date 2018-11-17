#pragma once
#include "ITestable.h"
#include "Utilities.h"

class VectorizedArrayTest : ITestable
{
public:
	void Prepare() override
	{
		a = CreateArray(array_size, 1.f);
		b = CreateArray(array_size, 2.f);
		c = CreateArray(array_size, 3.f);
	}

	void Execute() override
	{
		const int size = array_size;
		__pragma(loop(hint_parallel(8)))
		__pragma(loop(ivdep))
		for (int i = 0; i < size; ++i)
		{
			a[i] = b[i] * c[i];
		}
	}

	void Finalize() override
	{
		delete a;
		delete b;
		delete c;
	}

private:
	float* a = nullptr;
	float* b = nullptr;
	float* c = nullptr;
};
