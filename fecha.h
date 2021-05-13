#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct{
        int dia;
        int mes;
        int anio;
}eFecha;

#endif // FECHA_H_INCLUDED

int comparaFechas(eFecha f1, eFecha f2);
