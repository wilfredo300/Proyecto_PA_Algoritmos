#include <chrono>
#include <iostream>
#include <vector>
#include "listasAleatorias.h"
using namespace std;
/* void SelectionSort(int list[], int n) {
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
} */
 void bubleSort(int list[], int n){
    for(int j=0;j<n-1;j++){
        for (int i=0;i<n-j-1;i++){
            if(list[i]>list[i+1]){
                int temp = list[i];
                list[i] = list[i+1];
                list[i+1] = temp;
            }
        }
    }
 }

int main() {
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();

    
    
    int n = 10000 ; //tamaño del arreglo a utilizar
    //SelectionSort(listaAleatoria_10000, n);
    bubleSort(listaAleatoria_10000,n);
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

