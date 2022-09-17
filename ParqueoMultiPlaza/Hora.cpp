#include "Hora.h"

Hora::Hora(int horas, int minutos, int segundos) {
	this->horas = horas;
	this->minutos = minutos;
	this->segundos = segundos;
}
Hora::~Hora() {
}
//getters
int Hora::getHora() {
	return horas;
}
int Hora::getMinutos() {
	return minutos;
}
int Hora::getSegundos() {
	return segundos;
}
//setters
void Hora::setHoras(int horas) {
	this->horas = horas;
}
void Hora::setMinutos(int minuto) {
	this->minutos = minuto;
}
void Hora::setSegundos(int segundo) {
	this->segundos = segundo;
}
//tostring
string Hora::toString() {
	stringstream ss;
	ss << horas << ":" << minutos << ":" << segundos << endl;
	return ss.str();
}