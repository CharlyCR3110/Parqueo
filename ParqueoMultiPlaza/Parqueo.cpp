#include "Parqueo.h"

Parqueo::Parqueo(string nombre, string telefono, int numeroCampos)
{
    this->nombre = nombre;
    this->telefono = telefono;
    this->numeroCampos = numeroCampos;
    this->cantidadCampos = 0;
    this->camposLibres = numeroCampos;
    this->camposOcupados = 0;
    this->camposMantenimiento = 0;
    this->campos = new InfoDelCampo*[numeroCampos];
    for (int i = 0; i < numeroCampos; i++) {
        this->campos[i] = NULL;
    }
    //todos los campos deben de tener 10 espacios y estar libres
    for (int i = 0; i < numeroCampos; i++) {
        this->ingresarCampo(new InfoDelCampo(10, 'L'));
    }

}

Parqueo::~Parqueo()
{
    for (int i = 0; i < cantidadCampos; i++) {
        delete campos[i];
    }
    delete[] campos;
}

string Parqueo::getNombre()
{
    return nombre;
}

string Parqueo::getTelefono()
{
    return telefono;
}

int Parqueo::getCantidadCampos()
{
	return cantidadCampos;
}

int Parqueo::getNumeroCampos()
{
	return numeroCampos;
}

int Parqueo::getCamposLibres()
{
	return camposLibres;
}

int Parqueo::getCamposOcupados()
{
	return camposOcupados;
}

int Parqueo::getCamposEnMantenimiento()
{
	return camposMantenimiento;
}

InfoDelCampo** Parqueo::getCampos()
{
    return campos;
}

void Parqueo::setEstadoDeUnCampo(int posicion, char estado) {
    campos[posicion]->setEstadoCampo(estado);

    if (estado == 'L') {
        camposLibres++;
        camposOcupados--;
    }
    else if (estado == 'O') {
        camposLibres--;
        camposOcupados++;
    }
    else if (estado == 'M') {
        camposLibres--;
        camposMantenimiento++;
    }
}

void Parqueo::verificarEstadoDeLosCampos()
{
    for (int i = 0; i < cantidadCampos; i++) {
        if (campos[i]->getEstadoCampo() == 'L') {
            camposLibres++;
        }
        else if (campos[i]->getEstadoCampo() == 'O') {
            camposOcupados++;
        }
        else if (campos[i]->getEstadoCampo() == 'M') {
            camposMantenimiento++;
        }
    }
}

bool Parqueo::ingresarCampo(InfoDelCampo* campo)
{
    if (cantidadCampos < numeroCampos) {
        campos[cantidadCampos] = campo;
        cantidadCampos++;
        return true;
    }
    else {
        return false;
    }
}

string Parqueo::toString()
{
    stringstream s;
    s << "Numero campos: " << numeroCampos << endl;
    s << "Campos libres: " << camposLibres << endl;
    s << "Campos ocupados: " << camposOcupados << endl;
    s << "Campos en mantenimiento: " << camposMantenimiento << endl;
    return s.str();
}

string Parqueo::mostrarTodosLosCamposDelParqueo() {
    stringstream s;
    for (int i = 0; i < cantidadCampos; i++) {
        s << "Campo numero: " << i << endl << campos[i]->toString() << endl;
    }
    return s.str();
}

string Parqueo::mostrarCamposOcupados() {
    stringstream s;
    for (int i = 0; i < cantidadCampos; i++) {
        if (campos[i]->getEstadoCampo() == 'O') {
            s << "Campo numero: " << i << endl << campos[i]->toString() << endl;
        }
    }
    return s.str();
}

string Parqueo::mostrarCamposDisponibles() {
    stringstream s;
    for (int i = 0; i < cantidadCampos; i++) {
        if (campos[i]->getEstadoCampo() == 'L') {
            s << "Campo numero: " << i << endl << campos[i]->toString() << endl;
        }
    }
    return s.str();
}

string Parqueo::mostrarCamposEnMantenimiento() {
    stringstream s;
    for (int i = 0; i < cantidadCampos; i++) {
        if (campos[i]->getEstadoCampo() == 'M') {
            s << "Campo numero: " << i << endl << campos[i]->toString() << endl;
        }
    }
    return s.str();
}

bool Parqueo::ingresarUnVehiculoAlParqueo(int posicion, Vehiculo* vehiculo)
{
    //validar que la posicion exista
    if (posicion < cantidadCampos && posicion >= 0) {
        if (campos[posicion]->ingresarVehiculo(vehiculo)) {
            camposLibres--;
            camposOcupados++;
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

Vehiculo* Parqueo::buscarVehiculo(string placa)
{
    for (int i = 0; i < cantidadCampos; i++) {
        if (campos[i]->getEstadoCampo() == 'O') {
            if (campos[i]->getVehiculo()->getPlaca() == placa) {
                return campos[i]->getVehiculo();
            }
        }
    }
    return NULL;
}