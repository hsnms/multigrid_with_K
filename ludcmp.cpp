#include <math.h> 
#include "Header111.h" 
#include "Header222.h" 
#define TINY 1.0e-20;
void ludcmp(float **a, int k, int *indx, float *d)
	{
		int i,imax,j,k1; 
		float big,dum,sum,temp; 
		float *vv; 
		vv=vector(1,k); 
		*d=1.0;
		for (i=1;i<=k;i++) 
		{ 
			big=0.0;
			for (j=1;j<=k;j++) 
				if ((temp=fabs(a[i][j])) > big) 
					big=temp; 
			if (big == 0.0) 
				nrerror3("Singular matrix in routine ludcmp");  
			vv[i]=1.0/big; 
		} 
		for (j=1;j<=k;j++) 
		{ 
			for (i=1;i<j;i++) 
			{ 
				sum=a[i][j]; 
				for (k1=1;k1<i;k1++) 
					sum -= a[i][k1]*a[k1][j]; 
				a[i][j]=sum; 
			} 
			big=0.0;
			for (i=j;i<=k;i++) 
			{ 
				sum=a[i][j]; 
				for (k1=1;k1<j;k1++)
					sum -= a[i][k1]*a[k1][j]; 
				a[i][j]=sum; 
				if ( (dum=vv[i]*fabs(sum)) >= big) 
				{
					big=dum; 
					imax=i; 
				}
			} 
			if (j != imax) 
			{ 
				for (k1=1;k1<=k;k1++) 
				{ 
					dum=a[imax][k1]; 
					a[imax][k1]=a[j][k1]; 
					a[j][k1]=dum; 
				} 
				*d = -(*d);  
				vv[imax]=vv[j];
			} 
			indx[j]=imax; 
			if (a[j][j] == 0.0)
				a[j][j]=TINY;  
			if (j != k) 
			{ 
				dum=1.0/(a[j][j]); 
				for (i=j+1;i<=k;i++) 
					a[i][j] *= dum; 
			} 
		} free_vector(vv,1,k);
}