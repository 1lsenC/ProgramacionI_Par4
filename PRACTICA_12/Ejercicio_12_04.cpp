// Materia: Programación I, Paralelo 4
// Autor: Ilsen Arlett Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:22/11/2026
// Numero de ejercicio: 4

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int ContarPalabras(string &linea, string &busqueda);
void BuscarEnArchivo(string nombreArchivo, string &busqueda);

int main() {
    string archivo = "Datos.txt";
    string textoBuscado;

    cout << "Ingrese la palabra o frase a buscar: ";
    getline(cin, textoBuscado);
    BuscarEnArchivo(archivo, textoBuscado);
    return 0;
}

void BuscarEnArchivo(string nombreArchivo, string &busqueda) {
    ifstream entrada(nombreArchivo);
    string linea;
    int totalVeces = 0;

    if (entrada.fail()) {
        cout << "Error: no se pudo abrir el archivo" << endl;
    }
    else {
        while (getline(entrada, linea)) {
            totalVeces += ContarPalabras(linea, busqueda);
        }
        entrada.close();
        cout << "La palabra/frase '" << busqueda << "' aparece " << totalVeces << " veces." << endl;
    }
}

int ContarPalabras(string &linea, string &busqueda) {
    int veces = 0;
    if (busqueda.length() == 0) {
        return 0;
    }

    int pos = linea.find(busqueda, 0);
    while (pos != string::npos) {
        veces++;
        pos = linea.find(busqueda, pos + busqueda.length());
    }
    return veces;
}