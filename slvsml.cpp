#include <stdio.h>
#include "Header2.h"
void slvsml(double **u, double **rhs) 
{ 
	double h=0.5;
	fill0(u,3);
	u[2][2] = -h*h*rhs[2][2]/4.0;
}
