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
	if (horaDeSalida != NULL) {
		s << "Hora de salida: " << horaDeSalida->toString() << endl;
		s << "Total a pagar: " << totalPagar << endl;

	} else {
		s << "Hora de salida: " << "No ha salido" << endl;\
		s << "Total a pagar: " << "No ha salido" << endl;
	}
	return s.str();
}

string Cobro::diferenciaDeHoras() {
	stringstream s;
	int horaEntrada = horaDeEntrada->getHora();
	int minutoEntrada = horaDeEntrada->getMinutos();
	int segundoEntrada = horaDeEntrada->getSegundos();
	int horaSalida = horaDeSalida->getHora();
	int minutoSalida = horaDeSalida->getMinutos();
	int segundoSalida = horaDeSalida->getSegundos();
	int horaDiferencia = horaSalida - horaEntrada;
	int minutoDiferencia = minutoSalida - minutoEntrada;
	int segundoDiferencia = segundoSalida - segundoEntrada;
	if (segundoDiferencia < 0) {
		segundoDiferencia += 60;
		minutoDiferencia--;
	}
	if (minutoDiferencia < 0) {
		minutoDiferencia += 60;
		horaDiferencia--;
	}
	s << horaDiferencia << ":" << minutoDiferencia << ":" << segundoDiferencia;
	return s.str();
}