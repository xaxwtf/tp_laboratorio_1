/*
 * arrayEmployees.h
 *
 *  Created on: 30 sep. 2020
 *      Author: roid
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#define tam_string 51
typedef struct{
	char name[tam_string];
	int isEmpty;
	char lastName[tam_string];
	float salary;
	int sector;
	int id;
}sEmployee;

int employee_listar(sEmployee* lista, int len);
int employee_init(sEmployee* lista, int len);
int employee_buscarLibre(sEmployee* lista, int len, int* indiceLibre);
int employee_alta(sEmployee* lista, int len);
int employee_modificar(sEmployee* lista,int len);
int employee_baja(sEmployee* lista, int len);
int employee_imprimirxIndice(sEmployee* lista ,int len, int indice);
int employee_buscarLibre2(sEmployee* lista, int len);
int employee_generarId(void);
int employee_buscarOcurrenciaId(sEmployee* lista, int len, int id, int* indice);
int employee_ordenarxNombre(sEmployee* lista, int len, int order);
int addEmployee(sEmployee* list, int len, int id, char* name,char* lastName,float salary,int sector);
int findEmployeeById(sEmployee* list, int len,int id);
int removeEmployee(sEmployee* list, int len, int id);
int sortEmployees(sEmployee* list, int len, int order);
int employee_buscarOcurrencia_empty(sEmployee * lista, int len, int referencia);
int informar(sEmployee* lista, int len);
float promedioSalarios(sEmployee *lista,int tam);
int employee_contarSalariosArribaDe(sEmployee* lista, int len, float referencia);

#endif /* ARRAYEMPLOYEES_H_ */
