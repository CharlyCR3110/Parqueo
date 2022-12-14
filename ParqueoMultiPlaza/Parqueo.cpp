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

void Parqueo::setEstadoDeUnCampo(int posicion, char estado)
{
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

string Parqueo::mostrarTodosLosCamposDelParqueo()
{
    stringstream s;
    for (int i = 0; i < cantidadCampos; i++) {
        s << "Campo numero: " << i << endl << campos[i]->toString() << endl;
    }
    return s.str();
}

string Parqueo::mostrarCamposOcupados()
{
    stringstream s;
    for (int i = 0; i < cantidadCampos; i++) {
        if (campos[i]->getEstadoCampo() == 'O') {
            s << "Campo numero: " << i << endl << campos[i]->toString() << endl;
        }
    }
    return s.str();
}

string Parqueo::mostrarCamposLibres() 
{
    stringstream s;
    for (int i = 0; i < cantidadCampos; i++) {
        // Para que un campo este libre este no puede haber superado su capacidad maxima diaria
        if (campos[i]->getEstadoCampo() == 'L' && campos[i]->getNumeroDeCarrosRegistrados() < campos[i]->getNumeroMaximoDeVehiculos()) {
            s << "Campo numero: " << i << endl << campos[i]->toString() << endl;
        }
    }
    return s.str();
}

string Parqueo::mostrarCamposEnMantenimiento()
{
    stringstream s;
    for (int i = 0; i < cantidadCampos; i++) {
        if (campos[i]->getEstadoCampo() == 'M') {
            s << "Campo numero: " << i << endl << campos[i]->toString() << endl;
        }
    }
    return s.str();
}

/**
 * 
 * Comprueba si el campo es apto para el mantenimiento.
 * 
 */
bool Parqueo::verificarCampoElegibleMantenimiento(int posicion)
{
    if (campos[posicion]->getEstadoCampo() == 'L') {
        return true;
    }
    else {
        return false;
    }
}

/**
 * Comprueba si la posici??n es v??lida, luego comprueba si el veh??culo puede insertarse en la posici??n.
 * Si puede, disminuye los espacios libres y aumenta los espacios ocupados.
 * 
 * @param posicion Posici??n del campo en el que se quiere insertar el veh??culo.
 * @param vehiculo Veh??culo que se quiere insertar.
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
    s << "-------------------------------" << endl;
    s << "        Ticket de Salida" << endl;
    s << "-------------------------------" << endl;
    s << "Campo: " << posicion << endl;
    s << "Placa: " << campos[posicion]->getVehiculo()->getPlaca() << endl;
    s << "-------------------------------" << endl;
    s << "Hora de entrada: " << campos[posicion]->getVehiculo()->getCobro()->getHoraDeEntrada()->toString() << endl;
    s << "Hora de salida: " << campos[posicion]->getVehiculo()->getCobro()->getHoraDeSalida()->toString() << endl;
    s << "Total de horas: " << campos[posicion]->getVehiculo()->getCobro()->diferenciaDeHoras() << endl;
    s << "-------------------------------" << endl;
    s << "Pagado: " << totalPagar << endl;
    s << "-------------------------------" << endl;
    s << "     Gracias por su visita" << endl;
    return s.str();
}

string Parqueo::ticketDeEntrada(int posicion)
{
    stringstream s;

    s << "-------------------------------" << endl;
    s << "       Ticket de Ingreso" << endl;
    s << "-------------------------------" << endl;
    s << "Hora de entrada: " << campos[posicion]->getVehiculo()->getCobro()->getHoraDeEntrada()->toString() << endl;
    s << "Campo: " << posicion << endl;
    s << "Placa: " << campos[posicion]->getVehiculo()->getPlaca() << endl;
    s << "-------------------------------" << endl;
    s << "           Bienvenido" << endl;

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
 * Encuentra el tonelaje m??s com??n de los veh??culos que est??n actualmente estacionados en el aparcamiento
 * @return el tonelaje m??s com??n
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


/**
 * Para calcular el porcentaje de ocupaci??n del parqueo
 * se toma en cuenta la cantidad total de campos, esto incluye los campos
 * que no se pueden usar por estar en mantenimiento
 *
 * 
 * en el caso de que estos campos no se deban tomar en cuenta, se debe cambiar la operacion
 * a la siguiente: (camposOcupados * 100) / (cantidadCampos - camposMantenimiento)
 * 
 */
double Parqueo::porcentajeDeOcupacionDelParqueo()
{
    return (camposOcupados * 100) / cantidadCampos;
}

/**
 * Devuelve un string con la informaci??n de todos los veh??culos que han estado en un campo determinado
 * @param posicion Posici??n del campo
 */
string Parqueo::mostrarInformacionDeLosVehiculosQueHanEstadoEnUnDeterminadoCampo(int posicion)
{
    stringstream s;
    s << "Registro de vehiculos del campo numero " << posicion << endl;
    s << campos[posicion]->mostrarRegistroDeVehiculos();
    return s.str();
}

/**
 * Devuelve un string con la informaci??n de todos los veh??culos que han estado en el aparcamiento
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
            s << endl << "No se han registrado vehiculos en este campo" << endl;
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

bool Parqueo::verificarQueLaHoraDeEntradaSeaMenorQueLaDeSalida(int posicion, Hora* horaDeSalida)
{
    return campos[posicion]->laHoraDeEntradaEsMenorQue(horaDeSalida);
}