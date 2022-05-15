/*
 * tipo.h
 *
 *  Created on: 14 may 2022
 *      Author: leo
 */

#ifndef TIPO_H_
#define TIPO_H_

typedef struct{

int id;
char descripcion;

}eTipo;

#endif /* TIPO_H_ */


int cargarDescripcionTipo(eTipo vec[], int tamt, int id, char descripcion[]);

int buscarTipo(eTipo vec[], int tamt, int id, int* pIndice);

int validarTipo(eTipo vec[], int tamt, int id);
