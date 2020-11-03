#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStre);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_isValid_id(int id);
int employee_isValid_nombre(char* nombre);
int employee_isValid_horasTrabajadas(int horasTrabajadas);
int employee_isValid_sueldo(int sueldo);

int employee_imprimir_unElemento(Employee* this);
int employee_generarId();

int employee_compararNombres(void* employeeA,void* employeeB);
int employee_compararHorasTrabajadas(void* employeeA,void* employeeB);
int employee_compararSueldo(void* employeeA,void* employeeB);
int employee_compararId(void* employeeA,void* employeeB);



#endif // employee_H_INCLUDED
