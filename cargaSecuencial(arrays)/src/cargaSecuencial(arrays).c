/*
 ============================================================================
 Name        : cargaSecuencial(arrays).c
 Author      : 
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

int main(void) {
	setbuf(stdout, NULL);
	float legajo[2];
	char nombre[2][50];
	int notaA[2];
	int notaB[2];
	utnCargaValoresVariosTipos(legajo, nombre, notaA, notaB, CANTIDAD, "Ingrese legajo\n", "Ingrese nota 1\n", "ingrese nota 2:\n", "Ingrese nombre: ");
	utnMostrarValoresVariosTipos(legajo, nombre, notaA, notaB, 2);

	return EXIT_SUCCESS;
}
