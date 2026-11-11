// Materia: Programación I, Paralelo 4
// Autor: Ilsen Arlett Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:10/11/2026
// Numero de ejercicio: 7

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Producto {
    string nombre;
    string codigo;
    double precio;
};

void RegistrarProductos(vector<Producto> &inv, int n);
void AnalizarPrecios(vector<Producto> &inv);

int main() {
    system("cls");
    vector<Producto> inventario;
    int n;

    cout << "ANALISIS DE INVENTARIO" << endl;
    cout << "Ingrese la cantidad de productos: ";
    cin >> n;
    cin.ignore();
    RegistrarProductos(inventario, n);
    AnalizarPrecios(inventario);
    return 0;
}

void RegistrarProductos(vector<Producto> &inv, int n) {
    for (int i = 0; i < n; i++) {
        Producto p;
        cout << "\nProducto " << i + 1 << endl;
        cout << "Nombre: ";
        getline(cin, p.nombre);
        cout << "Codigo: ";
        getline(cin, p.codigo);
        cout << "Precio: ";
        cin >> p.precio;
        cin.ignore();
        inv.push_back(p);
    }
}

void AnalizarPrecios(vector<Producto> &inv) {
    int posCaro = 0;
    int posBarato = 0;
    for (int i = 1; i < inv.size(); i++) {
        if (inv[i].precio > inv[posCaro].precio) {
            posCaro = i;
        }
        if (inv[i].precio < inv[posBarato].precio) {
            posBarato = i;
        }
    }
    cout << "\tREPORTE DE PRECIOS" << endl;
    cout << "Producto mas caro:" << endl;
    cout << "- Nombre: " << inv[posCaro].nombre << " | Precio: " << inv[posCaro].precio << endl;
    cout << "Producto mas barato:" << endl;
    cout << "- Nombre: " << inv[posBarato].nombre << " | Precio: " << inv[posBarato].precio << endl;
}