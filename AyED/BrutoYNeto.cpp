/*
Desarrollar una función que reciba el sueldo bruto de un empleado, y retorne el sueldo neto utilizando las mejores prácticas

Restricciones:
    Cada empleado tiene un Nivel (0, 1, 2, 3) y un Sueldo Base (SB).

Proceso:
    1. A todos se le aplican nos descuentos de Ley ISSS (3.1%) y Ganancias (9.3%).
    2. Si el Nivel del empleado es 2 o 3, se descuenta el 11.4% del SB en concepto de Seguro.
    3. Según el Nivel del empleado se le calcula un Bono sobre el SB tal que:
        • Nivel 0: un importe fijo en pesos asignado por parámetro
        • Nivel 1: 6.4% del SB
        • Nivel 2: 13.94% del SB
        • Nivel 3: 21.04% del SB
*/

#include <iostream>
using namespace std;

// Estructura para representar un empleado
struct Empleado
{
    int nivel;
    float sueldoBase;
};

// Función para calcular el sueldo neto
float calcularSueldoNeto(const Empleado &empleado, float bonoFijoNivel0)
{
    const float ISSS = 0.031;
    const float GANANCIAS = 0.093;
    const float SEGURO = 0.114;

    float descuentoLey = empleado.sueldoBase * (ISSS + GANANCIAS);
    float descuentoSeguro = (empleado.nivel == 2 || empleado.nivel == 3) ? empleado.sueldoBase * SEGURO : 0.00;

    float bono = 0.00;
    switch (empleado.nivel)
    {
    case 0:
        bono = bonoFijoNivel0;
        break;
    case 1:
        bono = empleado.sueldoBase * 0.064;
        break;
    case 2:
        bono = empleado.sueldoBase * 0.1394;
        break;
    case 3:
        bono = empleado.sueldoBase * 0.2104;
        break;
    default:
        std::cerr << "Nivel no válido\n";
        return -1; // Código de error
    }

    float sueldoNeto = empleado.sueldoBase - descuentoLey - descuentoSeguro + bono;
    return sueldoNeto;
}

int main()
{
    Empleado empleado1 = {0, 300098.0};
    float bonoFijoNivel0 = 11328.23;

    float sueldoNeto = calcularSueldoNeto(empleado1, bonoFijoNivel0);
    cout << "El sueldo neto del empleado es: " << sueldoNeto << endl;

    return 0;
}
