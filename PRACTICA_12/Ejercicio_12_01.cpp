// Materia: Programación I, Paralelo 4
// Autor: Ilsen Arlett Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:22/11/2026
// Numero de ejercicio: 1

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void GuardarNombres(string nombreArchivo, int cantidad);
void MostrarNombres(string nombreArchivo);

int main() {
    string archivo = "Nombres.txt";
    int n;
    cout << "Cuantos nombres desea ingresar?: ";
    cin >> n;
    cin.ignore();

    GuardarNombres(archivo, n);
    MostrarNombres(archivo);
    return 0;
}

void GuardarNombres(string nombreArchivo, int cantidad) {
    ofstream Guardar(nombreArchivo);
    if (Guardar.fail()) {
        cout << "No se pudo abrir el archivo" << endl;
    }
    else {
        for (int i = 0; i < cantidad; i++) {
            string nombre;
            cout << "Ingrese el nombre " << (i + 1) << ": ";
            getline(cin, nombre);
            Guardar << nombre << endl;
        }
    }
    Guardar.close();
}

void MostrarNombres(string nombreArchivo) {
    ifstream LeerNombres(nombreArchivo);
    string linea;

    if (LeerNombres.fail()) {
        cout << "No se pudo abrir el archivo" << endl;
    }
    else {
        cout << "\n \tNombres guardados" << endl;
        while (getline(LeerNombres, linea)) {
            cout << linea << endl;
        }
    }
    LeerNombres.close();
}