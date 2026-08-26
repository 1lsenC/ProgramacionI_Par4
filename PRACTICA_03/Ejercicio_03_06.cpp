// Materia: Programación I, Paralelo 4
// Autor: Ilsen Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:26/08/2026

#include <iostream>
using namespace std;
int main (){
    int n1;
    int n2;
    cout << "Ingrese dos valores enteros: " << endl;
    cin >> n1;
    cin >> n2;

    if (n1 > n2) {
        for (int i = n1; i >= n2; i--) {
            cout << i << " ";
        }
    }
    if (n1 < n2) {
        for (int j = n1; j <= n2; j++) {
            cout << j << " ";
        }
    }
    
    return 0;
}