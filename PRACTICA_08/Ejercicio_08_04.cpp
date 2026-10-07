// Materia: Programación I, Paralelo 4
// Autor: Ilsen Arlett Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación: 06/10/2026
// Numero de ejercicio: 4

#include <iostream>
#include <string>
using namespace std;

void CensurarMensaje(string &mensaje, string prohibidas[]);

int main() {
    system("cls");
    string prohibidas[3] = {"manco", "tonto", "noob"};
    string mensaje;

    cout << "Ingrese el mensaje: ";
    getline(cin, mensaje);
    CensurarMensaje(mensaje, prohibidas);

    cout << "\nMensaje censurado: " << mensaje << endl;

    return 0;
}

void CensurarMensaje(string &mensaje, string prohibidas[]) {
    for (int i = 0; i < 3; i++) {
        string palabra = prohibidas[i];
        size_t longitud = palabra.length();
        string asteriscos = string(longitud, '*');
        size_t pos = mensaje.find(palabra);

        while (pos != string::npos) {
            mensaje.replace(pos, longitud, asteriscos);
            pos = mensaje.find(palabra);
        }
    }
}