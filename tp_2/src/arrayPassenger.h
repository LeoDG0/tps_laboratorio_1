/*
 * arrayPassenger.h
 *
 *  Created on: 14 may 2022
 *      Author: leo
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

typedef struct{

int id;
char nombre[51];
char apellido[51];
float precio;
char codigoVuelo[10];
int tipoPasajero;
int estadoVuelo;
int isEmpty;

}ePasajeros;

#endif /* ARRAYPASSENGER_H_ */

int initPassenger(ePasajeros vec[], int tam);

int addPassengers(ePasajeros vec[], eTipo tipo[], eEstado estado[], int tam, int tamt, int tame, int* pId);

int removePassenger(ePasajeros lista[], int tam);

int printPasajeros(ePasajeros lista[], int tam);

void mostrarPasajeros(ePasajeros lista);

int hardcodearPasajeros(ePasajeros pasajerosF[], int tam, int cant, int* pId);

int findPassengerFree(ePasajeros vec[], int tam, int* pIndex);

int modificarPasajero(ePasajeros vec[], int tam);

int sortPassengerByType(ePasajeros vec[], int tam);

int sortPassenger(ePasajeros vec[], int tam, int criterio);

int informar(ePasajeros vec[], int tam, int criterio);

int totalPromedio(ePasajeros vec[], int tam);

int printPasajerosPromedio(ePasajeros vec[], int tam);

int Promedios(ePasajeros vec[], int tam);

//int sortByCodeStatus(ePasajeros vec[], eEstado vec[], tam, tame);
