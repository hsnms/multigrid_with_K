#include <stdio.h>
#include <errno.h>
#include <math.h>
#include "Header11.h"
#include "Header22.h"
#include "Header222.h"
#include "Header33.h"
#include "Header5.h"
#include "Header6.h"
#define Up 1.570796326794897
#define Down 1.570796326794897
/*#define Left -1.57;*/
#define Right 1.570796326794897
#define Pi 3.141592653589793
#define S 0.00000000000001
#define Imax 1
#define IImax 1
int main()
{
    int i,j,k,n,ncycle=1,ii,ii2,ii3;
	double **u,x[300],y[300],*q,H,h,x1,x2,xacc,R0,*vol,VO;
	void mgfas(double **u, int n,int ncycle, double m, int a,double *q,double K);
	void **nrfunc(double **f,double **u, int n);
	//	double rtsafe( double x1, double x2, double xacc, double H, double h,double *L,int n,double **u,double *q,int j);
	//	void fanddf (double *f,double *df,double **u, double *q, double H, double h,double *L,int n,int j);
	void vofunc (double *q, double *vol,int n);
	double Stat (double **u,int n);
	double result,result2,**f,zero,rev2,rev3,v1,v2,v4,La,K;
	double m; int a,b; 
	FILE *fp,*fp2,*fp3;
	n=65;La=/*-10843.421805224*/-20000.0;xacc=0.00001;
	b=50;
	//	R0=1.0;
	h=1.0/(n-1);
	H=1.0;
	//	m=-1.0;
	//	K=1.0;
	//	a=18;
		printf("R0:");
		scanf("%lf",&R0);
		printf("m:");
		scanf("%lf",&m);
	printf("K:");
	scanf("%lf",&K);
        printf ("a:");
	scanf("%d", &a);//2.18
	u=dmatrix2(1,n,1,n);
	q=dvector(1,n);
	vol=dvector(1,n);
	for (i=1;i<=n;i++)
	{
		x[i]=1.0*(i-1)*(1.0/(n-1));
	}
	for (i=1;i<=n;i++)
	{
		y[i]=1.0*(i-1)*(1.0/(n-1));
	} 
	for(i=1;i<=n;i++)
		{
			for(k=1;k<=a;k++)
			    u[i][k]=Down+0.5*m*Pi;
			for (k=1+a;k<=n;k++)
				u[i][k]=Up-0.5*m*Pi;
	    }
	for (i=1;i<=n;i++)
		u[i][1]=Down+0.5*m*Pi;
	
	for (i=1;i<=n;i++)
		u[i][n]=Up-0.5*m*Pi;

	for (j=1;j<=n;j++)
		q[j]=R0;
	
	for (j=2;j<=n-1;j++)
		u[n][j]=Right+(q[j+1]-q[j-1])*1.0/(2.0*H*h);
	
	
for (ii2=1;ii2<=IImax;ii2++)
{
  mgfas(u,n,ncycle,m,a,q,K);
		/*for (ii=1;ii<=Imax;ii++)
{
                        j=2;
	                    v1=u[n][j+1]-u[n][j];
						v2=u[n][j]-u[n][j-1];
						v4=u[n][j]-u[n-1][j];

						if (v1>Pi/2+S)
						{v1=v1-Pi;}
						if (v1<-1.0*Pi/2-S)
							v1=v1+Pi;
						if (v2>Pi/2+S)
							v2=v2-Pi;
						if (v2<-1.0*Pi/2-S)
							v2=v2+Pi;
						if (v4>Pi/2+S)
							v4=v4-Pi;
						if (v4<-1.0*Pi/2-S)
							v4=v4+Pi;
		

La=(-pow(sin(u[n][j]),2)-(sin(2.0*u[n][j])/h+pow(sin(u[n][j])/h,2)*2.0*(q[j+1]-q[j])/H)*v4+pow(sin(u[n][j]),2)*(v1+v2)/(h*H)-(pow(q[j]/h,2)+pow((q[j+1]-q[j])/(h*H),2)/pow(h,2))*pow(v4,2)-pow(q[j]*(v1+v2)/(2.0*h*H),2)+q[j]*(q[j+1]-q[j])*(v1+v2)*v4/(pow(h,3)*pow(H,2)))/pow(q[j],2);
printf("La=%f\n",La);
x1=0.0;x2=R0;
for (j=3;j<=n-1;j++)
	{q[j]=rtsafe(x1,x2, xacc, H, h,&La,n,u,q,j);
printf("q[%d]=%f\n",j,q[j]);}
vofunc (q,vol,n);
	VO=trapzd(vol, n);
	printf("volume=%f\n",VO);
	for (j=1;j<=n;j++)
		q[j]=q[j]*sqrt(pow(R0,2)/VO);
	 vofunc (q,vol,n);
	VO=trapzd(vol, n);
	printf("volume2=%f\nq[1]=%f\n",VO,q[1]);
	for (ii3=1;ii3<=1;ii3++)
	{
		x1=0.0;x2=q[1];
		j=2;
	                    v1=u[n][j+1]-u[n][j];
						v2=u[n][j]-u[n][j-1];
						v4=u[n][j]-u[n-1][j];

						if (v1>Pi/2+S)
						{v1=v1-Pi;}
						if (v1<-1.0*Pi/2-S)
							v1=v1+Pi;
						if (v2>Pi/2+S)
							v2=v2-Pi;
						if (v2<-1.0*Pi/2-S)
							v2=v2+Pi;
						if (v4>Pi/2+S)
							v4=v4-Pi;
						if (v4<-1.0*Pi/2-S)
							v4=v4+Pi;
		

La=(-pow(sin(u[n][j]),2)-(sin(2.0*u[n][j])/h+pow(sin(u[n][j])/h,2)*2.0*(q[j+1]-q[j])/H)*v4+pow(sin(u[n][j]),2)*(v1+v2)/(h*H)-(pow(q[j]/h,2)+pow((q[j+1]-q[j])/(h*H),2)/pow(h,2))*pow(v4,2)-pow(q[j]*(v1+v2)/(2.0*h*H),2)+q[j]*(q[j+1]-q[j])*(v1+v2)*v4/(pow(h,3)*pow(H,2)))/pow(q[j],2);
printf("La=%f\n",La);
for (j=3;j<=n-1;j++)
	{q[j]=rtsafe(x1,x2, xacc, H, h,&La,n,u,q,j);
printf("q[%d]=%f\n",j,q[j]);}
vofunc (q,vol,n);
	VO=trapzd(vol, n);
	printf("volume=%f\n",VO);
	for (j=1;j<=n;j++)
		q[j]=q[j]*sqrt(pow(R0,2)/VO);
	 vofunc (q,vol,n);
	VO=trapzd(vol, n);
	printf("volume2=%f\nq[1]=%f\n",VO,q[1]);
	}
	}*/
}

    


	 fp = fopen ("C:\\C\\NLPDE.txt","w");
	 fp2 = fopen ("C:\\C\\VectorField.txt","w");
	 //	 fp3 = fopen ("C:\\C\\Shape.txt","w");
    if (fp == NULL) {
        printf ("File not created okay, errno = %d\n", errno);
        return 1;
    }
	if (fp2 == NULL) {
        printf ("File 2 not created okay, errno = %d\n", errno);
        return 1;
    }
	//	if (fp3 == NULL) {
	//  printf ("File 3 not created okay, errno = %d\n", errno);
	//  return 1;
	//  }
		fprintf(fp,"{");
		for(i=1;i<=n;i++)
		{
		  //	fprintf(fp,"{%f,\t%f},\t",x[i],u[i][n/2+1]);
                 	fprintf(fp,"{%f,\t%f},\t",sin(u[i][n/2+1]),cos(u[i][n/2+1]));
          	}
		fprintf(fp,"}");
		printf("n/2=%d\n",n/2+1);


		
		/*	fprintf(fp,"{");
			for(k=1;k<=n-1;k++)
				fprintf(fp,"{%f,\t%f,\t%f},\t",x[n],y[k],u[n][k]);
			fprintf(fp,"{%f,\t%f,\t%f}\t",x[n],y[n],u[n][n]);
			fprintf(fp,"}");
			fprintf(fp,"}");*/ //2.18
		fclose (fp);
		fprintf(fp2,"{");
		for(i=1;i<=n-1;i++)
		{
			fprintf(fp2,"{");
			for(k=1;k<=n-1;k++)
				fprintf(fp2,"{%f,\t%f},\t",sin(u[i][k]),cos(u[i][k]));
			fprintf(fp2,"{%f,\t%f}\t",sin(u[i][n]),cos(u[i][n]));
			fprintf(fp2,"},");
		}
			fprintf(fp2,"{");
			for(k=1;k<=n-1;k++)
				fprintf(fp2,"{%f,\t%f},\t",sin(u[n][k]),cos(u[n][k]));
			fprintf(fp2,"{%f,\t%f}\t",sin(u[n][n]),cos(u[n][n]));
			fprintf(fp2,"}");
			fprintf(fp2,"}"); //2.18
		fclose (fp2);

		/*	fprintf(fp3,"{");
		for(j=1;j<=n-1;j++)
		{
	        
			fprintf(fp3,"{%f,\t%f},\t",y[j],q[j]);
	        
		}
		fprintf(fp3,"{%f,\t%f}\t",y[n],q[n]);
		fprintf(fp3,"}");
		fclose (fp3);*/
    printf ("File created okay\n");

    	f=dmatrix2(1,n,1,n);
	nrfunc(f,u,n);
	zero=Stat(u,n);
	result=integrat(f, n);
	
	printf("%d\t%f\t%f\tf[n][n/2]=%f\nzero=%f\n",a,m,result,f[n][n/2],zero);

	/*m=-1.0*m;
for (i=1;i<=n;i++)
	{
		x[i]=1.0*(i-1)*(1.0/(n-1));
	}
	for (i=1;i<=n;i++)
	{
		y[i]=1.0*(i-1)*(1.0/(n-1));
	} 
	for(i=1;i<=n;i++)
		{
			for(k=1;k<=a;k++)
			    u[i][k]=Down+0.5*m*Pi;
			for (k=1+a;k<=n;k++)
				u[i][k]=Up-0.5*m*Pi;
	    }
	for (i=1;i<=n;i++)
		u[i][1]=Down+0.5*m*Pi;
	
	for (i=1;i<=n;i++)
		u[i][n]=Up-0.5*m*Pi;
	for (j=2;j<=n/2;j++)
		u[n][j]=Right; 
	for (j=1+n/2;j<=n-1;j++)
		u[n][j]=Right; 
	mgfas(u,n,ncycle,m,a);
	nrfunc(f,u,n);
	zero=Stat(u,n);
	result2=integrat(f, n);
	if (result2<result)
	{
		result=result2;
		 fp = fopen ("C:\\C\\NLPDE.txt","w");
	 fp2 = fopen ("C:\\C\\VectorField.txt","w");
    if (fp == NULL) {
        printf ("File not created okay, errno = %d\n", errno);
        return 1;
    }
	if (fp2 == NULL) {
        printf ("File 2 not created okay, errno = %d\n", errno);
        return 1;
    }
		
		fprintf(fp,"{");
		for(i=1;i<=n-1;i++)
		{
			fprintf(fp,"{");
			for(k=1;k<=n-1;k++)
				fprintf(fp,"{%f,\t%f,\t%f},\t",x[i],y[k],u[i][k]);
			fprintf(fp,"{%f,\t%f,\t%f}\t",x[i],y[n],u[i][n]);
			fprintf(fp,"},");
		}
			fprintf(fp,"{");
			for(k=1;k<=n-1;k++)
				fprintf(fp,"{%f,\t%f,\t%f},\t",x[n],y[k],u[n][k]);
			fprintf(fp,"{%f,\t%f,\t%f}\t",x[n],y[n],u[n][n]);
			fprintf(fp,"}");
		fprintf(fp,"}");
		fclose (fp);
		fprintf(fp2,"{");
		for(i=1;i<=n-1;i++)
		{
			fprintf(fp2,"{");
			for(k=1;k<=n-1;k++)
				fprintf(fp2,"{%f,\t%f},\t",sin(u[i][k]),cos(u[i][k]));
			fprintf(fp2,"{%f,\t%f}\t",sin(u[i][n]),cos(u[i][n]));
			fprintf(fp2,"},");
		}
			fprintf(fp2,"{");
			for(k=1;k<=n-1;k++)
				fprintf(fp2,"{%f,\t%f},\t",sin(u[n][k]),cos(u[n][k]));
			fprintf(fp2,"{%f,\t%f}\t",sin(u[n][n]),cos(u[n][n]));
			fprintf(fp2,"}");
		fprintf(fp2,"}");
		
		fclose (fp2);
    printf ("File created okay\n");
	}
 
	printf("%d\t%f\t%f\tf[n][n/2]=%f\nzero=%f\n",a,m,result2,f[n][n/2],zero);

	for (a=3;a<=n-1;a++)
	{
		m=-1.0*m;
for (i=1;i<=n;i++)
	{
		x[i]=1.0*(i-1)*(1.0/(n-1));
	}
	for (i=1;i<=n;i++)
	{
		y[i]=1.0*(i-1)*(1.0/(n-1));
	} 
	for(i=1;i<=n;i++)
		{
			for(k=1;k<=a;k++)
			    u[i][k]=Down+0.5*m*Pi;
			for (k=1+a;k<=n;k++)
				u[i][k]=Up-0.5*m*Pi;
	    }
	for (i=1;i<=n;i++)
		u[i][1]=Down+0.5*m*Pi;
	
	for (i=1;i<=n;i++)
		u[i][n]=Up-0.5*m*Pi;
	for (j=2;j<=n/2;j++)
		u[n][j]=Right; 
	for (j=1+n/2;j<=n-1;j++)
		u[n][j]=Right; 
	mgfas(u,n,ncycle,m,a);
	nrfunc(f,u,n);
	zero=Stat(u,n);
	result2=integrat(f, n);
	if (result2<result)
	{
		result=result2;
		 fp = fopen ("C:\\C\\NLPDE.txt","w");
	 fp2 = fopen ("C:\\C\\VectorField.txt","w");
    if (fp == NULL) {
        printf ("File not created okay, errno = %d\n", errno);
        return 1;
    }
	if (fp2 == NULL) {
        printf ("File 2 not created okay, errno = %d\n", errno);
        return 1;
    }
		
		fprintf(fp,"{");
		for(i=1;i<=n-1;i++)
		{
			fprintf(fp,"{");
			for(k=1;k<=n-1;k++)
				fprintf(fp,"{%f,\t%f,\t%f},\t",x[i],y[k],u[i][k]);
			fprintf(fp,"{%f,\t%f,\t%f}\t",x[i],y[n],u[i][n]);
			fprintf(fp,"},");
		}
			fprintf(fp,"{");
			for(k=1;k<=n-1;k++)
				fprintf(fp,"{%f,\t%f,\t%f},\t",x[n],y[k],u[n][k]);
			fprintf(fp,"{%f,\t%f,\t%f}\t",x[n],y[n],u[n][n]);
			fprintf(fp,"}");
		fprintf(fp,"}");
		fclose (fp);
		fprintf(fp2,"{");
		for(i=1;i<=n-1;i++)
		{
			fprintf(fp2,"{");
			for(k=1;k<=n-1;k++)
				fprintf(fp2,"{%f,\t%f},\t",sin(u[i][k]),cos(u[i][k]));
			fprintf(fp2,"{%f,\t%f}\t",sin(u[i][n]),cos(u[i][n]));
			fprintf(fp2,"},");
		}
			fprintf(fp2,"{");
			for(k=1;k<=n-1;k++)
				fprintf(fp2,"{%f,\t%f},\t",sin(u[n][k]),cos(u[n][k]));
			fprintf(fp2,"{%f,\t%f}\t",sin(u[n][n]),cos(u[n][n]));
			fprintf(fp2,"}");
		fprintf(fp2,"}");
		
		fclose (fp2);
    printf ("File created okay\n");
	}

	printf("%d\t%f\t%f\tf[n][n/2]=%f\nzero=%f\n",a,m,result2,f[n][n/2],zero);
		m=-1.0*m;
	for (i=1;i<=n;i++)
	{
		x[i]=1.0*(i-1)*(1.0/(n-1));
	}
	for (i=1;i<=n;i++)
	{
		y[i]=1.0*(i-1)*(1.0/(n-1));
	} 
	for(i=1;i<=n;i++)
		{
			for(k=1;k<=a;k++)
			    u[i][k]=Down+0.5*m*Pi;
			for (k=1+a;k<=n;k++)
				u[i][k]=Up-0.5*m*Pi;
	    }
	for (i=1;i<=n;i++)
		u[i][1]=Down+0.5*m*Pi;
	
	for (i=1;i<=n;i++)
		u[i][n]=Up-0.5*m*Pi;
	for (j=2;j<=n/2;j++)
		u[n][j]=Right; 
	for (j=1+n/2;j<=n-1;j++)
		u[n][j]=Right; 

		mgfas(u,n,ncycle,m,a);

	nrfunc(f,u,n);
	zero=Stat(u,n);
	result2=integrat(f, n);
	if (result2<result)
	{
		result=result2;
		 fp = fopen ("C:\\C\\NLPDE.txt","w");
	 fp2 = fopen ("C:\\C\\VectorField.txt","w");
    if (fp == NULL) {
        printf ("File not created okay, errno = %d\n", errno);
        return 1;
    }
	if (fp2 == NULL) {
        printf ("File 2 not created okay, errno = %d\n", errno);
        return 1;
    }
		
		fprintf(fp,"{");
		for(i=1;i<=n-1;i++)
		{
			fprintf(fp,"{");
			for(k=1;k<=n-1;k++)
				fprintf(fp,"{%f,\t%f,\t%f},\t",x[i],y[k],u[i][k]);
			fprintf(fp,"{%f,\t%f,\t%f}\t",x[i],y[n],u[i][n]);
			fprintf(fp,"},");
		}
			fprintf(fp,"{");
			for(k=1;k<=n-1;k++)
				fprintf(fp,"{%f,\t%f,\t%f},\t",x[n],y[k],u[n][k]);
			fprintf(fp,"{%f,\t%f,\t%f}\t",x[n],y[n],u[n][n]);
			fprintf(fp,"}");
		fprintf(fp,"}");
		fclose (fp);
		fprintf(fp2,"{");
		for(i=1;i<=n-1;i++)
		{
			fprintf(fp2,"{");
			for(k=1;k<=n-1;k++)
				fprintf(fp2,"{%f,\t%f},\t",sin(u[i][k]),cos(u[i][k]));
			fprintf(fp2,"{%f,\t%f}\t",sin(u[i][n]),cos(u[i][n]));
			fprintf(fp2,"},");
		}
			fprintf(fp2,"{");
			for(k=1;k<=n-1;k++)
				fprintf(fp2,"{%f,\t%f},\t",sin(u[n][k]),cos(u[n][k]));
			fprintf(fp2,"{%f,\t%f}\t",sin(u[n][n]),cos(u[n][n]));
			fprintf(fp2,"}");
		fprintf(fp2,"}");
		
		fclose (fp2);
    printf ("File created okay\n");
	}
	
	printf("%d\t%f\t%f\tf[n][n/2]=%f\nzero=%f\n",a,m,result2,f[n][n/2],zero);
	}*/
	free_dmatrix2(f,1,n,1,n);
	free_dmatrix2(u,1,n,1,n);
	free_dvector(q,1,n);
	free_dvector(vol,1,n);
    return 0;
}
