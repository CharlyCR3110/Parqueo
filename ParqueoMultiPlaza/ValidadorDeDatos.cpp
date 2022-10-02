#include "ValidadorDeDatos.h"

bool validarHora(int hora, int minutos, int segundos)
{
    if (hora >= 0 && hora <= 23) {
        if (minutos >= 0 && minutos <= 59) {
            if (segundos >= 0 && segundos <= 59) {
                return true;
            }
        }
    }
    return false;
}