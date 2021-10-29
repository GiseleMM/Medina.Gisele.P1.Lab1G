#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    int id;
    char descripcion[25];
    float precio;
} eServicios;

#endif // SERVICIO_H_INCLUDED
/** \brief valida que este en el ingresado el id servicio
 *
 * \param idIngresado int
 * \param servicios[] eServicios
 * \param tamServicios int
 * \return int retorna 1 si es valido 0 si no
 *
 */
int validarIdServicios(int idIngresado, eServicios servicios[],int tamServicios);
/** \brief listado de los servicios
 *
 * \param servicios[] eServicios
 * \param tamServicios int
 * \return int 1 si se logro mostrar servicios 0 si no
 *
 */
int mostrarServicios(eServicios servicios[], int tamServicios);
/** \brief carga descripcion de servicios
 *
 * \param servicios[] eServicios
 * \param tamServicios int
 * \param idServicio int
 * \param descripcionServicio[] char
 * \return int  1 si se logro cargar 0 si no
 *
 */
int cargarDescripcionServicios(eServicios servicios[],int tamServicios, int idServicio, char descripcionServicio[]);
