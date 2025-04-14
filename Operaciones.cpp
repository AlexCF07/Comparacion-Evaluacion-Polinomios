#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <cmath>
#include "Operaciones.hpp"  // Incluir su propio header

using namespace std;

void ImprimirPolinomio(int* a, int grado)
{
    for (int i = grado; i > 1; i--)
    {
        cout << a[i] << "x^" << i << " + ";
    }
    if(grado > 0)
    {
        cout << a[1] << "x" << " + ";
    }
    cout << a[0];
}

int* LlenarPolinomio(int* a, int grado)
{
    srand(time(0));
    for (int i = 0; i <= grado; i++)
    {
        a[i] = (rand()%21)-10;
    }
    return a;
}

#include <limits> // Añade esto al inicio

long double EvaluacionHorner(int* a, int grado, int x) {
    long double resultado = a[grado];

    for (int i = grado-1; i >= 0; i--)
    {
        resultado = resultado * x + a[i];

        // Verificación de desbordamiento
        if (isinf(resultado) || isnan(resultado)) {
            cerr << "Advertencia: Desbordamiento en grado " << grado << endl;
            return numeric_limits<long double>::quiet_NaN();
        }
    }
    return resultado;
}

long double EvaluacionTradicional(int* a, int grado, int x) {
    long double resultado = 0;
    long double potencia = 1; // Para optimizar el cálculo de x^i

    for (int i = 0; i <= grado; i++)
    {
        resultado += a[i] * potencia;
        potencia *= x;

        // Verificación de desbordamiento
        if (isinf(resultado) || isnan(resultado)) {
            cerr << "Advertencia: Desbordamiento en grado " << grado << endl;
            return numeric_limits<long double>::quiet_NaN();
        }
    }
    return resultado;
}
