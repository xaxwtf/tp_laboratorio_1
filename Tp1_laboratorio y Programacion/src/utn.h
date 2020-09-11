/*
 * utn.h
 *
 *  Created on: 7 sep. 2020
 *      Author: roid
 */

#ifndef UTN_H_
#define UTN_H_
int getInt(char* msj, char* errormsj,int*numObtenido, int intentos, int max, int min);
int getFloat(char* msj, char* errormsj,float*floatObtenido, int intentos, float max, float min);
int getChar(char* msj, char* errormsj,char* caracterObt, int intentos ,char max ,char min);
int array_calcular_max(int* array,int len,int* resultado, char max, char min);
int array_calcular_min(int* array,int len,int* resultado);
int array_calcular_prom(int* array,int len,float* resultado);
#endif /* UTN_H_ */
