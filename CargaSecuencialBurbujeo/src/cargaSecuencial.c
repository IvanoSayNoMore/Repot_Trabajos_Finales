/*
 * cargaSecuencial.c
 *
 *  Created on: 9 abr 2022
 *      Author: Usuario Programador
 */
#include "cargaSecuencial.h"
#include "InPut.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void utnMostrarValoresVariosTipos(int numeracion[], char cadenaCaracteres[][50], int numeroA[], int numeroB[],
		int cantidad)
{
	for (int i = 0; i < cantidad; i++)
	{
		printf("%d\t%-20s %4d\t%4d\n", numeracion[i], cadenaCaracteres[i], numeroA[i],
				numeroB[i]);
	}
}


int utnCargaValoresVariosTipos(int numeracion[], char cadenaCaracteres[][50], int numeroA[], int numeroB[],
		int cantidad,char* mensajeNumeracion,char* mensajeNumeroA, char* mensajeNumeroB, char* mensajeCadenaChar)
{
	int retorno=0;
	float auxIngreso;
	for (int i = 0; i < cantidad; i++)
	{
		retorno=utnGetNumero(&auxIngreso, mensajeNumeracion, "Error", "Mensaje seguir o no", 0, 10, 2);
		//printf("%d",retorno);
		if(retorno==-1)
		{
			printf("Error");
			break;
		}
		else
		{
			numeracion[i]=auxIngreso;
		}

		retorno=utnGetNumero(&auxIngreso, mensajeNumeroA, "Error", "Mensaje seguir o no", 0, 10, 2);
		printf("%d",retorno);
		if(retorno==-1)
		{
			printf("Error");
			break;
		}
		else
		{
			numeroA[i]=auxIngreso;
		}

		retorno=utnGetNumero(&auxIngreso, mensajeNumeroB, "Error", "Mensaje seguir o no", 0, 10, 2);
		printf("%d",retorno);
		if(retorno==-1)
		{
			printf("Error");
			break;
		}
		else
		{
			numeroB[i]=auxIngreso;
		}

		retorno=utnRecibeCadenaSoloCaracteres(cadenaCaracteres[i],mensajeCadenaChar, 2,10);
		printf("\n aca %d\n",retorno);
	}
	return retorno;
}

int IngresarEntero(char mensaje[])
{
	int numeroIngresado;
	printf("%s", mensaje);
	scanf("%d", &numeroIngresado);

	return numeroIngresado;
}

int utnRecibeCadenaSoloCaracteres(char cadena[],char mensaje[],int reintentos,int tam)
{
	setbuf(stdout,NULL);
	char auxiliarString[1000];
	int valido=0;
	int retorno;
	int largo;

	if (cadena != NULL && mensaje != NULL)
	{
		do
		{
			if(reintentos==0)
			{
				retorno=0;
				break;
			}
			printf(mensaje);
			fflush(stdin);
			fgets(auxiliarString,21,stdin);
			largo=strlen(auxiliarString);

			valido=0;

			if( largo > tam )
			{
				reintentos--;
				valido=1;
				printf("Ingreso demaciados caracteres. Quedan %d intentos\n",reintentos);
			}
			if(valido==1|| auxiliarString[0]==' '||auxiliarString[0]=='\n')
			{
				reintentos--;
				valido=1;
				printf("Por favor, no ingrese espacios o enter en primer lugar. Quedan %d intentos\n",reintentos);
			}
			if(valido==0)
			{
				for(int i=0;i<largo-1;i++)
				{
					if((auxiliarString[i]<'a'||auxiliarString[i]>'z')&&(auxiliarString[i]<'A'||auxiliarString[i]>'Z')&&!(auxiliarString[i]==' '))
					{
						valido=1;
						reintentos--;
						printf("Por favor, ingrese solo letras. Quedan %d intentos\n",reintentos);
						break;
					}
				}
			}

		}while(valido!=0);

		if(valido==0)
		{
			auxiliarString[largo-1]='\0';
			strcpy(cadena, auxiliarString);
			retorno=1;
		}

	}
	return retorno;
}

