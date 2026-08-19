// Materia: Programación I, Paralelo 4
// Autor: Ilsen Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación: 19/08/2026

#include <iostream>
using namespace std;
int main() {
    int edad;
    char sexo;
    double altura;

    cout << "Ingrese su edad: " << endl;
    cin >> edad;
    cout << "Ingrese su sexo (F/M)" << endl;
    cin >> sexo;
    cout <<"Ingrese su altura (m)" << endl;
    cin >> altura;

    cout << "DATOS DE LA PERSONA" << endl;
    cout << "\tEdad: " << edad << endl;
    cout << "\tSexo: " << sexo << endl;
    cout << "\tAltura: " << altura << "m" << endl;
   
    return 0;
}