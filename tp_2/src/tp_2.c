/*
 ============================================================================
 Name        : tp_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "arrayPassenger.h"
#include "menu.h"
#include "tipo.h"

#define TAM 5
#define TAMT 4
#define TAME 4

#define CRITERIOASC 1
#define CRITERIODESC 0


int main()
{

	setbuf(stdout, NULL);
    //int indice;
    char salir = 'n';
    int proximoId = 10000;
    int flagAlta = 0;
    int flagModificar = 0;
    ePasajeros lista[TAM];


    initPassenger(lista, TAM);

    eTipo pTipo[TAMT] ={
        {100, "Primera"},
        {101, "Ejecutiva"},
        {102, "Premium economy"},
        {103, "Turista"}
    };

    eEstado pEstado[TAME] =
    {
        {300, "Activo"},
        {301, "Demorado"},
        {302, "Reprogramado"},
        {303, "cancelado"}
    };

    initPassenger(lista, TAM);

    hardcodearPasajeros(lista, TAM, 3, &proximoId);


    do{

        switch(menu()){

        case 1:
                addPassengers(lista, pTipo, pEstado, TAM, TAMT, TAME, &proximoId);
                flagAlta = 1;
            break;
        case 2:
                if(flagAlta == 0){
                    printf("\nprimero debe ingresar un pasajero!\n\n");
                }
                else{
                    modificarPasajero(lista, TAM);
                    flagModificar = 1;
                }

            break;
        case 3:
                if(flagAlta == 0 && flagModificar == 0){
                    printf("\nprimero debe ingresar un pasajero!\n\n");
                }
                else{
                    removePassenger(lista, TAM);
                }
            break;
        case 4:
                informar(lista, TAM, CRITERIOASC);
            break;
        case 9:

            salir = 's';

            break;

        }
        system("pause");

    }while(salir == 'n');

    return 0;
}
