#include <iostream>
#include <string>

using namespace std;

long factorial(int n); // Prototipo de la función

int main()
{
    int numero;

    cout << "Introduzca un numero: ";
    cin >> numero;

    if (numero < 0)
    {
        cout << "No se puede calcular el factorial de un numero negativo." << endl;
        system("pause");
        return -1;
        
    }
    else
    {
        long resultado = factorial(numero);
        cout << "El factorial de " << numero << " es: " << resultado << endl;
        system("pause");
    }

    return 0;
}

long factorial(int n)
{
    if (n < 0) return 0;
    else if (n > 1) return n * factorial(n - 1);
    return 1;
}

int fibonacci(int n)
{
    if (n < 0) return 0;
    else if (n > 1) return fibonacci(n - 1) + fibonacci(n - 2);
    return 1;
}
