// Materia: Programación I, Paralelo 4
// Autor: Ilsen Arlett Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:28/09/2026
// Numero de ejercicio: 4

#include <iostream>
#include <vector>
using namespace std;

void MultiplicarVectores (vector<int> Vector1, vector<int> Vector2, vector<int> &resultado);
void NumerosdelosVectores (int cantidad, vector<int> &Vector1, vector<int> &Vector2);

int main () {
    system ("cls");
    int n = 0;
    vector<int> vector1;
    vector<int> vector2;
    vector<int> resultadoFinal;

    cout << "Cantidad de numeros en los 2 vectores: ";
    cin >> n;
    
    NumerosdelosVectores(n,vector1, vector2);
    MultiplicarVectores (vector1, vector2, resultadoFinal);

    cout << "\n" << "La multiplicacion de ambos vectores es: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Elemento " << i + 1 << ": " << resultadoFinal[i] << endl;
    }
    return 0;
}

void NumerosdelosVectores (int cantidad, vector<int> &Vector1, vector<int> &Vector2){
    int valor1, valor2;
    cout << "Datos del Primer Vector" << endl;
    for (int i = 0; i < cantidad; i++) {
        cout << "Elemento " << i + 1 << ": ";
        cin >> valor1;
        Vector1.push_back(valor1);
    }
    
    cout << "\nDatos del Segundo Vector" << endl;
    for (int i = 0; i < cantidad; i++) {
        cout << "Elemento " << i + 1 << ": ";
        cin >> valor2;
        Vector2.push_back(valor2);
    }
}

void MultiplicarVectores (vector<int> Vector1, vector<int> Vector2, vector<int> &resultado) {
    for (int i = 0; i < Vector1.size(); i++) {
        resultado.push_back(Vector1[i] * Vector2[i]);
    }
}