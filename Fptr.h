#ifndef F_PTR_H
#define F_PTR_H

using namespace std;

typedef void* vp;
typedef vp(*Fptr1)(vp);
typedef vp(*Fptr2)(vp,vp);
typedef vp(*Fptr3)(vp,vp,vp);

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



#endif