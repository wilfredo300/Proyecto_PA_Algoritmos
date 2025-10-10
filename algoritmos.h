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


#endif