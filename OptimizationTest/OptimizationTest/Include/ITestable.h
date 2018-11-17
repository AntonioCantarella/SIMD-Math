#pragma once

class ITestable
{
public:
	virtual ~ITestable() = default;

	virtual void Prepare() = 0;
	virtual void Execute() = 0;
	virtual void Finalize() = 0;

	static const int count = 20000;
	static const int array_size = 100'000;
};
