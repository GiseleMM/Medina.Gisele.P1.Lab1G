#include "marca.h"

int cargarDescripcionMarcas(eMarca marcas[],int tamMarcas, int idMarca, char descripcionMarca[])
{
    int todoOk=0;
    if(marcas!=NULL && tamMarcas>0 && descripcionMarca!=NULL)
    {
        for(int i=0; i<tamMarcas; i++)
        {
            if(marcas[i].id==idMarca)
            {
                strcpy(descripcionMarca,marcas[i].descripcion);
                break;
            }
        }
        todoOk=1;

    }
    return todoOk;

}
int mostrarMarcas(eMarca marcas[], int tamMarcas)
{
    int todoOk=0;
    if(marcas!=NULL && tamMarcas>0)
    {
        todoOk=1;
        printf("\nID                   Marcas\n");
        printf("---------------------------------------------------------\n");
        for(int i=0; i<tamMarcas; i++)
        {
            printf("%2d ..........................................  %-14s\n", marcas[i].id,marcas[i].descripcion);
        }
    }
    return todoOk;

}
int validarIdMarca(int idIngresado, eMarca marcas[],int tamMarcas)
{
    int esValido=0;
    if(marcas!=NULL && tamMarcas>0)
    {

        for(int i=0; i<tamMarcas; i++)
        {
            if(idIngresado==marcas[i].id)
            {
                esValido=1;
                break;
            }
        }


    }
    return esValido;
}
