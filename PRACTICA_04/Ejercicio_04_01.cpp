// Materia: Programación I, Paralelo 4
// Autor: Ilsen Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:01/09/2026

#include <iostream>
using namespace std;
int Calculodelarea (int b, int a);

int main (){
    int base;
    int altura;
    int Area;
    
    cout << "Para calcular el area de un triangulo debe dar los datos de:" << endl;
    cout << "La base: ";
    cin >> base;
    cout << "La altura: ";
    cin >> altura;

    Area = Calculodelarea (base, altura);
    cout << "El area del triangulo es: " << Area;
return 0;
}

int Calculodelarea (int base, int altura) {
    int area;
    area= (base*altura)/2;
    return area;
}