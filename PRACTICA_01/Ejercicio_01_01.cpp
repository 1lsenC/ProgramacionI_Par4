// Materia: Programación I, Paralelo 4
// Autor: Ilsen Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación: 19/08/2026

#include <iostream>
using namespace std;
int main() {
    int anio;
    cout << "Ingrese un anio para ver si es bisiesto (Cuatro digitos)" << endl;
    cin >> anio;

    if (anio%4 == 0 && anio >= 1000 && anio <= 9999) {
        cout << "Es bisiesto" << endl;
    }
    else if (anio%4 != 0 && anio >= 1000 && anio <= 9999){
        cout << "No es bisiesto" << endl;
    }
    else {
        cout << "No es posible calcular el anio" << endl;
    }
    return 0;
}