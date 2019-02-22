#include <stdlib.h>
#include "Header111.h"
#define NR_END 1
double *dvector(long nl,long nh)
/* allocate a double vector with subscript range v[nl..nh] */
{
	double *v;

	v=(double *)malloc((unsigned int) ((nh-nl+1+NR_END)*sizeof(double)));
	if (!v) nrerror3("allocation failure in dvector()");
	return v-nl+NR_END;
}