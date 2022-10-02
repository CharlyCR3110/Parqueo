#pragma once
#include "Vehiculo.h"

class InfoDelCampo {
private:
    int numeroMaximoDeVehiculos; //tamano del array
    int numeroDeCarrosRegistrados; //cantidad //carros que se han registrado en ese dia // maximo 10
    char estadoCampo; //O, M, L
    double dineroGeneradoPorELCampo;
    Vehiculo** registroDeVehiculos; //array
public:
    InfoDelCampo(int numeroMaximoDeVehiculos = 10, char estadoCampo = 'L');
    virtual ~InfoDelCampo();
    //getters
    int getNumeroMaximoDeVehiculos();
    int getNumeroDeCarrosRegistrados();
    char getEstadoCampo();
    double getDineroGeneradoPorELCampo();
    Vehiculo** getRegistroDeVehiculos();
    Vehiculo* getVehiculo();
    //setters
    //no se puede cambiar el numero maximo de vehiculos
    // void setNumeroMaximoDeVehiculos(int);
    // void setNumeroDeCarrosRegistrados(int);
    void setEstadoCampo(char);
    void setDineroGeneradoPorELCampo(double);
    void setRegistroDeVehiculos(Vehiculo**);
    //metodos
    string toString();
    string toStringCompleto(); //tiene mas informacion
    bool ingresarVehiculo(Vehiculo* vehiculo);
    double calcularElDineroGeneradoPorELCampo();
    string mostrarRegistroDeVehiculos();
    bool retirarVehiculo(); //realmente no se retira, simplemente se el campo se pone libre
    bool laHoraDeEntradaEsMenorQue(Hora* hora);
};