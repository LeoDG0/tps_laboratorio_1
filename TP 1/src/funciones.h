/*
 * funciones.h
 *
 *  Created on: 16 abr 2022
 *      Author: leo
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_


/** \brief muestra el menu y solicita opcion
 *
 * \return int retorna la opcion seleccionada
 *
 */
int menu();

void confirmarSalida(char* p);


/** \brief
 *
 * \param float precio de vuelo de aerolineas
 * \param int kilometros ingresados
 * \param float direccion donde se modifica la variable de main
 * \param float direccion donde se modifica la variable de main
 * \param float direccion donde se modifica la variable de main
 * \param float direccion donde se modifica la variable de main
 * \return void
 *
 */
void calcularDatosAerolineas(float, int, float*, float*, float*, float*);

/** \brief
 *
 * \param float precio de vuelo de latam
 * \param int kilometros
 * \param float direccion donde se modifica la variable de main
 * \param float direccion donde se modifica la variable de main
 * \param float direccion donde se modifica la variable de main
 * \param float direccion donde se modifica la variable de main
 * \return void
 *
 */
void calcularDatosLatam(float, int, float*, float*, float*, float*);


void forzarCarga();




#endif /* FUNCIONES_H_ */
