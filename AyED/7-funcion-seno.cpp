#include <iostream>
#include <cmath>
#include <limits>

// Función para calcular el factorial
double factorial(int n) {
    double result = 1.0;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Función para calcular el seno utilizando la serie de Taylor
double Seno(double angulo, char tipo) {
    // Convertir grados sexagesimales a radianes si es necesario
    if (tipo == 's') {
        angulo = angulo * M_PI / 180.0;
    }

    double seno = 0.0;
    for (int n = 0; n < 12; ++n) {
        double term = pow(-1, n) * pow(angulo, 2*n+1) / factorial(2*n+1);
        seno += term;
    }

    return seno;
}

int main() {
    while (true) {
        std::string input;
        std::cout << "Introduce el angulo o 'q' para salir: ";
        std::cin >> input;

        if (input == "q") {
            break;
        }

        try {
            double angulo = std::stod(input); // Convertir la entrada a un número

            char tipo;
            std::cout << "Introduce el tipo de angulo ('s' para grados, 'r' para radianes): ";
            std::cin >> tipo;

            if (tipo != 's' && tipo != 'r') {
                std::cout << "Tipo de angulo no valido. Intente de nuevo." << std::endl;
                continue;
            }

            double resultado = Seno(angulo, tipo);
            std::cout << "El seno de " << angulo << " es: " << resultado << std::endl;
        } catch (const std::invalid_argument&) {
            std::cout << "Entrada no valida. Intente de nuevo." << std::endl;
            continue;
        }

        // Limpiar cualquier entrada restante en el buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return 0;
}
