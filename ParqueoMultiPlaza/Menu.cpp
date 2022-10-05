#include "Menu.h"
string menu()
{
    system("cls");
    stringstream ss;
    ss << endl;
    ss << "Menu: " << endl;
    ss << "1) Mostrar todos los campos del parqueo" << endl;
    ss << "2) Mostrar solamente los campos que estan ocupados" << endl;
    ss << "3) Mostrar solamente los campos que estan en mantenimiento" << endl;
    ss << "4) Ingresar un vehiculo al parqueo" << endl;
    ss << "5) Cancelar la estancia en el lugar" << endl;
    ss << "6) Mostrar solamente los campos que esten libre" << endl;
    ss << "7) Mostrar la cantidad de vehiculos que existen en el parqueo" << endl;
    ss << "8) Saber la cantidad de campos libres en el parqueo" << endl; 
    ss << "9) Saber la cantidad de campos ocupados en el parqueo" << endl; 
    ss << "10) Saber la cantidad de campos en mantenimiento en el parqueo" << endl;
    ss << "11) Saber la cantidad de vehiculos que han ingresado en el dia" << endl;
    ss << "12) Saber la cantidad de dinero que ha ingresado al parqueo este dia" << endl;
    ss << "13) Saber la cantidad de dinero generado por un campo en especifico" << endl;
    ss << "14) Saber el tonelaje de los vehiculos que hacen mas uso del parqueo" << endl; // Buscar el tonelaje que mas se repite
    ss << "15) Saber el porcentaje de ocupacion del parqueo" << endl;
    ss << "16) Mostrar la informacion de los vehiculos que han estado en un determinado campo" << endl;
    ss << "17) Mostrar la informacion de todos los vehiculos que han estado en el parqueo" << endl;
    ss << "18) Mostrar los vehiculos que se encuentran en el rango de tonelaje de 1.0 a 1.5" << endl;
    ss << "19) Salir" << endl;
    ss << "Ingrese una opcion: ";
    return ss.str();
}