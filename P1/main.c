#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "trabajo.h"
#include "fecha.h"
#include "notebook.h"
#include "marca.h"
#include "utn.h"
#include "cliente.h"

/***INFORMES COMPLEMENTARIOS PARCIAL ABM NOTEBOOKS
1- Mostrar las notebooks del tipo seleccionado por el usuario.
2- Mostrar notebooks de una marca seleccionada.
3- Informar la o las notebooks más baratas.
4- Mostrar un listado de las notebooks separadas por marca.
5- Elegir un tipo y una marca y contar cuantas notebooks hay de ese tipo y esa marca.
6- Mostrar la o las marcas más elegidas por los clientes.
Bonus Track
Hardcodear algunos trabajos
7- Pedir una notebook y mostrar todos los trabajos que se le hicieron a la misma.
8- Pedir un notebook e informar la suma de los importes de los services se le hicieron a la
misma.
9- Pedir un servicio y mostrar las notebooks a las que se realizó ese servicio y la fecha.
10- Pedir una fecha y mostrar todos los servicios realizados en la misma.

Importante: Aquellos alumnos que no hayan podido entregar la primera parte del parcial
Deberán agregar al proyecto una estructura cliente: con campo id, nombre, sexo.
La notebook deberá tener el campo idCliente. Y cuando se muestre el listado de
notebooks se deberá informar el nombre del dueño
*/




#define TAM_NOTEBOOK 4
#define TAM_MARCAS 4
#define TAM_TIPOS 4
#define TAM_SERVICIOS 4
#define TAM_TRABAJOS 4
#define TAM_CLIENTES 4



















int main()
{

    //int banderaUnAlta=0;//para que no ingrese a modificar y baja
    int nextIdNotbook=7000;
    int nextIdTrabajo=8000;
    int nextIdCliente=90000;
    //int rta;
    eMarca marcas[]=
    {
        {1000,"Compaq"},
        {1001,"Asus"},
        {1002,"Acer"},
        {1003,"HP"}
    };
    eTipos tipos[]=
    {
        {5000,"Gamer"},
        {5001,"Disenio"},
        {5002,"Ultrabook"},
        {5003,"Normalita"}
    };
    eServicios servicios[]=
    {
        {20000,"Bateria",2250},
        {20001,"Display",10300},
        {20002,"Mantenimiento",4400},
        {20003,"Fuente",5600}
    };

//ARRAY DE CLIENTES
    eCliente clientes[TAM_CLIENTES];
if(!inicializarCliente(clientes,TAM_CLIENTES))
{
     printf("problemas al inicializar Clientes\n!");
}


//ARRAY DE ENOTEBOOKS
    eNotebook lista[TAM_NOTEBOOK];

    if(!inicializarNotebook(lista,TAM_NOTEBOOK))
    {
        printf("problemas al inicializar notebook\n!");
    }
//ARRAY DE ETRABAJO
    eTrabajo listaTrabajo[TAM_TRABAJOS];
    if(!inicializarTrabajo(listaTrabajo,TAM_TRABAJOS))
    {
        printf("problemas al inicializar trabajo\n");
    }

    char seguir='s';
    do
    {
        switch(menu())
        {
        case 'A':
            printf("Alta notebook\n");
            if(!altaNotebook(lista,TAM_NOTEBOOK,marcas,TAM_MARCAS,tipos,TAM_TIPOS, &nextIdNotbook,clientes,TAM_CLIENTES,&nextIdCliente))
            {
                printf("\nNo se pudo realizar el alta\n");
            }
            else
            {
                printf("\nAlta exitosa\n");
                //banderaUnAlta=1;
            }
            break;

        case 'B':
            //  if(banderaUnAlta==1)
            // {
            //rta=buscarLLeno(lista,TAM_NOTEBOOK);
            //printf("rta %d",rta);
            system("pause");
            printf("                    ***Modificar ***                          \n");
            if(modificarNotebook(lista,TAM_NOTEBOOK,marcas,TAM_MARCAS,tipos,TAM_TIPOS,clientes,TAM_CLIENTES))
            {
                printf("Modificacion exitosa\n");
            }
            else
            {
                printf("no se pudo realizar la modificacion\n");
            }


            break;
        case 'C':
            printf("Baja Notebook\n");
            if(!bajaNotebook(lista,TAM_NOTEBOOK,marcas,TAM_MARCAS,tipos,TAM_TIPOS,clientes,TAM_CLIENTES))
            {
                printf("No se pudo realizar la baja\n");
            }
            else
            {
                printf("Baja exitosa");
            }
            break;


        case 'D':
            printf("Listar notebooks\n");
            mostrarNotebooks(lista,TAM_NOTEBOOK,marcas,TAM_MARCAS,tipos,TAM_TIPOS,clientes,TAM_CLIENTES);
            break;
        case 'E':
            system("cls");
            printf("Listar Marcas   \n");
            if(mostrarMarcas(marcas,TAM_MARCAS))
            {
                printf("Informe Hecho");

            }
            else
            {
                printf("no se pudo mostrar marcas\n");
            }
            break;//NO OLVIDAR BREAK
        case 'F':
            system("cls");
            printf("Listar Tipos          \n");
            if(!mostrarTipos(tipos,TAM_TIPOS))
            {
                printf("Error en listar Tipos\n");
            }
            break;
        case 'G':
            system("cls");
            printf("Listar Servicios          \n");
            if(!mostrarServicios(servicios,TAM_SERVICIOS))
            {
                printf("Error en listar Servicios\n");
            }
            break;
        case 'H':
            system("cls");
            printf("Alta trabajo");
            if(!altaTrabajo(listaTrabajo,TAM_TRABAJOS,lista,TAM_NOTEBOOK,marcas,TAM_MARCAS,tipos,TAM_TIPOS,servicios,TAM_SERVICIOS,&nextIdTrabajo,clientes,TAM_CLIENTES))
            {
                printf("No se pudo realizar el alta Trabajo\n");
            }
            else
            {
                printf("alta trabajo exitosa\n");
            }
            break;
        case 'I':
            printf("Listar trabajos");
            mostrarTrabajos(listaTrabajo,TAM_TRABAJOS,lista,TAM_NOTEBOOK,marcas,TAM_MARCAS,tipos,TAM_TIPOS,servicios,TAM_SERVICIOS);
            break;
        case 'J':
            printf("INFORMES\n");
            informesNotebooks(lista,TAM_NOTEBOOK,marcas,TAM_MARCAS,tipos,TAM_TIPOS,clientes,TAM_CLIENTES);

            break;
        case 'S':

            printf("Ha seleccionado salir\n");
            seguir='n';
            break;//podemos cancelar la salida

        default:
            printf("Opcion no valida\n");
            break;//NO OLVIDAR BREAK

        }//Fin del switch
        //antes de comenzar de nuevo el do while  system pause
        system("pause");

    }
    while(seguir=='s');



    return 0;
}
























