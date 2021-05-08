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

int inicializarAlmuerzo(eAlmuerzo listadoDeAlmuerzos[], int tamanioListadoAlmuerzos, int idAlmuerzo)
{
    int todoOk = -1;
    if(listadoDeAlmuerzos != NULL && tamanioListadoAlmuerzos > 0)
    {
        for(int i= 0; i < tamanioListadoAlmuerzos; i++)
        {
        listadoDeAlmuerzos[i].isEmpty = 1;
        listadoDeAlmuerzos[i].id = idAlmuerzo;
        idAlmuerzo ++;

        }
        todoOk = 0;
    }

    return todoOk;

}

int altaAlmuerzo(eAlmuerzo listadoDeAlmuerzos[], int tamanioListadoAlmuerzos, eComida listadoDeComidas[], int tamanioListadoComidas, eEmpleado listadoEmpleados[], int tamanioListadoEmpleados, eSector sectoresLista[], int tamanioListadoSectores, int idAlmuerzo)
{
    int todoOk = -1;
    int idComida;
    int legajo;
    eFecha fecha;
    int almuerzoLibre;

    if(listadoDeAlmuerzos != NULL && tamanioListadoAlmuerzos > 0)
    {
        mostrarComidas(listadoDeComidas, tamanioListadoComidas);
        printf("Ingrese el id de la comida deseada: ");
        scanf("%d", &idComida);
        mostrarEmpleados(listadoEmpleados, tamanioListadoEmpleados, sectoresLista, tamanioListadoSectores);
        printf("Ingrese el legajo del empleado: ");
        scanf("%d", &legajo);
        printf("Ingrese fecha con formato dd/mm/aaaa\n");
        scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
        almuerzoLibre = buscarAlmuerzoLibre(listadoDeAlmuerzos, tamanioListadoAlmuerzos);
        listadoDeAlmuerzos[almuerzoLibre].idComida = idComida;
        listadoDeAlmuerzos[almuerzoLibre].legEmpleado = legajo;
        listadoDeAlmuerzos[almuerzoLibre].fecha.dia = fecha.dia;
        listadoDeAlmuerzos[almuerzoLibre].fecha.mes = fecha.mes;
        listadoDeAlmuerzos[almuerzoLibre].fecha.anio = fecha.anio;
        listadoDeAlmuerzos[almuerzoLibre].id = idAlmuerzo;
        idAlmuerzo ++;
        printf("%d, %d %d/%d/ %d  %d", listadoDeAlmuerzos[almuerzoLibre].idComida, listadoDeAlmuerzos[almuerzoLibre].legEmpleado,
               listadoDeAlmuerzos[almuerzoLibre].fecha.dia, listadoDeAlmuerzos[almuerzoLibre].fecha.mes,
               listadoDeAlmuerzos[almuerzoLibre].fecha.anio, listadoDeAlmuerzos[almuerzoLibre].id);
        system("pause");
    }

    return todoOk;
}

int buscarAlmuerzoLibre(eAlmuerzo listadoDeAlmuerzos[], int tamanioListadoAlmuerzos)
{
    int vacio;

    for(int i= 0; i < tamanioListadoAlmuerzos; i++)
    {
        if(listadoDeAlmuerzos[i].isEmpty == 1)
        {
            vacio = i;
            break;
        }
    }
    return vacio;
}
