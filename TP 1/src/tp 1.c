/*
 ============================================================================
 Name        : tp.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{
	setbuf(stdout, NULL);
    char salir = 'n';
    int kilometros;
    float latam;
    float aerolineas;
    float credito;
    float debito;
    float precioUnitario;
    float BTC;
    float diferencia;
    float creditoL;
    float debitoL;
    float precioUnitarioL;
    float BTCL;
    int flagKilometros = 1;
    int flagVuelos = 1;


    do
    {
        switch(menu())
        {
        case 1:

            printf("ingrese kilometros: ");
            scanf("%d", &kilometros);
            if(kilometros <= 0){
            	printf("Ingrese un valor valido!!\n\n");
            	printf("Ingrese kilometros nuevamente: ");
            	scanf("%d", &kilometros);
            }
            flagKilometros = 0;
            break;

        case 2:
            if (flagKilometros == 0){
            printf("ingrese el precio de latam: ");
            scanf("%f", &latam);
            while (latam <= 0){
            	printf("Ingrese un valor valido!!");
            	printf("Ingrese el precio de latam nuevamente: ");
            	scanf("%f", &latam);
            }
            printf("ingrese el precio de aerolineas: ");
            scanf("%f", &aerolineas);
            while (aerolineas <= 0){
            	printf("Ingrese un valor valido!!");
            	printf("Ingrese el precio de aerolineas nuevamente: ");
            	scanf("%f", &aerolineas);
            }
            flagVuelos = 0;
            }
            else
            {
                printf("Para calcular el precio de los vuelos se necesitan los kilometros!!\n\n");
            }

            break;

        case 3:
            if(flagVuelos == 0){
             calcularDatosAerolineas(aerolineas, kilometros, &credito, &debito, &precioUnitario, &BTC);
             calcularDatosLatam(latam, kilometros, &creditoL, &debitoL, &precioUnitarioL, &BTCL);
             diferencia = latam - aerolineas;
             flagKilometros = 1;
             flagVuelos = 1;
             }
             else if(flagKilometros == 1){
                printf("Que vas a calcular, si no ingresasaste los kilometros?\n\n");
             }
             else{
                printf("Ingresaste los kilometros, pero no los precios de vuelo!\n\n");
             }
            break;

        case 4:
                printf("*** AEROLINEAS ***\n\n");
                printf("Opcion credito: %.2f\n", credito);
                printf("Opcion debito: %.2f\n", debito);
                printf("Opcion BTC: %.2f\n", BTC);
                printf("Precio unitario: %.2f\n", precioUnitario);
                printf("La diferencia es: %.2f\n\n", diferencia);
                printf("*** LATAM ***\n\n");
                printf("Opcion credito: %.2f\n", creditoL);
                printf("Opcion debito: %.2f\n", debitoL);
                printf("Opcion BTC: %.2f\n", BTCL);
                printf("Precio unitario: %.2f\n", precioUnitarioL);
                printf("La diferencia es: %.2f\n", diferencia);

            break;
        case 5: forzarCarga();
            break;
        case 6: confirmarSalida(&salir);
            break;
        default:
            printf("Opcion Invalida!\n\n");
        }
        system("pause");

    }
    while(salir != 's');

    return EXIT_SUCCESS;
}
