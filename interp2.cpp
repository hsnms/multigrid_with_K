#include <stdio.h>
#define Up 1.570796326794897
#define Down 1.570796326794897
/*#define Left -1.57;*/
#define Right 1.570796326794897
#define Pi 3.141592653589793
void interp2(double **uf, double **uc, int nf, double m, int a) 
{ 
	int ic,iif,jc,jf,nc,i,j; 
	nc=nf/2+1; 
	for (jc=1,jf=1;jc<=nc;jc++,jf+=2)
		for (ic=1;ic<=nc;ic++) 
			uf[2*ic-1][jf]=uc[ic][jc]; 

	for (i=1;i<=nf;i++)
		uf[i][1]=Down+0.5*m*Pi;
	for (i=1;i<=nf;i++)
		uf[i][nf]=Up-0.5*m*Pi;
	for (j=2;j<=a;j++)
		uf[nf][j]=/*Down*/Right; 
	for (j=1+a;j<=nf-1;j++)
		uf[nf][j]=/*Up*/Right; 


	if (nf<=5)
	{
	for(i=1;i<=nf;i++)
		{
			for(j=1;j<=a;j++)
			    uf[i][j]=Down+0.5*m*Pi/*Up*/;
			for (j=1+a;j<=nf;j++)
				uf[i][j]=Up-0.5*m*Pi;/**/
	    }
	}
/*else 
	{
		for (jf=3;jf<=nf-2;jf+=2) 
		for (iif=2;iif<=nf-1;iif+=2) 
			uf[iif][jf]=0.5*(uf[iif+1][jf]+uf[iif-1][jf]);


	

		for (jf=2;jf<=-2+nf/2;jf+=2)
		for (iif=1;iif <= nf-1;iif++) 
            uf[iif][jf]=0.5*(uf[iif][jf+1]+uf[iif][jf-1]);
		for (jf=4+nf/2;jf<=nf-1;jf+=2)
		for (iif=1;iif <= nf-1;iif++) 
            uf[iif][jf]=0.5*(uf[iif][jf+1]+uf[iif][jf-1]);

        for (iif=1;iif<=nf-1;iif++)
		{
			uf[iif][nf/2]=uf[iif][-1+nf/2];
			
			uf[iif][nf/2+2]=uf[iif][nf/2+3];
		}
	
	}*/
	else if (nf>5&&a%2==0)
	{
		for (jf=3;jf<=nf-2;jf+=2) 
		for (iif=2;iif<=nf-1;iif+=2) 
			uf[iif][jf]=0.5*(uf[iif+1][jf]+uf[iif-1][jf]);


	
		if (a==2)
		{
			
			for (jf=4+a;jf<=nf-1;jf+=2)
		    for (iif=1;iif <= nf-1;iif++) 
            uf[iif][jf]=0.5*(uf[iif][jf+1]+uf[iif][jf-1]);

		}

		else
		{
		for (jf=2;jf<=-2+a;jf+=2)
		for (iif=1;iif <= nf-1;iif++) 
            uf[iif][jf]=0.5*(uf[iif][jf+1]+uf[iif][jf-1]);
		for (jf=4+a;jf<=nf-1;jf+=2)
		for (iif=1;iif <= nf-1;iif++) 
			uf[iif][jf]=0.5*(uf[iif][jf+1]+uf[iif][jf-1]);
		}

        for (iif=1;iif<=nf-1;iif++)
		{
			uf[iif][a]=uf[iif][-1+a];
			
			uf[iif][a+2]=uf[iif][a+3];
		}
	
	}
    else 
	{
		for (jf=3;jf<=nf-2;jf+=2) 
		for (iif=2;iif<=nf-1;iif+=2) 
			uf[iif][jf]=0.5*(uf[iif+1][jf]+uf[iif-1][jf]);


	if (a==3)
	{
		for (jf=3+a;jf<=nf-1;jf+=2)
		for (iif=1;iif <= nf-1;iif++) 
            uf[iif][jf]=0.5*(uf[iif][jf+1]+uf[iif][jf-1]);
	}
	else
	{
		for (jf=2;jf<=-3+a;jf+=2)
		for (iif=1;iif <= nf-1;iif++) 
            uf[iif][jf]=0.5*(uf[iif][jf+1]+uf[iif][jf-1]);
		for (jf=3+a;jf<=nf-1;jf+=2)
		for (iif=1;iif <= nf-1;iif++) 
            uf[iif][jf]=0.5*(uf[iif][jf+1]+uf[iif][jf-1]);
	}

        for (iif=1;iif<=nf-1;iif++)
		{
			uf[iif][a-1]=uf[iif][-2+a];
			
			uf[iif][a+1]=uf[iif][a+2];
		}
	
	}

}