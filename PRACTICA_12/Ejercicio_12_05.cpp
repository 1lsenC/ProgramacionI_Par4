// Materia: Programación I, Paralelo 4
// Autor: Ilsen Arlett Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:23/11/2026
// Numero de ejercicio: 5

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Producto {
    string nombre;
    double precio;
};

bool CargarProductos(vector<Producto> &productos, string nombreArchivo);
void GuardarProductos(vector<Producto> &productos, string nombreArchivo);
bool ActualizarPrecio(vector<Producto> &productos, string &nombreBuscado, double nuevoPrecio);

int main() {
    vector<Producto> inventario;
    string nombreProd;
    double nuevoPrecio;
    if (!CargarProductos(inventario, "productos.txt")) {
        cout << "No se pudo abrir el archivo" << endl;
    }
    else {
        cout << "\tACTUALIZAR PRECIOS" << endl;
        cout << "Ingrese el nombre del producto a actualizar: ";
        cin >> nombreProd;
        cout << "Ingrese el nuevo precio: ";
        cin >> nuevoPrecio;

        if (ActualizarPrecio(inventario, nombreProd, nuevoPrecio)) {
            GuardarProductos(inventario, "productos.txt");
            cout << "Precio actualizado correctamente" << endl;
        } 
        else {
            cout << "El producto '" << nombreProd << "' no existe en el archivo." << endl;
        }
    }
    return 0;
}

bool CargarProductos(vector<Producto> &productos, string nombreArchivo) {
    ifstream archivo;
    string linea;
    Producto p;
    archivo.open(nombreArchivo, ios::in);

    if (archivo.fail()) {
        cout << "No se pudo abrir el archivo" << endl;
        return false;
    }

    while (getline(archivo, linea)) {
        if (linea.length() > 0) {
            size_t espacio = linea.find(' ');
            if (espacio != string::npos) {
                p.nombre = linea.substr(0, espacio);
                string precioTexto = linea.substr(espacio + 1);
                p.precio = stod(precioTexto);
                productos.push_back(p);
            }
        }
    }
    archivo.close();
    return true;
}

bool ActualizarPrecio(vector<Producto> &productos, string &nombreBuscado, double nuevoPrecio) {
    for (int i = 0; i < productos.size(); i++) {
        if (productos[i].nombre == nombreBuscado) {
            productos[i].precio = nuevoPrecio;
            return true;
        }
    }
    return false;
}

void GuardarProductos(vector<Producto> &productos, string nombreArchivo) {
    ofstream archivo;
    archivo.open(nombreArchivo, ios::out);

    if (archivo.is_open()) {
        for (int i = 0; i < productos.size(); i++) {
            archivo << productos[i].nombre << " " << productos[i].precio << endl;
        }
        archivo.close();
    }
}