// Materia: Programación I, Paralelo 4
// Autor: Ilsen Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:09/09/2026

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int aleatorios (int min, int max);
int Consumo (int p);

int main () {
    srand(time(NULL));
    system("cls");
    int al = 0;
    int cantidad = 0;
    int ConsumoT = 0;

    cout << "De cuantos ninos quiere ver la cantidad de panales que se unas: ";
    cin >> cantidad;
    for (int i = 1; i <= cantidad; i++) {
        al = aleatorios (1, 3);
        ConsumoT += Consumo (al);
    }
    cout << "El consumo total de panales es de: " << ConsumoT << endl;

    return 0;
}

int aleatorios (int min, int max) {
    return ((rand() % (max-min+1))+min);
}

int Consumo (int p) {
    int consumo = 0;
    if (p == 1) {
        return 6;
    }
    if (p == 2) {
        return 3;
    }
    if (p == 3) {
        return 2;
    }
}