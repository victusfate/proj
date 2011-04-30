#include <stdarg.h>
#include <stdlib.h>
#include <iostream>

#include "mArray.h"
#include "curry.h"

using namespace std;

int main(int argc, char *argv[])
{
	if (argc != 2) {
		cout << argv[0] << " baseval\n";
		exit(-1);
	}
	
	//Fptr1 is of type void* (*f)(void*), setting template function pointers
	Fptr1 f1 = &addOne<double>;
	Fptr1 f2 = &multByTwo<double>;
	Fptr1 f7 = &subSeven<double>;
	Fptr1 f10 = &divByTen<double>;

	double val = atof(argv[1]), val2 = atof(argv[1]);
	cout << "Address to base numeric " << &val << " base val " << val << endl;
	cout << "addOne-> " << *(double *)f1((vp)&val) << " curried addOne " << sCurry<double>(2,f1,(vp)&val2) << endl;
	cout << endl;
	cout << "start curry val " << val << endl;
	cout << "curried output f10(f7(f2(f1(val)))) or ((val+1)*2-7)/10 = " << sCurry<double>(5,f10,f7,f2,f1,(vp)&val) << endl;
	return 1;
}