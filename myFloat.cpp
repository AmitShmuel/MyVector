#include "myFloat.h"



myFloat::myFloat(long int mant , int dec) 
: mantise(mant) , decPoint(dec) , number(_strdup(setNumber(mant , dec))){
	
	//cout << "Construct myFloat..\n";
		
	//cout << "float number is: " << number << "\n\n";
}



myFloat::myFloat(long int mant) 
: mantise(mant) , decPoint(0) , number(_strdup(setNumber(mant, decPoint))) {
	
	//cout << "(Conversion) Construct myFloat..\n";
	
	//cout << "float number is: " << number << "\n\n";
}



myFloat::myFloat(const myFloat& f) {
	
	//cout << "(Copy) construct myFloat from: " << f.number << "\n\n";
	number = _strdup(f.number);
	decPoint = f.decPoint;
	mantise = f.mantise;
}



myFloat::~myFloat() {
	
	//cout << "\nDestruct " << number << endl;
	if(number)
		delete[] number;
}



myFloat& myFloat::operator=(const myFloat& f) {
	
	if(this == &f)
		return *this;
	
	if(number)
		delete[] number;

	number = _strdup(f.number);
	if(!number)
	{
		cout << "\n\nmyFloat operator= : Allocation error!\n\n";
		exit(1);
	}
	mantise = f.mantise;
	decPoint = f.decPoint;	
	
	return *this;
}


char* myFloat::setNumber(long int mant , int dec) {

	char* _number = new char[50];
	int i , term , count = countDigits(mant);
	
	if(dec == 0 || dec > count)
	{
		i = sprintf(_number , "%d" , mant);
		if(dec>count)
		{
			term = dec - count;
			while(term)
			{
				_number[i] = '0';
				term--;
				i++;
			}
		}
		_number[i] = '.';
		_number[i+1] = '0';
		_number[i+2] = '\0';
	}
		
	else if(dec > 0)
	{
		i = sprintf(_number , "%d" , mant) , term = i - dec;
		_number[i+1] = '\0';
		while(term)
		{
			_number[i] = _number[i-1];
			term--; 
			i--;
		}
		_number[i] = '.';
	}
		
	else // dec < 0
	{
		_number[0] = '0';
		_number[1] = '.';
		term = dec * -1 , i = 2;
		while(term-1)
		{
			_number[i] = '0';
			term--;
			i++;
		}
		sprintf(_number+i , "%d" , mant);
	}
	return _number;
}



myFloat& myFloat::switchOP(const myFloat& f , char op) {
	
	double d1 = strtod(number , 0);	// string to double
	double d2 = strtod(f.number , 0);
	
	switch(op)	// doing arithmetic 
	{
		case '+':
			d1 += d2;
			break;
			
		case '-':
			d1 -= d2;
			break;
			
		case '*':
			d1 *= d2;
			break;
			
		case '/':
			d1 /= d2;
			break;
	}
	
	sprintf(number , "%f" , d1); // back to string
	decPoint = toDec(number);
	mantise = toMant(number);
	
	return *this;
}



myFloat operator+(const myFloat& f1 , const myFloat& f2) {
	
	myFloat temp(f1);
	temp += f2;
	return temp;
}


myFloat operator-(const myFloat& f1 , const myFloat& f2) {
	
	myFloat temp(f1);
	temp -= f2;
	return temp;
}


myFloat operator*(const myFloat& f1 , const myFloat& f2) {
	
	myFloat temp(f1);
	temp *= f2;
	return temp;
}


myFloat operator/(const myFloat& f1 , const myFloat& f2) {
	
	myFloat temp(f1);
	temp /= f2;
	return temp;
}



bool operator==(const myFloat& f1 , const myFloat& f2) {
	
	if(!strcmp(f1.getNumber() , f2.getNumber()))
		return true;
	return false;
}



ostream& operator<<(ostream& os , const myFloat& f) {
	
	os << f.getNumber();	
	return os;
}




int countDigits(int num)
{
	int count=0;
	while(num%10 != 0)
	{
		num /= 10;
		count++;
	}
	return count;
}


int toDec(char* _number) {
	
	int count = 0;
	while(*_number != '.' && *_number != '\0')
	{
		count++;
		_number++;
	}
	return count;
}



long int toMant(char* _number) {
	
	char* temp = _strdup(_number);
	int i = 0;
	while(temp[i] != '.')
		i++;
		
	while(temp[i] != '\0')
	{
		temp[i] = temp[i+1];
		i++;
	}
	long int res = atol(temp);
	delete[] temp;
	return res;
}
