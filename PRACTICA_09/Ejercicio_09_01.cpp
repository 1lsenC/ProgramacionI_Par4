// Materia: Programación I, Paralelo 4
// Autor: Ilsen Arlett Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:12/10/2026
// Numero de ejercicio: 1

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int Aleatorios (int min, int max);
void LlenarMatriz (int matrix [100][100], int tam, int A, int B);
void MostrarMatriz (int matrix [100][100], int tam);
void IntercambiarFilas (int matrix [100][100], int tam, int fila1, int fila2);

int main () {
    system ("cls");
    srand(time(NULL));
    int n = 0;
    int num1 = 0;
    int num2 = 9;
    int matrix [100][100];
    
    cout << "Tamanio de la matriz (nxn): ";
    cin >> n;
    int primera = 0;
    int ultima = n-1;
    LlenarMatriz (matrix, n, num1, num2);
    MostrarMatriz (matrix, n);
    cout << "\n";
    
    cout << "Primera fila cambiada con la ultima: " << endl;
    IntercambiarFilas (matrix, n, primera, ultima);
    MostrarMatriz (matrix, n);
    return 0;
}

int Aleatorios (int min, int max) {
    return ((rand()% (max-min+1))+min);
}

void LlenarMatriz (int matrix [100][100], int tam, int A, int B) {
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            matrix[i][j] = Aleatorios(A,B);
        }
    }
}

void MostrarMatriz (int matrix [100][100], int tam) {
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            cout << matrix [i][j] << "\t";
        }
        cout << "\n";
    }
}

void IntercambiarFilas (int matrix [100][100], int tam, int fila1, int fila2) {
    int aux;
    for (int i = 0; i < tam; i++) {
        aux = matrix [fila1][i];
        matrix[fila1][i] = matrix[fila2][i];
        matrix[fila2][i] = aux;
    }
}