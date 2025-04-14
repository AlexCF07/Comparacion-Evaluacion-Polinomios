#include <iostream>
#include <fstream>
#include <filesystem>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include "Operaciones.cpp"

#define GRADO_MIN 10
#define INCREMENTO 10
#define GRADO_MAX 1000

using namespace std;
using namespace std::chrono;

int main()
{
    const string nombreArchivo = "Polinomios-Evaluacion.csv";
    ofstream archivo(nombreArchivo);

    if (!archivo.is_open())
    {
        cout << "Error al crear el archivo CSV" << endl;
        return 1;
    }

    // Fila: Grados
    archivo << ",";
    for (int i = GRADO_MIN; i <= GRADO_MAX; i += INCREMENTO)
    {
        archivo << i;
        if (i + INCREMENTO <= GRADO_MAX) archivo << ",";
    }
    archivo << "\n";

    // Fila: Tiempos de Horner
    archivo << "Horner,";
    for (int i = GRADO_MIN; i <= GRADO_MAX; i += INCREMENTO)
    {
        int grado(i);
        int* polinomio = new int[grado+1];
        int valorX = (rand()%21)-10;

        LlenarPolinomio(polinomio, grado);

        auto tiempo_inicio = steady_clock::now();
        EvaluacionHorner(polinomio, grado, valorX);
        auto tiempo_final = steady_clock::now();
        auto tiempo_total = duration_cast<nanoseconds>(tiempo_final - tiempo_inicio);

        archivo << tiempo_total.count();
        if (i + INCREMENTO <= GRADO_MAX) archivo << ",";

        delete[] polinomio;
        cout << "Evaluación Horner grado " << i << " completada\n";
    }
    archivo << "\n";  // Fin de la fila Horner

    // Fila: Tiempos de Tradicional
    archivo << "Tradicional,";
    for (int i = GRADO_MIN; i <= GRADO_MAX; i += INCREMENTO)
    {
        int grado(i);
        int* polinomio = new int[grado+1];
        int valorX = (rand()%21)-10;

        LlenarPolinomio(polinomio, grado);

        auto tiempo_inicio = steady_clock::now();
        EvaluacionTradicional(polinomio, grado, valorX);
        auto tiempo_final = steady_clock::now();
        auto tiempo_total = duration_cast<nanoseconds>(tiempo_final - tiempo_inicio);

        archivo << tiempo_total.count();
        if (i + INCREMENTO <= GRADO_MAX) archivo << ",";

        delete[] polinomio;
        cout << "Evaluaci\242n Tradicional grado " << i << " completada\n";
    }

    // Cierre y mensaje final
    filesystem::path rutaCompleta = filesystem::absolute(nombreArchivo);
    cout << "\nResultados guardados en: " << rutaCompleta.string() << endl;
    archivo.close();

    return 0;
}
