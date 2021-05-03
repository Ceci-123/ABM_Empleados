#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libreria.h"
//#include "datawarehouse.h"
#define TAM 8


int main()
{
    // variables
    char salir = 'n';
    int nextLegajo = 200;
    int devolucion;
    eEmpleado nomina[TAM];
    int flagCarga = 0;

    //inicializo todo
    inicializarEmpleado(nomina, TAM);
    harcodear(nomina, TAM, 5, &nextLegajo);


    do {

	        switch(menu())
	        {
	            case 1:
	            printf("ALTA DE EMPLEADO - Legajo N° %d \n ", nextLegajo);
	            devolucion = altaEmpleado(nomina, TAM, &nextLegajo);
	            if(devolucion)
                {
                    printf("ALTA DE EMPLEADO exitosa\n ");
                    system("pause");
                    cambiarFlag(&flagCarga);
                }
                else
                {
                    printf("ALTA DE EMPLEADO con error\n ");
                    system("pause");
                }
	            break;

	            case 2:
	            printf("BAJA de empleado\n");
	            if(!flagCarga)
                {
                    printf("No hay empleados cargados, no pueden realizarse bajas\n");
                    system("pause");
                }
                else
                {
	            devolucion = bajaEmpleado(nomina, TAM);
	            if(devolucion == 1)
                  {
                    printf("BAJA de empleado exitosa\n");
                    system("pause");
                   }
                else if(devolucion == 2)
                   {
                     printf("Baja cancelada por el usuario\n");
                     system("pause");
                   }
                 else
                 {
                     printf("Error en la baja\n");
                     system("pause");
                 }

                }

	            break;

	            case 3:
	            printf("Modificar empleado\n");
	            if(!flagCarga)
                {
                    printf("No hay empleados cargados, no pueden efectuarse modificaciones\n");
                    system("pause");
                }
	            else
                {
                    devolucion = modificarEmpleado(nomina, TAM);
	                if(devolucion)
                    {
	                    printf("La modificacion fue exitosa\n");
	                    system("pause");

                    }
                    else
                    {
                        printf("La modificacion no pudo realizarse\n");
	                    system("pause");
                    }

                }

	            break;

	            case 4:
                printf("Lista de empleados\n");
                mostrarEmpleados(nomina, TAM);
                system("pause");
                break;

	            case 5:
                printf("Ordenar los empleados\n");
                system("pause");
                ordenarEmpleadosPorCriterios(nomina, TAM);
                //submenu
	            break;

	            case 6:
                printf("Informes de empleados\n");
                printf("Informes de empleados con submenus\n");
                system("pause");
                break;

	            case 12:
	            printf("seguro que quiere salir? s / n\n");
	            fflush(stdin);
	            scanf("%c", &salir);
	            break;

	            default:
	            printf("Opcion no valida\n");
	            system("pause");
	            break;

	        }   // fin del switch de opciones

	    }while(salir == 'n');  // fin del do while del menu
	    return 0;
}

