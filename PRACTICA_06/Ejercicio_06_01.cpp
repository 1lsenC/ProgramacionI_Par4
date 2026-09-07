// Materia: Programación I, Paralelo 4
// Autor: Ilsen Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:07/09/2026

#include <iostream>
using namespace std;
void intercambiar(int&, int&);

int main () {
    int num1=10, num2=15;
    cout<<"El valor del num1 es: "<<num1<<endl;
    cout<<"El valor del num2 es: "<<num2<<endl;

    intercambiar(num1,num2);

    cout<<"\nEl nuevo valor de num1 es: "<<num1<<endl;
    cout<<"El nuevo valor de num2 es: "<<num2<<endl;

    return 0;
}

void intercambiar(int& num1, int& num2) {
    int aux;
    
    aux = num1;
    num1 = num2;
    num2 = aux;
}