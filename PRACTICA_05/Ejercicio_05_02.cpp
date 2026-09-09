// Materia: Programación I, Paralelo 4
// Autor: Ilsen Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:07/09/2026

#include <iostream>
using namespace std;
void ModificarValores(int a, int &b);

int main () {
    int valor;
    int referencia;
    cout << "Ingrese dos valores enteros" << endl;
    cout << "Primer Valor: ";
    cin >> valor;
    cout << "Segundo Valor: ";
    cin >> referencia;

    ModificarValores (valor, referencia);
    cout << "\nPrimer valor: " << valor <<endl;
    cout << "Segundo valor: " << referencia <<  endl;

    return 0;
}
void ModificarValores(int a, int &b) {
    a*=2;
    b+=10;
}