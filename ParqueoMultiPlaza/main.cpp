#include "Parqueo.h"
#include "Menu.h"
using namespace std;

int main() {
	cout << "sexo";
	//datos del cobro
	int hora, minutos, segundos;
	Hora* horaDeEntrada;
	Hora* horaDeSalida;
	Cobro* cobro;
	//datos del chofer
	string cedula, nombre;
	Chofer* chofer;
	//datos del vehiculo
	string marca, placa, color;
	double tonelaje;
	Vehiculo* vehiculo;
	//datos del campo
	int numeroMaximoDeVehiculos;
	InfoDelCampo* campo;
	//datos del parqueo
	int numeroCampos;
	string nombre, telefono;
	Parqueo* parqueo;
	//Para escoger una opcion del menu
	int opcion;

	cout << "Ingrese el nombre del parqueo: ";
	getline(cin, nombre);
	cout << "Ingrese el telefono del parqueo: ";
	getline(cin, telefono);
	cout << "Ingrese el numero de campos del parqueo: ";
	cin >> numeroCampos;

	parqueo = new Parqueo(nombre, telefono, numeroCampos);

	return 0;
}