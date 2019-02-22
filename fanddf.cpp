#include <math.h> 
#define S 0.00000000000001
#define Pi 3.141592653589793
void fanddf (double *f,double *df,double **u, double *q, double H, double h,double *L,int n,int j)
{
	double v1,v2,v4;
	

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
		*f=/*pow(sin(u[n][j]),2)+(sin(2.0*u[n][j])/h+pow(sin(u[n][j])/h,2)*(q[j+1]-q[j-1])/H)*v4-pow(sin(u[n][j]),2)*(v1+v2)/(h*H)+(pow(q[j]/h,2)+pow((q[j+1]-q[j-1])/(2.0*h*H),2)/pow(h,2))*pow(v4,2)+pow(q[j]*(v1+v2)/(2.0*h*H),2)-q[j]*(q[j+1]-q[j-1])*(v1+v2)*v4/(2.0*pow(h,3)*pow(H,2))+La*pow(q[j],2)*/
			pow(sin(u[n][j]),2)+(sin(2.0*u[n][j])/h+pow(sin(u[n][j])/h,2)*2.0*(q[j+1]-q[j])/H)*v4-pow(sin(u[n][j]),2)*(v1+v2)/(h*H)+(pow(q[j]/h,2)+pow((q[j+1]-q[j])/(h*H),2)/pow(h,2))*pow(v4,2)+pow(q[j]*(v1+v2)/(2.0*h*H),2)-q[j]*(q[j+1]-q[j])*(v1+v2)*v4/(pow(h,3)*pow(H,2))+*L*pow(q[j],2);
	
		*df=/*2.0*q[j]*pow(v4/h,2)+2.0*q[j]*pow((v1+v2)/(2.0*h*H),2)-(q[j+1]-q[j-1])*(v1+v2)*v4/(2.0*pow(h,3)*pow(H,2))+2.0*La*q[j]*/
			-v4*pow(sin(u[n][j])/h,2)*2.0/H+2.0*q[j]*pow(v4/h,2)-2.0*pow(v4,2)*pow((q[j+1]-q[j])/(h*H),2)/pow(h,2)+2.0*q[j]*pow((v1+v2)/(2.0*h*H),2)-(q[j+1]-2.0*q[j])*(v1+v2)*v4/(pow(h,3)*pow(H,2))+*L*2.0*q[j];
		
}
