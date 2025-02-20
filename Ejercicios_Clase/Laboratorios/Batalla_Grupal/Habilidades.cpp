#include <iostream>
#include <string>
#include <list>

using namespace std;

class Habilidad {
public:
    string nombre;
    int nivel;

    Habilidad(string nombre, int nivel) : nombre(nombre), nivel(nivel) {}

    virtual void mostrar() {
        cout << "Habilidad: " << nombre << ", Nivel: " << nivel << endl;
    }
};

class ListaEnlazada {
private:
    list<Habilidad> habilidades; 

public:

    void agregarHabilidad(string nombre, int nivel) {
        habilidades.push_back(Habilidad(nombre, nivel));
    }

    void eliminarHabilidad(string nombre) {
        for (auto it = habilidades.begin(); it != habilidades.end(); ++it) {
            if (it->nombre == nombre) {
                habilidades.erase(it);
                return;
            }
        }
    }

    void imprimirHabilidades() {
        for (auto& habilidad : habilidades) {
            habilidad.mostrar();
        }
    }
};

int main() {
    ListaEnlazada lista;

    lista.agregarHabilidad("Fuerza", 1);
    lista.agregarHabilidad("Velocidad", 2);
    lista.agregarHabilidad("Inteligencia", 3);


    cout << "Lista de habilidades:" << endl;
    lista.imprimirHabilidades();

    lista.eliminarHabilidad("Velocidad");

    cout << "\nLista de habilidades después de eliminar 'Velocidad':" << endl;
    lista.imprimirHabilidades();
    cin.ignore();
    cin.get();

    return 0;
}
