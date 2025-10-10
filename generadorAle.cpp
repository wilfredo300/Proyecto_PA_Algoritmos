#include <iostream>
#include <fstream>   // para manejar archivos
#include <cstdlib>   // rand, srand
#include <ctime>     // time (para semilla aleatoria)

using namespace std;

int main() {
    // Semilla para que los números sean diferentes cada ejecución
    srand(0);
       // crea/abre el archivo
        ofstream archivo("listasAleatorias.h"); 

        if (!archivo) {
            cerr << "Error al abrir el archivo\n";
            return 1;
        }
    //encabezado del .h
    archivo<<"#ifndef LISTASALEATORIAS_H\n";
    archivo<<"#define LISTASALEATORIAS_H\n";
    archivo<<"#include<iostream>\n\n";
    //bucle para generar las listas de n numeros
    for(int n=1000;n<=100000;n*=10){
        string name;
        int cantidad = n;
        name= "int listaAleatoria_"+to_string(n)+"["+to_string(n)+"] = {";
        archivo<<name;
        for (int i = 0; i < cantidad; i++) {
            int numero = rand() % 1000; // aleatorio entre 0 y 999
            archivo << numero << (i!=cantidad-1? "," : "};");  // escribir en el archivo
            if(i%500==0 && i!=0) archivo<<"\n";
        }
        archivo<<"\n";

    }
        archivo<<"#endif";
        archivo.close(); // cerrar archivo
        cout << "Se generaron "<<endl;
    return 0;
}
