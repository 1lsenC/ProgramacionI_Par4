// Materia: Programación I, Paralelo 4
// Autor: Ilsen Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:01/09/2026

#include <iostream>
using namespace std;
bool NumeroPar(int numero);

int main (){
    int num;
    int Par;
    
    cout << "Ingrse un numero para verificar si es par: ";
    cin >> num;

    Par = NumeroPar(num);
    if (Par == true) {
        cout << "El numero es par (" << Par << " - TRUE)" << endl;
    }
    else {
        cout << "El numero no es par (" << Par << " - FALSE)" << endl;
    }
    return 0;
}

bool NumeroPar(int numero){
    if (numero % 2 == 0) {
        return true;
    }
    else {
        return false;
    } 
}