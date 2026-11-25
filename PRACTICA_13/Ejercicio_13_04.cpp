// Materia: Programación I, Paralelo 4
// Autor: Ilsen Arlett Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:25/11/2026
// Numero de ejercicio: 4

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
using namespace std;

struct EstudianteHab {
    char ci[15];
    char nombres[30];
    char apellidos[30];
    char materia[30];
    int paralelo;
    double notaHabilitacion;
    bool tieneMenor60;
    bool tieneNotas;
};

void AdicionarEstudiante();
void ListadoHabilitados();
void EliminarEstudiante();
void AdicionarNotasHabilitacion();

int main() {
    int opcion;
    do {
        cout << "\n\tMENU NOTAS UCB" << endl;
        cout << "1. Adicionar Estudiante" << endl;
        cout << "2. Listado de Estudiantes Habilitados" << endl;
        cout << "3. Eliminar una Estudiante" << endl;
        cout << "4. Adicionar notas habilitacion" << endl;
        cout << "5. Salir" << endl;
        cout << "Elija una opcion: ";
        cin >> opcion;
        cin.ignore();
        switch (opcion) {
            case 1:
                AdicionarEstudiante();
                break;
            case 2:
                ListadoHabilitados();
                break;
            case 3:
                EliminarEstudiante();
                break;
            case 4:
                AdicionarNotasHabilitacion();
                break;
            case 5:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion no valida." << endl;
                break;
        }
    } while (opcion != 5);
    return 0;
}

void AdicionarEstudiante() {
    EstudianteHab est;
    cout << "Carnet Identidad: ";
    cin.getline(est.ci, 15);
    cout << "Nombres: ";
    cin.getline(est.nombres, 30);
    cout << "Apellidos: ";
    cin.getline(est.apellidos, 30);
    cout << "Materia: ";
    cin.getline(est.materia, 30);
    cout << "Paralelo: ";
    cin >> est.paralelo;
    cin.ignore();

    est.notaHabilitacion = 0.0;
    est.tieneMenor60 = false;
    est.tieneNotas = false;

    ofstream archivo;
    archivo.open("ESTUDIANTES.BIN", ios::app | ios::binary);
    if (archivo.is_open()) {
        archivo.write((char*) &est, sizeof(EstudianteHab));
        archivo.close();
        cout << "Estudiante registrado" << endl;
    } 
    else {
        cout << "No se pudo abrir el archivo" << endl;
    }
}

void AdicionarNotasHabilitacion() {
    char ciBuscado[15];
    char matBuscada[30];
    int parBuscado;

    cout << "Carnet Identidad: ";
    cin.getline(ciBuscado, 15);
    cout << "Materia: ";
    cin.getline(matBuscada, 30);
    cout << "Paralelo: ";
    cin >> parBuscado;
    cin.ignore();

    ifstream revision;
    revision.open("ESTUDIANTES.BIN", ios::in | ios::binary);
    EstudianteHab aux;
    bool existeEstudiante = false;

    if (revision.is_open()) {
        while (revision.read((char*) &aux, sizeof(EstudianteHab))) {
            if (strcmp(aux.ci, ciBuscado) == 0) {
                if (strcmp(aux.materia, matBuscada) == 0) {
                    if (aux.paralelo == parBuscado) {
                        existeEstudiante = true;
                    }
                }
            }
        }
        revision.close();
    }

    if (existeEstudiante) {
        int cantNotas;
        cout << "Cuantas notas desea ingresar?: ";
        cin >> cantNotas;

        double sumaPond = 0.0;
        bool hayMenor60 = false;
        for (int i = 0; i < cantNotas; i++) {
            double nota;
            double pond;
            cout << "Nota " << i + 1 << ": ";
            cin >> nota;
            cout << "Ponderacion: ";
            cin >> pond;
            if (nota < 60.0) {
                hayMenor60 = true;
            }
            if (pond > 1.0) {
                sumaPond += nota * (pond / 100.0);
            } 
            else {
                sumaPond += nota * pond;
            }
        }
        cin.ignore();

        fstream archivo;
        archivo.open("ESTUDIANTES.BIN", ios::in | ios::out | ios::binary);
        EstudianteHab est;
        bool actualizado = false;

        if (archivo.is_open()) {
            while (archivo.read((char*) &est, sizeof(EstudianteHab))) {
                if (!actualizado &&
                    strcmp(est.ci, ciBuscado) == 0 &&
                    strcmp(est.materia, matBuscada) == 0 &&
                    est.paralelo == parBuscado) {
                    est.notaHabilitacion = sumaPond;
                    est.tieneMenor60 = hayMenor60;
                    est.tieneNotas = true;

                    archivo.seekp(-(int)sizeof(EstudianteHab), ios::cur);
                    archivo.write((char*) &est, sizeof(EstudianteHab));
                    actualizado = true;
                }
            }
            archivo.close();
        }

        if (actualizado) {
            cout << "Notas de habilitacion guardadas" << endl;
        } 
        else {
            cout << "No se pudo actualizar el registro" << endl;
        }
    } 
    else {
        cout << "No se encontro un estudiante" << endl;
    }
}

void ListadoHabilitados() {
    ifstream archivo;
    archivo.open("ESTUDIANTES.BIN", ios::in | ios::binary);
    EstudianteHab est;
    double sumaTotal = 0.0;
    int totalEst = 0;

    cout << "\nCARNET | NOMBRES | APELLIDOS | MATERIA | PARALELO | NOTA HABILITACION | ESTADO" << endl;
    if (archivo.is_open()) {
        while (archivo.read((char*) &est, sizeof(EstudianteHab))) {
            cout << est.ci << " | " << est.nombres << " | " << est.apellidos << " | " << est.materia << " | " << est.paralelo << " | " << est.notaHabilitacion << " | ";

            if (!est.tieneNotas) {
                cout << "SIN NOTAS" << endl;
            } 
            else if (est.tieneMenor60) {
                cout << "NO HABILITADO" << endl;
            } 
            else {
                cout << "HABILITADO" << endl;
            }
            sumaTotal += est.notaHabilitacion;
            totalEst++;
        }
        archivo.close();
    } 
    else {
        cout << "No se pudo abrir el documento" << endl;
    }

    if (totalEst > 0) {
        double promedio;
        promedio = sumaTotal / totalEst;
        cout << "\nPromedio de notas de habilitacion: " << promedio << endl;
    } 
    else {
        cout << "\nNo hay estudiantes registrados para calcular el promedio" << endl;
    }
}

void EliminarEstudiante() {
    char ciBuscado[15];
    cout << "Ingrese CI del estudiante a eliminar: ";
    cin.getline(ciBuscado, 15);

    ifstream original;
    original.open("ESTUDIANTES.BIN", ios::in | ios::binary);
    ofstream temporal;
    temporal.open("temp.bin", ios::out | ios::binary);
    EstudianteHab est;
    bool eliminado = false;

    if (original.is_open() && temporal.is_open()) {
        while (original.read((char*) &est, sizeof(EstudianteHab))) {
            if (strcmp(est.ci, ciBuscado) == 0) {
                eliminado = true;
            } 
            else {
                temporal.write((char*) &est, sizeof(EstudianteHab));
            }
        }
    }

    if (original.is_open()) {
        original.close();
    }
    if (temporal.is_open()) {
        temporal.close();
    }
    remove("ESTUDIANTES.BIN");
    rename("temp.bin", "ESTUDIANTES.BIN");
    if (eliminado) {
        cout << "Estudiante eliminado de ESTUDIANTES.BIN." << endl;
    } 
    else {
        cout << "No se encontro ningun estudiante con ese CI." << endl;
    }
}