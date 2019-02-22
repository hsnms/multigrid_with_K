#include <math.h>
#include <stdio.h>
#define Pi 3.141592653589793
#define S 0.00000000000001
double Stat (double **u,int n)
{
	double zero,v1,v2,v4,v5,s;
	int i,j,k1,k2;
	zero=0.0;
	
	

	
	/*s=0.0;i=44;
		for (j=2;j<=n-1;j++)
		{
			v1=(u[i][j+1]-u[i][j]);printf("v1=%f\t",v1);
			v2=(u[i][j]-u[i][j-1]);printf("v2=%f\t",v2);
			v4=(u[i+1][j]-u[i][j]);printf("v4=%f\t",v4);
			v5=(u[i][j]-u[i-1][j]);printf("v5=%f\n",v5);
			 
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
								 
			s=2.0*pow(1.0*(i-1),2)*(0.25*16*(v1-v2)+v4-v5)+1.0*(i-1)*(v4+v5)-sin(2.0*u[i][j]);
			printf("--v1=%f\t",v1);
		  printf("v2=%f\t",v2);
			printf("v4=%f\t",v4);
			printf("v5=%f--\t",v5);printf("s[%d]=%f\n",j,s);zero=zero+s;

			
		}*/
	zero=0.0;
	for (i=2;i<=n-1;i++)
	{s=0.0;
		for (j=2;j<=n-1;j++)
		{
			v1=(u[i][j+1]-u[i][j]);
			v2=(u[i][j]-u[i][j-1]);
			v4=(u[i+1][j]-u[i][j]);
			v5=(u[i][j]-u[i-1][j]);
			  
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
						if (v5>Pi/2+S)
							v5=v5-Pi;
						if (v5<-1.0*Pi/2-S)
							v5=v5+Pi;
								 
			s=s+2.0*pow(1.0*(i-1),2)*(0.25*16*(v1-v2)+v4-v5)+1.0*(i-1)*(v4+v5)-sin(2.0*u[i][j]);
			

			
		}/*printf("s[%d]=%f\n",i,s);*/
		zero=zero+s;
	}



		for (i=2;i<=n-1;i++)
	{
			v1=u[i][3]-u[i][2];
		    v2=u[i][2]-u[i][1];
			v4=u[i+1][1]-u[i][1];
			v5=u[i][1]-u[i-1][1];
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
						if (v5>Pi/2+S)
							v5=v5-Pi;
						if (v5<-1.0*Pi/2-S)
							v5=v5+Pi;
		zero=zero+2.0*pow(1.0*(i-1),2)*(0.25*16*(v1-v2)+v4-v5)+1.0*(i-1)*(v4+v5)-sin(2.0*u[i][1]);

	}
	for (i=2;i<=n-1;i++)
	{
			v1=u[i][n]-u[i][n-1];
		    v2=u[i][n-1]-u[i][n-2];
			v4=u[i+1][n]-u[i][n];
			v5=u[i][n]-u[i-1][n];
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
						if (v5>Pi/2+S)
							v5=v5-Pi;
						if (v5<-1.0*Pi/2-S)
							v5=v5+Pi;
		zero=zero+2.0*pow(1.0*(i-1),2)*(0.25*16*(v1-v2)+v4-v5)+1.0*(i-1)*(v4+v5)-sin(2.0*u[i][n]);

	}
	for (j=2;j<=n-1;j++)
	{
		    v1=u[1][j+1]-u[1][j];
		    v2=u[1][j]-u[1][j-1];
			v4=u[3][j]-u[2][j];
			v5=u[2][j]-u[1][j];
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
						if (v5>Pi/2+S)
							v5=v5-Pi;
						if (v5<-1.0*Pi/2-S)
							v5=v5+Pi;

		zero=zero-sin(2.0*u[1][j]);
	}
	for (j=2;j<=n-1;j++)
	{
		    v1=(u[n][j+1]-u[n][j]);
		    v2=(u[n][j]-u[n][j-1]);
			v4=(u[n][j]-u[n-1][j]);
			v5=(u[n-1][j]-u[n-2][j]);
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
						if (v5>Pi/2+S)
							v5=v5-Pi;
						if (v5<-1.0*Pi/2-S)
							v5=v5+Pi;

						 /*printf("\n--v1=%f\t",v1);
		  printf("v2=%f\t",v2);
			printf("v4=%f\t",v4);
			printf("v5=%f--\t",v5);
		s=2.0*pow(1.0*(n-1),2)*(0.25*16*(v1-v2)+v4-v5)+1.0*(n-1)*(v4+v5)-sin(2.0*u[n][j]); printf("s[%d]=%f\n",j,s);zero=zero+s;*/
	}
	zero=zero-sin(2.0*u[1][1]);
	zero=zero-sin(2.0*u[1][n]);
	       v1=u[n][3]-u[n][2];
		    v2=u[n][2]-u[n][1];
			v4=u[n][1]-u[n-1][1];
			v5=u[n-1][1]-u[n-2][1];
	zero=zero+2.0*pow(1.0*(n-1),2)*(0.25*16*(v1-v2)+v4-v5)+1.0*(n-1)*(v4+v5)-sin(2.0*u[n][1]);
	        v1=u[n][n]-u[n][n-1];
		    v2=u[n][n-1]-u[n][n-2];
			v4=u[n][n]-u[n-1][n];
			v5=u[n-1][n]-u[n-2][n];
	zero=zero+2.0*pow(1.0*(n-1),2)*(0.25*16*(v1-v2)+v4-v5)+1.0*(n-1)*(v4+v5)-sin(2.0*u[n][n]);
	return zero;
}