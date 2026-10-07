// Materia: Programación I, Paralelo 4
// Autor: Ilsen Arlett Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación: 06/10/2026
// Numero de ejercicio: 8

#include <iostream>
#include <string.h>
using namespace std;

string ConvertiraMinusculas (string texto);
void BuscarCoincidencias (string textobase, string comparar);

int main() {
    system("cls");
    string texto1;
    string texto2;

    cout << "\nDETECTOR DE PLAGIO" << endl;
    cout << "Ingrese el primer texto: ";
    getline(cin, texto1);

    cout << "Ingrese el segundo texto: ";
    getline(cin, texto2);

    cout << "\nCOINCIDENCIAS ENCONTRADAS:" << endl;
    BuscarCoincidencias(texto1, texto2);

    return 0;
}

void BuscarCoincidencias(string textoBase, string textoBuscar) {
    string base = ConvertiraMinusculas(textoBase);
    string buscar = ConvertiraMinusculas(textoBuscar) + " ";
    int coincidencias = 0;
    size_t posEspacio = buscar.find(' ');

    while (posEspacio != string::npos) {
        string palabra = buscar.substr(0, posEspacio);

        if (base.find(palabra) != string::npos) {
            cout << "- Coincidencia " << coincidencias + 1<< ": " << palabra << endl;
            coincidencias++;
        }
        buscar.erase(0, posEspacio + 1);
        posEspacio = buscar.find(' ');
    }

    if (coincidencias == 0) {
        cout << "No se encontraron coincidencias" << endl;
    } 
    else {
        cout << "\nTotal de palabras/partes iguales encontradas: " << coincidencias << endl;
    }
}

string ConvertiraMinusculas (string texto) {
    for (int i = 0; i < texto.length(); i++) {
        if (texto[i] >= 'A' && texto[i] <= 'Z') {
            texto[i] = texto[i] + ('a' - 'A');
        }
    }
    return texto;
}
