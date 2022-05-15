/*
 * estado.h
 *
 *  Created on: 14 may 2022
 *      Author: leo
 */

#ifndef ESTADO_H_
#define ESTADO_H_

typedef struct{

int id;
char descripcion;

}eEstado;

#endif /* ESTADO_H_ */

int cargarDescripcionEstado(eEstado vec[], int tame, int id, char descripcion[]);

int buscarEstado(eEstado vec[], int tame, int id, int* pIndice);

int validarEstado(eEstado vec[], int tame, int id);
