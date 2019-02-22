#include <stdio.h>
#include <math.h>
#define Pi 3.141592653589793
#define Up 1.570796326794897
#define Down 1.570796326794897
/*#define Left -1.57;*/
#define Right 1.570796326794897
#define S 0.00000000000001
void relax2(double **u, double **rhs, int n, double m,int a,double *q,double K) 
{ 
	int i,ipass,isw,j,jsw=1; 
	double foh2,h,h2i,res,v1,v2,v3,v4,v5,v6,v7,H,v8,v9;
	H=1.0;
	h=1.0/(n-1); 
	/*for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
		{
			if (u[i][j]<0.0)
				u[i][j]=0.0;
			
			
			if (u[i][j]>Pi)
				u[i][j]=Pi;
			
		}*/
	for (i=1;i<=n;i++)
		u[i][1]=Down+0.5*m*Pi;
	for (i=1;i<=n;i++)
		u[i][n]=Up-0.5*m*Pi;

	for (j=2;j<=n-1;j++)
		u[n][j]=Right+(q[j+1]-q[j-1])*1.0/(2.0*H*h);

	for (j=2;j<=n-1;j++)
	{
		v3=-2.0*K*cos(2.0*u[1][j]);
		res=-K*sin(2.0*u[1][j])-rhs[1][j];
		u[1][j]-= res/v3;
	} //2.18
	for (ipass=1;ipass<=2;ipass++,jsw=3-jsw) 
	{ 
		isw=jsw; 
		for (j=n-1;j>=2;j--,isw=3-isw) 
		{ 
			for (i=isw+1;i<n;i+=2) 
			{ 
				
						v1=u[i][j+1]-u[i][j];
						v2=u[i][j]-u[i][j-1];
						v4=u[i+1][j]-u[i][j];
						v5=u[i][j]-u[i-1][j];
						v6=u[i+1][j+1]-u[i-1][j+1];
						v7=u[i-1][j-1]-u[i+1][j-1];
		                         	v8=q[j+1]-q[j];
						v9=q[j]-q[j-1];//2.16
						//	v3=-4.0*pow(1.0*(i-1)*q[j]/H,2)-2.0*(2.0*pow(1.0*(i-1),2)+0.5*pow(1.0*(i-1)*(q[j+1]-q[j-1])/H,2)*pow(1.0*(i-1),2))-2.0*cos(2.0*u[i][j]); //2.16
						
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
						if (v6>Pi/2+S)
							v6=v6-Pi;
						if (v6<-1.0*Pi/2-S)
							v6=v6+Pi;
						if (v7>Pi/2+S)
							v7=v7-Pi;
						if (v7<-1.0*Pi/2-S)
							v7=v7+Pi;

				
						//	res=2.0*pow(1.0*(i-1)*q[j]/H,2)*(v1-v2)+(2.0*pow(1.0*(i-1),2)+0.5*pow(1.0*(i-1)*(q[j+1]-q[j-1])/H,2)*pow(1.0*(i-1),2))*(v4-v5)+(1.0*(i-1)-pow(1.0*(i-1),3)*q[j]*(q[j+1]+q[j-1]-2.0*q[j])/pow(H,2)+0.5*pow(1.0*(i-1),3)*pow(q[j+1]-q[j-1],2)/pow(H,2))*(v4+v5)-(0.5*pow(1.0*(i-1),3)*q[j]*(q[j+1]-q[j-1])/pow(H,2))*(v6+v7)-sin(2.0*u[i][j])-rhs[i][j]; //2.16

							res=K*sin(2.0*u[i][j])-(K-1.0)*0.25*sin(2.0*u[i][j])*pow((i-1)*q[j]*(v1+v2),2)+(K-1.0)*(sin(2.0*u[i][j])*pow(1.0*(i-1),2)-sin(2.0*u[i][j])*0.25*pow(1.0*(i-1),4)*pow(v8+v9,2)-cos(2.0*u[i][j])*pow(1.0*(i-1),3)*(v8+v9))*0.25*pow(v4+v5,2)
				+(K-1.0)*(0.5*(v8+v9)*q[j]*sin(2.0*u[i][j])*pow(1.0*(i-1),3)+q[j]*cos(2.0*u[i][j])*pow(1.0*(i-1),2))*0.5*(v4+v5)*(v1+v2)+(-(K*pow(cos(u[i][j]),2)+1.0*pow(sin(u[i][j]),2))*(1.0*(i-1)+pow(1.0*(i-1),3)*(0.5*pow(v8+v9,2)-(v8-v9)*q[j]))-(K-1.0)*pow(1.0*(i-1),2)*0.75*(v8+v9))*(v4+v5)
				+(K-1.0)*sin(2.0*u[i][j])*(i-1)*q[j]*0.5*(v1+v2)-2.0*((K*pow(cos(u[i][j]),2)+1.0*pow(sin(u[i][j]),2))*pow(1.0*(i-1),2)+(K*pow(sin(u[i][j]),2)+1.0*pow(cos(u[i][j]),2))*pow(1.0*(i-1),4)*0.25*pow(v8+v9,2)+(K-1)*pow(1.0*(i-1),3)*0.5*(v8+v9)*sin(2.0*u[i][j]))*(v4-v5)
							  -2.0*(K*pow(sin(u[i][j]),2)+1.0*pow(cos(u[i][j]),2))*pow(1.0*(i-1)*q[j],2)*(v1-v2)+((K*pow(sin(u[i][j]),2)+1.0*pow(cos(u[i][j]),2))*pow(1.0*(i-1),3)*(v8+v9)*q[j]+(K-1.0)*q[j]*pow(1.0*(i-1),2)*sin(2.0*u[i][j]))*0.5*(v6+v7)+rhs[i][j]; //2.16

								v3=2.0*K*cos(2.0*u[i][j])-0.5*(K-1.0)*pow(q[j]*(i-1)*(v1+v2),2)*cos(2.0*u[i][j])+(K-1.0)*(2.0*cos(2.0*u[i][j])*pow(1.0*(i-1),2)-0.5*pow(1.0*(i-1),4)*pow(v8+v9,2)*cos(2.0*u[i][j])+2.0*pow(1.0*(i-1),3)*(v8+v9)*sin(2.0*u[i][j]))*0.25*pow(v4+v5,2)
					+(K-1.0)*(pow(1.0*(i-1),3)*(v8+v9)*q[j]*cos(2.0*u[i][j])-2.0*(i-1)*(i-1)*q[j]*sin(2.0*u[i][j]))*0.5*(v1+v2)*(v4+v5)+(K*sin(2.0*u[i][j])-sin(2.0*u[i][j]))*(1.0*(i-1)+pow(1.0*(i-1),3)*(0.5*pow(v8+v9,2)-(v8-v9)*q[j]))*(v4+v5)
					+(K-1.0)*cos(2.0*u[i][j])*(i-1)*q[j]*(v1+v2)-2.0*(-(K*sin(2.0*u[i][j])-sin(2.0*u[i][j]))*pow(1.0*(i-1),2)+(K*sin(2.0*u[i][j])-sin(2.0*u[i][j]))*pow(1.0*(i-1),4)*0.25*pow(v8+v9,2)+(K-1.0)*pow(1.0*(i-1),3)*(v8+v9)*cos(2.0*u[i][j]))*(v4-v5)
					+4.0*((K*pow(cos(1.0*u[i][j]),2)+1.0*pow(sin(1.0*u[i][j]),2))*pow(1.0*(i-1),2)+(K*pow(sin(1.0*u[i][j]),2)+1.0*pow(cos(1.0*u[i][j]),2))*pow(1.0*(i-1),4)*0.25*pow(v8+v9,2)+(K-1.0)*pow(1.0*(i-1),3)*0.5*(v8+v9)*sin(2.0*u[i][j]))
								  -2.0*(K*sin(2.0*u[i][j])-sin(2.0*u[i][j]))*pow(1.0*(i-1)*q[j],2)*(v1-v2)+4.0*(K*pow(sin(1.0*u[i][j]),2)+1.0*pow(cos(1.0*u[i][j]),2))*pow(1.0*(i-1)*q[j],2)+((K*sin(2.0*u[i][j])-sin(2.0*u[i][j]))*pow(1.0*(i-1),3)*(v8+v9)*q[j]+2.0*(K-1.0)*q[j]*pow(1.0*(i-1),2)*cos(2.0*u[i][j]))*0.5*(v6+v7);//2.16

				u[i][j] -= res/v3;
				/*if (res/v3>0.5*Pi) printf ("NONONONONOu[%d][%d]=%f\n",i,j,u[i][j]);*/

				/*if (u[i][j]>Pi)
					u[i][j]=u[i][j]+res/v3;
				if (u[i][j]<0.0)
					u[i][j]=u[i][j]+res/v3;*/
			if (u[i][j]<0.0) 
				{
					u[i][j]=0.0;
			}
			if (u[i][j]>Pi)
				{
					 u[i][j]=Pi;
					
			}
			
		} 
	}
}
}
