#include "datawarehouse.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char nombres[10][20] = {"Matias", "Donato", "Claudia", "Marcela", "Sebastian", "German", "Sol","Morena","Carmen","Juan"};
char sexos[10] = {'m','m','f','f','m','m','f','f','f','m'};
int edades[10] = {40,32,56,25,21,56,38,33,37,28};
int idSectores[10] = {501,503,502,500,504,501,504,502,503,502};
float sueldos[10] = {12000, 15000, 34000, 22000, 54000, 32300, 43200, 26424, 32187, 38345};
eFecha fechas[10] = {{12,01,2021},{8,12,2020},{16,04,2019},{01,05,2021},{11,01,2020},{10,11,2018},{5,12,2021},{23,03,2020},{31,06,2020},{15,07,2021}};

eFecha fechas2[] = { {1,1,2021}, {1,1,2021}, {1,1,2021}, {1,1,2021},
                               {1,1,2021}, {1,1,2021}, {2,1,2021}, {2,1,2021},
                               {2,1,2021}, {2,1,2021}, {2,1,2021}, {2,1,2021},
                               {3,1,2021}, {3,1,2021}, {3,1,2021}, {3,1,2021},
                               {3,1,2021}, {3,1,2021},  {4,1,2021}, {4,1,2021},
                               {4,1,2021}, {4,1,2021}, {4,1,2021} };

int legajos[] ={20000,20006,20001,20005,20007,20002,20000,20004,20001,20003,20008,20001,20006,20003,20004,20008,20005,20000,20005,20003,20007,20009,20004};


int idComidas[]={1000,1003,1002,1000,1000,1004,1002,1001,1004,1003,1003,1004,1000,1002,1004,1004,1001,1001,1000,1001,1002,1002,1000};


int harcodear(eEmpleado lista[], int tamanio, int cantidadACargar, int* pLegajo, eSector sectores[])
{
    int todoOk = 0;

    if(lista != NULL && tamanio > 0 && cantidadACargar > 0 && pLegajo != NULL)
    {
        for(int i=0; i < cantidadACargar; i++)
        {
            lista[i].legajo = *pLegajo;
            (*pLegajo) ++;
            strcpy(lista[i].nombre, nombres[i]);
            lista[i].edad = edades[i];
            lista[i].sueldo = sueldos[i];
            lista[i].sexo = sexos[i];
            lista[i].fechaIngreso = fechas[i];
            lista[i].idSector = idSectores[i];
            lista[i].isEmpty = 0;
            todoOk ++;

        }
    }
       return todoOk;
}

int harcodearAlmuerzo(eAlmuerzo lista[], int tamanio, int cantidadACargar, int* pNextId)
{
       int todoOk = 0;

       if(lista != NULL && tamanio > 0 && cantidadACargar > 0 && pNextId != NULL)
       {
           for(int i=0; i < cantidadACargar; i++)
           {
               lista[i].id = *pNextId;
               (*pNextId) ++;
               lista[i].fecha = fechas2[i];
               lista[i].isEmpty = 0;
               lista[i].idComida = idComidas[i];
               lista[i].legEmpleado = legajos[i];
               todoOk = 1;
           }
       }
       return todoOk;
}


