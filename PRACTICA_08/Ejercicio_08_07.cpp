// Materia: Programación I, Paralelo 4
// Autor: Ilsen Arlett Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación: 07/10/2026
// Numero de ejercicio: 7

#include <iostream>
#include <string>
using namespace std;

int ExtraerHashtags(string texto, string hashtags[]);
void MostrarHashtags(string hashtags[], int cantidad);

int main() {
    system("cls");
    string texto;
    string hashtags[50];
    int totalHashtags;

    cout << "Ingrese la publicacion o tweet: ";
    getline(cin, texto);
    totalHashtags = ExtraerHashtags(texto, hashtags);

    cout << "\nLista de hashtags: ";
    MostrarHashtags(hashtags, totalHashtags);

    return 0;
}

int ExtraerHashtags(string texto, string hashtags[]) {
    int contador = 0;
    size_t espacio = texto.find (' ');
    texto = texto + " ";
    
    while (espacio != string::npos) {
       string palabra = texto.substr(0, espacio);

        if (palabra[0] == '#') {
            hashtags[contador] = palabra;
            contador++;
        }
        texto.erase(0, espacio + 1);
        espacio = texto.find(' ');
    }
    return contador;
}

void MostrarHashtags(string hashtags[], int cantidad) {
    cout << "\nLista de hashtags: [";
    for (int i = 0; i < cantidad; i++) {
        cout << hashtags[i];
        if (i < cantidad - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}