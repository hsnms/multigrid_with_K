#include <math.h>
#include "Header111.h"
#include "Header333.h"
float fmin(int k, float *fvec)  
{ 
	int i; float sum;
    
	for (sum=0.0,i=1;i<=k;i++) 
		sum += SQR(fvec[i]); 
	return 0.5*sum;
}