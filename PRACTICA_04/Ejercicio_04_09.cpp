// Materia: Programación I, Paralelo 4
// Autor: Ilsen Chivas Machaca
// Carrera del estudiante: Ingenieria Mecatronica
// Fecha creación:02/09/2026

#include <iostream>
using namespace std;
bool NotaValida(double nota);
bool estaHabilitado(double p1, double p2, double p3);
double calcularNotaFinal(double p1, double p2, double p3, double ef);

int main() {
    double estudiantes;
    double notaP1 = 0, notaP2 = 0, notaP3 = 0;
    double notaExamenfinal = 0;
    double notaFinal = 0;
    double Aprobados = 0, Reprobados = 0;
    double Promnota = 0;
    double Promedionotas = 0;
    double Porcentajeaprobados = 0;
    double Porcentajereprobados = 0;

    cout << "\tUCB - RENDIMIENTO ACADEMICO" << endl;
    cout << "Ingrese la cantidad de estudiantes que quiere analizar: ";
    cin >> estudiantes;

    for (int i = 1; i <= estudiantes; i++) {
        cout << "\n";
        cout << "\tEstudiante Nro " << i << endl;

        cout << "Ingrese las 3 notas parciales del estudiante" << endl;
        cout << "Nota Parcial 1: ";
        cin >> notaP1;
        cout << "Nota Parcial 2: ";
        cin >> notaP2;
        cout << "Nota Parcial 3: ";
        cin >> notaP3;

        if (NotaValida(notaP1) && NotaValida(notaP2) && NotaValida(notaP3)) {
        
            if (!estaHabilitado(notaP1, notaP2, notaP3)) {
                // Averigue que ese "!" sirve para invertir los valores booleanos, de TRUE a FALSE o al reves

                cout << "Una o varias notas fueron menores que 60, no dio el examen final" << endl;
                cout << "REPROBADO" << endl;
                notaExamenfinal = 0;
                notaFinal = calcularNotaFinal(notaP1, notaP2, notaP3, notaExamenfinal);
                Promnota += notaFinal;
                Reprobados++;
            } 
            else {
                cout << "Ingrese la nota del examen final: ";
                cin >> notaExamenfinal;

                if (NotaValida(notaExamenfinal)) {
                    notaFinal = calcularNotaFinal(notaP1, notaP2, notaP3, notaExamenfinal);
                    Promnota += notaFinal;

                    cout << "\n";
                    if (notaFinal >= 51) {
                        cout << "APROBADO" << endl;
                        Aprobados++;
                    } 
                    else {
                        cout << "REPROBADO" << endl;
                        Reprobados++;
                    }
                } 
            }
            cout << "NOTA PARCIAL 1: " << notaP1 << endl;
            cout << "NOTA PARCIAL 2: " << notaP2 << endl;
            cout << "NOTA PARCIAL 3: " << notaP3 << endl;
            cout << "NOTA EXAMEN FINAL: " << notaExamenfinal << endl;
            cout << "NOTA FINAL: " << notaFinal << endl;
        } 
    }
    
    Porcentajeaprobados = (Aprobados / estudiantes) * 100;
    Porcentajereprobados = (Reprobados / estudiantes) * 100;
    Promedionotas = Promnota / estudiantes;

    cout << "\n\tRESUMEN ACADEMICO" << endl;
    cout << "Porcentaje de alumnos APROBADOS: " << Porcentajeaprobados << "%" << endl;
    cout << "Porcentaje de alumnos REPROBADOS: " << Porcentajereprobados << "%" << endl;
    cout << "Promedio de las notas: " << Promedionotas << endl;

    return 0;
}
bool NotaValida(double nota) {
    return (nota >= 0 && nota <= 100);
}
bool estaHabilitado(double p1, double p2, double p3) {
    return (p1 >= 60 && p2 >= 60 && p3 >= 60);
}
double calcularNotaFinal(double p1, double p2, double p3, double ef) {
    double promedio = (((p1 + p2 + p3) / 3)*0.5)+(ef*0.5);
    return promedio;
}