// Materia: Programación I, Paralelo 4
// Autor: Ilsen Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:01/09/2026

#include <iostream>
using namespace std;
int numeromayor (int x, int y, int z);

int main (){
    int num1, num2, num3;
    int mayor;

    cout << "Ingrese tres numeros enteros" << endl;
    cout << "1er numero: ";
    cin >> num1;
    cout << "2do numero: ";
    cin >> num2;
    cout << "3er numero: ";
    cin >> num3;

    mayor = numeromayor (num1, num2, num3);
    cout << "El numero mayor es: " << mayor;

    return 0;
}

int numeromayor (int x, int y, int z) {
    int nummayor;
    if (x>=y && x>=z) {
        nummayor = x;
    }
    else if (y>=x && y>=z) {
        nummayor = y;
    }
    else {
        nummayor = z;
    }

    return nummayor;
}