// Vector Header file 
// Vector is implemented as a template of any T elements
// Vector holds an array of T elements, top and size values

#ifndef _VECTOR_
#define _VECTOR_
#include <iostream>
using namespace std;

const int SIZE = 10;
const int MAX_SIZE = 1024;

// some aid functions
int setSize(int);
void checkBounds(int , int);


template <class T>
class Vector{
	
	int top , size;
	T* Array;
	
public:
	
	Vector(int sz = SIZE) : size(setSize(sz)) , top(-1) , Array(new T[size]) {cout << "Construct Vector with " << size <<" elements..\n";}
	Vector(const Vector&);
	~Vector() {delete[] Array; cout << "Destruct Vector..\n";}
	
	Vector<T>& operator=(const Vector<T>&);
	T& operator[](int index);
	const T& operator[](int index) const;
	
	void clear();
	bool add(T elem);
	bool remove(int index);
	
	const T& first() const {checkBounds(0,top); return Array[0];} 
	const T& last() const {checkBounds(top,top); return Array[top];} 
	int getCount() const {return top+1;} 
	bool empty() const {return top == -1;} 
	bool full() const {return top == size-1;} 
};



template <class T>
Vector<T>::Vector(const Vector& l) : size(l.size) , top(l.top) , Array(new T[l.size]) {

	cout << "(Copy) Construct Vector..\n";
	for(int i=0; i<=top; ++i)
		Array[i] = l.Array[i]; 
}



template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& l) {
	
	if(this == &l)
		return *this;
	
	if(size != l.size)	// if sizes are equal, allocation is not nesessary
	{
		delete[] Array;
		Array = new T[size=l.size];
	}
	
	for(int i=0; i<=l.top; ++i)
		Array[i] = l.Array[i];
	top = l.top;
	
	return *this;
}



template <class T>
T& Vector <T>::operator[](int index) {
	
	checkBounds(index,top);	
	return Array[index];
}



template <class T>
const T& Vector<T>::operator[](int index) const {
	
	checkBounds(index,top);
	return Array[index];
}



template <class T>
bool Vector <T>::add(T elem) {
	
	if(!full())
	{
		Array[++top] = elem;
		return true;
	}
		
	else
	{
		if(size == MAX_SIZE)
		{
			cout << "Vector has reached the maximum size, cannot allocate any more memory..\n";
			return false;
		}
		
		else
		{
			int toAlloc = (MAX_SIZE - size) > SIZE ? SIZE : (MAX_SIZE - size); 	// if the difference between size and MAX_SIZE is less than SIZE, allocates just the difference.. (aviod allocating more than 1024 = MAX_SIZE)
			
			T* newArray = new T[size+=toAlloc];	// Allocating a new larger array
			if(newArray == 0) 
			{
				cout << "Vector::add : Allocation error!\n\n"; 
				return false;
			}
		
			for(int i=0; i<=top; i++)	// copying each element to the new array
				newArray[i] = Array[i];
			
			delete[] Array;
		
			Array = newArray; 	// this Array points to the new array
			Array[++top] = elem;	// adding is possible..
		
			return true;
		}
	}
}



template <class T>
bool Vector <T>::remove(int index) {
	
	if(empty())
	{
		cout << "Vector is empty..\n";
		return false;
	}
	
	if(index < 0 || index > top)
	{
		cout << "There's not such index in the list..\n";
		return false;
	}
	
	if(getCount() == 1 || index == size-1)	// if list holds one element, or given index is the last index, we can do just top--
	{
		top--;
		return true;
	}
		
	while(index < top) {	// here we want to shift each element one cell back
		
		Array[index] = Array[index+1];
		index++;
	}
	--top;
	return true;		
}



template <class T>
void Vector<T>::clear() {
	
	if(empty()) 
	{
		cout << "Vector is empty..\n";
		return;
	}
	
	cout << "Clearing list..\n";
	
	if(full())
		size = SIZE;	// will allocate new list with defined SIZE
	else
		size -= top;	// will allocate new list with the remaining space
		
	delete[] Array;
	Array = new T[size];
	top = -1;
}

#endif
