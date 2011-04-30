#ifndef CURRY 
#define CURRY 1

#include "Fptr.h"
#include "mArray.h"

using namespace std;

template<class T>
vp addTwo(vp vred,vp vval) {
	T *red = (T*)vred;
	T *val = (T*)vval;
//	cout << "about to add red " << *red << " to val " << *val << endl;
	*red += *val;
	return (vp)red;
};

template<class T>
vp addOne(vp vtemp) {
	T *temp = (T*)vtemp;
	T val = 1;
	cout << "temp " << *temp << " val " << val << endl;
	*temp += val;
	return (vp)temp;
};

template<class T>
vp multByTwo(vp vtemp) {
	T *temp = (T*)vtemp;
	T val = 2;
	cout << "temp " << *temp << " val " << val << endl;
	*temp *= val;
	return (vp)temp;
};

template<class T>
vp subSeven(vp vtemp) {
	T *temp = (T*)vtemp;
	T val = 7;
	cout << "temp " << *temp << " val " << val << endl;
	*temp -= val;
	return (vp)temp;
};

template<class T>
vp divByTen(vp vtemp) {
	T *temp = (T*)vtemp;
	T val = 10;
	cout << "temp " << *temp << " val " << val << endl;
	*temp /= val;
	return (vp)temp;
};

vp curry(mArray<Fptr1> funcs,vp varg) {
	long i;
	vp temp = varg;
	for (i=0;i < funcs.size();i++) {
		temp = funcs[i](temp);
	}
	return temp;
};

template <class T>
T sCurry(long n,...) {
	cout << "sCurry n " << n << endl;
	mArray<Fptr1> funcs(n-1);
	va_list a;
	va_start(a,n);
	long i;
	// lifo, last function on list, is first applied
	for (i=n-1;i >= 1;i--) {
		Fptr1 f = va_arg( a, Fptr1 );
		funcs[i-1] = f;
	}
	vp varg;
	varg = va_arg(a,vp);
	return *(T*)(curry(funcs,varg));
};

template <class T>
T sCurry(mArray<Fptr1> &funcs,T val) {
	vp varg = (vp)&val;
	return *(T*)(curry(funcs,varg));
};

#endif
