#pragma once
#include "Hora.h"

class Cobro {
private:
	Hora* horaDeEntrada;
	Hora* horaDeSalida;
	double totalPagar;
public:
	//Constructor/Destructor
	Cobro(Hora* = NULL, Hora* = NULL);
	virtual ~Cobro();
	//getters
	Hora* getHoraDeEntrada();
	Hora* getHoraDeSalida();
	double getTotalPagar();
	//setters
	void setHoraDeEntrada(Hora*);
	void setHoraDeSalida(Hora*);
	void setTotalPagar(double);
	//metodos
	string toString();
	string diferenciaDeHoras();
};