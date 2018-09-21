#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

#define NBOTONES 3
#define TAMBOTON 50

#define OPCIONES 2


typedef struct{
    int iCx; //Variable para capturar la posición inicial en coordenada en X
    int iCy; //Variable para capturar la posición inicial en coordenada en Y
    int iCFx; //Variable para capturar la posición final en coordenada en X
    int iCFy; //Variable para capturar la posición final en coordenada en Y
    int iColorF; //Variable para capturar el color de fondo de los objetos
    int iColorL; //Variable para capturar el color del contorno de los objetos
    int iCualBoton;
}BOTONIN;

void crearBotones(BOTONIN bBot[NBOTONES], int par, int ixx, int iyy);
int seleccionaBoton(BOTONIN bBot[10],int iXx,int iYy);
int MenuPrincipal();
int nuevoFile();
int abrirFile();
int SalirTodo();

#endif // BUTTON_H_INCLUDED

int MenuPrincipal()
{
    initwindow(800, 600, "HOLA"); //Pantalla de bienvenida
    int ixb = 200, iyb = 300, option = 0;
    BOTONIN bBot[10];  //estructura de los botones
    char cCualTecla;
    int iXraton,iYraton;
    crearBotones(bBot, 0, ixb, iyb);
    setbkcolor(7);
    outtextxy(bBot[NBOTONES-3].iCx, bBot[NBOTONES-3].iCy, "NUEVO");
    outtextxy(bBot[NBOTONES-2].iCx, bBot[NBOTONES-2].iCy, "ABRIR");
    outtextxy(bBot[NBOTONES-1].iCx, bBot[NBOTONES-1].iCy, "SALIR");
    do
        {
            if(ismouseclick(WM_LBUTTONDOWN)) //Si el mouse es presionado
            {
                getmouseclick(WM_LBUTTONDOWN,iXraton,iYraton); //Toma el valor del mouse
                option = seleccionaBoton(bBot,iXraton,iYraton);  //Seleciona el boton de las coordenadas
            }
        }
    while(option == 0); //Mientras que no se presione alguna tecla
    return (option);
}

void crearBotones(BOTONIN bBot[], int par, int ixx, int iyy)
{
    int iCont, iXx, iYy, i;
    iXx = ixx;  //Punto de inicio del los botones
    iYy = iyy;  //Punto de fin del primer boton (no cambia)

    for(iCont = 0;iCont < NBOTONES - par; iCont++) //Ciclo que genera los botones
        {
         bBot[iCont].iCx = iXx;
         bBot[iCont].iCy = iYy;
         bBot[iCont].iCFx = iXx+TAMBOTON+40;
         bBot[iCont].iCFy = iYy+TAMBOTON;
         bBot[iCont].iColorF = 7;  //Color gris oscuro
         bBot[iCont].iColorL = 15;  //Color gris claro
         bBot[iCont].iCualBoton = iCont;
         iXx+= TAMBOTON + 50;
         exterior(bBot[iCont].iCx,bBot[iCont].iCy,bBot[iCont].iCFx,bBot[iCont].iCFy,bBot[iCont].iColorF); //Genra los botones de opcion
        }
}

int seleccionaBoton(BOTONIN bBot[10],int iXx,int iYy)
{
     int iCont = 0, res = 0;
     for(iCont = 0; iCont < NBOTONES; iCont++)
        {
         if((iXx>=bBot[iCont].iCx)&&(iYy>=bBot[iCont].iCy)&&(iXx<=bBot[iCont].iCFx)&&(iYy<=bBot[iCont].iCFy))
         {
             setcolor(15);
             switch(bBot[iCont].iCualBoton)
             {
                 case 0:setbkcolor(0);
                        outtextxy(400,300,"Boton 1");
                        setbkcolor(8);
                        outtextxy(35,530,"Se presionó el Boton 1");
                        res = nuevoFile();
                        break;
                 case 1:setbkcolor(0);
                        outtextxy(400,300,"Boton 2");
                        setbkcolor(8);
                        outtextxy(35,530,"Se presionó el Boton 2");
                        res = abrirFile();
                        break;
                 case 2:setbkcolor(0);
                        outtextxy(400,300,"Boton 3");
                        setbkcolor(8);
                        outtextxy(35,530,"Se presionó el Boton 3");
                        res = SalirTodo();
                        break;
             }
         }

     }
     return (res);
}

int nuevoFile()
{
    return 1;
}

int abrirFile()
{
    return 2;
}

int SalirTodo()
{
    char cTecla = 0;
    int yas;
    initwindow(800, 600, "a");
    outtextxy(200, 300, "¿Realmente desea usted Salir del Editor?");
    outtextxy(200, 350, "SI[Y]    NO[N]");

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
           yas =  MenuPrincipal();
        break;
        case 83:
            return 3;
        break;
    }
}

void interfazPrimera()
{

}
