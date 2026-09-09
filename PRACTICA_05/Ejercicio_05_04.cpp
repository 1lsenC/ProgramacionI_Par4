// Materia: Programación I, Paralelo 4
// Autor: Ilsen Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:07/09/2026

#include <iostream>
using namespace std;
double CalcularPrecioTotal (double num, double IVA=0.13);

int main () {
    double precio;
    double num;
    cout << "Ingrese el precio inicial del producto: ";
    cin >> num;
    precio = CalcularPrecioTotal (num);
    cout << "El precio del producto con los impuestos IVA (13%) es de: " << precio;

    return 0;
}

double CalcularPrecioTotal (double num, double IVA) {
    double CalcularIVA;
    double Precio;

    CalcularIVA = num*IVA;
    Precio = num+CalcularIVA;
    return Precio;
}