// Materia: Programación I, Paralelo 4
// Autor: Ilsen Arlett Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:20/10/2026
// Numero de ejercicio: 3

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

float aleatorios (int min, int max);
void LlenarTiempos (vector<float> &tiem, int n);
void MostrarTiempos (vector<float> tiem, int n);
void Ordenamiento (vector<float> &tiem, int n);

int main () {
    system ("cls");
    srand(time(NULL));
    vector <float> Tiempos;
    int corredores;

    cout << "Cantidad de corredores: ";
    cin >> corredores;
    LlenarTiempos (Tiempos,corredores);

    cout << "\nTiempos que tuvieron los corredores:" << endl;
    MostrarTiempos (Tiempos,corredores);
    cout << endl;
    cout << "\nTiempos ordenados del menor al mayor:" << endl;
    Ordenamiento (Tiempos,corredores);

    return 0;
}

void LlenarTiempos (vector<float> &tiem, int n) {
    float valores = 0;
    for (int i = 0; i < n; i++) {
        valores = aleatorios(10.00,20.00);
        tiem.push_back(valores);
    }
}

void MostrarTiempos (vector<float> tiem, int n) {
    for (int i = 0; i < n; i++) {
        cout << tiem[i] << "seg  ";
    }
}

void Ordenamiento (vector<float> &tiem, int n) {
    float aux;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1; j++) {
            if (tiem[j] > tiem[j+1]) {
                aux = tiem[j];
                tiem[j] = tiem[j+1];
                tiem [j+1] = aux;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << tiem[i] << "seg  ";
    }
}

float aleatorios (int min, int max){
    return (rand() % (max * 100 - min * 100 + 1) + min * 100) / 100.00;
}