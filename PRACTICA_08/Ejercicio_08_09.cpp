// Materia: Programación I, Paralelo 4
// Autor: Ilsen Arlett Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación: 06/10/2026
// Numero de ejercicio: 9

#include <iostream>
#include <string>
using namespace std;

string ConvertiraMinusculas (string texto);
int BuscarContactos(string contactos[], string letras);

int main() {
    system("cls");
    string contactos[5] = {"Marcelo", "Maria", "Martin", "Juan", "Marcos"};
    string letras;

    cout << "\tBUSCADOR DE CONTACTOS" << endl;
    cout << "Contactos disponibles: [Marcelo, Maria, Martin, Juan, Marcos]" << endl;
    
    cout << "\nIngrese el contacto buscado: ";
    cin >> letras;

    cout << "\nResultados: " << endl;
    int encontrados = BuscarContactos(contactos, letras);

    if (encontrados == 0) {
        cout << "No se encontraron contactos" << endl;
    } 
    else {
        cout << "\nTotal de contactos encontrados: " << encontrados << endl;
    }
    return 0;
}

int BuscarContactos(string contactos[], string letras) {
    int contador = 0;
    string letraMin = ConvertiraMinusculas(letras);
    size_t tamNombre = letraMin.length();

    for (int i = 0; i < 5; i++) {
        if (contactos[i].length() >= tamNombre) {
            string inicioNombre = contactos[i].substr(0, tamNombre);

            if (ConvertiraMinusculas(inicioNombre) == letraMin) {
                cout << "- " << contactos[i] << endl;
                contador++;
            }
        }
    }
    return contador;
}

string ConvertiraMinusculas (string texto) {
    for (int i = 0; i < texto.length(); i++) {
        if (texto[i] >= 'A' && texto[i] <= 'Z') {
            texto[i] = texto[i] + ('a' - 'A');
        }
    }
    return texto;
}