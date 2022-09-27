#include "Parqueo.h"
#include "Menu.h"
#include "ValidadorDeDatos.h"
#include "PausaYContinuar.h"
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
		std::system("cls");
		//se muestran los campos libres (unicamente los libres, no los ocupados, porque los ocupados no se pueden poner en mantenimiento)
		cout << "Campos elegibles: " << endl;
		cout << parqueo->mostrarCamposLibres();
		cout << "Ingrese el numero del campo que desear poner en mantenimiento: ";
		cin >> numeroDelCampo;
		cout << "Numero del campo " << numeroDelCampo << endl;
		parqueo->setEstadoDeUnCampo(numeroDelCampo, 'M');
	}
	//to-do
	//verificar que se haya escogido un campo elegible

	std::system("cls");

	cout << parqueo->mostrarCamposLibres();

	do {
		cout << menu();
		cin >> opcionMenu;
		//por si alguien ingresa un caracter no valido
       if (!cin.good()) {
           cin.clear();
           cin.ignore(numeric_limits<int>::max(), '\n');
       }
		std::system("cls");
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
				cout << "Datps del chofer: " << endl;
				//se pide la cedula del chofer
				cout << "Ingrese la cedula del chofer: ";
				cin >> cedula;
				//se pide el nombre del chofer
				cout << "Ingrese el nombre del chofer: ";
				cin >> nombre;

				pausaYContinuar();
				//se crea el objeto chofer
				chofer = new Chofer(cedula, nombre);
				//datos del vehiculo
				cout << "Datos del vehiculo" << endl;
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

				pausaYContinuar();
				//datos de la hora de entrada
				cout << "Hora de entrada: " << endl << endl;
				cout << "Se utiliza el formato de 24 horas" << endl;
				cout << "Ejemplo: 16:30:23" << endl;
				pausaYContinuar();
				do {
					cout << "Digite la hora de entrada" << endl;
					cout << "Hora: ";
					cin >> hora;
					cout << "Minutos: ";
					cin >> minutos;
					cout << "Segundos: ";
					cin >> segundos;
					//se verifica que la hora ingresada sea valida
					if (!validarHora(hora, minutos, segundos)) {
						cout << "La hora ingresada no es valida" << endl;
						pausaYContinuar();
					}
				} while (validarHora(hora, minutos, segundos) == false);
				//se muestra la hora en formato HH:MM:SS
				cout << "Hora de entrada: " << hora << ":" << minutos << ":" << segundos << endl;
				pausaYContinuar();
				//se crea el objeto hora de entrada
				horaDeEntrada = new Hora(hora, minutos, segundos);
				//se crea el objeto cobro
				cobro = new Cobro(horaDeEntrada);
				//se crea el objeto vehiculo
				vehiculo = new Vehiculo(marca, placa, tonelaje, color, chofer, cobro);

				//se ingresa el vehiculo en el campo
				do {
					//mostrar los campos disponibles
					cout << parqueo->mostrarCamposLibres();
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
						pausaYContinuar();
						//se crea un ticket de entrada
						//opcion con una clase ticket de entrada
						// ticketDeEntrada = new TicketDeEntrada(vehiculo, numeroDelCampo);
						//se muestra el ticket de entrada
						// cout << ticketDeEntrada->toString();
						//opcion simulando un ticket a punta de couts
						cout << "Ticket de entrada" << endl;
						cout << "Campo: " << numeroDelCampo << endl;
						cout << "Datos del vehiculo: " << endl;
						cout << "Marca: " << vehiculo->getMarca() << endl;
						cout << "Placa: " << vehiculo->getPlaca() << endl;
						cout << "Datos del chofer: " << endl;
						cout << vehiculo->getChofer()->toString();
						cout << "Hora de entrada: " << hora << ":" << minutos << ":" << segundos << endl;
						hecho = true;
					} else {
						cout << "No se puede ingresar un vehiculo en ese campo" << endl;
						pausaYContinuar();
						cout << "Por favor ingrese un campo valido" << endl;
						hecho = false;
					}
				} while (hecho == false);
				break;
			// 5 - Cancelar la estancia en el lugar. Realizar el debido cobro del alquiler. 
			case 5:
				//esto es por si se hace por numero de placa y no por numero de campo
				// //se busca el vehiculo en el parqueo
				// vehiculo = parqueo->buscarVehiculo(placa);
				// //si el vehiculo no existe
				// if (vehiculo == NULL) {
				// 	cout << "El vehiculo no existe" << endl;
				// 	pausaYContinuar();
				// 	break;
				// }
				//si el vehiculo existe
				//se pide la hora de salida
				//se pide el campo donde esta  ubicado el vehiculo
				do {
					cout << "Ingrese el numero del campo donde se encuentra el vehiculo: ";
					cin >> numeroDelCampo;
					//por si alguien ingresa un caracter no valido
					if (!cin.good()) {
						cin.clear();
						cin.ignore(numeric_limits<int>::max(), '\n');
					}
					//se verifica que el campo ingresado sea valido
					if (parqueo->verificarQueElCampoExista(numeroDelCampo)) {
						if (parqueo->verificarQueEsteOcupado(numeroDelCampo)){
							hecho = true;
						} else {
							cout << "No hay ningun vehiculo en el campo numero " << numeroDelCampo << endl;
							pausaYContinuar();
							hecho = false;
						}
					} else {
						cout << "El campo numero " << numeroDelCampo << " no existe" << endl;
						pausaYContinuar();
						hecho = false;
					}
					
					if (hecho == false) {
						cout << "Intente de nuevo" << endl;
						pausaYContinuar();
					}
				} while (hecho == false);
			
				do {
					cout << "Digite la hora de salida" << endl;
					cout << "Hora: ";
					cin >> hora;
					cout << "Minutos: ";
					cin >> minutos;
					cout << "Segundos: ";
					cin >> segundos;
					//se verifica que la hora ingresada sea valida
					if (!validarHora(hora, minutos, segundos)) {
						cout << "La hora ingresada no es valida" << endl;
						pausaYContinuar();
					}
				} while (validarHora(hora, minutos, segundos) == false);
				//se muestra la hora en formato HH:MM:SS
				cout << "Hora de salida: " << hora << ":" << minutos << ":" << segundos << endl;
				pausaYContinuar();
				//se crea el objeto hora de salida
				horaDeSalida = new Hora(hora, minutos, segundos);
				//se muestra el cobro
				cout << parqueo->retirarUnVehiculoDelParqueo(numeroDelCampo, horaDeSalida);
				break;
			// 6 - Ver solo los campos que están LIBRES. (solo lugar y estado)
			case 6:
				cout << parqueo->mostrarCamposLibres();
				break;
			//7 - Saber la cantidad de vehículos que existen en el parqueo. 
			case 7:
				cout << "La cantidad de vehiculos en el parqueo es: " << parqueo->getCantidadDeVehiculosEnElParqueo() << endl;
				break;
			// 8 - Saber la cantidad de campos libres en el parqueo.
			case 8:
				cout << "La cantidad de campos libres en el parqueo es: " << parqueo->getCamposLibres() << endl;
				break;
		}
		std::system("pause");
	} while (opcionMenu != 19);
	return 0;
}