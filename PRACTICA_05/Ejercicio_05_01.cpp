// Materia: Programacion I, Paralelo 4
// Autor: Ilsen Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creacion:07/09/2026

#include <iostream>
using namespace std;
void IntercambiarValores (int& x, int& y);

int main () {
    int x = 7;
    int y = 10;
    cout << "El primer valor es: " << x << endl;
    cout << "El segundo valor es: " << y << endl;

    IntercambiarValores (x, y);
    cout << "\nEl nuevo valor del primer numero es: " << x << endl;
    cout << "El nuevo valor del segundo numero es: " << y << endl;

    return 0;
}
void IntercambiarValores (int& x, int& y) {
    int aux;
    aux = y;
    y = x;
    x = aux;
}