#include "libreria.h"
#include "datawarehouse.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu(){
    int opcion;
    system("cls");
    printf("        *****************************\n");
    printf("        *****************************\n");
    printf("        *******ABM de Empleados******\n");
    printf("        *****************************\n");
    printf("        *****************************\n");
    printf(" 1. Alta de un empleado\n");
    printf(" 2. Baja de un empleado\n");
    printf(" 3. Modificar un empleado\n");
    printf(" 4. Listar empleados \n");
    printf(" 5. Ordenar empleados\n");
    printf(" 6. Listar sectores\n");
    printf(" 7. \n");
    printf(" 8. \n");
    printf(" 9. \n");
    printf(" 10. \n");
    printf(" 11. Informes de empleados\n");
    printf(" 12. Ingrese para salir del menu \n");
    scanf("%d", &opcion);
    return opcion;

}


void mostrarEmpleado(eEmpleado unEmpleado)
{

    printf("%10s %02d     %02d    %.2f    %c    %02d     %02d/%02d/%d"
           , unEmpleado.nombre, unEmpleado.legajo, unEmpleado.edad, unEmpleado.sueldo, unEmpleado.sexo
           , unEmpleado.idSector, unEmpleado.fechaIngreso.dia, unEmpleado.fechaIngreso.mes,unEmpleado.fechaIngreso.anio);
    printf("\n");
}

void mostrarEmpleados(eEmpleado lista[], int tamanio){

    int flag = 1;
    printf("------------- NOMINA DE EMPLEADOS ------------------\n");
    printf("nombre    legajo   edad   sueldo   sexo  numero de sector  fecha de ingreso\n");
    for(int i=0; i< tamanio; i++)
    {
        if(!lista[i].isEmpty)
        {
           mostrarEmpleado(lista[i]);
           flag = 0;
        }

    }
    if(flag)
        {
            printf("No hay empleados ingresados\n");
        }


}

void ordenarEmpleados(eEmpleado lista[], int tamanio)
{
    eEmpleado auxiliarEmpleado;

    for(int i= 0; i < tamanio -1; i++)
    {
        for(int j= i+1; j < tamanio; j++)
        {
            if(lista[i].sexo > lista[j].sexo || (lista[i]. sexo == lista[j]. sexo && strcmp(lista[i].nombre, lista[j].nombre) > 0)) // criterios
            {
                //hacer swap
                auxiliarEmpleado = lista[i];
                lista[i] = lista[j];
                lista[j] = auxiliarEmpleado;

            }

        }  // segundo for

    }  // primer for
}

void inicializarEmpleado(eEmpleado lista[], int tamanio){
    for(int i = 0; i < tamanio; i++)
    {
        lista[i].isEmpty = 1;
    }


}

int altaEmpleado(eEmpleado lista[], int tamanio,int* legajo)
{
    int todoOk = 0;
    int respuestaLibre;
    eEmpleado auxiliar;

    if(lista != NULL && tamanio > 0 && legajo != NULL)
    {
       respuestaLibre = buscarLibre(lista, tamanio);
    if(respuestaLibre == -1)
   {
        // no hay lugar
        printf("No tiene posiciones disponibles en el array\n");
    }
    else
    {
        //pido datos
        printf("Ingrese nombre\n");
        fflush(stdin);
        gets(auxiliar.nombre);
        printf("Ingrese edad\n");
        scanf("%d", &auxiliar.edad);
        while(auxiliar.edad < 0 || auxiliar.edad > 100)
        {
            printf("Ingrese edad\n");
            scanf("%d", &auxiliar.edad);
        }
        printf("Ingrese sueldo\n");
        scanf("%f", &auxiliar.sueldo);
        while(auxiliar.sueldo < 0)
        {
            printf("Ingrese sueldo\n");
            scanf("%f", &auxiliar.sueldo);
        }
        printf("Ingrese sector al que pertenece\n");
        scanf("%d", &auxiliar.idSector);
        while(auxiliar.idSector < 500 || auxiliar.idSector > 504)
        {
            printf("Error, Ingrese sector al que pertenece\n");
            scanf("%d", &auxiliar.idSector);
        }
        printf("Ingrese sexo f/m\n");
        fflush(stdin);
        scanf("%c", &auxiliar.sexo);
        while(auxiliar.sexo != 'f' && auxiliar.sexo != 'm')
        {
           printf("Ingrese sexo f/m\n");
           fflush(stdin);
           scanf("%c", &auxiliar.sexo);

        }
        printf("Ingrese fecha de alta con formato dd/mm/aaaa\n");
        scanf("%d/%d/%d", &auxiliar.fechaIngreso.dia, &auxiliar.fechaIngreso.mes, &auxiliar.fechaIngreso.anio);
        while(auxiliar.fechaIngreso.dia < 1 || auxiliar.fechaIngreso.dia > 31 || auxiliar.fechaIngreso.mes < 1
              || auxiliar.fechaIngreso.mes > 12)
        {
            printf("Ingrese fecha de alta con formato dd/mm/aaaa\n");
            scanf("%d/%d/%d", &auxiliar.fechaIngreso.dia, &auxiliar.fechaIngreso.mes, &auxiliar.fechaIngreso.anio);

        }
        auxiliar.legajo = *legajo;
        (*legajo)++;
        auxiliar.isEmpty = 0;
        lista[respuestaLibre] = auxiliar;
        todoOk = 1;
    }
    }

    return todoOk;
}
int buscarLibre(eEmpleado lista[], int tamanio)
{
    int vacio = -1;
    if(lista != NULL && tamanio > 0)
    {
       for(int i= 0; i < tamanio;i++)
       {
         if(lista[i].isEmpty)
         {
                vacio= i;
                break;  // si ya encontre, puedo dejar de buscar
         } // fin del if que busca
        } // fin del for que recorre
    } // if validacion
     return vacio;
}

int buscarEmpleado(int legajo, eEmpleado lista[], int tamanio)  // devuelve indice
{
    int indice = -1;
    if(lista != NULL && tamanio > 0)
    {
       for(int i= 0; i < tamanio;i++)
       {
         if(lista[i].legajo == legajo && !lista[i].isEmpty)
         {
                indice = i;
                break;  // si ya encontre, puedo dejar de buscar
         } // fin del if que busca
        } // fin del for que recorre
    } // if validacion
     return indice;
}

int bajaEmpleado(eEmpleado lista[], int tamanio)
{
    int todoOk = 0;
    int respuesta;
    char opcion;
    int indice;

    mostrarEmpleados(lista, tamanio);
    printf("\n\n");
    printf("Cual es el numero de legajo para dar de baja?\n");
	scanf("%d", &respuesta);
	indice = buscarEmpleado(respuesta, lista, tamanio);
	mostrarEmpleado(lista[indice]);
	printf("Esta seguro que desea dar de baja al empleado con legajo %d  s/n ?\n", respuesta);
    fflush(stdin);
    scanf("%c", &opcion);
    if(opcion == 's')
    {
        lista[indice].isEmpty = 1;
        todoOk = 1;

    }
    else
    {
        printf("Se ha cancelado la baja\n");
        todoOk = 2;
    }
    return todoOk;

}

void cambiarFlag(int* bandera){

     if(bandera != NULL)
     {
        *bandera = 1;
     }

}

int modificarEmpleado(eEmpleado lista[], int tamanio)
{
    int todoOk = 0;
    int cualSeModifica;
    int opcion;
    eEmpleado auxiliar;
    int respuesta;

          mostrarEmpleados(lista, tamanio);
	      printf("\n\n");
	      printf("Cual es el numero de legajo para modificar?\n");
	      scanf("%d", &respuesta);
	      printf("Usted esta modificando el numero de legajo %d\n", respuesta);

    if(lista != NULL && tamanio > 0 && respuesta >0)
    {
        cualSeModifica = buscarEmpleado(respuesta, lista, tamanio);
        mostrarEmpleado(lista[cualSeModifica]);
        system("pause");
        printf("Si desea corregir el nombre ingrese 1\n");
        printf("Si desea corregir el sexo ingrese 2\n");
        printf("Si desea corregir el sueldo ingrese 3\n");
        printf("Si desea corregir la fecha de ingreso ingrese 4\n");
        printf("Si desea corregir la edad ingrese 5\n");
        printf("Si desea corregir el sector ingrese 6\n");
        scanf("%d", &opcion);
        switch(opcion)
        {
       case 1:
           printf("Re ingrese el nombre\n");
           fflush(stdin);
           gets(auxiliar.nombre);
           printf("%s\n", auxiliar.nombre);
           strcpy(lista[cualSeModifica].nombre,auxiliar.nombre);
            todoOk = 1;
        break;
       case 2:
           printf("Re ingrese sexo f/m\n");
           fflush(stdin);
           scanf("%c", &auxiliar.sexo);
           lista[cualSeModifica].sexo = auxiliar.sexo;
           while(auxiliar.sexo != 'f' && auxiliar.sexo != 'm')
           {
           printf("Re ingrese sexo f/m\n");
           fflush(stdin);
           scanf("%c", &auxiliar.sexo);
           lista[cualSeModifica].sexo = auxiliar.sexo;
           }
        todoOk = 1;
        break;
       case 3:
           printf("Re ingrese sueldo\n");
           scanf("%f", &auxiliar.sueldo);
           lista[cualSeModifica].sueldo = auxiliar.sueldo;
           while(auxiliar.sueldo < 0)
            {
            printf("Re ingrese sueldo\n");
            scanf("%f", &auxiliar.sueldo);
            lista[cualSeModifica].sueldo = auxiliar.sueldo;
            }
         todoOk = 1;
        break;
       case 4:
           printf("Re ingrese fecha de alta con formato dd/mm/aaaa\n");
           scanf("%d/%d/%d", &auxiliar.fechaIngreso.dia, &auxiliar.fechaIngreso.mes, &auxiliar.fechaIngreso.anio);
           lista[cualSeModifica].fechaIngreso = auxiliar.fechaIngreso;
           while(auxiliar.fechaIngreso.dia < 1 || auxiliar.fechaIngreso.dia > 31 || auxiliar.fechaIngreso.mes < 1
              || auxiliar.fechaIngreso.mes > 12)
           {
            printf("Ingrese fecha de alta con formato dd/mm/aaaa\n");
            scanf("%d/%d/%d", &auxiliar.fechaIngreso.dia, &auxiliar.fechaIngreso.mes, &auxiliar.fechaIngreso.anio);
            lista[cualSeModifica].fechaIngreso = auxiliar.fechaIngreso;
           }
       todoOk = 1;
       break;
       case 5:
           printf("Re ingrese edad\n");
           scanf("%d", &auxiliar.edad);
           while(auxiliar.edad < 0 || auxiliar.edad > 100)
           {
            printf("Re ingrese edad\n");
            scanf("%d", &auxiliar.edad);
            printf("%d", auxiliar.edad);
            lista[cualSeModifica].edad = auxiliar.edad;
            }
        todoOk = 1;
        break;
        case 6:
           printf("Re ingrese el sector al que pertenece\n");
           scanf("%d", &auxiliar.idSector);
           //validar
           lista[cualSeModifica].idSector = auxiliar.idSector;

        todoOk = 1;
        break;
       default:
           printf("opcion no valida\n");
        break;
        }

}
           return todoOk;
}

void ordenarEmpleadosPorCriterios(eEmpleado lista[], int tamanio)
{
    int opcion;
    eEmpleado auxiliarEmpleado;

    printf("Si desea ordenar por orden alfabetico ascendente ingrese 1\n");
    printf("Si desea ordenar por orden alfabetico descendente ingrese 2\n");
    printf("Si desea ordenar por sueldo ascendente ingrese 3\n");
    printf("Si desea ordenar por sueldo descendente ingrese 4\n");
    printf("Si desea ordenar por sexo ingrese 5\n");
    printf("Si desea ordenar por edad ascendente ingrese 6\n");
    printf("Si desea ordenar por edad descendente ingrese 7\n");
    printf("Si desea ordenar por sector ingrese 8\n");
    scanf("%d", &opcion);
    switch(opcion)
    {
    case 1:
    for(int i= 0; i < tamanio -1; i++)
    {
        for(int j= i+1; j < tamanio; j++)
        {
            if(strcmp(lista[i].nombre, lista[j].nombre) > 0)
            {
                auxiliarEmpleado = lista[i];
                lista[i] = lista[j];
                lista[j] = auxiliarEmpleado;

            }

        }  // segundo for

    }  // primer for
    mostrarEmpleados(lista, tamanio);
    system("pause");
    break;
    case 2:
        for(int i= 0; i < tamanio -1; i++)
    {
        for(int j= i+1; j < tamanio; j++)
        {
            if(strcmp(lista[i].nombre, lista[j].nombre) < 0)
            {
                auxiliarEmpleado = lista[i];
                lista[i] = lista[j];
                lista[j] = auxiliarEmpleado;

            }

        }  // segundo for

    }  // primer for
    mostrarEmpleados(lista, tamanio);
    system("pause");
    break;
    case 3:
        for(int i= 0; i < tamanio -1; i++)
    {
        for(int j= i+1; j < tamanio; j++)
        {
            if(lista[i].sueldo > lista[j].sueldo)
            {
                auxiliarEmpleado = lista[i];
                lista[i] = lista[j];
                lista[j] = auxiliarEmpleado;

            }

        }  // segundo for

    }  // primer for
    mostrarEmpleados(lista, tamanio);
    system("pause");
    break;
    case 4:
        for(int i= 0; i < tamanio -1; i++)
    {
        for(int j= i+1; j < tamanio; j++)
        {
            if(lista[i].sueldo < lista[j].sueldo)
            {
                auxiliarEmpleado = lista[i];
                lista[i] = lista[j];
                lista[j] = auxiliarEmpleado;

            }

        }  // segundo for

    }  // primer for
    mostrarEmpleados(lista, tamanio);
    system("pause");
    break;
    case 5:
        for(int i= 0; i < tamanio -1; i++)
    {
        for(int j= i+1; j < tamanio; j++)
        {
            if(lista[i].sexo > lista[j].sexo)
            {
                auxiliarEmpleado = lista[i];
                lista[i] = lista[j];
                lista[j] = auxiliarEmpleado;

            }

        }  // segundo for

    }  // primer for
    mostrarEmpleados(lista, tamanio);
    system("pause");
    break;
    case 6:
        for(int i= 0; i < tamanio -1; i++)
    {
        for(int j= i+1; j < tamanio; j++)
        {
            if(lista[i].edad > lista[j].edad )
            {
                auxiliarEmpleado = lista[i];
                lista[i] = lista[j];
                lista[j] = auxiliarEmpleado;

            }

        }  // segundo for

    }  // primer for
    mostrarEmpleados(lista, tamanio);
    system("pause");
    break;
    case 7:
        for(int i= 0; i < tamanio -1; i++)
    {
        for(int j= i+1; j < tamanio; j++)
        {
            if(lista[i].edad < lista[j].edad )
            {
                auxiliarEmpleado = lista[i];
                lista[i] = lista[j];
                lista[j] = auxiliarEmpleado;

            }

        }  // segundo for

    }  // primer for
    mostrarEmpleados(lista, tamanio);
    system("pause");
    break;
    case 8:
        for(int i= 0; i < tamanio -1; i++)
    {
        for(int j= i+1; j < tamanio; j++)
        {
            if(lista[i].idSector < lista[j].idSector )
            {
                auxiliarEmpleado = lista[i];
                lista[i] = lista[j];
                lista[j] = auxiliarEmpleado;

            }

        }  // segundo for

    }  // primer for
    mostrarEmpleados(lista, tamanio);
    system("pause");
    break;

    }
}

int harcodear(eEmpleado lista[], int tamanio, int cantidadACargar, int* pLegajo)
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
            lista[i].idSector = sectores[i];
            lista[i].isEmpty = 0;
            todoOk ++;

        }
    }
       return todoOk;
}



