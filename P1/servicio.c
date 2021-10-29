#include "servicio.h"

int validarIdServicios(int idIngresado, eServicios servicios[],int tamServicios)
{
    int esValido=0;
    if(servicios!=NULL && tamServicios>0)
    {

        for(int i=0; i<tamServicios; i++)
        {
            if(idIngresado==servicios[i].id)
            {
                esValido=1;
                break;
            }
        }


    }
    return esValido;
}
int mostrarServicios(eServicios servicios[], int tamServicios)
{
    int todoOk=0;
    if(servicios!=NULL && tamServicios>0)
    {
        todoOk=1;
        printf("\nID                Servicios                           precio\n");
        printf("------------------------------------------------------------------\n");
        for(int i=0; i<tamServicios; i++)
        {
            printf("%2d .....................%-14s.............................  %2.f\n", servicios[i].id,servicios[i].descripcion,servicios[i].precio);
        }
    }
    return todoOk;

}
int cargarDescripcionServicios(eServicios servicios[],int tamServicios, int idServicio, char descripcionServicio[])
{
    int todoOk=0;
    if(servicios!=NULL && tamServicios>0 && descripcionServicio!=NULL)
    {
        for(int i=0; i<tamServicios; i++)
        {
            if(servicios[i].id==idServicio)
            {
                strcpy(descripcionServicio,servicios[i].descripcion);
                break;
            }
        }
        todoOk=1;

    }
    return todoOk;

}
