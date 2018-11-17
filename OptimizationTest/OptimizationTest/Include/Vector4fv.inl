
Vector4fv::Vector4fv()
{
	_value = _mm_set_ps(0.f, 0.f, 0.f, 0.f);
}

Vector4fv::Vector4fv(const float x, const float y, const float z, const float w)
{
	_value = _mm_set_ps(w, z, y, x);
}

float Vector4fv::x() const
{
	return _mm_cvtss_f32(_value);
}

float Vector4fv::y() const
{
	return _mm_cvtss_f32(_mm_shuffle_ps(_value, _value, _MM_SHUFFLE(1, 1, 1, 1)));
}

float Vector4fv::z() const
{
	return _mm_cvtss_f32(_mm_shuffle_ps(_value, _value, _MM_SHUFFLE(2, 2, 2, 2)));
}

float Vector4fv::w() const
{
	return _mm_cvtss_f32(_mm_shuffle_ps(_value, _value, _MM_SHUFFLE(3, 3, 3, 3)));
}

void Vector4fv::SetX(float x)
{
	_value = _mm_move_ss(_value, _mm_set_ss(x));
}

void Vector4fv::SetY(float y)
{
	__m128 temp = _mm_move_ss(_value, _mm_set_ss(y));
	temp = _mm_shuffle_ps(temp, temp, _MM_SHUFFLE(3, 2, 0, 0));
	_value = _mm_move_ss(temp, _value);
}

void Vector4fv::SetZ(float z)
{
	__m128 temp = _mm_move_ss(_value, _mm_set_ss(z));
	temp = _mm_shuffle_ps(temp, temp, _MM_SHUFFLE(3, 0, 1, 0));
	_value = _mm_move_ss(temp, _value);
}

void Vector4fv::SetW(float w)
{
	__m128 temp = _mm_move_ss(_value, _mm_set_ss(w));
	temp = _mm_shuffle_ps(temp, temp, _MM_SHUFFLE(0, 2, 1, 0));
	_value = _mm_move_ss(temp, _value);
}

float Vector4fv::Dot(Vector4fv leftVector, Vector4fv rightVector)
{
	__m128 t0 = _mm_mul_ps(leftVector._value, rightVector._value);		//t0 = (ww, zz, yy, xx)
	__m128 t1 = _mm_shuffle_ps(t0, t0, _MM_SHUFFLE(1, 0, 3, 2));		//t1 = (yy, xx, ww, zz)
	__m128 t2 = _mm_add_ps(t0, t1);										//t2 = (yy+ww, xx+zz, yy+ww, xx+zz)
	__m128 t3 = _mm_shuffle_ps(t2, t2, _MM_SHUFFLE(2, 3, 0, 1));		//t3 = (xx+zz, yy+ww, xx+zz, yy+ww)
	__m128 t4 = _mm_add_ss(t3, t0);										//t4 = t3+t0(_mm_add_ss) (xx+zz, yy+zz, xx+zz, xx+yy+zz+ww)

	return _mm_cvtss_f32(t4);											//return _mm_cvtss_f32(t4)
}

Vector4fv __vectorcall operator +(Vector4fv lVec3, Vector4fv rVec3)
{
	return Vector4fv(_mm_add_ps(lVec3._value, rVec3._value));
}

Vector4fv __vectorcall operator -(Vector4fv lVec3, Vector4fv rVec3)
{
	return Vector4fv(_mm_sub_ps(lVec3._value, rVec3._value));
}

std::ostream& operator <<(std::ostream& os, const Vector4fv& rVec3)
{
	os << "( " << rVec3.x() << ", " << rVec3.y() << ", " << rVec3.z() << ", " << rVec3.w() << " )";

	return os;
}