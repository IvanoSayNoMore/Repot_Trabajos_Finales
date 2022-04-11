/*
 ============================================================================
 Name        : CargaSecuencialBurbujeo.c
 Author      : Ivan Fabella
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "cargaSecuencial.h"
#include <string.h>

#define CANTIDAD 2
void utnOrdenarDatosPorString(int posicion[] , char cadena[][50] , int numA[],int numB[], int tam);
void utnOrdenarDatosPorNumero(int posicion[], char cadena[][50], int numA[],
		int numB[], int tam);
int main(void) {
	setbuf(stdout, NULL);
	int legajo[2];
	char nombre[2][50];
	int notaA[2];
	int notaB[2];
	int retorno;
	retorno=utnCargaValoresVariosTipos(legajo, nombre, notaA, notaB, CANTIDAD, "Ingrese legajo\n", "Ingrese nota 1\n", "ingrese nota 2:\n", "Ingrese nombre: ");
	if(retorno!=-1)
	{
		utnMostrarValoresVariosTipos(legajo, nombre, notaA, notaB, 2);
		utnOrdenarDatosPorNumero(legajo, nombre, notaA, notaB, CANTIDAD);

		printf("Ordenado :\n");
		utnMostrarValoresVariosTipos(legajo, nombre, notaA, notaB, 2);

	}
	utnMostrarValoresVariosTipos(legajo, nombre, notaA, notaB, 2);
	utnOrdenarDatosPorNumero(legajo, nombre, notaA, notaB, CANTIDAD);

	printf("Ordenado :\n");
	utnMostrarValoresVariosTipos(legajo, nombre, notaA, notaB, 2);
	return EXIT_SUCCESS;
}
void utnOrdenarDatosPorString(int posicion[] , char cadena[][50] , int numA[],int numB[], int tam)
{
	int auxiliarInt;
	float auxiliarFloat;
	char auxiliarString[50];
	for (int i = 0; i < tam - 1; i++)
	{
		for (int j = i + 1; j < tam; j++)
		{
			if (strcmp(cadena[i], cadena[j]) > 0) //Criterio de ordenamiento
			{
				auxiliarFloat = numA[i];
				numA[i] = numA[j];
				numA[j] = auxiliarFloat;

				auxiliarInt = numB[i];
				numB[i] = numB[j];
				numB[j] = auxiliarInt;

				auxiliarInt = posicion[i];
				posicion[i] = posicion[j];
				posicion[j] = auxiliarInt;

				strcpy(auxiliarString, cadena[i]);
				strcpy(cadena[i], cadena[j]);
				strcpy(cadena[j], auxiliarString);

			}
		}
	}
}
void utnOrdenarDatosPorNumero(int posicion[], char cadena[][50], int numA[],
		int numB[], int tam)
{
	int auxiliarInt;
	float auxiliarFloat;
	char auxiliarString[50];
	for (int i = 0; i < tam - 1; i++)
	{
		for (int j = i + 1; j < tam; j++)
		{
			if (numA[i] < numA[j]) //Criterio de ordenamiento
			{
				auxiliarFloat = numA[i];
				numA[i] = numA[j];
				numA[j] = auxiliarFloat;

				auxiliarInt = numB[i];
				numB[i] = numB[j];
				numB[j] = auxiliarInt;

				auxiliarInt = posicion[i];
				posicion[i] = posicion[j];
				posicion[j] = auxiliarInt;

				strcpy(auxiliarString, cadena[i]);
				strcpy(cadena[i], cadena[j]);
				strcpy(cadena[j], auxiliarString);

			}
		}
	}
}

