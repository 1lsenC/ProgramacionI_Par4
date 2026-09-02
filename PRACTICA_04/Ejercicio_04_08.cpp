// Materia: Programación I, Paralelo 4
// Autor: Ilsen Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:02/09/2026

#include <iostream>
using namespace std;
int ContadordeDigitos (int N);

int main (){
    int numero;
    int digitos;

    cout << "Ingrese un numero entero: ";
    cin >> numero;
    cout << "\n";

    digitos = ContadordeDigitos (numero);
    cout << "El numero " << numero << " tiene " << digitos << " digito(s)";
return 0;
}

int ContadordeDigitos (int N) {
    int contador = 0;

    if (N == 0) {
        return 1;
    }

    while (N > 0) {
        N /= 10;
        contador ++;
    }
    return contador;
}