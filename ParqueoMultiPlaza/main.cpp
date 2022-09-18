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
	int numeroCampos, numeroDeCamposEnManteniemiento, numeroDelCampo; //el numeroDelCampo es la posicion del campo en el arreglo de campos
	string nombreParqueo, telefonoParqueo;
	Parqueo* parqueo;
	//Para escoger una opcion del menu
	int opcionMenu;

	cout << "Ingrese el nombre del parqueo: ";
	getline(cin, nombreParqueo);
	cout << "Ingrese el telefono del parqueo: ";
	getline(cin, telefonoParqueo);
	cout << "Ingrese el numero de campos del parqueo: ";
	cin >> numeroCampos;
	cout << "Cuantos campos estaran en mantenimiento: ";
	cin >> numeroDeCamposEnManteniemiento;
	parqueo = new Parqueo(nombreParqueo, telefonoParqueo, numeroCampos);
	//se establecen los campos en mantenimiento`
	for (int i = 0; i < numeroDeCamposEnManteniemiento; i++) {
		system("cls");
		//se muestran los campos libres (unicamente los libres, no los ocupados, porque los ocupados no se pueden poner en mantenimiento)
		cout << parqueo->mostrarCamposDisponibles();
		cout << "Ingrese el numero del campo en mantenimiento: ";
		cin >> numeroDelCampo;
		cout << "Numero del campo " << numeroDelCampo << endl;
		parqueo->setEstadoDeUnCampo(numeroDelCampo, 'M');
	}

	system("cls");

	cout << parqueo->mostrarCamposDisponibles();

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

	//objetos de prueba

	// InfoDelCampo* campo1 = new InfoDelCampo(10, 'L');
	// InfoDelCampo* campo2 = new InfoDelCampo(10, 'L');
	// InfoDelCampo* campo3 = new InfoDelCampo(10, 'O');
	// InfoDelCampo* campo4 = new InfoDelCampo(10, 'M');

	// Parqueo* parqueo2 = new Parqueo("Parqueo 2", "1234567", 10, 4);

	// parqueo2->ingresarCampo(campo1);
	// parqueo2->ingresarCampo(campo2);
	// parqueo2->ingresarCampo(campo3);
	// parqueo2->ingresarCampo(campo4);
	

	// cout << endl << endl << "Parqueo 2" << endl << endl;
	// cout << parqueo2->mostrarCamposDisponibles();

	system("pause");
	return 0;
}