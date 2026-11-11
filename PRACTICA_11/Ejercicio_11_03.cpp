// Materia: Programación I, Paralelo 4
// Autor: Ilsen Arlett Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:10/11/2026
// Numero de ejercicio: 3

#include <iostream>
using namespace std;

struct Tiempo {
    int horas;
    int minutos;
    int segundos;
};

void SumarTiempos(Tiempo &t1, Tiempo &t2);
void MostrarTiempo(Tiempo &t);

int main() {
    system("cls");    
    Tiempo t1, t2, t;

    cout << "CALCULADORA DE TIEMPO" << endl;
    cout << "\nIngrese Tiempo 1:" << endl;
    cout << "Horas: "; 
    cin >> t1.horas;
    cout << "Minutos: "; 
    cin >> t1.minutos;
    cout << "Segundos: "; 
    cin >> t1.segundos;

    cout << "\nIngrese Tiempo 2:" << endl;
    cout << "Horas: "; 
    cin >> t2.horas;
    cout << "Minutos: "; 
    cin >> t2.minutos;
    cout << "Segundos: "; 
    cin >> t2.segundos;
    cout << "\tRESULTADO DE LA SUMA" << endl;
    SumarTiempos(t1, t2);
    return 0;
}

void SumarTiempos(Tiempo &t1, Tiempo &t2) {
    Tiempo resultado;
    resultado.segundos = t1.segundos + t2.segundos;
    resultado.minutos = t1.minutos + t2.minutos;
    resultado.horas = t1.horas + t2.horas;

    if (resultado.segundos >= 60) {
        resultado.minutos += (resultado.segundos / 60);
        resultado.segundos = resultado.segundos % 60;
    }

    if (resultado.minutos >= 60) {
        resultado.horas += (resultado.minutos / 60);
        resultado.minutos = resultado.minutos % 60;
    }
    MostrarTiempo(resultado);
}

void MostrarTiempo(Tiempo &t) {
    cout << "Tiempo Total: " << t.horas << "h " << t.minutos << "m " << t.segundos << "s" << endl;
}