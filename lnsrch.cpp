#include <math.h>
#include "Header111.h"
#include "Header222.h"
#include "Header333.h"
#include "Header444.h"
#define ALF 1.0e-4 
#define TOLX 1.0e-7 
void lnsrch(int n, int k, float xold[], float fold, float g[], float p[], float x[], float *f, float stpmax, int *check, float *fvec, double m, int a)
	{
		int i; 
		float a1,alam,alam2,alamin,b,disc,f2,rhs1,rhs2,slope,sum,temp, test,tmplam;
		*check=0; 
		for (sum=0.0,i=1;i<=k;i++) 
			sum += p[i]*p[i]; 
		sum=sqrt(sum); 
		if (sum > stpmax) 
			for (i=1;i<=k;i++) 
				p[i] *= stpmax/sum;
		for (slope=0.0,i=1;i<=k;i++) 
			slope += g[i]*p[i]; 
		if (slope >= 0.0) nrerror3("Roundoff problem in lnsrch."); 
		test=0.0;
		for (i=1;i<=k;i++) 
		{
			temp=fabs(p[i])/FMAX(fabs(xold[i]),1.0); 
			if (temp > test) 
				test=temp;
		} 
		alamin=TOLX/test; 
		alam=1.0; 
		for (;;) 
		{ 
			for (i=1;i<=k;i++) 
				x[i]=xold[i]+alam*p[i];
			vecfunc(n,k,x,fvec,m,a);
			*f=fmin(k,fvec); 
			if (alam < alamin) 
			{ 
				for (i=1;i<=k;i++) 
					x[i]=xold[i]; 
				*check=1; 
				return; 
			} 
			else if (*f <= fold+ALF*alam*slope) 
				return; 
			else 
			{ 
				if (alam == 1.0) 
					tmplam = -slope/(2.0*(*f-fold-slope)); 
				else { 
					rhs1 = *f-fold-alam*slope; 
					rhs2=f2-fold-alam2*slope; 
					a1=(rhs1/(alam*alam)-rhs2/(alam2*alam2))/(alam-alam2); 
					b=(-alam2*rhs1/(alam*alam)+alam*rhs2/(alam2*alam2))/(alam-alam2); 
					if (a1 == 0.0) 
						tmplam = -slope/(2.0*b);
					else { disc=b*b-3.0*a1*slope; 
					if (disc < 0.0) 
						tmplam=0.5*alam; 
					else if (b <= 0.0) 
						tmplam=(-b+sqrt(disc))/(3.0*a1); 
					else 
						tmplam=-slope/(b+sqrt(disc)); 
					}
					if (tmplam > 0.5*alam) 
						tmplam=0.5*alam; 
				} 
			} 
			alam2=alam; 
			f2 = *f; 
			alam=FMAX(tmplam,0.1*alam); 
		} 
}