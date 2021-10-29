#ifndef NOTEBOOK_H_INCLUDED
#define NOTEBOOK_H_INCLUDED
#include "marca.h"
#include "tipo.h"
typedef struct
{
    int id;
    char modelo[20];
    int idMarca;
    int idTipo;
    float precio;
    int isEmpty;
} eNotebook;

#endif // NOTEBOOK_H_INCLUDED
int buscarLLeno(eNotebook lista[], int tamNotebook);
int inicializarNotebook(eNotebook lista[],int tamNotebook);
void mostrarNotebook(eNotebook p,int tamNotebook,eMarca marcas[],int tamMarcas,eTipos tipos[],int tamTipos);
int mostrarNotebooks(eNotebook lista[], int tamNotebook, eMarca marcas[],int tamMarcas, eTipos tipos[], int tamTipos);
int buscarLibre(eNotebook lista[], int tamNotebook);
int buscarNotebookId(eNotebook lista[], int tamNotebook, int id);
int altaNotebook(eNotebook lista[], int tamNotebook,eMarca marcas[],int tamMarcas,eTipos tipos[], int tamTipos, int* pId);
int bajaNotebook(eNotebook lista[],int tamNotebook,eMarca marcas[],int tamMarcas,eTipos tipos[],int tamTipos);
int modificarNotebook(eNotebook lista[], int tamNotebook, eMarca marcas[], int tamMarcas, eTipos tipos[], int tamTipos);
int menuModificacion();
int validarIdNotebook(int idIngresado, eNotebook lista[],int tamNotebook);
int validarModelo(char modelo[],int tamModelo);
int menu();
int cargarDescripcionModelo(eNotebook lista[],int tamNotebook, int idNotebook, char descripcionModelo[]);
