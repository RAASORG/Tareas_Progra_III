#include <iostream>
#include <string>

using namespace std;

class Semana {
public:
    virtual void mostrarDias() = 0;
    virtual int obtenerPosicion(const string& dia) = 0;
};

class DiasSemana : public Semana {
private:
    string dias[7] = {"Domingo", "Lunes", "Martes", "Miércoles", "Jueves", "Viernes", "Sábado"};

public:
    void mostrarDias() override {
        for (int i = 0; i < 7; ++i) {
            cout << dias[i] << endl;
        }
    }

    int obtenerPosicion(const string& dia) override {
        for (int i = 0; i < 7; ++i) {
            if (dias[i] == dia) {
                return i + 1;
            }
        }
        return -1; // Retorna -1 si el día no se encuentra en la lista
    }
};

int main() {
    DiasSemana semana;
    semana.mostrarDias();

    string dia;
    cout << "Ingrese el día para obtener su posición: ";
    cin >> dia;

    int posicion = semana.obtenerPosicion(dia);
    if (posicion != -1) {
        cout << "La posición de " << dia << " es: " << posicion << endl;
    } else {
        cout << "Día no encontrado." << endl;
    }

    return 0;
}