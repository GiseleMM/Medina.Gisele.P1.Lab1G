#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

#include <ctype.h>


#endif // UTN_H_INCLUDED

/** \brief valida caracter entre 2 opciones
 *
 * \param auxChar char caracter a validad
 * \param a char posible valor
 * \param b char posible valor
 * \return int 1 si es valido 0 si no lo es
 *
 */
int validarCaracter(char auxChar, char a, char b);

/** \brief valida un numero dependiendo del lim superior y lim inferior
 *
 * \param auxInt int numero a validar
 * \param limI int  limite inferior del rango
 * \param limS int  limite superior del rango
 * \return int 1 si es valido 0 si no lo es
 *
 */
int validarRangoEntero(int auxInt, int limI, int limS);
int validarPalabra(char palabra[]);
