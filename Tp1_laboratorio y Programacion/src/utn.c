/*
 * utn.c
 *
 *  Created on: 7 sep. 2020
 *      Author: roid
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
/**
 * /brief solicita el usuario un entero y lo guarda
 * /param char* es el mensaje a imprimir al solicitar el entero
 * /param char* es el mensaje a imprimir en caso de que no se ingrese un entero
 * /param int* es el puntero en el cual se guardara el entero obtenido
 * /param int son la cantidad de intentos de los cuales dispondra el usuario para ingresar un entero
 * /param int determina el maximo numero que el usuario podra igresar
 * /param int determina el minimo numero que el usuario podra ingresar
 *
 * /return (-1)error (1)OK
 *
 */
int getInt(char* msj, char* errormsj,int*intObtenido, int intentos, int max, int min)
{
	int r=-1;
	int aux;
	if(msj!=NULL &&
		errormsj!=NULL &&
		intObtenido!=NULL &&
		intentos>0 &&
		max>=min
		){
		for(int i=0;i<intentos;i++)
		{
			printf("%s",msj);
			if(scanf("%d",&aux)!=0 && (aux>=min && aux<=max))
			{
				*intObtenido=aux;
				r=0;
				__fpurge(stdin);
				break;
			}
			__fpurge(stdin);
			printf("%s",errormsj);
		}
	}
	return r;
}
int getFloat(char* msj, char* errormsj,float*floatObtenido, int intentos, float max, float min)
{
	int r=-1;
	float aux;
	if(msj!=NULL &&
		errormsj!=NULL &&
		floatObtenido!=NULL &&
		intentos>0 &&
		max>=min
		){
		for(int i=0;i<intentos;i++)
		{
			printf("%s",msj);
			if(scanf("%f",&aux)!=0 && (aux>=min && aux<=max))
			{
				*floatObtenido=aux;
				r=0;
				__fpurge(stdin);
				break;
			}
			__fpurge(stdin);
			printf("%s",errormsj);
		}
	}
	return r;
}
int getChar(char* msj, char* errormsj,char* caracterObt, int intentos, char max, char min)
{
	int r=-1;
	char aux;
	for(int i=0;i<intentos;i++)
	{
		printf("%s",msj);
		if(scanf("%c",&aux)!=0 &&(aux<=max && aux>=min))
		{
			*caracterObt=aux;
			r=0;
			__fpurge(stdin);
			break;
		}
		__fpurge(stdin);
		printf("%s",errormsj);
	}
	return r;
}
int array_calcular_max(int* array,int len,int* resultado)
{
	int r=-1;
	int max;
	if(array!=NULL &&
		len>0 &&
		resultado!=NULL){
		max=array[0];
		for(int i=1; i<len; i++)
		{
			if(array[i]>max)
			{
				max=array[i];
			}
		}
		*resultado=max;
		r=0;
	}
	return r;
}
int array_calcular_min(int* array,int len,int* resultado)
{
	int r=-1;
	int min;
	if(array!=NULL &&
		len>0 &&
		resultado!=NULL){
		min=array[0];
		for(int i=1; i<len; i++)
		{
			if(array[i]<min)
			{
				min=array[i];
			}
		}
		*resultado=min;
		r=0;
	}
	return r;
}
int array_calcular_prom(int* array,int len,float* resultado)
{
	int r=-1;
	int acumulador=0;
	if(array!=NULL &&
		len>0 &&
		resultado!=NULL){
		for(int i=0; i<len; i++)
		{
			acumulador=acumulador+array[i];
		}
		*resultado=(float)acumulador/len;
		r=0;
	}
	return r;
}
