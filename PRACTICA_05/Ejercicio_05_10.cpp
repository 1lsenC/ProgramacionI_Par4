// Materia: Programación I, Paralelo 4
// Autor: Ilsen Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:09/09/2026

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int aleatorios (int min, int max);
void NumerosPrimos (int n, int& contador);

int main () {
    srand(time(NULL));
    system("cls");
    int N;
    int Primos = 0;
    int numero;

    cout << "Cuantos numeros se van a generar: ";
    cin >> N;

    cout << "\nNumeros generados" << endl;
    for (int i = 1; i <= N; i++) {
        int numero = aleatorios(1, 10000);
        cout << "Numero " << i << ": " << numero << endl;
        NumerosPrimos (numero, Primos);
    }
    cout << "Total de numeros primos: " << Primos << endl;

    return 0;
}

int aleatorios (int min, int max){
    return ((rand() % (max-min+1))+min);
}

void NumerosPrimos (int n, int& contador) {
    if (n > 1) {
        int p = 0;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                p++; 
            }
        }
        if (p == 2) {
        contador++;
        }
    }
}