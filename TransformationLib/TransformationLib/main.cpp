#include <iostream>
#include "Vector3.h"
#include "Vector2.h"
#include "Matrix3.h"
#include "Quaternion.h"

/// <summary>
/// Joshua Dunne
/// C00241588
/// Date(s): 25/11/19, 01/12/19, 02/12/19, 03/12/19
/// Estimated time: 10 hours
/// Time taken: ~ 5hours
/// </summary>


void vector3Tests(); // vector3 function tests
void vector2Tests(); // vector2 function tests
void matrix3Tests(); // matrix function tests
void quarternionTests(); // quaternion function tests
void classTests(); // tests done in class

int main()
{
	/*vector3Tests();
	std::cin.get();
	std::cout << std::endl << std::endl;

	vector2Tests();
	std::cin.get();
	std::cout << std::endl << std::endl;

	matrix3Tests();
	std::cin.get();
	std::cout << std::endl << std::endl;*/

	classTests();
	std::cin.get();
	std::cout << std::endl << std::endl;

	return 0;
}

void vector3Tests()
{

	Vector3 myOriginalVector{};
	Vector3 myVector{ 2.0f, 2.0f, 2.0f };
	Vector3 myNewVector{ myVector };
	Vector3 productVector{ 4.5f, 8.2f, 18.6f };

	std::cout << "myOriginalVector: " << myOriginalVector.toString() << std::endl;
	std::cout << "myVector" << myVector.toString() << std::endl;
	std::cout << "myNewVector" << myNewVector.toString() << std::endl;

	myOriginalVector = myOriginalVector + myVector; // addition

	std::cout << "Addition of myOriginalVector with myVector: " << myOriginalVector.toString() << std::endl;

	-myOriginalVector; // sign flip

	std::cout << "Reversing Signs of myOriginalVector: " << myOriginalVector.toString() << std::endl;

	myOriginalVector = myOriginalVector - myVector; // subtraction

	std::cout << "Subtraction of myOriginalVector from myVector: " << myOriginalVector.toString() << std::endl;

	double scalarProduct = myOriginalVector * myNewVector; // scalar product by vector3

	std::cout << "Scalar Product of myOriginalVector and myNewVector: " << std::to_string(scalarProduct) << std::endl;

	myOriginalVector = myOriginalVector * 2.0f; // scalar by 2 float

	std::cout << "Multiplication of myOriginalVector by Float 2: " << myOriginalVector.toString() << std::endl;

	myOriginalVector = myOriginalVector * 2; // scalar by 2 int

	std::cout << "Multiplication of myOriginalVector by Int 2: " << myOriginalVector.toString() << std::endl;

	myVector = myOriginalVector ^ productVector; // get product of Vector3 classes

	std::cout << "Vector Product of myOriginalVector and myNewVector: " << myVector.toString() << std::endl;

	std::cout << std::endl;

	Vector3 normalisedVector;
	normalisedVector = myOriginalVector.normalise();

	std::cout << "Normalised myOriginalVector: " << normalisedVector.toString() << std::endl;
}

void vector2Tests()
{
	Vector2 myVector;
	Vector2 otherVector{ 2.0f, 2.0f };

	myVector = myVector + otherVector;

	std::cout << "Vector addition: " << myVector.toString() << std::endl;

	Vector2 anotherVector{ 1.0f, 1.0f };

	myVector = myVector - anotherVector;

	std::cout << "Vector subtraction: " << myVector.toString() << std::endl;

	float scalar = myVector * otherVector;

	std::cout << "Scalar of myVector: " << std::to_string(scalar) << std::endl;

	myVector = myVector * 2;

	std::cout << "myVector multiplication by Scalar of 2: " << myVector.toString() << std::endl;

	Vector2 normalised;
	normalised = myVector.normalise();

	std::cout << "myVector normalised " << normalised.toString() << std::endl;

	otherVector = Vector2{ 3.0f, 4.0f };
	anotherVector = Vector2{ 5.0f, 6.0f };

	float crossProduct = anotherVector ^ otherVector;

	std::cout << "Cross product of anotherVector and otherVector is " << std::to_string(crossProduct) << std::endl;
}

void matrix3Tests()
{
	Matrix3 matrix{ 1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0 };
	Matrix3 matrix2{};
	matrix2 = matrix + matrix; // addition with itself
	std::cout << "Matrix{1,2,3,4,5,6,7,8,9} added to itself: " + matrix2.toString() << std::endl;
	matrix2 = matrix - matrix2;
	std::cout << "Matrix{1,2,3,4,5,6,7,8,9} minus Matrix2{2,4,6,8,10,12,14,16,18}: " << matrix2.toString() << std::endl;
	
	Matrix3 matrix3;
	matrix3 = matrix * matrix2;
	std::cout << "Product of Matrix * Matrix 2: " << matrix3.toString() << std::endl;

}

void quarternionTests()
{
	Quaternion q1{ 2.0, 2.0, 2.0, 2.0 };

	std::cout << "Quaternion original: " << q1.ToString() << std::endl;
	
	q1 = q1 + Quaternion{ 1.0, 1.0, 1.0, 1.0 };
	std::cout << "Quaternion addition (1,1,1,1): " << q1.ToString() << std::endl;

	q1 = q1 - Quaternion{ 1.0, 1.0, 1.0, 1.0 };
	std::cout << "Quaternion subtraction (1,1,1,1): " << q1.ToString() << std::endl;

	q1 = q1 * Quaternion{ 3.0, 3.0, 3.0, 3.0 };
	std::cout << "Quaternion multiplication (3,3,3,3): " << q1.ToString() << std::endl;

	Quaternion q2;
	q2.FromAxisAngle(Vector3{ 1,0,0 }, 45);
	std::cout << "q2 from Axis Angle Vector3{1,0,0} at 45 degrees: " << q2.ToString() << std::endl;

	Quaternion q3{ 3,4,-9,6 };
	Vector3 rotated = q3.Rotate(Vector3{ 3,5,-1 }, 90);
	std::cout << "Rotated Vector{3,5,-1} by 90 degrees: " << rotated.toString() << std::endl;


}

void classTests()
{
	Vector3 v1{ 0, 2, -5};
	Vector3 v2{-2, -2, -5};
	Vector3 v3{2, -2, -5};

	Matrix3 m1{ v1, v2, v3 };

	float angle = 23.21;

	m1 = m1.RotationZ(23.21);

	float quartAngle = 5.0f;

	Vector3 v4 = Quaternion().Rotate(v3, quartAngle);
	

	std::cout << "v1 length: " << std::to_string(v1.length()) << std::endl;
	std::cout << "v2 lenght squared: " << std::to_string(v2.lengthSquared()) << std::endl;
	std::cout << "m1 rotated on Z Axis by 23.21 degrees: " << m1.toString() << std::endl;
	std::cout << "Vector rotated by quarternion: " << v4.toString() << std::endl;


}
