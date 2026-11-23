// Materia: Programación I, Paralelo 4
// Autor: Ilsen Arlett Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:23/11/2026
// Numero de ejercicio: 6

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void FiltrarAltasTemperaturas(string archivoEntrada, string archivoSalida, double limite);

int main() {
    double limiteTemp;
    cout << "Ingrese la temperatura limite (N): ";
    cin >> limiteTemp;

    FiltrarAltasTemperaturas("Temperaturas.txt", "Altas_temperaturas.txt", limiteTemp);
    cout << "Se guardaron las temperaturas mas altas en un nuevo archivo" << endl;
    return 0;
}

void FiltrarAltasTemperaturas(string archivoEntrada, string archivoSalida, double limite) {
    ifstream entrada(archivoEntrada);
    string linea;
    int filtradas = 0;

    if (entrada.fail()) {
        cout << "No se pudo abrir el archivo" << endl;
    }

    ofstream salida(archivoSalida);
    if (salida.fail()) {
        cout << "No se pudo crear un nuevo archivo" << endl;
        entrada.close();
    }

    while (getline(entrada, linea)) {
        if (linea.length() > 0) {
            size_t espacio = linea.find(' ');
            if (espacio != string::npos) {
                string ciudad = linea.substr(0, espacio);
                string tempTexto = linea.substr(espacio + 1);
                double temp = stod(tempTexto);
                if (temp > limite) {
                    salida << ciudad << " " << temp << endl;
                    filtradas++;
                }
            }
        }
    }
    entrada.close();
    salida.close();
}