// Materia: Programación I, Paralelo 4
// Autor: Ilsen Arlett Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:20/10/2026
// Numero de ejercicio: 4

#include <iostream>
#include <vector>
using namespace std;

void LlenarPrecios (vector<double> &precio, int N);
void Ordenamiento (vector<double> &precio, int N);
void PrecioMenor (vector<double> precio, int N);
void PrecioMayor (vector<double> precio, int N);
void Promedio (vector<double> &precio, int N);

int main () {
    system ("cls");
    vector <double>PreciosdeProductos;
    int n;

    cout << "Ingrese la cantidad de productos vendidos: ";
    cin >> n;
    cout << "\n";
    cout << "Ingrese el precio de cada producto: " << endl;
    LlenarPrecios (PreciosdeProductos, n);

    cout << "\nLos precios de los productos vendidos fueron (de menor a mayor): " << endl;
    Ordenamiento (PreciosdeProductos, n);
    cout << "\n" << endl;
    PrecioMenor (PreciosdeProductos, n);
    PrecioMayor (PreciosdeProductos, n);
    Promedio (PreciosdeProductos, n);
    
    return 0;
}

void LlenarPrecios (vector<double> &precio, int N) {
    double p = 0;
    for (int i = 0; i < N; i++) {
        cout << i+1 << " producto: ";
        cin >> p;
        precio.push_back(p);
    }
}

void Ordenamiento (vector<double> &precio, int N) {
    double aux;
    for (int i = 0; i < N-1; i++) {
        for (int j = 0; j < N-1; j++) {
            if (precio[j] > precio[j+1]) {
                aux = precio[j];
                precio[j] = precio[j+1];
                precio [j+1] = aux;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << precio[i] << "Bs  ";
    }
}

void PrecioMenor (vector<double> precio, int N) {
    double menor = precio[0];
    for (int i = 1; i < N; i++) {
        if (precio[i] < menor) {
            menor = precio[i];
        }
    }
    cout << "El precio mas bajo fue de " << menor << "Bs" << endl;
}

void PrecioMayor (vector<double> precio, int N) {
    double mayor = precio[0];
    for (int i = 1; i < N; i++) {
        if (precio[i] > mayor) {
            mayor = precio[i];
        }
    }
    cout << "El precio mas alto fue de " << mayor << "Bs" << endl;
}

void Promedio (vector<double> &precio, int N) {
    double suma = 0;
    double prom = 0;

    for (int i = 0; i < N; i++) {
        suma += precio[i];
    }
    prom = suma/N;
    cout << "La media de los precios es de: " << prom;
}