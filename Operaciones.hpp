#ifndef OPERACIONES_HPP_INCLUDED
#define OPERACIONES_HPP_INCLUDED

void ImprimirPolinomio(int* a, int grado);
int* LlenarPolinomio(int* a, int grado);
long double EvaluacionHorner(int* a, int grado, int x);
long double EvaluacionTradicional(int* a, int grado, int x);

#endif // OPERACIONES_HPP_INCLUDED
