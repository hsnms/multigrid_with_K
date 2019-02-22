#include "Header222.h"
#include "Header5.h"
double integrat (double **f, int n)
{
	int i;
	double *k,integ;
	k=dvector(1,n);
	for (i=1;i<=n;i++)
	{
		k[i]=trapzd(f[i],n);
	}
	integ=trapzd(k,n);
	free_dvector(k,1,n);
	return integ;
}
