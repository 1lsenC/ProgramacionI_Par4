// Materia: Programación I, Paralelo 4
// Autor: Ilsen Arlett Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:20/10/2026
// Numero de ejercicio: 1

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void NombresyApellidos (string nom[], string ap[], int cant);
int aleatorios (int min, int max);

int main () {
    srand(time(NULL));
    int cantidad=0;
    string nombres [10] = {"Mateo", "Maria", "Carlos", "Nicole", "Pedro", "Miguel", "Luciana", "Gabriela", "Diego", "Elena"};
    string apellidos [10] = {"Gonzalez", "Rodriguez", "Lopez", "Martinez", "Perez", "Cardenas", "Sanchez", "Alvarez", "Huarina", "Torres"};
    
    cout << "Cantidad de nombres: ";
    cin >> cantidad;
    cout << "\tLista de nombres y apellidos:" << endl;
    NombresyApellidos (nombres, apellidos, cantidad);

    return 0;
}

void NombresyApellidos (string nom[], string ap[], int cant) {
    for (int i = 0; i < cant; i++) {
        int NombreAl = aleatorios (0,9);
        int ApellidoAl = aleatorios (0,9);
        cout << i+1 << ". " << nom[NombreAl] << " " << ap[ApellidoAl] << endl;;
    }
}

int aleatorios (int min, int max) {
    return ((rand() % (max-min+1))+min);
}