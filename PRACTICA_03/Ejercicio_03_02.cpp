// Materia: Programación I, Paralelo 4
// Autor: Ilsen Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:25/08/2026

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main (){
    srand(time(NULL));
    system("cls");

    int limSup = 100;
    int limInf = 1;
    int numeros;
    int suma = 0, pares = 0, impares = 0, nprimos = 0, divisores = 0;

    cout << "Cuantos numeros habran? (1-100)" << endl;
    cin >> numeros;

    for (int i = 0; i < numeros; i++) {
        int aleatorios = ((rand() % (limSup-limInf+1))+limInf);

        suma += aleatorios;

        if (aleatorios %2 == 0) {
            pares += aleatorios;
        }
        else {
            impares += aleatorios;
        }

        if (aleatorios > 1) {
            divisores = 0;
            for (int j = 2; j < aleatorios; j++) {
                if (aleatorios % j == 0) {
                divisores++; }
            }
            if (divisores == 0) {
                nprimos += aleatorios;
            }
        }
    }
    cout << "Suma de todos los numeros: " << suma << endl;
    cout << "La suma de los numeros pares: " << pares << endl;
    cout << "Suma de los numeros impares: " << impares << endl;
    cout << "Suma de los numeros primos: " << nprimos << endl;
    return 0;
}