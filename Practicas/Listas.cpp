#include <iostream>
#include <list>

using namespace std;

class Persona
{
    private:
        string nombre, apellido, tipo;
    
    public:
        Persona(string xnombre, string xapellido, string xtipo) : nombre(xnombre), apellido(xapellido), tipo(xtipo) {}

        void setNombre (string xnombre) { nombre = xnombre; }
        void setApellido (string xapellido) { apellido = xapellido; }
        void setTipo (string xtipo) { tipo = xtipo; }

        string getNombre() { return nombre; }
        string getApellido() { return apellido; }
        string getTipo() { return tipo; }

};

list <Persona> personas;

void agregar()
{
    string xnombre, xapellido, xtipo;

    cout<<"LLENAR LISTA DE PERSONAS"<<endl;
    cout<<"Ingrese Nombre: "<<endl;
    cin>>xnombre;
    cout<<"Ingrese Apellido: "<<endl;
    cin>>xapellido;
    cout<<"Ingrese Tipo: "<<endl;
    cin>>xtipo;

    Persona personas(xnombre,xapellido,xtipo);

    cout<<"Se ha agregado la persona"<<endl;
    cout<<"Nombre: "<<personas.getNombre()<<endl;
    cout<<"Apellido: "<<personas.getApellido()<<endl;
    cout<<"Tipo: "<<personas.getTipo()<<endl;
    cin.ignore();
    cin.get();
}

void mostrar()
{
    list<Persona>::iterartor p;
    p = personas.begin();

    if(personas.empty())
    {
        cout<<"La lista esta vacia"<<endl;
    }
    else
    {
        cout<<"La lista tiene "<<personas.size()<<" personas"<<endl;
    }
}

void menu()
{
    int opcion;

    cout<<"Seleccione una opcion de la lista"<<endl<<endl;
}

int main()
{
    agregar();
    return 0;
}