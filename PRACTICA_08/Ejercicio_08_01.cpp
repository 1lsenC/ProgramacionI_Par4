// Materia: Programación I, Paralelo 4
// Autor: Ilsen Arlett Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación: 06/10/2026
// Numero de ejercicio: 1

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int aleatorios (int min, int max);
void Nombres (string nom[], string ap[], int&edad, int cant);

int main () {
    system("cls");
    srand(time(NULL));
    int cantidad=0;
    string nombres [10] = {"Juan", "Maria", "Carlos", "Nicole", "Pedro", "Miguel", "Luciana", "Gabriela", "Diego", "Elena"};
    string apellidos [10] = {"Gonzalez", "Rodriguez", "Lopez", "Martinez", "Perez", "Cardenas", "Sanchez", "Alvarez", "Diaz", "Torres"};
    int edades = 0;
    
    cout << "Cantidad de nombres que desea: ";
    cin >> cantidad;
    cout << "\tCombinacion aleatoria:" << endl;
    Nombres (nombres, apellidos, edades, cantidad);

    return 0;
}
void Nombres (string nom[], string ap[], int&edad, int cant) {
    for (int i = 0; i < cant; i++) {
        edad = aleatorios (0,100);
        int Nombreal = aleatorios (0,9);
        int Apellidoal = aleatorios (0,9);
    
        cout << "Persona " << i+1 << ":" << endl;
        cout << "- " << nom[Nombreal] << " " << ap[Apellidoal] << " - " << edad << " anios" << endl;;
    }
}

int aleatorios (int min, int max) {
    return ((rand() % (max-min+1))+min);
}
