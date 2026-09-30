// Materia: Programación I, Paralelo 4
// Autor: Ilsen Arlett Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:30/09/2026
// Numero de ejercicio: 3

#include <iostream>
using namespace std;

void CargarVector(int Vector[], int cantidad);
void MostrarVector(int Vector[], int cantidad);
int CalcularSuma(int Vector[], int cantidad);
double CalcularPromedio(int Vector[], int cantidad);
int EncontrarMayor(int Vector[], int cantidad);
int EncontrarMenor(int Vector[], int cantidad);

int main() {
    system("cls");
    int n = 0;
    cout << "Ingrese la cantidad de elementos para el vector: ";
    cin >> n;

    int Vector[n];
    CargarVector(Vector, n);
    cout << "\nEl vector ingresado es:" << endl;
    MostrarVector(Vector, n);

    int suma = CalcularSuma(Vector, n);
    double promedio = CalcularPromedio(Vector, n);
    int mayor = EncontrarMayor(Vector, n);
    int menor = EncontrarMenor(Vector, n);

    cout << "\tRESULTADOS" << endl;
    cout << "La suma de los elementos es: " << suma << endl;
    cout << "El promedio de los elementos es: " << promedio << endl;
    cout << "El elemento mayor es: " << mayor << endl;
    cout << "El elemento menor es: " << menor << endl;

    return 0;
}

void CargarVector(int Vector[], int cantidad) {
    cout << "\nDatos del vector" << endl;
    for (int i = 0; i < cantidad; i++) {
        cout << "Elemento " << i + 1 << ": ";
        cin >> Vector[i];
    }
}

void MostrarVector(int Vector[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        cout << "Elemento " << i + 1 << ": " << Vector[i] << endl;
    }
}

int CalcularSuma(int Vector[], int cantidad) {
    int suma = 0;
    for (int i = 0; i < cantidad; i++) {
        suma += Vector[i];
    }
    return suma;
}

double CalcularPromedio(int Vector[], int cantidad) {
    double Suma;
    Suma = (double)CalcularSuma(Vector, cantidad) / cantidad;
    return Suma;
}

int EncontrarMayor(int Vector[], int cantidad) {
    int mayor = Vector[0];
    for (int i = 1; i < cantidad; i++) {
        if (Vector[i] > mayor) {
            mayor = Vector[i];
        }
    }
    return mayor;
}

int EncontrarMenor(int Vector[], int cantidad) {
    int menor = Vector[0];
    for (int i = 1; i < cantidad; i++) {
        if (Vector[i] < menor) {
            menor = Vector[i];
        }
    }
    return menor;
}