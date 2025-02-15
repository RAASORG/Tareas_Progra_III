#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Dias_Semana 
{
    private:
    vector<string> dias;

    public:
    Dias_Semana() 
    {
        dias = { "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado","Domingo"};
    }

    void Mostrar() 
    {
        for (const auto& dia : dias)
        {
            cout << dia << endl;
        }
    }

    int Posicion(string dia) 
    {
        for (int i = 0; i < dias.size(); i++) 
        {
            if (dias[i] == dia) 
            {
                return i + 1;
            }
        }
        return -1; // Si no encuentra el día
    }
};

int main()
{
    Dias_Semana semana;
    semana.Mostrar();

    string dia;

    cout << "Ingrese el dia que desea saber sun posicion : "<<endl;
    cin >> dia;

    int posicion = semana.Posicion(dia);

    if (posicion != -1) 
    {
        cout << "La posición del dia  " << dia << " es : " << posicion << endl;
    } 

    else 
    {
        cout << "Ingreso Incorrecto" << endl;
    }

    return 0;
}