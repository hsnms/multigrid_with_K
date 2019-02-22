#include <math.h> 
#include <stdio.h>
#include "Header11.h"
#define MAXIT 100 
double rtsafe( double x1, double x2, double xacc, double H, double h,double *L,int n,double **u,double *q,int j) 

{ 
	double df,dx,dxold,f,fh,fl; 
	double temp,xh,xl,rts;
	int i;
	void fanddf (double *f,double *df,double **u, double *q, double H, double h,double *L,int n,int j);

q[j]=x1; fanddf (&fl,&df,u,q,H,h,L,n,j);
/*if (fl>0.0)
{
	x2=x1+0.1;
q[j]=x2; fanddf (&fh,&df,u,q,H,h,La,n,j);
while (fh>0.0)
{
	x2=x1+0.1;
q[j]=x2; fanddf (&fh,&df,u,q,H,h,La,n,j);
}
}*/q[j]=x2; fanddf (&fh,&df,u,q,H,h,L,n,j);
if ((fl > 0.0 && fh > 0.0) || (fl < 0.0 && fh < 0.0)) 
	{ printf("fl=%f\nfh=%f\nj=%d\n",fl,fh,j);
		nrerror2("Root must be bracketed in rtsafe");
}

if (fl == 0.0) return x1; 
if (fh == 0.0) return x2; 
if (fl < 0.0)
{
	xl=x1; xh=x2; 
} 
else 
{ 
	xh=x1; 
	xl=x2; 
} 
rts=0.5*(x1+x2); 
dxold=fabs(x2-x1); 
dx=dxold; 
q[j]=rts;fanddf (&f,&df,u,q,H,h,L,n,j);
for (i=1;i<=MAXIT;i++) 
{
	if ((((rts-xh)*df-f)*((rts-xl)*df-f) > 0.0)  || (fabs(2.0*f) > fabs(dxold*df))) 
	{ 
		dxold=dx; 
		dx=0.5*(xh-xl); 
		rts=xl+dx; 
		if (xl == rts) return rts;
	}
	else 
	{ 
		dxold=dx;
		dx=f/df; 
		temp=rts; 
		rts -= dx; 
		if (temp == rts) return rts; 
	} 
	if (fabs(dx) < xacc) return rts; 
q[j]=rts;fanddf (&f,&df,u,q,H,h,L,n,j);
	if (f < 0.0) 
		xl=rts;
	else xh=rts;
} 
nrerror2("Maximum number of iterations exceeded in rtsafe"); 
return 0.0; 
}
