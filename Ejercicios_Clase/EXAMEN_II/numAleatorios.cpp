#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <unordered_map>
#include <limits>

using namespace std;

int main() 
{
    
    ofstream archivo("numeros.txt");

    if (!archivo) 
    {
        cerr << "No se pudo abrir el archivo para escribir." << endl;
        return 1;
    }

    srand(time(0)); 

    vector<int> numeros;

    for (int i = 0; i < 100; i++) 
    {
        int num = rand() % 1000 + 1;
        numeros.push_back(num);
        archivo << num << endl; 
    }

    archivo.close();

    ifstream archivo1("numeros.txt");

    if (!archivo1) 
    {
        cerr << "No se pudo abrir el archivo para leer." << endl;
        return 1;
    }

    unordered_map<int, int> frecuencia;
    int numero;
    int mayor = numeric_limits<int>::min();
    int menor = numeric_limits<int>::max();

    while (archivo1 >> numero) 
    {
        frecuencia[numero]++;

        if (numero > mayor) mayor = numero;
        if (numero < menor) menor = numero;
    }

    int maxFrecuencia = 0;
    int numeroMasRepetido = -1;

    for (const auto& par : frecuencia) 
    {
        if (par.second > maxFrecuencia) 
        {
            maxFrecuencia = par.second;
            numeroMasRepetido = par.first;
        }
    }

    cout << "Numero mas repetido: " << numeroMasRepetido << " (repetido " << maxFrecuencia << " veces)" << endl;
    cout << "El mayor numero es: " << mayor << endl;
    cout << "El menor numero es: " << menor << endl;
    system("pause");

    archivo1.close();

    return 0;
}
