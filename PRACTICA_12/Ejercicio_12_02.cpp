// Materia: Programación I, Paralelo 4
// Autor: Ilsen Arlett Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:22/11/2026
// Numero de ejercicio: 2

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void ContarPalabras(string &nombreArchivo);

int main() {
    string archivo = "ContarTexto.txt";

    ContarPalabras(archivo);
    return 0;
}

void ContarPalabras(string &nombreArchivo) {
    ifstream EntradaC(nombreArchivo);
    string palabra;

    if (EntradaC.fail()) {
        cout << "No se pudo abrir el archivo" << endl;
    }
    else {
        int contador = 0;
        while (EntradaC >> palabra) {
            contador++;
        }
        EntradaC.close();
        cout << "Total de palabras en " << nombreArchivo << ": " << contador << endl;
    }
}