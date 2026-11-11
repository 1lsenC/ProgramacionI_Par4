// Materia: Programación I, Paralelo 4
// Autor: Ilsen Arlett Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:10/11/2026
// Numero de ejercicio: 5

#include <iostream>
#include <vector>
using namespace std;

struct Cancion {
    char titulo[100];
    char artista[100];
    int duracionSegundos;
};

void RegistrarCanciones(vector<Cancion> &lista, int n);
void CalcularDuracionTotal(vector<Cancion> &lista);

int main() {
    system("cls");
    vector<Cancion> playlist;
    int n;
    cout << "\tREGISTRO DE PLAYLIST" << endl;
    cout << "Ingrese la cantidad de canciones: ";
    cin >> n;
    cin.ignore();

    RegistrarCanciones(playlist, n);
    CalcularDuracionTotal(playlist);

    return 0;
}

void RegistrarCanciones(vector<Cancion> &lista, int n) {
    for (int i = 0; i < n; i++) {
        Cancion c;
        cout << "\n--- Cancion " << i + 1 << " ---" << endl;
        cout << "Titulo: ";
        cin.getline(c.titulo, 101);
        cout << "Artista: ";
        cin.getline(c.artista, 101);
        cout << "Duracion (en segundos): ";
        cin >> c.duracionSegundos;
        cin.ignore();
        lista.push_back(c);
    }
}

void CalcularDuracionTotal(vector<Cancion> &lista) {
    int totalSegundos = 0;
    for (int i = 0; i < lista.size(); i++) {
        totalSegundos += lista[i].duracionSegundos;
    }
    int minutos = totalSegundos / 60;
    int segundos = totalSegundos % 60;

    cout << "\nDuracion total de la Playlist: " << totalSegundos << " segundos" << endl;
    cout << "Equivalente a: " << minutos << " minutos y " << segundos << " segundos" << endl;
}