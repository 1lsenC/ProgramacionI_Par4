// Materia: Programación I, Paralelo 4
// Autor: Ilsen Arlett Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:10/11/2026
// Numero de ejercicio: 1

#include <iostream>
using namespace std;

struct Jugador {
    char nickname[30];
    int nivel;
    int experiencia;
};

void LlenarDatos (Jugador &Datos);
void IngresarPuntos(Jugador &Datos);
void MostrarDatos (Jugador Datos);

int main () {
    system("cls");
    Jugador DatosJugador;
    LlenarDatos(DatosJugador);
    return 0;
}

void LlenarDatos (Jugador &Datos) {
    int respuesta;
    cout << "\tDATOS DEL JUGADOR" << endl;
    cout << "Nickname: ";
    cin.getline(Datos.nickname,31);
    cout << "Nivel: ";
    cin >> Datos.nivel;
    cout << "Experiencia: ";
    cin >> Datos.experiencia;
    cin.ignore();

    do
    {
        cout << "\nQuiere ingresar mas puntos?" << endl;
        cout << "1. Si" << endl;
        cout << "2. No" << endl;
        cin >> respuesta;
        MostrarDatos (Datos);
        IngresarPuntos(Datos);
        MostrarDatos (Datos);
    } while (respuesta==1);
}

void MostrarDatos (Jugador Datos) {
    cout << "\nDatos de " << Datos.nickname << endl;
    cout << "-Nivel: " << Datos.nivel << endl;
    cout << "-Experiencia: " << Datos.experiencia << endl;
}

void IngresarPuntos(Jugador &Datos) {
    int SumaPuntos = 0;
    cout << "\nCuantos puntos de experiencia aumento: ";
    cin >> SumaPuntos;
    Datos.experiencia += SumaPuntos;
    if (Datos.experiencia >= 100) {
        Datos.nivel += 1;
        Datos.experiencia -=100;
    }
}