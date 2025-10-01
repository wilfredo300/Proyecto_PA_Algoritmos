#include <iostream>
#include <fstream>   // para manejar archivos
#include <cstdlib>   // rand, srand
#include <ctime>     // time (para semilla aleatoria)

using namespace std;

int main() {
    // Semilla para que los números sean diferentes cada ejecución
    srand(0);
    for(int n=1000;n<=10000;n+=1000){
        string name;
        int cantidad = n;
        name="lista_aleatoria_"+ to_string(cantidad) + ".txt";
        ofstream archivo(name); // crea/abre el archivo

        if (!archivo) {
            cerr << "Error al abrir el archivo\n";
            return 1;
        }

        // cuántos números quieres generar
        for (int i = 0; i < cantidad; i++) {
            int numero = rand() % 1000; // aleatorio entre 0 y 999
            archivo << numero <<"," " ";  // escribir en el archivo
        }

        archivo.close(); // cerrar archivo
        cout << "Se generaron " << cantidad << name <<"\n";
    }
    return 0;
}
