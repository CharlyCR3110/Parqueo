#include "Parqueo.h"

Parqueo::Parqueo(string nombre, string telefono, int numeroCampos)
{
    this->nombre = nombre;
    this->telefono = telefono;
    this->numeroCampos = numeroCampos;
    this->cantidadCampos = 0;
    this->camposLibres = 0;
    this->camposOcupados = 0;
    this->camposMantenimiento = 0;
    this->campos = new InfoDelCampo*[numeroCampos];
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
    s << "Cantidad de campos utilizados: " << cantidadCampos << endl;
    s << "Numero maximo de campos: " << numeroCampos << endl;
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
            s << campos[i]->toString() << endl;
        }
    }
    return s.str();
}