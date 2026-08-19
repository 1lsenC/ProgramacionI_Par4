// Materia: Programación I, Paralelo 4
// Autor: Ilsen Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación: 19/08/2026

#include <iostream>
using namespace std;
int main() {
    int n1,n2, suma = 0, resta = 0, multiplicacion = 0, division = 0;
    cout << "Digite un numero: "; cin >> n1;
    cout << "Digite un numero: "; cin >> n2;

    suma = n1 + n2;
    resta = n1 - n2;
    multiplicacion = n1*n2;
    division = n1 / n2;

    cout << "La suma es: " << suma << endl;
    cout << "La resta es: " << resta << endl;
    cout << "La multiplicacion es: " << multiplicacion << endl;
    cout << "La division es: " << division << endl;

    return 0;
}