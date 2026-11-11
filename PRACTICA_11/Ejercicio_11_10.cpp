// Materia: Programación I, Paralelo 4
// Autor: Ilsen Arlett Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:10/11/2026
// Numero de ejercicio: 10

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Equipo {
    char nombre[30];
    int partidosJugados;
    int victorias;
    int puntosTotales;
};

void RegistrarEquipos(vector<Equipo> &torneo, int n);
void SimularPartido(vector<Equipo> &torneo);
void OrdenarClasificacion(vector<Equipo> &torneo);
void MostrarTabla(vector<Equipo> &torneo);
int aleatorios (int min, int max);

int main() {
    system("cls");
    srand(time(NULL));
    vector<Equipo> torneo;
    int n, opcion;
    cout << "\tCAMPEONATO DE E-SPORTS" << endl;
    cout << "Ingrese la cantidad de equipos participantes: ";
    cin >> n;
    cin.ignore();
    RegistrarEquipos(torneo, n);

    do {
        cout << "\nMENU" << endl;
        cout << "1.Partido" << endl;
        cout << "2.Ver tabla de posiciones" << endl;
        cout << "3.Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                SimularPartido(torneo);
                break;
            case 2:
                OrdenarClasificacion(torneo);
                MostrarTabla(torneo);
                break;
            case 3:
                cout << "Saliendo del sistema del torneo" << endl;
                break;
            default:
                cout << "Opcion no valida." << endl;
        }
    } while (opcion != 3);
    return 0;
}

void RegistrarEquipos(vector<Equipo> &torneo, int n) {
    for (int i = 0; i < n; i++) {
        Equipo eq;
        cout << "\nNombre del equipo " << i + 1 << ": ";
        cin.getline(eq.nombre, 30);
        eq.partidosJugados = 0;
        eq.victorias = 0;
        eq.puntosTotales = 0;
        torneo.push_back(eq);
    }
}

void SimularPartido(vector<Equipo> &torneo) {
    int ganador;
    int perdedor;
    if (torneo.size() < 2) {
        cout << "Se necesitan al menos 2 equipos para un partido." << endl;
        return;
    }
    int eq1 = aleatorios(0, torneo.size()-1);
    int eq2;
    do {
        eq2 = aleatorios(0, torneo.size()-1);
    } while (eq1 == eq2);

    int goles1 = aleatorios(1, 3);
    int goles2 = aleatorios(1, 3);
    while (goles1 == goles2) {
        goles2 = aleatorios(1, 3);
    }

    if (goles1 > goles2) {
        ganador = eq1;
        perdedor = eq2;
    } else {
        ganador = eq2;
        perdedor = eq1;
    }

    torneo[ganador].partidosJugados++;
    torneo[ganador].victorias++;
    torneo[ganador].puntosTotales += 3;
    torneo[perdedor].partidosJugados++;

    cout << "\nFIN DEL PARTIDO" << endl;
    cout << torneo[ganador].nombre << " le gano a " << torneo[perdedor].nombre << endl;
}

void OrdenarClasificacion(vector<Equipo> &torneo) {
    int total = torneo.size();
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - 1 - i; j++) {
            if (torneo[j].puntosTotales < torneo[j + 1].puntosTotales) {
                Equipo aux = torneo[j];
                torneo[j] = torneo[j + 1];
                torneo[j + 1] = aux;
            }
        }
    }
}

void MostrarTabla(vector<Equipo> &torneo) {
    cout << "\tTABLA DE POSICIONES" << endl;
    cout << "Posicion | Equipo         | Jugados | Victorias | Puntos" << endl;
    cout << "--------------------------------------------------------" << endl;
    for (int i = 0; i < torneo.size(); i++) {
        cout << "    " << i + 1 << "    | " << torneo[i].nombre << "\t| " << torneo[i].partidosJugados << "    |     " << torneo[i].victorias << "     |   " << torneo[i].puntosTotales << endl;
    }
}

int aleatorios (int min, int max) {
    return ((rand() % (max-min+1))+min);
}