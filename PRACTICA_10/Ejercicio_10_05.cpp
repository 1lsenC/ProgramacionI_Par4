// Materia: Programación I, Paralelo 4
// Autor: Ilsen Arlett Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:21/10/2026
// Numero de ejercicio: 5

#include <iostream>
#include <string>
using namespace std;
void OrdenarPalabra(string &palabra);

int main () {
    system ("cls");
    string palabra;

    cout << "Ingrese una palabra: ";
    cin >> palabra;
    OrdenarPalabra(palabra);
    cout << "\nPalabra ordenada alfabeticamente: " << palabra << endl;

    return 0;
}

void OrdenarPalabra(string &palabra) {
    char aux;
    for (int i = 0; i < palabra.length(); i++) {
        if (palabra[i] >= 'A' && palabra[i] <= 'Z') {
            palabra[i] = palabra[i] + 32;
        }
    }

    for (int i = 0; i < palabra.length() - 1; i++) {
        for (int j = 0; j < palabra.length() - 1; j++) {
            if (palabra[j] > palabra[j + 1]) {
                aux = palabra[j];
                palabra[j] = palabra[j + 1];
                palabra[j + 1] = aux;
            }
        }
    }
}
