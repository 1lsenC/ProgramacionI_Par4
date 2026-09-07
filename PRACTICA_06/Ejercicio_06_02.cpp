// Materia: Programación I, Paralelo 4
// Autor: Ilsen Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:07/09/2026

#include <iostream>
using namespace std;
void tiempo(int,int&,int&,int&);

int main () {
    int totalseg, horas, min, seg;

    cout<<"Digite el numero total de segundos: ";
    cin>>totalseg;

    tiempo(totalseg, horas, min, seg);

    cout<<"El tiempo equivalente a la cantidad de segundos digitados: "<<endl;
    cout<<"Horas: "<<horas<<endl;
    cout<<"Minutos: "<<min<<endl;
    cout<<"Segundos: "<<seg<<endl;

    return 0;
}

void tiempo(int totalseg, int& horas, int& min, int& seg) {
    horas = totalseg/3600;
    totalseg %= 3600;
    min = totalseg/60;
    seg = totalseg%60;
}