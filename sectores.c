#include "sectores.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cargarDescripcionSector(int id, eSector sectores[],int tam, char descripcion[])
{
    int todoOk = -1;

    for(int i= 0; i < tam; i++)
    {
        if(sectores[i].idSector == id)
        {
            strcpy(descripcion, sectores[i].descripcion);
            todoOk = 0;
        }

    }
    return todoOk;
}

int mostrarSector(eSector unSector)
{
    int todoOk = -1;

    printf("  %d      %10s \n", unSector.idSector, unSector.descripcion);
    todoOk = 0;

    return todoOk;
}
int mostrarSectores(eSector listadoSectores[], int tamanio)
{
    int todoOk = -1;

    if(listadoSectores != NULL && tamanio > 0)
    {
        printf("------------ Sectores ------------------ \n");
        printf("--Identificador      Descripcion-------- \n");
        for(int i= 0; i < tamanio; i++)
        {
            mostrarSector(listadoSectores[i]);
            todoOk = 0;
        }
    }
    return todoOk;
}

