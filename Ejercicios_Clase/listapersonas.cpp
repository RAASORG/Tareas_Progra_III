#include<iostream>
#include<list>

using namespace std;

class Persona
{
    private:
        string nombre, apellido;

    public:
        Persona(string xnombre, string xapellido)
        {
            nombre = xnombre;
            apellido = xapellido;
        };

        friend ostream &operator<<(ostream &os, const Persona &persona)
        {
            os << persona.nombre << " " << persona.apellido;
            return os;
        }
        
        string getNombre()
        {
            return nombre;
        }

        void setNombre(string xnombre)
        {
            nombre = xnombre;
        }

        string getApellido()
        {
            return apellido;
        }
        void setApellido(string xapellido)
        {
            apellido = xapellido;
        }
};

list<Persona> personas;

void agregar()
{
    system("cls");
    string xnombre, xapellido;

    cout<<"Escriba los datos de la persona"<<endl;
    cout<<"Escriba el nombre: "<<endl;
    cin>>xnombre;
    cout<<"Escriba el apellido: "<<endl;
    cin>>xapellido;
    Persona objpersona(xnombre, xapellido);
    personas.push_back(objpersona);
    system("cls");
}

void mostrar()
{
    int contador = 0;
    system("cls");
    list<Persona>::iterator p;

    p = personas.begin();

    if(personas.empty())
    {
        cout<<"La lista esta vacia"<<endl;
    }
    else
    {
        cout<<"La lista tiene "<<personas.size() << " personas" <<endl;
    }

    cout<<"=================================================================================="<<endl;
    while(p != personas.end())
    {
        cout<<contador<<" "<<*p<<endl;
        p++;
        contador++;
    }
    cout<<"=================================================================================="<<endl;

}
void limpiar()
{
    system("cls");
    personas.clear();
}

void eliminar()
{
    int posicion;
    cout<<"Seleccione el numero de la persona que desea eliminar"<<endl;
    cin>>posicion;
    list<Persona>::iterator p;
    p = personas.begin();
    int contador = 0;
    while (p != personas.end())
    {
        if(contador == posicion)
        {
            personas.erase(p);
            cout<<*p<<" ha sido eliminado"<<endl;
            break;
        }
        p++;
        contador++;
    }
    system("cls");
}

void menu()
{
    int opcion;

    cout<<"Seleccione una opcion"<<endl;
    cout<<"1. Agregar persona"<<endl;
    cout<<"2. Eliminar persona"<<endl;
    cout<<"3. Actualizar persona"<<endl;
    cout<<"4. Mostrar Lista"<<endl;
    cout<<"5. Vaciar lista"<<endl;
    cout<<"6. Salir"<<endl;
    
    cin>>opcion;

    switch (opcion)
    {
        case 1:
            agregar();
            menu();
            break;
        case 2:
            eliminar();
            menu();
            break;
        case 3:
            mostrar();
            menu();
            break;
        case 4:
            mostrar();
            menu();
            break;
        case 5:
            limpiar();
            menu();
            break;
        case 6:
        system("exit");
            break;
    }
}

int main()
{
    menu();
    return 0;
}
