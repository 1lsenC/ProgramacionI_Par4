// Materia: Programación I, Paralelo 4
// Autor: Ilsen Arlett Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:22/11/2026
// Numero de ejercicio: 3

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Estudiante {
    string nombre;
    int edad;
    double promedio;
};

void RegistrarEstudiantes(string nombreArchivo, int cantidad);
void LeerEstudiantes(string nombreArchivo);

int main() {
    string archivo = "estudiantes.txt";
    int n;
    cout << "Cuantos estudiantes desea registrar?: ";
    cin >> n;
    cin.ignore();

    RegistrarEstudiantes(archivo, n);
    LeerEstudiantes(archivo);
    return 0;
}

void RegistrarEstudiantes(string nombreArchivo, int cantidad) {
    ofstream salida(nombreArchivo);
    if (salida.fail()) {
        cout << "No se pudo abrir el archivo" << endl;
    }
    else {
        for (int i = 0; i < cantidad; i++) {
            Estudiante est;
            cout << "\n-Estudiante " << (i + 1) << endl;
            cout << "Nombre: ";
            getline(cin, est.nombre);
            cout << "Edad: ";
            cin >> est.edad;
            cout << "Promedio: ";
            cin >> est.promedio;
            cin.ignore();

            salida << "Nombre: " << est.nombre << endl;
            salida << "Edad: " << est.edad << endl;
            salida << "Promedio: " << est.promedio << endl;
        }
    }
    salida.close();
}

void LeerEstudiantes(string nombreArchivo) {
    ifstream entrada(nombreArchivo);
    string linea;

    if (entrada.fail()) {
        cout << "No se pudo abrir el archivo" << endl;
    }
    else {
        cout << "\n \tREGISTRO DE ESTUDIANTES" << endl;
        int contador = 0;

        while (getline(entrada, linea)) {
            cout << linea << endl;
            contador++;
            if (contador % 3 == 0) {
                cout << "---------------------------------------------" << endl;
            }
        }
    }
    entrada.close();
}