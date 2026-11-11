// Materia: Programación I, Paralelo 4
// Autor: Ilsen Arlett Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:10/11/2026
// Numero de ejercicio: 9

#include <iostream>
#include <vector>
using namespace std;

struct Tarea {
    char descripcion[60];
    bool completada;
};

void IngresarTareas(vector<Tarea> &lista, int n);
void MostrarPendientes(vector<Tarea> &lista);
void MarcarCompletada(vector<Tarea> &lista);

int main() {
    system("cls");
    vector<Tarea> misTareas;
    int n;
    int opcion;
    cout << "\tTO-DO LIST" << endl;
    cout << "Cuantas tareas desea registrar: ";
    cin >> n;
    cin.ignore();
    IngresarTareas(misTareas, n);

    do {
        cout << "\n--- MENU DE TAREAS ---" << endl;
        cout << "1.Mostrar tareas pendientes" << endl;
        cout << "2.Marcar tarea como completada" << endl;
        cout << "3.Salir" << endl;
        cout << "Elija una opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                MostrarPendientes(misTareas);
                break;
            case 2:
                MarcarCompletada(misTareas);
                break;
            case 3:
                cout << "Saliendo del gestor de tareas" << endl;
                break;
            default:
                cout << "Opcion no valida." << endl;
        }
    } while (opcion != 3);
    return 0;
}

void IngresarTareas(vector<Tarea> &lista, int n) {
    for (int i = 0; i < n; i++) {
        Tarea t;
        cout << "\nDescripcion de la tarea " << i + 1 << ": ";
        cin.getline(t.descripcion, 60);
        t.completada = false;
        lista.push_back(t);
    }
}

void MostrarPendientes(vector<Tarea> &lista) {
    cout << "\nTAREAS PENDIENTES" << endl;
    bool hayPendientes = false;
    for (int i = 0; i < lista.size(); i++) {
        if (!lista[i].completada) {
            cout << i + 1<< ". " << lista[i].descripcion << endl;
            hayPendientes = true;
        }
    }
    if (!hayPendientes) {
        cout << "No tienes tareas pendientes." << endl;
    }
}

void MarcarCompletada(vector<Tarea> &lista) {
    int indice;
    MostrarPendientes(lista);
    cout << "\nIngrese el indice de la tarea que completo: ";
    cin >> indice;

    if (indice >= 0 && indice < lista.size()) {
        lista[indice-1].completada = true;
        cout << "Tarea marcada como completada" << endl;
    } else {
        cout << "Indice invalido." << endl;
    }
}