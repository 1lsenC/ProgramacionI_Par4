// Materia: Programación I, Paralelo 4
// Autor: Ilsen Arlett Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:21/10/2026
// Numero de ejercicio: 7

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int aleatorios (int min, int max);
void LlenarmatrizNotas (int matrix [5][3]);
void MostrarMtriz (int matrix [5][3]);
void PromediodeNotas (int matrix [5][3], vector <float> &prom, vector <string> N);
void MostrarVector (vector <float> &prom, vector <string>N);
void OrdenarEstudiantes(vector<string> &nombres, int matrix[5][3], vector<float> &prom);
void Boletin(const vector<string> &nombres, const int matrix[5][3], const vector<float> &prom);

int main () {
    system ("cls");
    srand(time(NULL));
    vector <string> Nombres {"Annie", "Leo", "Eliza", "Percy", "Jason"};
    int matrix [5][3];
    vector <float> Promedio;
    
    LlenarmatrizNotas (matrix);
    MostrarMtriz (matrix);
    PromediodeNotas (matrix, Promedio, Nombres);
    OrdenarEstudiantes(Nombres, matrix, Promedio);

    cout << "\n" << "\tBOLETIN DE NOTAS" << endl;
    Boletin(Nombres, matrix, Promedio);

    return 0;
}

int aleatorios (int min, int max) {
    return ((rand() % (max-min+1))+min);
}

void LlenarmatrizNotas (int matrix [5][3]) {
    for (int i=0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            matrix [i][j] = aleatorios (0,100);
        }
    }
}

void MostrarMtriz (int matrix [5][3]) {
    for (int i=0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix [i][j] << "\t";
        }
        cout << "\n";
    }
}

void PromediodeNotas (int matrix [5][3], vector <float> &prom, vector <string> N) {
    float suma;
    float promedios = 0;

    for (int i=0; i < 5; i++) {
        suma = 0;
        for (int j = 0; j < 3; j++) {
            suma += matrix [i][j];
        }
        promedios = suma/3;
        prom.push_back(promedios);
    }
    MostrarVector (prom,N);
}

void MostrarVector (vector <float> &prom, vector <string>N) {
    cout << endl;
    for (int i = 0; i < 5; i++){
        cout << "Promedio de " << N[i] << ": " << prom[i] << endl;
    }
}

void OrdenarEstudiantes(vector<string> &nombres, int matrix[5][3], vector<float> &prom) {
    for (int i = 0; i < 5 - 1; i++) {
        for (int j = 0; j < 5 - 1 - i; j++) {
            if (nombres[j] > nombres[j + 1]) {
                string aux = nombres[j];
                nombres[j] = nombres[j + 1];
                nombres[j + 1] = aux;

                for (int k = 0; k < 3; k++) {
                    int auxNota = matrix[j][k];
                    matrix[j][k] = matrix[j + 1][k];
                    matrix[j + 1][k] = auxNota;
                }

                float auxProm = prom[j];
                prom[j] = prom[j + 1];
                prom[j + 1] = auxProm;
            }
        }
    }
}

void Boletin(const vector<string> &nombres, const int matrix[5][3], const vector<float> &prom) {
    cout << "Nombre\tNota 1\tNota 2\tNota 3\tPromedio" << endl;
    cout << "------------------------------------------" << endl;
    for (int i = 0; i < 5; i++) {
        cout << nombres[i] << "\t";
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << prom[i] << endl;
    }
    cout << "------------------------------------------" << endl;
}