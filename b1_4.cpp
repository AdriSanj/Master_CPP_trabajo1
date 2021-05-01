#include<iostream>
#include<fstream> // Necesaria para la lectura desde archivo
using namespace std;

// Linea de compilacion: 
// g++ -o b1_4.exe b1_4.cpp

// Aclaraciones compilacion:
// - El archivo vector.txt debe estar en el mismo directorio que el presente
//   fichero (b1_4.cpp) 
// - El ejecutable se encontrará en el mismo directorio que el presente fichero
//   y se guardará como "b1_4.exe". Se podrá ejecutar con el siguiente comando:
// ./b1_4.exe

double ProductoEscalar(double u[], double v[], int n)
{
    // Funcion que calcula el producto escalar de u y v (ambos de dimension n) y
    // lo devuelve como un double.
                                                         
    double sum=0;
    for(int i=0;i<n;i++)
    {
        sum += u[i]*v[i];
    }
    return sum;
}

int main()
{
    ifstream fich_in;   // > Declaramos una variable del tipo ifstream para leer
                        // desde fichero.
    int n;              // > Tamaño de los vectores
    double *u;          // > Punteros desde los que manejaremos los vectores
    double *v;
    double pe;          // > Resultado del producto escalar
    
    fich_in.open("vector.txt");     // > Abrimos el fichero y leemos la longitud
    fich_in>>n;                     // de los vectores
    u = new double[n];              // > Reservamos la memoria necesaria una vez
    v = new double[n];              // conocemos su tamaño

    for(int i=0;i<n;i++)            // > Leemos el primer vector
    {
        fich_in>>u[i];
    }

    for(int i=0;i<n;i++)            // > Leemos el segundo vector
    {
        fich_in>>v[i];
    }

    // > Mostramos por pantalla con un formato entendible los vectores que se
    // han introducido desde el fichero para verificar que la lectura es 
    // correcta (se puede eliminar si no se quiere, hasta la linea 74 incluida)
    
    cout<<"Producto escalar de dos vectores:"<<endl;
    cout<<endl;
    cout<<"Vector 1:"<<endl;
    cout<<"[";
    for (int i=0;i<n;i++)
    {
        if(i == n-1)
        {
            cout<<u[i]<<"]"<<endl;
        }
        else{
            cout<<u[i]<<", ";
        }
    }
    cout<<endl;

    cout<<"Vector 2:"<<endl;
    cout<<"[";
    for (int i=0;i<n;i++)
    {
        if(i == n-1)
        {
            cout<<v[i]<<"]"<<endl;
        }
        else{
            cout<<v[i]<<", ";
        }
    }
    cout<<endl;
    
    pe = ProductoEscalar(u,v,n);    // > Devolvemos a la variable pe el producto
                                    // escalar de los vectores introducidos a
                                    // traves de la funcion definida
                                    // anteriormente

    cout<<"El producto escalar de los dos vectores es: "<<pe<<endl;

    // > Liberamos la memoria empleada y cerramos el fichero de datos

    delete[] u;
    delete[] v;
    fich_in.close();
}