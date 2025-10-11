#include"algoritmos.h"
#include"listasAleatorias.h"
using namespace std;
int main(){
    int a(0),b(0);
    int A[10]={1,6,3,7,8,5,7,5,4,6};
    int *lista = listaAleatoria_10000;
    cocktailSort(lista,10000,a,b);
    for(int i=0;i<1000;i++){
        cout<<lista[i]<<" ";
    }
    return 0;
}