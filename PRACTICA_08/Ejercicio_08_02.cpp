// Materia: Programación I, Paralelo 4
// Autor: Ilsen Arlett Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación: 06/10/2026
// Numero de ejercicio: 2

#include <iostream>
#include <string>
using namespace std;
bool ContraseniaSegura(string cont);

int main () {
    system("cls");
    string contrasenia;
    cout << "Ingrese la contrasenia a evaluar: ";
    getline(cin, contrasenia);

    if (ContraseniaSegura(contrasenia)) {
        cout << "Contrasenia segura" << endl;
    } else {
        cout << "Contrasenia vulnerable" << endl;
    }
    return 0;
}

bool ContraseniaSegura(string cont) {
    if (cont.length() < 8) {
        return false;
    }
    bool Mayuscula = false;
    bool Minuscula = false;
    bool Numero = false;
    bool CaracterEspecial = false;

    for (int i = 0; i < cont.length(); i++) {
        char c = cont[i];

        if (c >= 'A' && c <= 'Z') {
            Mayuscula = true;
        } 
        else if (c >= 'a' && c <= 'z') {
            Minuscula = true;
        } 
        else if (c >= '0' && c <= '9') {
            Numero = true;
        } 
        else {
            CaracterEspecial = true;
        }
    }
    return (Mayuscula && Minuscula && Numero && CaracterEspecial);
}
