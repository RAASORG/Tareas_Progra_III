#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <fstream>
#include <cstdlib>

using namespace std;

vector<string> listaFrases;

void guardarFraseEnFichero(const string& frase) 
{
    ofstream fichero("fichero.txt", ios::app);

    if (fichero) 
    {
        fichero << frase << endl;
        listaFrases.push_back(frase);
        cout << "Frase guardada exitosamente.\n";
        system("pause");
    }

    else 
    {
        cout << "No se pudo abrir el fichero para guardar la frase.\n";
    }
    fichero.close();
}

void mostrarFraseAleatoria() 
{
    if (listaFrases.empty()) 
    {
        cout << "No hay frases guardadas." << endl;
    }
    
    else 
    {
        srand(time(0));
        int indiceAleatorio = rand() % listaFrases.size();
        cout << "Frase aleatoria: " << listaFrases[indiceAleatorio] << endl;
        system("pause");
    }
}


void llenarLista()
{
    ifstream ficheroLeer("fichero.txt");
    string frase;
    while (getline(ficheroLeer, frase)) 
    {
        listaFrases.push_back(frase);
    }
    ficheroLeer.close();
}

void mostrarContenidoFichero() 
{

    ifstream ficheroLeer("fichero.txt");
    string frase;

    if (ficheroLeer) 
    {
        cout << "Contenido del fichero:\n";

        while (getline(ficheroLeer, frase)) 
        {
            cout << frase << endl;
        }

        system("pause");
        ficheroLeer.close();
    } 
    
    else 
    {
        cout << "No se pudo abrir el fichero para leer.\n";
        system("pause");
    }
}

void mostrarMenu() 
{
    llenarLista();
    int opcion;
    string frase;
    do {
        cout << "1. Ingresar una frase\n";
        cout << "2. Mostrar frase aleatoria\n";
        cout << "3. Mostrar contenido del fichero\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) 
        {
            case 1:
                cout << "Ingrese una frase: ";
                getline(cin, frase);
                guardarFraseEnFichero(frase);
                break;
            case 2:
                mostrarFraseAleatoria();
                break;
            case 3:
                mostrarContenidoFichero();
                break;
            case 4:
                return;
                break;
            default:
                cout << "Opcion no valida.\n";
                break;
        }
        system("cls");
    } while (opcion != 4);


}

int main() 
{
    mostrarMenu();
    return 0;
}
