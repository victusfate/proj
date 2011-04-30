#include <stdarg.h>
#include <math.h>

#include "mArray.h"

template <class T>
mArray<T> &qsort(mArray<T> &a) {
	long len = a.size();
	if (len <= 1) return;
	long pind = len/2;
	T piv = a[pind];
	mArray<T> less,greater,pivarr(1);
	pivarr[0]=piv;
	
	long i;
	for (i=0;i < len;i++) {
		T val = a[i];
		if (i!=pind) {
			if (val < piv) less.push(val);
			else greater.push(val);
		}
	}
	return cat<T>(3,qsort(less),pivarr,qsort(greater));
};

int main(int argc,char *argv[])
{
	Fptr2 fadd = &addTwo<double>;
	
	double pa[] = {0,1,2,3,5.5};
	mArray<double> test(5,pa);
	double sum=0;
	long i;
	long FTimes = 10000000;
	for (i=0;i < FTimes;i++) {
		test.nuke();
		test.resetD(5,pa);
		sum += test.foldRight(fadd);
		if (!(i%1000000)) cout << "\r what the f " << i << " sum " << sum << endl;
	}
	cout << "test " << test << " folded sum " << FTimes << " times " << sum << endl;
/*	double *pa = {0,1,2,3,5.5};
	double *pb = {9,12,77.4,sqrt(16)};
	mArray<double> a(5,pa);
	mArray<double> b(5,pb);
	c = cat(2,a,b);
	cout << "c " << c << endl;*/
}