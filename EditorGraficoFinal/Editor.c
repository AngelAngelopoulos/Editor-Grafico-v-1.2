
#include <stdlib.h>
#include <stdio.h>
#include <graphics.h>
#include <string.h>
#include "LIB01.h"
#include "button.h"
#include "EDITOR_WORDS.h"
#include "EDITOR_INTERFACE.h"
//#include "EDITOR_GRID_GEN.h"

void guardarArch(PIX **ptrPixel, int n, int m, char Name[]);
void leerArch(PIX **ptrPixel, int n, int m, char Name[]);
void leerPrimario(char Name[], int *fila, int *colu);

int main()
{
    PIX **ptrPixel;
    char cCualTecla;
    int opc = 0, fila = 0, colu = 0, malla = 0, res = 0;
    int renDes = 0, colDes = 0;
    int posxL = 300, posyL = 500;
    char nombre[30];
    opc = MenuPrincipal();
    printf("%d", opc);

do{
        switch(opc)
        {
            case 1:
                initwindow(800, 600, "NUEVO GRAFICO");
                fila = EscribeDato(posxL, posyL);
                colu = EscribeDato(posxL+100, posyL);
                res = asignaMem(&ptrPixel, fila, colu);
                iniStru(ptrPixel, fila, colu);
                LetrasStr(nombre, posxL, posyL+50);
                guardarArch(ptrPixel, fila, colu, nombre);
                malla = menu(ptrPixel, fila, colu);
                if (malla)
                {
                    break;
                }
                //malla = StartSpace(ptrPixel, fila, colu);
                //guardarArch(ptrPixel, fila, colu, nombre);
                //leerArch(ptrPixel, fila, colu, nombre);
                //impStruc(ptrPixel, fila, colu);
                //getch();
                //liberaMem(ptrPixel, fila, colu);
            break;

            case 2:
                initwindow(800, 600, "ABRIR GRAFICO");
                LetrasStr(nombre, posxL, posyL+50);
                leerPrimario(nombre, &renDes, &colDes);
                res = asignaMem(&ptrPixel, renDes, colDes);
                leerArch(ptrPixel, renDes, colDes, nombre);
                fila = renDes;
                colu = colDes;
                malla = menu(ptrPixel, renDes, colDes);

                if (malla)
                {
                    break;
                }
                //impStruc(ptrPixel, renDes, colDes);
                //getch();
            break;

            case 3:
                res = asignaMem(&ptrPixel, fila, colu);
                leerArch(ptrPixel, fila, colu, nombre);
                malla = menu(ptrPixel, fila, colu);
            break;

        }

        switch (malla)
        {
            setcolor(0);
            setbkcolor(0);
            case 1:
                liberaMem(ptrPixel, fila, colu);
                opc = 1;
            break;

            case 2:
                liberaMem(ptrPixel, fila, colu);
                opc = 2;
            break;

            case 3:
                guardarColor(ptrPixel, fila, colu);
                guardarArch(ptrPixel, fila, colu, nombre);
                liberaMem(ptrPixel, fila, colu);
                opc = 3;
            break;

            case 4:
                guardarColor(ptrPixel, fila, colu);
                LetrasStr(nombre, 680, 570);
                guardarArch(ptrPixel, fila, colu, nombre);
                liberaMem(ptrPixel, fila, colu);
                opc = 3;
            break;

            case 5:
                char cTecla = 0;
                do
                {
                    fflush(stdin);
                    if(kbhit())
                    {
                        cTecla=getch();
                    }
                }
                while(cTecla == 0);

                switch(cTecla)
                {
                    case 121:
                        exit(1);
                    break;
                    case 110:
                       malla = menu(ptrPixel, fila, colu);
                    break;
                }
    }
}
    while ( 1 == 1);
    return 0;
}


    void guardarArch(PIX **ptrPixel, int n, int m, char Name[])
    {
        FILE *arch;


        arch = fopen(Name, "wb+");

        if (arch)
            {
                for (int i = 0; i < n; i ++)
                {
                    for(int j = 0; j < m; j++)
                    {
                        fwrite(&(*(ptrPixel+i)+j)->nFil, sizeof(int), 1, arch);
                        fwrite(&(*(ptrPixel+i)+j)->nCol, sizeof(int), 1, arch);
                        fwrite(&(*(ptrPixel+i)+j)->ix, sizeof(int), 1, arch);
                        fwrite(&(*(ptrPixel+i)+j)->iy, sizeof(int), 1, arch);
                        fwrite(&(*(ptrPixel+i)+j)->iColor, sizeof(int), 1, arch);
                    }
                }
                printf("El archivo se guardo\n");
            }
            fclose(arch);
    }

    void leerArch(PIX **ptrPixel, int n, int m, char Name[])
    {

        FILE *arch;


        arch = fopen(Name, "rb+");

        if (arch)
            {
                for (int i = 0; i < n; i ++)
                {
                    for(int j = 0; j < m; j++)
                    {
                        fread(&(*(ptrPixel+i)+j)->nFil, sizeof(int), 1, arch);
                        fread(&(*(ptrPixel+i)+j)->nCol, sizeof(int), 1, arch);
                        fread(&(*(ptrPixel+i)+j)->ix, sizeof(int), 1, arch);
                        fread(&(*(ptrPixel+i)+j)->iy, sizeof(int), 1, arch);
                        fread(&(*(ptrPixel+i)+j)->iColor, sizeof(int), 1, arch);
                    }
                }
            }
            fclose(arch);
    }

    void leerPrimario(char Name[], int *renDes, int *colDes)
    {
        FILE *arch;


        arch = fopen(Name, "rb+");

        if (arch)
        {
            fread(renDes, sizeof(int), 1, arch);
            fread(colDes, sizeof(int), 1, arch);
    }
        fclose(arch);
}

