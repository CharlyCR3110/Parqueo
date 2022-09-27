#include "Vehiculo.h"

Vehiculo::Vehiculo(string marca, string placa, double tonelaje, string color, Chofer* chofer, Cobro* cobro)
{
	this->marca = marca;
	this->placa = placa;
	this->tonelaje = tonelaje;
	this->color = color;
	this->chofer = chofer;
	this->cobro = cobro;
}

Vehiculo::~Vehiculo()
{
	if (chofer != NULL) { delete chofer; }
	if (cobro != NULL) { delete cobro; }
}
//getters
string Vehiculo::getMarca()
{
	return marca;
}

string Vehiculo::getPlaca()
{
	return placa;
}

double Vehiculo::getTonelaje()
{
	return tonelaje;
}

string Vehiculo::getColor()
{
	return color;
}

Chofer* Vehiculo::getChofer()
{
	return chofer;
}

Cobro* Vehiculo::getCobro()
{
	return cobro;
}
//setters
void Vehiculo::setMarca(string)
{
	this->marca = marca;
}

void Vehiculo::setPlaca(string)
{
	this->placa = placa;
}

void Vehiculo::setTonelaje(double)
{
	this->tonelaje = tonelaje;
}

void Vehiculo::setColor(string)
{
	this->color = color;
}

void Vehiculo::setChofer(Chofer*)
{
	if (chofer != NULL) { delete chofer; }
	this->chofer = chofer;
}

void Vehiculo::setCobro(Cobro*)
{
	if (cobro != NULL) { delete cobro; }
	this->cobro = cobro;
}
//metodos
string Vehiculo::toString()
{
	stringstream ss;
	ss << "Marca: " << marca << endl;
	ss << "Placa: " << placa << endl;
	ss << "Tonelaje: " << tonelaje << endl;
	ss << "Color: " << color << endl;
	ss << "Chofer: " << chofer->toString() << endl;
	ss << "Cobro: " << cobro->toString() << endl;
	return ss.str();
}

int Vehiculo::horasQueElVehiculoEstuvoEnElParqueo() 
{
	int horas = 0;
	horas = cobro->getHoraDeSalida()->getHora() - cobro->getHoraDeEntrada()->getHora();
	if (cobro->getHoraDeSalida()->getMinutos() < cobro->getHoraDeEntrada()->getMinutos()) {
		horas--;
	}
	return horas;
}

double Vehiculo::calcularTotalAPagar()
{
	double montoTotal;
	int horas = horasQueElVehiculoEstuvoEnElParqueo();

	montoTotal = horas * 800.00;
	if (tonelaje >= 1.0 && tonelaje <= 1.5) {
		montoTotal = montoTotal * 1.05;
	}
	else if (tonelaje >= 1.6 && tonelaje <= 3.5) {
		montoTotal = montoTotal * 1.10;
	}
	else if (tonelaje >= 3.6 && tonelaje <= 5.0) {
		montoTotal = montoTotal * 1.15;
	}
	else if (tonelaje > 5.0) {
		montoTotal = montoTotal * 1.20;
	}
	cobro->setTotalPagar(montoTotal);
	return montoTotal;
}

void Vehiculo::actualizarHoraDeSalida(Hora* horaDeSalida)
{
	cobro->setHoraDeSalida(horaDeSalida);
}

string Vehiculo::mostrarCobro()
{
	stringstream ss;
	ss << "Cobro: " << cobro->toString() << endl;
	return ss.str();
}