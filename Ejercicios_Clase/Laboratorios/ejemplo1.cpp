#include <iostream>
#include <fstream>
#include <string>
#include <boost/multiprecision/cpp_dec_float.hpp>

using namespace std;
using namespace boost::multiprecision;

int main()
{
    //Procesos con archivos

    //1. abrir archivo

    string nombreArchivo;

    cout << "Introduzca el nombre del archivo a crear: ";
    cin>>nombreArchivo;

    ofstream archivo( nombreArchivo.data(), ios::out | ios::app);

    if (!archivo)
    {
        cout << "No se pudo abrir el archivo.";
        system("pause");
        return -1;
    } // verificacion del archivo

    //2. Guradar información
    int idCliente=0;
    char  nombre[20], apellido[20];
    cpp_dec_float_50 ingreso;

    cout << "Introduzca el id del cliente: (0 para terminar)";
    cin >> idCliente;

    while (idCliente > 0)
    {
        cout << "Introduzca el nombre del cliente: ";
        cin >> nombre;
        cout << "Introduzca el apellido del cliente: ";
        cin >> apellido;
        cout << "Introduzca el ingreso del cliente: ";
        cin >> ingreso;

        //Guardar datos en el archivo
        archivo << idCliente << " " << nombre << " " << apellido << " " << ingreso << endl;

        cout << "Introduzca el id del cliente: (0 para terminar)";
        cin >> idCliente;
    }
    
    archivo.close();

    cout << "Datos guardados en el archivo." << endl;
    system("pause");

    return 0;
}
