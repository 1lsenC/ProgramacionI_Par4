// Materia: Programación I, Paralelo 4
// Autor: Ilsen Arlett Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:20/10/2026
// Numero de ejercicio: 6

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

void NombresyApellidos (string nom[], string ap[], int cant, vector<string> &listaNombres);
void MostrarLista(const vector<string> &listaNombres, int cant);
void OrdenarNombresAlfabetico(vector<string> &listaNombres, int cant);
int aleatorios (int min, int max);

int main () {
    srand(time(NULL));
    int cantidad=0;
    string nombres [10] = {"Mateo", "Maria", "Carlos", "Nicole", "Pedro", "Miguel", "Luciana", "Gabriela", "Diego", "Elena"};
    string apellidos [10] = {"Gonzalez", "Rodriguez", "Lopez", "Martinez", "Perez", "Cardenas", "Sanchez", "Alvarez", "Huarina", "Torres"};
    vector<string> estudiantes;

    cout << "Cantidad de nombres: ";
    cin >> cantidad;
    cout << "\tLista de nombres y apellidos:" << endl;
    NombresyApellidos (nombres, apellidos, cantidad, estudiantes);
    MostrarLista(estudiantes, cantidad);

    OrdenarNombresAlfabetico(estudiantes, cantidad);
    cout << "\n" << "\tLista ordenada alfabeticamente" << endl;
    MostrarLista(estudiantes, cantidad);

    return 0;
}

void NombresyApellidos (string nom[], string ap[], int cant, vector<string> &listaNombres) {
    for (int i = 0; i < cant; i++) {
        int NombreAl = aleatorios (0,9);
        int ApellidoAl = aleatorios (0,9);
        string nombreCompleto = nom[NombreAl] + " " + ap[ApellidoAl];
        listaNombres.push_back(nombreCompleto);
    }
}

void OrdenarNombresAlfabetico(vector<string> &listaNombres, int cant) {
    string aux;
    for (int i = 0; i < cant - 1; i++) {
        for (int j = 0; j < cant - 1; j++) {
            if (listaNombres[j] > listaNombres[j + 1]) {
                aux = listaNombres[j];
                listaNombres[j] = listaNombres[j + 1];
                listaNombres[j + 1] = aux;
            }
        }
    }
}

void MostrarLista(const vector<string> &listaNombres, int cant) {
    for (int i = 0; i < cant; i++) {
        cout << i + 1 << ". " << listaNombres[i] << endl;
    }
}

int aleatorios (int min, int max) {
    return ((rand() % (max-min+1))+min);
}