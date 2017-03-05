

/*********************+
*     LIBRERIAS       *
+*********************/

# include <time.h>   /**   TIEMPO   **/
# include <conio.h>  /**   TECLADO  **/
# include <stdio.h>  /**   BASICA   **/
# include <stdlib.h> /**   LIMPIAR  **/

/*********************+
*     CONSTANTES      *
+*********************/

# define JF 10   /**  Columnas Facil    **/
# define IF 10   /**  Filas Facil       **/
# define JM 15   /**  Columnas Mediano  **/
# define IM 40   /**  Filas Mediano     **/
# define JD 40   /**  Columnas Dificil  **/
# define ID 60   /**  Filas Dificil     **/
# define W 94    /**  Arriba            **/
# define P 64    /**  Paredes           **/
# define M 42    /**  Muros             **/
# define S 118   /**  Abajo             **/
# define A 60    /**  Derecha           **/
# define D 62    /**  Izquierda         **/
# define E 32    /**  Espacio Vacio     **/
# define NOM 50  /**  Nombre            **/

/*********************+
*     ESTRUCTURAS     *
+*********************/

struct jugador      /** DATOS DEL JUGADOR **/
{
    char nombre[NOM];
    int puntaje;
    int fecha;
    int duracion;
};

typedef struct jugador jug ;        /*- TIPO DE VARIABLE "jug" -*/

struct puntaje      /** PUNTAJES DEL JUEGO **/
{
    int total;
    int nivel;
    int res;
};

typedef struct puntaje punt;        /*- TIPO DE VARIABLE "punt" -*/

struct pasos        /** PASOS EN EL JUEGO **/
{
    int derecha;
    int izquierda;
    int arriba;
    int abajo;
    int muro;
    int limite;
};

typedef struct pasos pas;        /*- TIPO DE VARIABLE "pas" -*/

/*********************+
*     PROTOTIPOS      *
+*********************/

void abajo_d (char [ID][JD],jug,punt*,pas*,int*,int*,char);
void abajo_f (char [IF][JF],jug,punt*,pas*,int*,int*,char);
void abajo_m (char [IM][JM],jug,punt*,pas*,int*,int*,char);
void arriba_d (char [ID][JD],jug,punt*,pas*,int*,int*,char);
void arriba_f (char [IF][JF],jug,punt*,pas*,int*,int*,char);
void arriba_m (char [IM][JM],jug,punt*,pas*,int*,int*,char);
void ayuda (void);
void cargar1 (char [IF][JF]);
void cargar2 (char [IF][JF]);
void cargar3 (char [IF][JF]);
void cargar4 (char [IM][JM]);
void cargar5 (char [IM][JM]);
void cargar6 (char [IM][JM]);
void cargar7 (char [ID][JD]);
void cargar8 (char [ID][JD]);
void cargar9 (char [ID][JD]);
void derecha_d (char [ID][JD],jug,punt*,pas*,int*,int*,char);
void derecha_f (char [IF][JF],jug,punt*,pas*,int*,int*,char);
void derecha_m (char [IM][JM],jug,punt*,pas*,int*,int*,char);
void despedida (void);
void imprimir_d (char [IF][JF],jug,punt,pas,int,int);
void imprimir_dd (char [ID][JD],jug,punt,pas,int,int);
void imprimir_df (char [ID][JD],jug,punt,pas,int,int);
void imprimir_dm (char [ID][JD],jug,punt,pas,int,int);
void imprimir_f (char [IF][JF],jug,punt,pas,int,int);
void imprimir_m (char [IF][JF],jug,punt,pas,int,int);
void imprimir_md (char [IM][JM],jug,punt,pas,int,int);
void imprimir_mf (char [IM][JM],jug,punt,pas,int,int);
void imprimir_mm (char [IM][JM],jug,punt,pas,int,int);
void iniciar_v (jug*,punt*,pas*);
void izquierda_d (char [ID][JD],jug,punt*,pas*,int*,int*,char);
void izquierda_f (char [IF][JF],jug,punt*,pas*,int*,int*,char);
void izquierda_m (char [IM][JM],jug,punt*,pas*,int*,int*,char);
char menu (void);
char nivel (jug);
char tama_o (jug);

/*****************************+
*     PROGRAMA PRONCOPAL      *
+*****************************/

main ()

{
    int i,j;
    char opc,tam,niv,tab_f[IF][JF],mov,tab_m[IM][JM],tab_d[ID][JD];
    pas pasos;
    jug jugador;
    punt puntos;
    do
    {
        opc=menu();
        switch(opc)
        {
            case'1':    /** JUGAR **/

                iniciar_v(&jugador,&puntos,&pasos);
                printf("\n\n\n\n\n\t\t\tPOR FAVOR DIGITE SU NOMBRE: \n\n\t\t\t");
                gets(jugador.nombre);
                do
                {
                    tam=tama_o(jugador);
                    switch(tam)
                    {
                        case'1':        /** TAMAÑO FACIL **/

                        do
                        {
                            niv=nivel(jugador);
                            switch(niv)
                            {
                                case'1':        /** NIVEL FACIL **/

                                cargar1(tab_f);
                                i=1,j=1;
                                imprimir_f (tab_f,jugador,puntos,pasos,i,j);
                                do
                                {
                                    mov=getch();
                                    if(mov=='w'||mov=='W')
                                    {
                                        arriba_f(tab_f,jugador,&puntos,&pasos,&i,&j,niv);
                                    }
                                    else if(mov=='s'||mov=='S')
                                    {
                                        abajo_f(tab_f,jugador,&puntos,&pasos,&i,&j,niv);
                                    }
                                    else if(mov=='d'||mov=='D')
                                    {
                                        derecha_f(tab_f,jugador,&puntos,&pasos,&i,&j,niv);
                                    }
                                    else if(mov=='a'||mov=='A')
                                    {
                                        izquierda_f(tab_f,jugador,&puntos,&pasos,&i,&j,niv);
                                    }
                                }while(tab_f[8][1]==70&&mov!=42);

                                break;

                                case'2':        /** NIVEL MEDIO **/

                                cargar2(tab_f);
                                i=8,j=1;
                                imprimir_m (tab_f,jugador,puntos,pasos,i,j);
                                do
                                {
                                    mov=getch();
                                    if(mov=='w'||mov=='W')
                                    {
                                        arriba_f(tab_f,jugador,&puntos,&pasos,&i,&j,niv);
                                    }
                                    else if(mov=='s'||mov=='S')
                                    {
                                        abajo_f(tab_f,jugador,&puntos,&pasos,&i,&j,niv);
                                    }
                                    else if(mov=='d'||mov=='D')
                                    {
                                        derecha_f(tab_f,jugador,&puntos,&pasos,&i,&j,niv);
                                    }
                                    else if(mov=='a'||mov=='A')
                                    {
                                        izquierda_f(tab_f,jugador,&puntos,&pasos,&i,&j,niv);
                                    }
                                }while(tab_f[1][1]==70&&mov!=42);

                                break;

                                case'3':        /** NIVEL DIFICIL **/

                                cargar3(tab_f);
                                i=3,j=8;
                                imprimir_d (tab_f,jugador,puntos,pasos,i,j);
                                do
                                {
                                    mov=getch();
                                    if(mov=='w'||mov=='W')
                                    {
                                        arriba_f(tab_f,jugador,&puntos,&pasos,&i,&j,niv);
                                    }
                                    else if(mov=='s'||mov=='S')
                                    {
                                        abajo_f(tab_f,jugador,&puntos,&pasos,&i,&j,niv);
                                    }
                                    else if(mov=='d'||mov=='D')
                                    {
                                        derecha_f(tab_f,jugador,&puntos,&pasos,&i,&j,niv);
                                    }
                                    else if(mov=='a'||mov=='A')
                                    {
                                        izquierda_f(tab_f,jugador,&puntos,&pasos,&i,&j,niv);
                                    }
                                }while(tab_f[8][2]==70&&mov!=42);

                                break;
                            }
                        }while(niv!='4');

                        break;

                        case '2':       /** TAMAÑO MEDIO **/

                        do
                        {
                            niv=nivel(jugador);
                            switch(niv)
                            {
                                case'1':        /** NIVEL FACIL **/

                                cargar4(tab_m);
                                i=18,j=1;
                                imprimir_mf (tab_m,jugador,puntos,pasos,i,j);
                                do
                                {
                                    mov=getch();
                                    if(mov=='w'||mov=='W')
                                    {
                                        arriba_m(tab_m,jugador,&puntos,&pasos,&i,&j,niv);
                                    }
                                    else if(mov=='s'||mov=='S')
                                    {
                                        abajo_m(tab_m,jugador,&puntos,&pasos,&i,&j,niv);
                                    }
                                    else if(mov=='d'||mov=='D')
                                    {
                                        derecha_m(tab_m,jugador,&puntos,&pasos,&i,&j,niv);
                                    }
                                    else if(mov=='a'||mov=='A')
                                    {
                                        izquierda_m(tab_m,jugador,&puntos,&pasos,&i,&j,niv);
                                    }
                                }while(tab_m[1][1]==70&&mov!=42);

                                break;

                                case'2':        /** NIVEL MEDIO **/

                                cargar5(tab_m);
                                i=38,j=7;
                                imprimir_mm (tab_m,jugador,puntos,pasos,i,j);
                                do
                                {
                                    mov=getch();
                                    if(mov=='w'||mov=='W')
                                    {
                                        arriba_m(tab_m,jugador,&puntos,&pasos,&i,&j,niv);
                                    }
                                    else if(mov=='s'||mov=='S')
                                    {
                                        abajo_m(tab_m,jugador,&puntos,&pasos,&i,&j,niv);
                                    }
                                    else if(mov=='d'||mov=='D')
                                    {
                                        derecha_m(tab_m,jugador,&puntos,&pasos,&i,&j,niv);
                                    }
                                    else if(mov=='a'||mov=='A')
                                    {
                                        izquierda_m(tab_m,jugador,&puntos,&pasos,&i,&j,niv);
                                    }
                                }while(tab_m[15][7]==70&&mov!=42);

                                break;

                                case'3':        /** NIVEL DIFICIL **/

                                cargar6(tab_m);
                                i=19,j=7;
                                imprimir_md (tab_m,jugador,puntos,pasos,i,j);
                                do
                                {
                                    mov=getch();
                                    if(mov=='w'||mov=='W')
                                    {
                                        arriba_m(tab_m,jugador,&puntos,&pasos,&i,&j,niv);
                                    }
                                    else if(mov=='s'||mov=='S')
                                    {
                                        abajo_m(tab_m,jugador,&puntos,&pasos,&i,&j,niv);
                                    }
                                    else if(mov=='d'||mov=='D')
                                    {
                                        derecha_m(tab_m,jugador,&puntos,&pasos,&i,&j,niv);
                                    }
                                    else if(mov=='a'||mov=='A')
                                    {
                                        izquierda_m(tab_m,jugador,&puntos,&pasos,&i,&j,niv);
                                    }
                                }while(tab_m[1][13]==70&&mov!=42);

                                break;

                            }
                        }while(tam!='4'&&niv!='4');

                        break;

                        case'3':        /** TAMAÑO DIFICIL **/

                        do
                        {
                        niv=nivel(jugador);
                            switch(niv)
                            {
                                case'1':        /** NIVEL FACIL **/

                                cargar7(tab_d);
                                i=1,j=1;
                                imprimir_df (tab_d,jugador,puntos,pasos,i,j);
                                do
                                {
                                    mov=getch();
                                    if(mov=='w'||mov=='W')
                                    {
                                        arriba_d(tab_d,jugador,&puntos,&pasos,&i,&j,niv);
                                    }
                                    else if(mov=='s'||mov=='S')
                                    {
                                        abajo_d(tab_d,jugador,&puntos,&pasos,&i,&j,niv);
                                    }
                                    else if(mov=='d'||mov=='D')
                                    {
                                        derecha_d(tab_d,jugador,&puntos,&pasos,&i,&j,niv);
                                    }
                                    else if(mov=='a'||mov=='A')
                                    {
                                        izquierda_d(tab_d,jugador,&puntos,&pasos,&i,&j,niv);
                                    }
                                }while(mov!=42);

                                break;
                            }
                        }while(tam!='4'&&niv!='4');

                        break;

                    }
                }while(tam!='4'&&niv!='4');

            break;
            case'2':

            break;
            case'3':

            break;
            case'4':        /** AYUDA **/
                ayuda();
            break;
            case'5':        /** SALIR **/
                despedida();
            break;
        }

    }while(opc!='5');

}

/*************************+
*     SUBPROGRAMAS        *
+*************************/

void abajo_d (char tab[ID][JD],jug nom,punt*punto,pas*pasos,int*i,int*j,char niv)
{
    system("cls");
    if(tab[*i+1][*j]==64)
    {
        punto->total=punto->total+5;
        tab[*i][*j]=S;   /** (v) **/
        pasos->limite=pasos->limite+1;
    }
    else if(tab[*i+1][*j]==42)
    {
        punto->total=punto->total+3;
        tab[*i][*j]=S;   /** (v) **/
        pasos->muro=pasos->muro+1;
    }
    else if(tab[*i+1][*j]==32)
    {
        punto->total=punto->total+1;
        tab[*i][*j]=32;   /** (ESPACIO) **/
        *i=*i+1;
        tab[*i][*j]=S;   /** (v) **/
    }
    else if(tab[*i+1][*j]==70)
    {
        *i=*i+1;
        tab[*i][*j]=S;   /** (v) **/
    }
    pasos->abajo=pasos->abajo+1;
    if(niv=='1')
        imprimir_df (tab,nom,*punto,*pasos,*i,*j);
    else if(niv=='2')
        imprimir_dm (tab,nom,*punto,*pasos,*i,*j);
    else if(niv=='3')
        imprimir_dd (tab,nom,*punto,*pasos,*i,*j);
}
void abajo_f (char tab[IF][JF],jug nom,punt*punto,pas*pasos,int*i,int*j,char niv)
{
    system("cls");
    if(tab[*i+1][*j]==64)
    {
        punto->total=punto->total+5;
        tab[*i][*j]=S;   /** (v) **/
        pasos->limite=pasos->limite+1;
    }
    else if(tab[*i+1][*j]==42)
    {
        punto->total=punto->total+3;
        tab[*i][*j]=S;   /** (v) **/
        pasos->muro=pasos->muro+1;
    }
    else if(tab[*i+1][*j]==32)
    {
        punto->total=punto->total+1;
        tab[*i][*j]=32;   /** (ESPACIO) **/
        *i=*i+1;
        tab[*i][*j]=S;   /** (v) **/
    }
    else if(tab[*i+1][*j]==70)
    {
        *i=*i+1;
        tab[*i][*j]=S;   /** (v) **/
    }
    pasos->abajo=pasos->abajo+1;
    if(niv=='1')
        imprimir_f (tab,nom,*punto,*pasos,*i,*j);
    else if(niv=='2')
        imprimir_m (tab,nom,*punto,*pasos,*i,*j);
    else if(niv=='3')
        imprimir_d (tab,nom,*punto,*pasos,*i,*j);
}
void abajo_m (char tab[IM][JM],jug nom,punt*punto,pas*pasos,int*i,int*j,char niv)
{
    system("cls");
    if(tab[*i+1][*j]==64)
    {
        punto->total=punto->total+5;
        tab[*i][*j]=S;   /** (v) **/
        pasos->limite=pasos->limite+1;
    }
    else if(tab[*i+1][*j]==42)
    {
        punto->total=punto->total+3;
        tab[*i][*j]=S;   /** (v) **/
        pasos->muro=pasos->muro+1;
    }
    else if(tab[*i+1][*j]==32)
    {
        punto->total=punto->total+1;
        tab[*i][*j]=32;   /** (ESPACIO) **/
        *i=*i+1;
        tab[*i][*j]=S;   /** (v) **/
    }
    else if(tab[*i+1][*j]==70)
    {
        *i=*i+1;
        tab[*i][*j]=S;   /** (v) **/
    }
    pasos->abajo=pasos->abajo+1;
    if(niv=='1')
        imprimir_mf (tab,nom,*punto,*pasos,*i,*j);
    else if(niv=='2')
        imprimir_mm (tab,nom,*punto,*pasos,*i,*j);
    else if(niv=='3')
        imprimir_md (tab,nom,*punto,*pasos,*i,*j);
}
void arriba_d (char tab[ID][JD],jug nom,punt*punto,pas*pasos,int*i,int*j,char niv)
{
    system("cls");
    if(tab[*i-1][*j]==64)
    {
        punto->total=punto->total+5;
        tab[*i][*j]=W;   /** (^) **/
        pasos->limite=pasos->limite+1;
    }
    else if(tab[*i-1][*j]==42)
    {
        punto->total=punto->total+3;
        tab[*i][*j]=W;   /** (^) **/
    }
    else if(tab[*i-1][*j]==32)
    {
        punto->total=punto->total+1;
        tab[*i][*j]=E;   /** (ESPACIO) **/
        *i=*i-1;
        tab[*i][*j]=W;   /** (^) **/
    }
    else if(tab[*i-1][*j]==70)
    {
        punto->total=punto->total+1;
        tab[*i][*j]=E;   /** (ESPACIO) **/
        *i=*i-1;
        tab[*i][*j]=W;   /** (^) **/
    }
    pasos->arriba=pasos->arriba+1;
    if(niv=='1')
        imprimir_df (tab,nom,*punto,*pasos,*i,*j);
    else if(niv=='2')
        imprimir_dm (tab,nom,*punto,*pasos,*i,*j);
    else if(niv=='3')
        imprimir_dd (tab,nom,*punto,*pasos,*i,*j);
}
void arriba_f (char tab[IF][JF],jug nom,punt*punto,pas*pasos,int*i,int*j,char niv)
{
    system("cls");
    if(tab[*i-1][*j]==64)
    {
        punto->total=punto->total+5;
        tab[*i][*j]=W;   /** (^) **/
        pasos->limite=pasos->limite+1;
    }
    else if(tab[*i-1][*j]==42)
    {
        punto->total=punto->total+3;
        tab[*i][*j]=W;   /** (^) **/
    }
    else if(tab[*i-1][*j]==32)
    {
        punto->total=punto->total+1;
        tab[*i][*j]=E;   /** (ESPACIO) **/
        *i=*i-1;
        tab[*i][*j]=W;   /** (^) **/
    }
    else if(tab[*i-1][*j]==70)
    {
        punto->total=punto->total+1;
        tab[*i][*j]=E;   /** (ESPACIO) **/
        *i=*i-1;
        tab[*i][*j]=W;   /** (^) **/
    }
    pasos->arriba=pasos->arriba+1;
    if(niv=='1')
        imprimir_f (tab,nom,*punto,*pasos,*i,*j);
    else if(niv=='2')
        imprimir_m (tab,nom,*punto,*pasos,*i,*j);
    else if(niv=='3')
        imprimir_d (tab,nom,*punto,*pasos,*i,*j);
}
void arriba_m (char tab[IM][JM],jug nom,punt*punto,pas*pasos,int*i,int*j,char niv)
{
    system("cls");
    if(tab[*i-1][*j]==64)
    {
        punto->total=punto->total+5;
        tab[*i][*j]=W;   /** (^) **/
        pasos->limite=pasos->limite+1;
    }
    else if(tab[*i-1][*j]==42)
    {
        punto->total=punto->total+3;
        tab[*i][*j]=W;   /** (^) **/
    }
    else if(tab[*i-1][*j]==32)
    {
        punto->total=punto->total+1;
        tab[*i][*j]=E;   /** (ESPACIO) **/
        *i=*i-1;
        tab[*i][*j]=W;   /** (^) **/
    }
    else if(tab[*i-1][*j]==70)
    {
        punto->total=punto->total+1;
        tab[*i][*j]=E;   /** (ESPACIO) **/
        *i=*i-1;
        tab[*i][*j]=W;   /** (^) **/
    }
    pasos->arriba=pasos->arriba+1;
    if(niv=='1')
        imprimir_mf (tab,nom,*punto,*pasos,*i,*j);
    else if(niv=='2')
        imprimir_mm (tab,nom,*punto,*pasos,*i,*j);
    else if(niv=='3')
        imprimir_md (tab,nom,*punto,*pasos,*i,*j);
}
void ayuda (void)
{
    system("cls");
    printf("\n\n\n\t\t\tBIENVENIDO A CRAZY MACEL....\n\n\nESTE JUEGO CONSISTE EN MOVER EL MACEL POR MEDIO DEL LAVERINTO CON EL FIN DE\nLLEGAR A LA META LA CUAL ES LA 'F'.\nCUANDO EL MACEL HALLA LLEGADO A LA 'F' EL TABLERO HABRA FINALIZADO Y PASARA AL  SIGUIENTE NIVEL.\n\nCADA DESPLAZAMIENTO DEL MACEL PRODUCE UN PUNTO, AL CHOCARCE CON UNA PARED\nAUMENTARA 5 PUNTOS Y AL CHOCARCE CON UN MURO AUENTARA 3 PUNTOS.\n\nEL OBJETIVO ES PASAR EL LABERINTO CON EL MENOR NUMERO DE PUNTOS POSIBLES.\n\n\nUD TIENE TRS OPCIONES DE SALIDA:\n\n1.JUEGO COMPLETO\n2.JUEGO ABANDONADO\n3.JUEGO INCOMPLETO\n\nJUEGO IMPLETO: ES CUANDO EL JUGADOR EXCEDE EL NUMERO DE PUNTOS PERMITIDOS EN EL TABLERO.\n\n\nPARA PODER MOVER AL MACEL TIENE LAS SIGUIENTES OPCIONES:\n\nW=DESPLAZARCE HACIA ARRIBA\nS=DESPLAZARCE HACIA ABAJO\nA=DESPLAZARCE A LA IZQUIERDA\nD=DESPLAZARCE A LA DERECHA\n\n\n\n\t\t\tMUCHA SUERTE.....\n\n\n");
    getch();
    system("cls");
}
void cargar1 (char tablero[IF][JF])
{
    FILE *tab;
    int fil,col;
    tab=fopen("facil1.txt","r");
    if(tab!=NULL)
    {
        for(fil=0;fil<IF;fil++)
        {
            for(col=0;col<JF;col++)
            {
                tablero[fil][col]=fgetc(tab);
            }
            fgetc(tab);
        }
        fgetc(tab);
    }
    fclose(tab);
}
void cargar2 (char tablero[IF][JF])
{
    FILE *tab;
    int fil,col;
    tab=fopen("facil2.txt","r");
    if(tab!=NULL)
    {
        for(fil=0;fil<IF;fil++)
        {
            for(col=0;col<JF;col++)
            {
                tablero[fil][col]=fgetc(tab);
            }
            fgetc(tab);
        }
        fgetc(tab);
    }
    fclose(tab);
}
void cargar3 (char tablero[IF][JF])
{
    FILE *tab;
    int fil,col;
    tab=fopen("facil3.txt","r");
    if(tab!=NULL)
    {
        for(fil=0;fil<IF;fil++)
        {
            for(col=0;col<JF;col++)
            {
                tablero[fil][col]=fgetc(tab);
            }
            fgetc(tab);
        }
        fgetc(tab);
    }
    fclose(tab);
}
void cargar4 (char tablero[IM][JM])
{
    FILE *tab;
    int fil,col;
    tab=fopen("medio1.txt","r");
    if(tab!=NULL)
    {
        for(fil=0;fil<IM;fil++)
        {
            for(col=0;col<JM;col++)
            {
                tablero[fil][col]=fgetc(tab);
            }
            fgetc(tab);
        }
        fgetc(tab);
    }
    fclose(tab);
}
void cargar5 (char tablero[IM][JM])
{
    FILE *tab;
    int fil,col;
    tab=fopen("medio2.txt","r");
    if(tab!=NULL)
    {
        for(fil=0;fil<IM;fil++)
        {
            for(col=0;col<JM;col++)
            {
                tablero[fil][col]=fgetc(tab);
            }
            fgetc(tab);
        }
        fgetc(tab);
    }
    fclose(tab);
}
void cargar6 (char tablero[IM][JM])
{
    FILE *tab;
    int fil,col;
    tab=fopen("medio3.txt","r");
    if(tab!=NULL)
    {
        for(fil=0;fil<IM;fil++)
        {
            for(col=0;col<JM;col++)
            {
                tablero[fil][col]=fgetc(tab);
            }
            fgetc(tab);
        }
        fgetc(tab);
    }
    fclose(tab);
}
void cargar7 (char tablero[ID][JD])
{
    FILE *tab;
    int fil,col;
    tab=fopen("dificil1.txt","r");
    if(tab!=NULL)
    {
        for(fil=0;fil<ID;fil++)
        {
            for(col=0;col<JD;col++)
            {
                tablero[fil][col]=fgetc(tab);
            }
            fgetc(tab);
        }
        fgetc(tab);
    }
    fclose(tab);
}
void cargar8 (char tablero[ID][JD])
{
    FILE *tab;
    int fil,col;
    tab=fopen("dificil2.txt","r");
    if(tab!=NULL)
    {
        for(fil=0;fil<ID;fil++)
        {
            for(col=0;col<JD;col++)
            {
                tablero[fil][col]=fgetc(tab);
            }
            fgetc(tab);
        }
        fgetc(tab);
    }
    fclose(tab);
}
void cargar9 (char tablero[ID][JD])
{
    FILE *tab;
    int fil,col;
    tab=fopen("dificil3.txt","r");
    if(tab!=NULL)
    {
        for(fil=0;fil<ID;fil++)
        {
            for(col=0;col<JD;col++)
            {
                tablero[fil][col]=fgetc(tab);
            }
            fgetc(tab);
        }
        fgetc(tab);
    }
    fclose(tab);
}
void derecha_d (char tab[ID][JD],jug nom,punt*punto,pas*pasos,int*i,int*j,char niv)
{
    system("cls");
    if(tab[*i][*j+1]==64)
    {
        punto->total=punto->total+5;
        tab[*i][*j]=62;   /** (>) **/
        pasos->limite=pasos->limite+1;
    }
    else if(tab[*i][*j+1]==42)
    {
        punto->total=punto->total+3;
        tab[*i][*j]=62;   /** (>) **/
        pasos->muro=pasos->muro+1;
    }
    else if(tab[*i][*j+1]==32)
    {
        punto->total=punto->total+1;
        tab[*i][*j]=32;   /** (ESPACIO) **/
        *j=*j+1;
        tab[*i][*j]=62;   /** (>) **/
    }
    else if(tab[*i][*j+1]==70)
    {
        punto->total=punto->total+1;
        tab[*i][*j]=32;   /** (ESPACIO) **/
        *j=*j+1;
        tab[*i][*j]=62;   /** (>) **/
    }
    pasos->derecha=pasos->derecha+1;
    if(niv=='1')
        imprimir_df (tab,nom,*punto,*pasos,*i,*j);
    else if(niv=='2')
        imprimir_dm (tab,nom,*punto,*pasos,*i,*j);
    else if(niv=='3')
        imprimir_dd (tab,nom,*punto,*pasos,*i,*j);
}
void derecha_f (char tab[IF][JF],jug nom,punt*punto,pas*pasos,int*i,int*j,char niv)
{
    system("cls");
    if(tab[*i][*j+1]==64)
    {
        punto->total=punto->total+5;
        tab[*i][*j]=62;   /** (>) **/
        pasos->limite=pasos->limite+1;
    }
    else if(tab[*i][*j+1]==42)
    {
        punto->total=punto->total+3;
        tab[*i][*j]=62;   /** (>) **/
        pasos->muro=pasos->muro+1;
    }
    else if(tab[*i][*j+1]==32)
    {
        punto->total=punto->total+1;
        tab[*i][*j]=32;   /** (ESPACIO) **/
        *j=*j+1;
        tab[*i][*j]=62;   /** (>) **/
    }
    else if(tab[*i][*j+1]==70)
    {
        punto->total=punto->total+1;
        tab[*i][*j]=32;   /** (ESPACIO) **/
        *j=*j+1;
        tab[*i][*j]=62;   /** (>) **/
    }
    pasos->derecha=pasos->derecha+1;
    if(niv=='1')
        imprimir_f (tab,nom,*punto,*pasos,*i,*j);
    else if(niv=='2')
        imprimir_m (tab,nom,*punto,*pasos,*i,*j);
    else if(niv=='3')
        imprimir_d (tab,nom,*punto,*pasos,*i,*j);
}
void derecha_m (char tab[IM][JM],jug nom,punt*punto,pas*pasos,int*i,int*j,char niv)
{
    system("cls");
    if(tab[*i][*j+1]==64)
    {
        punto->total=punto->total+5;
        tab[*i][*j]=62;   /** (>) **/
        pasos->limite=pasos->limite+1;
    }
    else if(tab[*i][*j+1]==42)
    {
        punto->total=punto->total+3;
        tab[*i][*j]=62;   /** (>) **/
        pasos->muro=pasos->muro+1;
    }
    else if(tab[*i][*j+1]==32)
    {
        punto->total=punto->total+1;
        tab[*i][*j]=32;   /** (ESPACIO) **/
        *j=*j+1;
        tab[*i][*j]=62;   /** (>) **/
    }
    else if(tab[*i][*j+1]==70)
    {
        punto->total=punto->total+1;
        tab[*i][*j]=32;   /** (ESPACIO) **/
        *j=*j+1;
        tab[*i][*j]=62;   /** (>) **/
    }
    pasos->derecha=pasos->derecha+1;
    if(niv=='1')
        imprimir_mf (tab,nom,*punto,*pasos,*i,*j);
    else if(niv=='2')
        imprimir_mm (tab,nom,*punto,*pasos,*i,*j);
    else if(niv=='3')
        imprimir_md (tab,nom,*punto,*pasos,*i,*j);
}
void despedida (void)
{
    system("cls");
    printf("\n\n\n\n\n\n\tGRACIAS POR JUGAR CRAZY MACEL... CUANDO QUIERAS VUELVE A INTENTALO\n\n\n\n\n");
    getch();
}
void imprimir_d (char tablero[IF][JF],jug nom,punt punto,pas pasos,int i,int j)    /**IMPRIMIR FACIL DIFICIL**/
{
    int fil,col;
    system("cls");
    printf("\n\n\n\n\n\n");
    for(fil=i-1;fil<=i+1;fil++)
    {
        printf("\t\t\t");
        for(col=j-1;col<=j+1;col++)
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
    printf("\n\n\t\tPULSE * PARA SALIR");
}
void imprimir_dd (char tablero[ID][JD],jug nom,punt punto,pas pasos,int i,int j)   /**IMPRIMIR DIFICI DIFIL**/
{
    int fil,col;
    system("cls");
    printf("\n\n\n\n\n\n");
    for(fil=i-1;fil<=i+1;fil++)
    {
        printf("\t\t\t");
        for(col=j-1;col<=j+1;col++)
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
    printf("\n\n\t\tPULSE * PARA SALIR");
}
void imprimir_df (char tablero[ID][JD],jug nom,punt punto,pas pasos,int i,int j)   /**IMPRIMIR DIFICIL FACIL**/
{
    int fil,col;
    system("cls");
    printf("\n\n\n\n\n\n");
    for(fil=i-3;fil<=i+3;fil++)
    {
        printf("\t\t\t");
        for(col=j-3;col<=j+3;col++)
        {
            if(col>JD-1||fil>ID-1)
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
    printf("\n\n\t\tPULSE * PARA SALIR");
}
void imprimir_dm (char tablero[ID][JD],jug nom,punt punto,pas pasos,int i,int j)   /**IMPRIMIR DIFICIL MEDIO**/
{
    int fil,col;
    system("cls");
    printf("\n\n\n\n\n\n");
    for(fil=i-2;fil<i+2;fil++)
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
    printf("\n\n\t\tPULSE * PARA SALIR");
}
void imprimir_f (char tablero[IF][JF],jug nom,punt punto,pas pasos,int i,int j)    /**IMPRIMIR FACIL FACIL**/
{
    int fil,col;
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
    punto.res=50-punto.total;
    printf("\n\n\t\tNOMBRE: %s",nom.nombre);
    printf("\n\n\t\tPUNTOS: %d",punto.nivel);
    printf("\n\n\t\tPUNTOS RESTANTES; %d",punto.res);
    printf("\n\n\t\tPASOS HACIA ARRIBA; %d",pasos.arriba);
    printf("\n\n\t\tPASOS HACIA ABAJO; %d",pasos.abajo);
    printf("\n\n\t\tPASOS HACIA DERECHA; %d",pasos.derecha);
    printf("\n\n\t\tPASOS HACIA IZQUIERDA; %d",pasos.izquierda);
    printf("\n\n\t\tPASOS CONTRA UN MURO; %d",pasos.muro);
    printf("\n\n\t\tPASOS CONTRA UN LIMITE; %d",pasos.limite);
    printf("\n\n\t\tPULSE * PARA SALIR");
}
void imprimir_m (char tablero[IF][JF],jug nom,punt punto,pas pasos,int i,int j)    /**IMPRIMIR FACIL MEDIO**/
{
    int fil,col;
    system("cls");
    printf("\n\n\n\n\n\n");
    for(fil=i-2;fil<=i+2;fil++)
    {
        printf("\t\t\t");
        for(col=j-2;col<=j+2;col++)
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
    printf("\n\n\t\tPULSE * PARA SALIR");
}
void imprimir_md (char tablero[IM][JM],jug nom,punt punto,pas pasos,int i,int j)   /**IMPRIMIR MEDIO DIFIL**/
{
    int fil,col;
    system("cls");
    printf("\n\n\n\n\n\n");
    for(fil=i-1;fil<=i+1;fil++)
    {
        printf("\t\t\t");
        for(col=j-1;col<=j+1;col++)
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
    printf("\n\n\t\tPULSE * PARA SALIR");
}
void imprimir_mf (char tablero[IM][JM],jug nom,punt punto,pas pasos,int i,int j)   /**IMPRIMIR MEDIO FACIL**/
{
    int fil,col;
    system("cls");
    printf("\n\n\n\n\n\n");
    for(fil=i-3;fil<i+3;fil++)
    {
        printf("\t\t\t");
        for(col=j-3;col<=j+3;col++)
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
    printf("\n\n\t\tPULSE * PARA SALIR");
}
void imprimir_mm (char tablero[IM][JM],jug nom,punt punto,pas pasos,int i,int j)   /**IMPRIMIR MEDIO MEDIO**/
{
    int fil,col;
    system("cls");
    printf("\n\n\n\n\n\n");
    for(fil=i-2;fil<i+2;fil++)
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
    printf("\n\n\t\tPULSE * PARA SALIR");
}
void iniciar_v (jug*jugador,punt*puntos,pas*pasos)
{
    jugador->puntaje=0;
    puntos->nivel=0;
    puntos->res=0;
    puntos->total=0;
    pasos->derecha=0;
    pasos->izquierda=0;
    pasos->arriba=0;
    pasos->abajo=0;
    pasos->muro=0;
    pasos->limite=0;
}
void izquierda_d (char tab[ID][JD],jug nom,punt*punto,pas*pasos,int*i,int*j,char niv)
{
    system("cls");
    if(tab[*i][*j-1]==64)
    {
        punto->total=punto->total+5;
        tab[*i][*j]=60;   /** (>) **/
        pasos->limite=pasos->limite+1;
    }
    else if(tab[*i][*j-1]==42)
    {
        punto->total=punto->total+3;
        tab[*i][*j]=60;   /** (>) **/
        pasos->muro=pasos->muro+1;
    }
    else if(tab[*i][*j-1]==32)
    {
        punto->total=punto->total+1;
        tab[*i][*j]=32;   /** (ESPACIO) **/
        *j=*j-1;
        tab[*i][*j]=60;   /** (>) **/
    }
    else if(tab[*i][*j-1]==70)
    {
        punto->total=punto->total+1;
        tab[*i][*j]=32;   /** (ESPACIO) **/
        *j=*j-1;
        tab[*i][*j]=60;   /** (>) **/
    }
    pasos->izquierda=pasos->izquierda+1;
    if(niv=='1')
        imprimir_df (tab,nom,*punto,*pasos,*i,*j);
    else if(niv=='2')
        imprimir_dm (tab,nom,*punto,*pasos,*i,*j);
    else if(niv=='3')
        imprimir_dd (tab,nom,*punto,*pasos,*i,*j);
}
void izquierda_f (char tab[IF][JF],jug nom,punt*punto,pas*pasos,int*i,int*j,char niv)
{
    system("cls");
    if(tab[*i][*j-1]==64)
    {
        punto->total=punto->total+5;
        tab[*i][*j]=60;   /** (>) **/
        pasos->limite=pasos->limite+1;
    }
    else if(tab[*i][*j-1]==42)
    {
        punto->total=punto->total+3;
        tab[*i][*j]=60;   /** (>) **/
        pasos->muro=pasos->muro+1;
    }
    else if(tab[*i][*j-1]==32)
    {
        punto->total=punto->total+1;
        tab[*i][*j]=32;   /** (ESPACIO) **/
        *j=*j-1;
        tab[*i][*j]=60;   /** (>) **/
    }
    else if(tab[*i][*j-1]==70)
    {
        punto->total=punto->total+1;
        tab[*i][*j]=32;   /** (ESPACIO) **/
        *j=*j-1;
        tab[*i][*j]=60;   /** (>) **/
    }
    pasos->izquierda=pasos->izquierda+1;
    if(niv=='1')
        imprimir_f (tab,nom,*punto,*pasos,*i,*j);
    else if(niv=='2')
        imprimir_m (tab,nom,*punto,*pasos,*i,*j);
    else if(niv=='3')
        imprimir_d (tab,nom,*punto,*pasos,*i,*j);
}
void izquierda_m (char tab[IM][JM],jug nom,punt*punto,pas*pasos,int*i,int*j,char niv)
{
    system("cls");
    if(tab[*i][*j-1]==64)
    {
        punto->total=punto->total+5;
        tab[*i][*j]=60;   /** (>) **/
        pasos->limite=pasos->limite+1;
    }
    else if(tab[*i][*j-1]==42)
    {
        punto->total=punto->total+3;
        tab[*i][*j]=60;   /** (>) **/
        pasos->muro=pasos->muro+1;
    }
    else if(tab[*i][*j-1]==32)
    {
        punto->total=punto->total+1;
        tab[*i][*j]=32;   /** (ESPACIO) **/
        *j=*j-1;
        tab[*i][*j]=60;   /** (>) **/
    }
    else if(tab[*i][*j-1]==70)
    {
        punto->total=punto->total+1;
        tab[*i][*j]=32;   /** (ESPACIO) **/
        *j=*j-1;
        tab[*i][*j]=60;   /** (>) **/
    }
    pasos->izquierda=pasos->izquierda+1;
    if(niv=='1')
        imprimir_mf (tab,nom,*punto,*pasos,*i,*j);
    else if(niv=='2')
        imprimir_mm (tab,nom,*punto,*pasos,*i,*j);
    else if(niv=='3')
        imprimir_md (tab,nom,*punto,*pasos,*i,*j);
}
char menu (void)
{
    char opc;
    system("cls");
    printf("\n\n\n\n\n\n\t\t\tESCOJA UNA OPCION\n\n\n\t\t\t1.EMPEZAR A JUGAR\n\n\n\t\t\t2.PARTIDAS GUARDADAS\n\n\n\t\t\t3.PUNTAJES ALTOS\n\n\n\t\t\t4.AYUDA\n\n\n\t\t\t5.SALIR\n");
    opc=getch();
    system("cls");
    return(opc);
}
char nivel (jug jugador)
{
    char opc;
    system("cls");
    printf("\n\n\n\n\n\n\t\t\t%s ESCOJA EL NIVEL DE JUEGO\n\n\n\t\t\t1.FACIL\n\n\n\t\t\t2.MEDIO\n\n\n\t\t\t3.DIFICIL\n\n\n\t\t\t4.VOLVER AL MENU\n\n\n\t\t\t",jugador.nombre);
    opc=getch();
    return(opc);
}
char tama_o (jug jugador)
{
    char opc;
    system("cls");
    printf("\n\n\n\n\n\n\t\t\t%s ESCOJA EL TAMAÑO DEL JUEGO\n\n\n\t\t\t1.FACIL\n\n\n\t\t\t2.MEDIO\n\n\n\t\t\t3.DIFICIL\n\n\n\t\t\t4.VOLVER AL MENU\n\n\n\t\t\t",jugador.nombre);
    opc=getch();
    return(opc);
    system("cls");
}
