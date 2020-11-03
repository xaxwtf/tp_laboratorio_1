#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Controller.h"
#include "utn.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	int r=0;
	pFile=fopen(path,"r");
	if(pFile!=NULL)
	{
		r=parser_EmployeeFromText(pFile, pArrayListEmployee);
		fclose(pFile);
	}
    return r;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	int r=0;
	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		pFile=fopen(path,"rb");
		if(pFile!=NULL)
		{
			parser_EmployeeFromBinary(pFile, pArrayListEmployee);
			fclose(pFile);
			r=1;
		}
	}
    return r;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	Employee* nuevo;
	int ok=1;
	nuevo=employee_new();
	if(nuevo!=NULL)
	{
		if(ok==1 &&
		(utn_pedirCadenadeUndeunDeterminadoTam(nuevo->nombre, "\nIndique el nombre del empleado: ", 3, 128, 1)
				||utn_soloLetras(nuevo->nombre)))
		{
			ok=0;
		}
		if(ok==1 && utn_getInt("\nindique la cantidad de Horas Trabajadas", "\nError,la cantidad horas ingresadas no es valida", &nuevo->horasTrabajadas, 3, 9999999, 0))
		{
			ok=0;
		}
		if(ok==1 && utn_getInt("\nindique el Sueldo", "Error, el sueldo indicado no es valido", &nuevo->sueldo, 3, 999999, 1))
		{
			ok=0;
		}
		if(ok==1)
		{
			employee_setId(nuevo, employee_generarId());
			ll_add(pArrayListEmployee, nuevo);
		}
	}
    return ok;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	Employee* aux;
	Employee mod;
	int bufferInt;
	char bufferString[300];
	int indice,opc;
	int r=-1;
	if(pArrayListEmployee!=NULL)
	{
		utn_getInt("\nindique el id Del Empleado que desea modificar:", "\nError,el id indicado no es valido", &mod.id, 3, 99999999, 1);
		if(!controller_buscarOcurrenciaxId(pArrayListEmployee, mod.id, &indice))
		{
			aux=ll_get(pArrayListEmployee, indice);
			mod=*aux;
			do{
				printf("---Modificar--- ID: %d\n"
						"1. Nombre: %s\n"
						"2. Horas Trabajadas: %d\n"
						"3. Sueldo: %d\n"
						"4. Salir y Guardar Cambios\n"
						"5. Salir",mod.id,mod.nombre,mod.horasTrabajadas,mod.sueldo);
				utn_getInt(" ", "\nLa opcion indicada no es valida", &opc, 1, 5, 1);
				switch(opc)
				{
					case 1:
						if(utn_pedirCadenadeUndeunDeterminadoTam(bufferString, "\nindique el Nombre: ", 3, 128, 1)==0 &&utn_soloLetras(bufferString)==0)
						{
							employee_setNombre(&mod, bufferString);
						}
						break;
					case 2:
						if(!utn_getInt("\nindique el Las Horas Trabajadas:", "\nerror,el numero indicado no es valido", &bufferInt, 3, 9999999, 1))
						{
							employee_setHorasTrabajadas(&mod, bufferInt);
						}
						break;
					case 3:
						if(!utn_getInt("\nindique el Sueldo:", "\nerror,el numero indicado no es valido", &bufferInt, 3, 9999999, 1))
						{
							employee_setSueldo(&mod, bufferInt);
						}
						break;
					case 4:
						*aux=mod;
						opc=0;
						break;
					case 5:
						opc=0;
						break;
				}
			}while(opc!=0);
			r=0;
		}
	}
    return r;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int r=-1;
	Employee* aux;
	int indice,opc,idAux;
	int ok=1;
	if(pArrayListEmployee!=NULL)
	{
		if(!utn_getInt("\nindique el numero de ID:", "\nError, el ID indicado esta fuera de rango",&idAux , 3, 999999, 1))
		{
			if(!controller_buscarOcurrenciaxId(pArrayListEmployee, idAux, &indice))
			{
				r=0;
				aux=(Employee*)ll_get(pArrayListEmployee, indice);
				do{
					printf("\n-----CONFIRMAR BAJA DE EMPLEADO-----ID=%d "
							"\n Name:  %s "
							"\n Horas Trabajadas: %d"
							"\n Sueldo: %d"
							"\n 1-SI"
							"\n 2-NO",aux->id,aux->nombre,aux->horasTrabajadas,aux->sueldo);
					utn_getInt(" ", "la opcion indicada no es valida", &opc, 1, 2, 1);
					switch(opc){
						case 1:
							ll_remove(pArrayListEmployee, indice);
							ok=0;
							break;
						case 2:
							ok=0;
							break;
					}
				}while(ok);
				}
			else{
				printf("\nEl Empleado Indicado no existe:");
			}
		}
	}
	return r;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int r=0;
	Employee* aux;
	printf("   ID\t                   NOMBRE\tHORAS TRABAJADAS\t    SUELDO\n");
	for(int i=0;i<ll_len(pArrayListEmployee);i++)
	{
		aux=ll_get(pArrayListEmployee, i);
		employee_imprimir_unElemento(aux);
		r=1;
	}
	return r;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int r=0;
	int opc=12323;
	if(pArrayListEmployee!=NULL)
	{
		do{
			utn_getInt("ORDERNAR EMPLEADOS x:\n"
					"1-Nombre\n"
					"2-Horas Trabajadas\n"
					"3-Sueldo\n"
					"4-ID\n"
					"5-Atras", "\nerror,la opcion indicada no es valida", &opc, 1, 5, 1);
			switch(opc)
			{
			case 1:
				r=ll_sort(pArrayListEmployee, employee_compararNombres,controller_Acendente_o_decendente());
				opc=5;
				break;
			case 2:
				ll_sort(pArrayListEmployee, employee_compararHorasTrabajadas, controller_Acendente_o_decendente());
				opc=5;
				break;
			case 3:
				ll_sort(pArrayListEmployee, employee_compararSueldo, controller_Acendente_o_decendente());
				opc=5;
				break;
			case 4:
				ll_sort(pArrayListEmployee, employee_compararId, controller_Acendente_o_decendente());
				opc=5;
				break;
			}

		}while(opc!=5);

	}
    return r;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	Employee* aux;
	char* encabezado="id,nombre,horasTrabajadas,sueldo";
	int r=-1;
	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		pFile=fopen(path,"w");
		if(pFile!=NULL)
		{
			fprintf(pFile,"%s\n",encabezado);
			for(int i=0;i<ll_len(pArrayListEmployee);i++)
			{
				aux=(Employee*)ll_get(pArrayListEmployee, i);
				fprintf(pFile,"%d,%s,%d,%d\n",aux->id,aux->nombre,aux->horasTrabajadas,aux->sueldo);
			}
			fclose(pFile);
		}
		r=0;
	}
    return r;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	Employee* aux;
	int r=-1;
	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		pFile=fopen(path,"wb");
		if(pFile!=NULL)
		{
			for(int i=0;i<ll_len(pArrayListEmployee);i++)
			{
				aux=(Employee*)ll_get(pArrayListEmployee, i);
				if(aux!=NULL)
				{
					fwrite(aux,sizeof(Employee),1,pFile);
				}
			}
			fclose(pFile);
		}
		r=0;
	}
    return r;
}

/**
 * /brief busca un empleado por su ID
 * /param linkendList* es la lista dinamica
 * /param int es el id por el cual se buscara el empleado
 * /param int* es la direcion de memoria donde se guardara el indice en el cual se encontro el employee
 * /param
 * /return (0)OK (-1)Error
 *
 */
int controller_buscarOcurrenciaxId(LinkedList* lista,int id, int* indice)
{
	Employee* aux;
	int r=-1;
	int idAux;
	for(int i=0;i<ll_len(lista);i++)
	{
		aux=(Employee*)ll_get(lista, i);
		if(!employee_getId(aux,&idAux))
		{
			if(idAux==id)
			{
				*indice=i;
				r=0;
				break;
			}
		}
	}
	return r;
}

/**
 * /briefes un menu en el cual se pedira que eliga entre 2 opciones Acendente y decendente
 * /param
 * /return (1)acendente (0)decentente
 *
 */
int controller_Acendente_o_decendente()
{
	int opc=10;
	int r;
	do{
		utn_getInt("\nIndique El Orden:\n"
				"1-Acendente\n"
				"2-Decendente", "\n!!!Error, la opcion indicada no es valida", &opc, 1, 2, 1);
		switch(opc)
		{
			case 1:
				opc=0;
				r=1;
				break;
			case 2:
				opc=0;
				r=0;
				break;
		}
	}while(opc!=0);
	return r;
}
