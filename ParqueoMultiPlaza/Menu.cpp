#include "Menu.h"
string menu() {
    system("cls");
    stringstream ss;
    ss << endl;
    ss << "Menu: " << endl;
    ss << "1) Mostrar todos los campos del parqueo" << endl;
    ss << "2) Mostrar solamente los campos que estan ocupados" << endl; //estadoCampo == 'O'
    ss << "3) Mostrar solamente los campos que estan en mantenimiento" << endl; //estadoCampo == 'M'
    ss << "4) Ingresar un vehiculo al parqueo" << endl; //solicitar posicion del campo
    ss << "5) Cancelar la estancia en el lugar" << endl;  //Realizar el cobro
    ss << "6) Mostrar solamente los campos que esten libre" << endl; //estadoCampo == 'L'
    ss << "7) Mostrar la cantidad de vehiculos que existen en el parqueo" << endl; // contar los vehiculos que estan en el parqueo
    ss << "8) Saber la cantidad de campos libres en el parqueo" << endl; // contar los campos que estan libres
    ss << "9) Saber la cantidad de campos ocupados en el parqueo" << endl; // contar los campos que estan ocupados
    ss << "10) Saber la cantidad de campos en mantenimiento en el parqueo" << endl; // contar los campos que estan en mantenimiento
    ss << "11) Saber la cantidad de vehiculos que han ingresado en el dia" << endl; // sumar numeroDeCarrosRegistrados de todos los objetos infoDelCampo
    ss << "12) Saber la cantidad de dinero que ha ingresado al parque este dia" << endl;
    ss << "13) Saber la cantidad de dinero generado por un campo en especifico" << endl; //solicitar posicion del campo
    ss << "14) Saber el tonelaje de los vehiculos que hacen mas uso del parqueo" << endl; // Buscar el tonelaje que mas se repite
    ss << "15) Saber el porcentaje de ocupacion del parqueo" << endl;
    ss << "16) Mostrar la informacion de los vehiculos que han estado en un determinado campo" << endl; //solicitar posicion del campo
    ss << "17) Mostrar la informacion de todos los vehiculos que han estado en el parqueo" << endl; //recorrer todos los campos y mostrar el registro de vehiculos
    ss << "18) Mostrar los vehiculos que se encuentran en el rango de tonelaje de 1.0 a 1.5" << endl;
    ss << "19) Salir" << endl;
    ss << "Ingrese una opcion: ";
    return ss.str();
}