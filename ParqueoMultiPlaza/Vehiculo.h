#pragma once
#include "Chofer.h"
#include "Cobro.h"

class Vehiculo {
private:
	string marca;
	string placa;
	double tonelaje;
	string color;
	Chofer* chofer;
	Cobro* cobro;
public:
	Vehiculo(string = "", string = "", double = 0, string = "", Chofer* = NULL, Cobro* = NULL);
	virtual ~Vehiculo();
	//getters
	string getMarca();
	string getPlaca();
	double getTonelaje();
	string getColor();
	Chofer* getChofer();
	Cobro* getCobro();
	//setters
	void setMarca(string);
	void setPlaca(string);
	void setTonelaje(double);
	void setColor(string);
	void setChofer(Chofer*);
	void setCobro(Cobro*);
	//metodos
	string toString();
	double calcularTotalAPagar();
};