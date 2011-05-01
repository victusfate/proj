#ifndef M_ARRAY 
#define M_ARRAY 1

#include <stdlib.h>
#include <iostream>

#include "Fptr.h"

using namespace std;

template <class T> class mArray;

template <class T>
ostream& operator<<(ostream &os,const mArray<T>& m);


template <class T>
class mArray {
public:
	mArray(long n=0,long cap=0,T *ptr=NULL) : m_p(NULL),m_cap(0),m_n(0) {
//		cout << "in constructor 1\n";
		if (n && !cap) cap = n;
		init(n,cap,ptr);
	};

	mArray(long n,T *ptr) : m_p(NULL),m_cap(0),m_n(0) {
//		cout << "in constructor 2\n";
		init(n,n,ptr);
	};
	
	mArray(const mArray<T> &r) : m_p(NULL),m_cap(0),m_n(0) {
		*this = r;
	}

	// mArray allocates and deletes its own memory
	~mArray() { 
		nuke();
	};

	// free up and contract marray to nil
	void nuke() {
		if (m_p) {
			delete [] m_p;
			m_p = NULL;
			m_n = 0;
			m_cap = 0;
		}
	}

	// allocate/grow marray
	void spawn(long n,long cap) {
//		cout << "spawn\n";
		if (n < 0 || cap < 0) {
			cout << "mArray::spawn attempting to spawn array of negative size, n,cap " << n << " " << cap << endl;
			exit(-1);
		}
		m_cap = cap;
		m_n = n;
		if (m_cap) {
			m_p = new T[m_cap];
		}
	}

	void copy(long n,const T *ptr) {
		if (m_n < n) {
			cout << "mArray<T> copy request of size n " << n << " greater than current array dim " << m_n << endl;
			exit(-1);
		}
		if (ptr) {
			long i;
			for (i=0;i < n;i++) {
				m_p[i] = ptr[i];
			}
		}
	}

	void init(long n,long cap,T *ptr) {
//		cout << "init n cap ptr " << n << " " << cap << " " << ptr << endl;
		spawn(n,cap);
		if (ptr) {
			long i;
			for (i=0;i < m_n;i++) {
				m_p[i] = ptr[i];
			}
		}
	};

	void resetD(long n=0,T *ptr=NULL) {
		if (n <= m_cap) {
			m_n = n;
		}
		else {
			nuke();
			spawn(n,n);
		}
		copy(n,ptr);
	}
	
	T foldRight(Fptr2 f) const {
		long i;
		T fout;
		if (m_n) {
			fout = m_p[0];
			for (i=1;i < m_n;i++) {
				fout = *(T*)f((vp)&fout,(vp)&m_p[i]);
			}
		}
		return fout;
	}
	
	const T& operator[](long i) const { 
		if (i>= 0 && i < m_n) return m_p[i];
		else { cout << "mArray operator[] const ind "<< i << " dim " << m_n << endl; exit(-1); }
	};
	
	T& operator[](long i) { 
		if (i>= 0 && i < m_n) return m_p[i];
		else { cout << "mArray operator[] ind "<< i << " dim " << m_n << endl; exit(-1); }
	};
	
	mArray<T> &push(const T& val){
		if ( (m_n+1) <= m_cap) {
			m_p[m_n] = val;
			m_n = m_n+1;
		}
		else {
			// temporary copy, nuke, spawn new size and cap, copy temp back into array,add new val
			long nsize = m_n+1;
			long cap = 2*nsize;
			mArray<T> temp = *this; 
			nuke();
			spawn(nsize,cap);
			copy(temp.size(),temp.ptr()); 
			m_p[nsize-1] = val;
		}
		return *this;
	};
	mArray<T> &append(const mArray<T> &r){
		if ( (m_n+r.m_n) <= m_cap) {
			long i;
			for (i=0;i < r.m_n;i++) {
				m_p[m_n+i] = r.m_p[i];
			}
			m_n = m_n+r.m_n;
			
		}
		else {
			mArray<T> temp = *this;
			resetD(m_n+r.m_n);
			long i;
			for (i=0;i < m_n;i++) {
				T val;
				if (i < temp.m_n) val = temp.m_p[i];
				else val = r.m_p[i-m_n];
				m_p[i] = val;
			}
		}
		return *this;
	}
	
	long size() const { return m_n; }
	long capacity() const { return m_cap; }

	T *ptr() { return m_p; }
	const T *ptr() const { return m_p; }
	
	const mArray<T>& operator=(const mArray<T> &r) {
		if (m_cap >= r.m_n) {
			m_n = r.m_n;
			copy(r.m_n,r.m_p);
		}
		else {
			// nuke local mem, spawn new mem and copy data
			nuke();
			spawn(r.m_n,r.m_n);
			copy(r.m_n,r.m_p);
		}
		return *this;
	}

	friend ostream& operator<< <>(ostream &os,const mArray<T>& m);
	
protected:
	T *m_p;
	long m_n;
	long m_cap;
};

template <class T>
ostream& operator<<(ostream &os,const mArray<T>& m) {
	long i;
	for (i=0;i < m.size();i++) {
		if (i) os << "\t" << m[i];
		else os << m[i];
	}
	return os;
}

// concatenate arrays together, or flatten
template <class T>
mArray<T> cat(const mArray< mArray<T> > &arrs) {
	long out=0,i,j;
	for(i=0;i < arrs.size();i++) {
		out += arrs[i].size();
	}

	mArray<T> fin(out);

	long cind=0;
	for(i=0;i < arrs.size();i++) {
	    const mArray<T>& m = arrs[i];
		for (j=0;j < m.size();j++) {
			fin[cind++] = m[j];
		}
	}
	return fin;
}

template <class T>
mArray<T> cat(long n,...) {
	long out=0,i,j;
	mArray< mArray<T> > arrs(n);
	va_list a;
	va_start(a,n);
	for(i=0;i < n;i++) {
		arrs[i] = *(mArray<T> *)va_arg( a, vp);
	}
	va_end(a);
	return cat<T>(arrs);
}

#endif
