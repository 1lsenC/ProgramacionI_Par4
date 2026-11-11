// Materia: Programación I, Paralelo 4
// Autor: Ilsen Arlett Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:10/11/2026
// Numero de ejercicio: 4

#include <iostream>
#include <cstring> 
using namespace std;

struct Paquete {
    char codigoRastreo[30];
    char direccion[50];
    double pesokg;
    char estado[20];
};

void LlenarPaquete(Paquete &p);
void EntregarPaquete(Paquete &p);

int main() {
    system("cls");
    Paquete Estadodepaquete;
    LlenarPaquete(Estadodepaquete);
    EntregarPaquete(Estadodepaquete);
    cout << "\nTamano de la estructura Paquete en memoria: " << sizeof(Paquete) << " bytes" << endl;
    return 0;
}

void LlenarPaquete(Paquete &p) {
    cout << "\tREGISTRO DE PAQUETE" << endl;
    cout << "Codigo de rastreo: ";
    cin >> p.codigoRastreo;
    cin.ignore();
    cout << "Direccion de envio: ";
    cin.getline(p.direccion, 50);
    cout << "Peso en kg: ";
    cin >> p.pesokg;
    strcpy(p.estado,"Transito");
    cout << "En Transito" << "\n";
}

void EntregarPaquete(Paquete &p) {
    strcpy(p.estado, "Entregado");
    cout << "\n" << "\tRECIBO DE ENTREGA" << endl;
    cout << "Codigo de Rastreo : " << p.codigoRastreo << endl;
    cout << "Direccion: " << p.direccion << endl;
    cout << "Peso: " << p.pesokg << " kg" << endl;
    cout << "Estado Actual: " << p.estado << endl;
}