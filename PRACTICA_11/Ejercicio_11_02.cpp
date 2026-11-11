// Materia: Programación I, Paralelo 4
// Autor: Ilsen Arlett Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:10/11/2026
// Numero de ejercicio: 2

#include <iostream>
using namespace std;

struct Cuenta {
    char Titular[30];
    int NumeroCuenta;
    double saldo;
};
void LlenarDatos (Cuenta &datos);
void Depositar (Cuenta &saldo);
void Retirar (Cuenta &saldo);
void MostrarSaldo (Cuenta saldo);

int main () {
    system ("cls");
    int n;
    Cuenta DinerodeCuenta;
    DinerodeCuenta.saldo = 0;
    LlenarDatos (DinerodeCuenta);
    do
    {
        cout << "\tMENU" << endl;
        cout << "1. Depositar dinero" << endl;
        cout << "2. Retirar dinero" << endl;
        cout << "3. Mostrar su saldo" << endl;
        cout << "4. Salir" << endl;
        cout << "Que desea realizar:" << endl;
        cin >> n;
        switch (n) {
            case 1:
                Depositar (DinerodeCuenta);
                break;
            case 2:
                Retirar (DinerodeCuenta);
                break;
            case 3:
                MostrarSaldo (DinerodeCuenta);
                break;
            case 4:
                cout << "Saliendo del sistema" << endl;
                break;
            default:
                cout << "Opcion no valida" << endl;
                break;
        }
    } while (n!=4);
    return 0;
}

void LlenarDatos (Cuenta &datos) {
    cout << "\tCUENTA BANCARIA" << endl;
    cout << "Ingrese el titular de la cuenta: ";
    cin.getline(datos.Titular,31);
    cout << "Numero de cuenta: ";
    cin >> datos.NumeroCuenta;
    cin.ignore();
    cout << "\n";
}

void Depositar (Cuenta &saldo) {
    int monto = 0;
    cout << "Dinero que desea depositar: ";
    cin >> monto;
    saldo.saldo += monto;
    cout << "Deposito exitoso" << endl;
    cout << "Saldo actual: " << saldo.saldo << endl;
}

void Retirar (Cuenta &saldo) {
    int retirar = 0;
    int pruebaSaldo = saldo.saldo;
    cout << "Cuanto dinero va a retirar: ";
    cin >> retirar;
    pruebaSaldo -= retirar;

    if (pruebaSaldo >=0) {
        saldo.saldo -= retirar;
        cout << "Monto retirado con exito" << endl;
        cout << "Saldo actual: " << saldo.saldo << endl;
    }
    else {
        cout << "Saldo insuficiente" << endl;
    }
}

void MostrarSaldo (Cuenta saldo) {
    cout << "\n" << "\tDATOS DE SU CUENTA BANCARIA" << endl;
    cout << "TITULAR: " << saldo.Titular << endl;
    cout << "NUMERO DE CUENTA: " << saldo.NumeroCuenta << endl;
    cout << "SALDO ACTUAL: " << saldo.saldo << endl;
}