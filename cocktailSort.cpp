#include <chrono>
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm> 
#include <iomanip>
#include "algoritmos_y_listas/listasAleatorias.h"
#include "algoritmos_y_listas/listasOrdenadas.h"
#include "algoritmos_y_listas/listasDecrecientes.h"
#include "algoritmos_y_listas/algoritmos.h"


using namespace std;

struct ListaInfo {
    int* lista;
    int size;
    string patron;
};

// Funciones auxiliares para estadísticos
double calcularMedia(const vector<long long>& v) {
    double suma = 0;
    for (auto t : v) suma += t;
    return suma / v.size();
}

double calcularDesviacion(const vector<long long>& v, double media) {
    double suma = 0;
    for (auto t : v) suma += pow(t - media, 2);
    return sqrt(suma / v.size());
}

double calcularMediana(vector<long long> v) {
    sort(v.begin(), v.end());
    int n = v.size();
    if (n % 2 == 0)
        return (v[n / 2 - 1] + v[n / 2]) / 2.0;
    else
        return v[n / 2];
}

int main() {
    string algoritmo = "Cocktail Sort";
    long long tiempo = 0;
    long long comparaciones = 0;
    long long intercambios = 0;
    int semilla = 0;

    ListaInfo listas[9] = {
        {listaAleatoria_1000, 1000, "aleatorio"},
        {listaAleatoria_10000, 10000, "aleatorio"},
        {listaAleatoria_100000, 100000, "aleatorio"},
        {listaOrdenada_1000, 1000, "ordenado creciente"},
        {listaOrdenada_10000, 10000, "ordenado creciente"},
        {listaOrdenada_100000, 100000, "ordenado creciente"},
        {listaDecreciente_1000, 1000, "ordenado decreciente"},
        {listaDecreciente_10000, 10000, "ordenado decreciente"},
        {listaDecreciente_100000, 100000, "ordenado decreciente"}
    };

    ofstream archivo("datos_de_medicion/datosCocktailSort.csv");
    if (!archivo) {
        cerr << "Error al abrir el archivo\n";
        return 1;
    }

    archivo << "algoritmo,n,patron,repeticiones,tiempo_ns,comparaciones,intercambios,semilla\n";

    for (int indice = 0; indice < 9; indice++) {
        int n = listas[indice].size;
        string patron = listas[indice].patron;

        cout << "\nProbando lista " << patron << " de " << n << " elementos...\n";

        vector<long long> tiempos; // guardar los tiempos de las 10 repeticiones

        for (int repeticion = 1; repeticion <= 10; repeticion++) {
            comparaciones = 0;
            intercambios = 0;

            int* copia = new int[n];
            for (int i = 0; i < n; i++) {
                copia[i] = listas[indice].lista[i];
            }

            auto begin = chrono::steady_clock::now();
            cocktailSort(copia, n, comparaciones, intercambios);
            auto end = chrono::steady_clock::now();

            tiempo = chrono::duration_cast<chrono::nanoseconds>(end - begin).count();
            tiempos.push_back(tiempo);

            cout << "Repetición " << repeticion << ": " << tiempo << " ns\n";

            archivo << algoritmo << "," << n << "," << patron << "," << repeticion << ","
                    << tiempo << "," << comparaciones << "," << intercambios << "," << semilla << "\n";

            delete[] copia;
        }

        // 🔹 Calcular estadísticas
        double media = calcularMedia(tiempos);
        double mediana = calcularMediana(tiempos);
        double desviacion = calcularDesviacion(tiempos, media);
        long long minimo = *min_element(tiempos.begin(), tiempos.end());
        long long maximo = *max_element(tiempos.begin(), tiempos.end());

        // 🔹 Mostrar en consola
        cout << "\nResumen (" << patron << ", " << n << " elementos):\n";
        cout << "Media: " << media << " ns\n";
        cout << "Mediana: " << mediana << " ns\n";
        cout << "Desviacion estándar: " << desviacion << " ns\n";
        cout << "Minimo: " << minimo << " ns\n";
        cout << "Maximo: " << maximo << " ns\n";

        // 🔹 Escribir resumen en el CSV (línea separada)
        archivo << algoritmo << "," << n << "," << patron
        <<",Resumen_de_tiempo:," 
                << ",Media:," << fixed<<setprecision(0)<< media 
                << ",Mediana:," << fixed<<setprecision(0)<<mediana 
                << ",Desviacion:,"<< fixed<<setprecision(0)<<desviacion 
                << ",minimo:," << fixed<<setprecision(0)<<minimo 
                << ",maximo:," << fixed<<setprecision(0)<<maximo << "\n";
    }

    archivo.close();
    cout << "\nTodos los resultados y estadísticas se guardaron en datos_de_medicion/datosCocktailSort.csv\n";
    return 0;
}
