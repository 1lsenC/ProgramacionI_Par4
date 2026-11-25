// Materia: Programación I, Paralelo 4
// Autor: Ilsen Arlett Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:25/11/2026
// Numero de ejercicio: 1

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;

struct DatosdelEstudiante {
    char ci[10];
    char nombres[30];
    char apellidos[30];
};

struct IngresodeNotas {
    char ci[10];
    char materia[30];
    int nota;
};

void IngresarEstudiante();
void IngresarNota();
void Reporte();

int main() {
    int opcion;
    do {
        cout << "\n \tMENU" << endl;
        cout << "1. Ingreso de datos estudiantes" << endl;
        cout << "2. Ingreso de materias y notas" << endl;
        cout << "3. Reporte de estudiantes y notas ingresadas" << endl;
        cout << "4. Salir" << endl;
        cout << "Elija una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                IngresarEstudiante();
                break;
            case 2:
                IngresarNota();
                break;
            case 3:
                Reporte();
                break;
            case 4:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion no valida." << endl;
                break;
        }
    } while (opcion != 4);
    return 0;
}

void IngresarEstudiante() {
    DatosdelEstudiante nuevo;
    cout << "Ingrese CI: ";
    cin.getline(nuevo.ci, 10);
    ifstream lectura;
    lectura.open("Estudiantes.bin", ios::in | ios::binary);
    DatosdelEstudiante aux;
    bool repetido = false;

    if (lectura.is_open()) {
        while (lectura.read((char*) &aux, sizeof(DatosdelEstudiante))) {
            if (strcmp(aux.ci, nuevo.ci) == 0) {
                repetido = true;
            }
        }
        lectura.close();
    }

    if (repetido) {
        cout << "Ya existe un estudiante con ese CI." << endl;
    } else {
        cout << "Ingrese nombres: ";
        cin.getline(nuevo.nombres, 30);
        cout << "Ingrese apellidos: ";
        cin.getline(nuevo.apellidos, 30);

        ofstream escritura;
        escritura.open("Estudiantes.bin", ios::app | ios::binary);
        if (escritura.is_open()) {
            escritura.write((char*) &nuevo, sizeof(DatosdelEstudiante));
            escritura.close();
            cout << "Estudiante guardado" << endl;
        }
    }
}

void IngresarNota() {
    IngresodeNotas nueva;
    cout << "Ingrese CI del estudiante: ";
    cin.getline(nueva.ci, 10);

    ifstream lecEst;
    lecEst.open("Estudiantes.bin", ios::in | ios::binary);
    DatosdelEstudiante est;
    bool existeEst = false;

    if (lecEst.is_open()) {
        while (lecEst.read((char*) &est, sizeof(DatosdelEstudiante))) {
            if (strcmp(est.ci, nueva.ci) == 0) {
                existeEst = true;
            }
        }
        lecEst.close();
    }

    if (!existeEst) {
        cout << "El estudiante no existe." << endl;
        return;
    }

    cout << "Ingrese materia: ";
    cin.getline(nueva.materia, 30);

    ifstream lecNotas;
    lecNotas.open("Notas.bin", ios::in | ios::binary);
    IngresodeNotas auxNota;
    bool duplicada = false;

    if (lecNotas.is_open()) {
        while (lecNotas.read((char*) &auxNota, sizeof(IngresodeNotas))) {
            if (strcmp(auxNota.ci, nueva.ci) == 0 && strcmp(auxNota.materia, nueva.materia) == 0) {
                duplicada = true;
            }
        }
        lecNotas.close();
    }

    if (duplicada) {
        cout << "Ya existe una nota para esa materia en este estudiante." << endl;
    } 
    else {
        cout << "Ingrese nota: ";
        cin >> nueva.nota;
        cin.ignore();

        ofstream escNota;
        escNota.open("Notas.bin", ios::app | ios::binary);
        if (escNota.is_open()) {
            escNota.write((char*) &nueva, sizeof(IngresodeNotas));
            escNota.close();
            cout << "Nota guardada" << endl;
        }
    }
}

void Reporte() {
    vector<DatosdelEstudiante> estudiantes;
    vector<IngresodeNotas> notas;

    ifstream lecEst;
    lecEst.open("Estudiantes.bin", ios::in | ios::binary);
    DatosdelEstudiante est;
    if (lecEst.is_open()) {
        while (lecEst.read((char*) &est, sizeof(DatosdelEstudiante))) {
            estudiantes.push_back(est);
        }
        lecEst.close();
    }

    ifstream lecNotas;
    lecNotas.open("Notas.bin", ios::in | ios::binary);
    IngresodeNotas n;
    if (lecNotas.is_open()) {
        while (lecNotas.read((char*) &n, sizeof(IngresodeNotas))) {
            notas.push_back(n);
        }
        lecNotas.close();
    }

    cout << "\n \tREPORTE" << endl;
    for (int i = 0; i < (int)estudiantes.size(); i++) {
        cout << "\nCI: " << estudiantes[i].ci << " | Nombre: " << estudiantes[i].nombres << " " << estudiantes[i].apellidos << endl;
        bool tiene = false;
        for (int j = 0; j < (int)notas.size(); j++) {
            if (strcmp(notas[j].ci, estudiantes[i].ci) == 0) {
                cout << "  - " << notas[j].materia << ": " << notas[j].nota << endl;
                tiene = true;
            }
        }
        if (!tiene) {
            cout << "  (Sin notas)" << endl;
        }
    }
}