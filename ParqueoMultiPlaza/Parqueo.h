#include "InfoDelCampo.h"

class Parqueo {
private:
    InfoDelCampo** campos;
    //tamano y cantidad
    string nombre;
    string telefono;
    int cantidadCampos;  //cantidad
    int numeroCampos; //tamano maxima
    int camposLibres;
    int camposOcupados;
    int camposMantenimiento;
public:
    Parqueo(string nombre = "", string telefono = "", int numeroCampos = 0);
    virtual ~Parqueo();
    //getters
    string getNombre();
    string getTelefono();
    int getCantidadCampos();
    int getNumeroCampos();
    int getCamposLibres();
    int getCamposOcupados();
    int getCamposEnMantenimiento();
    //retornar el vector de campos
    InfoDelCampo** getCampos();
    //setters
    //void setCantidadCampos(int cantidadCampos);
    //void setNumeroCampos(int numeroCampos);
    //void setCamposLibres(int camposLibres);
    //void setCamposOcupados(int camposOcupados);
    //void setCamposMantenimiento(int camposMantenimiento);
    void setEstadoDeUnCampo(int posicion, char estado);
    void verificarEstadoDeLosCampos(); //verifica el estado de los campos y actualiza los contadores
    bool ingresarCampo(InfoDelCampo* campo);
    string toString();
    string mostrarTodosLosCamposDelParqueo();
    string mostrarCamposOcupados();
    string mostrarCamposLibres();
    string mostrarCamposEnMantenimiento();
    bool ingresarUnVehiculoAlParqueo(int posicion, Vehiculo* vehiculo);
    Vehiculo* buscarVehiculo(string placa);
    string retirarUnVehiculoDelParqueo(int posicion, Hora* horaDeSalida);
    string ticketDeSalida(int posicion);
    bool verificarQueElCampoExista(int posicion);
    bool verificarQueEsteOcupado(int posicion);
    int getCantidadDeVehiculosEnElParqueo();
    int cantidadDeVehiculosQueHanIngresadoEnElDia();
};