#include <iostream>
#include <deque>
#include <algorithm>
#include <list>

using namespace std;

struct Habilidad {
    string nombre;
    int nivel;
};

list<Habilidad> habilidades;

class Personaje
{
    protected:
        string nombre;
        int nivel;
        int vida;
        int velocidad;
        

    public:
        Personaje(string xnombre, int xnivel, int xvida, int xvelocidad) : nombre(xnombre), nivel(xnivel), vida(xvida), velocidad(xvelocidad) {}

        string getNombre() { return nombre; }
        int getVelocidad() { return velocidad; }

        virtual void atacar() {
            cout << "-" << nombre << " Atacando..." << endl;
        }
};

class Mago : public Personaje
{
    private:
        int magia;

    public:
        Mago(string xnombre, int xnivel, int xvida, int xvelocidad, int xmagia) : Personaje(xnombre, xnivel, xvida, xvelocidad), magia(xmagia) {}

        void atacar() override {
            cout << nombre << " lanza un hechizo poderoso!" << endl;
        }
};

class Arquero : public Personaje
{
    private:
        string tipoFlecha;

    public:
        Arquero(string xnombre, int xnivel, int xvida, int xvelocidad, string xtipoFlecha) : Personaje(xnombre, xnivel, xvida, xvelocidad), tipoFlecha(xtipoFlecha) {}

        void atacar() override {
            cout << nombre << " Lanzando Flechas hasta destruir!" << endl;
        }
};

class Guerrero : public Personaje
{
    private:
        int fuerza;

    public:
        Guerrero(string xnombre, int xnivel, int xvida, int xvelocidad, int xfuerza) : Personaje(xnombre, xnivel, xvida, xvelocidad), fuerza(xfuerza) {}

        void atacar() override {
            cout << nombre << " Destruyendo con asedio los muros!" << endl;
        }
};

deque<Personaje*> personajes;
Personaje* nuevoPersonaje = nullptr;

void registrar(int opcion)
{
    string nombre;
    int nivel, vida, velocidad;

    cout << "Ingrese los datos del personaje\n" << endl;
    cout << "Nombre: "; 
    cin >> nombre;
    cout << "Nivel: "; 
    cin >> nivel;
    cout << "Vida: "; 
    cin >> vida;
    cout << "Velocidad: "; 
    cin >> velocidad;

    

    if(opcion == 1)
    {
        int magia;
        cout << "Magia: "; cin >> magia;
        nuevoPersonaje = new Mago(nombre, nivel, vida, velocidad, magia);
    }
    else if(opcion == 2)
    {
        string tipoFlecha;
        cout << "Tipo de flecha: "; cin >> tipoFlecha;
        nuevoPersonaje = new Arquero(nombre, nivel, vida, velocidad, tipoFlecha);
    }
    else if(opcion == 3)
    {
        int fuerza;
        cout << "Fuerza: "; cin >> fuerza;
        nuevoPersonaje = new Guerrero(nombre, nivel, vida, velocidad, fuerza);
    }

    if (nuevoPersonaje)
    {
        personajes.push_back(nuevoPersonaje);
        cout << "\n" <<nuevoPersonaje->getNombre() << " ha sido registrado." << endl;
        cin.ignore();
        cin.get();
        system("cls");
    }
}

void mostrarOrdenDeAtaque()
{
    system("cls");
    sort(personajes.begin(), personajes.end(), [](Personaje* a, Personaje* b) {return a->getVelocidad() > b->getVelocidad();});
    
    cout << "\nOrden de ataque segun su velocidad:\n";
    for(auto personaje : personajes)
    {
        cout << "-" <<personaje->getNombre() << " (Velocidad: " << personaje->getVelocidad() << ")" << endl;

        personaje->atacar();  
        cin.ignore();
        cin.get();
    }
    cout << "\nPresione cualquier tecla para volver al menu...";
    system("cls");
}

int main()
{
    int opcion;
    do {
        cout << "\nSeleccione el personaje de su preferencia\n";
        cout << "1. Mago\n2. Arquero\n3. Guerrero\n4. Realizar Ataques\n5. Salir\n";

        cout << "\nOpcion: ";
        cin >> opcion;

        if (opcion >= 1 && opcion <= 3)
        {
            registrar(opcion);
        }
        else if (opcion == 4)
        {
            mostrarOrdenDeAtaque();
        }
    } while(opcion != 5);
    
    for(auto personaje : personajes)
        delete personaje;
    
    return 0;
}
