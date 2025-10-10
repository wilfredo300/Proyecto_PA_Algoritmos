#include <chrono>
#include <iostream>
#include <fstream>
#include <vector>
#include "listasAleatorias.h"
#include "listasOrdenadas.h"
#include "listasDecrecientes.h"
#include "algoritmos.h"

using namespace std;


int main() {
    //tipos de datos que se usaran
    string algoritmo = "Buble Sort";
    int n = 100000 ; //tamaño del arreglo a utilizar
    string patron = "aleatorio";
    long long tiempo = 0;
    int repeticion = 1;  //probablemente igual a i
    int comparaciones = 0; 
    int intercambios = 0;
    int semilla = 0;
    ofstream archivo("datos.csv");
        if (!archivo) {
            cerr << "Error al abrir el archivo\n";
            return 1;
        }
               
        
        archivo<<"algoritmo,n,patron,repeticiones,tiempo_ns,comparaciones,intercambios,semilla\n";
        for(repeticion;repeticion <=10;repeticion++){
            int copia[n];
            for (int i = 0; i < n; i++) {
                copia[i] = listaDecreciente_100000[i];
            }

            chrono::steady_clock::time_point begin = chrono::steady_clock::now();
            
            bubleSort(copia,n);
                      
            chrono::steady_clock::time_point end = chrono::steady_clock::now();
            
            
            tiempo = chrono::duration_cast<chrono::nanoseconds>(end - begin).count() ;
            cout << "Time difference = "
            << tiempo << "[ns]" << endl;
                      
            archivo<<algoritmo<<","<<n<<","<<patron<<","<<repeticion<<","<<tiempo<<","<<comparaciones<<","<<intercambios<<","<<semilla<<"\n";
        }

    archivo.close(); // cerrar archivo    
    return 0;
}

