#include <stdio.h>
#define Pi 3.141592653589793
void interp3(double **uf, double **uc, int nf,int a) 
{ 
	int ic,iif,jc,jf,nc,i,j; 
	nc=nf/2+1; 
	for (jc=1,jf=1;jc<=nc;jc++,jf+=2)
		for (ic=1;ic<=nc;ic++) 
			uf[2*ic-1][jf]=uc[ic][jc]; 

	for (i=2;i<=nf-1;i++)
		uf[i][1]=0.0;
	for (i=2;i<=nf-1;i++)
		uf[i][nf]=0.0;
	for (j=1;j<=nf;j++)
		uf[1][j]=0.0;
	for (j=1;j<=nf;j++)
		uf[nf][j]=0.0; 
		
	if (nf<=5)
	{
	   uf[2][3]=0.5*(uf[1][3]+uf[3][3]);
	   uf[4][3]=0.5*(uf[3][3]+uf[5][3]);
	   uf[2][2]=uf[3][2]=uf[4][2]=uf[2][4]=uf[3][4]=uf[4][4]=0.0;
	
	}


	/*else
	{
		for (jf=3;jf<=nf-2;jf+=2) 
		for (iif=2;iif<=nf-1;iif+=2) 
			uf[iif][jf]=0.5*(uf[iif+1][jf]+uf[iif-1][jf]);


		
		for (iif=2;iif<=nf-1;iif++)
		{
			uf[iif][nf/2]=uf[iif][-1+nf/2];
			
			uf[iif][(nf/2)+2]=uf[iif][(nf/2)+3];
		}

		for (jf=2;jf<=-2+nf/2;jf+=2)
		for (iif=2;iif <= nf-1;iif++) 
            uf[iif][jf]=0.5*(uf[iif][jf+1]+uf[iif][jf-1]);
		for (jf=4+(nf/2);jf<=nf-1;jf+=2)
		for (iif=2;iif <= nf-1;iif++) 
            uf[iif][jf]=0.5*(uf[iif][jf+1]+uf[iif][jf-1]);

		
	
	}*/
			
	/*else if (nf>5&&a%2==0)
	{
		for (jf=3;jf<=nf-2;jf+=2) 
		for (iif=2;iif<=nf-1;iif+=2) 
			uf[iif][jf]=0.5*(uf[iif+1][jf]+uf[iif-1][jf]);


	    for (iif=1;iif<=nf-1;iif++)
		{
			uf[iif][a]=uf[iif][-1+a];
			
			uf[iif][a+2]=uf[iif][a+3];
		}

		for (jf=2;jf<=-2+a;jf+=2)
		for (iif=1;iif <= nf-1;iif++) 
            uf[iif][jf]=0.5*(uf[iif][jf+1]+uf[iif][jf-1]);
		for (jf=4+a;jf<=nf-1;jf+=2)
		for (iif=1;iif <= nf-1;iif++) 
            uf[iif][jf]=0.5*(uf[iif][jf+1]+uf[iif][jf-1]);

        
	
	}
    else 
	{
		for (jf=3;jf<=nf-2;jf+=2) 
		for (iif=2;iif<=nf-1;iif+=2) 
			uf[iif][jf]=0.5*(uf[iif+1][jf]+uf[iif-1][jf]);

        for (iif=1;iif<=nf-1;iif++)
		{
			uf[iif][a-1]=uf[iif][-2+a];
			
			uf[iif][a+1]=uf[iif][a+2];
		}
	

		for (jf=2;jf<=-3+a;jf+=2)
		for (iif=1;iif <= nf-1;iif++) 
            uf[iif][jf]=0.5*(uf[iif][jf+1]+uf[iif][jf-1]);
		for (jf=3+a;jf<=nf-1;jf+=2)
		for (iif=1;iif <= nf-1;iif++) 
            uf[iif][jf]=0.5*(uf[iif][jf+1]+uf[iif][jf-1]);

       
	
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