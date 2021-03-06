/*
 ============================================================================
 Name        : 1A.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 5
#define ASC 1
#define DESC 0

typedef struct{
	int id;
	char nombre[20];
	char tipo;
	float efectividad;
}eVacuna;


int aplicarAumento(float* precio);

void reemplazarCaracteres(char* cadena, char caracter, char caracter2);

int ordenarVacunasPorTipoYEfectividad(eVacuna vec[], int tam, int criterio);


int main(void) {

	float precio = 102;

	aplicarAumento(&precio);

	printf("%.2f\n\n", precio);

	char cadena[20] = {"garabato"};
	char caracter = 'a';
	char caracter2 = 'u';

	reemplazarCaracteres(cadena, caracter, caracter2);
	printf("%s", cadena);

	eVacuna vacunas[TAM];

	ordenarVacunasPorTipoYEfectividad(vacunas, TAM, DESC);

	return 0;
}

int aplicarAumento(float* precio)
{
	float todoOk = 0;
	float aumento = 0;
	float num;
	num = *precio;


	if(precio != NULL && precio > 0)
	{
		aumento = (float) (num*5) / 100;


		*precio = *precio + aumento;
	}

	return todoOk;
}

void reemplazarCaracteres(char* cadena, char caracter, char caracter2)
{
	char caracterNuevo = caracter2;

	if(cadena!=NULL)
	{
		for(int i = 0; i < strlen(cadena); i++)
		{
			if(cadena[i] == caracter)
			{
				cadena[i] = caracterNuevo;
			}
		}
	}



}


int ordenarVacunasPorTipoYEfectividad(eVacuna vec[], int tam, int criterio)
{
    int todoOk = 0;
    eVacuna auxVacuna;

    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam -1; i++)
        {
            for(int j= i + 1; j < tam; j++)
            {
                if(((vec[i].tipo == vec[j].tipo) && (vec[i].efectividad > vec[j].efectividad) && criterio)
                ||((vec[i].tipo == vec[j].tipo) && (vec[i].efectividad < vec[j].efectividad) && !criterio)
				||((vec[i].tipo != vec[j].tipo) && (vec[i].tipo > vec[j].tipo) && criterio)
				||((vec[i].tipo != vec[j].tipo) && (vec[i].tipo < vec[j].tipo) && !criterio))

                {
                	auxVacuna = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxVacuna;
                }

            }
        }
        todoOk = 1;
    }
    return todoOk;
}










