
//Juego de 2D
//Una linea -> el suelo
//Moverse de izquierda a derecha
// 20fps
//Limites en los laterales
//_Kbhit()  --> funcion para saber si el usuario dio una tecla (0 si no pulso nada). Esta en conio.h
//_getch()  --> saber k pulso
//Sleep(int a) --> 'a' son milisegundos. Esta en windows.h
// '\r'  --> volver a la linea anterior

/*
Ej:
	--------X-----
	-------X------
*/

#include "stdafx.h"

//FUNCIONES
void mover();
void pintar();

//CONSTANTES
#define ANCHO_MUNDO		80
#define FPS				20
#define DORMIR			1000/FPS
#define IZQ				'a'
#define DER				'd'
#define DISP_IZQ		'q'
#define DISP_DER		'e'
#define PJ_DIBUJO		"P"
#define SUELO_DIBUJO	"_"
#define BALA_DIBUJO		"*"

//VARIABLES GLOBALES
int g_pj		= ANCHO_MUNDO/2;
int g_bala_pos	= -1;
int g_bala_dir	= -1;

//FUNCION PRINCIPAL
int main()
{

	//Posicionar el suelo
	printf("\n\n\n\n");

	while (true)
	{
		mover();
		pintar();
		Sleep(DORMIR);
	}//fin while

	return 0;

}//fin main

//CONSTRUCCION DE FUNCIONES
//Funcion que lee lo que pulso el usuario y mueve el elemento
void mover()
{

	if (_kbhit() != 0)
	{
		int boton = _getch();
		if (boton == IZQ)
		{
			if (g_pj > 0)
				g_pj--;
		}
		else if (boton == DER)
		{
			if (g_pj < ANCHO_MUNDO)
				g_pj++;
		}
		else if (boton == DISP_IZQ)
		{
			if (g_bala_pos == -1)
			{
				g_bala_pos = g_pj - 1;
				g_bala_dir = -1;
			}
				
		}
		else if (boton == DISP_DER)
		{
			if (g_bala_pos == -1)
			{
				g_bala_pos = g_pj + 1;
				g_bala_dir = 1;
			}
				
		}

	}
	if (g_bala_pos != -1)
	{
		g_bala_pos += g_bala_dir;
		if (g_bala_pos > ANCHO_MUNDO || g_bala_pos < 0)
			g_bala_pos = -1;
	}


};//fin mover

//Dibuja el mundo
void pintar()
{

	//Volver a la linea del suelo
	printf("\r");

	int i = 0;
	while (i <= ANCHO_MUNDO)
	{
		if		(i == g_pj)			printf(PJ_DIBUJO);
		else if (i == g_bala_pos)	printf(BALA_DIBUJO);
		else						printf(SUELO_DIBUJO);

		i++;
	}//fin while

}//fin pintar

