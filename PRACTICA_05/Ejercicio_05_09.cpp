// Materia: Programación I, Paralelo 4
// Autor: Ilsen Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:08/09/2026

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int aleatorios (int min, int max);
int Factorial (int numero);

int main () {
    srand(time(NULL));
    system("cls");

    int numero = aleatorios (1, 10);
    int resultado;
    resultado = Factorial (numero);

    cout << "El factorial de " << numero << " es: " << resultado << endl;

    return 0;
}

int aleatorios (int min, int max){
    return ((rand() % (max-min+1))+min);
}

int Factorial (int numero) {
    int resultado = 1;
    for (int i = 1; i <= numero; i++) {
        resultado *= i;
    }
    return resultado;
}
