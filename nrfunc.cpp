#include <math.h>
#include "Header22.h"
/*#define EPI 1.0e-7*/ 
#define Pi 3.141592653589793
void **nrfunc(double **f, double **u, int n)
{
	double h,v1,v2,v4,v5;
	int i,j;
	h=1.0/(n-1); 	

	for(j=1;j<=n;j++)
		for(i=1;i<=n;i++)
			f[i][j]=0.0;


	for (j=2;j<=n-1;j++)
	{
		for (i=2;i<=n-1;i++)
		{
			v1=u[i][j+1]-u[i][j];
		    v2=u[i][j]-u[i][j-1];
			v4=u[i+1][j]-u[i][j];
			v5=u[i][j]-u[i-1][j];
				        if (v1>Pi/2)
						{v1=v1-Pi;}
						if (v1<-1.0*Pi/2)
							v1=v1+Pi;
						if (v2>Pi/2)
							v2=v2-Pi;
						if (v2<-1.0*Pi/2)
							v2=v2+Pi;
						if (v4>Pi/2)
							v4=v4-Pi;
						if (v4<-1.0*Pi/2)
							v4=v4+Pi;
						if (v5>Pi/2)
							v5=v5-Pi;
						if (v5<-1.0*Pi/2)
							v5=v5+Pi;
			f[i][j]=pow(sin(u[i][j]),2)/(1.0*(i-1)*h)+sin(2.0*u[i][j])*(v4+v5)/(2.0*h)-2.0*pow(sin(u[i][j]),2)*4.0*0.5*(v1+v2)/(2.0*h)+(1.0*(i-1)*h)*pow((v4+v5)/(2.0*h),2)+(1.0*(i-1)*h)*16.0*0.25*pow((v1+v2)/(2.0*h),2);
		}
	}
	for (i=2;i<=n-1;i++)
	{
			v1=u[i][2]-u[i][1];
		    v2=u[i][2]-u[i][1];
			v4=u[i+1][1]-u[i][1];
			v5=u[i][1]-u[i-1][1];
			            if (v1>Pi/2)
						{v1=v1-Pi;}
						if (v1<-1.0*Pi/2)
							v1=v1+Pi;
						if (v2>Pi/2)
							v2=v2-Pi;
						if (v2<-1.0*Pi/2)
							v2=v2+Pi;
						if (v4>Pi/2)
							v4=v4-Pi;
						if (v4<-1.0*Pi/2)
							v4=v4+Pi;
						if (v5>Pi/2)
							v5=v5-Pi;
						if (v5<-1.0*Pi/2)
							v5=v5+Pi;
		f[i][1]=pow(sin(u[i][1]),2)/(1.0*(i-1)*h)+sin(2.0*u[i][1])*(v4+v5)/(2.0*h)-2.0*pow(sin(u[i][1]),2)*4.0*0.5*(v1+v2)/(2.0*h)+(1.0*(i-1)*h)*pow((v4+v5)/(2.0*h),2)+(1.0*(i-1)*h)*16.0*0.25*pow((v1+v2)/(2.0*h),2);

	}
	for (i=2;i<=n-1;i++)
	{
			v1=u[i][n]-u[i][n-1];
		    v2=u[i][n]-u[i][n-1];
			v4=u[i+1][n]-u[i][n];
			v5=u[i][n]-u[i-1][n];
			            if (v1>Pi/2)
						{v1=v1-Pi;}
						if (v1<-1.0*Pi/2)
							v1=v1+Pi;
						if (v2>Pi/2)
							v2=v2-Pi;
						if (v2<-1.0*Pi/2)
							v2=v2+Pi;
						if (v4>Pi/2)
							v4=v4-Pi;
						if (v4<-1.0*Pi/2)
							v4=v4+Pi;
						if (v5>Pi/2)
							v5=v5-Pi;
						if (v5<-1.0*Pi/2)
							v5=v5+Pi;
		f[i][n]=pow(sin(u[i][n]),2)/(1.0*(i-1)*h)+sin(2.0*u[i][n])*(v4+v5)/(2.0*h)-2.0*pow(sin(u[i][n]),2)*4.0*0.5*(v1+v2)/(2.0*h)+(1.0*(i-1)*h)*pow((v4+v5)/(2.0*h),2)+(1.0*(i-1)*h)*16.0*0.25*pow((v1+v2)/(2.0*h),2);

	}
	for (j=2;j<=n-1;j++)
	{
		    v1=u[1][j+1]-u[1][j];
		    v2=u[1][j]-u[1][j-1];
			v4=u[2][j]-u[1][j];
			v5=u[2][j]-u[1][j];
				        if (v1>Pi/2)
						{v1=v1-Pi;}
						if (v1<-1.0*Pi/2)
							v1=v1+Pi;
						if (v2>Pi/2)
							v2=v2-Pi;
						if (v2<-1.0*Pi/2)
							v2=v2+Pi;
						if (v4>Pi/2)
							v4=v4-Pi;
						if (v4<-1.0*Pi/2)
							v4=v4+Pi;
						if (v5>Pi/2)
							v5=v5-Pi;
						if (v5<-1.0*Pi/2)
							v5=v5+Pi;

		f[1][j]=sin(2.0*u[1][j])*(v4+v5)/(2.0*h)-2.0*pow(sin(u[1][j]),2)*4.0*0.5*(v1+v2)/(2.0*h);
	}
	for (j=2;j<=n-1;j++)
	{
		    v1=u[n][j+1]-u[n][j];
		    v2=u[n][j]-u[n][j-1];
			v4=u[n][j]-u[n-1][j];
			v5=u[n][j]-u[n-1][j];
				        if (v1>Pi/2)
						{v1=v1-Pi;}
						if (v1<-1.0*Pi/2)
							v1=v1+Pi;
						if (v2>Pi/2)
							v2=v2-Pi;
						if (v2<-1.0*Pi/2)
							v2=v2+Pi;
						if (v4>Pi/2)
							v4=v4-Pi;
						if (v4<-1.0*Pi/2)
							v4=v4+Pi;
						if (v5>Pi/2)
							v5=v5-Pi;
						if (v5<-1.0*Pi/2)
							v5=v5+Pi;

		f[n][j]=pow(sin(u[n][j]),2)/(1.0*(n-1)*h)+sin(2.0*u[n][j])*(v4+v5)/(2.0*h)-2.0*pow(sin(u[n][j]),2)*4.0*0.5*(v1+v2)/(2.0*h)+(1.0*(n-1)*h)*pow((v4+v5)/(2.0*h),2)+(1.0*(n-1)*h)*16.0*0.25*pow((v1+v2)/(2.0*h),2);
	}
	f[1][1]=sin(2.0*u[1][1])*(u[2][1]-u[1][1])/(1.0*h)-2.0*pow(sin(u[1][1]),2)*4.0*0.5*(u[1][2]-u[1][1])/(1.0*h);
	f[1][n]=sin(2.0*u[1][n])*(u[2][n]-u[1][n])/(1.0*h)-2.0*pow(sin(u[1][n]),2)*4.0*0.5*(u[1][n]-u[1][n-1])/(1.0*h);
	f[n][1]=pow(sin(u[n][1]),2)/(1.0*(n-1)*h)+sin(2.0*u[n][1])*(u[n][1]-u[n-1][1])/(1.0*h)-2.0*pow(sin(u[n][1]),2)*4.0*0.5*(u[n][2]-u[n][1])/(1.0*h)+(1.0*(n-1)*h)*pow((u[n][1]-u[n-1][1])/(1.0*h),2)+(1.0*(n-1)*h)*16.0*0.25*pow((u[n][2]-u[n][1])/(1.0*h),2);
	f[n][n]=pow(sin(u[n][n]),2)/(1.0*(n-1)*h)+sin(2.0*u[n][n])*(u[n][n]-u[n-1][n])/(1.0*h)-2.0*pow(sin(u[n][n]),2)*4.0*0.5*(u[n][n]-u[n][n-1])/(1.0*h)+(1.0*(n-1)*h)*pow((u[n][n]-u[n-1][n])/(1.0*h),2)+(1.0*(n-1)*h)*16.0*0.25*pow((u[n][n]-u[n][n-1])/(1.0*h),2);
	return 0;
}
