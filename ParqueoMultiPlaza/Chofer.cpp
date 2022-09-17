#include "Chofer.h"

Chofer::Chofer(string cedula, string nombre)
{
	this->cedula = cedula;
	this->nombre = nombre;
}

Chofer::~Chofer() {}

string Chofer::getCedula()
{
	return cedula;
}

string Chofer::getNombre()
{
	return nombre;
}

void Chofer::setCedula(string cedula)
{
	this->cedula = cedula;
}

void Chofer::setNombre(string nombre)
{
	this->nombre = nombre;
}

string Chofer::toString()
{
	stringstream ss;
	ss << "Cedula: " << cedula << endl
		<< "Nombre: " << nombre << endl << endl;
	return ss.str();
}