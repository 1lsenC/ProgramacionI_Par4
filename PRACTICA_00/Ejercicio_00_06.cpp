// Materia: Programación I, Paralelo 4
// Autor: Ilsen Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación: 19/08/2026

#include <iostream>
using namespace std;
int main() {
    float practica, teorica, participacion,nota_final;

    cout<<"Digite la nota de practica: "; cin>>practica;
    cout<<"Digite la nota teorica: "; cin>>teorica;
    cout<<"Digite la nota de participacion: "; cin>>participacion;

    practica *= 0.30;
    teorica *= 0.60;
    participacion *= 0.10;

    nota_final = practica + teorica + participacion;

    cout<<"\nLa nota final es: "<<nota_final;
    return 0;
}