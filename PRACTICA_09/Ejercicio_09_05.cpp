// Materia: Programación I, Paralelo 4
// Autor: Ilsen Arlett Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación: 13/10/2026
// Numero de ejercicio: 5

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void Llenarmatriz(int matrix[5][5]);
void Mostrarmatriz(int matrix[5][5]);
void ComprarEntrada(int matrix[5][5]);
void MostrarEstadisticas(int matrix[5][5]);

int main () {
    system("cls");
    int matrix[5][5];
    int opcion;

    Llenarmatriz(matrix);

    do {
        cout << "\n" << "\tCINE VIP - GESTION DE ASIENTOS" << endl;
        cout << "1. Mostrar la sala" << endl;
        cout << "2. Comprar entrada" << endl;
        cout << "3. Estadisticas (Libres y Ocupados)" << endl;
        cout << "4. Salir" << endl;
        cout << "\tElija una opcion: ";
        cin >> opcion;
        cout << "\n";

        switch (opcion) {
            case 1:
                Mostrarmatriz(matrix);
                break;
            case 2:
                ComprarEntrada(matrix);
                break;
            case 3:
                MostrarEstadisticas(matrix);
                break;
            case 4:
                cout << "\nSaliendo del sistema" << endl;
                break;
            default:
                cout << "\nOpcion invalida" << endl;
        }

    } while (opcion != 4);

    return 0;
}

void Llenarmatriz(int matrix[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = 0;
        }
    }
}

void Mostrarmatriz(int matrix[5][5]) {
    for (int j = 0; j < 5; j++) {
        cout << "\tCol " << j + 1 << " ";
    }
    cout << "\n";
    for (int i = 0; i < 5; i++) {
        cout << "Fil " << i + 1 << " ";
        for (int j = 0; j < 5; j++) {
            if (matrix[i][j] == 0) {
                cout << "  [L]   ";
            } 
            else {
                cout << "  [O]   ";
            }
        }
        cout << endl;
    }
    cout << "\t" << "\t---PANTALLA---" << endl;
}

void ComprarEntrada(int matrix[5][5]) {
    int fila, asiento;
    cout << "\nIngrese la fila (1 al 5): ";
    cin >> fila;
    cout << "Ingrese el asiento (1 al 5): ";
    cin >> asiento;

    fila--;
    asiento--;

    if (fila >= 0 && fila < 5 && asiento >= 0 && asiento < 5) {

        if (matrix[fila][asiento] == 0) {
            matrix[fila][asiento] = 1;
            cout << "Reserva exitosa" << endl;
        } 
        else {
            cout << "Asiento no disponible" << endl;
        }
    } 
    else {
        cout << "Fila o asiento fuera de rango" << endl;
    }
}

void MostrarEstadisticas(int matrix[5][5]) {
    int totalAsientos = 5 * 5;
    double ocupados = 0;
    double libres = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrix[i][j] == 1) {
                ocupados++;
            } else {
                libres++;
            }
        }
    }

    double porcentajeLibres = (libres / totalAsientos) * 100.0;
    double porcentajeOcupados = (ocupados / totalAsientos) * 100.0;

    cout << "\tESTADISTICAS" << endl;
    cout << "Total de asientos: " << totalAsientos << endl;
    cout << "Asientos libres: " << libres << " (" << porcentajeLibres << "%)" << endl;
    cout << "Asientos ocupados: " << ocupados << " (" << porcentajeOcupados << "%)" << endl;
}