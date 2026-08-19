// Materia: Programación I, Paralelo 4
// Autor: Ilsen Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación: 19/08/2026

#include <iostream>
using namespace std;
int main() {
    int dia;
    cout << "Dia de la semana (1-7): ";
    cin >> dia;

    switch (dia){
    case 1:
        cout << "Lunes" << endl;
        break;
    case 2:
        cout << "Martes" << endl;
        break;
    case 3:
        cout << "Miercoles" << endl;
        break;
    case 4:
        cout << "Jueves" << endl;
        break;
    case 5:
        cout << "Viernes" << endl;
        break;
    case 6:
        cout << "Sabado" << endl;
        break;
    case 7:
        cout << "Domingo" << endl;
        break;
    default:
        cout << "Error, fuera del rango de numeros de la semana" << endl;
    }

    return 0;
}