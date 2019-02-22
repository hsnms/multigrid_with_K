#include <stdio.h>
#define Up 0.0;
#define Down 0.0;
#define Left 0.0;
#define Right 0.0;
void fill0(double **u, int n) 
	 
{ 
	int i,j; 
    for (j=2;j<=n-1;j++) 
		for (i=2;i<=n-1;i++) 
			u[i][j]=0.0; 
	for (i=2;i<=n-1;i++)
		u[i][1]=Up;
	for (i=2;i<=n-1;i++)
		u[i][n]=Down;
	for (j=1;j<=n;j++)
		u[1][j]=Left;
	for (j=1;j<=n;j++)
		u[n][j]=Right; /*change*/
}