// Materia: Programación I, Paralelo 4
// Autor: Ilsen Arlett Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación: 12/10/2026
// Numero de ejercicio: 4

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int Aleatorios (int min, int max);
void LlenarMatriz (int matrix [100][100], int A, int B, int x, int y);
void MostrarMatriz (int matrix [100][100], int N, int M);
void PuntoSilla (int matrix [100][100], int N, int M);

int aleatorios (int min, int max);

int main () {
    system ("cls");
    srand(time(NULL));
    int n = 0;
    int m = 0;
    int num1 = 1;
    int num2 = 10;
    int matrix [100][100];

    cout << "Numero de filas y columnas:" << endl;
    cout << "Filas: ";
    cin >> n;
    cout << "Columnas: ";
    cin >> m;

    LlenarMatriz (matrix, n, m, num1, num2);
    MostrarMatriz (matrix, n, m);
    cout << "\n" << "\tBusqueda del punto silla" << endl;
    PuntoSilla (matrix, n, m);

    return 0;
}

int Aleatorios (int min, int max) {
    return ((rand()% (max-min+1))+min);
}

void LlenarMatriz (int matrix [100][100], int A, int B, int x, int y) {
    for (int i = 0; i < A; i++) {
        for (int j = 0; j < B; j++) {
            matrix[i][j] = Aleatorios(x,y);
        }
    }
}

void MostrarMatriz (int matrix [100][100], int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << matrix [i][j] << "\t";
        }
        cout << "\n";
    }
}

void PuntoSilla (int matrix [100][100], int N, int M) {
    bool encontrado = false;
    int actual;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            actual = matrix[i][j];

            bool MenorFila = true;
            for (int k = 0; k < M; k++) {
                if (matrix[i][k] < actual) {
                    MenorFila = false;
                }
            }
            bool MayorColumna = true;
            for (int k = 0; k < N; k++) {
                if (matrix[k][j] > actual) {
                    MayorColumna = false;
                }
            }
            if (MenorFila && MayorColumna) {
                cout << "Punto de silla encontrado" << endl;
                cout << "Valor del dato: " << actual << endl;
                cout << "Se encuentra en la Fila: " << i + 1 << ", Columna: " << j + 1<< endl;
                encontrado = true;
            }
        }
    }
    if (encontrado != true) {
        cout << "No se encontro ningun punto de silla en la matriz" << endl;
    }
}