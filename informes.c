#include "informes.h"
#include "libreria.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void listarEmpleadosSector(eEmpleado listadoEmpleados[], int tamanioListadoEmpleados, eSector sectoresLista[], int tamanioListadoSectores)
{
    //int opcion;
    char descripcion[20];
    int devolucion;
    int idSector;
    int indice;
    int flag = 0;

    printf("Informe de los empleados de un sector \n");
    mostrarSectores(sectoresLista, tamanioListadoSectores);
    printf("Ingrese id de sector : ");
    scanf("%d", &idSector);
    printf("su opcion es %d ", idSector);
    indice = buscarSector(idSector, sectoresLista, tamanioListadoSectores);
//    while(indice == -1 )
//    {
//       printf("Sector no valido, reingrese de que sector desea saber los empleados?: ");
//       scanf("%d", &idSector);
//       indice = buscarSector(idSector, sectoresLista, tamanioListadoSectores);
//    }
    devolucion = cargarDescripcionSector(idSector, sectoresLista, tamanioListadoSectores, descripcion);
    printf("\nEl sector elegido es: %s\n\n",descripcion);
    printf("lo que me devuelve la funcion es %d", devolucion);
    system("pause");
    printf("------------- NOMINA DE EMPLEADOS sector %s------------------\n", sectoresLista[indice].descripcion);
    printf("nombre    legajo   edad   sueldo   sexo  numero de sector  fecha de ingreso\n");
    for(int i= 0; i < tamanioListadoEmpleados; i++)
    {
        if(listadoEmpleados[i].idSector == idSector && listadoEmpleados[i].isEmpty == 0)
        {

            mostrarEmpleado(listadoEmpleados[i], sectoresLista, tamanioListadoSectores);
            system("pause");
            flag = 1;
        }

    }

    if(flag == 0)
    {
        printf("No hay empleados en el sector %s", sectoresLista[indice].descripcion);
    }
}


int listarEmpleadosAllSector(eEmpleado listadoEmpleados[], int tamanioListadoEmpleados, eSector sectoresLista[], int tamanioListadoSectores)
{
    int flag;

    printf("------------- Listado de empleados por sector --------------------------\n");
    for(int i= 0; i < tamanioListadoSectores; i++)
    {
        flag = 1;
        printf("Sector : %s \n", sectoresLista[i].descripcion);
        system("pause");

        // recorre el array de empleados
        for(int j= 0; j < tamanioListadoEmpleados; j ++)
        {
            if(listadoEmpleados[j].idSector == sectoresLista[i].idSector && listadoEmpleados[j].isEmpty == 1)
            {
                mostrarEmpleado(listadoEmpleados[j], sectoresLista, tamanioListadoSectores);
                flag = 0;
            }
        }
                printf("---------------------------------------");
                system("pause");
    }
    if(flag == 1)
    {
        //no hay empleados
        printf("no hay empleados en este sector\n ");
        system("pause");
    }
    return 0;
}

int buscarSector(int idSector, eSector sectores[], int tamanioVector)
{
    int indice = -1;
    for(int i = 0; i < tamanioVector; i++)
    {
        if(sectores[i].idSector == idSector)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

//void totalSueldosSector(eEmpleado listadoEmpleados, int tamanioListadoEmpleados, eSector sectoresLista, int tamanioListadoSectores);
// void totalADepositar(eEmpleado listadoEmpleados, int tamanioListadoEmpleados, eSector sectoresLista, int tamanioListadoSectores);


