#include "empleado.h"
#include "almuerzo.h"
#include "comida.h"

#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED


void listarEmpleadosSector(eEmpleado listadoEmpleados[], int tamanioListadoEmpleados, eSector sectoresLista[], int tamanioListadoSectores);

int listarEmpleadosAllSector(eEmpleado listadoEmpleados[], int tamanioListadoEmpleados, eSector sectoresLista[], int tamanioListadoSectores);

int buscarSector(int idSector, eSector sectores[], int tamanioVector);

int totalSueldosSector(eEmpleado listadoEmpleados[], int tamanioListadoEmpleados, eSector sectoresLista[], int tamanioListadoSectores);

int totalADepositar(eEmpleado listadoEmpleados[], int tamanioListadoEmpleados, eSector sectoresLista[], int tamanioListadoSectores);

int sectorMayorSueldo(eEmpleado listadoEmpleados[], int tamanioListadoEmpleados, eSector sectoresLista[], int tamanioListadoSectores);

void almuerzosEmpleado(eEmpleado listadoEmpleados[], int tamanioListadoEmpleados, eSector sectoresLista[], int tamanioListadoSectores, eAlmuerzo listadoAlmuerzos[], int tamanioListadoAlmuerzos, eComida listadoComidas[], int tamanioListadoComidas);

void totalAlmuerzoEmpleado(eEmpleado listadoEmpleados[], int tamanioListadoEmpleados, eSector sectoresLista[], int tamanioListadoSectores, eAlmuerzo listadoAlmuerzos[], int tamanioListadoAlmuerzos, eComida listadoComidas[], int tamanioListadoComidas);

#endif // INFORMES_H_INCLUDED


