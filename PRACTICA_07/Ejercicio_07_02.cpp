// Materia: Programación I, Paralelo 4
// Autor: Ilsen Arlett Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:28/09/2026
// Numero de ejercicio: 2

#include <iostream>
#include <vector>
using namespace std;

void LlenarVoltajes (vector<double> &valores, int cantidad);
void MostrarVector(vector<double> &valores);
int aleatorios (int min, int max);

int main () {
    system ("cls");
    int n = 0;
    vector<double> voltajes;
    cout << "Cantidad de numeros en el vector para llenar: ";
    cin >> n;

    LlenarVoltajes (voltajes, n);
    MostrarVector (voltajes);
    return 0;
}

void LlenarVoltajes (vector<double> &valores, int cantidad){
    double valor = 0;
    cout << "Ingrese los valores de voltaje: " << endl;
    for (int i = 0; i < cantidad; i++)
    {
        cout << "Valor de voltaje " << i+1 << ": ";
        cin >> valor;
        valores.push_back(valor);
    }
}

void MostrarVector(vector<double> &valores) {
    cout << "\n";
    for (int i = 0; i < size(valores); i++)
    {
        cout << valores[i] << "\t";
        if (i == 2 || i == 5) {
            cout << "\n";
        }
    }
}