#ifndef ALGORITMOS_h
#define ALGORITMOS_h
#include<iostream>
#include<algorithm>
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
            if(A[i-1]>A[i]){
                swap(A[i-1],A[i]);
                k=i;
            }
        }
        der=k-1;
    }
 }


#endif