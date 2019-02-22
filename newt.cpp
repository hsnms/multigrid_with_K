#include <math.h> 
#include "Header111.h" 
#include "Header222.h" 
#include "Header333.h" 
#include "Header444.h"
#define MAXITS 200 
#define TOLF 1.0e-4 
#define TOLMIN 1.0e-6 
#define TOLX 1.0e-7 
#define STPMX 100.0
#define FREERETURN {free_vector(fvec,1,n);free_vector(xold,1,n);free_vector(p,1,n);free_vector(g,1,n);free_ivector(indx,1,n);free_matrix(fjac,1,n,1,n);return;}
void newt(int n, float x[], int k, int *check,double m, int a)
	{
		int i,its,j,*indx; 
		float d,den,f,fold,stpmax,sum,temp,test,**fjac,*g,*p,*xold,*fvec;
		indx=ivector(1,k); 
		fjac=matrix(1,k,1,k); 
		g=vector(1,k); 
		p=vector(1,k); 
		xold=vector(1,k); 
		fvec=vector(1,k); 
		vecfunc(n,k,x,fvec,m,a);
		f=fmin(k,fvec); 
		test=0.0; 
		for (i=1;i<=k;i++) 
			if (fabs(fvec[i]) > test) 
				test=fabs(fvec[i]); 
		if (test < 0.01*TOLF) 
		{ 
			*check=0; 
			FREERETURN 
		} 
		for (sum=0.0,i=1;i<=k;i++) 
			sum += SQR(x[i]); 
		stpmax=STPMX*FMAX(sqrt(sum),(float)k); 
		for (its=1;its<=MAXITS;its++) 
		{ 
			fdjac(n,k,x,fvec,fjac,m,a); 
			for (i=1;i<=k;i++)
			{ 
				for (sum=0.0,j=1;j<=k;j++) 
					sum += fjac[j][i]*fvec[j]; 
				g[i]=sum; 
			} 
			for (i=1;i<=k;i++) 
				xold[i]=x[i]; 
			fold=f;
			for (i=1;i<=k;i++) 
				p[i] = -fvec[i]; 
			ludcmp(fjac,k,indx,&d); 
			lubksb(fjac,k,indx,p); 
			lnsrch(n,k,xold,fold,g,p,x,&f,stpmax,check,fvec,m,a); 
			test=0.0; 
			for (i=1;i<=k;i++) 
				if (fabs(fvec[i]) > test)
					test=fabs(fvec[i]); 
			if (test < TOLF) 
			{ 
				*check=0; 
				FREERETURN 
			} 
			if (*check) 
			{ 
				test=0.0; 
				den=FMAX(f,0.5*k); 
				for (i=1;i<=k;i++) 
				{ 
					temp=fabs(g[i])*FMAX(fabs(x[i]),1.0)/den;
					if (temp > test) 
						test=temp;
				} 
				*check=(test < TOLMIN ? 1 : 0); 
				FREERETURN
			} 
			test=0.0;  
			for (i=1;i<=k;i++)
			{ 
				temp=(fabs(x[i]-xold[i]))/FMAX(fabs(x[i]),1.0); 
				if (temp > test) 
					test=temp; 
			} 
			if (test < TOLX)
				FREERETURN
		} 
		nrerror3("MAXITS exceeded in newt");
}