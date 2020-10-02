/*
 * arrayEmployees.c
 *
 *  Created on: 30 sep. 2020
 *      Author: roid
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "utn.h"
#include "arrayEmployees.h"
/**
 * /brief lista todos los employee del array
 * /param sEmployee* es el array que va ser imprimido
 * /param int es el tamaño del array
 *
 * /return (-1)error (0)OK
 *
 */
int employee_listar(sEmployee* lista, int len)
{
	int r=-1;
	if(lista!=NULL && len>0)
	{
		r=0;
		printf("      Nombre     Apellido  Salario     Sector ID");
		for(int i=0;i<len;i++)
			{
				if(!lista[i].isEmpty)
				{
					printf("\n%12s %12s %10.2f   %2d     %2d",lista[i].name,lista[i].lastName,lista[i].salary,lista[i].sector,lista[i].id);
				}
			}
	}
	return r;
}
/**
 * /brief inicializa el campo isEmpty(1) del array en cada uno de sus elementos
 * /param sEmployee* es el array va ser moficiado
 * /param int es el tamaño del array
 *
 * /return (-1)error (0)OK
 *
 */
int employee_init(sEmployee* lista, int len)
{
	int r=-1;
	if(lista!=NULL && len>0)
	{
		r=0;
		for(int i=0;i<len;i++)
		{
			lista[i].isEmpty=1;
		}
	}
	return r;
}
/**
 * /brief busca una pocicion libre en el array y la devuelve el indice por referencia
 * /param sEmployee* es el array a analizar
 * /param int es el tamaño del array
 * /param int* es la direccion de memoria donde guardara el indice obtenido
 *
 * /return (-1)error (0)OK
 *
 */
int employee_buscarLibre(sEmployee* lista, int len, int* indiceLibre)
{
	int r=-1;
	if(lista!=NULL && len>0 && indiceLibre!=NULL)
	{
		for(int i=0;i<len;i++)
		{
			if(lista[i].isEmpty==1)
			{
				r=0;
				*indiceLibre=i;
				break;
			}
		}
	}
	return r;
}

/**
 * /brief da de alta un employee
 * /param sEmployee* es el array
 * /param int es el tamaño del array
 *
 * /return (-1)error (0)OK
 *
 */
int employee_alta(sEmployee* lista, int len)
{
	int r=-1;
	int todoOk=1;
	sEmployee aux;
	if(lista!=NULL && len>0)
	{
		if(employee_buscarLibre2(lista, len)!=-1)
		{

			if(todoOk==1 && (utn_pedir_cadena("\nname: ", aux.name, tam_string) || utn_soloLetras(aux.name)))
			{
				printf("%d",todoOk);
				todoOk=0;
			}

			if(todoOk==1 && (utn_pedir_cadena("\nlastName: ", aux.lastName , tam_string) || utn_soloLetras(aux.lastName)))
			{
				todoOk=0;
			}
			if(todoOk==1 && utn_getFloat("\nindique el Salario:","\nerror debe ser mayor a 0", &aux.salary, 3, 999999999, 1))
			{
				todoOk=0;
			}
			if(todoOk==1 && utn_getInt("\nindique el sector(1-10): ", "\nerror,el sector indicado no existe", &aux.sector, 3, 10, 1))
			{
				todoOk=0;
			}
			aux.isEmpty=0;

			if(todoOk)
			{
				r=0;
				addEmployee(lista, len, employee_generarId(), aux.name, aux.lastName, aux.salary, aux.sector);
			}
		}
		else{
			printf("\n !!!!Registro lleno, no se pueden cargar mas empleados");
		}
	}
	return r;
}

/**
 * /brief Modifica un employee
 * /param sEmployee* es el array
 * /param int es el tamaño del array
 *
 * /return (-1)error (0)OK
 *
 */
int employee_modificar(sEmployee* lista,int len)
{
	int r=-1;
	sEmployee aux,mod;
	int indice,opc;
	int ok=1;
	if(lista!=NULL && len>0)
	{
		if(!utn_getInt("\nindique el ID:", "\nError, el iD es invalido",&aux.id , 3, len, 1))
		{
			indice=findEmployeeById(lista, len, aux.id);
			if(indice!=-1)
			{
				r=0;
				aux=lista[indice];
				do{
					printf("\n-----MODIFICAR EMPLOYEE-----ID= %d "
							"\n 1-Name:  %s"
							"\n 2-LastName: %s"
							"\n 3-Salary: %0.2f"
							"\n 4-Sector: %d"
							"\n 5-salir y descartar modificaciones"
							"\n 6-salir y guardar",aux.id,aux.name,aux.lastName,aux.salary, aux.sector);
					utn_getInt(" " ,"\nerror, la Opcion indicada no es valida", &opc, 1, 6, 1);
					switch(opc){
					case 1:
						if(utn_pedir_cadena("\nnew Name: ", mod.name, tam_string)||utn_soloLetras(mod.name))
						{
							printf("\nerror, indique solo letras");
						}
						else{
							strncpy(aux.name,mod.name,tam_string);
						}
						break;
					case 2:
						if(utn_pedir_cadena("\nnew LastName: ", mod.lastName, tam_string)||utn_soloLetras(mod.lastName))
						{
							printf("\nerror, indique solo letras");
						}
						else{
							strncpy(aux.lastName,mod.lastName,tam_string);
						}
						break;
					case 3:
						if(!utn_getFloat("\nNew Salary: ","\nerror, el numero indicado no es valido", &mod.salary, 1, 99999999, 1))
						{
							aux.salary=mod.salary;
						}
						break;
					case 4:
						if(utn_getInt("\nNew sector(1-10): ", "\nsector no valido", &mod.sector, 1, 10, 1))
						{
							aux.sector=mod.sector;
						}
						break;
					case 5:
						ok=0;
						break;
					case 6:
						ok=0;
						lista[indice]=aux;
						break;
					}
				}while(ok);
			}
		}
	}
	return r;
}

/**
 * /brief Da de Baja un employee
 * /param sEmployee* es el array
 * /param int es el tamaño del array
 *
 * /return (-1)error (0)OK
 *
 */
int employee_baja(sEmployee* lista, int len)
{
	int r=-1;
		sEmployee aux;
		int indice,opc;
		int ok=1;
		if(lista!=NULL && len>0)
		{
			if(!utn_getInt("\nindique el numero de ID:", "\nError, el ID indicado esta fuera de rango",&aux.id , 3, 999999, 1))
			{
				indice=findEmployeeById(lista, len, aux.id);
				if(indice!=-1)
				{
					r=0;
					aux=lista[indice];
					do{
						printf("\n-----CONFIRMAR BAJA DE EMPLOYEE-----ID=%d "
								"\n Name:  %s "
								"\n LastName: %s"
								"\n Salary: %0.2f"
								"\n Sector: %d"
								"\n 1-SI"
								"\n 2-NO",aux.id,aux.name,aux.lastName,aux.salary,aux.sector);

						utn_getInt(" ", "\nerror, la opcion indicada no es valida", &opc, 1, 2, 1);
						switch(opc){
						case 1:
							removeEmployee(lista, len, aux.id);
							ok=0;
							break;
						case 2:
							ok=0;
							break;
						}
					}while(ok);
				}
			}
		}
		return r;

}

/**
 * /brief imprime un empleado recibiendo el indice como referencia
 * /param sEmployee* es el array
 * /param int es el tamaño del array
 * /param es el indice del del cual se impriran los datos
 *
 * /return (-1)error (0)OK
 *
 */
int employee_imprimirxIndice(sEmployee* lista ,int len, int indice)
{
	int r=-1;
	if(lista!=NULL && len>0 &&indice >=0)
	{
		r=0;
		for(int i=0;i<len;i++)
		{
			if(i==indice)
			{
				printf("\n%20s",lista[i].name);
			}

		}
	}
	return r;
}

/**
 * /brief busca una Pocicion Libre en el array y devuelve el indice
 * /param sEmployee* es el array
 * /param int es el tamaño del array
 *
 * /return (-1)error  (algun indice valido)OK
 *
 */
int employee_buscarLibre2(sEmployee* lista, int len)
{
	int r=-1;
	if(lista!=NULL && len>0)
	{
		for(int i=0;i<len;i++)
		{
			if(lista[i].isEmpty==1)
			{
				r=i;
				break;
			}
		}
	}
	return r;
}

/**
 * /brief Genera un ID unico
 * /param void no recibe nada
 * /return algun id irepetible
 *
 */
int employee_generarId(void)
{
	static int id=0;
	id=id+1;
	return id;
}

/**
 * /brief busca en el array la 1ra concidencia con el id pasado como referencia y retorna el indice
 * /param sEmployee* es el array
 * /param int es el tamaño del array
 * /param int es el id a buscar en el array
 * /param es la direcion de memoria donde guardara el indice obtenido
 *
 * /return (-1)error (0)OK
 *
 */
int employee_buscarOcurrenciaId(sEmployee* lista, int len, int id, int* indice)
{
	int r=-1;
	if(lista!=NULL && len>0 && id>0 && indice!=NULL)
	{
		for(int i=0;i<len;i++)
		{
			if(id==lista[i].id)
			{
				r=0;
				*indice=i;
				break;
			}
		}
	}
	return r;
}
/**
 * /brief Ordena el Array segun el nombre
 * /param sEmployee* es el array
 * /param int es el tamaño del array
 * /param int es el orden en el cual se ordenara acendente(1) y decendente(0)
 *
 * /return (-1)error (0)OK
 *
 */
int employee_ordenarxNombre(sEmployee* lista, int len, int order)
{
	int r=-1;
	int flagSwap=1;
	sEmployee aux;
	if(lista!=NULL && len>0 && (order==0|| order==1))
	{
		r=0;
		do{
			flagSwap=0;
			for(int i=0;i<len;i++)
			{
				if((order==1 && strncmp(lista[i].name,lista[i+1].name,50)>0)
						||
					(order==0 && strncmp(lista[i].name,lista[i+1].name,50)>0))
				{
					aux=lista[i];
					lista[i]=lista[i+1];
					lista[i+1]=aux;
					flagSwap=1;
				}
			}
		}while(flagSwap);
	}
	return r;
}
/**
 * /brief Agrega un employee al array
 * /param sEmployee* es el array
 * /param int es el tamaño del array
 * /param int es el ID del employee
 * /param char* es el name del employee
 * /param char* es lastName del employee
 * /param float es el salary del employee
 * /param int es el sector del employee
 *
 * /return (-1)error (0)OK
 *
 */
int addEmployee(sEmployee* list, int len, int id, char* name,char* lastName,float salary,int sector)
{
	int r=-1;
	int indice;
	if(list!=NULL && len>0 && id>0 && name!=NULL && salary>0 && sector>0 && sector <=10)
	{
		employee_buscarLibre(list, len, &indice);
		list[indice].id=id;
		list[indice].isEmpty=0;
		list[indice].salary=salary;
		list[indice].sector=sector;
		strncpy(list[indice].name,name,tam_string);
		strncpy(list[indice].lastName,lastName,tam_string);
		r=0;
	}
 return r;
}
/**
 * /brief busca un employee x su ID y retorn el indice
 * /param sEmployee* es el array
 * /param int es el tamaño del array
 * /param int es el id Tomado como referencia
 *
 * /return (-1)error (un indice)OK
 *
 */
int findEmployeeById(sEmployee* list, int len,int id)
{
	int r=-1;
	if(list!=NULL && len>0 && id>0)
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].id==id)
			{
				r=i;
				break;
			}
		}
	}
 return r;
}
/**
 * /brief elimina de manera logica a un employee poniendo el isEmpty en 1
 * /param sEmployee* es el array
 * /param int es el tamaño del array
 * /param int es el id tomado como referencia
 *
 * /return (-1)error (0)OK
 *
 */
int removeEmployee(sEmployee* list, int len, int id)
{
	int r=-1;
	if(list!=NULL && len>0 && id>0)
	{
		list[findEmployeeById(list, len, id)].isEmpty=1;
		r=0;
	}
 return r;
}
/**
 * /brief Ordena el employee por lastName y sector
 * /param sEmployee* es el array
 * /param int es el tamaño del array
 * /param int es el orden en el cual va ordenar asendente (1) decentente(0)
 *
 * /return (-1)error (0)OK
 *
 */
int sortEmployees(sEmployee* list, int len, int order)
{
	int r=-1;
	sEmployee aux;
	int flagSwap=1;
		if(list!=NULL && len > 0 && (order==0|| order==1))
		{

			r=0;
			do{
				flagSwap=0;
				for(int i=0;i<len;i++)
				{
					if((order==1 && (list[i].isEmpty==0 && list[i+1].isEmpty==0) && (strncmp(list[i].lastName,list[i+1].lastName,tam_string)>0
																||
									(strncmp(list[i].lastName,list[i+1].lastName,tam_string)==0 && list[i].sector > list[i+1].sector)))
						||
					(order==0 && (list[i].isEmpty==0 && list[i+1].isEmpty==0) && (strncmp(list[i].lastName,list[i+1].lastName,tam_string)<0
																||
								(strncmp(list[i].lastName,list[i+1].lastName,tam_string)==0 && list[i].sector<list[i+1].sector))))
					{
						aux= list[i];
						list[i]=list[i+1];
						list[i+1]=aux;
						flagSwap=1;

					}
				}
			}while(flagSwap);
		}
		return r;
 return 0;
}
/**
 * /brief busca algun estado en especifico del isEmpty y retorna la 1r ocurrencia
 * /param sEmployee* es el array
 * /param int es el tamaño del array
 *  /param int es la condicion del isEmpty que busco true(1) false(0)
 *
 * /return (-1)error (el indice donde encontro la 1ra ocurrencia)OK
 *
 */
int employee_buscarOcurrencia_empty(sEmployee * lista, int len, int referencia)
{
	int r=-1;
		if(lista!=NULL && len>0)
		{
			for(int i=0;i<len;i++)
			{
				if(lista[i].isEmpty==referencia)
				{
					r=i;
					break;
				}
			}
		}
	return r;
}
/**
 * /brief muestra un menu e informa datos
 * /param sEmployee* es el array
 * /param int es el tamaño del array
 *
 * /return (-1)error (0)OK
 *
 */
int informar(sEmployee* lista, int len)
{
	int r=-1;
	float promedio;
	int ocurrencias;
	int opc=123;
	if(lista!=NULL && len>0)
	{
		r=0;
		do{
			utn_getInt("\nINFORMES"
					"\n1-Listado de los empleados ordenados alfabéticamente por Apellido y Sector"
					"\n2-Total y promedio de los salarios, y cuántos empleados superan el salario promedio."
					"\n3-Salir", "\nerror,opcion no valida", &opc, 1, 3, 1);
			switch(opc)
			{
				case 1:
					sortEmployees(lista, len, 1);
					employee_listar(lista, len);
					break;
				case 2:
					promedio=promedioSalarios(lista, len);
					ocurrencias=employee_contarSalariosArribaDe(lista, len, promedio);
					printf("\nSalario Promedio: %0.2f \nCantidad de Empleados que cobran sobre el promedio: %d",promedio,ocurrencias);
					break;
			}

		}while(opc!=3);
	}
	return r;
}
/**
 * /brief Calcula el Salario Promedio del array de employee
 * /param sEmployee* es el array
 * /param int es el tamaño del array
 *
 * /return (-1)error (0)OK
 *
 */
float promedioSalarios(sEmployee *lista,int tam)
{
    float total=0;
    float r;
    int j=0;
    for(int i=0;i<tam;i++)
    {
        if(!lista[i].isEmpty){
            total=total+lista[i].salary;
            j++;
        }
    }
    r=total/j;
    return r;

}
/**
 * /brief Cuenta la cantidad de employee que cobran arriba de la referencia
 * /param sEmployee* es el array
 * /param int es el tamaño del array
 * /param float es el salario de referencia al momento de contar
 *
 * /return (-1)error (cantidad de empleado que cobran arriba de la referencia)OK
 *
 */
int employee_contarSalariosArribaDe(sEmployee* lista, int len, float referencia)
{
	int r=-1;
	if(lista!=NULL && len>0)
	{
		r=0;
		for(int i=0;i<len;i++)
		{
			if(lista[i].salary>referencia)
			{
				r++;
			}
		}
	}
	return r;
}
