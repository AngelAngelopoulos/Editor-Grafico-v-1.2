#ifndef EDITOR_INTERFACE_H_INCLUDED
#define EDITOR_INTERFACE_H_INCLUDED

#define TAMBOTONx 100
#define TAMBOTONy 30
#define NBOTONES 5
//#include "EDITOR_GRID_GEN.h"

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

typedef struct
{
    int nFil;  //Guarda el numero de filas
    int nCol; //Guarda el numero de columnas
    int ix;  //Variable que guarda el valor de la coordenada X
    int iy;  //Variable que guarda el valor de la coordenada Y
    int iColor;  //Variable que guarda el color de la coordenada (X, Y)
}PIX;  //Estructura del pixel

int StartSpace(PIX **ptrArr, int ren, int col, BOTONES bBot[]);
void generaMalla();  //Funcion que genera la malla (dinamica)
//void colores();
int ObtenerColor(BOTONES bBoton[], PIX **ptrArr, int n, int m);  //Funcion que obtiene y devuelve un color
void PonerColor(int color);  //funcion que pone un color en un pixel
void llenaBarra();
//int pideNum();
int asignaMem(PIX ***ptrArr, int n, int m);  //Funcion para asignar memoria a la malla
void creaMalla(PIX **ptrArr, int n, int m);  //Funcion para usar los valores de nxm
void guardarColor(PIX **ptrArr, int n, int m);  //Funcion para guardar el color y la coordenada en la estructura
void liberaMem(PIX **ptrArr, int n, int m);
void imprimirCor(PIX **ptrArr, int n, int m);
void iniStru(PIX **ptrArr, int n, int m);  //Incializa la estructura
void impStruc(PIX **ptrArr, int n, int m);  //Ver el objeto
void impMini(PIX **ptrArr, int n, int m);


void generarBoton(int y1, int y2, int num);
void crearBotones(BOTONES bBot[10]);
int seleccionBoton(BOTONES bBot[10],int iXx,int iYy);
int menu(PIX **ptrPixel, int fila, int colu);
void colores();
void interfazG();


#endif // EDITOR_INTERFACE_H_INCLUDED

int menu(PIX **ptrPixel, int fila, int colu)
{
    initwindow(800, 600, "EditPixelPlus");
    char cCualTecla;
    int iXraton,iYraton;
    BOTONES bBot[10];
    int band = 0;
    interfazG();
    crearBotones(bBot);
    colores();
    band = StartSpace(ptrPixel, fila, colu, bBot);

    /*do
    {
        fflush(stdin);
        if(kbhit())
        {
            cCualTecla=getch();
            switch(cCualTecla)
            {
                 case 32:
                     band = 1;
                 break;
            }
        }
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN,iXraton,iYraton);
            seleccionBoton(bBot,iXraton,iYraton);
        }
    }
    while(cCualTecla!=32 || band != 1);*/
    return (band);
}

void interfazG()
{
    exterior(0, 0, 800, 800, 8); //marco principal
	interior(10, 10, 790, 590, 15);  //marco principal

	rectangle(150, 50, 650, 550); //Marco de trabajo
	setfillstyle(1, 0);
    floodfill(160, 110, 0);

	exterior(0, 0, 800, 50, 7); //Barra de opciones arriba
	interior(5, 5, 795, 45, 8); //Barra de opciones arriba

	exterior(0, 50, 150, 550, 7); //Barra de herramientas
	interior(5, 55, 145, 545, 8); //Barra de herramientas

	exterior(650, 50, 800, 550, 7); //Barra de visualizacion
	interior(655, 55, 795, 545, 8); //Barra de visualizacion

	exterior(0, 550, 800, 600, 7); //Barra de informacion
	interior(5, 555, 795, 595, 8);  //Barra de informacion
    setcolor(15);
    rectangle(30, 560, 770, 590);
    setfillstyle(1, 0);
    floodfill(31, 566, 15);

    setcolor(0);
    rectangle(675, 100, 775, 200);  //Area color actual
    setfillstyle(1, 15);
    floodfill(676, 101, 0);
    setbkcolor(7);
    outtextxy(675, 80, "Color Actual: ");

    setcolor(15);
    rectangle(675, 300, 775, 400);  //Area de previsualizacion
    setfillstyle(1, 0);
    floodfill(676, 301, 15);
}

void crearBotones(BOTONES bBot[10])
{
    int iCont,iXx,iYy, i;
    iXx=50;
    iYy=10;
    for(iCont=0;iCont<NBOTONES;iCont++){
         bBot[iCont].iCx=iXx;
         bBot[iCont].iCy=iYy;
         bBot[iCont].iCFx=iXx+TAMBOTONx;
         bBot[iCont].iCFy=iYy+TAMBOTONy;
         bBot[iCont].iColorF=7;
         bBot[iCont].iColorL=15;
         bBot[iCont].iCualBoton=iCont;
         iXx+=TAMBOTONx+50;
    }
    for(int iCont=0;iCont<NBOTONES;iCont++){
        exterior(bBot[iCont].iCx,bBot[iCont].iCy,bBot[iCont].iCFx,bBot[iCont].iCFy,bBot[iCont].iColorF);
    }
    setbkcolor(7);

    outtextxy(bBot[NBOTONES-5].iCx+20, bBot[NBOTONES-5].iCy+5, "NEW");
    outtextxy(bBot[NBOTONES-4].iCx+20, bBot[NBOTONES-4].iCy+5, "OPEN");
    outtextxy(bBot[NBOTONES-3].iCx+20, bBot[NBOTONES-3].iCy+5, "SAVE");
    outtextxy(bBot[NBOTONES-2].iCx+20, bBot[NBOTONES-2].iCy+5, "SAVE AS");
    outtextxy(bBot[NBOTONES-1].iCx+20, bBot[NBOTONES-1].iCy+5, "CLOSE");
}

int seleccionBoton(BOTONES bBot[10],int iXx,int iYy){
    int res = 0;
     for(int iCont=0;iCont<NBOTONES;iCont++){
         if((iXx>=bBot[iCont].iCx)&&(iYy>=bBot[iCont].iCy)&&(iXx<=bBot[iCont].iCFx)&&(iYy<=bBot[iCont].iCFy)){
             setcolor(15);
             switch(bBot[iCont].iCualBoton){
                case 0:
                    setbkcolor(0);
                    outtextxy(35, 565,"Ha seleccionado crear un nuevo archivo ");
                    res = 1;
                break;
                case 1:
                    setbkcolor(0);
                    outtextxy(35, 565,"Ha seleccionado abrir un archivo ");
                    res = 2;
                break;
                case 2:
                    setbkcolor(0);
                    outtextxy(35, 565,"El archivo ha sifo guardado con exito ");
                    res = 3;
                break;
                case 3:
                    setbkcolor(0);
                    outtextxy(35, 565,"Escriba el nombre del nuevo archivo para guardar: ");
                    res = 4;
                break;
                case 4:
                    setbkcolor(0);
                    outtextxy(35, 565,"¿Seguro que quiere salir del Editor? [y][n] (PRESIONE [Y] PARA SALIR)");
                    res = 5;
                break;
             }
         }

     }
     return (res);
}

void colores()
{
    setcolor(15);
    int x1, x2, y1, y2;
    x1 =45 , y1 = 130, x2 = 75, y2 = 160;

    int col = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int i = 0; i < 8; i++)
        {

            exterior(x1, y1, x2, y2, col);
            y1+= TAMC;
            y2+= TAMC;
            col++;
        }
        x1 += TAMC;
        x2 += TAMC;
        y1 = 130;
        y2 = 160;
    }
}


//////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////

int StartSpace(PIX **ptrArr, int ren, int col, BOTONES bBot[])
{
    int selcol = 0;
    //int res = 0;
    //res = asignaMem(&ptrArr, ren, col);

    //if (res == 1)
    {
        //initwindow(800, 600, "HOLA");
        //iniStru(ptrArr, ren, col);
        creaMalla(ptrArr, ren, col);
        //colores();
        selcol = ObtenerColor(bBot, ptrArr, ren, col);
        //if (selcol == 1){
        //guardarColor(ptrArr, ren, col);
            //printf("Color Guardado\n");
            //imprimirCor(ptrArr, ren, col);
            //impStruc(ptrArr, ren, col);
            //getch();
            //liberaMem(ptrArr, ren, col);
        }
        return (selcol);
}

/*void colores()
{
    setcolor(15);
    int x1, x2, y1, y2, i ,j;
    x1 = 550, y1 = 20, x2 = 580, y2 = 50;

    int col = 0;
    for (i = 0; i < 2; i++)
    {
        x1 += TAMC;
        x2 += TAMC;
        y1 = 20;
        y2 = 50;
        for (j = 0; j < 8; j++)
        {
            exterior(x1, y1, x2, y2, col);
            y1+= TAMC;
            y2+= TAMC;
            col++;
        }
    }
}*/

int ObtenerColor(BOTONES bBot[], PIX **ptrArr, int n, int m)
{
    int iXraton = 0, iYraton = 0, color = 0, band = 0;
    char cCualTecla = NULL;
    do
        {
        if(ismouseclick(WM_RBUTTONDOWN))
            {
                getmouseclick(WM_RBUTTONDOWN,iXraton,iYraton);
                color = getpixel(iXraton, iYraton);
                setfillstyle(1, color);
                floodfill(676, 101, 0);
                printf("Color: %d", color);
            }
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN,iXraton,iYraton);
            band = seleccionBoton(bBot, iXraton, iYraton);
            if (iXraton < 600 && iYraton > 100 && iYraton < 500 && iXraton > 200)
            {
                setfillstyle(1,color);
                floodfill(iXraton+1, iYraton+1, 15);
                printf("Color: %d\n", color);
            }
        }

        guardarColor(ptrArr, n, m);
        impMini(ptrArr, n, m);
    }
    while(band == 0);

    return(band);
}

int asignaMem(PIX ***ptrArr, int n, int m)
{
    int res = 0, i = 0;

    *ptrArr = (PIX**)malloc(sizeof(PIX*)*n);

    if (*ptrArr != NULL)
    {
        res = 1;

        for (i = 0; i < m; i++)
        {
            *(*ptrArr+i) = (PIX*)malloc(sizeof(PIX)*m);

            if (*(*ptrArr+i) == NULL)
            {
                while (--i > 0)
                {
                    free(*(*ptrArr+i));
                }
                free(*ptrArr);
                res = 0;
            }
        }
    }
    return(res);
}

void creaMalla(PIX **ptrArr, int n, int m)
{
    int tamDispx = 400;
    int tamDispy = 400;
    int x1, x2, y1, y2, i, j;
    x1 = 200, y1 = 100;
    x2 = x1 + (tamDispx/n) , y2 = y1 + (tamDispy/m);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            setcolor(15);
            rectangle(x1, y1, x2, y2);
            setfillstyle(1, (*(ptrArr+i)+j)->iColor);
            floodfill(x1+1, y1+1, 15);
            y1 = y2;
            y2 = y1+(tamDispy/m);
        }
        x1 = x2;
        x2 = x1+(tamDispx/n);
        y1 = 100;
        y2 = y1 + (tamDispy/m);
    }
}

void guardarColor(PIX **ptrArr, int n, int m)
{
    int tamDispx = 400;
    int tamDispy = 400;
    int x1, x2, y1, y2, i, j;
    x1 = 200, y1 = 100;
    x2 = x1 + (tamDispx/n) , y2 = y1 + (tamDispy/m);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            (*(ptrArr+i)+j)->iColor = getpixel(x1+1, y1+1);
            (*(ptrArr+i)+j)->ix = i;
            (*(ptrArr+i)+j)->iy = j;
            (*(ptrArr+i)+j)->nFil = n;
            (*(ptrArr+i)+j)->nCol = m;
            y1 = y2;
            y2 = y1+(tamDispy/m);
        }
        x1 = x2;
        x2 = x1+(tamDispx/n);
        y1 = 100;
        y2 = y1 + (tamDispy/m);
    }
}

void liberaMem(PIX **ptrArr, int n, int m)
{
    int i;
    for(i = m; i > m; i--)
    {
        free((*ptrArr+i));
    }
    free(*ptrArr);
}

void imprimirCor(PIX **ptrArr, int n, int m)
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("X = %d ", (*(ptrArr+i)+j)->ix);
            printf("Y = %d ", (*(ptrArr+i)+j)->iy);
            printf("Color = %d ", (*(ptrArr+i)+j)->iColor);
            printf("\n");
        }
    }
}

void impStruc(PIX **ptrArr, int n, int m)
{
    initwindow(800, 600, " ");
    int tamDispx = 500;
    int tamDispy = 500;
    int x1, x2, y1, y2, i, j;
    x1 = 20, y1 = 20;
    x2 = x1 + (tamDispx/n) , y2 = y1 + (tamDispy/m);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            setcolor(15);
            setfillstyle(1,(*(ptrArr+i)+j)->iColor);
            rectangle(x1, y1, x2, y2);
            floodfill(x1+1, y1+1, 15);
            y1 = y2;
            y2 = y1+(tamDispy/m);
        }
        x1 = x2;
        x2 = x1+(tamDispx/n);
        y1 = 20;
        y2 = y1 + (tamDispy/m);
    }

}

void iniStru(PIX **ptrArr, int n, int m)
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            (*(ptrArr+i)+j)->iColor = 0;
            (*(ptrArr+i)+j)->ix = 0;
            (*(ptrArr+i)+j)->iy = 0;
            (*(ptrArr+i)+j)->nFil = n;
            (*(ptrArr+i)+j)->nCol = m;
        }
    }
}


void impMini(PIX **ptrArr, int n, int m)
{
    int tamDispx = 100;
    int tamDispy = 100;
    int x1, x2, y1, y2, i, j;
    x1 = 675, y1 = 300;
    x2 = x1 + (tamDispx/n) , y2 = y1 + (tamDispy/m);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            setcolor(15);
            setfillstyle(1,(*(ptrArr+i)+j)->iColor);
            rectangle(x1, y1, x2, y2);
            floodfill(x1+1, y1+1, 15);
            y1 = y2;
            y2 = y1+(tamDispy/m);
        }
        x1 = x2;
        x2 = x1+(tamDispx/n);
        y1 = 300;
        y2 = y1 + (tamDispy/m);
    }

}
