#ifndef VECTOR3_H
#define VECTOR3_H

#include <iostream>
#include <math.h>
#include <string>

class Vector3
{
public:
	// default constructor
	Vector3() :
		m_x(0.0)
		, m_y(0.0)
		, m_z(0.0	)
	{

	}

	// To allow other values for X, Y and Z to be declared
	Vector3(double x1, double y1, double z1) :
		  m_x(x1)
		, m_y(y1)
		, m_z(z1)
	{
	}

	// To allow other values for X, Y and Z to be declared
	Vector3(const Vector3& t_v) :
		m_x(t_v.m_x)
		, m_y(t_v.m_y)
		, m_z(t_v.m_z)
	{
	}


private:
	// The class has three variables x, y and z 
	double m_x;
	double m_y;
	double m_z;

public:

	double getX() const { return m_x; };
	void setX(double t_x) { m_x = t_x; };

	double getY() const { return m_y; };
	void setY(double t_y) { m_y = t_y; };

	double getZ() const { return m_z; };
	void setZ(double t_z) { m_z = t_z; };

	/// <summary>
	/// A method to return the length of the vector 
	/// </summary>
	/// <returns>Length of vector</returns>
	inline double length() const
	{
		return sqrt(lengthSquared());
	}

	/// <summary>
	/// A method to return the length squared of the vector
	/// </summary>
	/// <returns>Squared length of vector</returns>
	inline double lengthSquared() const
	{
		return (m_x * m_x + m_y * m_y + m_z * m_z);
	}

	/// <summary>
	/// A method to reduce the length of the vector to 1.0 
	/// keeping the direction the same 
	/// </summary>
	/// <returns>Normalised Vector3</returns>
	Vector3 normalise();

	std::string toString();

	Vector3 operator+(const Vector3 t_addVector) const;
	Vector3 operator-(const Vector3 t_subVector) const;
	void operator-();
	double operator *(Vector3 m_scalarVector) const;
	Vector3 operator *(float k) const;
	Vector3 operator ^(Vector3 t_vector) const;
};

#endif