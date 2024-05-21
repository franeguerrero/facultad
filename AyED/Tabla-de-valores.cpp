#include <iostream>
#include <iomanip> // Utilizado para formatear la impresión -> setw
#include <sstream> // Utilizado para crear cadenas de texto a partir de "fragmentos" -> ostringstream

using namespace std;

// Función auxiliar para multiplicar usando solo sumas
int multiplicar(int a, int b)
{
    int resultado = 0;
    for (int i = 0; i < b; ++i)
    {
        resultado += a;
    }
    return resultado;
}

// Función para elevar un número a una potencia usando solo sumas
int elevar(int base, int exponente)
{
    if (exponente == 0)
        return 1;
    int resultado = base;
    for (int i = 1; i < exponente; ++i)
    {
        resultado = multiplicar(resultado, base);
    }
    return resultado;
}

// Función que genera la tabla de potencias y la devuelve como una cadena
string generarTabla(int N, int maxBase)
{
    if (N < 1 || N > 4)
    {
        return "ERROR, imposible generar tabla de potencia requerida";
    }

    ostringstream tabla;
    tabla << "\n"
          << "Tabla de potencias para N = " << N << "\n\n";
    tabla << "Base | Potencia\n";
    tabla << "-------------\n";
    for (int i = 1; i <= maxBase; ++i)
    {
        int resultado = elevar(i, N);
        tabla << setw(4) << i << " | " << resultado << "\n";
    }
    return tabla.str();
}

int main()
{
    int N, maxBase;
    cout << "Ingrese el valor de N (entre 1 y 4): ";
    cin >> N;
    cout << "Ingrese el valor maximo de la base: ";
    cin >> maxBase;

    cout << generarTabla(N, maxBase) << endl;

    return 0;
}
