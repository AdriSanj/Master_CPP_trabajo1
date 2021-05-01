#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
	double n=0, N = 1000000;
	double x, y;
	srand(time(NULL));
	for (int i = 0; i <= N; i++) {			// Calculamos el modulo en cada iteracion pero no lo guardamos,
		x = ((double)rand()) / RAND_MAX;	// solamente sumamos 1 a n si el modulo es menor que 1.
		y = ((double)rand()) / RAND_MAX;
		if (sqrt(x*x + y*y) <= 1) {
			n += 1;
		}
	}
	printf( "El valor aproximado de pi es %4.8f ",4*n/N);
}