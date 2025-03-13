//Escriba un programa en el que el usuario ingrese un numero de varias cifras y el programa muestre el numero invertido usando recursividad.

#include <iostream>
#include <string>

using namespace std;

void invertir(int n);

int main()
{
    int numero;

    cout << "Introduzca un numero: ";
    cin >> numero;

    cout << "El numero invertido es: ";
    invertir(numero);
    cout << endl;
    system("pause");

    return 0;
}

void invertir(int n)
{
    if (n < 10) 
    {
        cout << n;
    }
    else
    {
        cout << n % 10;
        return invertir(n / 10);
    }
}
