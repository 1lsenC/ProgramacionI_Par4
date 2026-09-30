// Materia: Programación I, Paralelo 4
// Autor: Ilsen Arlett Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:28/09/2026
// Numero de ejercicio: 6

#include <iostream>
using namespace std;

void NumerosdelosVectores(int Vector1[], int Vector2[], int tam);
void SumarVectores(int Vector1[], int Vector2[], int resultado[], int tam);

int main() {
    system("cls");
    int vector1[5];
    int vector2[5];
    int resultadoFinal[5];

    cout << "Suma de vectores que tienen 5 elementos" << endl;
    NumerosdelosVectores(vector1, vector2, 5);
    SumarVectores(vector1, vector2, resultadoFinal, 5);

    cout << "\nLa suma de ambos vectores es: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Elemento " << i + 1 << ": " << resultadoFinal[i] << endl;
    }
    return 0;
}

void NumerosdelosVectores(int Vector1[], int Vector2[], int tam) {
    cout << "Datos del Primer Vector" << endl;
    for (int i = 0; i < tam; i++) {
        cout << "Elemento " << i + 1 << ": ";
        cin >> Vector1[i];
    }

    cout << "\nDatos del Segundo Vector" << endl;
    for (int i = 0; i < tam; i++) {
        cout << "Elemento " << i + 1 << ": ";
        cin >> Vector2[i];
    }
}

void SumarVectores(int Vector1[], int Vector2[], int resultado[], int tam) {
    for (int i = 0; i < tam; i++) {
        resultado[i] = Vector1[i] + Vector2[i];
    }
}