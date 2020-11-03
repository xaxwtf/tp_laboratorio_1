#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* nuevo;
	char aux1[900],aux2[900],aux3[900],aux4[900];
	int r=0;
	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		fscanf(pFile,"%[^\n]\n",aux1);
		do{
			r=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",aux1,aux2,aux3,aux4);
			if(r==4)
			{
				nuevo=employee_newParametros(aux1, aux2, aux3, aux4);
				if(nuevo!=NULL)
				{
					ll_add(pArrayListEmployee, nuevo);
				}
			}
		}while(feof(pFile)==0);
		r=1;
	}
    return r;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* nuevo;
	int r=-1;

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		do{
			nuevo=employee_new();
			if(nuevo!=NULL && fread(nuevo,sizeof(Employee),1,pFile)==1)
			{
				ll_add(pArrayListEmployee,nuevo);
			}
			else{
				employee_delete(nuevo);
			}
		}while(feof(pFile)==0);
		r=0;
	}
    return r;
}
