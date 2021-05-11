#include "comida.h"
#include "almuerzo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mostrarComidas(eComida listadoComidas[], int tamanioListadoComidas)
{
    int todoOk = 1;
    printf("------------- Comidas -----------------\n");
    printf("--Id-----Descripcion--------Precio----\n");
    printf("----------------------------------------\n");
    for(int i= 0; i < tamanioListadoComidas; i++)
    {
        mostrarComida(listadoComidas[i]);
        printf("\n");
    }
    system("pause");
    return todoOk;
}


int mostrarComida(eComida unaComida)
{
    printf("%5d     %10s         %5.2f", unaComida.id, unaComida.descripcion, unaComida.precio);
    return 0;
}

int validarIdComida(eComida listadoComidas[], int tamanioListadoComidas, int idABuscar)
{
    int todoOk = 0;

    if(listadoComidas != NULL && tamanioListadoComidas > 0)
    {
        for(int i= 0; i < tamanioListadoComidas; i ++)
        {
            if(listadoComidas[i].id == idABuscar)
            {
                todoOk = 1;
                break;
            }
        }
    }
   return todoOk;
}

int cargarDescripcionComida(int idComida, eComida listadoComidas[], int tamanioListadoComidas, char descripcion[])
{
    int todoOk = 0;
    if(idComida > 0 && listadoComidas != NULL && tamanioListadoComidas > 0 && descripcion != NULL)
    {
        for(int i= 0; i < tamanioListadoComidas; i++)
        {
            if(listadoComidas[i].id == idComida)
            {
                strcpy(descripcion, listadoComidas[i].descripcion);
                todoOk = 1;
                break;
            }
        }
    }

    return todoOk;
}
