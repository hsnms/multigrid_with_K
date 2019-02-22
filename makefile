output: main22.o addint.o anorm2.o copy.o copy2.o dmatrix.o dmatrix2.o dvector.o fdjac.o fill0.o fill02.o fmin.o free_dmatrix.o free_dmatrix2.o free_dmatrix3.o free_dvector.o free_ivector.o free_matrix.o free_vector.o integrat.o interp.o interp1.o interp2.o interp3.o ivector.o lnsrch.o lop.o lubksb.o ludcmp.o matadd.o matrix.o matsub.o mgfas.o nrerror.o nrerror2.o nrerror3.o nrfunc.o relax.o relax2.o resid.o rstrct.o rstrct2.o slvsm2.o slvsml.o Stat.o trapzd.o vecfunc.o vector.o vofunc.o
	g++ main22.o addint.o anorm2.o copy.o copy2.o dmatrix.o dmatrix2.o dvector.o fdjac.o fill0.o fill02.o fmin.o free_dmatrix.o free_dmatrix2.o free_dmatrix3.o free_dvector.o free_ivector.o free_matrix.o free_vector.o integrat.o interp.o interp1.o interp2.o interp3.o ivector.o lnsrch.o lop.o lubksb.o ludcmp.o matadd.o matrix.o matsub.o mgfas.o nrerror.o nrerror2.o nrerror3.o nrfunc.o relax.o relax2.o resid.o rstrct.o rstrct2.o slvsm2.o slvsml.o Stat.o trapzd.o vecfunc.o vector.o vofunc.o -o output
main22.o: main22.cpp
	g++ -c main22.cpp
addint.o: addint.cpp Header3.h
	g++ -c addint.cpp
anorm2.o: anorm2.cpp Header22.h 
	g++ -c anorm2.cpp
copy.o: copy.cpp Header2.h
	g++ -c copy.cpp
copy2.o: copy2.cpp Header22.h
	g++ -c copy2.cpp
dmatrix.o: dmatrix.cpp Header2.h
	g++ -c dmatrix.cpp
dmatrix2.o: dmatrix2.cpp Header22.h
	g++ -c dmatrix2.cpp
dvector.o: dvector.cpp Header222.h
	g++ -c dvector.cpp
fdjac.o: fdjac.cpp Header333.h
	g++ -c fdjac.cpp
fill0.o: fill0.cpp Header2.h
	g++ -c fill0.cpp
fill02.o: fill02.cpp Header22.h
	g++ -c fill02.cpp
fmin.o: fmin.cpp Header333.h
	g++ -c fmin.cpp
free_dmatrix.o: free_dmatrix.cpp Header2.h
	g++ -c free_dmatrix.cpp
free_dmatrix2.o: free_dmatrix2.cpp Header22.h
	g++ -c free_dmatrix2.cpp
free_dmatrix3.o: free_dmatrix3.cpp Header222.h
	g++ -c free_dmatrix3.cpp
free_dvector.o: free_dvector.cpp Header222.h
	g++ -c free_dvector.cpp
free_ivector.o: free_ivector.cpp Header222.h 
	g++ -c free_ivector.cpp
free_matrix.o: free_matrix.cpp Header222.h
	g++ -c free_matrix.cpp
free_vector.o: free_vector.cpp Header222.h
	g++ -c free_vector.cpp
integrat.o: integrat.cpp Header6.h
	g++ -c integrat.cpp
interp.o: interp.cpp Header2.h
	g++ -c interp.cpp
interp1.o: interp1.cpp Header2.h
	g++ -c interp1.cpp
interp2.o: interp2.cpp Header22.h
	g++ -c interp2.cpp
interp3.o: interp3.cpp Header22.h
	g++ -c interp3.cpp
ivector.o: ivector.cpp Header222.h
	g++ -c ivector.cpp
lnsrch.o: lnsrch.cpp Header444.h
	g++ -c lnsrch.cpp
lop.o: lop.cpp Header22.h
	g++ -c lop.cpp
lubksb.o: lubksb.cpp Header333.h
	g++ -c lubksb.cpp
ludcmp.o: ludcmp.cpp Header333.h
	g++ -c ludcmp.cpp
matadd.o: matadd.cpp Header22.h
	g++ -c matadd.cpp
matrix.o: matrix.cpp Header222.h
	g++ -c matrix.cpp
matsub.o: matsub.cpp Header22.h
	g++ -c matsub.cpp
mgfas.o: mgfas.cpp
	g++ -c mgfas.cpp
nrerror.o: nrerror.cpp Header1.h
	g++ -c nrerror.cpp
nrerror2.o: nrerror2.cpp Header11.h
	g++ -c nrerror2.cpp
nrerror3.o: nrerror3.cpp Header111.h
	g++ -c nrerror3.cpp
nrfunc.o: nrfunc.cpp
	g++ -c nrfunc.cpp
relax.o: relax.cpp Header2.h
	g++ -c relax.cpp
relax2.o: relax2.cpp Header22.h
	g++ -c relax2.cpp
resid.o: resid.cpp Header2.h
	g++ -c resid.cpp
rstrct.o: rstrct.cpp Header2.h
	g++ -c rstrct.cpp
rstrct2.o: rstrct2.cpp Header22.h
	g++ -c rstrct2.cpp
slvsm2.o: slvsm2.cpp Header33.h
	g++ -c slvsm2.cpp
slvsml.o: slvsml.cpp Header3.h
	g++ -c slvsml.cpp
Stat.o: Stat.cpp
	g++ -c Stat.cpp
trapzd.o: trapzd.cpp Header5.h
	g++ -c trapzd.cpp
vecfunc.o: vecfunc.cpp
	g++ -c vecfunc.cpp
vector.o: vector.cpp Header222.h
	g++ -c vector.cpp
vofunc.o: vofunc.cpp Header222.h
	g++ -c vofunc.cpp
clean:
	rm *.o output
