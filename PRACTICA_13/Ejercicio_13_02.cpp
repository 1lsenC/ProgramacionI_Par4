// Materia: Programación I, Paralelo 4
// Autor: Ilsen Arlett Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:25/11/2026
// Numero de ejercicio: 2

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

struct Producto {
    int codigo;
    char nombre[30];
    int cantidadInicial;
    double precioUnitario;
    int cantidadVendida;
};

void AdicionarProducto();
void ListadoProductos();
void BuscarProducto();
void ModificarProducto();
void AdicionarVentas();

int main() {
    int opcion;
    do {
    cout << "\n \tMENU NOTAS UCB" << endl;
    cout << "1. Adicionar Producto" << endl;
    cout << "2. Listado de Productos" << endl;
    cout << "3. Buscar un producto por codigo" << endl;
    cout << "4. Modificar un producto" << endl;
    cout << "5. Adicionar ventas del producto" << endl;
    cout << "6. Salir" << endl;
    cout << "Elija una opcion: ";
    cin >> opcion;
    cin.ignore();

    switch (opcion) {
        case 1:
            AdicionarProducto();
            break;
        case 2:
            ListadoProductos();
            break;
        case 3:
            BuscarProducto();
            break;
        case 4:
            ModificarProducto();
            break;
        case 5:
            AdicionarVentas();
            break;
        case 6:
            cout << "Saliendo del programa" << endl;
            break;
        default:
            cout << "Opcion no invalida" << endl;
            break;
    }
} while (opcion != 6);
    return 0;
}

void AdicionarProducto() {
    Producto p;
    cout << "Codigo producto: ";
    cin >> p.codigo;
    cin.ignore();
    cout << "Nombre producto: ";
    cin.getline(p.nombre, 30);
    cout << "Cantidad inicial: ";
    cin >> p.cantidadInicial;
    cout << "Precio unitario: ";
    cin >> p.precioUnitario;
    cin.ignore();
    p.cantidadVendida = 0;

    ofstream archivo;
    archivo.open("PRODUCTOS.BIN", ios::app | ios::binary);
    if (archivo.is_open()) {
        archivo.write((char*) &p, sizeof(Producto));
        archivo.close();
        cout << "Producto guardado" << endl;
    }
}

void ListadoProductos() {
    ifstream archivo;
    archivo.open("PRODUCTOS.BIN", ios::in | ios::binary);
    Producto p;

    cout << "\nCODIGO | NOMBRE PRODUCTO | CANTIDAD INICIAL | PRECIO | CANTIDAD VENDIDA | TOTAL" << endl;
    if (archivo.is_open()) {
        while (archivo.read((char*) &p, sizeof(Producto))) {
            double total = p.cantidadVendida * p.precioUnitario;
            cout << p.codigo << " | " << p.nombre << " | " << p.cantidadInicial << " | " << p.precioUnitario << " | " << p.cantidadVendida << " | " << total << endl;
        }
        archivo.close();
    }
}

void BuscarProducto() {
    int cod;
    cout << "Ingrese codigo que quiere buscar: ";
    cin >> cod;
    cin.ignore();

    ifstream archivo;
    archivo.open("PRODUCTOS.BIN", ios::in | ios::binary);
    Producto p;
    bool encontrado = false;

    if (archivo.is_open()) {
        while (archivo.read((char*) &p, sizeof(Producto))) {
            if (p.codigo == cod) {
                cout << "Encontrado:  " << p.nombre << " | Stock: " << p.cantidadInicial << " | Precio: " << p.precioUnitario << " | Vendidos: " << p.cantidadVendida << endl;
                encontrado = true;
            }
        }
        archivo.close();
    }
    if (!encontrado) {
        cout << "Producto no encontrado" << endl;
    }
}

void ModificarProducto() {
    int cod;
    cout << "Ingrese codigo que va a modificar: ";
    cin >> cod;
    cin.ignore();

    fstream archivo;
    archivo.open("PRODUCTOS.BIN", ios::in | ios::out | ios::binary);
    Producto p;
    bool encontrado = false;

    if (archivo.is_open()) {
        while (archivo.read((char*) &p, sizeof(Producto))) {
            if (p.codigo == cod) {
                cout << "Nuevo nombre: ";
                cin.getline(p.nombre, 30);
                cout << "Nueva cantidad inicial: ";
                cin >> p.cantidadInicial;
                cout << "Nuevo precio unitario: ";
                cin >> p.precioUnitario;
                cin.ignore();
                archivo.seekp(-(int)sizeof(Producto), ios::cur);
                archivo.write((char*) &p, sizeof(Producto));
                encontrado = true;
            }
        }
        archivo.close();
    }

    if (encontrado) {
        cout << "Codigo del producto modificado" << endl;
    } 
    else {
        cout << "Codigo no encontrado" << endl;
    }
}

void AdicionarVentas() {
    ifstream ventas;
    ventas.open("VENTAS.txt", ios::in);
    if (ventas.fail()) {
        cout << "No se pudo abrir el documento" << endl;
    }

    fstream bin;
    bin.open("PRODUCTOS.BIN", ios::in | ios::out | ios::binary);
    if (!bin.is_open()) {
        cout << "No se pudo abrir la lista de productos" << endl;
        ventas.close();
    }

    char ciCliente[20];
    char nomCliente[50];
    char codTexto[20];
    char cantTexto[20];
    int codProd;
    int cantVendida;
    int ventasAplicadas = 0;

    while (ventas.getline(ciCliente, 20, ';')) {
        ventas.getline(nomCliente, 50, ';');
        ventas.getline(codTexto, 20, ';');
        ventas.getline(cantTexto, 20, '\n');
        codProd = atoi(codTexto);
        cantVendida = atoi(cantTexto);

        bin.clear();
        bin.seekg(0, ios::beg);
        bin.seekp(0, ios::beg);

        Producto p;
        bool actualizado = false;

        while (bin.read((char*) &p, sizeof(Producto))) {
            if (!actualizado && p.codigo == codProd) {
                p.cantidadVendida += cantVendida;

                bin.seekp(-(int)sizeof(Producto), ios::cur);
                bin.write((char*) &p, sizeof(Producto));
                bin.flush();

                cout << "Producto actualizado: " << p.nombre
                     << " (+" << cantVendida << " vendidos -> Total vendidos: " << p.cantidadVendida << ")" << endl;
                ventasAplicadas++;
                actualizado = true;
            }
        }
    }
    ventas.close();
    bin.close();
    if (ventasAplicadas > 0) {
        cout << "Ventas agregadas correctamente" << endl;
    } 
    else {
        cout << "No se aplicaron ventas" << endl;
    }
}