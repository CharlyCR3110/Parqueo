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

/**
 * Devuelve un string con el estado del campo, la matrícula del coche si está ocupado, un mensaje
 * si está en mantenimiento o un mensaje si no hay vehículos registrados.
 * 
 */
string InfoDelCampo::toString() {
    stringstream s;
    s << "Estado del campo: " << this->estadoCampo << endl;
    if (estadoCampo == 'O') {
        s << "Placa del vehiculo: " << this->registroDeVehiculos[numeroDeCarrosRegistrados - 1]->getPlaca() << endl;
    } else if (estadoCampo == 'M') {
        s << "El campo esta en mantenimiento" << endl;
    } else {
        s << "No hay ningun vehiculo registrado actualmente" << endl;
    }
    return s.str();
}

/**
 * Metodo que devuelve un string con la informacion sobre la clase InfoDelCampo
 * 
 * @return A string
 */
string InfoDelCampo::toStringCompleto() //tiene mas informacion
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

/**
 * Toma un puntero a un vehículo y lo añade al array de vehículos
 * 
 * @param vehiculo es un puntero de un vehiculo
 * 
 * @return true si se pudo añadir el vehiculo, false si no se pudo
 */
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

double InfoDelCampo::calcularElDineroGeneradoPorELCampo()
{
    double dinero = 0;
    for (int i = 0; i < this->numeroDeCarrosRegistrados; i++) {
        dinero += this->registroDeVehiculos[i]->getCobro()->getTotalPagar();
    }
    this->dineroGeneradoPorELCampo = dinero;
    return dinero;
}

/**
 * Es una función que devuelve un string que contiene la información de todos los coches que están
 * registrados en el campo.
 * 
 * @return Un objeto stringstream.
 */
string InfoDelCampo::mostrarRegistroDeVehiculos()
{
    stringstream s;
    for (int i = 0; i < this->numeroDeCarrosRegistrados; i++) {
        s << "Carro numero: " << i << endl << this->registroDeVehiculos[i]->toString() << endl;
    }
    return s.str();
}

Vehiculo* InfoDelCampo::getVehiculo()
{
    //devuelve el vehiculo que esta en el campo
    if (this->numeroDeCarrosRegistrados > 0) {
        if (this->estadoCampo == 'O') {
            return this->registroDeVehiculos[this->numeroDeCarrosRegistrados - 1];
        }
    }
    return NULL;
}

bool InfoDelCampo::retirarVehiculo() {
    if (this->numeroDeCarrosRegistrados > 0) {
        if (this->estadoCampo == 'O') {
            this->estadoCampo = 'L';
            return true;
        }
    }
    return false;
}

/**
 * Devuelve true si el ultimo carro registrado en el parqueadero tiene una hora de entrada menor a la
 * hora pasada como parametro
 */
bool InfoDelCampo::laHoraDeEntradaEsMenorQue(Hora* hora)
{
    if (this->numeroDeCarrosRegistrados > 0) {
        if (this->estadoCampo == 'O') {
            return this->registroDeVehiculos[this->numeroDeCarrosRegistrados - 1]->getCobro()->getHoraDeEntrada()->esMenorQue(hora);
        }
    }
    return false;
}