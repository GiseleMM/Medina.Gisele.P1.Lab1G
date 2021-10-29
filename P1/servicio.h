#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    int id;
    char descripcion[20];
    float precio;
} eServicios;

#endif // SERVICIO_H_INCLUDED
int validarIdServicios(int idIngresado, eServicios servicios[],int tamServicios);
int mostrarServicios(eServicios servicios[], int tamServicios);
int cargarDescripcionServicios(eServicios servicios[],int tamServicios, int idServicio, char descripcionServicio[]);
