//fibonacci recursivo y manual

#include <iostream>
#include <string>

using namespace std;

long fibonacciRecursivo(int n);
long fibonacciManual(long posicion, int imprimir);

int main()
{
    int posicion;

    cout << "Introduzca la posicion del numero de fibonacci: ";
    cin >> posicion;
    cout << endl;
    cout << "Fibonacci recursivo: " << fibonacciRecursivo(posicion) << endl;
    cout << "Fibonacci manual: " << endl;
    fibonacciManual(posicion, 1);


    return 0;
}

long fibonacciRecursivo(int posicion)
{
    if (posicion < 0) return 0;
    else if (posicion > 1) return fibonacciRecursivo(posicion - 1) + fibonacciRecursivo(posicion - 2);
    return 1;
}

long fibonacciManual(long posicion, int imprimir)
{
    long siguiente = 1, actual = 0, temp;
    for (long  x = 0; x <= posicion; x++)
    {
        if (imprimir) printf("%ld ", actual);
        temp = actual;
        actual = siguiente;
        siguiente = temp + siguiente;
    }
    if (imprimir) printf("%ld\n", actual);
    return actual;
}