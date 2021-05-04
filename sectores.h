#ifndef SECTORES_H_INCLUDED
#define SECTORES_H_INCLUDED

typedef struct
{
    int idSector;
    char descripcion[20];

} eSector;

int cargarDescripcionSector(int id, eSector sectores[],int tam, char descripcion[]);

void mostrarSectores(eSector listadoSectores[],int tamanio);

void mostrarSector(eSector unSector);


#endif // SECTORES_H_INCLUDED
