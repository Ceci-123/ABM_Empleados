#include "informes.h"
#include "empleado.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void listarEmpleadosSector(eEmpleado listadoEmpleados[], int tamanioListadoEmpleados, eSector sectoresLista[], int tamanioListadoSectores)
{
    //int opcion;
    char descripcion[20];
    int idSector;
    int indice;
    int flag = 0;

    printf("Informe de los empleados de un sector \n");
    mostrarSectores(sectoresLista, tamanioListadoSectores);
    printf("Ingrese id de sector : ");
    scanf("%d", &idSector);
    printf("su opcion es %d ", idSector);
    indice = buscarSector(idSector, sectoresLista, tamanioListadoSectores);
    while(indice == -1 )
    {
       printf("Sector no valido, reingrese de que sector desea saber los empleados?: ");
       scanf("%d", &idSector);
       indice = buscarSector(idSector, sectoresLista, tamanioListadoSectores);
    }
    cargarDescripcionSector(idSector, sectoresLista, tamanioListadoSectores, descripcion);
    printf("\nEl sector elegido es: %s\n\n",descripcion);
    printf("------------- NOMINA DE EMPLEADOS sector %s------------------\n", sectoresLista[indice].descripcion);
    printf("nombre    legajo   edad   sueldo   sexo  numero de sector  fecha de ingreso\n");
    for(int i= 0; i < tamanioListadoEmpleados; i++)
    {
        if(listadoEmpleados[i].idSector == idSector && listadoEmpleados[i].isEmpty == 0)
        {

            mostrarEmpleado(listadoEmpleados[i], sectoresLista, tamanioListadoSectores);
            flag = 1;
        }

    }
    system("pause");
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


        // recorre el array de empleados
        for(int j= 0; j < tamanioListadoEmpleados; j ++)
        {
            if(listadoEmpleados[j].idSector == sectoresLista[i].idSector && listadoEmpleados[j].isEmpty == 0)
            {
                mostrarEmpleado(listadoEmpleados[j], sectoresLista, tamanioListadoSectores);
                flag = 0;
            }
        }
                printf("-----------------------------------------------------------\n");
    }
    if(flag == 1)
    {
        //no hay empleados
        printf("no hay empleados en este sector\n ");
        system("pause");
    }
    system("pause");
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

int totalSueldosSector(eEmpleado listadoEmpleados[], int tamanioListadoEmpleados, eSector sectoresLista[], int tamanioListadoSectores)
{
    int opcion;
    float acumuladorDeSueldos = 0;

    mostrarSectores(sectoresLista, tamanioListadoSectores);
    printf("De que sector desea saber el total de sueldos? \n");
    scanf("%d", &opcion);

    for(int i= 0; i < tamanioListadoEmpleados; i++)
    {
        if(listadoEmpleados[i].idSector == opcion && listadoEmpleados[i].isEmpty == 0)
        {
            acumuladorDeSueldos = acumuladorDeSueldos + listadoEmpleados[i].sueldo;
        }
    }
     printf("El total de los sueldos del sector %d es %6.2f\n",opcion, acumuladorDeSueldos);
     system("pause");
     return 0;
}
int totalADepositar(eEmpleado listadoEmpleados[], int tamanioListadoEmpleados, eSector sectoresLista[], int tamanioListadoSectores)
{
    float acumuladorDeSueldos = 0;
    float acumuladorDelAcumulador = 0;

    for(int i=0; i < tamanioListadoSectores; i++)
    {
        printf("------ sector %s ------------------\n", sectoresLista[i].descripcion);
        printf("-----------------------------------\n");
        for(int j=0; j < tamanioListadoEmpleados; j++)
        {
            if(listadoEmpleados[j].idSector == sectoresLista[i].idSector && listadoEmpleados[j].isEmpty == 0)
            {
                acumuladorDeSueldos = acumuladorDeSueldos + listadoEmpleados[i].sueldo;
            }
        }
        printf("Total sueldos del sector %s  es $$ %f\n", sectoresLista[i].descripcion, acumuladorDeSueldos);
        acumuladorDelAcumulador = acumuladorDelAcumulador + acumuladorDeSueldos;
    }

    printf("El total de los sueldos es %6.2f\n", acumuladorDelAcumulador);
    system("pause");
    return 0;
}

int sectorMayorSueldo(eEmpleado listadoEmpleados[], int tamanioListadoEmpleados, eSector sectoresLista[], int tamanioListadoSectores)
{
    float totales[tamanioListadoSectores];
    float totalSueldo = 0;
    float mayor = 0;
    int flag= 0;

     printf("-------Sector que mas gana---------\n");
    for(int s= 0; s < tamanioListadoSectores; s++)
    {
        for(int e= 0; e < tamanioListadoEmpleados; e++)
        {
            if(listadoEmpleados[e].isEmpty == 0 && listadoEmpleados[e].idSector == sectoresLista[s].idSector)
            {
                totalSueldo = totalSueldo + listadoEmpleados[e].sueldo;

            }
        } // fin del for de empleados
      totales[s] = totalSueldo;

    } // fin del for sectores
     for(int i = 0; i < tamanioListadoSectores; i++) // recorro el array de totales
     {
         if(mayor > totales[i] || flag == 0)
         {
             flag = 1;
             mayor = totales[i];
         }
     }

     for(int i = 0; i < tamanioListadoSectores; i++) // recorro de nuevo por si hay empate
     {
         if(mayor == totales[i])
         {
             printf("%s", sectoresLista[i].descripcion);

         }
     }
     printf(" es el sector de sueldos mas altos\n");
     system("pause");
    return 0;
}

