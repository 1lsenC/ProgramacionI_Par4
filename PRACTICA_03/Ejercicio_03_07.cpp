// Materia: Programación I, Paralelo 4
// Autor: Ilsen Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:26/08/2026

#include <iostream>
using namespace std;
int main (){
    int numero;
    int suma = 0;
    cout << "Ver si un numero es Perfecto" << endl;
    cout << "Ingresa un numero: ";
    cin >> numero;

    for (int i = 1; i < numero; i++) {
        if (numero % i == 0) {
            suma+=i;
        }
    }
    if (suma == numero) {
        cout << numero << " si es un numero perfecto" << endl;
    }
    else {
        cout << numero << " no es un numero perfecto" << endl;
    }
    
    return 0;
}