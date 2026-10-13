// Materia: Programación I, Paralelo 4
// Autor: Ilsen Arlett Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación: 12/10/2026
// Numero de ejercicio: 3

#include <iostream>
using namespace std;
void LlenarMatriz (int matrix [5][5], int num);
void MostrarMatriz (int matrix [5][5], int num);

int main () {
    system ("cls");
    int n = 5;
    int matrix [5][5];

    LlenarMatriz (matrix, n);
    MostrarMatriz (matrix, n);
    return 0;
}
void LlenarMatriz (int matrix [5][5], int num) {
    int InicioFila = 1;
    for (int i = 0; i < num; i++) {
        int Columna = InicioFila;
        for (int j = 0; j < num; j++) {
            matrix[i][j] = Columna;
            Columna++;
        }
        InicioFila +=2;
    }
}
void MostrarMatriz (int matrix [5][5], int num) {
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            cout << matrix [i][j] << "\t";
        }
        cout << "\n";
    }
}