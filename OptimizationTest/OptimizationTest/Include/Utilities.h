#pragma once

inline float* CreateArray(const int _size, const float _default_value = 0.f)
{
	float* array = new float[_size] {};
	for (int i = 0; i < _size; ++i)
	{
		array[i] = _default_value;
	}
	return array;
}