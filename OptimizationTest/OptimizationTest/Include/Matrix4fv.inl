
Matrix4fv::Matrix4fv()
{
	_value[0] = Vector4fv();
	_value[1] = Vector4fv();
	_value[2] = Vector4fv();
	_value[3] = Vector4fv();
}

Matrix4fv::Matrix4fv(Vector4fv row1, Vector4fv row2, Vector4fv row3, Vector4fv row4)
{
	_value[0] = row1;
	_value[1] = row2;
	_value[2] = row3;
	_value[3] = row4;
}

Matrix4fv Matrix4fv::Transpose() const
{
	Vector4fv r3 = Vector4fv(_value[0].w(), _value[1].w(), _value[2].w(), _value[3].w());
	Vector4fv r2 = Vector4fv(_value[0].z(), _value[1].z(), _value[2].z(), _value[3].z());
	Vector4fv r1 = Vector4fv(_value[0].y(), _value[1].y(), _value[2].y(), _value[3].y());
	Vector4fv r0 = Vector4fv(_value[0].x(), _value[1].x(), _value[2].x(), _value[3].x());

	return { r0, r1, r2, r3 };
}

Matrix4fv __vectorcall operator *(const Matrix4fv lMat4, const Matrix4fv rMat4)
{
	Matrix4fv rt = rMat4.Transpose();
	Matrix4fv res;
	float row[4];

	for (int8_t i = 0; i < 4; ++i)
	{
		for (int8_t j = 0; j < 4; ++j)
			row[j] = Vector4fv::Dot(lMat4._value[i], rt._value[j]);

		res._value[i] = Vector4fv(row[0], row[1], row[2], row[3]);
	}

	return res;
}