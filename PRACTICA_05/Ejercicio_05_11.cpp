// Materia: Programación I, Paralelo 4
// Autor: Ilsen Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:09/09/2026

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int aleatorios (int min, int max);
void NumeroPrimo (int A, int& mayorPrimo);
void SumayPromedio (int& suma, double& prom, int A);

int main () {
    srand(time(NULL));
    system("cls");

    double N;
    int al;
    int suma = 0;
    double impar = 0;
    int NroImpares = 0;
    int primo = 0;
    double promedio;
    cout << "Cantidad de numeros que desea generar: "; 
    cin >> N;

    for (int i = 1; i <= N; i++) {
        al = aleatorios (1, 1000);
        NumeroPrimo (al, primo);

        if (al%2 != 0) {
            NroImpares++;
        }
        SumayPromedio (suma, impar, al);
    }
    promedio = impar / NroImpares;
    cout << "La suma de los numeros pares es: " << suma << endl;
    cout << "El promedio de los numeros impares es: " << promedio << endl;
    cout << "El numero primo mayor es: " << primo << endl;

    return 0;
}

int aleatorios (int min, int max){
    return ((rand() % (max-min+1))+min);
}

void SumayPromedio (int& suma, double& prom, int A) {
    if (A%2 == 0) {
        suma += A;
    }
    else {
        prom +=A;
    }
}

void NumeroPrimo (int A, int& mayorPrimo) {
    if (A > 1) {
        int divisores = 0;
        for (int i = 1; i <= A; i++) {
            if (A % i == 0) {
                divisores++;
            }
        }
        if (divisores == 2) {
            if (A > mayorPrimo) {
                mayorPrimo = A;
            }
        }
    }
}