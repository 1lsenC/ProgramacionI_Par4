// Materia: Programación I, Paralelo 4
// Autor: Ilsen Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:01/09/2026

#include <iostream>
using namespace std;
double Volumencilindro (double r, double h);
int main (){
    double altura;
    double radio;
    double volumen;

    cout << "Calcular el volumen de un cilindro" << endl;
    cout << "El radio del cilindro es de: ";
    cin >> radio;
    cout << "La altura del cilindro es de: ";
    cin >> altura;

    volumen = Volumencilindro (radio, altura);
    cout << "El volumen del cilindro es: " << volumen; 
    
return 0;
}

double Volumencilindro (double r, double h) {
    const double PI = 3.14159;
    double vol;

    vol = PI*r*r*h;
    return vol;
}