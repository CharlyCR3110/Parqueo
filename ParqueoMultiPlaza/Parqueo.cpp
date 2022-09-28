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

string Parqueo::mostrarCamposLibres() {
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

/**
 * Comprueba si la posición es válida, luego comprueba si el vehículo puede insertarse en la posición.
 * Si puede, disminuye los espacios libres y aumenta los espacios ocupados.
 * 
 * @param posicion Posición del campo en el que se quiere insertar el vehículo.
 * @param vehiculo Vehículo que se quiere insertar.
 */
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

/**
 * Devuelve un puntero a un objeto vehiculo si el vehiculo es encontrado en el parqueo, de lo contrario 
 * devuelve NULL
 * @param placa la placa del vehiculo a buscar
 */
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

string Parqueo::retirarUnVehiculoDelParqueo(int posicion, Hora* horaDeSalida) 
{
    stringstream s;
    if (campos[posicion]->getEstadoCampo() == 'O') {
        campos[posicion]->getVehiculo()->actualizarHoraDeSalida(horaDeSalida);
        camposLibres++;
        camposOcupados--;
        s << this->ticketDeSalida(posicion);
        campos[posicion]->retirarVehiculo();
    } else {
        s << "No hay ningun vehiculo en ese campo" << endl;
    }
    return s.str();
}

string Parqueo::ticketDeSalida(int posicion)
{
    stringstream s;
    double totalPagar = campos[posicion]->getVehiculo()->calcularTotalAPagar();
    s << "Ticket de Salida: " << endl;
    s << "Campo: " << posicion << endl;
    s << "Datos del vehiculo: " << endl;
    s << "Marca: " << campos[posicion]->getVehiculo()->getMarca() << endl;
    s << "Placa: " << campos[posicion]->getVehiculo()->getPlaca() << endl;
    s << "Datos del chofer: " << endl;
    s << campos[posicion]->getVehiculo()->getChofer()->toString() << endl;
    //hora de entrada y hora de salida
    s << "Hora de entrada: " << campos[posicion]->getVehiculo()->getCobro()->getHoraDeEntrada()->toString() << endl;
    s << "Hora de salida: " << campos[posicion]->getVehiculo()->getCobro()->getHoraDeSalida()->toString() << endl;
    s << "El vehiculo estuvo: " << campos[posicion]->getVehiculo()->getCobro()->diferenciaDeHoras() << endl;
    s << "Total a pagar: " << totalPagar << endl;
    return s.str();
}

bool Parqueo::verificarQueElCampoExista(int posicion)
{
    if (posicion < cantidadCampos && posicion >= 0) {
        return true;
    }
    else {
        return false;
    }
}

//verifica que el campo actualmente este ocupado
bool Parqueo::verificarQueEsteOcupado(int posicion)
{
    if (campos[posicion]->getEstadoCampo() == 'O') {
        return true;
    }
    else {
        return false;
    }
}

int Parqueo::getCantidadDeVehiculosEnElParqueo()
{
    return camposOcupados;
}

int Parqueo::cantidadDeVehiculosQueHanIngresadoEnElDia() 
{
    int cantidad = 0;
    for (int i = 0; i < cantidadCampos; i++) {
        cantidad += campos[i]->getNumeroDeCarrosRegistrados();
    }
    return cantidad;
}

double Parqueo::dineroQueHaIngresadoAlParqueoEsteDia()
{
    double total = 0;
    for (int i = 0; i < cantidadCampos; i++) {
        total += campos[i]->calcularElDineroGeneradoPorELCampo();
    }
    return total;
}

double Parqueo::dineroQueHaIngresadoAlParqueoEsteDiaPorUnCampo(int posicion)
{
    return campos[posicion]->calcularElDineroGeneradoPorELCampo();
}

/**
 * Encuentra el tonelaje más común de los vehículos que están actualmente estacionados en el aparcamiento
 * @return el tonelaje más común
 */
double Parqueo::tonelajeDeLosVehiculosQueHacenMasUsoDelParqueo()
{
    //buscar el tonelaje que mas repite
    double tonelajeMasRepetido = 0;
    int cantidadDeVecesQueSeRepite = 0;
    for (int i = 0; i < cantidadCampos; i++) {
        if (campos[i]->getEstadoCampo() == 'O') {
            double tonelajeActual = campos[i]->getVehiculo()->getTonelaje();
            int cantidadDeVecesQueSeRepiteElTonelajeActual = 0;
            for (int j = 0; j < cantidadCampos; j++) {
                if (campos[j]->getEstadoCampo() == 'O') {
                    if (campos[j]->getVehiculo()->getTonelaje() == tonelajeActual) {
                        cantidadDeVecesQueSeRepiteElTonelajeActual++;
                    }
                }
            }
            if (cantidadDeVecesQueSeRepiteElTonelajeActual > cantidadDeVecesQueSeRepite) {
                tonelajeMasRepetido = tonelajeActual;
                cantidadDeVecesQueSeRepite = cantidadDeVecesQueSeRepiteElTonelajeActual;
            }
        }
    }
    return tonelajeMasRepetido;
}

double Parqueo::porcentajeDeOcupacionDelParqueo()
{
    return (camposOcupados * 100) / cantidadCampos;
}

/**
 * Devuelve un string con la información de todos los vehículos que han estado en un campo determinado
 * @param posicion Posición del campo
 */
string Parqueo::mostrarInformacionDeLosVehiculosQueHanEstadoEnUnDeterminadoCampo(int posicion)
{
    stringstream s;
    s << "Registro de vehiculos del campo numero " << posicion << endl;
    s << campos[posicion]->mostrarRegistroDeVehiculos();
    return s.str();
}

/**
 * Devuelve un string con la información de todos los vehículos que han estado en el aparcamiento
 */
string Parqueo::mostrarInformacionDeTodosLosVehiculosQueEstanOHanEstadoEnElParqueo() 
{
    stringstream s;
    s << "Registro de todos los vehiculos que han estado en el parqueo" << endl;
    s << "------------------------------------------------------------" << endl;
    for (int i = 0; i < cantidadCampos; i++) {
        s << "Registro de vehiculos del campo numero " << i << endl;
        if (campos[i]->getNumeroDeCarrosRegistrados() > 0) {
            s << campos[i]->mostrarRegistroDeVehiculos();
        }
        else {
            s << "No se han registrado vehiculos en este campo" << endl;
        }
        //podria llamar a la funcion "mostrarInformacionDeLosVehiculosQueHanEstadoEnUnDeterminadoCampo"
        //  y pasarle i como parametro pero no se si es buena practica
    }
    return s.str();
}

string Parqueo::mostrarVehiculosQueSeEncuentranEnElRangoDeTonelajeDe1A15()
{
    stringstream s;
    s << "Vehiculos que se encuentran en el rango de tonelaje de 1 a 1.5" << endl;
    s << "------------------------------------------------------------" << endl;
    for (int i = 0; i < cantidadCampos; i++) {
        if (campos[i]->getEstadoCampo() == 'O') {
            if (campos[i]->getVehiculo()->getTonelaje() >= 1 && campos[i]->getVehiculo()->getTonelaje() <= 1.5) {
                s << campos[i]->getVehiculo()->toString() << endl;
            }
        }
    }
    return s.str();
}
