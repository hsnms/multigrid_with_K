#ifndef HEADER2_H
#define HEADER2_H
double **dmatrix(long nrl,long nrh,long ncl,long nch);
void free_dmatrix(double **m, long nrl, long nrh, long ncl, long nch);
void fill0(double **u, int n);
void copy(double **aout, double **ain, int n);
void resid(double **res, double **u, double **rhs, int n);
void relax(double **u, double **rhs, int n);
void interp(double **uf, double **uc, int nf); 
void interp1(double **uf, double **uc, int nf); 
void rstrct(double **uc, double **uf, int nc); 
#endif