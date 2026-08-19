// Materia: Programación I, Paralelo 4
// Autor: Ilsen Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación: 19/08/2026

#include <iostream>
using namespace std;
int main() {
    double practicas;
    double teoria;
    double participacion;

    cout << "NOTAS DEL ALUMNO" << endl;
    cout << "Puntaje de practicas (1-100): ";
    cin >> practicas;
    cout << "Puntaje de parte teorica (1-100): ";
    cin >> teoria;
    cout << "Puntaje de participacion (1-100): ";
    cin >> participacion;

    practicas *= 0.3;
    teoria *= 0.6;
    participacion *= 0.1;

    cout << "NOTA FINAL: " << practicas + teoria + participacion <<endl;
    return 0;
}