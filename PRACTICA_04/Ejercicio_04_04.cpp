// Materia: Programación I, Paralelo 4
// Autor: Ilsen Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:01/09/2026

#include <iostream>
using namespace std;
double conversiondivisas (double Bs, double Cambio);

int main (){
    double bolivianos;
    double Doficial;
    double Dparalelo;
    double conversionP;
    double conversionO;

    cout << "Conversion de bolivianos a dolares" << endl;
    cout << "La cantidad de Bolivianos que quiere cambiar es: ";
    cin >> bolivianos;
    cout << "El tipo del cambio de dolar Ooficial es de: ";
    cin >> Doficial;
    cout << "El tipo de cambio del dolar Paralelo es de: ";
    cin >> Dparalelo;

    conversionO = conversiondivisas (bolivianos, Doficial);
    conversionP = conversiondivisas (bolivianos, Dparalelo);

    cout << "\n";
    cout << "Sus Bs a dolares con el tipo de cambio oficial son de: " << conversionO << endl;
    cout << "Sus Bs a dolares con el tipo de cambio paralelo son de: " << conversionP << endl;

return 0;
}

double conversiondivisas (double Bs, double Cambio){
    double conversion;
    conversion = Bs/Cambio;
    return conversion;
}