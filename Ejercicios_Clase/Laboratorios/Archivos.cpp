#include <iostream>
#include <fstream>

using namespace std;

string nombre, nombreAuxiliar, semestre, edad;
int clave=0, claveAuxiliar=0;
char grupo[10];
char opca;
bool encontrado = false;

void altas()
{
    ofstream escritura;
    ifstream consulta;

    do
    {
        escritura.open("alumnos.txt", ios::out | ios::app); //crea y escribe si ya tiene texto, une al final del archivo
        consulta.open("alumnos.txt", ios::in); //abre el archivo para lectura

        if (escritura.is_open() && consulta.is_open())
        {
            bool repetido = false;
            cout << "Ingrese la clave del alumno: ";
            cin >> claveAuxiliar;

            //Acontinuacion se aplica el tipo de lectura de archivos secuencial

            consulta>>clave; // esto es para leer la primera clave del archivo y en caso de que no haya nada en el archivo, no se leera nada
            while (!consulta.eof())
            {
                consulta>>nombre>>semestre>>grupo>>edad;
                if (claveAuxiliar == clave)
                {
                    repetido = true;
                    break;
                }
                consulta>>clave;
            }
            if (repetido == false)
            {
                cout << "Ingrese el nombre del alumno: ";
                cin >> nombre;
                cout << "Ingrese el semestre del alumno: ";
                cin >> semestre;
                cout << "Ingrese el grupo del alumno: ";
                cin >> grupo;
                cout << "Ingrese la edad del alumno: ";
                cin >> edad;

                escritura << claveAuxiliar << " " << nombre << " " << semestre << " " << grupo << " " << edad << endl;
                cout << "Registro guardado" << endl;
            }
            else
            {
                cout << "La clave ya existe" << endl;
            }
        }

        else
        {
            cout << "Error al abrir el archivo" << endl;
        }

        escritura.close();
        consulta.close();

    } while (opca == 's' || opca == 'S');
}

void bajas()
{
    ofstream auxiliar;
    ifstream lectura;

    encontrado = false;
    auxiliar.open("auxiliar.txt", ios::out);
    lectura.open("alumnos.txt", ios::in);

    if (auxiliar.is_open() && lectura.is_open())
    {
        cout << "\n";
        cout << "\tIngresa la clave del alumno que deseas eliminar: ";
        cin>>claveAuxiliar;

        ///De nuevo se aplica el tipo de lectura de archivos secuencial, esto quiere decir que lee campo por campo
        ///hasta llegar al final del archivo gracuas a la funcion .eof()

        lectura>>clave;

        while (!lectura.eof())
        {
            lectura>>nombre>>semestre>>grupo>>edad;
            if (claveAuxiliar == clave)
            {
                encontrado = true;
                cout << "\n";
                cout << "Clave: " << clave << endl;
                cout << "Nombre: " << nombre << endl;
                cout << "Semestre: " << semestre << endl;
                cout << "Grupo: " << grupo << endl;
                cout << "Edad: " << edad << endl;
                cout << "\t__________________________________________________\n\n";
                cout << "\tRealmente deseas eliminar este registro? (s/n): ";
                cin>>opca;

                if (opca == 's' || opca == 'S')
                {
                    cout << "\n";
                    cout << "\n\n\t\tRegistro eliminado\n\n\t\t\a";
                }
                else
                {
                    auxiliar << clave << " " << nombre << " " << semestre << " " << grupo << " " << edad << endl;
                }

            }

            lectura>>clave;

        }
    }

    else
    {
        cout << "Error al abrir el archivo" << endl;
    }

    if (encontrado == false)
    {
        cout << "No se encontró ningun registro con la clave: " << claveAuxiliar << "\n\n\t\t\t";
    }

}

int main()
{
    altas();
    return 0;
}