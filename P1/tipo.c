#include "tipo.h"

int mostrarTipos(eTipos tipos[], int tamTipos)
{
    int todoOk=0;
    if(tipos!=NULL && tamTipos>0)
    {
        todoOk=1;
        printf("\nID                     Tipos\n");
        printf("----------------------------------------------------------\n");
        for(int i=0; i<tamTipos; i++)
        {
            printf("%2d ..............................................  %-14s\n", tipos[i].id,tipos[i].descripcion);
        }
    }
    return todoOk;

}
int validarIdTipos(int idIngresado, eTipos tipos[],int tamTipos)
{
    int esValido=0;
    if(tipos!=NULL && tamTipos>0)
    {

        for(int i=0; i<tamTipos; i++)
        {
            if(idIngresado==tipos[i].id)
            {
                esValido=1;
                break;
            }
        }


    }
    return esValido;
}
int cargarDescripcionTipos(eTipos tipos[],int tamTipos, int idTipos, char descripcionTipo[])
{
    int todoOk=0;
    if(tipos!=NULL && tamTipos>0 && descripcionTipo!=NULL)
    {
        for(int i=0; i<tamTipos; i++)
        {
            if(tipos[i].id==idTipos)
            {
                strcpy(descripcionTipo,tipos[i].descripcion);
                break;
            }
        }
        todoOk=1;

    }
    return todoOk;

}
