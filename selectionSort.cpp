#include <chrono>
#include <iostream>
#include "listasAleatorias.h"
using namespace std;
void SelectionSort(int list[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (list[j] < list[minIndex]) {
                minIndex = j;
            }
        }
        // Intercambio
        int temp = list[i];
        list[i] = list[minIndex];
        list[minIndex] = temp;
    }
}

int main() {
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();

    
    int &lista[10000] = listaAleatoria_10000;
    int n = lista.size();
    SelectionSort(lista, n);

    

    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    cout << "Time difference = "
         << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << "[ms]" << endl;
    cout << "Time difference = "
         << chrono::duration_cast<chrono::microseconds>(end - begin).count() << "[us]" << endl;
    cout << "Time difference = "
         << chrono::duration_cast<chrono::nanoseconds>(end - begin).count() << "[ns]" << endl;

    return 0;
}

