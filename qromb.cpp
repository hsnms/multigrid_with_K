#include <math.h> 
#include "Header11.h"
#include "Header5.h"
#define EPS 1.0e-6 
#define JMAX 20 
#define JMAXP (JMAX+1) 
#define K 5
float qromb(float **f, float a, float b)
{
		void polint(float xa[], float ya[], int n, float x, float *y, float *dy); 
		float ss,dss; 
		float s[JMAXP],h[JMAXP+1]; 
		int j;
		h[1]=1.0; 
		for (j=1;j<=JMAX;j++) 
		{ 
			s[j]=trapzd(f[],a,b,j); 
			if (j >= K) 
			{ 
				polint(&h[j-K],&s[j-K],K,0.0,&ss,&dss); 
				if (fabs(dss) <= EPS*fabs(ss)) return ss; 
			} 
			h[j+1]=0.25*h[j]; 
		} 
		nrerror2("Too many steps in routine qromb");
		return 0.0; 
}