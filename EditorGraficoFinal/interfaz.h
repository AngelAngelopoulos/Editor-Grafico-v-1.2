#ifndef INTERFAZ_H_INCLUDED
#define INTERFAZ_H_INCLUDED

#include <stdio.h>
#include <graphics.h>
#include <math.h>
//#include "LIB01.h"

#define TAMBOTON 50
#define NBOTONES 8

#define NCOLORES 16
#define TAMC 30

typedef struct{
    int iCx; //Variable para capturar la posición inicial en coordenada en X
    int iCy; //Variable para capturar la posición inicial en coordenada en Y
    int iCFx; //Variable para capturar la posición final en coordenada en X
    int iCFy; //Variable para capturar la posición final en coordenada en Y
    int iColorF; //Variable para capturar el color de fondo de los objetos
    int iColorL; //Variable para capturar el color del contorno de los objetos
    int iCualBoton;
}BOTONES, COLORES;


/*void interior(int x1, int y1, int x2, int y2, int color);
void exterior(int x1, int y1, int x2, int y2, int color);*/
void generarBoton(int y1, int y2, int num);
void interfazG(BOTONES bBot[10]);
void crearBotones(BOTONES bBot[10]);
void seleccionBoton(BOTONES bBot[10],int iXx,int iYy);
//void crearColores(COLORES cCol[16]);
int menu();
void generaMalla();
void colores();



#endif // INTERFAZ_H_INCLUDED

int menu()
{

    char cCualTecla;
    int iXraton,iYraton;

    BOTONES bBot[10];
    COLORES cCol[16];
    int band = 0;

	//initwindow(800, 600);
	//crearBotones(bBot);
    interfazG(bBot);
	//generarBoton(buty1, buty2, 8);
	crearBotones(bBot);
    //crearColores(cCol);
    generaMalla();
    colores();
   do{
        fflush(stdin);
        if(kbhit()){
            cCualTecla=getch();
            //opcion(cCualTecla);
            switch(cCualTecla){
                 case 32: band = 1;
                          break;
            }
        }
        if(ismouseclick(WM_LBUTTONDOWN)){
            getmouseclick(WM_LBUTTONDOWN,iXraton,iYraton);
            seleccionBoton(bBot,iXraton,iYraton);
       }

       // }
    }while(cCualTecla!=32 || band != 1);
   //int buty1 = 30;
    //int buty2 = 70;
    //seleccionBoton(bBot, iXx, iYy);
    return (band);
}


/*void generarBoton(int y1, int y2, int num)
{
    int x1 = 100, x2 = 150;

    for (int i = 0; i < num; i++)
    {
        rectangle(x1, y1, x2, y2);
        exterior(x1+5, y1+5, x2+5, y2+5, 8);
        interior(x1, y1, x2, y2, 15);
        x1 += 75;
        x2 += 75;
    }
}
*/

void crearBotones(BOTONES bBot[10])
{
    int iCont,iXx,iYy, i;
    iXx=90;
    iYy=30;
    for(iCont=0;iCont<NBOTONES;iCont++){
         bBot[iCont].iCx=iXx;
         bBot[iCont].iCy=iYy;
         bBot[iCont].iCFx=iXx+TAMBOTON+10;
         bBot[iCont].iCFy=iYy+TAMBOTON;
         bBot[iCont].iColorF=7;
         bBot[iCont].iColorL=15;
         bBot[iCont].iCualBoton=iCont;
         iXx+=TAMBOTON+25;
    }
    for(int iCont=0;iCont<NBOTONES;iCont++){
        exterior(bBot[iCont].iCx,bBot[iCont].iCy,bBot[iCont].iCFx,bBot[iCont].iCFy,bBot[iCont].iColorF);
    }
    setbkcolor(7);
    outtextxy(bBot[NBOTONES-8].iCx+5, bBot[NBOTONES-8].iCy+15, "Botón 1");
    outtextxy(bBot[NBOTONES-7].iCx+5, bBot[NBOTONES-7].iCy+15, "Botón 2");
    outtextxy(bBot[NBOTONES-6].iCx+5, bBot[NBOTONES-6].iCy+15, "Botón 3");
    outtextxy(bBot[NBOTONES-5].iCx+5, bBot[NBOTONES-5].iCy+15, "Botón 4");
    outtextxy(bBot[NBOTONES-4].iCx+5, bBot[NBOTONES-4].iCy+15, "Botón 5");
    outtextxy(bBot[NBOTONES-3].iCx+5, bBot[NBOTONES-3].iCy+15, "Botón 6");
    outtextxy(bBot[NBOTONES-2].iCx+5, bBot[NBOTONES-2].iCy+15, "Botón 7");
    outtextxy(bBot[NBOTONES-1].iCx+12, bBot[NBOTONES-1].iCy+15, "Jugar");
}


void interfazG(BOTONES bBot[10])
{
    exterior(0, 0, 800, 800, 8); //marco principal
	interior(10, 10, 790, 590, 15);  //marco principal

    rectangle(10,10, 790, 15); //Marco secundario

    /*exterior(95, 145, 690, 540, 8); //marco de trabajo
	interior(105, 155, 700, 550, 15);  //marco de trabajo*/

	rectangle(150, 100, 650, 500); //Marco de trabajo
    //floodfill(160, 110, 0);
    interior(150, 100, 650, 500, 0);


	//rectangle(10, 10, 790, 100); //Barra de opciones arriba
	interior(20, 20, 780, 90, 0);
	exterior(10, 10, 790, 100, 7);
	//crearBotones(bBot);
	//setfillstyle(1,0);
	rectangle(0, 100, 150, 500); //Barra de herramientas
	rectangle(0, 500, 800, 600); //Barra de informacion
    bar(30, 530, 770, 570);
    setfillstyle(1, 8);

}

/*void dibujaBotones(BOTONES bBot[10]){
    exterior(0,0,getmaxx(),getmaxy(),7);
    interior(20,20,650,500,0);
    interior(20,570,getmaxx()-20,590,7);
    for(int iCont=0;iCont<NBOTONES;iCont++){
        exterior(bBot[iCont].iCx,bBot[iCont].iCy,bBot[iCont].iCFx,bBot[iCont].iCFy,bBot[iCont].iColorF);
    }*/


void seleccionBoton(BOTONES bBot[10],int iXx,int iYy){
     for(int iCont=0;iCont<NBOTONES;iCont++){
         if((iXx>=bBot[iCont].iCx)&&(iYy>=bBot[iCont].iCy)&&(iXx<=bBot[iCont].iCFx)&&(iYy<=bBot[iCont].iCFy)){
             setcolor(15);
             switch(bBot[iCont].iCualBoton){
                 case 0:setbkcolor(0);
                        outtextxy(400,300,"Boton 1");
                        setbkcolor(8);
                        outtextxy(35,530,"Se presionó el Boton 1");
                        break;
                 case 1:setbkcolor(0);
                        outtextxy(400,300,"Boton 2");
                        setbkcolor(8);
                        outtextxy(35,530,"Se presionó el Boton 2");
                        break;
                 case 2:setbkcolor(0);
                        outtextxy(400,300,"Boton 3");
                        setbkcolor(8);
                        outtextxy(35,530,"Se presionó el Boton 3");
                        break;
                 case 3:setbkcolor(0);
                        outtextxy(400,300,"Boton 4");
                        setbkcolor(8);
                        outtextxy(35,530,"Se presionó el Boton 4");
                        break;
                 case 4:setbkcolor(0);
                        outtextxy(400,300,"Boton 5");
                        setbkcolor(8);
                        outtextxy(35,530,"Se presionó el Boton 5");
                        break;

                case 5:setbkcolor(0);
                        outtextxy(400,300,"Boton 6");
                        setbkcolor(8);
                        outtextxy(35,530,"Se presionó el Boton 6");
                        break;
                case 6:setbkcolor(0);
                        outtextxy(400,300,"Boton 7");
                        setbkcolor(8);
                        outtextxy(35,530,"Se presionó el Boton 7");
                        break;
                case 7:setbkcolor(0);
                        outtextxy(400,300,"PACMAN :V");
                        setbkcolor(8);
                        outtextxy(35,530,"Presione el boton ESPACIO para iniciar el juego");
                        break;
             }
         }

     }
}


void generaMalla()
{
    setcolor(15);
    int x1, x2, y1, y2;
    x1 = 140, y1 = 100, x2 = 150, y2 = 110;
    for (int i = 0; i < 1; i++)
    {
        x1 += 10;
        x2 += 10;
        y1 = 100;
        y2 = 110;
        //x1 = 140;
        for (int i = 0; i < 1; i++)
        {
         rectangle(x1, y1, x2, y2);
         y1 += 10;
         y2 += 10;
        }
    }
}
void colores()
{
    setcolor(15);
    int x1, x2, y1, y2;
    x1 =30 , y1 = 160, x2 = 60, y2 = 190;

    int col = 0;
    for (int i = 0; i < 2; i++)
    {
        x1 += TAMC;
        x2 += TAMC;
        y1 = 160;
        y2 = 190;
        for (int i = 0; i < 8; i++)
        {

            exterior(x1, y1, x2, y2, col);
            y1+= TAMC;
            y2+= TAMC;
            col++;
        }
    }
}



/*void interior (int x1, int y1, int x2, int y2, int color){
    setfillstyle(1, color);
    bar(x1, y1, x2, y2);
    setcolor(0);
    line(x1,y1,x2+2,y1);
    line(x1,y1,x1, y2+2);
    setcolor(15);
    line(x1,y2+2,x2+2,y2+2);
    line(x2+2,y2+2,x2+2,y1);
    setcolor(0);
    }
void exterior (int x1, int y1, int x2, int y2, int color){
    setfillstyle(1,color);
    bar(x1+1, y1+1, x2-1, y2-1);
    setcolor(15);setcolor(15);
    line(x1,y1,x2,y1);
    line(x1,y1,x1,y2);
    setcolor(0);
    line(x1,y2,x2,y2);
    line(x2,y2,x2,y1);
    setcolor(0);
    }
*/
