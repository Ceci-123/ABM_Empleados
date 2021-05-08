#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"
#include "sectores.h"
#include "informes.h"
#include "comida.h"
//#include "almuerzo.h"

#define TAM 10
#define TAMSECTOR 5
#define TAMC 5
#define TAMA 30

int main()
{
    // variables
    char salir = 'n';
    int nextLegajo = 200;
    int nextIdAlmuerzo = 50000;
    int devolucion;
    eEmpleado nomina[TAM];   //listado de empleados
    int flagCarga = 0;
    int opcion;
    //listado de sectores
    eSector sectores[TAMSECTOR] = {{500, "Sistemas"},{501, "Legales"},{502, "RRHH"},{503, "Contable"},{504, "Ventas"}};
    //listado de comidas
    eComida comidas[TAMC] = {{1000, "Milanesa", 150},
                            {1001, "Ensalada", 190},
                            {1002, "Fideos", 140},
                            {1003, "Pizza", 120},
                            {1004, "Sopa", 110}};

    eAlmuerzo almuerzos[TAMA];

    //inicializo todo
    inicializarEmpleado(nomina, TAM);
    harcodear(nomina, TAM, 8, &nextLegajo, sectores);
    flagCarga = 1; // porque hardcodeo
    inicializarAlmuerzo(almuerzos, TAMA, nextIdAlmuerzo);


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
	            devolucion = bajaEmpleado(nomina, TAM, sectores, TAMSECTOR);
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
                    devolucion = modificarEmpleado(nomina, TAM, sectores, TAMSECTOR);
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
                mostrarEmpleados(nomina, TAM, sectores, TAMSECTOR);
                system("pause");
                break;

	            case 5:
                ordenarEmpleadosPorCriterios(nomina, TAM, sectores, TAMSECTOR);
                break;

	            case 6:
                printf("  --------Informes----------\n");
                printf(" * Elija que informe desea solicitar\n");
                printf(" * Si desea mostrar los sectores ingrese 1: \n");
                printf(" * Si desea listar empleados separados por sector ingrese 2: \n");
                printf(" * Si desea listar empleados de todos los sectores, ingrese 3: \n");
                printf(" * Si desea los sueldos de cada sector, ingrese 4: \n");
                printf(" * Total a depositar, ingrese 5: \n");
                printf(" * Sector con sueldos mas altos, ingrese 6: \n");
                scanf("%d", &opcion);
                       switch(opcion)
                       {
                        case 1:
                        mostrarSectores(sectores, TAMSECTOR);
                        system("pause");
                        break;
                        case 2:
                        listarEmpleadosSector(nomina, TAM, sectores, TAMSECTOR);
                        break;
                        case 3:
                        listarEmpleadosAllSector(nomina, TAM, sectores, TAMSECTOR);
                        break;
                        case 4:
                        totalSueldosSector(nomina, TAM, sectores, TAMSECTOR);
                        break;
                        case 5:
                        totalADepositar(nomina, TAM, sectores, TAMSECTOR);
                        break;
                        case 6:
                        sectorMayorSueldo(nomina, TAM, sectores, TAMSECTOR);
                        break;
                        }

                break;

                case 7:  // comidas
                    printf("Mostrar comidas ingrese 1\n");
                    printf("Mostrar almuerzos ingrese 2\n");
                    printf("Alta de almuerzos ingrese 3\n");
                    scanf("%d", &opcion);
                    switch(opcion)
                    {
                    case 1:
                        // mostrar comidas
                        mostrarComidas(comidas, TAMC);
                    break;
                    case 2:
                        // mostrar almuerzo
                    break;
                    case 3:
                        // alta de almuerzo
                        altaAlmuerzo(almuerzos, TAMA, comidas, TAMC, nomina, TAM, sectores, TAMSECTOR, &nextIdAlmuerzo);
                    break;
                    }
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

