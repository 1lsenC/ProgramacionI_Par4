// Materia: Programación I, Paralelo 4
// Autor: Ilsen Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:25/08/2026

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main (){
    srand(time(NULL));
    system("cls");

    int limSup = 100;
    int limInf = 1;
    int numero;
    int respuesta;
    int intentos = 0;

    respuesta = ((rand() % (limSup-limInf+1))+limInf);
    cout << "Adivina el numero entre 1 y 100" << endl;
    do {
        cout << "El numero que piensas es:";
        cin >> numero;
        intentos++;

        if (numero == respuesta) {
            cout << "\nCorrecto, el numero es " << respuesta << endl;
            cout << "Los intentos que tuviste: " << intentos << endl;
        }
        else if (numero > respuesta) {
            cout << "El numero es menor que ese\n" << endl;
        }
        else {
            cout << "El numero es mayor que ese\n" << endl;
        }
    } while (numero != respuesta);
    
    return 0;
}