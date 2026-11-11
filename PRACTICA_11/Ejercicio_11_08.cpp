// Materia: Programación I, Paralelo 4
// Autor: Ilsen Arlett Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:10/11/2026
// Numero de ejercicio: 8

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Estudiante {
    char nombres[40];
    int notaFinal;
};

void LlenarEstudiantes(vector<Estudiante> &lista, int n);
void FiltrarEstudiantes(vector<Estudiante> &lista);
int aleatorios (int min, int max);

int main() {
    system("cls");
    srand(time(NULL));
    vector<Estudiante> aula;
    int n;
    cout << "\tCALIFICACIONES" << endl;
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> n;
    cin.ignore();
    LlenarEstudiantes(aula, n);
    FiltrarEstudiantes(aula);
    return 0;
}

void LlenarEstudiantes(vector<Estudiante> &lista, int n) {
    for (int i = 0; i < n; i++) {
        Estudiante e;
        cout << "\nEstudiante " << i + 1 << ":" << endl;
        cout << "Nombre completo: ";
        cin.getline(e.nombres, 41);
        e.notaFinal = aleatorios(0,100);
        cout << "Nota: " << e.notaFinal << endl;
        lista.push_back(e);
    }
}

void FiltrarEstudiantes(vector<Estudiante> &lista) {
    cout << "\n\tLista de Aprobados" << endl;
    bool hayAprobados = false;
    for (int i = 0; i < lista.size(); i++) {
        if (lista[i].notaFinal >= 60) {
            cout << "- " << lista[i].nombres << " | Nota: " << lista[i].notaFinal << endl;
            hayAprobados = true;
        }
    }
    if (!hayAprobados) {
        cout << "Ninguno." << endl;
    }
    cout << "\nLista de Reprobados" << endl;
    bool hayReprobados = false;
    for (int i = 0; i < lista.size(); i++) {
        if (lista[i].notaFinal < 60) {
            cout << "- " << lista[i].nombres << " | Nota: " << lista[i].notaFinal << endl;
            hayReprobados = true;
        }
    }
    if (!hayReprobados) {
        cout << "Ninguno." << endl;
    }
}

int aleatorios (int min, int max) {
    return ((rand() % (max-min+1))+min);
}