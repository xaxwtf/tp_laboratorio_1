/*
 * utn.h
 *
 *  Created on: 7 sep. 2020
 *      Author: roid
 */

#ifndef UTN_H_
#define UTN_H_
int utn_getInt(char* msj, char* errormsj,int*numObtenido, int intentos, int max, int min);
int utn_getFloat(char* msj, char* errormsj,float*floatObtenido, int intentos, int max, int min);
int utn_getChar(char* msj, char* errormsj,char* caracterObt, int intentos);
int utn_array_calcular_max(int* array,int len,int* resultado);
int utn_array_calcular_min(int* array,int len,int* resultado);
int utn_array_calcular_prom(int* array,int len,float* resultado);
int utn_myGets(char* cadena, int len);
int utn_pedir_cadena(char* mensaje, char* cadena, int len);
int utn_soloLetras(char* vec);
#endif /* UTN_H_ */
