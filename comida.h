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

int altaAlmuerzo(eAlmuerzo listadoDeAlmuerzos[], int tamanioListadoAlmuerzos, eComida listadoDeComidas[], int tamanioListadoComidas, eEmpleado listadoEmpleados[], int tamanioListadoEmpleados, eSector sectoresLista[], int tamanioListadoSectores, int idAlmuerzo);

int buscarAlmuerzoLibre(eAlmuerzo listadoDeAlmuerzos[], int tamanioListadoAlmuerzos);
#endif // COMIDA_H_INCLUDED
