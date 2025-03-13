//Escriba un programa en el que el usuario ingrese un numero de varias cifras y el programa muestre el numero invertido usando recursividad.

#include <iostream>
#include <string>

using namespace std;

void invertirNumero(long numero);

int main()
{
    long numero;

    cout << "Introduzca un numero: ";
    cin >> numero;

    cout << "El numero invertido es: ";
    invertirNumero(numero);
    cout << endl;
    system("pause");

    return 0;
}

void invertirNumero(long numero)
{
    if (numero < 10)
    {
        cout << numero;
    }
    else
    {
        cout << numero % 10;
        invertirNumero(numero / 10);
    }
}