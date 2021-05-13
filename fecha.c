#include "fecha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comparaFechas(eFecha f1, eFecha f2)
{
    int igual = 0;
    if(f1.dia == f2.dia && f1.mes == f2.mes && f1.anio == f2.anio)
    {
        igual = 1;
    }
    return igual;
}
