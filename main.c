#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libreria.h"
#define TAM 5


int main()
{
    // variables
    char salir = 'n';
    int nextLegajo = 200;
    int devolucion;
    eEmpleado nomina[TAM];
    inicializarEmpleado(nomina, TAM);
    int respuesta;
    char opcion;
    int flagCarga = 0;

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
                    printf("No hay empleados cargados\n");
                    system("pause");
                }
                else
                {

                mostrarEmpleados(nomina, TAM);
	            printf("\n\n");
	            printf("Cual es el numero de legajo para dar de baja?\n");
	            scanf("%d", &respuesta);
	            printf("Esta seguro que desea dar de baja al empleado con legajo %d  s/n ?\n", respuesta);
                fflush(stdin);
                scanf("%c", &opcion);
                if(opcion == 's')
                {
	               devolucion = bajaEmpleado(nomina, TAM, respuesta);
	               if(devolucion)
                        {
                         printf("BAJA de empleado exitosa\n");
                         system("pause");
                        }
                   else
                       {
                        printf("no pudo realizarse la baja\n");
                        system("pause");
                       }
                }
                else
                {
                    printf("no pudo realizarse la baja\n");
                    system("pause");
                }
                }

	            break;

	            case 3:
	            printf("Modificar empleado\n");
	            if(!flagCarga)
                {
                    printf("No hay empleados cargados\n");
                    system("pause");
                }
	            else
                {
                    mostrarEmpleados(nomina, TAM);
	                printf("\n\n");
	                printf("Cual es el numero de legajo para modificar?\n");
	                scanf("%d", &respuesta);
	                //system("pause");
	                printf("Usted esta modificando el numero de legajo %d\n", respuesta);
	                devolucion = modificarEmpleado(nomina, TAM, respuesta);
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

	            case 7:
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

