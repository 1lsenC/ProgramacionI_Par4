// Materia: Programación I, Paralelo 4
// Autor: Ilsen Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:25/08/2026

#include <iostream>
using namespace std;
int main (){
    int numero;
    cout << "Ingrese un numero del 1 al 10" << endl;
    cin >> numero;
    
    if (numero > 10 || numero <= 0) {
        cout << "Numero fuera del rango permitido" << endl;
    }
    else {
        cout << "TABLA DE MUTIPLICAR DEL " << numero << endl;
        for (int i; i <= 10; i++) {
            cout << numero << " * " << i << " = " << numero*i << endl;
        }
        
    }
    return 0;
}
