#include "cliente.h"



int cargarDescripcionNombre(eCliente clientes[],int tamClientes, int idCliente, char descripcionNombre[])
{
    int todoOk=0;
    if(clientes!=NULL && tamClientes>0 && descripcionNombre!=NULL)
    {
        for(int i=0; i<tamClientes; i++)
        {
            if(clientes[i].id==idCliente)
            {
                strcpy(descripcionNombre,clientes[i].nombre);
                //puts(descripcionNombre);
                //system("pause");
                break;
            }
        }
        todoOk=1;

    }
    return todoOk;

}
int inicializarCliente(eCliente cliente[],int tamCliente)
{
    //a un vector vacio recorre todo el array colocando en el campo isEmpty 1
    int todoOk=0;
    if(cliente!=NULL && tamCliente>0)
    {
        todoOk=1;
        for(int i=0; i<tamCliente; i++)
        {
            cliente[i].isEmpty=1;//CAMPO DE ESTADO Vacio
        }

    }
    return todoOk;
}
void mostrarCliente(eCliente p,int tamCliente)
{

        printf("%2d        %-14s     %2d\n",
               p.id,p.nombre,p.sexo);
    //no muestro el isEmpty por que es una herramienta interna

}
