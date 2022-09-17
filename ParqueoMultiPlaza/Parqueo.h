#include "InfoDelCampo.h"

class Parqueo {
private:
    InfoDelCampo** campos;
	//tamano y cantidad
	int cantidadCampos;  //cantidad
    int numeroCampos; //tamano maxima
    int camposLibres;
    int camposOcupados;
    int camposMantenimiento;
public:
    Parqueo(int numeroCampos = 0);
    virtual ~Parqueo();
	//getters
	int getCantidadCampos();
    int getNumeroCampos();
    int getCamposLibres();
    int getCamposOcupados();
    int getCamposEnMantenimiento();
    //setters
    //void setCantidadCampos(int cantidadCampos);
    //void setNumeroCampos(int numeroCampos);
    //void setCamposLibres(int camposLibres);
    //void setCamposOcupados(int camposOcupados);
    //void setCamposMantenimiento(int camposMantenimiento);
    void verificarEstadoDeLosCampos(); //verifica el estado de los campos y actualiza los contadores
    bool ingresarCampo(InfoDelCampo* campo);
    string toString();
    
};