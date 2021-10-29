#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct{
    int id;
    char nombre[20];
    char sexo;
    int isEmpty;

}eCliente;


#endif // CLIENTE_H_INCLUDED
int cargarDescripcionNombre(eCliente clientes[],int tamClientes, int idCliente, char descripcionNombre[]);
