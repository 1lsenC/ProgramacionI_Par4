// Materia: Programación I, Paralelo 4
// Autor: Ilsen Arlett Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación: 06/10/2026
// Numero de ejercicio: 3

#include <iostream>
#include <string>
using namespace std;
int CalcularSuma(string numeroTarjeta);

int main() {
    system("cls");
    string tarjeta;
    int sumaTotal = 0;
    cout << "Ingrese los 16 digitos de la tarjeta de credito: ";
    getline(cin, tarjeta);

    if (tarjeta.length() != 16) {
        cout << "\nLa tarjeta debe tener exactamente 16 digitos." << endl;
    } 
    else {
        sumaTotal = CalcularSuma(tarjeta);
        if (sumaTotal % 10 == 0) {
            cout << "\n" << "\tTarjeta Valida" << endl;
        } 
        else {
            cout << "\n" << "\tTarjeta Invalida" << endl;
        }
    }

    return 0;
}

int CalcularSuma(string numeroTarjeta) {
    int suma = 0;
    int cont = 1;

    for (int i = numeroTarjeta.length() - 1; i >= 0; i--) {
        int digito = numeroTarjeta[i] - '0';
        if (cont % 2 == 0) {
            digito *= 2;
            if (digito > 9) {
                digito -= 9;
            }
        }
        suma += digito;
        cont++;
    }
    return suma;
}