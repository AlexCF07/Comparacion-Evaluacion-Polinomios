# 🚀 Comparación de Evaluación de Polinomios

Este proyecto compara experimentalmente dos métodos para evaluar polinomios: el método tradicional (evaluación directa) y el esquema de Horner. Mide sus tiempos de ejecución para polinomios de distintos grados (desde 10 hasta 1000) y genera un archivo CSV con los resultados para su análisis.

## 👤 Autor(a)
Alejandro Cordero Fraga

## ⚙️ Requisitos del Sistema
### Para Windows:
- Compilador: MinGW-w64 (g++ 9.0 o superior)
- CMake (opcional, versión 3.15+)
- Git Bash (recomendado para la terminal)

### Para Linux:
- Compilador: g++ (versión 9.0 o superior)
- Build-essential
- Git

## 🛠️ Compilación y ejecución

### Windows (sin Git):
1. Descarga el ZIP desde GitHub
2. Extrae en una carpeta
3. Abre PowerShell/CMD en esa ubicación
4. Ejecuta:
   ```powershell
   g++ -std=c++17 main.cpp Operaciones.cpp -o evaluacion_polinomios.exe
   .\evaluacion_polinomios.exe
   ```

### Linux (sin Git):
1. Descarga el ZIP desde GitHub
2. Extrae:
   ```bash
   unzip Comparacion-Evaluacion-Polinomios-main.zip
   cd Comparacion-Evaluacion-Polinomios-main
   ```
3. Compila y ejecuta:
   ```bash
   g++ -std=c++17 main.cpp Operaciones.cpp -o evaluacion_polinomios
   ./evaluacion_polinomios
   ``
## 📊 Descripción de los Algoritmos

### Método Tradicional
Evalúa el polinomio calculando cada término por separado usando potencias:
```
P(x) = aₙxⁿ + aₙ₋₁xⁿ⁻¹ + ... + a₁x + a₀
```
- **Complejidad**: O(n²) operaciones
- **Ventaja**: Fácil de implementar
- **Desventaja**: Ineficiente para grados altos

### Método de Horner
Reescribe el polinomio para minimizar operaciones:
```
P(x) = ((...((aₙx + aₙ₋₁)x + aₙ₋₂)...)x + a₁)x + a₀
```
- **Complejidad**: O(n) operaciones
- **Ventaja**: Más eficiente en tiempo y memoria
- **Desventaja**: Menos intuitivo

## 📈 Resultados Experimentales

El programa genera un archivo CSV con tres filas:
1. Grados evaluados (de 10 en 10 hasta 1000)
2. Tiempos de evaluación con Horner (en ns)
3. Tiempos de evaluación tradicional (en ns)

**Gráfica comparativa** 
![Grafica-comparativa-d](https://github.com/user-attachments/assets/4a72c706-8856-4e09-ada6-3b9fd96c805c)

## 🔍 Análisis de Resultados
- El método de Horner demostró ser mucho más eficiente que el método tradicional en la enorme mayoría de casos.
- El único caso en el que el método tradicional demostró ser superior es en la evaluación de un polinomio grado 10, donde el método de Horner tardó 4500 nanosegundos, mientras que el tradicional tardó 1500.
- La diferencia de velocidades se hace más notoria conforme aumenta el grado del polinomio.

## ✅ Conclusiones
- El método tradicional es más recomendable para polinomios de grado 10 o menor.
- Para polinomios con grados superiores al 10, el método de Horner es mucho más eficiente.
