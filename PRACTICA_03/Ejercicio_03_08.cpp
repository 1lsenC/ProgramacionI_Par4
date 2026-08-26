// Materia: Programación I, Paralelo 4
// Autor: Ilsen Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:26/08/2026

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main (){
    srand(time(NULL));
    system("cls");
    int limSup = 10000, limInf = 10;

    int productos;
    double preciomax = 0;
    double preciomin = 0;
    double preciofin;
    double IVA = 0;
    double total = 0,  totalIVA = 0, totaldescuento = 0;

    cout << "\tLA ESTRELLA" << endl;
    cout << "- El IVA es del 13%" << endl;
    cout << "- Si el precio supera los 2500 obtiene descuento corporativo del 5%" << endl;

    cout << "\nREGISTRO DE VENTAS DIARIAS" << endl;
    cout << "Ingrese la cantidad de ventas diarias: ";
    cin >> productos;

    for (int i = 1; i <= productos; i++) {
        double venta = ((rand() % (limSup-limInf+1))+limInf);        
        IVA = venta * 0.13;
        double descuento = 0;

        if (venta > 2500) {
            descuento = venta * 0.05;
        }

        preciofin = venta - descuento;
        total += preciofin;
        totalIVA += IVA;
        totaldescuento += descuento;

        if (i == 1) {
            preciomax = preciofin;
            preciomin = preciofin;
        }
        else {
            if (preciofin > preciomax) {
                preciomax = preciofin;
            }
            if (preciofin < preciomin) {
                preciomin = preciofin;
            }
        }
    }
    
    cout << "\n" << "\tTOTAL DE VENTAS" << endl;
    cout << "Total de las ventas: " << total << "Bs" << endl;
    cout << "Monto acumulado del IVA: " << totalIVA << "Bs" << endl;
    cout << "Total descontado a clientes: " << totaldescuento << endl;
    cout << "Producto mas caro: " << preciomax << "Bs" << endl;
    cout << "Producto mas barato: " << preciomin << "Bs" << endl;

    return 0;
}