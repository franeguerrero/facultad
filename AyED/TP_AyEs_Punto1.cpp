#include <iostream>
using namespace std;

//  FUNCIONES consigna 1:
// Elabore una función para registro académico AyEd, que solicite Numero de curso y sus correspondientes notas de periodo. Cuyo prototipo es int registroAcademico(int(int, int, int, int,int, int, int) Curso, 1er Parcial, 2do Parcial, 1er Rec 1er P,2do R 1erP, 2do Rec 1er P, 2do R 2doP. Cero en nota es ausente. Retorna 1..4: promocion, aprobado, no aprobado, ausente

// Creo la funcion registroAcademico
string registroAcademico(int curso, int parcial1, int parcial2, int recParcial11, int recParcial21, int recParcial12, int recParcial22)
{

    int nota_final_parcial1 = parcial1; // Busco la nota más alta del primer parcial
    if (recParcial11 > nota_final_parcial1)
        nota_final_parcial1 = recParcial11;
    if (recParcial21 > nota_final_parcial1)
        nota_final_parcial1 = recParcial21;

    int nota_final_parcial2 = parcial2; // Busco la nota más alta del segundo parcial
    if (recParcial12 > nota_final_parcial2)
        nota_final_parcial2 = recParcial12;
    if (recParcial22 > nota_final_parcial2)
        nota_final_parcial2 = recParcial22;

    // Verifica si se dio un recuperatorio para ambos parciales
    bool recuperatorio_parcial1 = (recParcial11 == parcial1) || (recParcial21 == parcial1);
    bool recuperatorio_parcial2 = (recParcial12 == parcial2) || (recParcial22 == parcial2);

    // Calculo el promedio de cada parcial
    float promedio_parcial1 = nota_final_parcial1;
    float promedio_parcial2 = nota_final_parcial2;

    float promedio_final = (promedio_parcial1 + promedio_parcial2) / 2.0; // Calcula el promedio entre los dos parciales

    // Verificación del resultado para retorno
    if (promedio_final >= 8 && promedio_final <= 10 && recuperatorio_parcial1 && recuperatorio_parcial2)
    {
        return "Promocionado";
    }
    else if (promedio_final >= 6)
    {
        return "Aprobado";
    }
    else if (promedio_final >= 1 && promedio_final <= 5)
    {
        return "Desaprobado";
    }
    else
    {
        return "Ausente";
    }
}

int main()
{ // Encabezado

    // Declaramos las variables
    int curso;
    int parcial1, parcial2, recParcial11, recParcial21, recParcial12, recParcial22;

    // Solicitar al usuario ingresar el número de curso y sus notas
    cout << "Ingrese el numero de curso: ";
    cin >> curso;
    cout << "Ingrese la nota del primer parcial (0 - 10): ";
    cin >> parcial1;
    if (parcial1 < 8)
    {
        cout << "Ingrese la nota del primer recuperatorio del primer parcial (0 - 10): ";
        cin >> recParcial11;

        if (recParcial11 < 8)
        {
            cout << "Ingrese la nota del segundo recuperatorio del primer parcial (0 - 10): ";
            cin >> recParcial21;
        }
        else
        {
            recParcial21 = recParcial11;
        };
    }
    else
    {
        recParcial11 = parcial1;
        recParcial21 = parcial1;
    };

    cout << "Ingrese la nota del segundo parcial (0 - 10): ";
    cin >> parcial2;
    if (parcial2 < 8)
    {
        cout << "Ingrese la nota del primer recuperatorio del segundo parcial (0 - 10): ";
        cin >> recParcial12;

        if (recParcial12 < 8)
        {
            cout << "Ingrese la nota del segundo recuperatorio del segundo parcial (0 - 10): ";
            cin >> recParcial22;
        }
        else
        {
            recParcial22 = recParcial12;
        };
    }
    else
    {
        recParcial12 = parcial2;
        recParcial22 = parcial2;
    };

    string resultado = registroAcademico(curso, parcial1, parcial2, recParcial11, recParcial21, recParcial12, recParcial22);

    cout << "Nota: " << resultado << endl; // Mostrar el resultado

    return 0; // Finalizar
}
