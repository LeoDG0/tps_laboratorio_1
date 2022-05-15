/*
 * menu.c
 *
 *  Created on: 14 may 2022
 *      Author: leo
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"


int menu()
{
    int opcion;
    system("cls");
    printf("     *** ABM Pasajeros ***\n");
    printf("1- Alta\n");
    printf("2- Modificar\n");
    printf("3- Baja\n");
    printf("4- Informar\n");
    printf("9- Salir\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    return opcion;

}

int menuModificarPas()
{
    int opcion;

    system("cls");

    printf("   *** Modificar ***   \n");
    printf("1- Nombre\n");
    printf("2- Apellido\n");
    printf("3- Precio\n");
    printf("4- Codigo de vuelo\n");
    printf("5- Tipo de pasajero\n");
    printf("6- Estado de vuelo\n");
    printf("9-  Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);


    return opcion;


}


int menuInformar(){

int opcion;

    system("cls");

    printf("   *** Informar por: ***   \n");
    printf("1- Alfabeticamente por apellido y tipo\n");
    printf("2- Total y Promedio\n");
    printf("3- Codigo y Estado\n");
    printf("9-  Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);


    return opcion;

}











