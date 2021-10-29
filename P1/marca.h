#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct
{
    int id;
    char descripcion[20];
} eMarca;


#endif // MARCA_H_INCLUDED
int cargarDescripcionMarcas(eMarca marcas[],int tamMarcas, int idMarca, char descripcionMarca[]);
int mostrarMarcas(eMarca marcas[], int tamMarcas);
int validarIdMarca(int idIngresado, eMarca marcas[],int tamMarcas);
