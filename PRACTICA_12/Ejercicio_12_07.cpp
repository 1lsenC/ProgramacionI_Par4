// Materia: Programación I, Paralelo 4
// Autor: Ilsen Arlett Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:23/11/2026
// Numero de ejercicio: 7

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void ProcesarPromedios(string archivoEntrada, string archivoSalida);

int main() {
    ProcesarPromedios("calificaciones.txt", "promedios.txt");
    return 0;
}

void ProcesarPromedios(string archivoEntrada, string archivoSalida) {
    ifstream entrada(archivoEntrada);
    ofstream salida(archivoSalida);
    string linea;

    if (entrada.fail()) {
        cout << "No se pudo abrir el archivo" << endl;
    }
    if (salida.fail()) {
        cout << "No se pudo crear un archivo nuevo" << endl;
        entrada.close();
    }

    while (getline(entrada, linea)) {
        int primerEspacio = linea.find(' ');
        if (primerEspacio != string::npos) {
            string nombre = linea.substr(0, primerEspacio);
            double suma = 0.0;
            int cantidadNotas = 0;

            int posActual = primerEspacio + 1;
            while (posActual < linea.length()) {
                while (posActual < linea.length() && linea[posActual] == ' ') {
                    posActual++;
                }

                if (posActual < linea.length()) {
                    int siguienteEspacio = linea.find(' ', posActual);
                    string Nota;
                    double parteEntera = 0.0;
                    double parteDecimal = 0.0;
                    double divisor = 1.0;
                    bool decimalEncontrado = false;

                    if (siguienteEspacio == string::npos) {
                        Nota = linea.substr(posActual);
                        posActual = linea.length();
                    } 
                    else {
                        Nota = linea.substr(posActual, siguienteEspacio - posActual);
                        posActual = siguienteEspacio + 1;
                    }

                    for (int i = 0; i < Nota.length(); i++) {
                        char c = Nota[i];
                        if (c >= '0' && c <= '9') {
                            if (!decimalEncontrado) {
                                parteEntera = parteEntera * 10.0 + (c - '0');
                            } 
                            else {
                                divisor = divisor * 10.0;
                                parteDecimal = parteDecimal + ((c - '0') / divisor);
                            }
                        } 
                        else if (c == '.') {
                            decimalEncontrado = true;
                        }
                    }

                    double valorNota = parteEntera + parteDecimal;
                    suma += valorNota;
                    cantidadNotas++;
                }
            }

            if (cantidadNotas > 0) {
                double promedio = suma / cantidadNotas;
                salida << nombre << " " << promedio << endl;
            }
        }
    }
    cout << "Promedios calculados y guardados en otro archivo" << endl;
    entrada.close();
    salida.close();
}