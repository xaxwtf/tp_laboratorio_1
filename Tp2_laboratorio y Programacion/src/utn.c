/*
 * utn.c
 *
 *  Created on: 7 sep. 2020
 *      Author: roid
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <strings.h>
/**
 * /brief solicita el usuario un entero y lo guarda
 * /param char* es el mensaje a imprimir al solicitar el entero
 * /param char* es el mensaje a imprimir en caso de que no se ingrese un entero
 * /param int* es el puntero en el cual se guardara el entero obtenido
 * /param int son la cantidad de intentos de los cuales dispondra el usuario para ingresar un entero
 * /param int determina el maximo numero que el usuario podra igresar
 * /param int determina el minimo numero que el usuario podra ingresar
 *
 * /return (-1)error (0)OK
 *
 */
int utn_getInt(char* msj, char* errormsj,int*intObtenido, int intentos, int max, int min)
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
/**
 * /brief solicita el usuario un flotante y lo guarda
 * /param char* es el mensaje a imprimir al solicitar el dato
 * /param char* es el mensaje a imprimir en caso de que no se ingrese un flotante
 * /param float* es la direccion de memoria que guardara el dato obtenido
 * /param int son la cantidad de intentos de los cuales dispondra el usuario para ingresar un dato valido
 * /param int determina el maximo numero que el usuario podra igresar
 * /param int determina el minimo numero que el usuario podra ingresar
 *
 * /return (-1)error (0)OK
 *
 */
int utn_getFloat(char* msj, char* errormsj,float*floatObtenido, int intentos, int max, int min)
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
/**
 * /brief solicita el usuario un solo caracter y lo guarda
 * /param char* es el mensaje a imprimir al solicitar el dato
 * /param char* es el mensaje a imprimir en caso de que no se ingrese un caracter valido
 * /param float* es la direccion de memoria que guardara el dato obtenido
 * /param int son la cantidad de intentos de los cuales dispondra el usuario para ingresar un dato valido
 * /param int determina el maximo numero que el usuario podra igresar
 * /param int determina el minimo numero que el usuario podra ingresar
 *
 * /return (-1)error (0)OK
 *
 */
int utn_getChar(char* msj, char* errormsj,char* caracterObt, int intentos)
{
	int r=-1;
	char aux;
	for(int i=0;i<intentos;i++)
	{
		printf("%s",msj);
		if(scanf("%c",&aux)!=0)
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
/**
 * /brief obtiene numero maximo de un array de enteros
 * /param int* es el array el cual sera analizado
 * /param int es el tamaño del array
 * /param int* es la direccion de memoria donde guardara el resultado obtenido
 *
 * /return (-1)error (0)OK
 *
 */
int utn_array_calcular_max(int* array,int len,int* resultado)
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
/**
 * /brief obtiene numero minimo de un array de enteros
 * /param int* es el array el cual sera analizado
 * /param int es el tamaño del array
 * /param int* es la direccion de memoria donde guardara el resultado obtenido
 *
 * /return (-1)error (0)OK
 *
 */
int utn_array_calcular_min(int* array,int len,int* resultado)
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
/**
 * /brief obtiene el promedio de un array de enteros
 * /param int* es el array el cual sera analizado
 * /param int es el tamaño del array
 * /param int* es la direccion de memoria donde guardara el resultado obtenido
 *
 * /return (-1)error (0)OK
 *
 */
int utn_array_calcular_prom(int* array,int len,float* resultado)
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
/**
 * /brief guarda una array de caracteres ingresada por el usurio
 * /param char* es la direccion de memoria donde sera guardada
 * /param int es el tamaño maximo del array
 * /return (-1)error (0)OK
 *
 */
int utn_myGets(char* cadena, int len)
{
	__fpurge(stdin);
	fgets(cadena,len,stdin);
	cadena[strlen(cadena)-1]='\0';
	return 0;
	}
/**
 * /brief solicita al usuario una cadena de caracteres y lo guarda
 * /param char* es el mensaje a imprimir al solicitar la cadena
 * /param char* es la dirreccion de memoria donde se guardara la cadena
 * /param int es el tamaño maximo que podra la cadena;
 *
 * /return (-1)error (0)OK
 *
 */
int utn_pedir_cadena(char* mensaje, char* cadena, int len)
{
	int r=-1;
	if(mensaje!=NULL && cadena !=NULL && len>0)
	{
		printf("%s",mensaje);
		utn_myGets(cadena, len);
		r=0;
	}
	return r;
}
/**
 * /brief Recibe una cadena de caracteres y valida que sean solo letras
 * /param char* es la cadena a ser analizada
 *
 * /return (-1)error (0)OK
 *
 */
int utn_soloLetras(char* vec)
{
    int r=0;
    int i=0;
    if(vec!=NULL)
    {
    	 while(vec[i]!='\0')
    	 {
    	    if((vec[i]<'a'||vec[i]>'z') && (vec[i]<'A'||vec[i]>'Z') && vec[i]!=' ')
    	     {
    	          r=-1;
    	     }
    	     i++;
    	  }
    }
    else{
    	r=-1;
    }

    return r;
}
