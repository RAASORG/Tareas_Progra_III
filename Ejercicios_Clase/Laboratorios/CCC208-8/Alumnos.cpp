#include<iostream>
#include<list>

using namespace std;

class Alumno
{
    private:
        string nombre, apellido;

    public:
        Alumno(string xnombre, string xapellido)
        {
            nombre = xnombre;
            apellido = xapellido;
        };

        friend ostream &operator<<(ostream &os, const Alumno &alumno)
        {
            os << alumno.nombre << " " << alumno.apellido;
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

list<Alumno> alumnos;

void agregar()
{
    system("cls");
    string xnombre, xapellido;

    cout<<"Escriba los datos del alumno"<<endl;
    cout<<"Escriba el nombre: "<<endl;
    cin>>xnombre;
    cout<<"Escriba el apellido: "<<endl;
    cin>>xapellido;
    Alumno objalumno(xnombre, xapellido);
    alumnos.push_back(objalumno);
    system("cls");
}

void mostrar()
{
    int contador = 0;
    system("cls");
    list<Alumno>::iterator p;

    p = alumnos.begin();

    if(alumnos.empty())
    {
        cout<<"La lista esta vacia"<<endl;
    }
    else
    {
        cout<<"La lista tiene "<<alumnos.size() << " alumnos" <<endl;
    }

    cout<<"=================================================================================="<<endl;
    while(p != alumnos.end())
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
    alumnos.clear();
}

void eliminar()
{
    int posicion;
    cout<<"Seleccione el numero del alumno que desea eliminar"<<endl;
    cin>>posicion;
    list<Alumno>::iterator p;
    p = alumnos.begin();
    int contador = 0;
    while (p != alumnos.end())
    {
        if(contador == posicion)
        {
            cout<<*p<<" ha sido eliminado"<<endl;
            alumnos.erase(p);
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
    cout<<"1. Agregar alumno"<<endl;
    cout<<"2. Eliminar alumno"<<endl;
    cout<<"3. Actualizar alumno"<<endl;
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
