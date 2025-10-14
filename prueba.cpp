#include<iostream>
#include"listasAleatorias.h"
#include"algoritmos.h"
using namespace std;
int main(){
    int *A = new int[10000];
    int comparaciones(0),intercambios(0);
    for(int i=0;i<100;i++){
        A[i]=listaAleatoria_1000[i];
    }
    //mergeSort(A,0,99,comparaciones,intercambios);
    cocktailSort(A,100,comparaciones,intercambios);
    for(int i=0;i<100;i++){
        cout<<A[i]<<" ";
    }
    cout<<"comparaciones: "<<comparaciones<<endl;
    cout<<"intercambios: "<<intercambios<<endl;
    return 0;
}