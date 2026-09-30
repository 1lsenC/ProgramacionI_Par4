// Materia: Programación I, Paralelo 4
// Autor: Ilsen Arlett Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:28/09/2026
// Numero de ejercicio: 7

#include <iostream>
using namespace std;
void ElementosdelVector (int Vector [], int &cantidad);
void MostrarVector (int Vector [], int cantidad);

int main () {
    int Vector [100];
    int num = 0;
    cout << "Ingrese elementos para un vector con capacidad de almacenar 100 elementos" << endl;
    ElementosdelVector (Vector, num);
    cout << "El vector resultante de " << num << " elementos los cuales son:" << endl;
    MostrarVector (Vector, num);

    return 0;
}

void ElementosdelVector (int Vector [], int &cantidad) {
    int num;
    cout << "Datos del vector" << endl;
    cout << "Elemento 1: ";
    cin >> num;
    while (num >= 0 && cantidad < 100) {
        Vector[cantidad] = num;
        cantidad++;

        if (cantidad < 100) {
            cout << "Elemento " << cantidad + 1 << ": ";
            cin >> num;
        }
    }
}

void MostrarVector (int Vector [], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        cout << Vector[i] << "  ";
    }
}