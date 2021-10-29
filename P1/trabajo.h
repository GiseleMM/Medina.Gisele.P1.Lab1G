#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED
#include "fecha.h"
#include "notebook.h"
#include "servicio.h"
typedef struct
{
    int id;
    int idNotebook;
    int idServicios;
    eFecha fechaTrabajo;
    int isEmpty;
} eTrabajo;

#endif // TRABAJO_H_INCLUDED
int inicializarTrabajo(eTrabajo listaTrabajo[],int tamTrabajo);
int buscarLibreTrabajo(eTrabajo listaTrabajo[], int tamTrabajo);
int altaTrabajo(eTrabajo listaTrabajo[], int tamTrabajo,eNotebook lista[],int tamNotebook, eMarca marcas[],int tamMarcas,eTipos tipos[], int tamTipos,eServicios servicios[],int tamServicios, int* pIdTrabajo);
void mostrarTrabajo(eTrabajo t,int tamTrabajo,eNotebook lista[], int tamNotebook,eMarca marcas[],int tamMarcas,eTipos tipos[],int tamTipos, eServicios servicios[], int tamServicios);
int mostrarTrabajos(eTrabajo listaTrabajo[],int tamTrabajo, eNotebook lista[], int tamNotebook, eMarca marcas[], int tamMarcas, eTipos tipos[], int tamTipos,eServicios servicios[], int tamServicios);
