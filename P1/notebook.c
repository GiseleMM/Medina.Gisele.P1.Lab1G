#include "notebook.h"

int buscarLLeno(eNotebook lista[], int tamNotebook)
{
    int todoOk=0;//por si no encuentra ninguna posicion libre
    if(lista!=NULL && tamNotebook>0)
    {
        for(int i=0; i<tamNotebook; i++)
        {
            if(lista[i].isEmpty==0)//es lo mismo que (lista[i].isEmpty)
            {
                todoOk=1;
                break;//cuando la encontramos salimos por que si no estariamos devolviendo la ultima posicion ocupada
                // acomodariamos gente desde el final del array al primero
                //error de rendimiento funciona igual
            }
        }

    }
    return todoOk;
}

int inicializarNotebook(eNotebook lista[],int tamNotebook)
{
    //a un vector vacio recorre todo el array colocando en el campo isEmpty 1
    int todoOk=0;
    if(lista!=NULL && tamNotebook>0)
    {
        todoOk=1;
        for(int i=0; i<tamNotebook; i++)
        {
            lista[i].isEmpty=1;//si coloco un defaine llevarlo a persona.h tambien rellevar el defaine
        }

    }
    return todoOk;
}

void mostrarNotebook(eNotebook p,int tamNotebook,eMarca marcas[],int tamMarcas,eTipos tipos[],int tamTipos)
{
    //char descripcionLoc[20];//vector de caracteres donde yo pueda copiar ahi las localidades
    //cargarDescripcionLocalidades(localidades, tamLoc, p.idLocalidades , descripcionLoc);
    char descripcionMarcas[20];
    char descripcionTipos[20];
    int rta1;
    int rta2;
    rta2=cargarDescripcionMarcas(marcas,tamMarcas,p.idMarca,descripcionMarcas);
    rta1=cargarDescripcionTipos(tipos,tamTipos,p.idTipo,descripcionTipos);
    if(rta1==1 && rta2==1)
    {

        printf("%2d        %-14s     %2d %-14s    %2d %-14s    %.2f\n",
               p.id,
               p.modelo,
               p.idMarca,
               descripcionMarcas,
               p.idTipo,
               descripcionTipos,
               p.precio
              );
    }


    //no muestro el isEmpty por que es una herramienta interna

}

int mostrarNotebooks(eNotebook lista[], int tamNotebook, eMarca marcas[], int tamMarcas, eTipos tipos[], int tamTipos)
{
    int todoOk=0;
    int banderaNohayNotebook=1;
    if(lista!=NULL&& tamNotebook>0)
    {

        todoOk=1;
        system("cls");
        printf("                    ***Lista de Notebook***\n");
        printf("------------------------------------------------------------------------------\n");
        printf("  Id        modelo              id  marca           id  tipo                precio\n");
        for(int i=0; i<tamNotebook; i++)
        {
            //tengo que filtrar no puedo recorrer todo el array
            //y mostrar todos los indices tengo que pasar a mostrar
            //persona solamente las estructuras cargadas
            if(lista[i].isEmpty==0)// o podria negar (!lista[i].isEmpty)
            {
                //si el elemento de la lista no esta ocupado lo muestro
                mostrarNotebook(lista[i],tamNotebook,marcas,tamMarcas,tipos,tamTipos);
                banderaNohayNotebook=0;//mostre persona

            }
        }//FIN DEL FOR
        //afuera del for una vez recorrido todo array si no entro quiere decir que no hay personas que mostar
        if(banderaNohayNotebook)
        {
            printf("\nNo hay notebook para mostrar\n");
        }
    }


    return todoOk;
}
int buscarLibre(eNotebook lista[], int tamNotebook)
{
    int indice=-1;//por si no encuentra ninguna posicion libre
    if(lista!=NULL && tamNotebook>0)
    {
        for(int i=0; i<tamNotebook; i++)
        {
            if(lista[i].isEmpty==1)//es lo mismo que (lista[i].isEmpty)
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

int buscarNotebookId(eNotebook lista[], int tamNotebook, int id)
{
    int indice=-1;
    if(lista!=NULL && (tamNotebook>0) && (id>=7000))//SI quieto id lo puedo reutilizar
    {

        for(int i=0; i<tamNotebook; i++)
        {
            if(lista[i].id== id && lista[i].isEmpty==0)//si la estructura no esta vacia y el id es igual id
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}

int altaNotebook(eNotebook lista[], int tamNotebook,eMarca marcas[],int tamMarcas,eTipos tipos[], int tamTipos, int* pIdNotebook)
{
    int todoOk=0;
    int indice;
    int tamModelo=20;
    eNotebook auxNotebook;// me va permitir cargar todos los datos y validarlos ahi es  como un buffer


    if(lista!=NULL && tamNotebook>0 && marcas!=NULL && tamMarcas>0)
    {
        system("cls");//una vez que valide limpio la patalla
        printf("\n                   Alta Notebook                          \n");
        printf("-----------------------------------------------------------\n");

        indice=buscarLibre(lista,tamNotebook);
        if(indice==-1)
        {
            printf("\nNo hay lugar\n");
        }
        else
        {

//ID
            //printf("Ingrese id: \n");// validar
            //scanf("%d", &auxPersona.id);
            auxNotebook.id= *pIdNotebook;//accedo al valor de la direccion de memoria con el operador de indireccion
            (*pIdNotebook)++;//primero el valor y despues el incremento
            //no se reutilizan los id. nadie de baja de algo .Nosostros vamos a ser una baja logica pero en la vida real no

 //MODELO
            printf("Ingrese Modelo:\n");
            fflush(stdin);
            gets(auxNotebook.modelo);
            validarModelo(auxNotebook.modelo,tamModelo);
//MARCA

            mostrarMarcas(marcas,tamMarcas);
            printf("Ingrese Id marca:\n");
            fflush(stdin);
            scanf("%d", &auxNotebook.idMarca);
            while(!validarIdMarca(auxNotebook.idMarca,marcas,tamMarcas))
            {
                printf("ERROR REingrese id marca:\n");
                fflush(stdin);
                scanf("%d", &auxNotebook.idMarca);
            }

//TIPO

            mostrarTipos(tipos,tamTipos);
            printf("Ingrese id tipo:\n");
            scanf("%d", &auxNotebook.idTipo);
            while(!validarIdTipos(auxNotebook.idTipo,tipos,tamTipos))
            {
                printf("ERROR REingrese id tipo:\n");

                fflush(stdin);
                scanf("%d", &auxNotebook.idTipo);
            }

//PRECIO
            printf("Ingrese precio\n");
            fflush(stdin);
            while(!scanf("%f",&auxNotebook.precio))
            {
                fflush(stdin);
                printf("precio invalido Reingrese\n");
            }

            auxNotebook.isEmpty=0;//indico que esta lleno el campo isEmpty
            lista[indice] =auxNotebook;//entre al else por que hay indice libre, enla posicion indice que es la que devolvio buscarLibre
            //esta funcion la usaria en el case 1
            todoOk=1; // si se pudo dar de alta


        }

    }
    return todoOk;
}
int bajaNotebook(eNotebook lista[],int tamNotebook,eMarca marcas[],int tamMarcas,eTipos tipos[],int tamTipos)
{
    int todoOk=0;
    int indice;//declaro el indice y el id
    int id;
    char confirma;
    if(lista!=NULL && tamNotebook>0)
    {
        system("cls");
        if(buscarLLeno(lista,tamNotebook))
        {
            printf("\n                  Baja notebook        \n");
            printf("\n----------------------------------------------------------\n");
            mostrarNotebooks(lista,tamNotebook,marcas,tamMarcas,tipos,tamTipos);
            printf("\nIngrese id:\n");
            scanf("%d", &id);
            indice= buscarNotebookId(lista,tamNotebook,id);//busco el id
            if(indice==-1)
            {//no se encuentra en el  sistema
                printf("\nId: %d  no esta registrado en  el sistema\n", id);
            }
            else
            {
                mostrarNotebook(lista[indice],tamNotebook,marcas,tamMarcas,tipos,tamTipos);//muestro la persona que esta en la posicion indice
                printf("\nConfirma baja s/n: \n");
                fflush(stdin);
                scanf("%c", &confirma);
                confirma=tolower(confirma);
                while(!validarCaracter(confirma,'s','n'))
                {
                    printf("\nRespuesta no valida. Confirma la  baja s/n :\n ");
                    fflush(stdin);
                    scanf("%c", &confirma);
                }
                if(confirma=='s')
                {
                    lista[indice].isEmpty=1;//libero el espacio
                    todoOk=1;//se pudo hacer la baja si no devuelve todook o
                }
                else
                {
                    printf("\nBaja cancelada por el usuario\n");
                }
            }
        }
        else
        {
            printf("\nNo hay  Notebooks en el sistema\n\n");
        }

    }
    return todoOk;
}
int modificarNotebook(eNotebook lista[], int tamNotebook, eMarca marcas[], int tamMarcas, eTipos tipos[], int tamTipos)
{
    int todoOk=0;
    int indice;//declaro el indice y el id
    int id;
    char confirma;
    //char auxSexo;
    int auxTipo;//auxiliar ETIPOS POR QUE LO DEFINI COMO UN FKEY DE TIPOS
    // int aux;
    float auxPrecio;
    //char auxLocalidades[20];
    if(lista!=NULL && tamNotebook>0)
    {
        system("cls");
        if(buscarLLeno(lista,tamNotebook))
        {
            printf("\n                   ***Modificar***                        \n");
            printf("---------------------------------------------------------------------\n");
            mostrarNotebooks(lista,tamNotebook,marcas,tamMarcas,tipos,tamTipos);
            printf("\nIngrese Id:\n");
            while(!scanf("%d", &id))
            {
                printf("\nError tipo de dato no valido Re-Ingrese Id\n");
                fflush(stdin);
            }
            indice= buscarNotebookId(lista,tamNotebook,id);//busco el id
            if(indice==-1)
            {
                //no se encuentra en el  sistema
                printf("\nId: %d  no esta registrado en  el sistema\n", id);
            }
            else
            {
                mostrarNotebook(lista[indice],tamNotebook,marcas,tamMarcas,tipos,tamTipos);//muestro la persona que esta en la posicion indice
                printf("\nConfirma modificacion s/n:\n");
                fflush(stdin);
                scanf("%c", &confirma);
                confirma=tolower(confirma);
                while(!validarCaracter(confirma,'s','n'))
                {
                    printf("Respuesta no valida. Confirma la modicinacion s/n :\n ");
                    fflush(stdin);
                    scanf("%c", &confirma);
                }
                if(confirma=='s')
                {
                    todoOk=1;//se pudo hacer la baja si no devuelve todook o
                    system("cls");
                    fflush(stdin);
                    switch(menuModificacion())
                    {

                    case 'A':
                        printf("\nIngrese nuevo precio");
                        while(!scanf("%f",&auxPrecio))
                        {
                            printf("\nError, ingrese nuevo precio");
                            fflush(stdin);
                        }
                        //valido
                        lista[indice].precio=auxPrecio;
                        printf("%f",lista[indice].precio);

    //actualizo el nombre
                        break;
                    case 'B':
                        mostrarTipos(tipos,tamTipos);
                        printf("\nIngrese nuevo Id tipo:\n");
                        //fflush(stdin);
                        //gets(auxTipo);
                        while(!scanf("%d",&auxTipo))
                        {
                            if(!validarIdTipos(auxPrecio,tipos,tamTipos))
                            {
                                printf("\nError Id no valido Reingrese Id tipos:\n");
                                fflush(stdin);
                            }
                        }

                        lista[indice].idTipo=auxTipo;
                        break;

                    case 'S':
                        printf("\nIngreso Salir\n");
                        todoOk=0;
                        break;
                    default:
                        printf("Opcion no valida\n");
                        todoOk=0;
                        break;
                    }//FIN DE SWITCH

                }
                else
                {
                    printf("\nModificacion cancelada por el usuario\n");
                }
            }



        }
        else
        {
            printf("\nNo hay notebooks ingresadas al sistema        \n");
        }

    }
    return todoOk;
}
int menuModificacion()
{

    char opcion;
    system("cls");


    printf("A- Modificar precio\n");//registrar un elelmento
    printf("B- Modificar tipo \n");//eliminar

    printf("S - Salir\n");
    printf("Ingrese opcion: \n ");

    while(!(scanf("%c",&opcion)))
    {

        printf("Opcion no valida Reingrese opcion\n");
        fflush(stdin);
        //scanf("%d",&opcion);//si lo coloco adentro me pide 2 veces la opcion
    }
    opcion=toupper(opcion);

    return opcion;
}
int validarIdNotebook(int idIngresado, eNotebook lista[],int tamNotebook)
{
    int esValido=0;
    if(lista!=NULL && tamNotebook>0)
    {

        for(int i=0; i<tamNotebook; i++)
        {
            if(idIngresado==lista[i].id)
            {
                esValido=1;
                break;
            }
        }


    }
    return esValido;
}

int validarModelo(char modelo[],int tamModelo)
{
    int todoOk=0;
    if(modelo!=NULL && tamModelo>0)
    {
        while(strlen(modelo)>20)
        {
            printf("nombre demasiado largo Reingrese Modelo\n");
            fflush(stdin);
            gets(modelo);

        }
        todoOk=1;
    }
      return todoOk;
}
int menu()
{
    char opcion;
    system("cls");
    printf("***ABM NOTEBOOK***\n");
    printf("A- Alta notebook\n");//registrar un elelmento
    printf("B- Modificar notebook\n");//eliminar
    printf("C- Baja notebook\n");//modificar algunos de los campos
    printf("D- Listar notebook\n");//ordenar en base a algun criterio en particular
    printf("E- Listar Marcas\n");// mostrar un listado de las personas
    printf("F- Listar Tipos\n");
    printf("G- Listar Servicios\n");
    printf("H- Alta trabajo\n");
    printf("I- Listar trabajo\n");
    printf("S- Salir\n");
    printf("Ingrese opcion: \n ");
    fflush(stdin);
    while(!(scanf("%c",&opcion)))
    {

        printf("Opcion no valida Reingrese opcion\n");
        fflush(stdin);
        //scanf("%d",&opcion);//si lo coloco adentro me pide 2 veces la opcion
    }
    opcion=toupper(opcion);
    // printf("%c",opcion);


    return opcion;
}
int cargarDescripcionModelo(eNotebook lista[],int tamNotebook, int idNotebook, char descripcionModelo[])
{
    int todoOk=0;
    if(lista!=NULL && tamNotebook>0 && descripcionModelo!=NULL)
    {
        for(int i=0; i<tamNotebook; i++)
        {
            if(lista[i].id==idNotebook)
            {
                strcpy(descripcionModelo,lista[i].modelo);
                break;
            }
        }
        todoOk=1;

    }
    return todoOk;

}
