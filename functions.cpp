#include<iostream>
#include <cmath>
#include "functions.h"


//la funcion cuya raiz queremos calcular
double Function(double x){
    double F=exp(-x*x)-x;
    return F;
}

//su derivada
double derivada(double x){
    double F1=-2*x*exp(-x*x)-1;
    return F1;
}