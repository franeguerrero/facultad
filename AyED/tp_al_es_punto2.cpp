#include <iostream>
using namespace std;

bool esBisiesto(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool validarFecha(int dia, int mes, int ano) {
    // Verificar el rango del año
    if (ano < 1900 || ano >= 2100) {
        return false;
    }

    // Verificar el rango del mes
    if (mes < 1 || mes > 12) {
        return false;
    }

    // Verificar el rango del día según el mes
    if (dia < 1) {
        return false;
    }

    switch (mes) {
        case 1: // Enero
        case 3: // Marzo
        case 5: // Mayo
        case 7: // Julio
        case 8: // Agosto
        case 10: // Octubre
        case 12: // Diciembre
            if (dia > 31) {
                return false;
            }
            break;
        case 4: // Abril
        case 6: // Junio
        case 9: // Septiembre
        case 11: // Noviembre
            if (dia > 30) {
                return false;
            }
            break;
        case 2: // Febrero
            if (esBisiesto(ano)) {
                if (dia > 29) {
                    return false;
                }
            } else {
                if (dia > 28) {
                    return false;
                }
            }
            break;
        default:
            return false;
    }

    return true;
}

int main() {
    int dia, mes, ano;

    cout << "Ingrese el día: ";
    cin >> dia;

    cout << "Ingrese el mes: ";
    cin >> mes;

    cout << "Ingrese el año: ";
    cin >> ano;

    if (validarFecha(dia, mes, ano)) {
        cout << "La fecha ingresada es válida." << endl;
    } else {
        cout << "La fecha ingresada no es válida." << endl;
    }

    return 0;
}