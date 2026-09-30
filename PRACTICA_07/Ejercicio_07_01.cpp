// Materia: Programación I, Paralelo 4
// Autor: Ilsen Arlett Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación: 30/09/2026
// Numero de ejercicio: 1

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int aleatorios (int min, int max);
double aleatorioscondecimales (int min, int max);
char CaracterAleatorio();

void Voltajes(double Vector [], int cantidad=100);
void Temperaturas (double Vector [], int cantidad=50);
void CaracteresAlfanumericos (char Vector [], int cantidad=30);
void Anios (int Vector [], int cantidad=100);
void Velocidades (double Vector [], int cantidad=32);
void Distancias (double Vector [], int cantidad=1000);
void MostrarVector (double Vector [], int cantidad);
void MostrarVectorAnios (int Vector [], int cantidad);
void MostrarVectorAlfanumerico (char Vector [], int cantidad);

int main () {
    srand(time(NULL));
    system ("cls");
    double vectorVoltajes[100];
    double vectorTemperaturas[50];
    char vectorAlfanumericos[30];
    int vectorAnios[100];
    double vectorVelocidades[100];
    double vectorDistancias[100];

    Voltajes (vectorVoltajes);
    cout << "Lista de 100 voltajes entre 20V y 220V" << endl;
    MostrarVector (vectorVoltajes, 100);

    Temperaturas (vectorTemperaturas);
    cout << "\nLista de Temperaturas entre 0 y 100 grados" << endl;
    MostrarVector (vectorTemperaturas,50);

    CaracteresAlfanumericos (vectorAlfanumericos);
    cout << "\nLista de Caracteres Alfanumericos" << endl;
    MostrarVectorAlfanumerico (vectorAlfanumericos,30);

    Anios (vectorAnios);
    cout << "\nLista de anios entre 1990 y 2025" << endl;
    MostrarVectorAnios (vectorAnios,100);

    Velocidades (vectorVelocidades);
    cout << "\nLista de Velocidades entre 10 y 300" << endl;
    MostrarVector (vectorVelocidades,32);

    Distancias (vectorDistancias);
    cout << "\nLista de Distancias entre 1 y 1000" << endl;
    MostrarVector (vectorDistancias,50);
    return 0;
}

void Voltajes(double Vector [], int cantidad){
    for (int i = 0; i < cantidad; i++) {
        Vector[i] = aleatorioscondecimales (20.00, 220.00);
    }
}

void Temperaturas (double Vector [], int cantidad){
    for (int i = 0; i < cantidad; i++) {
        Vector[i] = aleatorioscondecimales (0.00, 100.00);
    }
}
void CaracteresAlfanumericos (char Vector [], int cantidad){
    for (int i = 0; i < cantidad; i++) {
        Vector[i] = CaracterAleatorio();
    }
}

void Anios (int Vector [], int cantidad){
    for (int i = 0; i < cantidad; i++) {
        Vector[i] = aleatorios (1990, 2025);
    }
}

void Velocidades (double Vector [], int cantidad){
    for (int i = 0; i < cantidad; i++) {
        Vector[i] = aleatorioscondecimales (10.00, 300.00);
    }
}

void Distancias (double Vector [], int cantidad){
    for (int i = 0; i < cantidad; i++) {
        Vector[i] = aleatorioscondecimales (1.00, 1000.00);
    }
}

void MostrarVector (double Vector [], int cantidad){
    for (int i = 0; i < cantidad; i++) {
        cout << Vector[i] << "   ";
        if ((i + 1) % 10 == 0) {
            cout << endl;
        }
    }
}

void MostrarVectorAnios (int Vector [], int cantidad){
    for (int i = 0; i < cantidad; i++) {
        cout << Vector[i] << "   ";
        if ((i + 1) % 10 == 0) {
            cout << endl;
        }
    }
}

void MostrarVectorAlfanumerico (char Vector [], int cantidad){
    for (int i = 0; i < cantidad; i++) {
        cout << Vector[i] << "  ";
        if ((i + 1) % 10 == 0) {
            cout << endl;
        }
    }
}

int aleatorios (int min, int max) {
    return ((rand() % (max-min+1))+min);
}
double aleatorioscondecimales (int min, int max){
    return (rand() % (max * 100 - min * 100 + 1) + min * 100) / 100.00;
}
char CaracterAleatorio() {
    if (rand() % 2 == 0) {
        return '0' + rand() % ('9' - '0' + 1);
    } 
    else {
        return 'A' + rand() % ('Z' - 'A' + 1);
    }
}