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
/** \brief carga el campo del campo isEmpty con 1
 *
 * \param listaTrabajo[] eTrabajo
 * \param tamTrabajo int
 * \return int 1 si logro realizar la cargar 0 si no
 *
 */
int inicializarTrabajo(eTrabajo listaTrabajo[],int tamTrabajo);
/** \brief busca si hay espacio en el array para cargar datoo
 *
 * \param listaTrabajo[] eTrabajo
 * \param tamTrabajo int
 * \return int indice disponible -1 si no hay espacio
 *
 */
int buscarLibreTrabajo(eTrabajo listaTrabajo[], int tamTrabajo);
/** \brief realiza la carga de un elemento del array de listaTrabajo
 *
 * \param listaTrabajo[] eTrabajo
 * \param tamTrabajo int
 * \param lista[] eNotebook
 * \param tamNotebook int
 * \param marcas[] eMarca
 * \param tamMarcas int
 * \param tipos[] eTipos
 * \param tamTipos int
 * \param servicios[] eServicios
 * \param tamServicios int
 * \param pIdTrabajo int* asigna id e incrementa su valor para que no se use un mismo id
 * \return int 1 si se pudo realziar la cargar 0 si nno
 *
 */
int altaTrabajo(eTrabajo listaTrabajo[], int tamTrabajo,eNotebook lista[],int tamNotebook, eMarca marcas[],int tamMarcas,eTipos tipos[], int tamTipos,eServicios servicios[],int tamServicios, int* pIdTrabajo,eCliente clientes[], int tamClientes);
/** \brief muestro un elemento del array lista trabajo
 *
 * \param t eTrabajo
 * \param tamTrabajo int
 * \param lista[] eNotebook
 * \param tamNotebook int
 * \param marcas[] eMarca
 * \param tamMarcas int
 * \param tipos[] eTipos
 * \param tamTipos int
 * \param servicios[] eServicios
 * \param tamServicios int
 * \return void
 *
 */
void mostrarTrabajo(eTrabajo t,int tamTrabajo,eNotebook lista[], int tamNotebook,eMarca marcas[],int tamMarcas,eTipos tipos[],int tamTipos, eServicios servicios[], int tamServicios);
/** \brief litado de trabajos
 *
 * \param listaTrabajo[] eTrabajo
 * \param tamTrabajo int
 * \param lista[] eNotebook
 * \param tamNotebook int
 * \param marcas[] eMarca
 * \param tamMarcas int
 * \param tipos[] eTipos
 * \param tamTipos int
 * \param servicios[] eServicios
 * \param tamServicios int
 * \return int 1 se pudo realizar 0 no
 *
 */
int mostrarTrabajos(eTrabajo listaTrabajo[],int tamTrabajo, eNotebook lista[], int tamNotebook, eMarca marcas[], int tamMarcas, eTipos tipos[], int tamTipos,eServicios servicios[], int tamServicios);
/** \brief busca si el id eiste y si esta activo y no fue dado de baja
 *
 * \param listaTrabajo[] eTrabajo
 * \param tamTrabajo int
 * \param id int
 * \return int retorna el indice si se encontro -1 si no lo encontro
 *
 */
int buscarTrabajoId(eTrabajo listaTrabajo[], int tamTrabajo, int id);
