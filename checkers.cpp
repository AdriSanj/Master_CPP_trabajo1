#include <iostream>
#include <climits>  // Lo importamos para INT_MAX
#include "checkers.h"


using namespace std;

void check(int &x, int mx ){ // > Declaramos la variable x por referencia
                                //   para poder modificarla, damos el valor
                                //   5 por defecto a la variable mx
    int ac = 1;
    while (cin.fail()) // > Si el input falla (no es del tipo requerido)
        {
            ac++; // > Acumulador (ac = ac+1)
            cin.clear();          // > Inicializa el "cin"
            cin.ignore(INT_MAX,'\n'); // > Elimina lo que haya almacenado en el
                                      //   "buffer" del "cin"
            cout <<
                "Error, el elemento insertado no es del tipo requerido" <<
                endl;
            if (ac > mx) // > En caso de que haya un error de tipo {mx}
                {        //   veces seguidas, finalizamos el programa
                    cout <<
                        "Programa finalizado debido a un error en el " <<
                        "input continuado" <<
                        endl;
                    exit(0); // > Cierra el programa
                }
            cout <<
                "Por favor, inténtelo de nuevo (intento " <<
                ac << "/" << mx << "):" <<
                endl;
            cin >> x; // > Volvemos a insertar el input
        }
    
    cin.clear();
    cin.ignore(INT_MAX,'\n');
}

// -- Sobrecarga de la función check(int ...) a su uso para "doubles" ----------

void check(double &x, int mx ){
    int ac = 1;
    while (cin.fail())
        {
            ac++;
            cin.clear();
            cin.ignore(INT_MAX,'\n');
            cout <<
                "Error, el elemento insertado no es del tipo requerido" <<
                endl;
            if (ac > mx)
                {
                    cout <<
                        "Programa finalizado debido a un error en el " <<
                        "input continuado" <<
                        endl;
                    exit(10);
                }
            cout <<
                "Por favor, inténtelo de nuevo (intento " <<
                ac << "/" << mx << "):" <<
                endl;
            cin >> x;
        }
    
    cin.clear();
    cin.ignore(INT_MAX,'\n');
}