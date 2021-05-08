#include "empleado.h"

#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED


void listarEmpleadosSector(eEmpleado listadoEmpleados[], int tamanioListadoEmpleados, eSector sectoresLista[], int tamanioListadoSectores);

int listarEmpleadosAllSector(eEmpleado listadoEmpleados[], int tamanioListadoEmpleados, eSector sectoresLista[], int tamanioListadoSectores);

int buscarSector(int idSector, eSector sectores[], int tamanioVector);

int totalSueldosSector(eEmpleado listadoEmpleados[], int tamanioListadoEmpleados, eSector sectoresLista[], int tamanioListadoSectores);

int totalADepositar(eEmpleado listadoEmpleados[], int tamanioListadoEmpleados, eSector sectoresLista[], int tamanioListadoSectores);

int sectorMayorSueldo(eEmpleado listadoEmpleados[], int tamanioListadoEmpleados, eSector sectoresLista[], int tamanioListadoSectores);

#endif // INFORMES_H_INCLUDED


