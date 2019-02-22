#include <stdio.h>
#define Up 1.0;
#define Down 1.0;
#define Left 1.0;
#define Right 1.0;
void interp(double **uf, double **uc, int nf) 
{ 
	int ic,iif,jc,jf,nc,i,j; 
	nc=nf/2+1; 
	for (jc=1,jf=1;jc<=nc;jc++,jf+=2)
		for (ic=1;ic<=nc;ic++) 
			uf[2*ic-1][jf]=uc[ic][jc]; 
	for (jf=1;jf<=nf;jf+=2) 
		for (iif=2;iif<nf;iif+=2) 
			uf[iif][jf]=0.5*(uf[iif+1][jf]+uf[iif-1][jf]);
	for (jf=2;jf<nf;jf+=2)
		for (iif=1;iif <= nf;iif++) 
			uf[iif][jf]=0.5*(uf[iif][jf+1]+uf[iif][jf-1]);
	for (i=2;i<=nf-1;i++)
		uf[i][1]=Up;
	for (i=2;i<=nf-1;i++)
		uf[i][nf]=Down;
	for (j=1;j<=nf;j++)
		uf[1][j]=Left;
	for (j=1;j<=nf;j++)
		uf[nf][j]=Right; /*change*/
}