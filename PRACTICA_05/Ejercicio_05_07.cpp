// Materia: Programación I, Paralelo 4
// Autor: Ilsen Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:08/09/2026

#include <iostream>
using namespace std;
void agregarNota(double &sumaTotal, int &cantidadNotas, double nuevaNota);

int main () {
    int N = 0;
    double sumaT = 0;
    int cantidad = 0;
    double nota = 0;

    cout << "Cuantas notas se van a agragar: ";
    cin >> N;
    cout << "\n";
    
    for (int i = 1; i <= N; i++) {
        cout << "- Agregar nota: ";
        cin >> nota;
        agregarNota(sumaT, cantidad, nota);
    }
    cout << "\n";
    cout << "\tSe agregaron " << cantidad << " notas" << endl;
    cout << "\tLa suma de las notas es: " << sumaT << endl;

    return 0;
}

void agregarNota(double &sumaTotal, int &cantidadNotas, double nuevaNota){
    sumaTotal +=nuevaNota;
    cantidadNotas++;
}