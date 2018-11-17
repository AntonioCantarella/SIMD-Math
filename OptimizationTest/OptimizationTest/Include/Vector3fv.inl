
Vector3fv::Vector3fv()
{
	_value = _mm_set_ps(0.f, 0.f, 0.f, 0.f);
}

Vector3fv::Vector3fv(const float x, const float y, const float z)
{
	_value = _mm_set_ps(z, z, y, x);
}

float Vector3fv::x() const
{
	return _mm_cvtss_f32(_value);
}

float Vector3fv::y() const
{
	return _mm_cvtss_f32(_mm_shuffle_ps(_value, _value, _MM_SHUFFLE(1, 1, 1, 1)));
}

float Vector3fv::z() const
{
	return _mm_cvtss_f32(_mm_shuffle_ps(_value, _value, _MM_SHUFFLE(2, 2, 2, 2)));
}

void Vector3fv::SetX(float x)
{
	_value = _mm_move_ss(_value, _mm_set_ss(x));
}

void Vector3fv::SetY(float y)
{
	__m128 temp = _mm_move_ss(_value, _mm_set_ss(y));
	temp = _mm_shuffle_ps(temp, temp, _MM_SHUFFLE(3, 2, 0, 0));
	_value = _mm_move_ss(temp, _value);
}

void Vector3fv::SetZ(float z)
{
	__m128 temp = _mm_move_ss(_value, _mm_set_ss(z));
	temp = _mm_shuffle_ps(temp, temp, _MM_SHUFFLE(3, 0, 1, 0));
	_value = _mm_move_ss(temp, _value);
}

float Vector3fv::Dot(Vector3fv leftVector, Vector3fv rightVector)
{
	__m128 t0 = _mm_mul_ps(leftVector._value, rightVector._value);		//t0 = (zz, zz, yy, xx)
	__m128 t1 = _mm_shuffle_ps(t0, t0, _MM_SHUFFLE(1, 0, 3, 2));		//t1 = (yy, xx, zz, zz)
	__m128 t2 = _mm_add_ps(t0, t1);										//t2 = (yy+zz, xx+zz, yy+zz, xx+zz)
	__m128 t3 = _mm_shuffle_ps(t2, t2, _MM_SHUFFLE(2, 3, 0, 1));		//t3 = (xx+zz, yy+zz, xx+zz, yy+zz)
	__m128 t4 = _mm_add_ss(t3, t0);										//t4 = t3+t0(_mm_add_ss) (xx+zz, yy+zz, xx+zz, xx+yy+zz) || t3+t0(_mm_add_ps) (xx+zz+zz, yy+zz+zz, xx+yy+zz, xx+yy+zz)

	return _mm_cvtss_f32(t4);											//return _mm_cvtss_f32(t4)
}

float Vector3fv::DotV2(Vector3fv leftVector, Vector3fv rightVector)
{
	__m128 dot = _mm_mul_ps(leftVector._value, rightVector._value);		//dot (zz, zz, yy, xx)
	__m128 temp = _mm_shuffle_ps(dot, dot, _MM_SHUFFLE(2, 1, 2, 1));	//t0 = (zz, yy, zz, yy)
	dot = _mm_add_ps(dot, temp);										//dot = (zz+zz, yy+zz, yy+zz, xx+yy)
	temp = _mm_shuffle_ps(temp, temp, _MM_SHUFFLE(1, 1, 1, 1));			//t0 = (zz, zz, zz, zz)
	dot = _mm_add_ss(dot, temp);										//dot = (zz+zz+zz, yy+zz+zz, yy+zz+zz, xx+yy+zz)

	return _mm_cvtss_f32(dot);
}

Vector3fv __vectorcall operator +(Vector3fv lVec3, Vector3fv rVec3)
{
	return Vector3fv(_mm_add_ps(lVec3._value, rVec3._value));
}

Vector3fv __vectorcall operator -(Vector3fv lVec3, Vector3fv rVec3)
{
	return Vector3fv(_mm_sub_ps(lVec3._value, rVec3._value));
}

std::ostream& operator <<(std::ostream& os, const Vector3fv& rVec3)
{
	os << "( " << rVec3.x() << ", " << rVec3.y() << ", " << rVec3.z() << " )";

	return os;
}