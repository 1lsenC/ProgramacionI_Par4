// Materia: Programación I, Paralelo 4
// Autor: Ilsen Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:25/08/2026

#include <iostream>
using namespace std;
int main (){
    int numero;
    int suma = 0;
    cout << "Suma del factorial del numero: ";
    cin >> numero;
    
    for (int i = 1; i <= numero; i++) {
        int multiplicacion = 1;
        for (int j = 1; j <= i; j++) {
        multiplicacion *= j;
    }
        suma += multiplicacion;
    }
    cout << "La factorial de " << numero << "!: " << suma << endl; 
    return 0;
}