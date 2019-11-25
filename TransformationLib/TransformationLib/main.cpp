#include <iostream>
#include "Vector3.h"

int main()
{
	Vector3 myOriginalVector{};
	Vector3 myVector{ 2.0, 2.0, 2.0 };
	Vector3 myNewVector{ myVector };
	Vector3 productVector{ 4.5, 8.2, 18.6 };

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

	std::cin.get();
	return 0;
}