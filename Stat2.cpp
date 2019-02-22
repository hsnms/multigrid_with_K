#include <math.h>
double Stat2 (double **u,int n)
{
	double zero;
	int i,j;
	zero=0.0;
	for (i=2;i<=n-1;i++)
		for (j=2;j<=n-1;j++)
	zero=zero+u[i+1][j]+u[i-1][j]+u[i][j+1] +u[i][j-1]-4.0*u[i][j];

	return zero;
}