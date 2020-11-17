#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "utn.h"

/**
 * /brief settea el id de un employee
 * /param Employee* es el puntero a un employee
 * /param es el id que se guardara en el employee
 *
 * /return (0)OK (-1)Error
 *
 */
int employee_setId(Employee* this, int id)
{
  int r=-1;
  if(this!=NULL && employee_isValid_id(id))
  {
	this->id=id;
	r=0;
  }
  return r;
}
/**
 * /brief valida que sea un id valido
 * /param int es el id a validar
 *
 * /return (1)OK (0)Error
 *
 */
int employee_isValid_id(int id)
{
	int r=0;
	if(id>0)
	{
		r=1;
	}
	return r;
}

/**
 * /brief settea el nombre de un employee
 * /param Employee* es el puntero a un employee
 * /param char* es el nombre que se guardara en el employee
 *
 * /return (0)OK (-1)Error
 *
 */
int employee_setNombre(Employee* this, char* nombre)
{
  int r=-1;
  if(this!=NULL && employee_isValid_nombre(nombre))
  {
	strcpy(this->nombre,nombre);
	r=0;
  }
  return r;
}

/**
 * /brief valida que sea un nombre sea valido
 * /param char* es el nombre a validar
 *
 * /return (1)OK (0)Error
 *
 */
int employee_isValid_nombre(char* nombre)
{
	int r=1;
	if(utn_soloLetras(nombre))
	{
		r=0;
	}
	return r;
}

/**
 * /brief settea las horas trabajadas de un employee
 * /param Employee* es el puntero a un employee
 * /param int son las horasTrabajadas que se guardara en el employee
 *
 * /return (0)OK (-1)Error
 *
 */
int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
  int r=-1;
  if(this!=NULL && employee_isValid_horasTrabajadas(horasTrabajadas))
  {
	this->horasTrabajadas=horasTrabajadas;
	r=0;
  }
  return r;
}

/**
 * /brief valida que las horas trabajadas
 * /param int son las horas trabajadas a validar
 *
 * /return (1)OK (0)Error
 *
 */
int employee_isValid_horasTrabajadas(int horasTrabajadas)
{
	int r=0;
	if(horasTrabajadas>0)
	{
		r=1;
	}
	return r;
}

/**
 * /brief settea el sueldo de un employee
 * /param Employee* es el puntero a un employee
 * /param int es el sueldo que se guardara en el employee
 *
 * /return (0)OK (-1)Error
 *
 */
int employee_setSueldo(Employee* this, int sueldo)
{
  int r=-1;
  if(this!=NULL && employee_isValid_sueldo(sueldo))
  {
	this->sueldo=sueldo;
	r=0;
  }
  return r;
}

/**
 * /brief valida el sueldo
 * /param int es el sueldo a validar
 *
 * /return (1)OK (0)Error
 *
 */
int employee_isValid_sueldo(int sueldo)
{
	int r=0;
	if(sueldo>0)
	{
		r=1;
	}
	return r;
}

/**
 * /brief reserva memoria para un employee y devuelve el puntero a esa reserva
 * /param
 *
 * /return (un puntero a employee)OK (NULL)Error
 *
 */
Employee* employee_new()
{
	Employee* nuevo=(Employee*)malloc(sizeof(Employee));
	return nuevo;
}

/**
 * /brief elimina  a un employee
 * /param Employee* es el employee
 *
 * /return
 *
 */
void employee_delete(Employee* this)
{
	free(this);
}

/**
 * /brief obtiene el id De un employee
 * /param int* es la direccion de memoria donde se guardara el id
 * /param
 * /return (1)OK (0)Error
 *
 */
int employee_getId(Employee* this, int* id)
{
	int r=-1;
	if(this!=NULL && id!=NULL)
	{
		*id=this->id;
		r=0;
	}
	return r;
}

/**
 * /brief obtiene el Nombre De un employee
 * /param char* es la direccion de memoria donde se guardara el Nombre
 * /param
 * /return (1)OK (0)Error
 *
 */
int employee_getNombre(Employee* this, char* nombre)
{
	int r=-1;
	if(this!=NULL&&nombre!=NULL)
	{
		r=0;
		strcpy(nombre,this->nombre);
	}
	return r;
}

/**
 * /brief obtiene las horasTrabajadas De un employee
 * /param int* es la direccion de memoria donde se guardara el las horasTrabajadas
 * /param
 * /return (1)OK (0)Error
 *
 */
int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
	int r=-1;
	if(this!=NULL && horasTrabajadas!=NULL)
	{
		*horasTrabajadas=this->horasTrabajadas;
		r=0;
	}
	return r;
}

/**
 * /brief obtiene el sueldo De un employee
 * /param int* es la direccion de memoria donde se guardara el sueldo
 * /param
 * /return (1)OK (0)Error
 *
 */
int employee_getSueldo(Employee* this, int* sueldo)
{
	int r=-1;
	if(this!=NULL && sueldo!=NULL)
	{
		*sueldo=this->sueldo;
		r=0;
	}
  return r;
}

/**
 * /brief se reserva memoria para un emloyee y se le settea los campos
 * /param char* es el strin de un id
 * /param char* es el strin de un nombre
 * /param char* es el strin de las horasTrabajadas
 * /param char* es el strin del sueldo
 * /param
 * /return (un puntero a employee)OK (NULL)Error
 *
 */
Employee* employee_newParametros(char* idStr,char* nombre,char* horasTrabajadasStr,char* sueldoStr)
{
  int ok=1;
  Employee* nuevo=employee_new();
  if(nuevo!=NULL)
  {
	employee_setId(nuevo, atoi(idStr));
	if(ok==1 && employee_setNombre(nuevo,nombre))
	{
		ok=0;
	}
	if(ok==1 && employee_setHorasTrabajadas(nuevo,atoi(horasTrabajadasStr)))
	{
		ok=0;
	}
	if(ok==1 && employee_setSueldo(nuevo,atoi(sueldoStr)))
	{
		ok=0;
	}
 	if(ok!=1)
	{
		employee_delete(nuevo);
		nuevo=NULL;
	}
  }
	return nuevo;
}

/**
 * /brief imprime los datos de un employee
 * /param Employee* es el employee
 * /param
 * /return (0)OK (-1)Error
 *
 */
int employee_imprimir_unElemento(Employee* this)
{
	int r=-1;
	if(this!=NULL)
	{
		r=0;
		printf("%5d\t%25s\t%16d\t%10d\n",this->id,this->nombre,this->horasTrabajadas,this->sueldo);
	}
	return r;
}

/**
 * /brief genera un id para un employee
 * /param
 * /param
 * /return (un indice)OK
 *
 */
int employee_generarId()
{
	static int id=1000;
	id++;
	return id;
}

/**
 * /brief compara 2 employee por nombre
 * /param Employee* es el employee
 * /param Employee* es el employee
 * /param
 * /return 1 si A es mayor a B o 0 si A es menor a B
 *
 */
int employee_compararNombres(void* employeeA,void* employeeB)
{
	int r=0;
	if(strcmp(((Employee*)employeeA)->nombre ,((Employee*)employeeB)->nombre)>0)
	{
		r=1;
	}
	else if(strcmp(((Employee*)employeeA)->nombre ,((Employee*)employeeB)->nombre)<0)
	{
		r=-1;
	}
	return r;
}

/**
 * /brief compara 2 employee por HorasTrabajadas
 * /param Employee* es el employee
 * /param Employee* es el employee
 * /param
 * /return 1 si A es mayor a B o 0 si A es menor a B
 *
 */
int employee_compararHorasTrabajadas(void* employeeA,void* employeeB)
{
	int r=0;
	if(((Employee*)employeeA)->horasTrabajadas> ((Employee*)employeeB)->horasTrabajadas)
	{
		r=1;
	}
	else if(((Employee*)employeeA)->horasTrabajadas < ((Employee*)employeeB)->horasTrabajadas)
	{
		r=-1;
	}
	return r;
}

/**
 * /brief compara 2 employee por Sueldo
 * /param Employee* es el employee
 * /param Employee* es el employee
 * /param
 * /return 1 si A es mayor a B o 0 si A es menor a B
 *
 */
int employee_compararSueldo(void* employeeA,void* employeeB)
{
	int r=0;
	if(((Employee*)employeeA)->sueldo> ((Employee*)employeeB)->sueldo)
	{
		r=1;
	}
	else if(((Employee*)employeeA)->sueldo < ((Employee*)employeeB)->sueldo)
	{
		r=-1;
	}
	return r;
}

/**
 * /brief compara 2 employee por ID
 * /param Employee* es el employee
 * /param Employee* es el employee
 * /param
 * /return 1 si A es mayor a B o 0 si A es menor a B
 *
 */
int employee_compararId(void* employeeA,void* employeeB)
{
	int r=0;
	if(((Employee*)employeeA)->id> ((Employee*)employeeB)->id)
	{
		r=1;
	}
	else if(((Employee*)employeeA)->id < ((Employee*)employeeB)->id)
	{
		r=-1;
	}
	return r;
}
