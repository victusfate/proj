#include <stdarg.h>
#include <stdlib.h>
#include <iostream>

template<class T>
T sum(long n,...) {
	long i;
	va_list a;
    va_start( a, n );
	T osum=0;
	for(i=1;i <= n;i++) {
		T val = va_arg(a,T);
		osum += val;
	}
	va_end(a);
	return osum;
};

template<class T>
T product(long n,...) {
	long i;
	va_list a;
    va_start( a, n );
	T prod=1;
	for(i=1;i <= n;i++) {
		T val = va_arg(a,T);
		prod *= val;
	}
	va_end(a);
	return prod;
};

using namespace std;

int main(int argc, char *argv[])
{
	double ten = sum<double>(4,2.,3.,4.,1.);
	double twelve = product<double>(3,2.,2.,3.);
	cout << "Ten (doubles)" << ten << " twelve " << twelve << endl;
	ten = sum<long>(4,2,3,4,1);
	twelve = product<long>(3,2,2,3);
	cout << "Ten (longs)" << ten << " twelve " << twelve << endl;
	return 1;
}
