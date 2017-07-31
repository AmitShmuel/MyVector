// Assignment 3 - Template Vector + myFloat
// Made by Amit Shmuel - 305213621

#include <iostream>
#include "Vector.h"
#include "myFloat.h"
using namespace std;


int main(int argc, char** argv) {
	
	const myFloat f1(123,2) , f2(134,2);
	if(f1 == f2)
		cout << "bla";
	
	Vector<myFloat> vec = 30;
	Vector<myFloat> listA(4); // Creating 4 myFloat members list
	
	myFloat x(1234 , 3); // Creating myFloat abject - 123.4 
	myFloat y(123 , 2); // Creating myFloat object 12.3
	
	listA.add(x); 
	listA.add(y);
	
	cout << listA.first() << endl;
	cout << listA.last() << endl;
	
	Vector<myFloat> listB;
	listB = listA; // Vector operator=
	cout << listB.first() << endl; // x
	cout << listB.last() << endl; // y
	
	listA[0] *= listA[1]; // x = 123.4 * 12.3
	cout << "x * y = " << listA[0] << endl; // 1517.82000
	
	myFloat z(1234 , -1); // 0.1234
	
	listA.add(z);
	cout << "y / z = " << listA[1] / z << endl; // 12.3 / 0.1234 = 99.675851
	listA.remove(0); // remove x

	Vector<char> charVector(2);
	
	charVector.add(':');
	charVector.add(')');
	
	cout << endl << charVector.first();
	cout << charVector.last() << endl << endl; // :)
	
	getchar();
	return 0;
}
