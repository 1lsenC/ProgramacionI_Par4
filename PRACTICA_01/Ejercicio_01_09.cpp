// Materia: Programación I, Paralelo 4
// Autor: Ilsen Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación: 19/08/2026

#include <iostream>
using namespace std;
int main() {
    int N;
    cout << "Ingrese un numero entero positivo: ";
    cin >> N;

    if (N <= 0) {
        cout << "Solo numeros mayores a cero" << endl;
    }

    int cont = N;
    int digitos = 0;
    while (cont > 0) {
        digitos++;
        cont /= 10;
    }

    int num = N;
    int numInv = 0;
    while (num > 0) {
        numInv = (numInv * 10) + (num % 10);
        num /= 10;
    }

    int d;
    for (int k = 0; k < digitos; k++) {
        d = numInv % 10;
        cout << " " << endl;
        if (d == 0) {
            cout << "Siguiente digito es 0, \nno tiene cuadricula" << endl;
        } 
        else {
            for (int i = 0; i < d; i++) {
                for (int j = 0; j < d; j++) {
                    cout << d << " "; 
                }
                cout << " " << endl;
            }
        }
        numInv /= 10;
    }

    return 0;
}