#include "almuerzo.h"
#include "comida.h"
#include "empleado.h"
#include "sectores.h"

#include <stdio.h>
#include <stdlib.h>

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


int altaAlmuerzo(eAlmuerzo listadoDeAlmuerzos[], int tamanioListadoAlmuerzos, eComida listadoDeComidas[], int tamanioListadoComidas, eEmpleado listadoEmpleados[], int tamanioListadoEmpleados, eSector sectoresLista[], int tamanioListadoSectores, int* idAlmuerzo)
{
    int todoOk = -1;
    int idComida;
    int legajo;
    eFecha fecha;
    int almuerzoLibre;
    int devolucionDeValidacion;
    int devolucionDeValidacionEmpleado;
    char descripcionComida[15];
    char nombre[20];

    if(listadoDeAlmuerzos != NULL && tamanioListadoAlmuerzos > 0)
    {
        printf("-----alta de almuerzos-------\n");
        almuerzoLibre = buscarAlmuerzoLibre(listadoDeAlmuerzos, tamanioListadoAlmuerzos);
        if(almuerzoLibre == -1)
        {
            printf("No hay mas almuerzos libres para ingresar");
        }
        else
        {
            // sigo adelante
        mostrarComidas(listadoDeComidas, tamanioListadoComidas);
        printf("Ingrese el id de la comida deseada: ");
        scanf("%d", &idComida);
        devolucionDeValidacion = validarIdComida(listadoDeComidas, tamanioListadoComidas, idComida);
        if(devolucionDeValidacion == 0)  // valida que exista ese id
        {
           printf("Error, reingrese el id de la comida deseada: ");
           scanf("%d", &idComida);
           devolucionDeValidacion = validarIdComida(listadoDeComidas, tamanioListadoComidas, idComida);
        }
        mostrarEmpleados(listadoEmpleados, tamanioListadoEmpleados, sectoresLista, tamanioListadoSectores);
        printf("Ingrese el legajo del empleado: ");
        scanf("%d", &legajo);
        devolucionDeValidacionEmpleado = buscarEmpleado(legajo, listadoEmpleados, tamanioListadoEmpleados);
             // validar q el legajo exista con buscar empleado
            if(devolucionDeValidacionEmpleado == -1)
             {
                 printf("Error, rengrese el legajo del empleado: ");
                 scanf("%d", &legajo);
                 devolucionDeValidacionEmpleado = buscarEmpleado(legajo, listadoEmpleados, tamanioListadoEmpleados);
             }
             printf("Ingrese fecha con formato dd/mm/aaaa\n");
             scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);

        listadoDeAlmuerzos[almuerzoLibre].isEmpty = 0;
        listadoDeAlmuerzos[almuerzoLibre].idComida = idComida;
        listadoDeAlmuerzos[almuerzoLibre].legEmpleado = legajo;
        listadoDeAlmuerzos[almuerzoLibre].fecha.dia = fecha.dia;
        listadoDeAlmuerzos[almuerzoLibre].fecha.mes = fecha.mes;
        listadoDeAlmuerzos[almuerzoLibre].fecha.anio = fecha.anio;
        listadoDeAlmuerzos[almuerzoLibre].id = *idAlmuerzo;
        (*idAlmuerzo) ++;

        cargarDescripcionComida(idComida, listadoDeComidas, tamanioListadoComidas, descripcionComida);
        cargarNombreEmpleado(legajo, listadoEmpleados, tamanioListadoEmpleados, nombre);
        printf("\n\n---Id de la comida: %d %s \nEmpleado legajo:%d %s \nFecha: %d/%d/%d\n  Id de almuerzo: %d   ---\n",
               listadoDeAlmuerzos[almuerzoLibre].idComida, descripcionComida,
               listadoDeAlmuerzos[almuerzoLibre].legEmpleado, nombre,
               listadoDeAlmuerzos[almuerzoLibre].fecha.dia, listadoDeAlmuerzos[almuerzoLibre].fecha.mes,
               listadoDeAlmuerzos[almuerzoLibre].fecha.anio, listadoDeAlmuerzos[almuerzoLibre].id);
        system("pause");
        }

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

int mostrarAlmuerzos(eAlmuerzo listadoDeAlmuerzos[], int tamanioListadoAlmuerzos, eEmpleado listadoEmpleados[], int tamanioListaEmpleados, eComida listadoComidas[], int tamanioListadoComidas)
{
    int todoOk = -1;
    int flag = 0;

    printf("-------------------------Listado de Almuerzos------------------------\n");
    printf(" id comida nombre Comida legajo Nombre empleado   fecha   id almuerzo\n");
    printf("---------------------------------------------------------------------\n");
    if(listadoDeAlmuerzos != NULL && tamanioListadoAlmuerzos > 0)
    {
      for(int i= 0; i < tamanioListadoAlmuerzos; i++)
      {
          if(listadoDeAlmuerzos[i].isEmpty == 0)
            {
              mostrarAlmuerzo(listadoDeAlmuerzos[i], listadoEmpleados, tamanioListaEmpleados, listadoComidas, tamanioListadoComidas);
              flag = 1;
              todoOk = 0;
            }
       }

   }
   if(flag == 0)
   {
       printf("------------------ No hay almuerzos que mostrar  ------------------------\n");

   }
    system("pause");
    return todoOk;
}

int mostrarAlmuerzo(eAlmuerzo unAlmuerzo, eEmpleado listadoEmpleados[], int tamanioListaEmpleados, eComida listadoComidas[], int tamanioListadoComidas)
{
    char nombre[15];
    char descripcion[15];

    cargarDescripcionComida(unAlmuerzo.idComida, listadoComidas, tamanioListadoComidas, descripcion);
    cargarNombreEmpleado(unAlmuerzo.legEmpleado, listadoEmpleados, tamanioListaEmpleados, nombre);
    printf("%d        %s     %d    %s      %d/%d/%d    %d\n", unAlmuerzo.idComida, descripcion,
                unAlmuerzo.legEmpleado, nombre,
                unAlmuerzo.fecha.dia, unAlmuerzo.fecha.mes,
                unAlmuerzo.fecha.anio, unAlmuerzo.id);
    return 0;
}

int mostrarAlmuerzoUnEmpleado(eAlmuerzo listadoDeAlmuerzos[], int tamanioListadoAlmuerzos, eEmpleado listadoEmpleados[], int tamanioListaEmpleados, eComida listadoComidas[], int tamanioListadoComidas, eSector sectoresLista[], int tamanioListadoSectores)
{
    int cualEmpleado;

    printf("Ingrese legajo del Empleado que desea listar almuerzos\n");
    mostrarEmpleados(listadoEmpleados, tamanioListaEmpleados, sectoresLista, tamanioListadoSectores);
    scanf("%d", &cualEmpleado);
    for(int i= 0; i < tamanioListadoAlmuerzos; i++)
    {
        if(listadoDeAlmuerzos[i].legEmpleado == cualEmpleado && listadoDeAlmuerzos[i].isEmpty == 0)
        {
            mostrarAlmuerzo(listadoDeAlmuerzos[i], listadoEmpleados, tamanioListaEmpleados, listadoComidas, tamanioListadoComidas);
            system("pause");
        }
    }
    return 0;
}


void totalAlmuerzosUnEmpleado(eEmpleado listadoEmpleados[], int tamanioListadoEmpleados, eSector sectoresLista[], int tamanioListadoSectores, eAlmuerzo listadoAlmuerzos[], int tamanioListadoAlmuerzos, eComida listadoComidas[], int tamanioListadoComidas)
{
  float acumulador = 0;
  int cualEmpleado;
  int identificadorComida;
  char nombre[20];

  printf("total a pagar almuerzos de un empleado");
  printf("De que empleado desea calcular?");
  mostrarEmpleados(listadoEmpleados, tamanioListadoEmpleados, sectoresLista, tamanioListadoSectores);
  printf("ingrese legajo");
  scanf("%d", &cualEmpleado);
  for(int i= 0; i < tamanioListadoAlmuerzos; i++)
  {
      if(listadoAlmuerzos[i].legEmpleado == cualEmpleado && listadoAlmuerzos[i].isEmpty == 0)
      {
          identificadorComida = listadoAlmuerzos[i].idComida;
          for(int j= 0; j < tamanioListadoComidas; j++)
          {
              if(listadoComidas[j].id == identificadorComida)
              {
                  acumulador = acumulador + listadoComidas[j].precio;
              }
          }
      }
  }
      cargarNombreEmpleado(cualEmpleado, listadoEmpleados, tamanioListadoEmpleados, nombre);
      printf("el empleado legajo %d %s gasto un total de $ %.2f en sus almuerzos\n", cualEmpleado, nombre, acumulador);
      system("pause");
}

void totalAlmuerzosPorSector(eEmpleado listadoEmpleados[], int tamanioListadoEmpleados, eSector sectoresLista[], int tamanioListadoSectores, eAlmuerzo listadoAlmuerzos[], int tamanioListadoAlmuerzos, eComida listadoComidas[], int tamanioListadoComidas)
{
    int cualSector;
    int legajoABuscar;
    float acumulador;
    char descripcion[15];
    int comidaABuscar;

    printf("Ingrese de cual sector desea calcular el gasto de almuerzos\n");
    mostrarSectores(sectoresLista, tamanioListadoSectores);
    scanf("%d", &cualSector);
    for(int i= 0; i < tamanioListadoEmpleados; i ++)
    {
        if(listadoEmpleados[i].idSector == cualSector)
        {
           legajoABuscar = listadoEmpleados[i].legajo; //este empleado es de ese sector
           for(int j = 0; j < tamanioListadoAlmuerzos; j ++)
           {
               if(listadoAlmuerzos[j].legEmpleado == legajoABuscar) //encuentro un almuerzo de ese empleado
               {
                   comidaABuscar = listadoAlmuerzos[j].idComida; //esta id de comida tengo q sumar
                   for(int k = 0; k < tamanioListadoComidas; k ++) // recorro array de comidas
                   {
                       if(comidaABuscar == listadoComidas[k].id)
                       {
                          acumulador = acumulador * listadoComidas[k].precio;

                       }
                   }
               }

           }
        }
    }
    cargarDescripcionSector(cualSector, sectoresLista, tamanioListadoSectores, descripcion);
    printf("El sector %d %s gasto un total de $ %.2f en sus almuerzos\n", cualSector, descripcion, acumulador);
    system("pause");
}


