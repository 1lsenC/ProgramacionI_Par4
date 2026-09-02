// Materia: Programación I, Paralelo 4
// Autor: Ilsen Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:01/09/2026

#include <iostream>
using namespace std;
int SumadeNumeros (int N);

int main (){
    int numero;
    int suma;
    cout << "Ingrese un numero: ";
    cin >> numero;

    suma = SumadeNumeros (numero);
    cout << "La suma de los numeros del 1 al " << numero << " es: " << suma;

    return 0;
}

int SumadeNumeros (int N) {
    int Suma;
    for (int i = 1; i <= N; i++) {
        Suma += i;
    }
    return Suma;
}