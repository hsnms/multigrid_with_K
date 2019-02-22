#include <stdio.h>
#include <errno.h>
#include "Header1.h"
#include "Header2.h"
#include "Header3.h"
#define NPRE 1
#define NPOST 1
#define NGMAX 15
int main()
{
    int i,k,n,ncycle=1;
	double **u,x[50],y[50],zero;
	void mglin(double **u, int n,int ncycle);
	double Stat2(double **u, int n);
	FILE *fp;
	n=33;
	u=dmatrix(1,n,1,n);
	for (i=1;i<=n;i++)
	{
		x[i]=1.0*i*(1.0/n);
		y[i]=1.0*i*(1.0/n);
	}
	for(i=1;i<=n;i++)
		for(k=1;k<=n;k++)
			u[i][k]=1.0*(i+k);
	mglin(u,n,ncycle);
	zero=Stat2(u,n);
	 fp = fopen ("C:\\C\\LPDE.txt","w");
    if (fp == NULL) {
        printf ("File not created okay, errno = %d\n", errno);
        return 1;
    }
		for(i=1;i<=n;i++)
		for(k=1;k<=n;k++)
			fprintf(fp,"{%f,\t%f,\t%f},\t",x[i],y[k],u[i][k]);
		fclose (fp);
    printf ("File created okay\n");
	/*printf ("u[1][1]=%f\nu[1][n]=%f\nu[n][1]=%f\nu[n][n]=%f\n",u[1][1],u[1][n],u[n][1],u[n][n]);*/
	printf ("zero=%f\n",zero);
    return 0;
}