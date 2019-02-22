#include <stdio.h>
#define Up 1.570796326794897
#define Down 1.570796326794897
#define Right 1.570796326794897
#define Pi 3.141592653589793
void fill02(double **u, int n, double m, int a) 
	 
{ 
	int i,j; 
  
	for(i=1;i<=3;i++)
		u[i][1]=Down+0.5*m*Pi;
	for (i=1;i<=3;i++)
	{
		u[i][3]=Up-0.5*m*Pi;
	}
	u[1][2]=Up-0.5*m*Pi;
	//	u[2][2]=Up-0.5*m*Pi;//2.16
	u[2][2]=Up-0.5*m*Pi;//2.16
	//	u[2][3]=Right;//2.16
	u[3][2]=Right;//2.16

}
