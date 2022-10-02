#pragma once
#include <iostream>
#include <sstream>
using namespace std;

class Hora {
private:
	int horas;
	int minutos;
	int segundos;
public:
	Hora(int = 0, int = 0, int = 0);
	virtual ~Hora();
	//getters
	int getHora();
	int getMinutos();
	int getSegundos();
	//setters
	void setHoras(int);
	void setMinutos(int);
	void setSegundos(int);
	//metodos
	string toString();
	bool esMenorQue(Hora*);
};