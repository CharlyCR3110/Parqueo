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