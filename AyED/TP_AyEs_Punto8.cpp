/*Desarrolle una funcion Primos, que genere en pantalla al listado de numeros primos ubicados
entre 1 hasta un numero X (recibido como parametro).*/
#include <iostream>
using namespace std;
int main(void){
    int N; //Declaro variable

    cout << "Ingrese un numero entero positivo: " <<endl;
    cin >> N;

    for(int k=2; k<N; k++){ //se mide a partir de 2 ya que 1 ya es primo, revisa todos los menores a la variable asignada

        int creciente = 2;
        bool esPrimo = true; 

        while(esPrimo && creciente < k){

            if(k % creciente == 0){ //verificando si la division es exacta
             esPrimo = false;
             }
             else{
             creciente++;
             }
        }

        if(esPrimo)
            cout << k << " es un numero primo." <<endl; 
    }
}