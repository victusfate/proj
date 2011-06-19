#include <stdarg.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

#include "SimpleRNG.h"
#include "RunTime.h"

using namespace std;

#define DEBUG_INFO 

int main(int argc, char *argv[])
{
	if (argc != 2) {
		cout << argv[0] << " ncalls\n";
		exit(-1);
	}
	SimpleRNG rng;
	long ncalls = atol(argv[1]),i;
	double *data = new double[ncalls];
	double var=0,mean=0;
	
	RunTime t1;
	for (i=0;i < ncalls;i++) {
		data[i] = rng.GetUniform();
#ifdef DEBUG_INFO
		mean += data[i];
		var += data[i]*data[i];
#endif
	}

#ifdef DEBUG_INFO
	mean /= ncalls;
	var = (1.0/ncalls)*var - mean*mean;
#endif	
	cout << "rng get uniform time " << t1 << " mean " << mean << " stddev " << sqrt(var) << endl;

	var=0,mean=0;
	RunTime t2;
	for (i=0;i < ncalls;i++) {
		data[i] = (double)(rand()/(double)RAND_MAX);
#ifdef DEBUG_INFO
		mean += data[i];
		var += data[i]*data[i];
#endif
	}

#ifdef DEBUG_INFO
	mean /= ncalls;
	var = (1.0/ncalls)*var - mean*mean;
#endif	
	cout << "rand() get uniform time " << t2 << " mean " << mean << " stddev " << sqrt(var) << endl;

	double gmean=0,gsigma=1;

	var=0,mean=0;
	RunTime t3;
	for (i=0;i < ncalls;i++) {
		long j,CLT = 12;
		double rval = 0;
		for (j=0;j < CLT;j++) {
			rval += (double)rand()/(double)RAND_MAX;
		}
		rval -= (double)CLT/2.0;
		data[i] = rval;
//		rval *= sqrt(12/CLT); CLT is 12
#ifdef DEBUG_INFO
		mean += data[i];
		var += data[i]*data[i];
#endif
	}

#ifdef DEBUG_INFO
	mean /= ncalls;
	var = (1.0/ncalls)*var - mean*mean;
#endif	
	cout << "generated normal " << t3 << " mean " << mean << " stddev " << sqrt(var) << endl;

	var=0,mean=0;
	RunTime t4;
	for (i=0;i < ncalls;i++) {
 		data[i] = rng.GetNormal(gmean,gsigma);
#ifdef DEBUG_INFO
		mean += data[i];
		var += data[i]*data[i];
#endif
	}

#ifdef DEBUG_INFO
	mean /= ncalls;
	var = (1.0/ncalls)*var - mean*mean;
#endif	
	cout << "rng Normal time " << t4 << " mean " << mean << " stddev " << sqrt(var) << endl;

	var=0,mean=0;
	RunTime t5;
	for (i=0;i < ncalls;i++) {
		double temp = data[(long)(rng.GetUniform()*ncalls)];
#ifdef DEBUG_INFO
		mean += data[i];
		var += data[i]*data[i];
#endif
	}

#ifdef DEBUG_INFO
	mean /= ncalls;
	var = (1.0/ncalls)*var - mean*mean;
#endif	
	cout << "rng stored normal accessed with uniform " << t5 << " mean " << mean << " stddev " << sqrt(var) << endl;


	
	
	cout << endl;
	return 1;
}