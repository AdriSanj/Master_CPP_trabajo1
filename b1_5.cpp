#include<iostream>
#include <cmath>
#include "checkers.h"     //aqui estan las funciones check para comprobar lo que se introduzca por pantalla
#include "functions.h"    //aqui estan la funcion de la que se quiera calcular las raices y su derivada
using namespace std;

// linea de compilacion:
// g++ -o b1_5.exe b1_5.cpp functions.cpp checkers.cpp

//vamos a implementar dicotomia como una funcion que devuelve el valor de la raiz
//los argumentos de entrada son los limites del intervalo y el error para el test de parada
double dicotomia(double a,double b,double epsi){

    //calculamos la funcion en los extremos
    double fa=Function(a);
    double fb=Function(b);

    // calculamos el punto medio del intervalo
    double c=(a+b)/2;
    // y el valor de la funcion en el punto medio
    double fc=Function(c);

    // usamos la formula de teoria para saber el numero de iteracciones para ese delta
    // como sale un doble del calculo, con ceil redondeamos hacia arriba y luego lo truncamos a un int
    int k=(int)ceil(((log((b-a)/epsi))/log(2))-1);

	//comenzamos el bucle desde 0 hasta k-1 incluido (k iteracciones)
    for (int i=0;i<k;i++){
        
        //en caso de que la raiz este en el subintervalo de la izquierda
        if (fa*fc<0){
            b=c;              // el extremo derecho pasa al centro
            fb=fc;            // se cambian tambien los valores de la funcion para no reevaluar los puntos
            c=(a+b)/2;        // se recalcula el nuevo centro
            fc=Function(c);   // y se evalua
        }    

        // en caso de que la raiz este en el subintervalo de la derecha
        else if (fc*fb<0){
            a=c;              // el extremo izquierdo pasa al centro, y hacemos analogo a antes
            fa=fc;
            c=(a+b)/2;
            fc=Function(c);
        }
        // el test de parada:
        else if (abs(fc)<epsi){
            cout<<"c= "<<c<<" es la raiz de la funcion: "<<endl;
            break;
        }
        // un default por si el intervalo introducido no es adecuado
        else {
            cout<<"no se cumple Bolzano en este intervalo"<<endl;
            break;
        }
    }  
    // hacemos que la funcion devuelva la raiz
    return c;
}

// ahora implementamos newton, lo hacemos sin intervalo ni comprobacion de convergencia
// devuelve true si ha converido y false si no
// los argumentos de entrada son el error delta, el epsilon, el num max de iteracciones
// la x es la semilla y entra por referencia, se va a machacar hasta que converga
bool newton(double &x,double epsi,double delta,int N){

    // definimos una xnew en cada paso para comparar con el anterior
    double xn;

    // hacemos el bucle
    for (int i=0;i<N;i++){

        // el algortimo del metodo
        xn=x-Function(x)/derivada(x);

        //test de parada epsilon:
        if (abs(Function(xn))<delta && abs(xn-x)>=epsi){
            return true;          // valor booleano que devuelve la funcion
        }
        x=xn;  //para el siguiente paso machacamos la x
    }  
    return false;  //devuelve false si no ha convergido
}

//el ppal: pide que se elija un metodo y luego pide lo que cada metodo necesita
// en el metodo llama a la funcion
int main(){

    // se declara la variable para decidir el metodo
    int decision;
    cout<<"dicotomia: 1  ,  newton: 2"<<endl;
    cin>>decision;

    if (decision==1){
        
        //estamos en dicotomia

        //se declaran las variables de entrada a la funcion y la c que es la que sale
        double a,b,c,epsi;

        // se piden a b y epsi por pantalla
        cout<<"Introduzca el inicio del intervalo: "<<endl;
        cin>>a;
        check(a);   // se chequean siempre
        cout<<"Introduzca el final del intervalo: "<<endl;
        cin>>b;
        check(b);
        cout<<"Introduzca el error deseado: "<<endl;
        cin>>epsi;
        check(epsi);

        //llamamos a la funcion
        c=dicotomia(a,b,epsi);

        //usamos printf para que se vean mas decimales
        printf("Valor de la raiz %10.10f \n",c);
    }
    else if (decision==2){

        // estamos en newton

        // declaramos el booleano que es la salida de la funcion
        bool conv;

        // declaramos las variables que entran en la funcion
        int N;
        double x,epsi,delta;

        // pedimos los valores por pantalla y chequeamos
        cout<<"Introduzca las iteracciones"<<endl;
        cin>>N;
        check(N);
        cout<<"Introduzca la semilla"<<endl;
        cin>>x;
        check(x);
        cout<<"Introduzca el error epsilon deseado: "<<endl;
        cin>>epsi;
        check(epsi);
        cout<<"Introduzca el error delta deseado: "<<endl;
        cin>>delta;
        check(delta);

        // llamamos a la funcion
        conv=newton(x,epsi,delta,N);  //al pasar x por referencia se va a modificar este valor (solucion)

		//en funcion del booleano rematamos el programa
        if (conv){
            cout<<"Se ha alcanzado la convergencia"<<endl;
           
            printf("Valor de la raiz %10.10f \n",x);
        }
        else {
            cout<<"no se ha alcanzado la convergencia"<<endl;
        }
    }
    //si por un casual metiesemos mal la decision el programa acaba
    else {
        cout<<"decision incorrecta"<<endl;
        exit;
    }
}