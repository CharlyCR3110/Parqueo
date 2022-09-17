#pragma once
#include <iostream>
#include <sstream>
using namespace std;

class Chofer {
private:
	string cedula;
	string nombre;
public:
	Chofer(string = "", string = "");
	virtual ~Chofer();
	//getters
	string getCedula();
	string getNombre();
	//setters
	void setCedula(string);
	void setNombre(string);
	//metodos
	string toString();
};