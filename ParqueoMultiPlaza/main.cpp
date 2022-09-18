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
	int opcionMenu;

	cout << "Ingrese el nombre del parqueo: ";
	getline(cin, nombre);
	cout << "Ingrese el telefono del parqueo: ";
	getline(cin, telefono);
	cout << "Ingrese el numero de campos del parqueo: ";
	cin >> numeroCampos;

	parqueo = new Parqueo(nombre, telefono, numeroCampos);

	do {
		cout << menu();
		cin >> opcionMenu;
		//por si alguien ingresa un caracter no valido
        if (!cin.good()) {
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');
        }
		system("cls");
		switch (opcionMenu) {
			
		}
	} while (opcionMenu != 19);

	return 0;
}