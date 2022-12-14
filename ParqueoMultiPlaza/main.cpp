#include "Parqueo.h"
#include "Menu.h"
#include "funcionesVarias.h"
using namespace std;

int main() {
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
		do {
			//se muestran los campos libres (unicamente los libres, no los ocupados, 
			// porque los ocupados no se pueden poner en mantenimiento)
			cout << "Campos elegibles: " << endl;
			cout << parqueo->mostrarCamposLibres();
			cout << "Ingrese el numero del campo que desear poner en mantenimiento: ";
			cin >> numeroDelCampo;
			// se verifica que el numero del campo sea valido
			if (parqueo->verificarQueElCampoExista(numeroDelCampo)) {
				if (parqueo->verificarCampoElegibleMantenimiento(numeroDelCampo)) {
					parqueo->setEstadoDeUnCampo(numeroDelCampo, 'M');
					hecho = true;
					cout << "El campo numero: " << numeroDelCampo << " se ha puesto en mantenimiento exitosamente" << endl;
					pausaYContinuar();
				} else {
					cout << "El campo no es elegible para poner en mantenimiento" << endl;
					hecho = false;
					pausaYContinuar();
				}
			} else {
				cout << "El campo no existe" << endl;
				hecho = false;
				pausaYContinuar();
			}
		} while (hecho == false);
	}

	do {
		cout << menu();
		cin >> opcionMenu;

		std::system("cls");
		switch (opcionMenu) {
			case 1:
				cout << parqueo->mostrarTodosLosCamposDelParqueo();
				break;
			case 2:
				cout << parqueo->mostrarCamposOcupados();
				break;
			case 3:
				cout << parqueo->mostrarCamposEnMantenimiento();
				break; 
			case 4:
				//datos del chofer
				cout << "-------Datos del chofer-------" << endl;
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
				cout << "------Datos del vehiculo------" << endl;
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
				cout << "--------Hora de entrada-------" << endl << endl;
				cout << "Se utiliza el formato de 24 horas" << endl;
				cout << "Ejemplo: 16:30:23" << endl;
				pausaYContinuar();
				cout << "Digite la hora de entrada" << endl;
				cout << "Hora: ";
				cin >> hora;
				while (hora < 0 || hora > 23) {
					std::system("cls");
					cout << "La hora debe estar entre 0 y 23" << endl;
					cout << "Hora: ";
					cin >> hora;
				}
				cout << "Minutos: ";
				cin >> minutos;
				while (minutos < 0 || minutos > 59) {
					std::system("cls");
					cout << "Los minutos deben estar entre 0 y 59" << endl;
					cout << "Minutos: ";
					cin >> minutos;
				}
				cout << "Segundos: ";
				cin >> segundos;
				while (segundos < 0 || segundos > 59) {
					std::system("cls");
					cout << "Los segundos deben estar entre 0 y 59" << endl;
					cout << "Segundos: ";
					cin >> segundos;
				}
				pausaYContinuar();
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
					cout << endl << "Ingrese el numero del campo donde desea ingresar el vehiculo: ";
					cin >> numeroDelCampo;
					//por si alguien ingresa un caracter no valido
					if (!cin.good()) {
						cin.clear();
						cin.ignore(numeric_limits<int>::max(), '\n');
					}
					//en el if () se verifica y se ingresa el vehiculo en el campo
					if (parqueo->ingresarUnVehiculoAlParqueo(numeroDelCampo, vehiculo)) {
						pausaYContinuar();
						cout << parqueo->ticketDeEntrada(numeroDelCampo);
						hecho = true;
					} else {
						cout << "No se puede ingresar un vehiculo en ese campo" << endl;
						pausaYContinuar();
						cout << "Por favor ingrese un campo valido" << endl;
						hecho = false;
					}
				} while (hecho == false);
				break;
			case 5:
				do {
					//se muestra los campos ocupados
					cout << parqueo->mostrarCamposOcupados();
					cout << "Ingrese el numero del campo donde se encuentra el vehiculo: ";
					cin >> numeroDelCampo;
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
				pausaYContinuar();
				do {
					cout << "Digite la hora de salida" << endl;
					cout << "Hora: ";
					cin >> hora;
					while (hora < 0 || hora > 23) {
						std::system("cls");
						cout << "La hora debe estar entre 0 y 23" << endl;
						cout << "Hora: ";
						cin >> hora;
					}
					cout << "Minutos: ";
					cin >> minutos;
					while (minutos < 0 || minutos > 59) {
						std::system("cls");
						cout << "Los minutos deben estar entre 0 y 59" << endl;
						cout << "Minutos: ";
						cin >> minutos;
					}
					cout << "Segundos: ";
					cin >> segundos;
					while (segundos < 0 || segundos > 59) {
						std::system("cls");
						cout << "Los segundos deben estar entre 0 y 59" << endl;
						cout << "Segundos: ";
						cin >> segundos;
					}
					//se verifica que la hora sea mayor a la hora de entrada
					if (parqueo->verificarQueLaHoraDeEntradaSeaMenorQueLaDeSalida(numeroDelCampo, new Hora(hora, minutos, segundos))) {
						hecho = true;
					} else {
						cout << "La hora de salida debe ser mayor a la hora de entrada" << endl;
						pausaYContinuar();
						hecho = false;
					}
				} while (hecho == false);
				pausaYContinuar();
				//se muestra la hora en formato HH:MM:SS
				cout << "Hora de salida: " << hora << ":" << minutos << ":" << segundos << endl;
				pausaYContinuar();
				//se crea el objeto hora de salida
				horaDeSalida = new Hora(hora, minutos, segundos);
				//se muestra el cobro
				cout << parqueo->retirarUnVehiculoDelParqueo(numeroDelCampo, horaDeSalida);
				break;
			case 6:
				cout << parqueo->mostrarCamposLibres();
				break;
			case 7:
				cout << "La cantidad de vehiculos en el parqueo es: " << parqueo->getCantidadDeVehiculosEnElParqueo() << endl;
				break;
			case 8:
				cout << "La cantidad de campos libres en el parqueo es: " << parqueo->getCamposLibres() << endl;
				break;
			case 9:
				cout << "La cantidad de campos ocupados en el parqueo es: " << parqueo->getCamposOcupados() << endl;
				break;
			case 10:
				cout << "La cantidad de campos en mantenimiento en el parqueo es: " << parqueo->getCamposEnMantenimiento() << endl;
				break;
			case 11:
				cout << "La cantidad de vehiculos que han ingresado en el dia es: " << parqueo->cantidadDeVehiculosQueHanIngresadoEnElDia() << endl;
				break; 
			case 12:
				cout << "La cantidad de dinero que ha ingresado al parqueo este dia es: " << parqueo->dineroQueHaIngresadoAlParqueoEsteDia() << endl;
				break;
			case 13:
				//se pide el campo donde esta  ubicado el vehiculo
				do {
					cout << "Ingrese el numero del campo: ";
					cin >> numeroDelCampo;
					//se verifica que el campo ingresado sea valido
					if (parqueo->verificarQueElCampoExista(numeroDelCampo)) {
						hecho = true;
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
				cout << "La cantidad de dinero que ha ingresado el parqueo por el campo numero " << numeroDelCampo << " es: " << parqueo->dineroQueHaIngresadoAlParqueoEsteDiaPorUnCampo(numeroDelCampo) << endl;
				break; 
			case 14:
				cout << "El tonelaje de los vehiculos que hacen mas uso del parqueo es: " << parqueo->tonelajeDeLosVehiculosQueHacenMasUsoDelParqueo() << endl;
				break; 
			case 15:
				cout << "El porcentaje de ocupacion que tiene el parqueo es: " << parqueo->porcentajeDeOcupacionDelParqueo() << "%" << endl;
				break;
			case 16:
				do {
					cout << "Ingrese el numero del campo: ";
					cin >> numeroDelCampo;
					//se verifica que el campo ingresado sea valido
					if (parqueo->verificarQueElCampoExista(numeroDelCampo)) {
						hecho = true;
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
				cout << parqueo->mostrarInformacionDeLosVehiculosQueHanEstadoEnUnDeterminadoCampo(numeroDelCampo);
				break; 
			case 17:
				cout << parqueo->mostrarInformacionDeTodosLosVehiculosQueEstanOHanEstadoEnElParqueo();
				break; 
			case 18:
				cout << parqueo->mostrarVehiculosQueSeEncuentranEnElRangoDeTonelajeDe1A15();
				break;
			case 19:
				cout << "Gracias por usar el programa" << endl;
				break;
			default:
				cout << "Opcion no valida" << endl;
				break;
		}
		std::system("pause");
	} while (opcionMenu != 19);
	
	delete parqueo;
	return 0;
}