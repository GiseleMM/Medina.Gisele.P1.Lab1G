#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct
{
    int id;
    char descripcion[20];

} eTipos;


#endif // TIPO_H_INCLUDED
int mostrarTipos(eTipos tipos[], int tamTipos);
int validarIdTipos(int idIngresado, eTipos tipos[],int tamTipos);
int cargarDescripcionTipos(eTipos tipos[],int tamTipos, int idTipos, char descripcionTipo[]);
