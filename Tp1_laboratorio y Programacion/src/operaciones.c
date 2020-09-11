/*
 * operaciones.c
 *
 *  Created on: 10 sep. 2020
 *      Author: roid
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
int sumar_flotantes(float num1, float num2, float* resultado)
{
	int r=-1;
	if(resultado!=NULL)
	{
		*resultado=num1+num2;
		r=0;
	}
	return r;
}
int restar_flotantes(float num1, float num2, float* resultado)
{
	int r=-1;
	if(resultado!=NULL)
	{
		*resultado=num1-num2;
		r=0;
	}
	return r;
}
int multiplicar_flotantes(float num1, float num2, float* resultado)
{
	int r=-1;
	if(resultado!=NULL)
	{
		*resultado=num1*num2;
		r=0;
	}
	return r;
}
int dividir_flotantes(float num1, float num2, float* resultado)
{
	int r=-1;
	if(resultado!=NULL)
	{
		if(num2!=0)
		{
			*resultado=num1/num2;
			r=0;
		}
		else{
			printf("Error, no se puede dividir por cero");
		}

	}
	return r;
}
int factorial_float(float num,int* resultado)
{
	int r=-1;
	int aux=(int)num;
	if(resultado!=NULL)
	{
		if(num-aux==0)
		{
			r=0;
			if(num==0)
			{
				*resultado=1;

			}
			else if(num<0)
			{
				printf("\nError, no se puede realizar el factorial de un numero negativo\n");
				r=-1;
			}
			else
			{
				for(int i=(aux-1);i>0;i--)
					{
						aux=aux*i;
					}
				*resultado=aux;
			}
		}
	}
	return r;


}
