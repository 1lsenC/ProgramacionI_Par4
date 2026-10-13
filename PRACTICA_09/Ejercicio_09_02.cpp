// Materia: Programación I, Paralelo 4
// Autor: Ilsen Arlett Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación: 07/10/2026
// Numero de ejercicio: 2

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void LlenarMatriz (int matrix [100][100], int tam, int A, int B);
void MostrarMatriz (int matrix [100][100], int tam);
int SumaUltimaColumna(int matrix [100][100], int tam, int col);
int ProductoUltimaFila (int matrix [100][100], int tam, int fil);
void ElementoMayor (int matrix [100][100], int tam, int& mayor, int& fila, int& col);
int Promedio (int matrix [100][100], int tam);
int Aleatorios (int min, int max);

int main () { 
    system ("cls");
    srand(time(NULL));
    int n;
    int numeros = 0;
    int num1 = 0;
    int num2 = 0;
    int matrix [100][100];
    int resultado=0;
    int producto=0;
    int NumMayor = 0;
    int Fila, Columna;
    int promediodenum = 0;

    cout << "Tamanio de la matriz que desea ingresar (NxN): ";
    cin >> n;
    cout << "Rango de numeros que tendra la matriz" << endl;
    cout << "Numero menor: ";
    cin >> num1;
    cout << "Numero mayor: ";
    cin >> num2;
    cout << "\n";

    LlenarMatriz (matrix, n, num1, num2);
    MostrarMatriz (matrix, n);

    resultado = SumaUltimaColumna (matrix, n, n);
    cout << "\nSuma de la ultima columna: " << resultado << endl;

    producto = ProductoUltimaFila (matrix, n, n);
    cout << "Producto de la ultima fila: " << producto << endl;

    ElementoMayor (matrix, n, NumMayor, Fila, Columna);
    cout << "Numero mayor es " << NumMayor << " y se encuentra en la fila " << Fila << " y columna " << Columna << endl;

    promediodenum = Promedio (matrix, n);
    cout << "El promedio de los nuemros es: " << promediodenum << endl;

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

int SumaUltimaColumna(int matrix [100][100], int tam, int col) {
    int suma = 0;
    col = tam -1;
    for (int  i = 0; i < tam; i++) {
        suma+=matrix [i][col];
    } 
    return suma;
}

int ProductoUltimaFila (int matrix [100][100], int tam, int fil) {
    int producto = 1;
    fil = tam - 1;
    for (int  i = 0; i < tam; i++) {
        producto*=matrix [fil][i];
    } 
    return producto;
}

void ElementoMayor (int matrix [100][100], int tam, int& mayor, int& fila, int& col) {
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            matrix[i][j];
            if (matrix [i][j] > mayor) {
                mayor = matrix[i][j];
                fila = i + 1;
                col = j + 1;
            }
        }
    }
}

int Promedio (int matrix [100][100], int tam) {
    int prom = 0;
    int suma = 0;
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            suma+=matrix [i][j];
        }
    }
    prom = suma/(2*tam);
    return prom;
}