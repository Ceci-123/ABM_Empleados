#include "sectores.h"
#include "fecha.h"

#ifndef LIBRERIA_H_INCLUDED
#define LIBRERIA_H_INCLUDED

/** \brief Muestra un menu de opciones, mientras el usuario no elija salir
 *
 * \return un entero, numero de opcion del menu
 *
 */
int menu(void);


typedef struct{
          int legajo;
          char nombre[20];
          eFecha fechaIngreso;
          int edad;
          char sexo;
          float sueldo;
          int idSector;
          int isEmpty;

} eEmpleado;

/** \brief Muestra un empleado del array
 *
 * \param el empleado que quiero mostrar
 *
 */
void mostrarEmpleado(eEmpleado unEmpleado, eSector listadoSectores[], int tamaniosectores);

/** \brief Muestra todo el array de empleados
 *
 * \param El array de empleados
 * \param El tamaño del array
 *
 */
void mostrarEmpleados(eEmpleado lista[], int tamanio, eSector listadoSectores[], int tamaniosectores);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void ordenarEmpleados(eEmpleado lista[], int tamanio);

/** \brief Asigna al campo isEmpty del array el valor de 1
 *
 * \param El array a inicializar
 * \param El tamaño del array
 *
 */
void inicializarEmpleado(eEmpleado lista[], int tamanio);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int altaEmpleado(eEmpleado lista[], int tamanio, int* plegajo);

/** \brief Asigna al campo isEmpty de un empleado el valor 1
 *
 * \param El array de empleados
 * \param El tamaño del array
 * \return Devuelve 1 si la baja fue exitosa y 0 si la baja no pudo realizarse
 *
 */
int bajaEmpleado(eEmpleado lista[], int tamanio, eSector listadoSectores[], int tamanioListadoSectores);


/** \brief Busca la primera posicion vacia en el array
 *
 * \param El array
 * \param El tamaño del array
 * \return El indice de la posicion libre en el array
 *
 */
int buscarLibre(eEmpleado lista[], int tamanio);

/** \brief
*
* \param
* \param
* \return Devuelve el indice del empleado buscado
*
*/
int buscarEmpleado(int legajo, eEmpleado lista[], int tamanio);

/** \brief  Cambia el estado de una bandera pasandola a valor 1
 *
 * \param La direccion de memoria de la flag
 *
 */
void cambiarFlag(int* bandera);

/** \brief Modifica el registro de un empleado
 *
 * \param Numero de legajo del empleado a modificar
 * \return Devuelve 1 si modifico el registro y 0 si hubo algun error
 *
 */

int modificarEmpleado(eEmpleado lista[], int tamanio, eSector sectores[], int tamanioListadoSectores);

/** \brief Ordena la lista de empleados por diferentes criterios
 *
 * \param La lista a ordenar
 * \param El tamaño de la lista
 *
 */
void ordenarEmpleadosPorCriterios(eEmpleado lista[], int tamanio, eSector listadoSectores[], int tamanioSectores);

int cargarNombreEmpleado(int legajo, eEmpleado listadoEmpleados[], int tamanioListadoEmpleados, char nombre[]);


#endif // LIBRERIA_H_INCLUDED
