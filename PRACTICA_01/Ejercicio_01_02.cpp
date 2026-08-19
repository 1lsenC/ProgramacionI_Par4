// Materia: Programación I, Paralelo 4
// Autor: Ilsen Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación: 19/08/2026

#include <iostream>
using namespace std;
int main() {
    double precio;
    double resultado;

    cout << "Ingrese el precio el producto: ";
    cin >> precio;
    cout << "El IVA es del 13%" << endl;

    resultado = (precio*0.13) + precio;

    cout << "El precio del producto con el IVA es: " << resultado << endl;
    return 0;
}