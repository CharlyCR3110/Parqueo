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
	//Para validar que este hecho
	bool hecho;

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
		cout << "Campos elegibles: " << endl;
		cout << parqueo->mostrarCamposDisponibles();
		cout << "Ingrese el numero del campo que desear poner en mantenimiento: ";
		cin >> numeroDelCampo;
		cout << "Numero del campo " << numeroDelCampo << endl;
		parqueo->setEstadoDeUnCampo(numeroDelCampo, 'M');
	}
	//to-do
	//verificar que se haya escogido un campo elegible

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
			//1 - Ver TODOS los campos del parqueo, (solo lugar, estado y placa)
			case 1:
				cout << parqueo->mostrarTodosLosCamposDelParqueo();
				break;
			//2 - Ver solo los campos que están OCUPADOS. (solo lugar, estado y placa)
			case 2:
				cout << parqueo->mostrarCamposOcupados();
				break;
			//3 - Ver solo los campos que están en MANTENIMIENTO. (solo lugar y estado)
			case 3:
				cout << parqueo->mostrarCamposEnMantenimiento();
				break;
			// 4 - Ingresar un vehículo al parqueo. Solicitar posición o lugar. 
			case 4:
				//datos del chofer
				//se pide la cedula del chofer
				cout << "Ingrese la cedula del chofer: ";
				cin >> cedula;
				//se pide el nombre del chofer
				cout << "Ingrese el nombre del chofer: ";
				cin >> nombre;
				//se crea el objeto chofer
				chofer = new Chofer(cedula, nombre);
				//datos del vehiculo
				//se pide la marca del vehiculo
				cout << "Ingrese la marca del vehiculo: ";
				cin >> marca;
				//se pide la placa del vehiculo
				cout << "Ingrese la placa del vehiculo: ";
				cin >> placa;
				//se pide el tonelaje del vehiculo
				cout << "Ingrese el tonelaje del vehiculo: ";
				cin >> tonelaje;
				//se pide el color del vehiculo
				cout << "Ingrese el color del vehiculo: ";
				cin >> color;
				//datos del cobro del vehiculo
				//datos de la hora de entrada
				cout << "A continuacion ingrese los datos para posteriormente realizar el cobro" << endl << endl;
				cout << "A continuacion se le solicitara la hora de entrada" << endl;
				cout << "Hora: ";
				cin >> hora;
				cout << "Minutos: ";
				cin >> minutos;
				cout << "Segundos: ";
				cin >> segundos;
				//se crea el objeto hora de entrada
				horaDeEntrada = new Hora(hora, minutos, segundos);
				//datos de la hora de salida
				cout << "A continuacion se le solicitara la hora de salida" << endl;
				cout << "Hora: ";
				cin >> hora;
				cout << "Minutos: ";
				cin >> minutos;
				cout << "Segundos: ";
				cin >> segundos;
				//se crea el objeto hora de salida
				horaDeSalida = new Hora(hora, minutos, segundos);
				//se crea el objeto cobro
				cobro = new Cobro(horaDeEntrada, horaDeSalida);
				//se crea el objeto vehiculo
				vehiculo = new Vehiculo(marca, placa, tonelaje, color, chofer, cobro);

				//se ingresa el vehiculo en el campo
				do {
					//mostrar los campos disponibles
					cout << parqueo->mostrarCamposDisponibles();
					//se pide el numero del campo donde se desea ingresar el vehiculo
					cout << "Ingrese el numero del campo donde desea ingresar el vehiculo: ";
					cin >> numeroDelCampo;
					//por si alguien ingresa un caracter no valido
					if (!cin.good()) {
						cin.clear();
						cin.ignore(numeric_limits<int>::max(), '\n');
					}
					//en el if () se verifica y se ingresa el vehiculo en el campo
					if (parqueo->ingresarUnVehiculoAlParqueo(numeroDelCampo, vehiculo)) {
						cout << "Vehiculo ingresado correctamente" << endl;
						hecho = true;
					} else {
						cout << "No se puede ingresar el vehiculo en ese campo" << endl;
						hecho = false;
					}
				} while (hecho == false);
				break;

		}
		system("PAUSE");
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

	return 0;
}