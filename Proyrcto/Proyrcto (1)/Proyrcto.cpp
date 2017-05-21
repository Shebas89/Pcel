/***************************************************
*              PROGRAMA CRAZY MACE                 *
****************************************************
* AUTOR      :  Henry Sebastian Velandia Martinez  *
* FECHA      :  Noviembre 2 de 2008                *
* ASIGNATURA :  PCEL - 3                           *
***************************************************/

/**LIBRERIAS**/

# include <conio.h>
# include <stdio.h>
# include <stdlib.h>

/**CONSTANTES**/

# define JF 10   /**Columnas Nivel Facil**/
# define IF 10   /**Filas Nivel Facil**/
# define JM 15   /**Columnas Nivel Mediano**/
# define IM 40   /**Filas Nivel Mediano**/
# define JD 20   /**Columnas Nivel Dificil**/
# define ID 70   /**Filas Nivel Dificil**/
# define W 94    /**Arriba**/
# define P 64    /**Paredes**/
# define M 42    /**Muros**/
# define S 118   /**Abajo**/
# define A 60    /**Derecha**/
# define D 62    /**Izquierda**/
# define E 32    /**Espacio Vacio**/
# define NOM 50  /**Nombre**/

/**ESTRUCTURAS**/

struct jugador
{
    char nombre[NOM];
};

/**PROTOTIPOS**/

void ayuda (void);
char menu (void);
char nivel (struct jugador);
void inciar_facil (char[IF][JF],int*,int*,int*);
void inciar_medio (char[IM][JM],int*,int*,int*);
void imprimir_tablero (char [IF][JF],struct jugador,int,int,int);
void imprimir_tablero_medio (char [IM][JM],struct jugador,int,int,int);
void mover_arriba (char [IF][JF],struct jugador,int*,int*,int*);
void mover_arriba_medio (char [IM][JM],struct jugador,int*,int*,int*);
void mover_abajo (char [IF][JF],struct jugador,int*,int*,int*);
void mover_abajo_medio (char [IM][JM],struct jugador,int*,int*,int*);
void mover_derecha (char [IF][JF],struct jugador,int*,int*,int*);
void mover_derecha_medio (char [IM][JM],struct jugador,int*,int*,int*);
void mover_izquierda (char [IF][JF],struct jugador,int*,int*,int*);
void mover_izquierda_medio (char [IM][JM],struct jugador,int*,int*,int*);
void despedida (void);
main ()

/**PROGRAMA PRONCOPAL**/

{
    int puntos, i, j;
    char tab1[IF][JF], tab2[IM][JM], opc, niv, mov;
    struct jugador nom;
    do
    {
        opc=menu();
            switch(opc)
            {
                case '1':
                    system("cls");
                    printf("\n\n\n\n\n\n\t\t\tPOR FAVOR DIGITE SU NOMBRE\n\t\t\t");
                    gets(nom.nombre);
                    system("cls");
                    do
                    {
                        system("cls");
                        niv=nivel(nom);
                        if(niv=='1')
                        {
                            inciar_facil (tab1,&i,&j,&puntos);
                            imprimir_tablero (tab1,nom,puntos,i,j);
                                do
                                {
                                    mov=getch();    /**MOVER MACEL**/

                                    if(mov=='w' || mov=='W')    /** ARIBA **/
                                    {
                                        mover_arriba(tab1,nom,&puntos,&i,&j);
                                    }
                                    else    if(mov=='d' || mov=='D')    /** DERECHA **/
                                    {
                                        mover_derecha (tab1,nom,&puntos,&i,&j);
                                    }
                                    else    if(mov=='s' || mov=='S')    /** ABAJO **/
                                    {
                                        mover_abajo (tab1,nom,&puntos,&i,&j);
                                    }
                                    else    if(mov=='a' || mov=='A')    /** IZQUIERDA **/
                                    {
                                        mover_izquierda (tab1,nom,&puntos,&i,&j);
                                    }
                                }while(tab1[8][1]==70&&puntos<100);
                                if(tab1[8][1]!=70)
                                {
                                    system("cls");
                                    printf("\n\n\n\n\n\n\t\tFELICITACIONES..... JUEGO COMPLETO\n\n\n\n\n");
                                    getch();
                                }100
                                if(puntos>=100)
                                {
                                    system("cls");
                                    printf("\n\n\n\n\n\n\t\tJUEGO INCOMPLETO....INTENTELO DE NUEVO\n\n\n\n\n");
                                    getch();
                                }
                        }
                        else if(niv=='2')
                        {
                            inciar_medio (tab2,&i,&j,&puntos);
                            imprimir_tablero_medio (tab2,nom,puntos,i,j);
                            do
                            {
                                mov=getch();    /**MOVER MACEL**/
                                if(mov=='w' || mov=='W')    /** ARIBA **/
                                {
                                    mover_arriba_medio(tab2,nom,&puntos,&i,&j);
                                }
                                else    if(mov=='d' || mov=='D')    /** DERECHA **/
                                {
                                    mover_derecha_medio (tab2,nom,&puntos,&i,&j);
                                }
                                else    if(mov=='s' || mov=='S')    /** ABAJO **/
                                {
                                    mover_abajo_medio (tab2,nom,&puntos,&i,&j);
                                }
                                else    if(mov=='a' || mov=='A')    /** IZQUIERDA **/
                                {
                                    mover_izquierda_medio (tab2,nom,&puntos,&i,&j);
                                }
                            }while((tab2[36][1]==70)&&(puntos<1000)&&(mov!=42));
                            if(tab2[36][1]!=70)
                            {
                                system("cls");
                                printf("\n\n\n\n\n\n\t\tFELICITACIONES..... JUEGO COMPLETO\n\n\n\n\n");
                                getch();
                            }
                            if(puntos>=500)
                            {
                                system("cls");
                                printf("\n\n\n\n\n\n\t\tJUEGO INCOMPLETO....INTENTELO DE NUEVO\n\n\n\n\n");
                                getch();
                            }
                            if(mov==42)
                            {
                                system("cls");
                                printf("\n\n\n\n\n\n\t\tJUEGO INCOMPLETO....INTENTELO DE NUEVO\n\n\n\n\n");
                                getch();
                            }
                        }
                    }while(niv!='1'&&niv!='2'&&niv!='3');
                break;
                case '2':
                ayuda ();
                break;
                case '3':
                despedida ();
                break;
            }
    }while(opc!='3');
}

/**SUBPROGRAMAS**/

void ayuda (void)
{
    system("cls");
    printf("\n\n\n\t\t\tBIENVENIDO A CRAZY MACEL....\n\n\nESTE JUEGO CONSISTE EN MOVER EL MACEL POR MEDIO DEL LAVERINTO CON EL FIN DE\nLLEGAR A LA META LA CUAL ES LA 'F'.\nCUANDO EL MACEL HALLA LLEGADO A LA 'F' EL TABLERO HABRA FINALIZADO Y PASARA AL  SIGUIENTE NIVEL.\n\nCADA DESPLAZAMIENTO DEL MACEL PRODUCE UN PUNTO, AL CHOCARCE CON UNA PARED\nAUMENTARA 5 PUNTOS Y AL CHOCARCE CON UN MURO AUENTARA 3 PUNTOS.\n\nEL OBJETIVO ES PASAR EL LABERINTO CON EL MENOR NUMERO DE PUNTOS POSIBLES.\n\n\nUD TIENE TRS OPCIONES DE SALIDA:\n\n1.JUEGO COMPLETO\n2.JUEGO ABANDONADO\n3.JUEGO INCOMPLETO\n\nJUEGO IMPLETO: ES CUANDO EL JUGADOR EXCEDE EL NUMERO DE PUNTOS PERMITIDOS EN EL TABLERO.\n\n\nPARA PODER MOVER AL MACEL TIENE LAS SIGUIENTES OPCIONES:\n\nW=DESPLAZARCE HACIA ARRIBA\nS=DESPLAZARCE HACIA ABAJO\nA=DESPLAZARCE A LA IZQUIERDA\nD=DESPLAZARCE A LA DERECHA\n\n\n\n\t\t\tMUCHA SUERTE.....\n\n\n");
    getch();
    system("cls");
}
char menu (void)
{
    char opc;
    system("cls");
    printf("\n\n\n\n\n\n\t\t\tESCOJA UNA OPCION\n\n\n\t\t\t1.EMPEZAR A JUGAR\n\n\n\t\t\t2.AYUDA\n\n\n\t\t\t3.SALIR\n");
    opc=getch();
    return(opc);
    system("cls");
}
char nivel(struct jugador nom)
{
    char niv;
    printf("\n\n\n\n\n\n\t\t\t%s ESCOJA EL NIVEL DE JUEGO\n\n\n\t\t\t1.FACIL\n\n\n\t\t\t2.MEDIO\n\n\n\t\t\t",nom.nombre);
    niv=getch();
    return(niv);
}
void inciar_facil (char tab1[IF][JF],int*i,int*j,int*pun)
{
    int filas, columnas;
    for(filas=0;filas<IF;filas++)
    {
        for(columnas=0;columnas<IF;columnas++)
            tab1[filas][columnas]=E;   /** (ESPACIO) **/
    }
    tab1[1][1]=73;   /** (I) **/
    tab1[8][1]=70;   /** (F) **/
    *pun=0;     /**PUNTUACION**/
    *i=1,*j=1;
    tab1[5][3]=M,tab1[5][3]=M,tab1[4][6]=M;  /** (*) **/
    for(filas=0;filas<1;filas++)   /** (@) **/
    {
        for(columnas=0;columnas<JF;columnas++)
            tab1[filas][columnas]=P;
    }
    for(filas=9;filas<IF;filas++)   /** (@) **/
    {
        for(columnas=0;columnas<JF;columnas++)
            tab1[filas][columnas]=P;
    }
    for(columnas=0;columnas<1;columnas++)   /** (@) **/
    {
        for(filas=0;filas<IF;filas++)
            tab1[filas][columnas]=P;
    }
    for(columnas=9;columnas<JF;columnas++)   /** (@) **/
    {
        for(filas=0;filas<IF;filas++)
            tab1[filas][columnas]=P;
    }
    for(filas=2,columnas=1;columnas<6;columnas++)  /** (*) **/
        tab1[filas][columnas]=M;
    for(filas=4,columnas=2;columnas<5;columnas++)  /** (*) **/
        tab1[filas][columnas]=M;
    for(columnas=7,filas=2;filas<8;filas++)  /** (*) **/
        tab1[filas][columnas]=M;
    for(filas=8,columnas=2;columnas<6;columnas++)  /** (*) **/
        tab1[filas][columnas]=M;
    for(columnas=5,filas=6;filas<9;filas++)  /** (*) **/
        tab1[filas][columnas]=M;
    for(filas=6,columnas=1;columnas<4;columnas++)  /** (*) **/
        tab1[filas][columnas]=M;
}
void inciar_medio (char tab2[IM][JM],int*i,int*j,int*pun)
{
    int filas, columnas;
    for(filas=0;filas<IM;filas++)
    {
        for(columnas=0;columnas<JM;columnas++)
            tab2[filas][columnas]=E;        /** (ESPACIO) **/
    }
    tab2[4][13]=73;     /**(I)**/
    tab2[36][1]=70;     /**(F)**/
    *i=4,*j=13,*pun=0,tab2[1][7]=M,tab2[13][5]=M,tab2[3][13]=M,tab2[13][13]=M,tab2[14][7]=M,tab2[35][7]=M,tab2[4][11]=M,tab2[3][2]=M,tab2[4][4]=M,tab2[11][3]=M,tab2[3][8]=M,tab2[3][9]=M,tab2[34][4]=M,tab2[29][11]=M,tab2[25][7]=M,tab2[23][12]=M,tab2[33][2]=M;
    for(filas=0,columnas=0;columnas<JM;columnas++)    /** (@) **/
        tab2[filas][columnas]=P;
    for(filas=IM-1,columnas=0;columnas<JM;columnas++)    /** (@) **/
        tab2[filas][columnas]=P;
    for(columnas=0,filas=0;filas<IM;filas++)     /** (@) **/
        tab2[filas][columnas]=P;
    for(columnas=JM-1,filas=0;filas<IM;filas++)      /** (@) **/
        tab2[filas][columnas]=P;
    for(filas=2,columnas=1;columnas<=4;columnas++)
        tab2[filas][columnas]=M;
    for(columnas=9;columnas<14;columnas++)
        tab2[filas][columnas]=M;
    for(columnas=6,filas=1;filas<=11;filas++)
        tab2[filas][columnas]=M;
    for(filas=5,columnas=2;columnas<=4;columnas++)
        tab2[filas][columnas]=M;
    for(columnas=8;columnas<14;columnas++)
        tab2[filas][columnas]=M;
    for(columnas=8,filas=5;filas<8;filas++)
        tab2[filas][columnas]=M;
    for(columnas=2,filas=5;filas<12;filas++)
        tab2[filas][columnas]=M;
    for(filas=7,columnas=4;columnas<=6;columnas++)
        tab2[filas][columnas]=M;
    for(filas=9,columnas=2;columnas<=4;columnas++)
        tab2[filas][columnas]=M;
    for(filas=11,columnas=5;columnas<=8;columnas++)
        tab2[filas][columnas]=M;
    for(filas=7,columnas=10;columnas<=12;columnas++)
        tab2[filas][columnas]=M;
    for(filas=9,columnas=8;columnas<=10;columnas++)
        tab2[filas][columnas]=M;
    for(filas=9,columnas=12;columnas<=13;columnas++)
        tab2[filas][columnas]=M;
    for(filas=11,columnas=10;columnas<=12;columnas++)
        tab2[filas][columnas]=M;
    for(columnas=10,filas=7;filas<11;filas++)
        tab2[filas][columnas]=M;
    for(filas=37,columnas=2;columnas<=6;columnas++)
        tab2[filas][columnas]=M;
    for(columnas=2,filas=35;filas<=37;filas++)
        tab2[filas][columnas]=M;
    for(filas=35,columnas=1;columnas<=4;columnas++)
        tab2[filas][columnas]=M;
    for(filas=37,columnas=8;columnas<=10;columnas++)
        tab2[filas][columnas]=M;
    for(columnas=12,filas=35;filas<=37;filas++)
        tab2[filas][columnas]=M;
    for(filas=35,columnas=9;columnas<=12;columnas++)
        tab2[filas][columnas]=M;
    for(columnas=9,filas=33;filas<=35;filas++)
        tab2[filas][columnas]=M;
    for(filas=33,columnas=8;columnas<=10;columnas++)
        tab2[filas][columnas]=M;
    for(columnas=10,filas=29;filas<=33;filas++)
        tab2[filas][columnas]=M;
    for(columnas=12,filas=31;filas<=33;filas++)
        tab2[filas][columnas]=M;
    for(columnas=13,filas=29;filas<=31;filas++)
        tab2[filas][columnas]=M;
    for(filas=27,columnas=4;columnas<=12;columnas++)
        tab2[filas][columnas]=M;
    for(columnas=4,filas=25;filas<=30;filas++)
        tab2[filas][columnas]=M;
    for(filas=30,columnas=1;columnas<=4;columnas++)
        tab2[filas][columnas]=M;
    for(filas=32,columnas=2;columnas<=6;columnas++)
        tab2[filas][columnas]=M;
    for(columnas=6,filas=29;filas<=35;filas++)
        tab2[filas][columnas]=M;
    for(filas=29,columnas=7;columnas<=8;columnas++)
        tab2[filas][columnas]=M;
    for(filas=31,columnas=7;columnas<=8;columnas++)
        tab2[filas][columnas]=M;
    for(filas=28,columnas=1;columnas<=2;columnas++)
        tab2[filas][columnas]=M;
    for(filas=23,columnas=1;columnas<=2;columnas++)
        tab2[filas][columnas]=M;
    for(filas=25,columnas=2;filas<=26;filas++)
        tab2[filas][columnas]=M;
    for(filas=19,columnas=6;filas<=25;filas++)
        tab2[filas][columnas]=M;
    for(filas=19,columnas=4;filas<=23;filas++)
        tab2[filas][columnas]=M;
    for(filas=21,columnas=1;columnas<=3;columnas++)
        tab2[filas][columnas]=M;
    for(filas=23,columnas=7;columnas<=8;columnas++)
        tab2[filas][columnas]=M;
    for(filas=21,columnas=10;filas<=23;filas++)
        tab2[filas][columnas]=M;
    for(filas=25,columnas=9;columnas<=13;columnas++)
        tab2[filas][columnas]=M;
    for(filas=21,columnas=8;columnas<=13;columnas++)
        tab2[filas][columnas]=M;
    for(filas=19,columnas=10;columnas<=12;columnas++)
        tab2[filas][columnas]=M;
    for(filas=17,columnas=10;filas<=18;filas++)
        tab2[filas][columnas]=M;
    for(filas=17,columnas=12;filas<=18;filas++)
        tab2[filas][columnas]=M;
    for(filas=15,columnas=10;columnas<=13;columnas++)
        tab2[filas][columnas]=M;
    for(filas=19,columnas=6;columnas<=8;columnas++)
        tab2[filas][columnas]=M;
    for(filas=15,columnas=8;filas<=19;filas++)
        tab2[filas][columnas]=M;
    for(filas=15,columnas=6;columnas<=8;columnas++)
        tab2[filas][columnas]=M;
    for(filas=17,columnas=2;filas<=19;filas++)
        tab2[filas][columnas]=M;
    for(filas=17,columnas=2;columnas<=6;columnas++)
        tab2[filas][columnas]=M;
    for(filas=15,columnas=1;columnas<=2;columnas++)
        tab2[filas][columnas]=M;
    for(filas=13,columnas=1;columnas<=2;columnas++)
        tab2[filas][columnas]=M;
    for(filas=13,columnas=4;filas<=17;filas++)
        tab2[filas][columnas]=M;
    for(filas=13,columnas=7;columnas<=8;columnas++)
        tab2[filas][columnas]=M;
    for(filas=13,columnas=10;columnas<=11;columnas++)
        tab2[filas][columnas]=M;
}
void imprimir_tablero (char tablero[IF][JF],struct jugador nom,int punt,int i,int j)   /**IMPRIMIR**/
{
    int res,fil,col;
    system("cls");
    printf("\n\n\n\n\n\n");
    for(fil=i-3;fil<=i+3;fil++)
    {
        printf("\t\t\t");
        for(col=j-3;col<=j+3;col++)
        {
            if(col>9||fil>9)
                printf("  ");
            else if(col<0||fil<0)
                printf("  ");
            else
            {
                printf("%2c",tablero[fil][col]);
            }
        }
        printf("\n");
    }
    res=100-punt;
    printf("\n\n\t\tNOMBRE: %s",nom.nombre);
    printf("\n\n\t\tPUNTOS: %d",punt);
    printf("\n\n\t\tPUNTOS RESTANTES; %d",res);
    printf("\n\n\t\tPULSE * PARA SALIR");
}
void imprimir_tablero_medio (char tablero[IM][JM],struct jugador nom,int punt,int i,int j)   /**IMPRIMIR**/
{
    int res,fil,col;
    system("cls");
    printf("\n\n\n\n\n\n");
    for(fil=i-2;fil<=i+2;fil++)
    {
        printf("\t\t\t");
        for(col=j-2;col<=j+2;col++)
        {
            if(col>14||fil>39)
                printf("  ");
            else if(col<0||fil<0)
                printf("  ");
            else
            {
                printf("%2c",tablero[fil][col]);
            }
        }
        printf("\n");
    }
    res=500-punt;
    printf("\n\n\t\tNOMBRE: %s",nom.nombre);
    printf("\n\n\t\tPUNTOS: %d",punt);
    printf("\n\n\t\tPUNTOS RESTANTES; %d",res);
}
void mover_arriba (char tab[IF][JF],struct jugador nom,int*punt,int*i,int*j)
{
    int temp;
    system("cls");
    if(tab[*i-1][*j]==64)
    {
        *punt=*punt+5;
        tab[*i][*j]=W;   /** (^) **/
    }
    else if(tab[*i-1][*j]==42)
    {
        *punt=*punt+3;
        tab[*i][*j]=W;   /** (^) **/
    }
    else if(tab[*i-1][*j]==32)
    {
        *punt=*punt+1;
        tab[*i][*j]=E;   /** (ESPACIO) **/
        *i=*i-1;
        tab[*i][*j]=W;   /** (^) **/
    }
    imprimir_tablero (tab,nom,*punt,*i,*j);
}
void mover_arriba_medio (char tab[IM][JM],struct jugador nom,int*punt,int*i,int*j)
{
    int temp;
    system("cls");
    if(tab[*i-1][*j]==64)
    {
        *punt=*punt+5;
        tab[*i][*j]=W;   /** (^) **/
    }
    else if(tab[*i-1][*j]==42)
    {
        *punt=*punt+3;
        tab[*i][*j]=W;   /** (^) **/
    }
    else if(tab[*i-1][*j]==32)
    {
        *punt=*punt+1;
        tab[*i][*j]=E;   /** (ESPACIO) **/
        *i=*i-1;
        tab[*i][*j]=W;   /** (^) **/
    }
    else if(tab[*i-1][*j]==70)
    {
        *i=*i-1;
        tab[*i][*j]=W;   /** (^) **/
    }
    imprimir_tablero_medio (tab,nom,*punt,*i,*j);
}
void mover_abajo (char tab[IF][JF],struct jugador nom,int*punt,int*i,int*j)
{
    int temp;
    system("cls");
    if(tab[*i+1][*j]==64)
    {
        *punt=*punt+5;
        tab[*i][*j]=S;   /** (v) **/
    }
    else if(tab[*i+1][*j]==42)
    {
        *punt=*punt+3;
        tab[*i][*j]=S;   /** (v) **/
    }
    else if(tab[*i+1][*j]==32)
    {
        *punt=*punt+1;
        tab[*i][*j]=32;   /** (ESPACIO) **/
        *i=*i+1;
        tab[*i][*j]=S;   /** (v) **/
    }
    else if(tab[*i+1][*j]==70)
    {
        *i=*i+1;
        tab[*i][*j]=S;   /** (v) **/
    }
    imprimir_tablero (tab,nom,*punt,*i,*j);
}
void mover_abajo_medio (char tab[IM][JM],struct jugador nom,int*punt,int*i,int*j)
{
    int temp;
    system("cls");
    if(tab[*i+1][*j]==64)
    {
        *punt=*punt+5;
        tab[*i][*j]=S;   /** (v) **/
    }
    else if(tab[*i+1][*j]==42)
    {
        *punt=*punt+3;
        tab[*i][*j]=S;   /** (v) **/
    }
    else if(tab[*i+1][*j]==32)
    {
        *punt=*punt+1;
        tab[*i][*j]=E;   /** (ESPACIO) **/
        *i=*i+1;
        tab[*i][*j]=S;   /** (v) **/
    }
    else if(tab[*i+1][*j]==70)
    {
        *i=*i+1;
        tab[*i][*j]=S;   /** (v) **/
    }
    imprimir_tablero_medio (tab,nom,*punt,*i,*j);
}
void mover_derecha (char tab[IF][JF],struct jugador nom,int*punt,int*i,int*j)
{
    int temp;
    system("cls");
    if(tab[*i][*j+1]==64)
    {
        *punt=*punt+5;
        tab[*i][*j]=62;   /** (>) **/
    }
    else if(tab[*i][*j+1]==42)
    {
        *punt=*punt+3;
        tab[*i][*j]=62;   /** (>) **/
    }
    else if(tab[*i][*j+1]==32)
    {
        *punt=*punt+1;
        tab[*i][*j]=32;   /** (ESPACIO) **/
        *j=*j+1;
        tab[*i][*j]=62;   /** (>) **/
    }
    imprimir_tablero (tab,nom,*punt,*i,*j);
}
void mover_derecha_medio (char tab[IM][JM],struct jugador nom,int*punt,int*i,int*j)
{
    int temp;
    system("cls");
    if(tab[*i][*j+1]==64)
    {
        *punt=*punt+5;
        tab[*i][*j]=62;   /** (>) **/
    }
    else if(tab[*i][*j+1]==42)
    {
        *punt=*punt+3;
        tab[*i][*j]=62;   /** (>) **/
    }
    else if(tab[*i][*j+1]==32)
    {
        *punt=*punt+1;
        tab[*i][*j]=32;   /** (ESPACIO) **/
        *j=*j+1;
        tab[*i][*j]=62;   /** (>) **/
    }
    imprimir_tablero_medio (tab,nom,*punt,*i,*j);
}
void mover_izquierda (char tab[IF][JF],struct jugador nom,int*punt,int*i,int*j)
{
    int temp;
    system("cls");
        if(tab[*i][*j-1]==64)
    {
        *punt=*punt+5;
        tab[*i][*j]=60;   /** (>) **/
    }
    else if(tab[*i][*j-1]==42)
    {
        *punt=*punt+3;
        tab[*i][*j]=60;   /** (>) **/
    }
    else if(tab[*i][*j-1]==32)
    {
        *punt=*punt+1;
        tab[*i][*j]=32;   /** (ESPACIO) **/
        *j=*j-1;
        tab[*i][*j]=60;   /** (>) **/
    }
    imprimir_tablero (tab,nom,*punt,*i,*j);
}
void mover_izquierda_medio (char tab[IM][JM],struct jugador nom,int*punt,int*i,int*j)
{
    int temp;
    system("cls");
        if(tab[*i][*j-1]==64)
    {
        *punt=*punt+5;
        tab[*i][*j]=60;   /** (>) **/
    }
    else if(tab[*i][*j-1]==42)
    {
        *punt=*punt+3;
        tab[*i][*j]=60;   /** (>) **/
    }
    else if(tab[*i][*j-1]==32)
    {
        *punt=*punt+1;
        tab[*i][*j]=32;   /** (ESPACIO) **/
        *j=*j-1;
        tab[*i][*j]=60;   /** (>) **/
    }
    imprimir_tablero_medio (tab,nom,*punt,*i,*j);
}
void despedida (void)
{
    system("cls");
    printf("\n\n\n\n\n\n\tGRACIAS POR JUGAR CRAZY MACEL... CUANDO QUIERAS VUELVE A INTENTALO\n\n\n\n\n");
}
