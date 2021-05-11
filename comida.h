#include "almuerzo.h"
#include "empleado.h"

#ifndef COMIDA_H_INCLUDED
#define COMIDA_H_INCLUDED

 typedef struct{
        int id;
        char descripcion[20];
        float precio;

 }eComida;

int mostrarComidas(eComida listadoComidas[], int tamanioListadoComidas);

int mostrarComida(eComida unaComida);

int inicializarAlmuerzo(eAlmuerzo listadoDeAlmuerzos[], int tamanioListadoAlmuerzos, int idAlmuerzo);

int altaAlmuerzo(eAlmuerzo listadoDeAlmuerzos[], int tamanioListadoAlmuerzos, eComida listadoDeComidas[], int tamanioListadoComidas, eEmpleado listadoEmpleados[], int tamanioListadoEmpleados, eSector sectoresLista[], int tamanioListadoSectores, int* idAlmuerzo);

int buscarAlmuerzoLibre(eAlmuerzo listadoDeAlmuerzos[], int tamanioListadoAlmuerzos);

int mostrarAlmuerzos(eAlmuerzo listadoDeAlmuerzos[], int tamanioListadoAlmuerzos, eEmpleado listadoEmpleados[], int tamanioListaEmpleados, eComida listadoComidas[], int tamanioListadoComidas);

int mostrarAlmuerzo(eAlmuerzo unAlmuerzo, eEmpleado listadoEmpleados[], int tamanioListaEmpleados, eComida listadoComidas[], int tamanioListadoComidas);

int validarIdComida(eComida listadoComidas[], int tamanioListadoComidas, int idABuscar);

int cargarDescripcionComida(int idComida, eComida listadoComidas[], int tamanioListadoComidas, char descripcion[]);

int mostrarAlmuerzoUnEmpleado(eAlmuerzo listadoDeAlmuerzos[], int tamanioListadoAlmuerzos, eEmpleado listadoEmpleados[], int tamanioListaEmpleados, eComida listadoComidas[], int tamanioListadoComidas, eSector sectoresLista[], int tamanioListadoSectores);

void totalAlmuerzosUnEmpleado(eEmpleado listadoEmpleados[], int tamanioListadoEmpleados, eSector sectoresLista[], int tamanioListadoSectores, eAlmuerzo listadoAlmuerzos[], int tamanioListadoAlmuerzos, eComida listadoComidas[], int tamanioListadoComidas);

void totalAlmuerzosPorSector(eEmpleado listadoEmpleados[], int tamanioListadoEmpleados, eSector sectoresLista[], int tamanioListadoSectores, eAlmuerzo listadoAlmuerzos[], int tamanioListadoAlmuerzos, eComida listadoComidas[], int tamanioListadoComidas);

#endif // COMIDA_H_INCLUDED
