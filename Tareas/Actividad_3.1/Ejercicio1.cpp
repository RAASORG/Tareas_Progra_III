#include <iostream>
#include <string>

using namespace std;

class Vehiculo {
	protected:
    	string matricula;
    	string modelo;
    	int potenciaCV;

	public:
    	Vehiculo(string mat, string mod, int pot) : matricula(mat), modelo(mod), potenciaCV(pot) {}

    	string getMatricula() { return matricula; }
    	string getModelo() { return modelo; }
    	int getPotenciaCV() { return potenciaCV; }
	};

class Taxi : public Vehiculo {
	private:
    	int numeroLicencia;

	public:
    	Taxi(string mat, string mod, int pot, int licencia) : Vehiculo(mat, mod, pot), numeroLicencia(licencia) {}

    	void setNumeroLicencia(int licencia) { numeroLicencia = licencia; }
    	int getNumeroLicencia() { return numeroLicencia; }
	};

class Autobus : public Vehiculo {
	private:
    	int numeroPlazas;

	public:
    	Autobus(string mat, string mod, int pot, int plazas) : Vehiculo(mat, mod, pot), numeroPlazas(plazas) {}

    	void setNumeroPlazas(int plazas) { numeroPlazas = plazas; }
    	int getNumeroPlazas() { return numeroPlazas; }
	};

int main() {
    Taxi miTaxi("ABC123", "Toyota Corola", 110, 12567);
    Autobus miAutobus("XYZ789", "Mercedes Sprinter", 150, 10);

    cout << "Taxi - Matricula: " << miTaxi.getMatricula() << ", Modelo: " << miTaxi.getModelo()
         << ", Potencia: " << miTaxi.getPotenciaCV() << "CV, Licencia: " << miTaxi.getNumeroLicencia() << endl;

    cout << "Autobus - Matricula: " << miAutobus.getMatricula() << ", Modelo: " << miAutobus.getModelo()
         << ", Potencia: " << miAutobus.getPotenciaCV() << "CV, Plazas: " << miAutobus.getNumeroPlazas() << endl;

    return 0;
}