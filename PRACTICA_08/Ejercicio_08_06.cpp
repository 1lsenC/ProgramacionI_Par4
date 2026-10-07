// Materia: Programación I, Paralelo 4
// Autor: Ilsen Arlett Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación: 07/10/2026
// Numero de ejercicio: 6

#include <iostream>
#include <string>
using namespace std;
string LimpiarEspacios(string texto);

int main() {
    system("cls");
    string textoOriginal;
    cout << "Ingrese un texto: ";
    getline(cin, textoOriginal);
    
    string textoLimpio = LimpiarEspacios(textoOriginal);
    cout << "Texto limpio: "<< textoLimpio << endl;

    return 0;
}

string LimpiarEspacios(string texto) {
    string resultado = "";
    char caracterActual;

    for (int i = 0; i < texto.length(); i++) {
        caracterActual = texto[i];
        if (caracterActual == ' ') {
            if (resultado.length() > 0 && resultado[resultado.length() - 1] != ' ') {
                resultado += caracterActual;
            }
        } 
        else {
            resultado += caracterActual;
        }
    }
    if (resultado.length() > 0 && resultado[resultado.length() - 1] == ' ') {
        resultado.erase(resultado.length() - 1, 1);
    }
    return resultado;
}