// Materia: Programación I, Paralelo 4
// Autor: Ilsen Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:26/08/2026

#include <iostream>
using namespace std;
int main (){
    int numero;

    do {
        cout<<"Digite un numero: "; cin>> numero;
    } while ((numero<1) || (numero >10));

    for (int i = 1; i<= 20; i++){
        cout << numero << " * "<<i<< " = "<< numero*i << endl;
    }
    
    cout <<"\n\n";
    system("pause");
    return 0;
}