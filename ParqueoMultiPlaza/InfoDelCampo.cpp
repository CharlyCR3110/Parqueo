#include "InfoDelCampo.h"

InfoDelCampo::InfoDelCampo(int numeroMaximoDeVehiculos, char estadoCampo)
{
    this->numeroMaximoDeVehiculos = numeroMaximoDeVehiculos;  //tamano del array
    this->estadoCampo = estadoCampo; 
    //O = Ocupado, L = Libre, M = Mantenimiento
    this->numeroDeCarrosRegistrados = 0; //cantidad
    this->dineroGeneradoPorELCampo = 0;
    this->registroDeVehiculos = new Vehiculo*[numeroMaximoDeVehiculos];
    for (int i = 0; i < numeroMaximoDeVehiculos; i++) {
        this->registroDeVehiculos[i] = NULL;
    }
}

InfoDelCampo::~InfoDelCampo()
{
    for (int i = 0; i < numeroMaximoDeVehiculos; i++) {
        delete this->registroDeVehiculos[i];
    }
    delete[] this->registroDeVehiculos;
}

int InfoDelCampo::getNumeroMaximoDeVehiculos()
{
	return numeroMaximoDeVehiculos;
}

int InfoDelCampo::getNumeroDeCarrosRegistrados()
{
	return numeroDeCarrosRegistrados;
}

char InfoDelCampo::getEstadoCampo()
{
	return estadoCampo;
}

double InfoDelCampo::getDineroGeneradoPorELCampo()
{
	return dineroGeneradoPorELCampo;
}

Vehiculo** InfoDelCampo::getRegistroDeVehiculos()
{
	return registroDeVehiculos;
}

void InfoDelCampo::setEstadoCampo(char estadoCampo)
{
    this->estadoCampo = estadoCampo;
}

void InfoDelCampo::setDineroGeneradoPorELCampo(double dineroGeneradoPorELCampo)
{
    this->dineroGeneradoPorELCampo = dineroGeneradoPorELCampo;
}

void InfoDelCampo::setRegistroDeVehiculos(Vehiculo** registroDeVehiculos)
{
    if (registroDeVehiculos != NULL) { delete registroDeVehiculos;}
    this->registroDeVehiculos = registroDeVehiculos;
}

bool InfoDelCampo::ingresarVehiculo(Vehiculo* vehiculo)
{
    if (estadoCampo == 'L' && this->numeroDeCarrosRegistrados < this->numeroMaximoDeVehiculos) {
        this->registroDeVehiculos[this->numeroDeCarrosRegistrados] = vehiculo;
        estadoCampo = 'O';
        this->numeroDeCarrosRegistrados++;
        return true;
    }
    return false;
}

string InfoDelCampo::toString()
{
    stringstream s;
    s << "Numero maximo de vehiculos: " << this->numeroMaximoDeVehiculos << endl;
    s << "Numero de carros registrados: " << this->numeroDeCarrosRegistrados << endl;
    s << "Estado del campo: " << this->estadoCampo << endl;
    s << "Dinero generado por el campo: " << this->dineroGeneradoPorELCampo << endl;
    s << "Registro de vehiculos: " << endl;
    for (int i = 0; i < this->numeroDeCarrosRegistrados; i++) {
        s << this->registroDeVehiculos[i]->toString() << endl;
    }
    return s.str();
}
