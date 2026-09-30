// Materia: Programación I, Paralelo 4
// Autor: Ilsen Arlett Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:28/09/2026
// Numero de ejercicio: 5

#include <iostream>
#include <vector>
using namespace std;
void LlenarElementos (int tam, vector<int> &Vector1, vector<int> &Vector2);
void CombinarVectores (vector<int> Vector1, vector<int> Vector2, vector<int> &Vector3);

int main () {
    system ("cls");
    int N;
    vector<int> vector1;
    vector<int> vector2;
    vector<int> vector3;
    cout << "Cantidad de elementos en los vectores: ";
    cin >> N;

    LlenarElementos (N, vector1, vector2);
    CombinarVectores (vector1, vector2, vector3);

    cout << "\nVector combinado:" << endl;
    for (size_t i = 0; i < vector3.size(); i++) {
        cout << "Elemento " << i + 1 << ": " << vector3[i] << endl;
    }
    return 0;
}

void LlenarElementos (int tam, vector<int> &Vector1, vector<int> &Vector2) {
    int valor1, valor2;
    cout << "Datos del Primer Vector" << endl;
    for (int i = 0; i < tam; i++) {
        cout << "Elemento " << i + 1 << ": ";
        cin >> valor1;
        Vector1.push_back(valor1);
    }
    
    cout << "Datos del Segundo Vector" << endl;
    for (int i = 0; i < tam; i++) {
        cout << "Elemento " << i + 1 << ": ";
        cin >> valor2;
        Vector2.push_back(valor2);
    }
}

void CombinarVectores (vector<int> Vector1, vector<int> Vector2, vector<int> &Vector3) {
    Vector3.insert(Vector3.end(), Vector1.begin(), Vector1.end());
    Vector3.insert(Vector3.end(), Vector2.begin(), Vector2.end());
}