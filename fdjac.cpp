#include <math.h>
#include "Header222.h"
#define EPS 1.0e-4 
void fdjac(int n,int k, float x[], float fvec[], float **df, double m, int a)
{
	int i,j; 
	float h,temp,*f;
	f=vector(1,k); 
	for (j=1;j<=k;j++) 
	{ 
		temp=x[j]; 
		h=EPS*fabs(temp); 
		if (h == 0.0) 
			h=EPS; 
		x[j]=temp+h;  
		h=x[j]-temp; 
		vecfunc(n,k,x,f,m,a); 
		x[j]=temp; 
		for (i=1;i<=k;i++) 
			df[i][j]=(f[i]-fvec[i])/h;
	} 
	free_vector(f,1,k);
}