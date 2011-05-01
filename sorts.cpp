#include <stdarg.h>
#include <math.h>

#include "mArray.h"
#include "RunTime.h"

template <class T>
void qsort(mArray<T> &a) {
	long len = a.size();
	if (len <= 1) return;
	long pind = len/2;
	T piv = a[pind];
	mArray<T> less(0,a.capacity()),greater(0,a.capacity()),pivarr(1);
	pivarr[0]=piv;
	
	long i;
	for (i=0;i < len;i++) {
		T val = a[i];
		if (i!=pind) {
			if (val < piv) less.push(val);
			else greater.push(val);
		}
	}

	qsort(less);
	less.append(pivarr);
	qsort(greater);
	less.append(greater);
	a = less;
};


// fast in memory of the original array
template <class T>
void qsort(mArray<T> &a,long start,long end) {
	long len = end - start+1;
	
	if (len <= 1) return;

	long pind = len/2+start;
	T piv = a[pind];
	long si = start,i;

	swap<T>(a[pind],a[end]);
	pind = end;
//	cout << "Piv " << piv << endl;
	for (i=start;i < end;i++) {
//		cout << i << " before a " << a << endl;
		if (a[i] < piv) {
//			cout << "swapping left " << a[si] << " and current " << a[i] << " si ";
			swap<T>(a[i],a[si]);
			si++;
//			cout << si << endl;
		}
//		cout << i << " after  a " << a << endl;
	}
	swap<T>(a[si],a[pind]);
	pind = si;
	qsort(a,start,pind-1);
	qsort(a,pind+1,end);
};



int main(int argc,char *argv[])
{
	double pa[] = {0,11.6,2,4.3,5.5};
	double pb[] = {9,112,8,77.4,4};
	mArray<double> a(5,pa);
	mArray<double> b(5,pb);

	cout << "testing concatentation\n";
	mArray<double> c = cat<double>(2,(vp)&a,(vp)&b);
	cout << "c cat (...) " << c << endl;
	
	mArray< mArray<double> > dat(2);
	dat[0] = a;
	dat[1] = b;
	
	mArray<double> d = cat<double>(dat);
	cout << "d cat (arr) " << d << endl;
	
	cout << "\n-------------------------------------------------------------------------\n";
	long FTimes = 1000000;
	cout << "folding a " << FTimes << " times\n";
  	// test folding	
	Fptr2 fadd = &addTwo<double>;
	
	double pc[] = {0,1,2,3,5.5};
	mArray<double> test(5,pc);
	double sum=0;
	long i;
	for (i=0;i < FTimes;i++) {
		test.nuke();
		test.resetD(5,pc);
		sum += test.foldRight(fadd);
		if (!(i%100000)) cout << "\r what the f " << i << " sum " << sum << endl;
	}
	cout << "test " << test << " folded sum " << FTimes << " times " << sum << endl;
	
	cout << "\n-------------------------------------------------------------------------\n";
	cout << "in place sorting " << FTimes << " arrays " << endl;
//	double da[] = {4,2,3};
//	d.resetD(3,da);
	RunTime timer;
	for (i=0;i < FTimes;i++) {
		mArray<double> sorted = d;
		qsort(sorted,0,sorted.size()-1);
		if (!(i%100000)) {
			cout << "sorted " << sorted << endl;
			cout << "in place method: " << timer << endl;
		}
	}
	cout << "\n-------------------------------------------------------------------------\n";
	cout << "temporary lists sorting " << FTimes << " arrays " << endl;
	RunTime timer2;
	for (i=0;i < FTimes;i++) {
		mArray<double> sorted = d;
		qsort(sorted);
		if (!(i%100000)) {
			cout << "sorted " << sorted << endl;
			cout << "temporary lists method: " << timer << endl;
		}
	}

	
}