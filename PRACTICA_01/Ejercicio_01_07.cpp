// Materia: Programación I, Paralelo 4
// Autor: Ilsen Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación: 19/08/2026

#include <iostream>
using namespace std;
int main() {
    int N;
    int digitos = 0;
    int suma = 0;
    int ultimodigito;
    
    cout << "Ingrese un numero entero positivo: ";
    cin >> N;

    int num = N;
    if (num <= 0) {
        cout << "No se admiten numeros negativos" << endl;
        return 1;
    }

    while (num > 0) {
        ultimodigito = num % 10;
        suma += ultimodigito;
        digitos++;
        num /= 10;
    }
    cout << "El numero " << N << " tiene " << digitos << " digitos" << endl;
    cout << "La suma de sus digitos es: " << suma << endl;

    return 0;
}