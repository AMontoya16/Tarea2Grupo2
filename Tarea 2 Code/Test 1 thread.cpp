#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <thread>  

using namespace std;

void imprimirNumeros() {
    for (int i = 0; i <= 30; i++) {
        cout << "Numero: " << i << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

void imprimirLetras() {
    for (int i = 0; i < 30; i++) {
        char letra = 'A' + (rand() % 26);
        cout << "Letra: " << letra << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

int main() {
    srand(time(0));

    auto inicio = chrono::high_resolution_clock::now();

    // Llamada secuencial en un solo hilo
    imprimirNumeros();
    imprimirLetras();

    auto fin = chrono::high_resolution_clock::now();
    chrono::duration<double> duracion = fin - inicio;

    cout << "Tiempo de ejecucion (1 hilo): " 
         << duracion.count() << " segundos" << endl;

    return 0;
}
