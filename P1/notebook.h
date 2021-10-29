#ifndef NOTEBOOK_H_INCLUDED
#define NOTEBOOK_H_INCLUDED
#include "marca.h"
#include "tipo.h"
#include "utn.h"
#include "cliente.h"
typedef struct
{
    int id;
    char modelo[20];
    int idMarca;
    int idTipo;
    float precio;
    int idCliente;
    int isEmpty;
} eNotebook;

#endif // NOTEBOOK_H_INCLUDED
/** \brief busca que se halla ingresado al menos una carga a el array lista
 *
 * \param lista[] eNotebook lista de notebook
 * \param tamNotebook int   tamaño del array de enotebook
 * \return int  1 hay almenos un dato cargado 0 no hay dato ingresado
 *
 */
int buscarLLeno(eNotebook lista[], int tamNotebook);
/** \brief reccorre el array lista y cargar el estado del campo isEmpty con 1 vacio
 *
 * \param lista[] eNotebook lista sobre la que trabaja
 * \param tamNotebook int   tamaño del array
 * \return int  1 si logro inicializarla o si no
 *
 */
int inicializarNotebook(eNotebook lista[],int tamNotebook);
/** \brief muestra un elemento del array lista
 *
 * \param p eNotebook variable del tipo eNotebook
 * \param tamNotebook int   tamano del vector al que pertenece
 * \param marcas[] eMarca    necesario por campo id del tipo de dato eNotebook
 * \param tamMarcas int     tamaño del array de marcas
 * \param tipos[] eTipos    necesario por el campo id tipos
 * \param tamTipos int  tamaño del tipo
 * \return void
 *
 */
void mostrarNotebook(eNotebook p,int tamNotebook,eMarca marcas[],int tamMarcas,eTipos tipos[],int tamTipos,eCliente clientes[],int tamClientes);
/** \brief muestra listado de Notebooks activas
 *
 * \param lista[] eNotebook array a recorrer filtrando basado en campo isEmpty
 * \param tamNotebook int  del array lista
 * \param marcas[] eMarca
 * \param tamMarcas int
 * \param tipos[] eTipos
 * \param tamTipos int
 * \return int    1 si logro mostrar o si no
 *
 */
int mostrarNotebooks(eNotebook lista[], int tamNotebook, eMarca marcas[],int tamMarcas, eTipos tipos[], int tamTipos,eCliente clientes[],int tamClientes);
/** \brief verifica si hay espacio para cargar dato en el vector
 *
 * \param lista[] eNotebook vector a cargar
 * \param tamNotebook int
 * \return int  indice donde se puede cargar el dato, -1 si no hay espacio
 *
 */
int buscarLibre(eNotebook lista[], int tamNotebook);
/** \brief busca si el id de la ingresado esta ingresado al sistema de notebook
 *
 * \param lista[] eNotebook
 * \param tamNotebook int
 * \param id int    id a comparar con los datos del array de lista en el campo id
 * \return int  el indice si se encuentra activo y su ubicacion, -1 si no esta
 *
 */
int buscarNotebookId(eNotebook lista[], int tamNotebook, int id);
/** \brief ingreso de los datos  y asignacion automatica de id
 *
 * \param lista[] eNotebook
 * \param tamNotebook int
 * \param marcas[] eMarca
 * \param tamMarcas int
 * \param tipos[] eTipos
 * \param tamTipos int
 * \param pId int*  direccion de memoria de la variable nextId para aignarla como un campo e incrementarla para proximo ingreso
 * \return int 1 si se logro dar de alta 0 si no
 *
 */
int altaNotebook(eNotebook lista[], int tamNotebook,eMarca marcas[],int tamMarcas,eTipos tipos[], int tamTipos, int* pId,eCliente clientes[],int tamClientes,int* pIdCliente);
/** \brief baja logica aun elemento de la lista mediante el campo isEmpty
 *
 * \param lista[] eNotebook
 * \param tamNotebook int
 * \param marcas[] eMarca
 * \param tamMarcas int
 * \param tipos[] eTipos
 * \param tamTipos int
 * \return int 1 se logro realizar la baja 0 no se pudo realizar
 *
 */
int bajaNotebook(eNotebook lista[],int tamNotebook,eMarca marcas[],int tamMarcas,eTipos tipos[],int tamTipos,eCliente clientes[], int tamClientes);
/** \brief muestras las notebooks pide ingresar id y utiliza la funcion menu modificacion para modificar dos campos de la estructura precio y tipo
 *
 * \param lista[] eNotebook
 * \param tamNotebook int
 * \param marcas[] eMarca
 * \param tamMarcas int
 * \param tipos[] eTipos
 * \param tamTipos int
 * \return int 1 si se pudo realizar la modificacion 0 si no
 *
 */
int modificarNotebook(eNotebook lista[], int tamNotebook, eMarca marcas[], int tamMarcas, eTipos tipos[], int tamTipos,eCliente clientes[],int tamClientes);
/** \brief menu utilizado por la funcion modificar mostrardo 3 opciones cambio tipo, cambio precio y salir
 *
 * \return int
 *
 */
int menuModificacion();
/** \brief valida id notebook este cargado
 *
 * \param idIngresado int
 * \param lista[] eNotebook
 * \param tamNotebook int
 * \return int 1 si es valido si lo encontro en el array 0 si no
 *
 */
int validarIdNotebook(int idIngresado, eNotebook lista[],int tamNotebook);
/** \brief valida que la descripcion de modelo no supere el tamaño de 20 caracteres
 *
 * \param modelo[] char
 * \param tamModelo int
 * \return int 1 es valido 0 si no
 *
 */
int validarModelo(char modelo[],int tamModelo);
/** \brief menu que retorna la opcion del abm notebook y trabajo
 *
 * \return int opcion elegida por el usuario
 *
 */
int menu();
/** \brief recibe una direccion de memoria de una varible donde carga la el campo modelo si coincide con el id ingresado
 *
 * \param lista[] eNotebook
 * \param tamNotebook int
 * \param idNotebook int
 * \param descripcionModelo[] char array donde copia modelo
 * \return int 1 si logro cargar la descripcion 0 si no
 *
 */
int cargarDescripcionModelo(eNotebook lista[],int tamNotebook, int idNotebook, char descripcionModelo[]);
