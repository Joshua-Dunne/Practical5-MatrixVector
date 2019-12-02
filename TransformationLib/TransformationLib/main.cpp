#include <iostream>
#include "Vector3.h"
#include "Vector2.h"
#include "Matrix3.h"
#include "Quaternion.h"

/// <summary>
/// Joshua Dunne
/// C00241588
/// Date(s): 25/11/19, 01/12/19, 02/12/19
/// Estimated time: 10 hours
/// Time taken: ~ 5hours
/// </summary>


void vector3Tests();
void vector2Tests();
void matrix3Tests();
void quarternionTests();

int main()
{
	vector3Tests();
	std::cin.get();
	std::cout << std::endl << std::endl;

	vector2Tests();
	std::cin.get();
	std::cout << std::endl << std::endl;

	matrix3Tests();
	std::cin.get();
	std::cout << std::endl << std::endl;

	quarternionTests();
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
	// put different tests of matrix functions here
}

void quarternionTests()
{
	// put different tests of quaternion functions here
	Quaternion q1{ 2.0, 2.0, 2.0, 2.0 };

	std::cout << "Quaternion original: " << q1.ToString() << std::endl;
	
	q1 = q1 + Quaternion{ 1.0, 1.0, 1.0, 1.0 };
	std::cout << "Quaternion addition (1,1,1,1): " << q1.ToString() << std::endl;

	q1 = q1 - Quaternion{ 1.0, 1.0, 1.0, 1.0 };
	std::cout << "Quaternion subtraction (1,1,1,1): " << q1.ToString() << std::endl;

	q1 = q1 * Quaternion{ 3.0, 3.0, 3.0, 3.0 };
	std::cout << "Quaternion multiplication (3,3,3,3): " << q1.ToString() << std::endl;
}
