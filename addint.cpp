#include <stdio.h>
#include "Header1.h"
#include "Header2.h"
void addint(double **uf, double **uc, double **res, int nf)
{ 
	void interp1(double **uf, double **uc, int nf); 
	int i,j;
	interp1(res,uc,nf); 
	for (j=1;j<=nf;j++) 
		for (i=1;i<=nf;i++) 
			uf[i][j] += res[i][j];
}