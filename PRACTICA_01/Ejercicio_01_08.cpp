// Materia: Programación I, Paralelo 4
// Autor: Ilsen Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación: 19/08/2026

#include <iostream>
using namespace std;
int main() {
    int N;
    cout << "Ingrese una nota entre el 0 y el 100: " << endl;
    cin >> N;

    while (N >= 0 && N <= 100) {
        cout << "Nota registrada correctamente" << endl;
        cout << "Ingrese una nota entre el 0 y el 100: " << endl;
        cin >> N;
    }
    cout << "Numero invalido" << endl;

    return 0;
}