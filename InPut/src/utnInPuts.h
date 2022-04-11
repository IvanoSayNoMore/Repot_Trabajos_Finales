/*
 * utnInPuts.h
 *
 *  Created on: 9 abr 2022
 *      Author: Usuario Programador
 */

#ifndef UTNINPUTS_H_
#define UTNINPUTS_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int utnMyGets(char* cadena, int longitud);

int utnGetInt(int* pResultado);

int utnGetNumero(float* pNumeroIngresado, char* mensaje, char* mensajeError,char* mensajeSeguirNoSeguir,
		int minimo, int maximo, int reintentos);

int utnVerificacionConChar(char* mensajeValidacion,char* mensajeFinal);

int utnEsNumerica(char* cadena);

void utnMostrarResultados(float parametroPivot, float parametroA, float parametroB,float parametroAconDescuento,
		float parametroBconDescuento,float parametroAconAumento,float parametroBconAumento,float valorPorUnidadParametroB,
		float valorPorUnidadParametroA,float difDeValores);

float utnIngresarFlotante(char mensaje[]);

int utnRecibeCadenaSoloCaracteres(char cadena[],char mensaje[],int reintentos,int tam);

int utnIngresarAlfanumerico(char cadena[], char mensaje[], int tam);

char utnIngresarChar(char mensaje[]);


#endif /* UTNINPUTS_H_ */
