// Materia: Programación I, Paralelo 4
// Autor: Ilsen Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:08/09/2026

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int aleatorios (int x, int y);
void LanzamientoMoneda(int lanzamientos, int&cara, int&cruz);

int main () {
    srand(time(NULL));
    system("cls");

    float N;
    int cara = 0;
    int cruz = 0;
    float PorcentajeCara;
    float PorcentajeCruz;

    cout << "Veces que quiere lanzar la moneda: ";
    cin >> N;

    for (int i = 1; i <= N; i++) {
        LanzamientoMoneda (N, cara, cruz);
    }
    PorcentajeCara = (cara/N)*100;
    PorcentajeCruz = (cruz/N)*100;

    cout << "En el lanzamiento de " << N << " veces de la moneda se obtuvo:" << endl;
    cout << "Porcentaje de caer en cara: " << PorcentajeCara << "%" << endl;
    cout << "Porcentaje de caer en cruz: " << PorcentajeCruz << "%" << endl;

    return 0;
}

int aleatorios (int min, int max){
    return ((rand() % (max-min+1))+min);
}

void LanzamientoMoneda(int lanzamientos, int&cara, int&cruz){
    lanzamientos = aleatorios (0, 1);
    if (lanzamientos == 1) {
        cara++;
    }
    else {
        cruz++;
    }

}