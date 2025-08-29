#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <mutex>

using namespace std;

void imprimirNumeros() {
    for (int i = 0; i <= 30; i++) {
        {
            cout << "Numero: " << i << endl;
        }
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

void imprimirLetras() {
    for (int i = 0; i < 30; i++) {
        char letra = 'A' + (rand() % 26);
        {
            cout << "Letra: " << letra << endl;
        }
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

int main() {
    srand(time(0));

    auto inicio = chrono::high_resolution_clock::now();

    thread t1(imprimirNumeros);
    thread t2(imprimirLetras);

    t1.join();
    t2.join();

    auto fin = chrono::high_resolution_clock::now();
    chrono::duration<double> duracion = fin - inicio;

    cout << "Tiempo de ejecución (2 hilos): " 
         << duracion.count() << " segundos" << endl;

    return 0;
}
