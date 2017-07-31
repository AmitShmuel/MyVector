#include "Vector.h"


int setSize(int size) {
	
	if(size <= 0 || size >= MAX_SIZE)
		return SIZE;
	return size;
}


void checkBounds(int index , int _top) {
	
	if(index < 0 || index > _top)
	{
		cout << "Out of bounds! shutting down program..\n";
		exit(1);
	}
}
