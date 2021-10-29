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
/*Desarrollar en ANSI C:
Se necesita gestionar un Service de Notebooks y para eso se deberá desarrollar lo siguiente:
ENTIDADES:
Fecha:
• dia
• mes
• año
Marca:
• id (comienza en 1000)
• descripción (máx 20 caracteres)
Tipo:
• id (comienza en 5000)
• descripción (máx 20 caracteres)
Notebook:
• id
• modelo (máx 20 caracteres)
• idMarca Validar
• idTipo Validar
• precio
Servicio:
• id(comienza en 20000)
• descripción (máximo 25 caracteres)
• precio
Trabajo:
• id (autoincremental)
• idNotebook (debe existir) Validar
• idServicio (debe existir) Validar
• fecha (Validar día, mes y año)
DATOS PREVIOS:
Los arrays de marca, tipo y servicio deberán ser hardcodeados.
Marcas (Compaq, Asus, Acer, HP)
Tipos ( Gamer, Disenio, Ultrabook, Normalita)
Servicios (Bateria: $2250, Display: $10300, Mantenimiento: $4400, Fuente: $5600)
MENU DE OPCIONES:
A. ALTA NOTEBOOK
B. MODIFICAR NOTEBOOK: Se ingresará el id de la notebook, permitiendo en un submenú modificar:
• precio
• tipo
C. BAJA NOTEBOOK: Se ingresará el id de la notebook y se realizará una baja lógica.
D. LISTAR NOTEBOOKS: Hacer un único listado de todas las notebooks ordenadas por marca y precio.
E. LISTAR MARCAS
F. LISTAR TIPOS
G. LISTAR SERVICIOS
H. ALTA TRABAJO: Se dará de alta cada ocurrencia de trabajo pidiéndole al usuario que elija una
notebook y un Servicio
I. LISTAR TRABAJOS*/




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

    eCliente clientes[TAM_CLIENTES];


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
























