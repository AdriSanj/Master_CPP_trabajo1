#include <iostream>
#include <cmath>
#include "checkers.h"

using namespace std;

int main() {
	// definimos las variables del programa
	int n;	// n: numero de terminos de la suma 
	double S,F = 1,p ;	// S es el valor de la suma y le iremos anhadiendo los terminos calculados. F es la parte correspondiente al factorial y p la potencia en cada iteracion
	cout << "Introduce cuantos terminos de la suma quieres" << endl;
	cin >> n;
	check(n);		// Comprobacion del numero entero
	for (int k = 0; k < n; k++) {
		if (k == 0) {		// Solo para el primer termino de la suma tomamos
			F = 1;
			p = 1;
		}
		else {    //Para k>0 se ejecuta y calcula la nueva potencia y un valor mas al factorial
			p *= 3;
			F *= k;
		}
		S += p / (3 + F);  
	}
	printf("La suma de %i terminos de la suma es %3.15f",n,S);
}