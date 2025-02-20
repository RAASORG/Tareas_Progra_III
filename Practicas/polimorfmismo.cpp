#include <iostream>
#include <string>

using namespace std;

class Persona 
{
	protected:
		string nombre;
		string apellido;
		string tipo;

	public:

		Persona(string xnombre, string xapellido, string xtipo) : nombre(xnombre), apellido(xapellido), tipo(xtipo) {}

		void setNombre(string xnomrbe) {nombre = xnomrbe;}
		void setApellido(string xapellido) {apellido = xapellido;}
		void setTipoPersona(string xtipo) {tipo = xtipo;}

		string getNombre() {return nombre;}
		string getApellido() {return apellido;}
		string getTipo() {return  tipo;}
};

class Empleado : public Persona 
{
	
    private:
		string cargo;
		string salario;

	public:

		Empleado (string xnombre, string xapellido, string xtipo, string xcargo, string xsalario) : Persona(xnombre, xapellido, xtipo), cargo(xcargo), salario(xsalario) {}

		void setCargo(string xcargo) {cargo = xcargo;}
		void setSalario(string xsalario) {salario = xsalario;}

		string getCargo() {return cargo;}
		string getSalario() {return salario;}
};

int main() 
{
	string xnombre;
	string xapellido;
	string xtipo;

	cout<<"Ingrese el nombre de la persona: ";
	cin>>xnombre;
    cout<<"Ingrese el apellido de la persona: ";
    cin>>xapellido;
    cout<<"Ingrese el tipo de persona: ";
    cin>>xtipo;

	Persona persona(xnombre,xapellido,xtipo);

    cout<<"Nombre: "<<persona.getNombre()<<endl;
    cout<<"Apellido: "<<persona.getApellido()<<endl;
    cout<<"Tipo: "<<persona.getTipo()<<endl;
    cin.ignore();
    cin.get();
	return 0;
}
