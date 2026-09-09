// Materia: Programación I, Paralelo 4
// Autor: Ilsen Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:08/09/2026

#include <iostream>
using namespace std;
void calcularTiempo(int totalSegundos, int &horas, int &minutos, int&segundos);

int main () {
    int segundosiniciales = 0;
    int horas = 0;
    int minutos = 0;
    int segundos = 0;

    cout << "Ingrese los segundos totales: ";
    cin >> segundosiniciales;

    calcularTiempo (segundosiniciales, horas, minutos, segundos);
    cout << "\nLas horas totales: " << horas << "hr(s)" << endl;
    cout << "Los minutos totales: " << minutos << "min" << endl;
    cout << "Los segundos totales: " << segundos << "s" << endl;

    return 0;
}
void calcularTiempo(int totalSegundos, int &horas, int &minutos, int&segundos){
    horas = totalSegundos/3600;
    minutos = (totalSegundos%3600)/60;
    segundos = totalSegundos%60;
}