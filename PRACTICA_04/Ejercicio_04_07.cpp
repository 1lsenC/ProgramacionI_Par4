// Materia: Programación I, Paralelo 4
// Autor: Ilsen Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:01/09/2026

#include <iostream>
using namespace std;
double Distancia (double V, double t);

int main (){
    double velocidad;
    double tiempo;
    double distancia;

    cout << "Para calcular la distancia necesitamos los datos de" << endl;
    cout << "Velocidad: ";
    cin >> velocidad;
    cout << "Tiempo: ";
    cin >> tiempo;
    cout << "\n";

    distancia = Distancia (velocidad, tiempo);
    cout << "La distancia es: " << distancia;
return 0;
}

double Distancia (double V, double t) {
    double dist;
    dist = V*t;
    return dist;
}