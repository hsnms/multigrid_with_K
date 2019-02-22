#include <stdio.h>
double trapzd(double *g, int n)
{
		int i;
		double h;
		double sum;
		sum=0.0;
		h=1.0/(n-1); 
		for (i=1;i<=n;i++)
			sum=sum+g[i]*h;
		sum=sum-0.5*h*(g[1]+g[n]);
		
		return sum;
}