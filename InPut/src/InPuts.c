/*
 * InPuts.c
 *
 *  Created on: 9 abr 2022
 *      Author: Usuario Programador
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int utnMyGets(char* cadena, int longitud)
{
	fflush(stdin);
	fgets(cadena,longitud,stdin);
	cadena[strlen(cadena)-1]='\0';
	return 0;
}

int utnGetInt(int* pResultado)
{
	int retorno=-1;
	char buffer[1000];

	if(utnMyGets(buffer,sizeof(buffer))==0 && utnEsNumerica(buffer))
	{
		retorno=0;
		*pResultado=atoi(buffer);
	}

	return retorno;
}

int utnGetNumero(float* pNumeroIngresado, char* mensaje, char* mensajeError,char* mensajeSeguirNoSeguir, int minimo, int maximo, int reintentos)
{
	int retorno =1;
	int buffer;
	int verificacionFinal;

	if(pNumeroIngresado!=NULL && mensaje!=NULL && mensajeError!=NULL && mensajeSeguirNoSeguir!=NULL
			&& minimo<=maximo && reintentos>=0)

		do
		{

			printf("%s",mensaje);
			if(utnGetInt(&buffer)==0 && buffer>=minimo && buffer<=maximo)
			{
				*pNumeroIngresado=buffer;
				retorno=0;
				break;
			}
			reintentos--;
			if(reintentos!=0 && retorno!=0)
			{
				verificacionFinal=utnVerificacionConChar(mensajeSeguirNoSeguir,mensajeError);
				if(verificacionFinal==0)
				{
					reintentos=0;
					break;
				}
			}
			else
			{
				printf("No queden intentos.\n");
			}


		}while(reintentos>=1);

	return retorno;
}

int utnVerificacionConChar(char* mensajeValidacion,char* mensajeFinal)
{
	int retorno=0;
	char ingresoDeUsuario;
	printf("%s",mensajeValidacion);
	fflush(stdin);
	scanf("%c",&ingresoDeUsuario);
	ingresoDeUsuario=tolower(ingresoDeUsuario);

	if(ingresoDeUsuario=='s')
	{
		printf("\n %s \n",mensajeFinal);
		retorno =-1;
	}
	return retorno;
}

int utnEsNumerica(char* cadena)
{
	int retorno=1;
	int i=0;
	if(cadena[0]=='-')
	{
		i=1;
	}

	for(;cadena[i] != '\0';i++)
	{
		if(cadena[i]>'9' || cadena[i]<'0')
		{
			retorno=0;
			break;
		}
	}


	return retorno;
}

void utnMostrarResultados(float parametroPivot, float parametroA, float parametroB,float parametroAconDescuento,
		float parametroBconDescuento,float parametroAconAumento,float parametroBconAumento,float valorPorUnidadParametroB,
		float valorPorUnidadParametroA,float difDeValores)
{
	printf(	"KMs Ingresados...............: %.2f\n",parametroPivot);


	printf(	"Precio Aerolineas............: %.2f\n"
			"Precio con tarjeta de débito.: %.2f\n"
			"Precio con tarjeta de crédito: %.2f\n"
			"Precio Unitario..............: %.2f\n",parametroA,parametroAconDescuento,parametroAconAumento,valorPorUnidadParametroA);

	printf(	"Precio Latam.................: %.2f\n"
			"Precio con tarjeta de débito.: %.2f\n"
			"Precio con tarjeta de crédito: %.2f\n"
			"Precio Unitario..............: %.2f\n",parametroB,parametroBconDescuento,parametroBconAumento,valorPorUnidadParametroB);

	printf(	"\nLa diferencia es de..........: %.2f \n\n",difDeValores);

}

float utnIngresarFlotante(char mensaje[])
{
    float numero;

    printf("%s",mensaje);
	scanf("%f",&numero );

	return numero;
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

int utnIngresarAlfanumerico(char cadena[], char mensaje[], int tam)
{
	setbuf(stdout,NULL);
	char auxiliarString[1000];
	char reintentar='n';
	int valido=0;
	int retorno=0;
	int largo;

	if(cadena != NULL && mensaje != NULL)
	{
		do
		{
			printf(mensaje);
			fflush(stdin);
			fgets(auxiliarString,21,stdin);
			largo=strlen(auxiliarString);

			if(largo>tam)
			{
				valido=1;
				puts("Ingreso demaciados caracteres\n");
				reintentar=utnIngresarChar("Desea volver a intentar? Oprima la tecla 's' si es asi. Sino saldra");

			}
			if(valido==0)
			{
				auxiliarString[largo-1]='\0';
				strcpy(cadena, auxiliarString);
				retorno=1;
			}

		}while(reintentar=='s');

	}

	return retorno;
}

char utnIngresarChar(char mensaje[])
{
	char opcion;
	fflush(stdin);
	printf("%s",mensaje);
	scanf("%c",&opcion);
	opcion=tolower(opcion);


	return opcion;

}


