// Materia: Programación I, Paralelo 4
// Autor: Ilsen Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:25/08/2026

#include <iostream>
using namespace std;
int main (){
    int numero;
    int suma;

    cout << "Ingrese el ultimo numero que sera sumado: ";
    cin >> numero;

    for (int i = 1; i <= numero; i++) {
        suma += i;
    }
    cout << "La suma de todos los numeros hasta el " << numero << " es: " << suma;

    return 0;
}