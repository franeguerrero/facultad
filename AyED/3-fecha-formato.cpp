#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <windows.h>

#pragma execution_character_set("utf-8")
using namespace std;

/*Elabore una funcion que riciba tres valores enteros que representan un dia, un mes y un año.
de una fecha del siglo 20 o 21 y retorne fecha valida? 1:o;*/

bool esBisiesto(int ano)
{ // te dice si es verdadero o falso un booleano

    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

bool fechaValida(int dia, int mes, int ano)
{
    if (ano < 1900 || ano >= 2100)
        return false;
    if (mes < 1 || mes > 12)
        return false;
    if (dia < 1 || dia > 31)
        return false;

    if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30)
        return false;
    if (mes == 2)
    {
        if (esBisiesto(ano))
        {
            if (dia > 29)
                return false;
        }
        else
        {
            if (dia > 28)
                return false;
        }
    }

    return true;
}

string formatearFecha(int dia, int mes, int ano)
{

    if (fechaValida(dia, mes, ano))
    {

        stringstream ss;
        ss << setw(4) << setfill('0') << ano
           << setw(2) << setfill('0') << mes
           << setw(2) << setfill('0') << dia;
        return ss.str();
    }
    return " error la fecha no es valida ";
}

int main()
{
    SetConsoleOutputCP(65001);

    int dia, mes, ano;

    cout << "Ingrese el día: ";
    cin >> dia;

    cout << "Ingrese el mes: ";
    cin >> mes;

    cout << "Ingrese el año: ";
    cin >> ano;

    if (fechaValida(dia, mes, ano))
    {
        cout << formatearFecha(dia, mes, ano) << endl;
    }
    else
    {
        cout << "La fecha ingresada no es válida." << endl;
    }

    return 0;
}
