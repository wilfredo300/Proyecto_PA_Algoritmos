#include <chrono>
#include <iostream>
#include <vector>
#include "listasAleatorias.h"
#include "listasOrdenadas.h"
#include "listasDecrecientes.h"
#include "algoritmos.h"

using namespace std;


int main() {
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();

    int n = 1000 ; //tamaño del arreglo a utilizar
    //SelectionSort(listaAleatoria_10000, n);
    bubleSort(listaAleatoria_1000,n);
    
    for(int i=0;i<n;i++){
        cout<<listaAleatoria_10000[i]<<" ";
    }
    

    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    cout << "Time difference = "
         << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << "[ms]" << endl;
    cout << "Time difference = "
         << chrono::duration_cast<chrono::microseconds>(end - begin).count() << "[us]" << endl;
    cout << "Time difference = "
         << chrono::duration_cast<chrono::nanoseconds>(end - begin).count() << "[ns]" << endl;

    return 0;
}

