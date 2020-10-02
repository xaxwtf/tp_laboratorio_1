/*
 ============================================================================
 Name        : Tp2_laboratorio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "arrayEmployees.h"
#define TAM 3


int main(void) {
	sEmployee empleados[TAM];
	int opc=123;
	employee_init(empleados, TAM);
	do{
		utn_getInt("\n-----ESTRUCTURAS----- "
				"\n 1-Alta employee"
				"\n 2-INFORMAR"
				"\n 3-Modificar employee"
				"\n 4-Baja employee"
				"\n 0-salir", "error,la opcion indicada no es valido", &opc, 1, 4, 0);
		switch(opc)
		{
			case 1:
				employee_alta(empleados, TAM);
				break;
			case 2:
				if(employee_buscarOcurrencia_empty(empleados, TAM, 0)!=-1)
				{
					informar(empleados, TAM);
				}
				else{
					printf("\nno hay datos Cargados");
				}
				break;
			case 3:
				if(employee_buscarOcurrencia_empty(empleados, TAM, 0)!=-1)
				{
					if(employee_modificar(empleados, TAM))
					{
						printf("\nno hay concidencias");
					}
				}
				else{
					printf("\nno hay datos Cargados");
				}
				break;
			case 4:
				if(employee_buscarOcurrencia_empty(empleados, TAM, 0)!=-1)
				{
					if(employee_baja(empleados, TAM))
					{
						printf("\nno hay concidencias");
					}
				}
				else{
					printf("\nno hay datos Cargados");
				}
				break;
		}
	}while(opc!=0);
	return EXIT_SUCCESS;
}
