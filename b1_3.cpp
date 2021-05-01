#include<iostream>
#include<climits> // Lo importamos para INT_MAX
#include<checkers.h> // Contiene la funcion check para el control del input
using namespace std;

// Linea de compilacion: 
// g++ -I./ -o b1_3.exe b1_3.cpp checkers.cpp

// Aclaraciones compilacion:
// - El archivo checkers.cpp debe estar en el mismo directorio que el presente
//   fichero (b1_3.cpp).
// - El ejecutable se encontrará en el mismo directorio que el presente fichero
//   y se guardará como "b1_3.exe". Se podrá ejecutar con el siguiente comando:
// ./b1_3.exe

int main(){

    int ot; // Operation Type
    double a, b, ot_ab;
    bool off = false;

    while (!off)
    {

        cout <<
            "Operación a realizar\n1: Suma\n" <<
            "2: Resta\n3: Multiplicación\n4: División\n5: Salir" <<
            endl;
        cin >> ot;

        check(ot); // > Comprobamos que el input sea del tipo correcto (int),
                   //   de no ser así, lo pedimos de nuevo.

        switch (ot)
        {
            case (1):
                cout << "Sumando 1: " << endl;
                cin >> a;
                check(a);
                cout << "Sumando 2: " << endl;
                cin >> b;
                check(b);
                ot_ab = a+b;
                cout << "Resultado de la suma: "<< ot_ab << endl;
                break;

            case (2):
                cout << "Minuendo: " << endl;
                cin >> a;
                check(a);
                cout << "Sustraendo: " << endl;
                cin >> b;
                check(b);
                ot_ab = a-b;
                cout << "Resultado de la resta: "<< ot_ab << endl;
                break;

            case (3):
                cout << "Factor 1: " << endl;
                cin >> a;
                check(a);
                cout << "Factor 2: " << endl;
                cin >> b;
                check(b);
                ot_ab = a*b;
                cout << "Resultado del producto: "<< ot_ab << endl;
                break;

            case (4):
                cout << "Dividendo: " << endl;
                cin >> a;
                check(a);
                cout << "Divisor: " << endl;
                cin >> b;
                check(b);
                ot_ab = a/b;
                cout << "Resultado de la división: "<< ot_ab << endl;
                break;

            case (5):
                cout << "Programa finalizado con éxito" << endl;
                return 0; // Finalizamos main() y así, el programa

            default:
                cout << "La operación introducida (" << ot <<
                    ") no se encuentra entre las disponibles" <<
                    endl;
                cout << "Por favor, introduzca una operación válida" << endl;
                break;
        }

        cout << "----------------------------" << endl;
    }
}