// Materia: Programación I, Paralelo 4
// Autor: Ilsen Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:07/09/2026

#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;

double CalcularArea (double lado);
double CalcularArea (double base, double altura);
float CalcularArea (float radio, float PI=M_PI);

int main () {
    double l;
    double b;
    double h;
    float r;
    double cuadrado;
    double rectangulo;
    float circulo;

    cout << "Ingrese numeros para poder determinar el area de un cuadrado, rectangulo y un circulo" << endl;
    cout << "Lado del cuadrado: ";
    cin >> l;
    cout << "\nBase del rectangulo: ";
    cin >> b;
    cout << "Altura del rectangulo: ";
    cin >> h;
    cout << "\nRadio del circulo: ";
    cin >> r;

    cuadrado = CalcularArea (l);
    rectangulo = CalcularArea (b, h);
    circulo = CalcularArea (r);

    cout << "\nEl area de un cuadrado es: " << cuadrado << endl;
    cout << "El area de un rectangulo es: " << rectangulo << endl;
    cout << "El area de un circulo es: " << circulo << endl;

    return 0;
}

double CalcularArea (double lado) {
    double area;
    area = lado*lado;
    return area;
}
double CalcularArea (double base, double altura) {
    double area;
    area = base*altura;
    return area;
}
float CalcularArea (float radio, float PI) {
    float area;
    area = radio*radio*PI;
    return area;
}