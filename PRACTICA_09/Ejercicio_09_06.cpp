// Materia: Programación I, Paralelo 4
// Autor: Ilsen Arlett Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación: 12/10/2026
// Numero de ejercicio: 6

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void LlenarMatriz (int matrix [4][7], int A, int B);
void MostrarMatriz (int matrix [4][7]);
void ElementoMayor (int matrix [4][7], int& mayor, int& fila, int& col);
int Promedio (int matrix [4][7]);
int Diasconmasde30grados (int matrix [4][7]);
int Aleatorios (int min, int max);

int main () { 
    system ("cls");
    srand(time(NULL));
    int num1 = 5;
    int num2 = 35;
    int matrix [4][7];
    int Tempmayor = 0;
    int Fila, Columna;
    int promediotemp = 0;
    int tempdias = 0;

    cout << "\tEstudio climatico" << endl;
    LlenarMatriz (matrix, num1, num2);
    MostrarMatriz (matrix);

    ElementoMayor (matrix, Tempmayor, Fila, Columna);
    cout << "\nEl dia con la temperatura mas alta es  " << Tempmayor << "C"<< " y se encuentra en el dia " << Columna << " de la semana " << Fila << endl;

    promediotemp = Promedio (matrix);
    cout << "El promedio de la temperatura de cada semana es: " << promediotemp << "C" << endl;

    tempdias = Diasconmasde30grados (matrix);
    cout << "Cantidad de dias que superaron los 30C: " << tempdias<< endl;

    return 0;
}

int Aleatorios (int min, int max) {
    return ((rand()% (max-min+1))+min);
}

void LlenarMatriz (int matrix [4][7], int A, int B) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 7; j++) {
            matrix[i][j] = Aleatorios(A,B);
        }
    }
}

void MostrarMatriz (int matrix [4][7]) {
    cout << "\tLun\tMar\tMie\tJue\tVie\tSab\tDom" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "Sem " << i + 1 << "\t";
        for (int j = 0; j < 7; j++) {
            cout << matrix [i][j] << "\t";
        }
        cout << "\n";
    }
}

void ElementoMayor (int matrix [4][7], int& mayor, int& fila, int& col) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 7; j++) {
            matrix[i][j];
            if (matrix [i][j] > mayor) {
                mayor = matrix[i][j];
                fila = i + 1;
                col = j + 1;
            }
        }
    }
}

int Promedio (int matrix [4][7]) {
    double prom = 0;
    double suma = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 7; j++) {
            suma+=matrix [i][j];
        }
    }
    prom = suma/7;
    return prom;
}

int Diasconmasde30grados (int matrix [4][7]) {
    int dias = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 7; j++) {
            if (matrix[i][j] > 30) {
                dias++;
            }
        }
    }
    return dias;
}