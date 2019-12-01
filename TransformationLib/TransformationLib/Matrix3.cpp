#include "Matrix3.h"

Matrix3::Matrix3()
{
	A11 = 0.0;
	A12 = 0.0;
	A13 = 0.0;
	A21 = 0.0;
	A22 = 0.0;
	A23 = 0.0;
	A31 = 0.0;
	A32 = 0.0;
	A33 = 0.0;
}

Matrix3::Matrix3(Vector3 Row1, Vector3 Row2, Vector3 Row3)
{
	A11 = Row1.getX();
	A12 = Row1.getY();
	A13 = Row1.getZ();
	A21 = Row2.getX();
	A22 = Row2.getY();
	A23 = Row2.getZ();
	A31 = Row3.getX();
	A32 = Row3.getY();
	A33 = Row3.getZ();
}

Matrix3::Matrix3(double _A11, double _A12, double _A13, double _A21, double _A22, double _A23, double _A31, double _A32, double _A33)
{
	A11 = _A11;
	A12 = _A12;
	A13 = _A13;
	A21 = _A21;
	A22 = _A22;
	A23 = _A23;
	A31 = _A31;
	A32 = _A32;
	A33 = _A33;
}

Vector3 Matrix3::operator*(Vector3 V1)
{
	{// An overloaded operator * to return the  product of the matrix by a vector
		return { A11 * V1.getX() + A21 * V1.getY() + A31 * V1.getZ(),
			A12 * V1.getX() + A22 * V1.getY() + A32 * V1.getZ(),
			A13 * V1.getX() + A23 * V1.getY() + A33 * V1.getZ() };
	}
}

Matrix3 Matrix3::Transpose(Matrix3 M1)
{// a method to transpose a given matrix
	return Matrix3(M1.A11, M1.A21, M1.A31,
		M1.A12, M1.A22, M1.A32,
		M1.A13, M1.A23, M1.A33);
}

Matrix3 Matrix3::operator+(Matrix3 M1)
{// An overloaded operator + to return the  sum of two matrix 
	return Matrix3(M1.A11 + A11, M1.A12 + A12, M1.A13 + A13,
		M1.A21 + A21, M1.A22 + A22, M1.A23 + A23,
		M1.A31 + A31, M1.A32 + A32, M1.A33 + A33);
}

Matrix3 Matrix3::operator-(Matrix3 M1)
{// An overloaded operator * to return the  difference of two matrix
	return Matrix3(M1.A11 - A11, M1.A12 - A12, M1.A13 - A13,
		M1.A21 - A21, M1.A22 - A22, M1.A23 - A23,
		M1.A31 - A31, M1.A32 - A32, M1.A33 - A33);
}

// An overloaded operator * to return the  product of the matrix by a scalar
Matrix3 Matrix3::operator*(double x)
{
	Matrix3 answer;
	answer.A11 = A11 * x;
	answer.A12 = A12 * x;
	answer.A13 = A13 * x;

	answer.A21 = A21 * x;
	answer.A22 = A22 * x;
	answer.A23 = A23 * x;

	answer.A31 = A31 * x;
	answer.A32 = A32 * x;
	answer.A33 = A33 * x; ;

	return answer;
}

Matrix3 Matrix3::operator*(Matrix3 M1)
{// An overloaded operator * to return the  product of two matrix
	Matrix3 answer;

	answer.A11 = M1.Row(0) * Column(0);
	answer.A12 = M1.Row(0) * Column(1);
	answer.A13 = M1.Row(0) * Column(2);

	answer.A21 = M1.Row(1) * Column(0);
	answer.A22 = M1.Row(1) * Column(1);
	answer.A23 = M1.Row(1) * Column(2);

	answer.A31 = M1.Row(2) * Column(0);
	answer.A32 = M1.Row(2) * Column(1);
	answer.A33 = M1.Row(2) * Column(2);

	return answer;
}

double Matrix3::Determinant(Matrix3 M1)
{// method to return the determinant of a 3x3 matrix
			//                     aei      -     ahf                  + dhc                     - gec                      +    gbh                    -     dbi   
	return M1.A11 * M1.A22 * M1.A33 - M1.A11 * M1.A32 * M1.A23 + M1.A21 * M1.A32 * M1.A13 - M1.A31 * M1.A22 * M1.A13 + M1.A31 * M1.A12 * M1.A23 - M1.A21 * M1.A12 * M1.A33;
}

Vector3 Matrix3::Row(int i)
{
	// a method to return as Row as vector3 0 == first row, default == last row
	Vector3 answer;
	switch (i)
	{
	case 0:
		answer = Vector3(A11, A12, A13);
		break;
	case 1:
		answer = Vector3(A21, A22, A23);
		break;
	case 2:
	default:
		answer = Vector3(A31, A32, A33);
		break;
	}

	return answer;
}

Vector3 Matrix3::Column(int i)
{// a method to return as column as vector3 0 == first column, default == last column
	switch (i)
	{
	case 0:
		return{ A11, A21, A31 };
	case 1:
		return{ A12, A22, A32 };
	case 2:
	default:
		return{ A13, A23, A33 };
	}
}
