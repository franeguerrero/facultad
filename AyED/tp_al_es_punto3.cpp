#include <iostream>
#include <format>
using namespace std;


/*Elabore una funcion que riciba tres valores enteros que representan un dia, un mes y un año.
de una fecha del siglo 20 o 21 y retorne fecha valida? 1:o;*/

bool esBisiesto(int ano)
{ // te dice si es verdadero o falso un booleano

    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

bool validarFecha (int dia, int mes, int ano)
{

    // verificamos el rango del año
    if (ano < 1900 || ano >= 2100)
    {

        return false;
    }
    if (mes < 1 || mes > 12)
    { // verificamos el rango de los meses

        return false;
    }
    if (dia < 1)
    {

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

string formatearFecha(int dia, int mes, int ano){

    if (validarFecha(dia, mes, ano)){

    return to_string(ano)+to_string(mes)+to_string(dia);

    }
        return " error la fecha no es valida ";
}

int main() {
    int dia, mes, ano;

    cout << "Ingrese el dia: ";
    cin >> dia;

    cout << "Ingrese el mes: ";
    cin >> mes;

    cout << "Ingrese el ano: ";
    cin >> ano;

    if (validarFecha(dia, mes, ano)) {
        cout << formatearFecha(dia, mes, ano) << endl;
    } else {
        cout << "La fecha ingresada no es valida." << endl;
    }

    return 0;
}

