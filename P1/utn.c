#include "utn.h"

int validarCaracter(char auxChar, char a, char b)
{
    int todoOk=0;

    auxChar=tolower(auxChar);
    if(auxChar==a || auxChar==b)
    {
        todoOk=1;
    }
    return todoOk;
}
int validarRangoEntero(int auxInt, int limI, int limS)
{
    int todoOk=1;
    if(auxInt<limI || auxInt>limS)
    {
        todoOk=0;
    }

    return todoOk;
}
int validarPalabra(char palabra[])
{

int todoOk=1;
    int i=0;
    while(palabra[i]!='\0')
    {
        if(!isalpha(palabra[i]))
        {
            todoOk=0;
            break;
        }
        i++;
    }

    return todoOk;
}
