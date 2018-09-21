#ifndef EDITOR_GRID_GEN_H_INCLUDED
#define EDITOR_GRID_GEN_H_INCLUDED

#define TAMC 30
typedef struct
{
    int ix;  //Variable que guarda el valor de la coordenada X
    int iy;  //Variable que guarda el valor de la coordenada Y
    int iColor;  //Variable que guarda el color de la coordenada (X, Y)
}PIX;  //Estructura del pixel

void generaMalla();  //Funcion que genera la malla (dinamica)
//void colores();
int ObtenerColor();  //Funcion que obtiene y devuelve un color
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

#endif // EDITOR_GRID_GEN_H_INCLUDED

int StartSpace(PIX **ptrArr, int ren, int col)
{
    int selcol = 0;
    int res = 0;
    res = asignaMem(&ptrArr, ren, col);

    if (res == 1)
    {
        //initwindow(800, 600, "HOLA");
        iniStru(ptrArr, ren, col);
        creaMalla(ptrArr, ren, col);
        //colores();
        selcol = ObtenerColor();
        if (selcol == 1){
            guardarColor(ptrArr, ren, col);
            printf("Color Guardado\n");
            imprimirCor(ptrArr, ren, col);
            impStruc(ptrArr, ren, col);
            getch();
            liberaMem(ptrArr, ren, col);
        }
    }
    return (res);
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

int ObtenerColor()
{
    int iXraton = 0, iYraton = 0, color = 0, band = 0;
    char cCualTecla = NULL;
    do
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
            if (iXraton < 520 && iYraton > 20 && iYraton < 520 && iXraton > 20)
            {
                setfillstyle(1,color);
                floodfill(iXraton+1, iYraton+1, 15);
                printf("Color: %d\n", color);
            }
        }
    }
    while(band != 1 && cCualTecla != 32);
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
        }
    }
}
