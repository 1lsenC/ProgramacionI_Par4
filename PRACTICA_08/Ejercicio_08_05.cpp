// Materia: Programación I, Paralelo 4
// Autor: Ilsen Arlett Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación: 06/10/2026
// Numero de ejercicio: 5

#include <iostream>
#include <string>
using namespace std;
void ExtraerComponentes(string url);

int main() {
    system("cls");
    string url;
    cout << "Ingrese la URL completa: ";
    getline(cin, url);

    cout << "\tCOMPONENTES EXTRAIDOS" << endl;
    ExtraerComponentes(url);

    return 0;
}

void ExtraerComponentes(string url) {
    size_t posProtocolo = url.find("://");
    if (posProtocolo != string::npos) {
        string protocolo = url.substr(0, posProtocolo);
        size_t inicioDominio = posProtocolo + 3;

        size_t posRuta = url.find('/', inicioDominio);
        string dominio = "";
        string ruta = "";

        if (posRuta != string::npos) {
            dominio = url.substr(inicioDominio, posRuta - inicioDominio);
            ruta = url.substr(posRuta);
        } 
        else {
            dominio = url.substr(inicioDominio);
            ruta = "/";
        }
        cout << "Protocolo: " << protocolo << endl;
        cout << "Dominio: " << dominio << endl;
        cout << "Ruta: " << ruta << endl;
    } 
}