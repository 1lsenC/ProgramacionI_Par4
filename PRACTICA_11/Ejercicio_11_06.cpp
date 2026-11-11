// Materia: Programación I, Paralelo 4
// Autor: Ilsen Arlett Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:10/11/2026
// Numero de ejercicio: 6

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Contacto {
    string nombreCompleto;
    int telefono;
};

void LlenarContactos(vector<Contacto> &lista, int n);
void BuscarContacto(vector<Contacto> &lista, string busqueda);

int main() {
    system("cls");
    vector<Contacto> agenda;
    int n;
    string criterio;

    cout << "\tBUSCADOR DE CONTACTOS" << endl;
    cout << "Cantidad de contactos a ingresar: ";
    cin >> n;
    cin.ignore();
    LlenarContactos(agenda, n);

    cout << "\nIngrese el nombre o texto a buscar: ";
    getline(cin, criterio);
    BuscarContacto(agenda, criterio);
    return 0;
}

void LlenarContactos(vector<Contacto> &lista, int n) {
    for (int i = 0; i < n; i++) {
        Contacto c;
        cout << "\nContacto " << i + 1 << ":" << endl;
        cout << "Nombre completo: ";
        getline(cin, c.nombreCompleto);
        cout << "Telefono: ";
        cin >> c.telefono;
        cin.ignore();
        lista.push_back(c);
    }
}

void BuscarContacto(vector<Contacto> &lista, string busqueda) {
    cout << "\nResultados de busqueda de: " << busqueda << endl;
    bool encontrado = false;
    for (int i = 0; i < lista.size(); i++) {
        if (lista[i].nombreCompleto.find(busqueda) != string::npos) {
            cout << "- Nombre: " << lista[i].nombreCompleto << " | Telefono: " << lista[i].telefono << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No se encontraron contactos que coincidan con la busqueda." << endl;
    }
}