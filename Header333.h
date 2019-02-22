#ifndef HEADER333_H
#define HEADER333_H
float fmin(int k, float *fvec);
void fdjac(int n, int k, float x[], float fvec[], float **df, double m, int a);
void ludcmp(float **a, int k, int *indx, float *d);
void lubksb(float **a, int k, int *indx, float b[]);
#endif