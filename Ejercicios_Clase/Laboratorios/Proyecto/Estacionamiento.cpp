#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <fstream>
#include <cstdlib>

using namespace std;

struct Vehiculo
{
    string placa;
    string modelo;
    string tipo;
    string horaIngreso;
    Vehiculo *siguiente;
};

class Estacionamiento
{
private:
    Vehiculo *inicio;
    void registrarLog(const string &mensaje);

public:
    Estacionamiento() { inicio = nullptr; }
    ~Estacionamiento();
    void registrarVehiculo();
    void removerVehiculo();
    void mostrarVehiculos();
    void verLog();
};

void Estacionamiento::registrarLog(const string &mensaje)
{
    ofstream logFile("log.txt", ios::app);
    if (logFile)
    {
        time_t ahora = time(0);
        char *hora = ctime(&ahora);
        logFile << hora << " - " << mensaje << endl;
    }
    logFile.close();
}

Estacionamiento::~Estacionamiento()
{
    Vehiculo *temp;
    while (inicio)
    {
        temp = inicio;
        inicio = inicio->siguiente;
        delete temp;
    }
}

void Estacionamiento::registrarVehiculo()
{
    system("clear || cls");
    cout << "\n--- REGISTRO DE VEHICULO ---\n";
    cout << "Al registrar un vehiculo, se guardara la hora actual como hora de ingreso .\n\n";
    string placa, modelo, tipo;
    cout << "Ingrese placa: ";
    getline(cin, placa);
    cout << "Ingrese modelo: ";
    getline(cin, modelo);
    cout << "Ingrese tipo de vehiculo (moto, carro, camion, etc.): ";
    getline(cin, tipo);
    
    time_t ahora = time(0);
    string horaIngreso = ctime(&ahora);
    Vehiculo *nuevo = new Vehiculo{placa, modelo, tipo, horaIngreso, inicio};
    inicio = nuevo;
    registrarLog("Vehiculo registrado - Placa: " + placa + ", Modelo: " + modelo + ", Tipo: " + tipo);
}

void Estacionamiento::removerVehiculo()
{
    system("clear || cls");
    string placa;
    cout << "\n---  VEHICULO QUE SALE DEL ESTACIONAMIENTO---\n";
    cout << "Ingrese placa del vehiculo a eliminar: ";
    getline(cin, placa);
    
    Vehiculo *actual = inicio, *anterior = nullptr;
    while (actual && actual->placa != placa)
    {
        anterior = actual;
        actual = actual->siguiente;
    }
    if (!actual)
        return;
    if (!anterior)
        inicio = actual->siguiente;
    else
        anterior->siguiente = actual->siguiente;
    registrarLog("Vehiculo eliminado - Placa: " + actual->placa + ", Modelo: " + actual->modelo + ", Tipo: " + actual->tipo + ", Hora de ingreso: " + actual->horaIngreso);
    delete actual;
}

void Estacionamiento::mostrarVehiculos()
{
    system("clear || cls");
    Vehiculo *temp = inicio;
    cout << "\nVehiculos en el estacionamiento:\n";
    while (temp)
    {
        cout << "Placa: " << temp->placa << ", Modelo: " << temp->modelo << ", Tipo: " << temp->tipo << ", Hora: " << temp->horaIngreso << endl;
        temp = temp->siguiente;
    }
    system("pause");
}

void Estacionamiento::verLog()
{
    system("clear || cls");
    ifstream logFile("log.txt");
    if (logFile)
    {
        string linea;
        cout << "\n--- LOG DEL ESTACIONAMIENTO ---\n";
        while (getline(logFile, linea))
        {
            cout << linea << endl;
        }
    }
    else
    {
        cout << "\nNo hay registros en el log.\n";
    }
    logFile.close();
    system("pause");
}

class UIConsola
{
private:
    Estacionamiento estacionamiento;
public:
    void mostrarMenu();
};

void UIConsola::mostrarMenu()
{
    int opcion;
    do
    {
        system("clear || cls");
        cout << "\n--- MENU ---\n";
        cout << "1. Registrar Vehiculo\n";
        cout << "2. Eliminar Vehiculo\n";
        cout << "3. Mostrar Vehiculos\n";
        cout << "4. Ver Log\n";
        cout << "5. Salir\n";
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion)
        {
        case 1:
            estacionamiento.registrarVehiculo();
            break;
        case 2:
            estacionamiento.removerVehiculo();
            break;
        case 3:
            estacionamiento.mostrarVehiculos();
            break;
        case 4:
            estacionamiento.verLog();
            break;
        }
    } while (opcion != 5);
}

int main()
{
    UIConsola ui;
    ui.mostrarMenu();
    return 0;
}
