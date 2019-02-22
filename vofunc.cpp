#include <math.h>
void vofunc (double *q, double *vol,int n)
{
	int j;
	for (j=1;j<=n;j++)
		vol[j]=pow(q[j],2);
}