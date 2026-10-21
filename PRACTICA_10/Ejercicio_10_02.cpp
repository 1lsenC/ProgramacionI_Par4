// Materia: Programación I, Paralelo 4
// Autor: Ilsen Arlett Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:20/10/2026
// Numero de ejercicio: 2

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

void LlenarRanking (vector<int> &Num, int N);
void Ordenar (vector<int> &Num, int N);
void Podio (vector<int> Num);
int aleatorios (int min, int max);

int main () {
    system ("cls");
    srand(time(NULL));
    vector <int> Puntuaciones;
    int n;

    cout << "Cantidad de jugadores que estaran en el torneo: ";
    cin >> n;
    LlenarRanking (Puntuaciones,n);
    cout << "Las puntuaciones ordenadas de mayor a menor:" << endl;
    Ordenar (Puntuaciones,n);
    cout << "\n" <<"\tEl podio de los tres mejores puntajes:" << endl;
    Podio (Puntuaciones);

    return 0;
}

void LlenarRanking (vector<int> &Num, int N) {
    int valores = 0;
    for (int i = 0; i < N; i++) {
        valores = aleatorios(1,100);
        Num.push_back(valores);
    }
}

void Ordenar (vector<int> &Num, int N) {
    int aux;
    for (int i = 0; i < N-1; i++) {
        for (int j = 0; j < N-1; j++) {
            if (Num[j] < Num[j+1]) {
                aux = Num[j];
                Num[j] = Num[j+1];
                Num [j+1] = aux;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << Num[i] << " ";
    }
}

void Podio (vector<int> Num) {
    for (int i = 0; i < 3; i++) {
        cout << "- " << i+1 << " lugar: " << Num[i] << endl;
    }
}

int aleatorios (int min, int max) {
    return ((rand() % (max-min+1))+min);
}