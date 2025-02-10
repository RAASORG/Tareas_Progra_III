#include <iostream>
#include <string>

using namespace std;

// Clase base
class Vehiculo {
protected:
    string marca;
    int modelo;
public:
    Vehiculo(string m, int mod) : marca(m), modelo(mod) {}

    virtual void mostrarInfo() {
        cout << "Marca: " << marca << ", Modelo: " << modelo << endl;
    }
};

// Clase derivada Taxi
class Taxi : public Vehiculo {
private:
    string licencia;
public:
    Taxi(string m, int mod, string lic) : Vehiculo(m, mod), licencia(lic) {}

    void mostrarInfo() override {
        cout << "Taxi - Marca: " << marca << ", Modelo: " << modelo << ", Licencia: " << licencia << endl;
    }
};

// Clase derivada Autobus
class Autobus : public Vehiculo {
private:
    int capacidad;
public:
    Autobus(string m, int mod, int cap) : Vehiculo(m, mod), capacidad(cap) {}

    void mostrarInfo() override {
        cout << "Autobus - Marca: " << marca << ", Modelo: " << modelo << ", Capacidad: " << capacidad << " pasajeros" << endl;
    }
};

// Función principal
int main() {
    Vehiculo* vehiculo = new Vehiculo("Toyota", 2022);
    Taxi* taxi = new Taxi("Nissan", 2020, "TX12345");
    Autobus* autobus = new Autobus("Mercedes", 2019, 50);

    vehiculo->mostrarInfo();
    taxi->mostrarInfo();
    autobus->mostrarInfo();

    // Liberar memoria
    delete vehiculo;
    delete taxi;
    delete autobus;

    return 0;  
}