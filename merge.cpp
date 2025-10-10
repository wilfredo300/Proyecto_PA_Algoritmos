#include <chrono>
#include <iostream>
#include <vector>
#include "listasAleatorias.h"
#include "listasAleatorias10000.h"
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

// Función para fusionar dos subarreglos ya ordenados
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1; // tamaño del primer subarray
    int n2 = right - mid;    // tamaño del segundo subarray

    // Crear arrays temporales
    vector<int> L(n1), R(n2);

    // Copiar datos a los arrays temporales
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Fusionar los arrays temporales de vuelta en arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de L[]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de R[]
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Función recursiva de MergeSort
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Ordenar primera y segunda mitad
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Fusionar las mitades
        merge(arr, left, mid, right);
    }
}

int main() {
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();

    vector<int> lista;
    for(int &x: listaAleatoria_100000){
        lista.push_back(x);
    }   
    int n= lista.size();
    //int n = 100000; //tamaño del arreglo a utilizar
    //SelectionSort(listaAleatoria_100000, n);
    mergeSort(lista,0,n-1);
    
    

    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    cout << "Time difference = "
         << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << "[ms]" << endl;
    cout << "Time difference = "
         << chrono::duration_cast<chrono::microseconds>(end - begin).count() << "[us]" << endl;
    cout << "Time difference = "
         << chrono::duration_cast<chrono::nanoseconds>(end - begin).count() << "[ns]" << endl;

    return 0;
}

