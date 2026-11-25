// Materia: Programación I, Paralelo 4
// Autor: Ilsen Arlett Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:25/11/2026
// Numero de ejercicio: 3

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
using namespace std;

struct Pizza {
    int codigo;
    char nombre[30];
    char tipo[15];
    char tamano[20];
    double precio;
    int cantidadVendida;
};

void AdicionarPizza();
void ListadoPizzas();
void ModificarPrecioPizza();
void EliminarPizza();
void AdicionarVentasPizzas();

int main() {
    int opcion;
    do {
    cout << "\nMENU PIZZERIA ELIS" << endl;
    cout << "1. Adicionar Pizza" << endl;
    cout << "2. Listado de Pizzas" << endl;
    cout << "3. Modificar el precio de la Pizza segun el codigo" << endl;
    cout << "4. Eliminar una Pizza" << endl;
    cout << "5. Adicionar Venta de Pizzas" << endl;
    cout << "6. Salir" << endl;
    cout << "Elija una opcion: ";
    cin >> opcion;
    cin.ignore();

    switch (opcion) {
        case 1:
            AdicionarPizza();
            break;
        case 2:
            ListadoPizzas();
            break;
        case 3:
            ModificarPrecioPizza();
            break;
        case 4:
            EliminarPizza();
            break;
        case 5:
            AdicionarVentasPizzas();
            break;
        case 6:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opcion no valida." << endl;
            break;
    }
} while (opcion != 6);
    return 0;
}

void AdicionarPizza() {
    Pizza pz;
    double precioBase;

    cout << "Codigo: ";
    cin >> pz.codigo;
    cin.ignore();
    cout << "Nombre: ";
    cin.getline(pz.nombre, 30);
    cout << "Tipo (TRADICIONAL / ESPECIAL): ";
    cin.getline(pz.tipo, 15);
    cout << "Tamano (Pizza XS, Mediana, Grande, Familiar, Interminable): ";
    cin.getline(pz.tamano, 20);
    cout << "Precio tradicional: ";
    cin >> precioBase;
    cin.ignore();

    if (strcmp(pz.tipo, "ESPECIAL") == 0 || strcmp(pz.tipo, "Especial") == 0) {
        pz.precio = precioBase * 1.10;
    } 
    else {
        pz.precio = precioBase;
    }
    pz.cantidadVendida = 0;

    ofstream archivo;
    archivo.open("PRODUCTO.BIN", ios::app | ios::binary);
    if (archivo.is_open()) {
        archivo.write((char*) &pz, sizeof(Pizza));
        archivo.close();
        cout << "Pizza guardada." << endl;
    }
}

void ListadoPizzas() {
    ifstream archivo;
    archivo.open("PRODUCTO.BIN", ios::in | ios::binary);
    Pizza pz;

    cout << "\nLISTADO DE PIZZAS" << endl;
    cout << "CODIGO | NOMBRE | TIPO | TAMANO | PRECIO | CANTIDAD | TOTAL" << endl;
    if (archivo.is_open()) {
        while (archivo.read((char*) &pz, sizeof(Pizza))) {
            double total = pz.precio * pz.cantidadVendida;
            cout << pz.codigo << " | " << pz.nombre << " | " << pz.tipo << " | " << pz.tamano << " | " << pz.precio << " | " << pz.cantidadVendida << " | " << total << endl;
        }
        archivo.close();
    }
}

void ModificarPrecioPizza() {
    int cod;
    double nuevoBase;
    cout << "Ingrese codigo de la pizza: ";
    cin >> cod;
    cout << "Ingrese nuevo precio base: ";
    cin >> nuevoBase;
    cin.ignore();

    fstream archivo;
    archivo.open("PRODUCTO.BIN", ios::in | ios::out | ios::binary);
    Pizza pz;
    bool encontrado = false;

    if (archivo.is_open()) {
        while (archivo.read((char*) &pz, sizeof(Pizza))) {
            if (pz.codigo == cod) {
                if (strcmp(pz.tipo, "ESPECIAL") == 0 || strcmp(pz.tipo, "Especial") == 0) {
                    pz.precio = nuevoBase * 1.10;
                } 
                else {
                    pz.precio = nuevoBase;
                }
                archivo.seekp(-(int)sizeof(Pizza), ios::cur);
                archivo.write((char*) &pz, sizeof(Pizza));
                encontrado = true;
            }
        }
        archivo.close();
    }

    if (encontrado) {
        cout << "Precio actualizado" << endl;
    } 
    else {
        cout << "Pizza no encontrada" << endl;
    }
}

void EliminarPizza() {
    int cod;
    cout << "Ingrese codigo de la pizza a eliminar: ";
    cin >> cod;
    cin.ignore();
    ifstream original;
    original.open("PRODUCTO.BIN", ios::in | ios::binary);
    ofstream temporal;
    temporal.open("temp.bin", ios::out | ios::binary);

    Pizza pz;
    bool eliminada = false;

    if (original.is_open() && temporal.is_open()) {
        while (original.read((char*) &pz, sizeof(Pizza))) {
            if (pz.codigo == cod) {
                eliminada = true;
            } 
            else {
                temporal.write((char*) &pz, sizeof(Pizza));
            }
        }
    }

    if (original.is_open()) {
        original.close();
    }
    if (temporal.is_open()) {
        temporal.close();
    }

    remove("PRODUCTO.BIN");
    rename("temp.bin", "PRODUCTO.BIN");

    if (eliminada) {
        cout << "Pizza eliminada" << endl;
    } 
    else {
        cout << "Codigo no encontrado" << endl;
    }
}

void AdicionarVentasPizzas() {
    ifstream ventas;
    ventas.open("VENTAS.TXT", ios::in);
    if (!ventas.is_open()) {
        cout << "No se pudo abrir el documento" << endl;
    }

    fstream bin;
    bin.open("PRODUCTO.BIN", ios::in | ios::out | ios::binary);
    if (!bin.is_open()) {
        cout << "No se pudo abrir el documento" << endl;
        ventas.close();
    }

    char ciCliente[20];
    int codPizza;
    char tamano[20];
    int cant;
    char puntoComa;

    while (ventas.getline(ciCliente, 20, ';')) {
        ventas >> codPizza >> puntoComa;
        ventas.getline(tamano, 20, ';');
        ventas >> cant;
        ventas.ignore();

        bin.clear();
        bin.seekg(0, ios::beg);
        bin.seekp(0, ios::beg);

        Pizza pz;
        while (bin.read((char*) &pz, sizeof(Pizza))) {
            if (pz.codigo == codPizza) {
                pz.cantidadVendida += cant;
                bin.seekp(-(int)sizeof(Pizza), ios::cur);
                bin.write((char*) &pz, sizeof(Pizza));
            }
        }
    }
    ventas.close();
    bin.close();
    cout << "Ventas de pizzas procesadas" << endl;
}