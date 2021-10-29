#include "trabajo.h"

int inicializarTrabajo(eTrabajo listaTrabajo[],int tamTrabajo)
{
    //a un vector vacio recorre todo el array colocando en el campo isEmpty 1
    int todoOk=0;
    if(listaTrabajo!=NULL && tamTrabajo>0)
    {
        todoOk=1;
        for(int i=0; i<tamTrabajo; i++)
        {
            listaTrabajo[i].isEmpty=1;//CAMPO DE ESTADO Vacio
        }

    }
    return todoOk;
}
int buscarLibreTrabajo(eTrabajo listaTrabajo[], int tamTrabajo)
{
    int indice=-1;//por si no encuentra ninguna posicion libre
    if(listaTrabajo!=NULL && tamTrabajo>0)
    {
        for(int i=0; i<tamTrabajo; i++)
        {
            if(listaTrabajo[i].isEmpty==1)//es lo mismo que (lista[i].isEmpty)
            {
                indice=i;
                break;//cuando la encontramos salimos por que si no estariamos devolviendo la ultima posicion LIBRE
                // acomodariamos gente desde el final del array al primero
                //error de rendimiento funciona igual
            }
        }

    }
    return indice;
}
int altaTrabajo(eTrabajo listaTrabajo[], int tamTrabajo,eNotebook lista[],int tamNotebook, eMarca marcas[],int tamMarcas,eTipos tipos[], int tamTipos,eServicios servicios[],int tamServicios, int* pIdTrabajo,eCliente clientes[],int tamClientes)
{
    int todoOk=0;
    int indice;
    //int rta;
    //int tamModelo=20;
    eTrabajo auxTrabajo;// me va permitir cargar todos los datos y validarlos ahi es  como un buffer


    if(listaTrabajo!=NULL && tamTrabajo>0 && lista!=NULL && tamNotebook>0 && marcas!=NULL && tamMarcas>0 && tipos!=NULL && tamTipos>0 && servicios!=NULL && tamServicios>0 && pIdTrabajo!=NULL)
    {
        system("cls");//una vez que valide limpio la patalla
        printf("\n                 *****Alta Trabajo****                   \n");
        printf("-----------------------------------------------------------\n");

        indice=buscarLibreTrabajo(listaTrabajo,tamTrabajo);

        if(indice==-1)
        {
            printf("\nNo hay lugar\n");
        }
        else
        {
            if(!buscarLLeno(lista,tamNotebook))
            {
                printf("\nAntes de ingresar a Alta trabajo debe ingresar a opcion A- Alta notebook\n");
            }
            else
            {
//ID AUTOINCREMENTAL
                //printf("Ingrese id: \n");// validar
                //scanf("%d", &auxPersona.id);
                auxTrabajo.id=*pIdTrabajo;//accedo alvalor de la direccion de memoria con el operador de indireccion
                (*pIdTrabajo)++;//primero el valor despues el incremento


//ID NOTEBOOK
                mostrarNotebooks(lista,tamNotebook,marcas,tamMarcas,tipos,tamTipos,clientes,tamClientes);
                printf("Ingrese ID Notebook:\n");
                while(!scanf("%d",&auxTrabajo.idNotebook))
                {
                    printf("dato no valido id \n");
                    fflush(stdin);
                }
                //rta=validarIdNotebook(auxTrabajo.idNotebook,lista,tamNotebook);
                //printf("%d respuesta de validar notebook",rta);
                while(!validarIdNotebook(auxTrabajo.idNotebook,lista,tamNotebook))
                {
                    printf("ERROR REingrese id Notebook:\n");
                    fflush(stdin);
                    scanf("%d", &auxTrabajo.idServicios);
                }
//ID SERVICIO

                //mostrarMarcas(marcas,tamMarcas);
                mostrarServicios(servicios,tamServicios);
                printf("Ingrese Id Servicios:\n");
                fflush(stdin);
                while(!scanf("%d", &auxTrabajo.idServicios))
                {
                    printf("Tipo de dato No valido\n");
                    fflush(stdin);
                }

                while(!validarIdServicios(auxTrabajo.idServicios,servicios,tamServicios))
                {
                    printf("ERROR REingrese Id servicio:\n");
                    fflush(stdin);
                    scanf("%d", &auxTrabajo.idServicios);
                }


//FECHA


                printf("Ingrese fecha dd/mm/aaaa:\n");
                while(!scanf("%2d/%2d/%d", &auxTrabajo.fechaTrabajo.dia,&auxTrabajo.fechaTrabajo.mes,&auxTrabajo.fechaTrabajo.anio))
                {
                    printf("Error dato no valido. Reingrese fecha:");
                    fflush(stdin);
                }

                auxTrabajo.isEmpty=0;//indico que esta lleno el campo isEmpty
                listaTrabajo[indice] =auxTrabajo;//entre al else por que hay indice libre, enla posicion indice que es la que devolvio buscarLibre
                //esta funcion la usaria en el case 1
                todoOk=1; // si se pudo dar de alta
            }



        }

    }
    return todoOk;
}
void mostrarTrabajo(eTrabajo t,int tamTrabajo,eNotebook lista[], int tamNotebook,eMarca marcas[],int tamMarcas,eTipos tipos[],int tamTipos, eServicios servicios[], int tamServicios)
{


    if(tamTrabajo>0 && lista!=NULL && tamNotebook>0 && marcas!=NULL && tamMarcas>0 && tipos!=NULL && tamTipos>0 && servicios!=NULL && tamServicios>0)
    {
        int rta1;
        int rta2;
        char descripcionModelo[20];
        char descripcionServicios[20];
        rta1=cargarDescripcionModelo(lista,tamNotebook,t.idNotebook,descripcionModelo);
        rta2=cargarDescripcionServicios(servicios,tamServicios,t.idServicios,descripcionServicios);
        if(rta1==1 && rta2==1)
        {
            printf("%2d     %2d %-14s        %2d %-14s         %2d/%2d/%d \n",t.id,
                   t.idNotebook,
                   descripcionModelo,
                   t.idServicios,
                   descripcionServicios,
                   t.fechaTrabajo.dia,
                   t.fechaTrabajo.mes,
                   t.fechaTrabajo.anio
                  );
        }



    }

}
int mostrarTrabajos(eTrabajo listaTrabajo[],int tamTrabajo, eNotebook lista[], int tamNotebook, eMarca marcas[], int tamMarcas, eTipos tipos[], int tamTipos,eServicios servicios[], int tamServicios)
{
    int todoOk=0;
    int banderaNohayTrabajos=1;
    if(listaTrabajo!=NULL&& tamTrabajo>0)
    {

        todoOk=1;
        system("cls");
        printf("                    ***Lista de trabajos***\n");
        printf("------------------------------------------------------------------------------\n");
        printf("  Id        id notebook-modelo          id  servicio                        fecha \n");
        for(int i=0; i<tamTrabajo; i++)
        {
            //tengo que filtrar no puedo recorrer todo el array
            //y mostrar todos los indices tengo que pasar a mostrar
            //persona solamente las estructuras cargadas
            if(listaTrabajo[i].isEmpty==0)// o podria negar (!lista[i].isEmpty)
            {
                //si el elemento de la lista no esta ocupado lo muestro
                mostrarTrabajo(listaTrabajo[i],tamTrabajo,lista,tamNotebook,marcas,tamMarcas,tipos,tamTipos,servicios,tamServicios);
                banderaNohayTrabajos=0;//mostre persona

            }
        }//FIN DEL FOR
        //afuera del for una vez recorrido todo array si no entro quiere decir que no hay personas que mostar
        if(banderaNohayTrabajos)
        {
            printf("\nNo hay trabajos para mostrar    \n");
        }
    }


    return todoOk;
}
int buscarTrabajoId(eTrabajo listaTrabajo[], int tamTrabajo, int id)
{
    int indice=-1;
    if((listaTrabajo!=NULL && tamTrabajo>0) && id>=20000)//SI quieto id lo puedo reutilizar
    {

        for(int i=0; i<tamTrabajo;i++)
        {
            if(listaTrabajo[i].id== id && listaTrabajo[i].isEmpty==0)//si la estructura no esta vacia y el id es igual id
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}
