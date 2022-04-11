/*
 * cargaSecuencial.h
 *
 *  Created on: 9 abr 2022
 *      Author: Usuario Programador
 */

#ifndef CARGASECUENCIAL_H_
#define CARGASECUENCIAL_H_

int utnCargaValoresVariosTipos(int numeracion[], char cadenaCaracteres[][50], int numeroA[], int numeroB[],
		int cantidad,char* mensajeNumeracion,char* mensajeNumeroA, char* mensajeNumeroB, char* mensajeCadenaChar);
int IngresarEntero(char mensaje[]);
int utnRecibeCadenaSoloCaracteres(char cadena[],char mensaje[],int reintentos,int tam);
void utnMostrarValoresVariosTipos(int numeracion[], char cadenaCaracteres[][50], int numeroA[], int numeroB[],
		int cantidad);



#endif /* CARGASECUENCIAL_H_ */
