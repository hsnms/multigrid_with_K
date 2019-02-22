#include <math.h>
#include <stdio.h>
#include "Header22.h"
void slvsm2(int n, double **u, double **rhs, double m, int a) 
{ 
	int k,check[5];
	float x[5];
	/*void newt(int n, float x[], int k, int *check, double m, int a);
	k=1;*/
	/*x[1]=1.5;*/
	/*x[2]=1.5;*/
	/*check[1]=2;
	newt(n,x,k,check,m,a);*/
	fill02(u,n,m,a); /**/
	/*u[1][2]=x[1];*/
	/*u[2][2]=x[1];*/
}