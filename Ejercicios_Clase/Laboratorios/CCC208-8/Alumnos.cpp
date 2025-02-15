#include<iostream>
#include<list>
#include<algorithm>

using namespace std;

class Alumno
{
    private:
        string nombre, apellido;
        double nota;

    public:
        Alumno(string xnombre, string xapellido, double xnota)
        {
            nombre = xnombre;
            apellido = xapellido;
            nota = xnota;
        };

        friend ostream &operator<<(ostream &os, const Alumno &alumno)
        {
            os << alumno.nombre << " " << alumno.apellido << " "  << alumno.nota <<"%";
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

        double getNota() const
        {
            return nota;
        }

        void setNota(double xnota)
        {
            nota = xnota;
        }
};

list<Alumno> alumnos;

void agregar()
{
    system("cls");
    string xnombre, xapellido;
    double xnota;

    cout<<"Escriba los datos del alumno"<<endl<<endl;
    cout<<"Escriba el nombre: "<<endl;
    cin>>xnombre;
    cout<<"Escriba el apellido: "<<endl;
    cin>>xapellido;
    cout<<"Escriba la nota: "<<endl;
    cin>>xnota;
    Alumno objalumno(xnombre, xapellido, xnota);
    alumnos.push_back(objalumno);
    system("cls");
}

void actualizar()
{
    int posicion;
    cout<<"Seleccione el numero del alumno que desea actualizar"<<endl;
    cin>>posicion;
    list<Alumno>::iterator p;
    p = alumnos.begin();
    int contador = 0;
    while (p != alumnos.end())
    {
        if(contador == posicion)
        {
            
            string xnombre, xapellido;
            double xnota;

            system("cls");
            cout<<"Escriba los datos del alumno"<<endl<<endl;
            cout<<"Escriba el nombre: "<<endl;
            cin>>xnombre;
            cout<<"Escriba el apellido: "<<endl;
            cin>>xapellido;
            cout<<"Escriba la nota: "<<endl;
            cin>>xnota;
            p->setNombre(xnombre);
            p->setApellido(xapellido);
            p->setNota(xnota);
            cout<<*p<<" ha sido actualizado"<<endl;
            cin.ignore();
            cin.get();
            system("cls");
            break;
        }
        p++;
        contador++;
    }
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

void calcular() {

    list<Alumno>::iterator p = alumnos.begin();
    double promedio, nota = 0;
    
    while (p != alumnos.end()) {
        nota += p->getNota();
        p++;
    }

    promedio = nota / alumnos.size();

    auto mayor = max_element(alumnos.begin(), alumnos.end(),
        [](const Alumno& a, const Alumno& b) {
            return a.getNota() < b.getNota();
        });

    auto menor = min_element(alumnos.begin(), alumnos.end(),
        [](const Alumno& a, const Alumno& b) {
            return a.getNota() < b.getNota();
        });

    cout << "El promedio de la lista es: " << promedio << "%" << endl;
    cout << "La nota mayor es: " << mayor->getNota() << "%" << endl;
    cout << "La nota menor es: " << menor->getNota() << "%" << endl;
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
    cout<<"=================================================================================="<<endl<<endl;

}

void limpiar()
{
    system("cls");
    alumnos.clear();
}

void menu()
{
    int opcion;

    cout<<"Seleccione una opcion"<<endl<<endl;
    cout<<"1. Agregar alumno"<<endl;
    cout<<"2. Eliminar alumno"<<endl;
    cout<<"3. Actualizar alumno"<<endl;
    cout<<"4. Mostrar Lista (y promedio)"<<endl;
    cout<<"5. Vaciar lista"<<endl;
    cout<<"6. Salir"<<endl<<endl;
    
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
            actualizar();
            menu();
            break;
        case 4:
            mostrar();
            calcular();
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
