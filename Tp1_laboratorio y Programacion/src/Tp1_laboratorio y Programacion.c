/*
 ============================================================================
 Name        : Tp1_laboratorio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "operaciones.h"
#include "utn.h"

int main(void) {
	float num1=0;
	float num2=0;
	float resultados[4];
	int resultados_factorial[2];
	int divicionOK;
	int opc=999;
	char letra;
	do{
		printf("\n-----CALCULADORA----- "
				"\n 1-ingresar el 1er operando (A= %0.2f)"
				"\n 2-ingresar el 2do operando (B= %0.2f)"
				"\n 3-Calcular todas las Operaciones"
				"\n 4-informar resultados"
				"\n 5-salir\n",num1,num2);
		scanf("%d",&opc);
		__fpurge(stdin);
		switch(opc){
		case 1:
			if(getFloat("\nindique el un numero", "\nerror, igrese solo numeros", &num1, 3, 9999999, -9999999)!=0)
			{
				printf("\nerror!!!!los caracteres ingresados no son validos vuelva a intentarlo\n");
			}
			break;
		case 2:
			if(getFloat("indique el un numero", "error, igrese solo numeros", &num2, 3, 999999990, -9999999)!=0)
			{
				printf("\nerror!!!!los caracteres ingresados no son validos vuelva a intentarlo\n");
			}
			break;
		case 3:
			do{
				getChar("\na) Calcular la suma (A+B)"
				"\nb) Calcular la resta (A-B)"
				"\nc) Calcular la division (A/B)"
				"\nd) Calcular la multiplicacion (A*B)"
				"\ne) Calcular el factorial (A!)\nf)salir","error, no se indico un caracter valido\n", &letra, 3, 'f', 'a');
				switch(letra)
				{
					case 'a':
						if(!sumar_flotantes(num1, num2, &resultados[0])){
							printf("\nSuma realizada con exito");
						}
						else{
							printf("\nNo se ha podido realizar la operacion");
						}
						break;
					case 'b':
						if(!restar_flotantes(num1, num2, &resultados[1])){
							printf("\nresta realizada con exito");
						}
						else{
							printf("\nNo se ha podido realizar la operacion");
						}
						break;
					case 'c':
						divicionOK=dividir_flotantes(num1, num2, &resultados[2]);
						if(divicionOK==0)
						{
							printf("\nDivicion realizada con exito");
						}
						else{
							printf("\nNo se ha podido realizar la operacion");
						}
						break;
					case 'd':
						if(!multiplicar_flotantes(num1, num2, &resultados[3])){
							printf("\nMultiplicacion realizada con exito");
						}
							else{
							printf("\nNo se ha podido realizar la operacion");
						}
						break;
					case 'e':
						if(!factorial_float(num1, &resultados_factorial[0]))
						{
							printf("\nFactorial de A calculado Correctamente");
						}
						if(!factorial_float(num2, &resultados_factorial[1]))
						{
							printf("\nFactorial de B calculado Correctamente");
						}
						break;
				}

			}while(letra!='f');
			break;
		case 4:
			if(!divicionOK)
			{
				printf("\na) “El resultado de A+B es: %0.2f”"
				"\nb) “El resultado de A-B es: %0.2f”"
				"\nc) “El resultado de A/B es: %0.2f”"
				"\nd) “El resultado de A*B es: %0.2f”"
				"\ne) “El factorial de A es: %d y El factorial de B es: %d”",resultados[0],resultados[1],resultados[2],resultados[3],resultados_factorial[0],resultados_factorial[1]);
			}
			else{
				printf("\na) “El resultado de A+B es: %0.2f”"
				"\nb) “El resultado de A-B es: %0.2f”"
				"\nc) “No es posible dividir por cero”"
				"\nd) “El resultado de A*B es: %0.2f”"
				"\ne) “El factorial de A es: %d y El factorial de B es: %d”",resultados[0],resultados[1],resultados[3],resultados_factorial[0],resultados_factorial[1]);
			}
			break;
		}

	}while(opc!=5);

	return EXIT_SUCCESS;
}
