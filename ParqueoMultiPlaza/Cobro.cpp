#include "Cobro.h"

Cobro::Cobro(Hora* entrada, Hora* salida)
{
	this->horaDeEntrada = entrada;
	this->horaDeSalida = salida;
	this->totalPagar = 0;
}

Cobro::~Cobro() {
	if (horaDeEntrada != NULL) { delete horaDeEntrada; }
	if (horaDeSalida != NULL) { delete horaDeSalida; }
}
//getters
Hora* Cobro::getHoraDeEntrada()
{
	return horaDeEntrada;
}
Hora* Cobro::getHoraDeSalida()
{
	return horaDeSalida;
}
double Cobro::getTotalPagar()
{
	return totalPagar;
}
//setters
void Cobro::setHoraDeEntrada(Hora* entrada)
{
	if (entrada != NULL) { delete horaDeEntrada; }
	this->horaDeEntrada = entrada;
}
void Cobro::setHoraDeSalida(Hora* salida)
{
	if (salida != NULL) { delete horaDeSalida; }
	this->horaDeSalida = salida;
}
void Cobro::setTotalPagar(double total)
{
	this->totalPagar = total;
}
//toString
string Cobro::toString()
{
	stringstream s;
	s << "Hora de entrada: " << horaDeEntrada->toString() << endl;
	s << "Hora de salida: " << horaDeSalida->toString() << endl;
	s << "Total a pagar: " << totalPagar << endl;
	return s.str();
}