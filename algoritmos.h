#ifndef ALGORITMOS_h
#define ALGORITMOS_h
#include<iostream>
#include<algorithm>
using namespace std;
 void bubleSort(int list[], int n,int &comparaciones,int &intercambios){
    comparaciones = 0;
    intercambios = 0;
    for(int j=0;j<n-1;j++){
        for (int i=0;i<n-j-1;i++){
            if(list[i]>list[i+1]){
                swap(list[i],list[i+1]);
                intercambios++;
            }
            comparaciones++;
        }
    }
 }
 void cocktailSort(int A[],int n,int &comparaciones,int &intercambios){
    int izq = 1;
    int der = n-1;
    int k = n-1;
    while(izq<=der){
        for(int i=der;i>=izq;i--){
            comparaciones++;
            if(A[i-1]>A[i]){
                swap(A[i-1],A[i]);
                intercambios++;
                k=i;
            }
        }
        izq=k+1;
        for(int i=izq;i<=der;i++){
            comparaciones++;
            if(A[i-1]>A[i]){
                swap(A[i-1],A[i]);
                k=i;
            }
        }
        der=k-1;
    }
 }
 void merge(int arr[], int inicio, int medio, int fin,int &comparaciones, int &intercambios) {
    int n1 = medio - inicio + 1;
    int n2 = fin - medio;

    // Arreglos temporales
    int* izquierda = new int[n1];
    int* derecha = new int[n2];

    // Copiar datos a los arreglos temporales
    for (int i = 0; i < n1; i++){
        izquierda[i] = arr[inicio + i];
        intercambios++;
    }
    for (int j = 0; j < n2; j++){
        derecha[j] = arr[medio + 1 + j];
        intercambios++;
    }

    // Mezclar los arreglos temporales de vuelta en arr[inicio..fin]
    int i = 0, j = 0, k = inicio;

    while (i < n1 && j < n2) {
        comparaciones++;
        if (izquierda[i] <= derecha[j]) {
            arr[k] = izquierda[i];
            i++;
        } else {
            arr[k] = derecha[j];
            j++;
        }
        k++;
        intercambios++;
    }

    // Copiar los elementos restantes de izquierda[], si hay
    while (i < n1) {
        arr[k] = izquierda[i];
        i++;
        k++;
        intercambios++;
    }

    // Copiar los elementos restantes de derecha[], si hay
    while (j < n2) {
        arr[k] = derecha[j];
        j++;
        k++;
        intercambios++;
    }

    // Liberar memoria
    delete[] izquierda;
    delete[] derecha;
}

// Función principal de Merge Sort
void mergeSort(int arr[], int inicio, int fin,int &comparaciones,int &intercambios) {
    if (inicio < fin) {
        int medio = inicio + (fin - inicio) / 2;

        mergeSort(arr, inicio, medio,comparaciones,intercambios);
        mergeSort(arr, medio + 1, fin,comparaciones,intercambios);

        merge(arr, inicio, medio, fin,comparaciones,intercambios);
    }
}
#endif