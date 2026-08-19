// Materia: Programación I, Paralelo 4
// Autor: Ilsen Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación: 19/08/2026

#include <iostream>
using namespace std;
int main() {
    int numero;
    cout << "Ingrese un numero: " << endl;
    cin >> numero;
 
    if (numero % 2 == 0){
        cout << "Es un numero par" << endl;
    }
    else {
        cout << "Es un numero impar" << endl;
    }
    return 0;
}