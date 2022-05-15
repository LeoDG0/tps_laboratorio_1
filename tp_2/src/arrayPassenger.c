/*
 * arrayPassenger.c
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

int initPassenger(ePasajeros vec[], int tam)
{

    int todoOk = 0;

    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            vec[i].isEmpty = 1;
        }
        todoOk = 1;
    }

    return todoOk;
}


int hardcodearPasajeros(ePasajeros vec[], int tam, int cant, int* pId)
{

    int todoOk = 0;
    ePasajeros listaF[] =
    {
        {0, "juan", "perez", 100000, "b2jak2ia", 100, 300},
        {0, "alan", "cortez", 400000, "mashe", 103, 302},
        {0, "pedro", "disalvo", 300000, "ashee", 102, 301},
        {0, "mariano", "martinez", 200000, "b2ia", 101, 303},
        {0, "lucas", "rodriguez", 110000, "bsersk2ia", 103, 301}
    };

    if(listaF != NULL && tam > 0 && pId != NULL && cant > 0 && cant <= tam)
    {

        for(int i=0; i < cant; i++)
        {
            vec[i] = listaF[i];
            vec[i].id = *pId;
            *pId = *pId +1;

        }
        todoOk = 1;
    }

    return todoOk;
}


void mostrarPasajeros(ePasajeros vec)
{

    printf(" %4d\t%10s\t%10s\t%9.2f\t%10s\t\t%d\t\t%d\n",
           vec.id,
           vec.nombre,
           vec.apellido,
           vec.precio,
           vec.codigoVuelo,
           vec.tipoPasajero,
           vec.estadoVuelo
          );
}


int informar(ePasajeros vec[], int tam, int criterio)
{
    int todoOk = 0;
    char salir = 'n';

    do
    {
        switch(menuInformar())
        {

        case 1:

            sortPassenger(vec, tam, criterio);
            printPasajeros(vec, tam);
            system("pause");

            break;
        case 2:

            printPasajerosPromedio(vec, tam);
            system("pause");

            break;
        case 3:



            break;
        case 9:
            salir = 's';
            break;

        }
        todoOk = 1;
    }
    while(salir == 'n');

    return todoOk;
}


int printPasajeros(ePasajeros vec[], int tam)
{


    int todoOk = 0;
    int flag = 0;
    if(vec != NULL && tam > 0)
    {
        printf("                          ***Listado de pasajeros***\n\n");
        printf("  id\t   Nombre\t   Apellido\t   Precio\t   Codigo\t    Tipo\t  Estado\n\n");
        printf(" -----------------------------------------------------------------------------------------------------\n\n");
        for(int i = 0; i < tam; i++)
        {
            if(!vec[i].isEmpty)
            {
                mostrarPasajeros(vec[i]);
                flag++;
            }
        }
        if(flag == 0)
        {
            printf("\t\t\tNo hay pasajeros en el sistema\n");
        }
        printf("\n\n");
        todoOk = 1;
    }


    return todoOk;
}



int findPassengerFree(ePasajeros vec[], int tam, int* pIndex)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0 && pIndex != NULL)
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if( vec[i].isEmpty )
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}



int addPassengers(ePasajeros vec[], eTipo tipo[], eEstado estado[],  int tam, int tamt, int tame, int* pId)
{
    int todoOk = 0;
    int indice;
    char auxCad[100];
    char auxCadC[10];
    ePasajeros nuevoPasajero;


    if(vec != NULL && tam > 0 && pId != NULL)
    {
        if( findPassengerFree(vec, tam, &indice) )
        {

            if(indice == - 1)
            {
                printf("No hay lugar en el sistema\n");
            }
            else
            {

                printf("Ingrese el nombre: ");
                fflush(stdin);
                gets(auxCad);

                while(strlen(auxCad) >= 20)
                {
                    printf("Nombre demasiado largo. Reingrese nombre: ");
                    fflush(stdin);
                    gets(auxCad);
                }
                strcpy(nuevoPasajero.nombre, auxCad);

                printf("Ingrese el apellido: ");
                fflush(stdin);
                gets(auxCad);

                while(strlen(auxCad) >= 20)
                {
                    printf("Apellido demasiado largo. Reingrese apellido: ");
                    fflush(stdin);
                    gets(auxCad);
                }
                strcpy(nuevoPasajero.apellido, auxCad);

                printf("Ingrese precio: ");
                scanf("%f", &nuevoPasajero.precio);

                printf("Ingrese el codigo de vuelo: ");
                fflush(stdin);
                gets(auxCadC);

                while(strlen(auxCadC) >= 10)
                {
                    printf("Codigo demasiado largo. Reingrese: ");
                    fflush(stdin);
                    gets(auxCadC);
                }
                strcpy(nuevoPasajero.codigoVuelo, auxCadC);

                printf("Ingrese tipo de pasajero(100 a 103): ");
                scanf("%d", &nuevoPasajero.tipoPasajero);

                while( !validarTipo(tipo, tamt, nuevoPasajero.tipoPasajero))
                {
                    printf("Tipo invalido.Ingrese Id Tipo: ");
                    scanf("%d", &nuevoPasajero.tipoPasajero);
                }

                printf("Ingrese Estado(300 a 303): ");
                scanf("%d", &nuevoPasajero.estadoVuelo);

                while( !validarEstado(estado, tame, nuevoPasajero.estadoVuelo))
                {
                    printf("Estadp invalido.Ingrese Estado(300 a 303): ");
                    scanf("%d", &nuevoPasajero.estadoVuelo);
                }


                nuevoPasajero.isEmpty = 0;
                nuevoPasajero.id = *pId;
                *pId = *pId + 1;
                vec[indice] = nuevoPasajero;
                todoOk = 1;
            }
        }
        else
        {
            printf("Ocurrio un problema\n");
        }
    }
    return todoOk;
}

int buscarPasajero(ePasajeros vec[], int tam, int id, int* pIndex)
{

    int todoOk = 0;

    if(vec != NULL && tam > 0 && pIndex != NULL && id > 0)
    {
        *pIndex = -1;
        for(int i = 0; i < tam; i++)
        {
            if(vec[i].isEmpty == 0 && vec[i].id == id)
            {
                *pIndex = i ;
                break;
            }

        }
        todoOk = 1;
    }

    return todoOk;
}



int removePassenger(ePasajeros vec[], int tam)
{

    int todoOk = 0;
    int indice;
    int id;
    char confirma;


    if(vec != NULL && tam > 0)
    {
        printPasajeros(vec, tam);

        printf("ingrese Id: ");
        scanf("%d", &id);
        if(buscarPasajero(vec, tam, id, &indice))
        {
            if(indice == -1)
            {
                printf("no hay un pasajero con id %d\n", id);
            }
            else
            {
                mostrarPasajeros(vec[indice]);
                fflush(stdin);
                printf("confirma baja?: ");
                scanf("%c", &confirma);
                if(confirma != 'S' && confirma != 's')
                {
                    printf("Baja cancelada\n");
                }
                else
                {
                    vec[indice].isEmpty = 1;
                    printf("Baja confirmada!");
                    todoOk = 1;
                }

            }
        }
        else
        {
            printf("ocurrio un error");
        }


    }



    return todoOk;

}

int modificarPasajero(ePasajeros vec[], int tam)
{

    int todoOk = 0;
    int indice;
    int id;
    char auxCad[100];
    char auxCadC[10];
    char salir = 'n';

    if(vec != NULL && tam > 0)
    {
        printPasajeros(vec, tam);

        printf("ingrese id: ");
        scanf("%d", &id);
        if(buscarPasajero(vec, tam, id, &indice))
        {
            if(indice == -1)
            {
                printf("no hay un pasajero con Id: %d\n", id);
            }
            else
            {
                mostrarPasajeros(vec[indice]);

                do
                {
                    switch(menuModificarPas())
                    {

                    case 1:
                        printf("Ingrese nuevo nombre: ");
                        fflush(stdin);
                        gets(auxCad);

                        strcpy(vec[indice].nombre, auxCad);
                        printf("Nombre modificado!\n");

                        break;
                    case 2:
                        printf("Ingrese nuevo apellido: ");
                        fflush(stdin);
                        gets(auxCad);

                        strcpy(vec[indice].apellido, auxCad);
                        printf("Apellido modificado!\n");

                        break;
                    case 3:
                        printf("Ingrese nuevo precio: ");
                        scanf("%f", &vec[indice].precio);

                        printf("Precio modificado!\n");

                        break;
                    case 4:
                        printf("Ingrese nuevo codigo: ");
                        fflush(stdin);
                        gets(auxCadC);

                        while(strlen(auxCadC) >= 10)
                        {
                            printf("Codigo demasiado largo. Reingrese: ");
                            fflush(stdin);
                            gets(auxCadC);
                        }
                        strcpy(vec[indice].codigoVuelo, auxCadC);

                        printf("Codigo modificado!\n");
                        break;
                    case 5:
                        printf("Ingrese nuevo tipo: ");
                        scanf("%d", &vec[indice].tipoPasajero);

                        printf("Tipo modificado!\n");
                        break;
                    case 6:
                        printf("Ingrese nuevo estado: ");
                        scanf("%d", &vec[indice].estadoVuelo);

                        printf("Estado modificado!\n");
                        break;
                    case 9:
                        salir = 's';
                        break;
                    }
                    system("pause");

                }
                while(salir != 's');
            }
        }
        else
        {
            printf("ocurrio un error");
        }

        todoOk = 1;
    }



    return todoOk;

}

//int sortPassengerByName(ePasajeros vec[], int tam)
//{
//    int todoOk = 0;
//    ePasajeros auxPasajero;
//    if(vec != NULL && tam > 0)
//    {
//        for(int i=0; i < tam -1; i++)
//        {
//            for(int j= i + 1; j < tam; j++)
//            {
//                if(strcmp(vec[i].apellido, vec[j].apellido) > 0)
//                {
//                    auxPasajero = vec[i];
//                    vec[i] = vec[j];
//                    vec[j] = auxPasajero;
//                }
//            }
//        }
//        todoOk = 1;
//    }
//    return todoOk;
//}

int sortPassengerByType(ePasajeros vec[], int tam)
{

    int todoOk = 0;
    ePasajeros auxPasajero;
    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam -1; i++)
        {
            for(int j= i + 1; j < tam; j++)
            {
                if(vec[i].tipoPasajero && vec[j].tipoPasajero > 0)
                {
                    auxPasajero = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxPasajero;
                }
            }
        }
        todoOk = 1;
    }
    return todoOk;

}


int sortPassenger(ePasajeros vec[], int tam, int criterio)
{

    int todoOk = 0;
    ePasajeros vecAux;

    if(vec != NULL && tam > 0 && (criterio == 1 || criterio == 0))
    {
        for(int i = 0; i < tam; i++)
        {
            for(int j = i + 1; j < tam; j++)
            {
                if(vec[i].isEmpty == 0 && vec[j].isEmpty == 0)
                {
                    if(((vec[i].tipoPasajero == vec[j].tipoPasajero) && strcmp(vec[i].apellido, vec[j].apellido) > 0 && criterio == 1)
                            || (vec[i].tipoPasajero != vec[j].tipoPasajero && vec[i].tipoPasajero > vec[j].tipoPasajero && criterio == 1)
                            || ((vec[i].tipoPasajero == vec[j].tipoPasajero) && strcmp(vec[i].apellido, vec[j].apellido) < 0 && criterio == 0)
                            || (vec[i].tipoPasajero != vec[j].tipoPasajero && vec[i].tipoPasajero < vec[j].tipoPasajero && criterio == 0))
                    {

                        vecAux = vec[i];
                        vec[i] = vec[j];
                        vec[j] = vecAux;

                    }
                }
            }
        }
        todoOk = 1;
    }

    return todoOk;
}

int printPasajerosPromedio(ePasajeros vec[], int tam)
{
    int todoOk = 0;
    int flag = 0;
    if(vec != NULL && tam > 0)
    {
        printf("                          ***Listado de pasajeros***\n\n");
        printf("  id\t   Nombre\t   Apellido\t   Precio\t   Codigo\t    Tipo\t  Estado\n\n");
        printf(" -----------------------------------------------------------------------------------------------------\n\n");
        for(int i = 0; i < tam; i++)
        {
            if(!vec[i].isEmpty)
            {
                Promedios(vec, tam);
                printf("\n\n");
                mostrarPasajeros(vec[i]);
                flag++;
            }
        }
        if(flag == 0)
        {
            printf("\t\t\tNo hay pasajeros en el sistema\n");
        }
        printf("\n\n");
        todoOk = 1;
    }


    return todoOk;
}

int Promedios(ePasajeros vec[], int tam)
{

    int todoOk = 0;
    float acumPrecios = 0;
    int contPasajeros = 0;
    float promedio = 0;

    if(vec != NULL && tam > 0 )
    {
        for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty )
            {
                acumPrecios += vec[i].precio;
                contPasajeros++;
            }
        }
        if(contPasajeros > 0)
        {
            promedio = acumPrecios / contPasajeros;
        }

        system("cls");
        printf("    ***Informe Promedio***\n\n");
        printf("Promedio: $ %.2f\n", promedio);

        todoOk = 1;
    }
    return todoOk;

}

//int sortByCodeStatus(ePasajeros vec[], eEstado vec[], tam, tame){


//}
