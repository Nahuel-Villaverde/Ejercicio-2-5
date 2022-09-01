/*
 ============================================================================
 Name        : Ejercicio.c
 Author      : Nahuel Villaverde Guzman
 Version     : (Entradas, procesos y salidas) Ejercicio 2-5
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	setbuf(stdout, NULL);

	int continuar = 1;
	int contadorLibretas = 0;
	int numeroLegajo;

	char estadoCivil;
	int edad;
	int yearIngreso;
	char genero;

	int contadorMayores = 0;

	int banderaMasTiempo = 0;
	int masTiempo;
	int legajoMasTiempo;
	int edadMasTiempo;

	int totalLibretasSinDescuento;

	int porcentaje;
	int descuento;
	int precioFinal;
	int precioFinalConDescuentoExtra;
	int porcentajeDescuentoExtra;

	int descuentoExtra;


    while(continuar == 1)
    {
    	printf("Ingrese el numero del legajo (Del 1000 al 9999");
    	scanf("%d",&numeroLegajo);
    	while(numeroLegajo <= 1000 && numeroLegajo < 9999)
    	{
    		printf("Reingrese el numero del legajo");
    		scanf("%d",&numeroLegajo);
    	}

    	fflush(stdin);
    	printf("Ingrese el estado civil");
    	scanf("%c",&estadoCivil);
    	while(estadoCivil != 's' && estadoCivil != 'c' && estadoCivil != 'v')
    	{
    		fflush(stdin);
        	printf("Reingrese el estado civil");
        	scanf("%c",&estadoCivil);
    	}

    	printf("Ingrese la edad");
    	scanf("%d",&edad);
    	while(edad < 17)
    	{
    	    printf("Reingrese la edad");
    	    scanf("%d",&edad);
    	}

    	printf("Ingrese el año de ingreso (Del 2000 hasta el 2022)");
    	scanf("%d",&yearIngreso);
    	while(yearIngreso < 2000 || yearIngreso > 2022)
    	{
    	    printf("Reingrese el año de ingreso (Del 2000 hasta el 2022)");
    	    scanf("%d",&yearIngreso);
    	}

    	fflush(stdin);
    	printf("Ingrese el genero");
    	scanf("%c",&genero);
    	while(genero != 'f' && genero != 'm' && genero != 'o')
    	{
    		fflush(stdin);
        	printf("Reingrese el genero");
        	scanf("%c",&genero);
    	}

    	if(edad > 60)
    	{
    		contadorMayores++;
    	}

    	if(genero == 'f')
    	{
    		if(banderaMasTiempo == 0 || masTiempo < yearIngreso)
    		{
    			masTiempo = yearIngreso;
    			legajoMasTiempo = numeroLegajo;
    			edadMasTiempo = edad;
    			banderaMasTiempo = 1;
    		}
    	}

    	contadorLibretas++;
    	printf("Quieres seguir ingresando numeros?(1 para aceptar/ otro numero para rechazar");
    	scanf("%d",&continuar);
    }

    totalLibretasSinDescuento = contadorLibretas * 450;

    if(contadorLibretas < 5)
    {
    	porcentaje = 0;
    }
    else if(contadorLibretas >= 5 || contadorLibretas <= 9)
    {
    	porcentaje = 5;
    }
    else if(contadorLibretas >= 10)
    {
    	porcentaje = 10;
    }

    if(edad > 60)
    {
    	porcentajeDescuentoExtra = 25;
    }
    else
    {
    	porcentajeDescuentoExtra = 0;
    }

    descuento = (porcentaje/100 * totalLibretasSinDescuento);
    precioFinal = totalLibretasSinDescuento - descuento;

    descuentoExtra = (porcentajeDescuentoExtra/100 * precioFinal);
    precioFinalConDescuentoExtra = precioFinal - descuentoExtra;

    printf("La cantidad de personas mayores de 60 años es: %d" , contadorMayores);
    printf("El legajo de la mujer que ingreso hace más tiempo es: %d y la edad es: %d" , legajoMasTiempo , edadMasTiempo);
    printf("Total a abonar sin descuento: %d" , totalLibretasSinDescuento);
    printf("El precio con descuento es de: %d" , precioFinalConDescuentoExtra);
    return 0;
}
