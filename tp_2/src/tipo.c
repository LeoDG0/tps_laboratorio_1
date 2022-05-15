/*
 * tipo.c
 *
 *  Created on: 14 may 2022
 *      Author: leo
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arrayPassenger.h"
#include "tipo.h"








int cargarDescripcionTipo(eTipo vec[], int tamt, int id, char descripcion[]){
int todoOk = 0;
int indice;

    buscarTipo(vec, tamt, id, &indice);

    if(descripcion != NULL && indice != -1 ){
       strcpy(descripcion, vec[indice].descripcion);
       todoOk = 1;
    }
  return todoOk;
}

int buscarTipo(eTipo vec[], int tamt, int id, int* pIndice){
    int todoOk = 0;
    if(vec != NULL && tamt > 0 && pIndice != NULL){
            *pIndice = -1;
            for(int i=0; i < tamt; i++){
                if(vec[i].id == id){
                    *pIndice = i;
                    break;
                }
            }
        todoOk = 1;
    }
    return todoOk;
}

int validarTipo(eTipo vec[], int tamt, int id){
    int esValido = 0;
    int indice;

    buscarTipo(vec, tamt, id, &indice);

    if(indice != -1){
        esValido = 1;
    }
    return esValido;
}

