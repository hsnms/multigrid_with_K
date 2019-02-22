#include <stdio.h>
int main()
{
	int n,check[5];
	float x[5];
	void newt(float x[], int n, int *check);
	n=2;
	x[1]=1.5;
	x[2]=1.5;
	check[1]=2;
	newt(x,n,check);
	printf("x[1]=%f\nx[2]=%f\n",x[1],x[2]);
	return 0;
}