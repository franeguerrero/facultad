#include <iostream>
#include <string>
#include <sstream>
using namespace std;


/*
Elaboe una funcion que reciba una fecha valida del siglo 20 o 21
y la descomponga en sus componentes dia, mes y año y devuelva los valores
*/

bool esBisiesto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

bool fechaValida(int dia, int mes, int ano) {
    if (ano < 1900 || ano >= 2100) return false;
    if (mes < 1 || mes > 12) return false;
    if (dia < 1 || dia > 31) return false;

    if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) return false;
    if (mes == 2) {
        if (esBisiesto(ano)) {
            if (dia > 29) return false;
        } else {
            if (dia > 28) return false;
        }
    }

    return true;
}

void descomponerFecha(const string& fecha, int& dia, int& mes, int& ano) {
    stringstream ss(fecha);
    char sep;
    ss >> ano >> sep >> mes >> sep >> dia;
}

int main() {
    string fecha;
    cout << "Ingrese una fecha en formato AAAA/MM/DD: ";
    cin >> fecha;

    int dia, mes, ano;
    descomponerFecha(fecha, dia, mes, ano);

    if (fechaValida(dia, mes, ano)) {
        cout << "Ano: " << ano << ", Mes: " << mes << ", Dia: " << dia << endl;
    } else {
        cout << "Fecha invalida." << endl;
    }

    return 0;
}
