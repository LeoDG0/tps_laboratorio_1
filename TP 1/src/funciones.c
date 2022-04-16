/*
 * funciones.c
 *
 *  Created on: 16 abr 2022
 *      Author: leo
 */
#include <stdio.h>
#include <stdlib.h>

int menu()
{
    int opcion;

    printf("  *** Menu de Opciones ***\n\n");
    printf("1- ingresar kilometros\n");
    printf("2- precio de vuelos\n");
    printf("3- calcular datos\n");
    printf("4- mostrar resultados\n");
    printf("5- carga forzada\n");
    printf("6- Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);


    return opcion;
}


void confirmarSalida(char* p)
{
    char confirma;
    printf("Confirma salida?: ");
    fflush(stdin);
    scanf("%c", &confirma);

    *p = confirma;

}


void calcularDatosAerolineas(float aerolineas, int kilometros, float *credito, float *debito, float *precioUnitario, float *BTC){

	*debito = aerolineas * 0.90;

	*credito = (aerolineas * 0.25) + aerolineas;

	*BTC = aerolineas / 4621700.45;

	*precioUnitario = aerolineas / kilometros;


}


void calcularDatosLatam(float latam, int kilometros, float *creditoL, float *debitoL, float *precioUnitarioL, float *BTCL){

    *creditoL = (latam * 0.25) + latam;

    *debitoL = latam * 0.90;

	*BTCL = latam / 4621700.45;

	*precioUnitarioL = latam / kilometros;


}


void forzarCarga(){


    int kilometrosDos = 7090;
    float bitcoin = 4594747.30;
    int latam = 159339;
    int aerolineas = 162965;
    float debitoLatam = 0;
    float creditoLatam = 0;
    float debitoAero = 0;
    float creditoAero = 0;
    float BTCA = 0;
    float BTCL = 0;
    float precioUnitarioLatam = 0;
    float precioUnitarioAero = 0;
    float diferencia = 0;


    creditoAero = (aerolineas * 0.25) + aerolineas;

    debitoAero = aerolineas * 0.90;

    precioUnitarioAero = aerolineas / kilometrosDos;

    BTCA = aerolineas / bitcoin;

    diferencia = aerolineas - latam;


    creditoLatam = (latam * 0.25) + latam;

    debitoLatam = latam * 0.90;

    precioUnitarioLatam = latam / kilometrosDos;

    BTCL = latam / bitcoin;

    printf("*** AEROLINEAS ***\n\n");
    printf("Opcion credito: %.2f\n", creditoAero);
    printf("Opcion debito: %.2f\n", debitoAero);
    printf("Opcion BTC: %f\n", BTCA);
    printf("Precio unitario: %.2f\n", precioUnitarioAero);
    printf("La diferencia es: %.2f\n\n", diferencia);
    printf("*** LATAM ***\n\n");
    printf("Opcion credito: %.2f\n", creditoLatam);
    printf("Opcion debito: %.2f\n", debitoLatam);
    printf("Opcion BTC: %.7f\n", BTCL);
    printf("Precio unitario: %.2f\n", precioUnitarioLatam);
    printf("La diferencia es: %.2f\n", diferencia);
}










