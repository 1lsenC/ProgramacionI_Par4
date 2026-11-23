// Materia: Programación I, Paralelo 4
// Autor: Ilsen Arlett Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:23/11/2026
// Numero de ejercicio: 8

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void ContarLineasYPalabras(string nombreArchivo, int &lineas, int &palabras);
int ContarCaracteres(string nombreArchivo);

int main() {
    string archivo = "documento.txt";
    int totalLineas = 0;
    int totalPalabras = 0;
    int totalCaracteres = 0;

    ContarLineasYPalabras(archivo, totalLineas, totalPalabras);
    totalCaracteres = ContarCaracteres(archivo);

    cout << "Lineas: " << totalLineas << endl;
    cout << "Palabras: " << totalPalabras << endl;
    cout << "Caracteres: " << totalCaracteres << endl;
    return 0;
}

void ContarLineasYPalabras(string nombreArchivo, int &lineas, int &palabras) {
    ifstream entrada(nombreArchivo);
    string linea;
    lineas = 0;
    palabras = 0;

    if (entrada.fail()) {
        cout << "No se pudo abrir el archivo" << endl;
    }

    while (getline(entrada, linea)) {
        lineas++;
        bool enPalabra = false;
        for (int i = 0; i < (int)linea.length(); i++) {
            char c = linea[i];
            if (c != ' ' && c != '\t' && c != '\r') {
                if (!enPalabra) {
                    palabras++;
                    enPalabra = true;
                }
            } 
            else {
                enPalabra = false;
            }
        }
    }
    entrada.close();
}

int ContarCaracteres(string nombreArchivo, int &lineas, int &palabras) {
    ifstream entrada(nombreArchivo);
    int caracteres = 0;
    string linea;
    lineas = 0;
    palabras = 0;

    if (entrada.fail()) {
        cout << "No se pudo abrir el archivo." << endl;
    }

    while (getline(entrada, linea)) {
        lineas++;
        caracteres += linea.length();
        bool enPalabra = false;
        for (int i = 0; i < linea.length(); i++) {
            if (linea[i] != ' ' && linea[i] != '\t' && linea[i] != '\r') {
                if (!enPalabra) {
                    palabras++;
                    enPalabra = true;
                }
            } else {
                enPalabra = false;
            }
        }
    }
    entrada.close();
    return caracteres;
}