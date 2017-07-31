// myFloat Header file
// myFloat is implemented by a long-int mantise and an int value representing the decimal point

#ifndef _MYFLOAT_
#define _MYFLOAT_
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

// some aid functions
int countDigits(int);
long int toMant(char*);
int toDec(char*);
 

class myFloat {
	
	long int mantise;
	int decPoint;
	char* number; // will represent the float number
	
	char* setNumber(long int , int); // representing the number by string using the mantise and decPoint
	myFloat& switchOP(const myFloat& f, char op); // switch for OP= (+= -= *= /=) , helps avoid reuse of code 
	
public:
	
	myFloat(long int mant=0 , int dec=0); 
	myFloat(long int mant); // Conversion for primitive variables to myFloat
	myFloat(const myFloat&);
	~myFloat();
	
	myFloat& operator=(const myFloat&);
	myFloat& operator+=(const myFloat& f) {return switchOP(f , '+');}
	myFloat& operator-=(const myFloat& f) {return switchOP(f , '-');}
	myFloat& operator*=(const myFloat& f) {return switchOP(f , '*');}
	myFloat& operator/=(const myFloat& f) {return switchOP(f , '/');}
	
	const char* getNumber() const {return number;} 
};

// symetric unary extern functions
myFloat operator+(const myFloat& , const myFloat&);
myFloat operator-(const myFloat& , const myFloat&);
myFloat operator*(const myFloat& , const myFloat&);
myFloat operator/(const myFloat& , const myFloat&);

bool operator==(const myFloat& , const myFloat&); 
ostream& operator<<(ostream& , const myFloat&);

#endif
