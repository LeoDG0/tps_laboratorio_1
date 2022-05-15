/*
 * estado.c
 *
 *  Created on: 14 may 2022
 *      Author: leo
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arrayPassenger.h"
#include "menu.h"
#include "tipo.h"
#include "estado.h"




int cargarDescripcionEstado(eEstado vec[], int tame, int id, char descripcion[]){

int todoOk = 0;
int indice;

    buscarEstado(vec, tame, id, &indice);

    if(descripcion != NULL && indice != -1 ){
       strcpy(descripcion, vec[indice].descripcion);
       todoOk = 1;
    }
  return todoOk;

}

int buscarEstado(eEstado vec[], int tame, int id, int* pIndice){

    int todoOk = 0;
    if(vec != NULL && tame > 0 && pIndice != NULL){
            *pIndice = -1;
            for(int i=0; i < tame; i++){
                if(vec[i].id == id){
                    *pIndice = i;
                    break;
                }
            }
        todoOk = 1;
    }
    return todoOk;

}

int validarEstado(eEstado vec[], int tame, int id){

    int esValido = 0;
    int indice;

    buscarEstado(vec, tame, id, &indice);

    if(indice != -1){
        esValido = 1;
    }
    return esValido;


}








