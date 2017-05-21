/******************************************************************************
*                            Tarea 2                                  *
*******************************************************************************
* AUTOR(ES) : Henry                                 *
* FECHA     : 26/04/08                                                        *
* ASIGNATURA: PCEL - 5                                                        *
******************************************************************************/

/*********************+
*     LIBRERIAS       *
+*********************/

# include <time.h>   /**   TIEMPO       **/
# include <conio.h>  /**   TECLADO      **/
# include <stdio.h>  /**   BASICA       **/
# include <ctype.h>  /**   MAYUSCULAS   **/
# include <stdlib.h> /**   LIMPIAR      **/
# include <string.h> /**   CADENAS      **/

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
# define NUM 30  /**  Jugadores         **/

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

struct juego
{
    int num_jug;
    jug par[NUM];
};

typedef struct juego adm;

/*********************+
*     PROTOTIPOS      *
+*********************/

void abajo_d (char [ID][JD],jug,punt*,pas*,int*,int*,char,char,char*,char*);
void abajo_f (char [IF][JF],jug,punt*,pas*,int*,int*,char,char,char*,char*);
void abajo_m (char [IM][JM],jug,punt*,pas*,int*,int*,char,char,char*,char*);
void arriba_d (char [ID][JD],jug,punt*,pas*,int*,int*,char,char,char*,char*);
void arriba_f (char [IF][JF],jug,punt*,pas*,int*,int*,char,char,char*,char*);
void arriba_m (char [IM][JM],jug,punt*,pas*,int*,int*,char,char,char*,char*);
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
int cargar_juego (jug);
void derecha_d (char [ID][JD],jug,punt*,pas*,int*,int*,char,char,char*,char*);
void derecha_f (char [IF][JF],jug,punt*,pas*,int*,int*,char,char,char*,char*);
void derecha_m (char [IM][JM],jug,punt*,pas*,int*,int*,char,char,char*,char*);
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
void izquierda_d (char [ID][JD],jug,punt*,pas*,int*,int*,char,char,char*,char*);
void izquierda_f (char [IF][JF],jug,punt*,pas*,int*,int*,char,char,char*,char*);
void izquierda_m (char [IM][JM],jug,punt*,pas*,int*,int*,char,char,char*,char*);
char menu (void);
char nivel (jug);
void nombre (jug);
char rastro (jug);
char tama_o (jug);

/*****************************+
*     PROGRAMA PRONCOPAL      *
+*****************************/

main ()

{
    int i,j,pos_juga,juga,paso;
    char opc,tam,niv,tab_f[IF][JF],mov,tab_m[IM][JM],tab_d[ID][JD],ras,ant,pos;
    pas pasos;
    jug jugador;
    punt puntos;
    do
    {
        opc=menu();
        switch(opc)
        {
            case'1':    /** JUGAR **/

                puntos.total=0;
                printf("\n\n\n\n\n\t\t\tPOR FAVOR DIGITE SU NOMBRE: \n\n\t\t\t");
                gets(jugador.nombre);
                for(i = 0; i!=strlen(jugador.nombre); i++)
                {
                    jugador.nombre[i] = toupper(jugador.nombre[i]);
                }
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

                                    iniciar_v(&jugador,&puntos,&pasos);
                                    cargar1(tab_f);
                                    ant=0;
                                    i=1,j=1;        /**  POSICION INICIAL FF  **/
                                    ras=rastro(jugador);
                                    if (ras=='4')
                                        break;
                                    imprimir_f (tab_f,jugador,puntos,pasos,i,j);
                                    do
                                    {
                                        mov=getch();
                                        if(mov=='w'||mov=='W')
                                        {
                                            arriba_f(tab_f,jugador,&puntos,&pasos,&i,&j,niv,ras,&ant,&pos);
                                        }
                                        else if(mov=='s'||mov=='S')
                                        {
                                            abajo_f(tab_f,jugador,&puntos,&pasos,&i,&j,niv,ras,&ant,&pos);
                                        }
                                        else if(mov=='d'||mov=='D')
                                        {
                                            derecha_f(tab_f,jugador,&puntos,&pasos,&i,&j,niv,ras,&ant,&pos);
                                        }
                                        else if(mov=='a'||mov=='A')
                                        {
                                            izquierda_f(tab_f,jugador,&puntos,&pasos,&i,&j,niv,ras,&ant,&pos);
                                        }
                                    }while(tab_f[8][1]==70&&mov!=42&&puntos.nivel<IF*JF);

                                    if(tab_f[8][1]!=70)
                                    {
                                        system("cls");
                                        printf("\n\n\n\tFELICITACIONES.... NIVEL COMPLETO");
                                        paso=1;
                                        getch();
                                    }
                                    else if(puntos.nivel>IF*JF)
                                    {
                                        system("cls");
                                        printf("\n\n\n\n\n\n\t\tJUEGO INCOMPLETO....INTENTELO DE NUEVO\n\n\n\n\n");
                                        paso=0;
                                        getch();
                                    }
                                    else if(mov==42)
                                    {
                                        system("cls");
                                        printf("\n\n\n\n\n\n\t\tJUEGO INCOMPLETO....INTENTELO DE NUEVO\n\n\n\n\n");
                                        paso=0;
                                        getch();
                                    }
                                    if(paso==0)
                                        break;

                                case '2':        /** NIVEL MEDIO **/

                                    if(paso==1)
                                        niv=50;
                                    iniciar_v(&jugador,&puntos,&pasos);
                                    cargar2(tab_f);
                                    i=8,j=1;        /**  POSICION INICIAL FM  **/
                                    ras=rastro(jugador);
                                    if (ras=='4')
                                        break;
                                    ant=0;
                                    imprimir_m (tab_f,jugador,puntos,pasos,i,j);
                                    do
                                    {
                                        mov=getch();
                                        if(mov=='w'||mov=='W')
                                        {
                                            arriba_f(tab_f,jugador,&puntos,&pasos,&i,&j,niv,ras,&ant,&pos);
                                        }
                                        else if(mov=='s'||mov=='S')
                                        {
                                            abajo_f(tab_f,jugador,&puntos,&pasos,&i,&j,niv,ras,&ant,&pos);
                                        }
                                        else if(mov=='d'||mov=='D')
                                        {
                                            derecha_f(tab_f,jugador,&puntos,&pasos,&i,&j,niv,ras,&ant,&pos);
                                        }
                                        else if(mov=='a'||mov=='A')
                                        {
                                            izquierda_f(tab_f,jugador,&puntos,&pasos,&i,&j,niv,ras,&ant,&pos);
                                        }
                                    }while(tab_f[1][1]==70&&mov!=42&&puntos.nivel<IF*JF);
                                    if(tab_f[1][1]!=70)
                                    {
                                        system("cls");
                                        printf("\n\n\n\tFELICITACIONES.... NIVEL COMPLETO");
                                        paso=1;
                                        getch();
                                    }
                                    else if(puntos.nivel>IF*JF)
                                    {
                                        system("cls");
                                        printf("\n\n\n\n\n\n\t\tJUEGO INCOMPLETO....INTENTELO DE NUEVO\n\n\n\n\n");
                                        paso=0;
                                        getch();
                                    }
                                    else if(mov==42)
                                    {
                                        system("cls");
                                        printf("\n\n\n\n\n\n\t\tJUEGO INCOMPLETO....INTENTELO DE NUEVO\n\n\n\n\n");
                                        paso=0;
                                        getch();
                                    }
                                    if(paso==0)
                                        break;

                                case'3':        /** NIVEL DIFICIL **/

                                    if(paso==1)
                                        niv=51;
                                    iniciar_v(&jugador,&puntos,&pasos);
                                    cargar3(tab_f);
                                    i=3,j=8;        /**  POSICION INICIAL FD  **/
                                    ras=rastro(jugador);
                                    if (ras=='4')
                                        break;
                                    ant=0;
                                    imprimir_d (tab_f,jugador,puntos,pasos,i,j);
                                    do
                                    {
                                        mov=getch();
                                        if(mov=='w'||mov=='W')
                                        {
                                            arriba_f(tab_f,jugador,&puntos,&pasos,&i,&j,niv,ras,&ant,&pos);
                                        }
                                        else if(mov=='s'||mov=='S')
                                        {
                                            abajo_f(tab_f,jugador,&puntos,&pasos,&i,&j,niv,ras,&ant,&pos);
                                        }
                                        else if(mov=='d'||mov=='D')
                                        {
                                            derecha_f(tab_f,jugador,&puntos,&pasos,&i,&j,niv,ras,&ant,&pos);
                                        }
                                        else if(mov=='a'||mov=='A')
                                        {
                                            izquierda_f(tab_f,jugador,&puntos,&pasos,&i,&j,niv,ras,&ant,&pos);
                                        }
                                    }while(tab_f[8][2]==70&&mov!=42&&puntos.nivel<IF*JF);
                                    if(tab_f[8][2]!=70)
                                    {
                                        system("cls");
                                        printf("\n\n\n\tFELICITACIONES.... NIVEL COMPLETO");
                                        paso=2;
                                        getch();
                                    }
                                    else if(puntos.nivel>IF*JF)
                                    {
                                        system("cls");
                                        printf("\n\n\n\n\n\n\t\tJUEGO INCOMPLETO....INTENTELO DE NUEVO\n\n\n\n\n");
                                        paso=0;
                                        getch();
                                    }
                                    else if(mov==42)
                                    {
                                        system("cls");
                                        printf("\n\n\n\n\n\n\t\tJUEGO INCOMPLETO....INTENTELO DE NUEVO\n\n\n\n\n");
                                        paso=0;
                                        getch();
                                    }
                                    if(paso==2)
                                    {
                                        niv='4';
                                        break;
                                    }
                                    else if(paso==0)
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

                                iniciar_v(&jugador,&puntos,&pasos);
                                cargar4(tab_m);
                                i=18,j=1;        /**  POSICION INICIAL MF  **/
                                ras=rastro(jugador);
                                if (ras=='4')
                                    break;
                                imprimir_mf (tab_m,jugador,puntos,pasos,i,j);
                                do
                                {
                                    mov=getch();
                                    if(mov=='w'||mov=='W')
                                    {
                                        arriba_m(tab_m,jugador,&puntos,&pasos,&i,&j,niv,ras,&ant,&pos);
                                    }
                                    else if(mov=='s'||mov=='S')
                                    {
                                        abajo_m(tab_m,jugador,&puntos,&pasos,&i,&j,niv,ras,&ant,&pos);
                                    }
                                    else if(mov=='d'||mov=='D')
                                    {
                                        derecha_m(tab_m,jugador,&puntos,&pasos,&i,&j,niv,ras,&ant,&pos);
                                    }
                                    else if(mov=='a'||mov=='A')
                                    {
                                        izquierda_m(tab_m,jugador,&puntos,&pasos,&i,&j,niv,ras,&ant,&pos);
                                    }
                                }while(tab_m[1][1]==70&&mov!=42);

                                break;

                                case'2':        /** NIVEL MEDIO **/

                                cargar5(tab_m);
                                i=38,j=7;        /**  POSICION INICIAL MM  **/
                                ras=rastro(jugador);
                                if (ras=='4')
                                    break;
                                imprimir_mm (tab_m,jugador,puntos,pasos,i,j);
                                do
                                {
                                    mov=getch();
                                    if(mov=='w'||mov=='W')
                                    {
                                        arriba_m(tab_m,jugador,&puntos,&pasos,&i,&j,niv,ras,&ant,&pos);
                                    }
                                    else if(mov=='s'||mov=='S')
                                    {
                                        abajo_m(tab_m,jugador,&puntos,&pasos,&i,&j,niv,ras,&ant,&pos);
                                    }
                                    else if(mov=='d'||mov=='D')
                                    {
                                        derecha_m(tab_m,jugador,&puntos,&pasos,&i,&j,niv,ras,&ant,&pos);
                                    }
                                    else if(mov=='a'||mov=='A')
                                    {
                                        izquierda_m(tab_m,jugador,&puntos,&pasos,&i,&j,niv,ras,&ant,&pos);
                                    }
                                }while(tab_m[15][7]==70&&mov!=42);

                                break;

                                case'3':        /** NIVEL DIFICIL **/

                                cargar6(tab_m);
                                i=19,j=7;        /**  POSICION INICIAL MD  **/
                                ras=rastro(jugador);
                                if (ras=='4')
                                        break;
                                imprimir_md (tab_m,jugador,puntos,pasos,i,j);
                                do
                                {
                                    mov=getch();
                                    if(mov=='w'||mov=='W')
                                    {
                                        arriba_m(tab_m,jugador,&puntos,&pasos,&i,&j,niv,ras,&ant,&pos);
                                    }
                                    else if(mov=='s'||mov=='S')
                                    {
                                        abajo_m(tab_m,jugador,&puntos,&pasos,&i,&j,niv,ras,&ant,&pos);
                                    }
                                    else if(mov=='d'||mov=='D')
                                    {
                                        derecha_m(tab_m,jugador,&puntos,&pasos,&i,&j,niv,ras,&ant,&pos);
                                    }
                                    else if(mov=='a'||mov=='A')
                                    {
                                        izquierda_m(tab_m,jugador,&puntos,&pasos,&i,&j,niv,ras,&ant,&pos);
                                    }
                                }while(tab_m[1][13]==70&&mov!=42);

                                break;

                            }
                        }while(niv!='4');

                        break;

                        case'3':        /** TAMAÑO DIFICIL **/

                        do
                        {
                            niv=nivel(jugador);
                            if(niv=='1')        /** NIVEL FACIL **/
                            {

                                cargar7(tab_d);
                                i=1,j=1;        /**  POSICION INICIAL DF  **/
                                ras=rastro(jugador);
                                if (ras=='4')
                                        break;
                                imprimir_df (tab_d,jugador,puntos,pasos,i,j);
                                do
                                {
                                    mov=getch();
                                    if(mov=='w'||mov=='W')
                                    {
                                        arriba_d(tab_d,jugador,&puntos,&pasos,&i,&j,niv,ras,&ant,&pos);
                                    }
                                    else if(mov=='s'||mov=='S')
                                    {
                                        abajo_d(tab_d,jugador,&puntos,&pasos,&i,&j,niv,ras,&ant,&pos);
                                    }
                                    else if(mov=='d'||mov=='D')
                                    {
                                        derecha_d(tab_d,jugador,&puntos,&pasos,&i,&j,niv,ras,&ant,&pos);
                                    }
                                    else if(mov=='a'||mov=='A')
                                    {
                                        izquierda_d(tab_d,jugador,&puntos,&pasos,&i,&j,niv,ras,&ant,&pos);
                                    }
                                }while(tab_d[50][19]==70&&mov!=42);

                                if(tab_d[50][19]!=70)
                                {
                                    printf("\n\n\n\tFELICITACIONES.... NIVEL COMPLETO");
                                    paso='s';
                                    getch();
                                }
                                if(mov!=42)
                                {
                                    printf("\n\n\n\tJUEGO INCOMPLETO....INTENTELO DE NUEVO");
                                    paso='n';
                                    getch();
                                }
                                if(puntos.total>=100)
                                {
                                    system("cls");
                                    printf("\n\n\n\n\n\n\t\tJUEGO INCOMPLETO....INTENTELO DE NUEVO\n\n\n\n\n");
                                    getch();
                                }
                            }

                            else if(niv=='2')        /** NIVEL MEDIO **/
                            {

                                cargar8(tab_d);
                                i=58,j=1;
                                ras=rastro(jugador);
                                if (ras=='4')
                                        break;
                                imprimir_dm (tab_d,jugador,puntos,pasos,i,j);
                                do
                                {
                                    mov=getch();
                                    if(mov=='w'||mov=='W')
                                    {
                                        arriba_d(tab_d,jugador,&puntos,&pasos,&i,&j,niv,ras,&ant,&pos);
                                    }
                                    else if(mov=='s'||mov=='S')
                                    {
                                        abajo_d(tab_d,jugador,&puntos,&pasos,&i,&j,niv,ras,&ant,&pos);
                                    }
                                    else if(mov=='d'||mov=='D')
                                    {
                                        derecha_d(tab_d,jugador,&puntos,&pasos,&i,&j,niv,ras,&ant,&pos);
                                    }
                                    else if(mov=='a'||mov=='A')
                                    {
                                        izquierda_d(tab_d,jugador,&puntos,&pasos,&i,&j,niv,ras,&ant,&pos);
                                    }
                                }while(tab_d[13][32]==70&&mov!=42);

                                if(tab_d[50][19]!=70)
                                {
                                    printf("\n\n\n\tFELICITACIONES.... NIVEL COMPLETO");
                                    paso='s';
                                    getch();
                                }
                                if(mov!=42)
                                {
                                    printf("\n\n\n\tJUEGO INCOMPLETO....INTENTELO DE NUEVO");
                                    paso='n';
                                    getch();
                                }
                                if(puntos.total>=100)
                                {
                                    system("cls");
                                    printf("\n\n\n\n\n\n\t\tJUEGO INCOMPLETO....INTENTELO DE NUEVO\n\n\n\n\n");
                                    getch();
                                }

                            }

                            case'3':        /** NIVEL DIFICIL **/

                                cargar9(tab_d);
                                i=52,j=7;        /**  POSICION INICIAL DD  **/
                                ras=rastro(jugador);
                                if (ras=='4')
                                        break;
                                imprimir_dm (tab_d,jugador,puntos,pasos,i,j);
                                do
                                {
                                    mov=getch();
                                    if(mov=='w'||mov=='W')
                                    {
                                        arriba_d(tab_d,jugador,&puntos,&pasos,&i,&j,niv,ras,&ant,&pos);
                                    }
                                    else if(mov=='s'||mov=='S')
                                    {
                                        abajo_d(tab_d,jugador,&puntos,&pasos,&i,&j,niv,ras,&ant,&pos);
                                    }
                                    else if(mov=='d'||mov=='D')
                                    {
                                        derecha_d(tab_d,jugador,&puntos,&pasos,&i,&j,niv,ras,&ant,&pos);
                                    }
                                    else if(mov=='a'||mov=='A')
                                    {
                                        izquierda_d(tab_d,jugador,&puntos,&pasos,&i,&j,niv,ras,&ant,&pos);
                                    }
                                }while(tab_d[1][38]==70&&mov!=42);

                                break;

                            }

                        }while(niv!='4');
                        break;

                    }
                }while(tam!='4');

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

void abajo_d (char tab[ID][JD],jug nom,punt*punto,pas*pasos,int*i,int*j,char niv,char ras,char*ant,char*pos)
{
    system("cls");
    if(tab[*i+1][*j]==P)        /**  LIMITE  **/
    {
        pasos->limite=pasos->limite+1;
        punto->nivel=punto->nivel+5;
        punto->total=punto->total+5;
        tab[*i][*j]=S;   /** (v) **/
    }
    else if(tab[*i+1][*j]==M)       /**  MURO  **/
    {
        pasos->muro=pasos->muro+1;
        punto->nivel=punto->nivel+3;
        punto->total=punto->total+3;
        tab[*i][*j]=S;   /** (v) **/
    }
    else if(tab[*i+1][*j]==70)      /**  FINAL  **/
    {
        punto->nivel=punto->nivel+1;
        punto->total=punto->total+1;
        tab[*i][*j]=32;
        *i=*i+1;
        tab[*i][*j]=S;   /** (v) **/
    }
    if(ras=='1')        /** RASTRO FACIL  **/
    {
        if(*ant==0)
        {
            if(tab[*i+1][*j]!=P&&tab[*i+1][*j]!=M)
            {
                *ant=32;
                *pos=tab[*i+1][*j];
            }
            if (*ant==32)
            {
                tab[*i][*j]=46;
                *ant=*pos;
                *i=*i+1;
                tab[*i][*j]=S;   /** (v) **/
            }
        }
        else if(*ant==32)
        {
            if(tab[*i+1][*j]!=P&&tab[*i+1][*j]!=M)
            {
                *pos=tab[*i+1][*j];
                tab[*i][*j]=46;
                *ant=*pos;
                *i=*i+1;
                tab[*i][*j]=S;   /** (v) **/
            }
        }
        else if(*ant==46)
        {
            if(tab[*i+1][*j]!=P&&tab[*i+1][*j]!=M)
            {
                *pos=tab[*i+1][*j];
                tab[*i][*j]=50;
                *ant=*pos;
                *i=*i+1;
                tab[*i][*j]=S;   /** (v) **/
            }
        }
        else if(*ant==50)
        {
            if(tab[*i+1][*j]!=P&&tab[*i+1][*j]!=M)
            {
                *pos=tab[*i+1][*j];
                tab[*i][*j]=51;
                *ant=*pos;
                *i=*i+1;
                tab[*i][*j]=S;   /** (v) **/
            }
        }
        else if(*ant==51)
        {
            if(tab[*i+1][*j]!=P&&tab[*i+1][*j]!=M)
            {
                *pos=tab[*i+1][*j];
                tab[*i][*j]=52;
                *ant=*pos;
                *i=*i+1;
                tab[*i][*j]=S;   /** (v) **/
            }
        }
        else if(*ant==52)
        {
            if(tab[*i+1][*j]!=P&&tab[*i+1][*j]!=M)
            {
                *pos=tab[*i+1][*j];
                tab[*i][*j]=53;
                *ant=*pos;
                *i=*i+1;
                tab[*i][*j]=S;   /** (v) **/
            }
        }
        else if(*ant==53)
        {
            if(tab[*i+1][*j]!=P&&tab[*i+1][*j]!=M)
            {
                *pos=tab[*i+1][*j];
                tab[*i][*j]=54;
                *ant=*pos;
                *i=*i+1;
                tab[*i][*j]=S;   /** (v) **/
            }
        }
        else if(*ant==54)
        {
            if(tab[*i+1][*j]!=P&&tab[*i+1][*j]!=M)
            {
                *pos=tab[*i+1][*j];
                tab[*i][*j]=55;
                *ant=*pos;
                *i=*i+1;
                tab[*i][*j]=S;   /** (v) **/
            }
        }
        else if(*ant==55)
        {
            if(tab[*i+1][*j]!=P&&tab[*i+1][*j]!=M)
            {
                *pos=tab[*i+1][*j];
                tab[*i][*j]=56;
                *ant=*pos;
                *i=*i+1;
                tab[*i][*j]=S;   /** (v) **/
            }
        }
        else if(*ant==56)
        {
            if(tab[*i+1][*j]!=P&&tab[*i+1][*j]!=M)
            {
                *pos=tab[*i+1][*j];
                tab[*i][*j]=57;
                *ant=*pos;
                *i=*i+1;
                tab[*i][*j]=S;   /** (v) **/
            }
        }
        else if(*ant==57)
        {
            if(tab[*i+1][*j]!=P&&tab[*i+1][*j]!=M)
            {
                *pos=tab[*i+1][*j];
                tab[*i][*j]=43;
                *ant=*pos;
                *i=*i+1;
                tab[*i][*j]=S;   /** (v) **/
            }
        }
        else if(*ant==43)
        {
            if(tab[*i+1][*j]!=P&&tab[*i+1][*j]!=M)
            {
                *pos=tab[*i+1][*j];
                tab[*i][*j]=43;
                *ant=*pos;
                *i=*i+1;
                tab[*i][*j]=S;   /** (v) **/
            }
        }
        punto->nivel=punto->nivel+1;
        punto->total=punto->total+1;
    }
    else if(ras=='2')       /**  RASTRO MEDIO  **/
    {
         if(tab[*i+1][*j]==32)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=46;   /** (PUNTO) **/
            *i=*i+1;
            tab[*i][*j]=S;   /** (v) **/
        }
        else if(tab[*i+1][*j]==46)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=46;   /** (PUNTO) **/
            *i=*i+1;
            tab[*i][*j]=S;
        }
    }
    else if(ras=='3')       /**  RASTRO DIFICIL  **/
    {
        if(tab[*i+1][*j]==32)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=32;   /** (ESPACIO) **/
            *i=*i+1;
            tab[*i][*j]=S;   /** (v) **/
        }
    }
    pasos->abajo=pasos->abajo+1;
    if(niv=='1')
        imprimir_df (tab,nom,*punto,*pasos,*i,*j);
    else if(niv=='2')
        imprimir_dm (tab,nom,*punto,*pasos,*i,*j);
    else if(niv=='3')
        imprimir_dd (tab,nom,*punto,*pasos,*i,*j);
}
void abajo_f (char tab[IF][JF],jug nom,punt*punto,pas*pasos,int*i,int*j,char niv,char ras,char*ant,char*pos)
{
    system("cls");
    if(tab[*i+1][*j]==P)        /**  LIMITE  **/
    {
        pasos->limite=pasos->limite+1;
        punto->nivel=punto->nivel+5;
        punto->total=punto->total+5;
        tab[*i][*j]=S;   /** (v) **/
    }
    else if(tab[*i+1][*j]==M)       /**  MURO  **/
    {
        pasos->muro=pasos->muro+1;
        punto->nivel=punto->nivel+3;
        punto->total=punto->total+3;
        tab[*i][*j]=S;   /** (v) **/
    }
    else if(tab[*i+1][*j]==70)      /**  FINAL  **/
    {
        punto->nivel=punto->nivel+1;
        punto->total=punto->total+1;
        tab[*i][*j]=32;
        *i=*i+1;
        tab[*i][*j]=S;   /** (v) **/
    }
    if(ras=='1')        /** RASTRO FACIL  **/
    {
        if(*ant==0)
        {
            if(tab[*i+1][*j]!=P&&tab[*i+1][*j]!=M)
            {
                *ant=32;
                *pos=tab[*i+1][*j];
            }
            if (*ant==32)
            {
                tab[*i][*j]=46;
                *ant=*pos;
                *i=*i+1;
                tab[*i][*j]=S;   /** (v) **/
            }
        }
        else if(*ant==32)
        {
            if(tab[*i+1][*j]!=P&&tab[*i+1][*j]!=M)
            {
                *pos=tab[*i+1][*j];
                tab[*i][*j]=46;
                *ant=*pos;
                *i=*i+1;
                tab[*i][*j]=S;   /** (v) **/
            }
        }
        else if(*ant==46)
        {
            if(tab[*i+1][*j]!=P&&tab[*i+1][*j]!=M)
            {
                *pos=tab[*i+1][*j];
                tab[*i][*j]=50;
                *ant=*pos;
                *i=*i+1;
                tab[*i][*j]=S;   /** (v) **/
            }
        }
        else if(*ant==50)
        {
            if(tab[*i+1][*j]!=P&&tab[*i+1][*j]!=M)
            {
                *pos=tab[*i+1][*j];
                tab[*i][*j]=51;
                *ant=*pos;
                *i=*i+1;
                tab[*i][*j]=S;   /** (v) **/
            }
        }
        else if(*ant==51)
        {
            if(tab[*i+1][*j]!=P&&tab[*i+1][*j]!=M)
            {
                *pos=tab[*i+1][*j];
                tab[*i][*j]=52;
                *ant=*pos;
                *i=*i+1;
                tab[*i][*j]=S;   /** (v) **/
            }
        }
        else if(*ant==52)
        {
            if(tab[*i+1][*j]!=P&&tab[*i+1][*j]!=M)
            {
                *pos=tab[*i+1][*j];
                tab[*i][*j]=53;
                *ant=*pos;
                *i=*i+1;
                tab[*i][*j]=S;   /** (v) **/
            }
        }
        else if(*ant==53)
        {
            if(tab[*i+1][*j]!=P&&tab[*i+1][*j]!=M)
            {
                *pos=tab[*i+1][*j];
                tab[*i][*j]=54;
                *ant=*pos;
                *i=*i+1;
                tab[*i][*j]=S;   /** (v) **/
            }
        }
        else if(*ant==54)
        {
            if(tab[*i+1][*j]!=P&&tab[*i+1][*j]!=M)
            {
                *pos=tab[*i+1][*j];
                tab[*i][*j]=55;
                *ant=*pos;
                *i=*i+1;
                tab[*i][*j]=S;   /** (v) **/
            }
        }
        else if(*ant==55)
        {
            if(tab[*i+1][*j]!=P&&tab[*i+1][*j]!=M)
            {
                *pos=tab[*i+1][*j];
                tab[*i][*j]=56;
                *ant=*pos;
                *i=*i+1;
                tab[*i][*j]=S;   /** (v) **/
            }
        }
        else if(*ant==56)
        {
            if(tab[*i+1][*j]!=P&&tab[*i+1][*j]!=M)
            {
                *pos=tab[*i+1][*j];
                tab[*i][*j]=57;
                *ant=*pos;
                *i=*i+1;
                tab[*i][*j]=S;   /** (v) **/
            }
        }
        else if(*ant==57)
        {
            if(tab[*i+1][*j]!=P&&tab[*i+1][*j]!=M)
            {
                *pos=tab[*i+1][*j];
                tab[*i][*j]=43;
                *ant=*pos;
                *i=*i+1;
                tab[*i][*j]=S;   /** (v) **/
            }
        }
        else if(*ant==43)
        {
            if(tab[*i+1][*j]!=P&&tab[*i+1][*j]!=M)
            {
                *pos=tab[*i+1][*j];
                tab[*i][*j]=43;
                *ant=*pos;
                *i=*i+1;
                tab[*i][*j]=S;   /** (v) **/
            }
        }
        punto->nivel=punto->nivel+1;
        punto->total=punto->total+1;
    }
    if(ras=='2')
    {
         if(tab[*i+1][*j]==32)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=46;   /** (PUNTO) **/
            *i=*i+1;
            tab[*i][*j]=S;   /** (v) **/
        }
        else if(tab[*i+1][*j]==46)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=46;
            *i=*i+1;
            tab[*i][*j]=S;
        }
    }
    else if(ras=='3')
    {
        if(tab[*i+1][*j]==32)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=32;   /** (ESPACIO) **/
            *i=*i+1;
            tab[*i][*j]=S;   /** (v) **/
        }
    }
    pasos->abajo=pasos->abajo+1;
    if(niv=='1')
        imprimir_f (tab,nom,*punto,*pasos,*i,*j);
    else if(niv=='2')
        imprimir_m (tab,nom,*punto,*pasos,*i,*j);
    else if(niv=='3')
        imprimir_d (tab,nom,*punto,*pasos,*i,*j);
}
void abajo_m (char tab[IM][JM],jug nom,punt*punto,pas*pasos,int*i,int*j,char niv,char ras,char*ant,char*pos)
{
    system("cls");
    if(tab[*i+1][*j]==P)        /**  LIMITE  **/
    {
        pasos->limite=pasos->limite+1;
        punto->nivel=punto->nivel+5;
        punto->total=punto->total+5;
        tab[*i][*j]=S;   /** (v) **/
    }
    else if(tab[*i+1][*j]==M)       /**  MURO  **/
    {
        pasos->muro=pasos->muro+1;
        punto->nivel=punto->nivel+3;
        punto->total=punto->total+3;
        tab[*i][*j]=S;   /** (v) **/
    }
    else if(tab[*i+1][*j]==70)      /**  FINAL  **/
    {
        punto->nivel=punto->nivel+1;
        punto->total=punto->total+1;
        tab[*i][*j]=32;
        *i=*i+1;
        tab[*i][*j]=S;   /** (v) **/
    }
    if(ras=='1')        /** RASTRO FACIL  **/
    {
        if(*ant==0)
        {
            if(tab[*i+1][*j]!=P&&tab[*i+1][*j]!=M)
            {
                *ant=32;
                *pos=tab[*i+1][*j];
            }
            if (*ant==32)
            {
                tab[*i][*j]=46;
                *ant=*pos;
                *i=*i+1;
                tab[*i][*j]=S;   /** (v) **/
            }
        }
        else if(*ant==32)
        {
            if(tab[*i+1][*j]!=P&&tab[*i+1][*j]!=M)
            {
                *pos=tab[*i+1][*j];
                tab[*i][*j]=46;
                *ant=*pos;
                *i=*i+1;
                tab[*i][*j]=S;   /** (v) **/
            }
        }
        else if(*ant==46)
        {
            if(tab[*i+1][*j]!=P&&tab[*i+1][*j]!=M)
            {
                *pos=tab[*i+1][*j];
                tab[*i][*j]=50;
                *ant=*pos;
                *i=*i+1;
                tab[*i][*j]=S;   /** (v) **/
            }
        }
        else if(*ant==50)
        {
            if(tab[*i+1][*j]!=P&&tab[*i+1][*j]!=M)
            {
                *pos=tab[*i+1][*j];
                tab[*i][*j]=51;
                *ant=*pos;
                *i=*i+1;
                tab[*i][*j]=S;   /** (v) **/
            }
        }
        else if(*ant==51)
        {
            if(tab[*i+1][*j]!=P&&tab[*i+1][*j]!=M)
            {
                *pos=tab[*i+1][*j];
                tab[*i][*j]=52;
                *ant=*pos;
                *i=*i+1;
                tab[*i][*j]=S;   /** (v) **/
            }
        }
        else if(*ant==52)
        {
            if(tab[*i+1][*j]!=P&&tab[*i+1][*j]!=M)
            {
                *pos=tab[*i+1][*j];
                tab[*i][*j]=53;
                *ant=*pos;
                *i=*i+1;
                tab[*i][*j]=S;   /** (v) **/
            }
        }
        else if(*ant==53)
        {
            if(tab[*i+1][*j]!=P&&tab[*i+1][*j]!=M)
            {
                *pos=tab[*i+1][*j];
                tab[*i][*j]=54;
                *ant=*pos;
                *i=*i+1;
                tab[*i][*j]=S;   /** (v) **/
            }
        }
        else if(*ant==54)
        {
            if(tab[*i+1][*j]!=P&&tab[*i+1][*j]!=M)
            {
                *pos=tab[*i+1][*j];
                tab[*i][*j]=55;
                *ant=*pos;
                *i=*i+1;
                tab[*i][*j]=S;   /** (v) **/
            }
        }
        else if(*ant==55)
        {
            if(tab[*i+1][*j]!=P&&tab[*i+1][*j]!=M)
            {
                *pos=tab[*i+1][*j];
                tab[*i][*j]=56;
                *ant=*pos;
                *i=*i+1;
                tab[*i][*j]=S;   /** (v) **/
            }
        }
        else if(*ant==56)
        {
            if(tab[*i+1][*j]!=P&&tab[*i+1][*j]!=M)
            {
                *pos=tab[*i+1][*j];
                tab[*i][*j]=57;
                *ant=*pos;
                *i=*i+1;
                tab[*i][*j]=S;   /** (v) **/
            }
        }
        else if(*ant==57)
        {
            if(tab[*i+1][*j]!=P&&tab[*i+1][*j]!=M)
            {
                *pos=tab[*i+1][*j];
                tab[*i][*j]=43;
                *ant=*pos;
                *i=*i+1;
                tab[*i][*j]=S;   /** (v) **/
            }
        }
        else if(*ant==43)
        {
            if(tab[*i+1][*j]!=P&&tab[*i+1][*j]!=M)
            {
                *pos=tab[*i+1][*j];
                tab[*i][*j]=43;
                *ant=*pos;
                *i=*i+1;
                tab[*i][*j]=S;   /** (v) **/
            }
        }
        punto->nivel=punto->nivel+1;
        punto->total=punto->total+1;
    }
    if(ras=='2')
    {
         if(tab[*i+1][*j]==32)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=46;   /** (PUNTO) **/
            *i=*i+1;
            tab[*i][*j]=S;   /** (v) **/
        }
        else if(tab[*i+1][*j]==46)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=46;
            *i=*i+1;
            tab[*i][*j]=S;
        }
    }
    else if(ras=='3')
    {
        if(tab[*i+1][*j]==32)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=32;   /** (ESPACIO) **/
            *i=*i+1;
            tab[*i][*j]=S;   /** (v) **/
        }
    }
    pasos->abajo=pasos->abajo+1;
    if(niv=='1')
        imprimir_mf (tab,nom,*punto,*pasos,*i,*j);
    else if(niv=='2')
        imprimir_mm (tab,nom,*punto,*pasos,*i,*j);
    else if(niv=='3')
        imprimir_md (tab,nom,*punto,*pasos,*i,*j);
}
void arriba_d (char tab[ID][JD],jug nom,punt*punto,pas*pasos,int*i,int*j,char niv,char ras,char*ant,char*pos)
{
    system("cls");
    if(tab[*i-1][*j]==P)            /**  LIMITE  **/
    {
        pasos->limite=pasos->limite+1;
        punto->nivel=punto->nivel+5;
        punto->total=punto->total+5;
        tab[*i][*j]=W;   /** (^) **/
    }
    else if(tab[*i-1][*j]==M)       /**  MURO  **/
    {
        pasos->muro=pasos->muro+1;
        punto->nivel=punto->nivel+3;
        punto->total=punto->total+3;
        tab[*i][*j]=W;   /** (^) **/
    }
    else if(tab[*i-1][*j]==70)      /**  FINAL  **/
    {
        punto->nivel=punto->nivel+1;
        punto->total=punto->total+1;
        tab[*i][*j]=32;
        *i=*i-1;
        tab[*i][*j]=W;   /** (v) **/
    }
    if(ras=='1')        /** RASTRO FACIL  **/
    {
        if(*ant==0)
        {
            if(tab[*i-1][*j]!=P&&tab[*i-1][*j]!=M)
            {
                *ant=32;
                *pos=tab[*i-1][*j];
            }
            if (*ant==32)
            {
                tab[*i][*j]=46;
                *ant=*pos,
                *i=*i-1;
                tab[*i][*j]=W;   /** (v) **/
            }
        }
        else if(*ant==32)
        {
            if(tab[*i-1][*j]!=P&&tab[*i-1][*j]!=M)
            {
                *pos=tab[*i-1][*j];
                tab[*i][*j]=46;
                *ant=*pos;
                *i=*i-1;
                tab[*i][*j]=W;   /** (v) **/
            }
        }
        else if(*ant==46)
        {
            if(tab[*i-1][*j]!=P&&tab[*i-1][*j]!=M)
            {
                *pos=tab[*i-1][*j];
                tab[*i][*j]=50;
                *ant=*pos;
                *i=*i-1;
                tab[*i][*j]=W;   /** (v) **/
            }
        }
        else if(*ant==50)
        {
            if(tab[*i-1][*j]!=P&&tab[*i-1][*j]!=M)
            {
                *pos=tab[*i-1][*j];
                tab[*i][*j]=51;
                *ant=*pos;
                *i=*i-1;
                tab[*i][*j]=W;   /** (v) **/
            }
        }
        else if(*ant==51)
        {
            if(tab[*i-1][*j]!=P&&tab[*i-1][*j]!=M)
            {
                *pos=tab[*i-1][*j];
                tab[*i][*j]=52;
                *ant=*pos;
                *i=*i-1;
                tab[*i][*j]=W;   /** (v) **/
            }
        }
        else if(*ant==52)
        {
            if(tab[*i-1][*j]!=P&&tab[*i-1][*j]!=M)
            {
                *pos=tab[*i+1][*j];
                tab[*i][*j]=53;
                *ant=*pos;
                *i=*i-1;
                tab[*i][*j]=W;   /** (v) **/
            }
        }
        else if(*ant==53)
        {
            if(tab[*i-1][*j]!=P&&tab[*i-1][*j]!=M)
            {
                *pos=tab[*i-1][*j];
                tab[*i][*j]=54;
                *ant=*pos;
                *i=*i-1;
                tab[*i][*j]=W;   /** (v) **/
            }
        }
        else if(*ant==54)
        {
            if(tab[*i-1][*j]!=P&&tab[*i-1][*j]!=M)
            {
                *pos=tab[*i-1][*j];
                tab[*i][*j]=55;
                *ant=*pos;
                *i=*i-1;
                tab[*i][*j]=W;   /** (v) **/
            }
        }
        else if(*ant==55)
        {
            if(tab[*i-1][*j]!=P&&tab[*i-1][*j]!=M)
            {
                *pos=tab[*i-1][*j];
                tab[*i][*j]=56;
                *ant=*pos;
                *i=*i-1;
                tab[*i][*j]=W;   /** (v) **/
            }
        }
        else if(*ant==56)
        {
            if(tab[*i-1][*j]!=P&&tab[*i-1][*j]!=M)
            {
                *pos=tab[*i-1][*j];
                tab[*i][*j]=57;
                *ant=*pos;
                *i=*i-1;
                tab[*i][*j]=W;   /** (v) **/
            }
        }
        else if(*ant==57)
        {
            if(tab[*i-1][*j]!=P&&tab[*i-1][*j]!=M)
            {
                *pos=tab[*i-1][*j];
                tab[*i][*j]=43;
                *ant=*pos;
                *i=*i-1;
                tab[*i][*j]=W;   /** (v) **/
            }
        }
        else if(*ant==43)
        {
            if(tab[*i-1][*j]!=P&&tab[*i-1][*j]!=M)
            {
                *pos=tab[*i-1][*j];
                tab[*i][*j]=43;
                *ant=*pos;
                *i=*i-1;
                tab[*i][*j]=W;   /** (v) **/
            }
        }
        punto->nivel=punto->nivel+1;
        punto->total=punto->total+1;
    }
    if(ras=='2')
    {
         if(tab[*i-1][*j]==32)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=46;   /** (PUNTO) **/
            *i=*i-1;
            tab[*i][*j]=W;   /** (^) **/
        }
        else if(tab[*i-1][*j]==46)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=46;
            *i=*i-1;
            tab[*i][*j]=W;
        }
    }
    else if(ras=='3')
    {
        if(tab[*i-1][*j]==32)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=32;   /** (ESPACIO) **/
            *i=*i-1;
            tab[*i][*j]=W;   /** (^) **/
        }
    }

    pasos->arriba=pasos->arriba+1;
    if(niv=='1')
        imprimir_df (tab,nom,*punto,*pasos,*i,*j);
    else if(niv=='2')
        imprimir_dm (tab,nom,*punto,*pasos,*i,*j);
    else if(niv=='3')
        imprimir_dd (tab,nom,*punto,*pasos,*i,*j);
}
void arriba_f (char tab[IF][JF],jug nom,punt*punto,pas*pasos,int*i,int*j,char niv,char ras,char*ant,char*pos)
{
    system("cls");
    if(tab[*i-1][*j]==P)            /**  LIMITE  **/
    {
        pasos->limite=pasos->limite+1;
        punto->nivel=punto->nivel+5;
        punto->total=punto->total+5;
        tab[*i][*j]=W;   /** (^) **/
    }
    else if(tab[*i-1][*j]==M)       /**  MURO  **/
    {
        pasos->muro=pasos->muro+1;
        punto->nivel=punto->nivel+3;
        punto->total=punto->total+3;
        tab[*i][*j]=W;   /** (^) **/
    }
    else if(tab[*i-1][*j]==70)      /**  FINAL  **/
    {
        punto->nivel=punto->nivel+1;
        punto->total=punto->total+1;
        tab[*i][*j]=32;
        *i=*i-1;
        tab[*i][*j]=W;   /** (v) **/
    }
    if(ras=='1')        /** RASTRO FACIL  **/
    {
        if(*ant==0)
        {
            if(tab[*i-1][*j]!=P&&tab[*i-1][*j]!=M)
            {
                *ant=32;
                *pos=tab[*i-1][*j];
            }
            if (*ant==32)
            {
                tab[*i][*j]=46;
                *ant=*pos,
                *i=*i-1;
                tab[*i][*j]=W;   /** (v) **/
            }
        }
        else if(*ant==32)
        {
            if(tab[*i-1][*j]!=P&&tab[*i-1][*j]!=M)
            {
                *pos=tab[*i-1][*j];
                tab[*i][*j]=46;
                *ant=*pos;
                *i=*i-1;
                tab[*i][*j]=W;   /** (v) **/
            }
        }
        else if(*ant==46)
        {
            if(tab[*i-1][*j]!=P&&tab[*i-1][*j]!=M)
            {
                *pos=tab[*i-1][*j];
                tab[*i][*j]=50;
                *ant=*pos;
                *i=*i-1;
                tab[*i][*j]=W;   /** (v) **/
            }
        }
        else if(*ant==50)
        {
            if(tab[*i-1][*j]!=P&&tab[*i-1][*j]!=M)
            {
                *pos=tab[*i-1][*j];
                tab[*i][*j]=51;
                *ant=*pos;
                *i=*i-1;
                tab[*i][*j]=W;   /** (v) **/
            }
        }
        else if(*ant==51)
        {
            if(tab[*i-1][*j]!=P&&tab[*i-1][*j]!=M)
            {
                *pos=tab[*i-1][*j];
                tab[*i][*j]=52;
                *ant=*pos;
                *i=*i-1;
                tab[*i][*j]=W;   /** (v) **/
            }
        }
        else if(*ant==52)
        {
            if(tab[*i-1][*j]!=P&&tab[*i-1][*j]!=M)
            {
                *pos=tab[*i+1][*j];
                tab[*i][*j]=53;
                *ant=*pos;
                *i=*i-1;
                tab[*i][*j]=W;   /** (v) **/
            }
        }
        else if(*ant==53)
        {
            if(tab[*i-1][*j]!=P&&tab[*i-1][*j]!=M)
            {
                *pos=tab[*i-1][*j];
                tab[*i][*j]=54;
                *ant=*pos;
                *i=*i-1;
                tab[*i][*j]=W;   /** (v) **/
            }
        }
        else if(*ant==54)
        {
            if(tab[*i-1][*j]!=P&&tab[*i-1][*j]!=M)
            {
                *pos=tab[*i-1][*j];
                tab[*i][*j]=55;
                *ant=*pos;
                *i=*i-1;
                tab[*i][*j]=W;   /** (v) **/
            }
        }
        else if(*ant==55)
        {
            if(tab[*i-1][*j]!=P&&tab[*i-1][*j]!=M)
            {
                *pos=tab[*i-1][*j];
                tab[*i][*j]=56;
                *ant=*pos;
                *i=*i-1;
                tab[*i][*j]=W;   /** (v) **/
            }
        }
        else if(*ant==56)
        {
            if(tab[*i-1][*j]!=P&&tab[*i-1][*j]!=M)
            {
                *pos=tab[*i-1][*j];
                tab[*i][*j]=57;
                *ant=*pos;
                *i=*i-1;
                tab[*i][*j]=W;   /** (v) **/
            }
        }
        else if(*ant==57)
        {
            if(tab[*i-1][*j]!=P&&tab[*i-1][*j]!=M)
            {
                *pos=tab[*i-1][*j];
                tab[*i][*j]=43;
                *ant=*pos;
                *i=*i-1;
                tab[*i][*j]=W;   /** (v) **/
            }
        }
        else if(*ant==43)
        {
            if(tab[*i-1][*j]!=P&&tab[*i-1][*j]!=M)
            {
                *pos=tab[*i-1][*j];
                tab[*i][*j]=43;
                *ant=*pos;
                *i=*i-1;
                tab[*i][*j]=W;   /** (v) **/
            }
        }
        punto->nivel=punto->nivel+1;
        punto->total=punto->total+1;
    }
    if(ras=='2')
    {
         if(tab[*i-1][*j]==32)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=46;   /** (PUNTO) **/
            *i=*i-1;
            tab[*i][*j]=W;   /** (^) **/
        }
        else if(tab[*i-1][*j]==46)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=46;
            *i=*i-1;
            tab[*i][*j]=W;
        }
    }
    else if(ras=='3')
    {
        if(tab[*i-1][*j]==32)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=32;   /** (ESPACIO) **/
            *i=*i-1;
            tab[*i][*j]=W;   /** (^) **/
        }
    }
    pasos->arriba=pasos->arriba+1;
    if(niv=='1')
        imprimir_f (tab,nom,*punto,*pasos,*i,*j);
    else if(niv=='2')
        imprimir_m (tab,nom,*punto,*pasos,*i,*j);
    else if(niv=='3')
        imprimir_d (tab,nom,*punto,*pasos,*i,*j);
}
void arriba_m (char tab[IM][JM],jug nom,punt*punto,pas*pasos,int*i,int*j,char niv,char ras,char*ant,char*pos)
{
    system("cls");
    if(tab[*i-1][*j]==P)            /**  LIMITE  **/
    {
        pasos->limite=pasos->limite+1;
        punto->nivel=punto->nivel+5;
        punto->total=punto->total+5;
        tab[*i][*j]=W;   /** (^) **/
    }
    else if(tab[*i-1][*j]==M)       /**  MURO  **/
    {
        pasos->muro=pasos->muro+1;
        punto->nivel=punto->nivel+3;
        punto->total=punto->total+3;
        tab[*i][*j]=W;   /** (^) **/
    }
    else if(tab[*i-1][*j]==70)      /**  FINAL  **/
    {
        punto->nivel=punto->nivel+1;
        punto->total=punto->total+1;
        tab[*i][*j]=32;
        *i=*i-1;
        tab[*i][*j]=W;   /** (v) **/
    }
    if(ras=='1')        /** RASTRO FACIL  **/
    {
        if(*ant==0)
        {
            if(tab[*i-1][*j]!=P&&tab[*i-1][*j]!=M)
            {
                *ant=32;
                *pos=tab[*i-1][*j];
            }
            if (*ant==32)
            {
                tab[*i][*j]=46;
                *ant=*pos,
                *i=*i-1;
                tab[*i][*j]=W;   /** (v) **/
            }
        }
        else if(*ant==32)
        {
            if(tab[*i-1][*j]!=P&&tab[*i-1][*j]!=M)
            {
                *pos=tab[*i-1][*j];
                tab[*i][*j]=46;
                *ant=*pos;
                *i=*i-1;
                tab[*i][*j]=W;   /** (v) **/
            }
        }
        else if(*ant==46)
        {
            if(tab[*i-1][*j]!=P&&tab[*i-1][*j]!=M)
            {
                *pos=tab[*i-1][*j];
                tab[*i][*j]=50;
                *ant=*pos;
                *i=*i-1;
                tab[*i][*j]=W;   /** (v) **/
            }
        }
        else if(*ant==50)
        {
            if(tab[*i-1][*j]!=P&&tab[*i-1][*j]!=M)
            {
                *pos=tab[*i-1][*j];
                tab[*i][*j]=51;
                *ant=*pos;
                *i=*i-1;
                tab[*i][*j]=W;   /** (v) **/
            }
        }
        else if(*ant==51)
        {
            if(tab[*i-1][*j]!=P&&tab[*i-1][*j]!=M)
            {
                *pos=tab[*i-1][*j];
                tab[*i][*j]=52;
                *ant=*pos;
                *i=*i-1;
                tab[*i][*j]=W;   /** (v) **/
            }
        }
        else if(*ant==52)
        {
            if(tab[*i-1][*j]!=P&&tab[*i-1][*j]!=M)
            {
                *pos=tab[*i+1][*j];
                tab[*i][*j]=53;
                *ant=*pos;
                *i=*i-1;
                tab[*i][*j]=W;   /** (v) **/
            }
        }
        else if(*ant==53)
        {
            if(tab[*i-1][*j]!=P&&tab[*i-1][*j]!=M)
            {
                *pos=tab[*i-1][*j];
                tab[*i][*j]=54;
                *ant=*pos;
                *i=*i-1;
                tab[*i][*j]=W;   /** (v) **/
            }
        }
        else if(*ant==54)
        {
            if(tab[*i-1][*j]!=P&&tab[*i-1][*j]!=M)
            {
                *pos=tab[*i-1][*j];
                tab[*i][*j]=55;
                *ant=*pos;
                *i=*i-1;
                tab[*i][*j]=W;   /** (v) **/
            }
        }
        else if(*ant==55)
        {
            if(tab[*i-1][*j]!=P&&tab[*i-1][*j]!=M)
            {
                *pos=tab[*i-1][*j];
                tab[*i][*j]=56;
                *ant=*pos;
                *i=*i-1;
                tab[*i][*j]=W;   /** (v) **/
            }
        }
        else if(*ant==56)
        {
            if(tab[*i-1][*j]!=P&&tab[*i-1][*j]!=M)
            {
                *pos=tab[*i-1][*j];
                tab[*i][*j]=57;
                *ant=*pos;
                *i=*i-1;
                tab[*i][*j]=W;   /** (v) **/
            }
        }
        else if(*ant==57)
        {
            if(tab[*i-1][*j]!=P&&tab[*i-1][*j]!=M)
            {
                *pos=tab[*i-1][*j];
                tab[*i][*j]=43;
                *ant=*pos;
                *i=*i-1;
                tab[*i][*j]=W;   /** (v) **/
            }
        }
        else if(*ant==43)
        {
            if(tab[*i-1][*j]!=P&&tab[*i-1][*j]!=M)
            {
                *pos=tab[*i-1][*j];
                tab[*i][*j]=43;
                *ant=*pos;
                *i=*i-1;
                tab[*i][*j]=W;   /** (v) **/
            }
        }
        punto->nivel=punto->nivel+1;
        punto->total=punto->total+1;
    }
    else if(ras=='2')
    {
         if(tab[*i-1][*j]==32)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=46;   /** (PUNTO) **/
            *i=*i-1;
            tab[*i][*j]=W;   /** (^) **/
        }
        else if(tab[*i-1][*j]==46)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=46;
            *i=*i-1;
            tab[*i][*j]=W;
        }
    }
    else if(ras=='3')
    {
        if(tab[*i-1][*j]==32)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=32;   /** (ESPACIO) **/
            *i=*i-1;
            tab[*i][*j]=W;   /** (^) **/
        }
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
int cargar_juego (jug juga)
{
    FILE *arch;
    int i;
    i=0;
    if ((arch=fopen ("jugadores.txt","rb"))==NULL)
        return(0);
    else
    {
        while (!feof (arch))
        {
            fread (& juga ,50, 1, arch);
            i++;
        }
        fclose(arch);
        return (i-1);
    }
}
void derecha_d (char tab[ID][JD],jug nom,punt*punto,pas*pasos,int*i,int*j,char niv,char ras,char*ant,char*pos)
{
    system("cls");
    if(tab[*i][*j+1]==P)        /**  LIMITE  **/
    {
        pasos->limite=pasos->limite+1;
        punto->nivel=punto->nivel+5;
        punto->total=punto->total+5;
        tab[*i][*j]=D;   /** (>) **/
    }
    else if(tab[*i][*j+1]==M)   /**  MURO  **/
    {
        pasos->muro=pasos->muro+1;
        punto->nivel=punto->nivel+3;
        punto->total=punto->total+3;
        tab[*i][*j]=D;   /** (>) **/

    }
    else if(tab[*i][*j+1]==70)   /**  FINAL  **/
    {
        punto->nivel=punto->nivel+1;
        punto->total=punto->total+1;
        tab[*i][*j]=46;
        *j=*j+1;
        tab[*i][*j]=D;   /** (>) **/
    }
    if(ras=='1')        /** RASTRO FACIL  **/
    {
        if(*ant==0)
        {
            if(tab[*i][*j+1]!=P&&tab[*i][*j+1]!=M)
            {
                *ant=32;
                *pos=tab[*i][*j+1];
            }
            if (*ant==32)
            {
                tab[*i][*j]=46;
                *ant=*pos;
                *j=*j+1;
                tab[*i][*j]=D;   /** (v) **/
            }
        }
        else if(*ant==32)
        {
            if(tab[*i][*j+1]!=P&&tab[*i][*j+1]!=M)
            {
                *pos=tab[*i][*j+1];
                tab[*i][*j]=46;
                *ant=*pos;
                *j=*j+1;
                tab[*i][*j]=D;   /** (v) **/
            }
        }
        else if(*ant==46)
        {
            if(tab[*i][*j+1]!=P&&tab[*i][*j+1]!=M)
            {
                *pos=tab[*i][*j+1];
                tab[*i][*j]=50;
                *ant=*pos;
                *j=*j+1;
                tab[*i][*j]=D;   /** (v) **/
            }
        }
        else if(*ant==50)
        {
            if(tab[*i][*j+1]!=P&&tab[*i][*j+1]!=M)
            {
                *pos=tab[*i][*j+1];
                tab[*i][*j]=51;
                *ant=*pos;
                *j=*j+1;
                tab[*i][*j]=D;   /** (v) **/
            }
        }
        else if(*ant==51)
        {
            if(tab[*i][*j+1]!=P&&tab[*i][*j+1]!=M)
            {
                *pos=tab[*i][*j+1];
                tab[*i][*j]=52;
                *ant=*pos;
                *j=*j+1;
                tab[*i][*j]=D;   /** (v) **/
            }
        }
        else if(*ant==52)
        {
            if(tab[*i][*j+1]!=P&&tab[*i][*j+1]!=M)
            {
                *pos=tab[*i][*j+1];
                tab[*i][*j]=53;
                *ant=*pos;
                *j=*j+1;
                tab[*i][*j]=D;   /** (v) **/
            }
        }
        else if(*ant==53)
        {
            if(tab[*i][*j+1]!=P&&tab[*i][*j+1]!=M)
            {
                *pos=tab[*i][*j+1];
                tab[*i][*j]=54;
                *ant=*pos;
                *j=*j+1;
                tab[*i][*j]=D;   /** (v) **/
            }
        }
        else if(*ant==54)
        {
            if(tab[*i][*j+1]!=P&&tab[*i][*j+1]!=M)
            {
                *pos=tab[*i][*j+1];
                tab[*i][*j]=55;
                *ant=*pos;
                *j=*j+1;
                tab[*i][*j]=D;   /** (v) **/
            }
        }
        else if(*ant==55)
        {
            if(tab[*i][*j+1]!=P&&tab[*i][*j+1]!=M)
            {
                *pos=tab[*i][*j+1];
                tab[*i][*j]=56;
                *ant=*pos;
                *j=*j+1;
                tab[*i][*j]=D;   /** (v) **/
            }
        }
        else if(*ant==56)
        {
            if(tab[*i][*j+1]!=P&&tab[*i][*j+1]!=M)
            {
                *pos=tab[*i+1][*j];
                tab[*i][*j]=57;
                *ant=*pos;
                *j=*j+1;
                tab[*i][*j]=D;   /** (v) **/
            }
        }
        else if(*ant==57)
        {
            if(tab[*i+1][*j]!=P&&tab[*i][*j+1]!=M)
            {
                *pos=tab[*i][*j+1];
                tab[*i][*j]=43;
                *ant=*pos;
                *j=*j+1;
                tab[*i][*j]=D;   /** (v) **/
            }
        }
        else if(*ant==43)
        {
            if(tab[*i][*j+1]!=P&&tab[*i][*j+1]!=M)
            {
                *pos=tab[*i][*j+1];
                tab[*i][*j]=43;
                *ant=*pos;
                *j=*j+1;
                tab[*i][*j]=D;   /** (v) **/
            }
        }
        punto->nivel=punto->nivel+1;
        punto->total=punto->total+1;
    }
    if(ras=='2')
    {
         if(tab[*i][*j+1]==32)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=46;   /** (PUNTO) **/
            *j=*j+1;
            tab[*i][*j]=D;   /** (>) **/
        }
        else if(tab[*i][*j+1]==46)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=46;
            *j=*j+1;
            tab[*i][*j]=D;
        }
    }
    else if(ras=='3')
    {
        if(tab[*i][*j+1]==32)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=32;   /** (ESPACIO) **/
            *j=*j+1;
            tab[*i][*j]=D;   /** (v) **/
        }
    }
    pasos->derecha=pasos->derecha+1;
    if(niv=='1')
        imprimir_df (tab,nom,*punto,*pasos,*i,*j);
    else if(niv=='2')
        imprimir_dm (tab,nom,*punto,*pasos,*i,*j);
    else if(niv=='3')
        imprimir_dd (tab,nom,*punto,*pasos,*i,*j);
}
void derecha_f (char tab[IF][JF],jug nom,punt*punto,pas*pasos,int*i,int*j,char niv,char ras,char*ant,char*pos)
{
    system("cls");
    if(tab[*i][*j+1]==P)        /**  LIMITE  **/
    {
        pasos->limite=pasos->limite+1;
        punto->nivel=punto->nivel+5;
        punto->total=punto->total+5;
        tab[*i][*j]=D;   /** (>) **/
    }
    else if(tab[*i][*j+1]==M)   /**  MURO  **/
    {
        pasos->muro=pasos->muro+1;
        punto->nivel=punto->nivel+3;
        punto->total=punto->total+3;
        tab[*i][*j]=D;   /** (>) **/

    }
    else if(tab[*i][*j+1]==70)   /**  FINAL  **/
    {
        punto->nivel=punto->nivel+1;
        punto->total=punto->total+1;
        tab[*i][*j]=46;
        *j=*j+1;
        tab[*i][*j]=D;   /** (>) **/
    }
    if(ras=='1')        /** RASTRO FACIL  **/
    {
        if(*ant==0)
        {
            if(tab[*i][*j+1]!=P&&tab[*i][*j+1]!=M)
            {
                *ant=32;
                *pos=tab[*i][*j+1];
            }
            if (*ant==32)
            {
                tab[*i][*j]=46;
                *ant=*pos;
                *j=*j+1;
                tab[*i][*j]=D;   /** (v) **/
            }
        }
        else if(*ant==32)
        {
            if(tab[*i][*j+1]!=P&&tab[*i][*j+1]!=M)
            {
                *pos=tab[*i][*j+1];
                tab[*i][*j]=46;
                *ant=*pos;
                *j=*j+1;
                tab[*i][*j]=D;   /** (v) **/
            }
        }
        else if(*ant==46)
        {
            if(tab[*i][*j+1]!=P&&tab[*i][*j+1]!=M)
            {
                *pos=tab[*i][*j+1];
                tab[*i][*j]=50;
                *ant=*pos;
                *j=*j+1;
                tab[*i][*j]=D;   /** (v) **/
            }
        }
        else if(*ant==50)
        {
            if(tab[*i][*j+1]!=P&&tab[*i][*j+1]!=M)
            {
                *pos=tab[*i][*j+1];
                tab[*i][*j]=51;
                *ant=*pos;
                *j=*j+1;
                tab[*i][*j]=D;   /** (v) **/
            }
        }
        else if(*ant==51)
        {
            if(tab[*i][*j+1]!=P&&tab[*i][*j+1]!=M)
            {
                *pos=tab[*i][*j+1];
                tab[*i][*j]=52;
                *ant=*pos;
                *j=*j+1;
                tab[*i][*j]=D;   /** (v) **/
            }
        }
        else if(*ant==52)
        {
            if(tab[*i][*j+1]!=P&&tab[*i][*j+1]!=M)
            {
                *pos=tab[*i][*j+1];
                tab[*i][*j]=53;
                *ant=*pos;
                *j=*j+1;
                tab[*i][*j]=D;   /** (v) **/
            }
        }
        else if(*ant==53)
        {
            if(tab[*i][*j+1]!=P&&tab[*i][*j+1]!=M)
            {
                *pos=tab[*i][*j+1];
                tab[*i][*j]=54;
                *ant=*pos;
                *j=*j+1;
                tab[*i][*j]=D;   /** (v) **/
            }
        }
        else if(*ant==54)
        {
            if(tab[*i][*j+1]!=P&&tab[*i][*j+1]!=M)
            {
                *pos=tab[*i][*j+1];
                tab[*i][*j]=55;
                *ant=*pos;
                *j=*j+1;
                tab[*i][*j]=D;   /** (v) **/
            }
        }
        else if(*ant==55)
        {
            if(tab[*i][*j+1]!=P&&tab[*i][*j+1]!=M)
            {
                *pos=tab[*i][*j+1];
                tab[*i][*j]=56;
                *ant=*pos;
                *j=*j+1;
                tab[*i][*j]=D;   /** (v) **/
            }
        }
        else if(*ant==56)
        {
            if(tab[*i][*j+1]!=P&&tab[*i][*j+1]!=M)
            {
                *pos=tab[*i+1][*j];
                tab[*i][*j]=57;
                *ant=*pos;
                *j=*j+1;
                tab[*i][*j]=D;   /** (v) **/
            }
        }
        else if(*ant==57)
        {
            if(tab[*i+1][*j]!=P&&tab[*i][*j+1]!=M)
            {
                *pos=tab[*i][*j+1];
                tab[*i][*j]=43;
                *ant=*pos;
                *j=*j+1;
                tab[*i][*j]=D;   /** (v) **/
            }
        }
        else if(*ant==43)
        {
            if(tab[*i][*j+1]!=P&&tab[*i][*j+1]!=M)
            {
                *pos=tab[*i][*j+1];
                tab[*i][*j]=43;
                *ant=*pos;
                *j=*j+1;
                tab[*i][*j]=D;   /** (v) **/
            }
        }
        punto->nivel=punto->nivel+1;
        punto->total=punto->total+1;
    }
    if(ras=='2')
    {
         if(tab[*i][*j+1]==32)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=46;   /** (PUNTO) **/
            *j=*j+1;
            tab[*i][*j]=D;   /** (>) **/
        }
        else if(tab[*i][*j+1]==46)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=46;
            *j=*j+1;
            tab[*i][*j]=D;
        }
    }
    else if(ras=='3')
    {
        if(tab[*i][*j+1]==32)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=32;   /** (ESPACIO) **/
            *j=*j+1;
            tab[*i][*j]=D;   /** (v) **/
        }
    }
    pasos->derecha=pasos->derecha+1;
    if(niv=='1')
        imprimir_f (tab,nom,*punto,*pasos,*i,*j);
    else if(niv=='2')
        imprimir_m (tab,nom,*punto,*pasos,*i,*j);
    else if(niv=='3')
        imprimir_d (tab,nom,*punto,*pasos,*i,*j);
}
void derecha_m (char tab[IM][JM],jug nom,punt*punto,pas*pasos,int*i,int*j,char niv,char ras,char*ant,char*pos)
{
    system("cls");
    if(tab[*i][*j+1]==P)        /**  LIMITE  **/
    {
        pasos->limite=pasos->limite+1;
        punto->nivel=punto->nivel+5;
        punto->total=punto->total+5;
        tab[*i][*j]=D;   /** (>) **/
    }
    else if(tab[*i][*j+1]==M)   /**  MURO  **/
    {
        pasos->muro=pasos->muro+1;
        punto->nivel=punto->nivel+3;
        punto->total=punto->total+3;
        tab[*i][*j]=D;   /** (>) **/

    }
    else if(tab[*i][*j+1]==70)   /**  FINAL  **/
    {
        punto->nivel=punto->nivel+1;
        punto->total=punto->total+1;
        tab[*i][*j]=46;
        *j=*j+1;
        tab[*i][*j]=D;   /** (>) **/
    }
    if(ras=='1')        /** RASTRO FACIL  **/
    {
        if(*ant==0)
        {
            if(tab[*i][*j+1]!=P&&tab[*i][*j+1]!=M)
            {
                *ant=32;
                *pos=tab[*i][*j+1];
            }
            if (*ant==32)
            {
                tab[*i][*j]=46;
                *ant=*pos;
                *j=*j+1;
                tab[*i][*j]=D;   /** (v) **/
            }
        }
        else if(*ant==32)
        {
            if(tab[*i][*j+1]!=P&&tab[*i][*j+1]!=M)
            {
                *pos=tab[*i][*j+1];
                tab[*i][*j]=46;
                *ant=*pos;
                *j=*j+1;
                tab[*i][*j]=D;   /** (v) **/
            }
        }
        else if(*ant==46)
        {
            if(tab[*i][*j+1]!=P&&tab[*i][*j+1]!=M)
            {
                *pos=tab[*i][*j+1];
                tab[*i][*j]=50;
                *ant=*pos;
                *j=*j+1;
                tab[*i][*j]=D;   /** (v) **/
            }
        }
        else if(*ant==50)
        {
            if(tab[*i][*j+1]!=P&&tab[*i][*j+1]!=M)
            {
                *pos=tab[*i][*j+1];
                tab[*i][*j]=51;
                *ant=*pos;
                *j=*j+1;
                tab[*i][*j]=D;   /** (v) **/
            }
        }
        else if(*ant==51)
        {
            if(tab[*i][*j+1]!=P&&tab[*i][*j+1]!=M)
            {
                *pos=tab[*i][*j+1];
                tab[*i][*j]=52;
                *ant=*pos;
                *j=*j+1;
                tab[*i][*j]=D;   /** (v) **/
            }
        }
        else if(*ant==52)
        {
            if(tab[*i][*j+1]!=P&&tab[*i][*j+1]!=M)
            {
                *pos=tab[*i][*j+1];
                tab[*i][*j]=53;
                *ant=*pos;
                *j=*j+1;
                tab[*i][*j]=D;   /** (v) **/
            }
        }
        else if(*ant==53)
        {
            if(tab[*i][*j+1]!=P&&tab[*i][*j+1]!=M)
            {
                *pos=tab[*i][*j+1];
                tab[*i][*j]=54;
                *ant=*pos;
                *j=*j+1;
                tab[*i][*j]=D;   /** (v) **/
            }
        }
        else if(*ant==54)
        {
            if(tab[*i][*j+1]!=P&&tab[*i][*j+1]!=M)
            {
                *pos=tab[*i][*j+1];
                tab[*i][*j]=55;
                *ant=*pos;
                *j=*j+1;
                tab[*i][*j]=D;   /** (v) **/
            }
        }
        else if(*ant==55)
        {
            if(tab[*i][*j+1]!=P&&tab[*i][*j+1]!=M)
            {
                *pos=tab[*i][*j+1];
                tab[*i][*j]=56;
                *ant=*pos;
                *j=*j+1;
                tab[*i][*j]=D;   /** (v) **/
            }
        }
        else if(*ant==56)
        {
            if(tab[*i][*j+1]!=P&&tab[*i][*j+1]!=M)
            {
                *pos=tab[*i+1][*j];
                tab[*i][*j]=57;
                *ant=*pos;
                *j=*j+1;
                tab[*i][*j]=D;   /** (v) **/
            }
        }
        else if(*ant==57)
        {
            if(tab[*i+1][*j]!=P&&tab[*i][*j+1]!=M)
            {
                *pos=tab[*i][*j+1];
                tab[*i][*j]=43;
                *ant=*pos;
                *j=*j+1;
                tab[*i][*j]=D;   /** (v) **/
            }
        }
        else if(*ant==43)
        {
            if(tab[*i][*j+1]!=P&&tab[*i][*j+1]!=M)
            {
                *pos=tab[*i][*j+1];
                tab[*i][*j]=43;
                *ant=*pos;
                *j=*j+1;
                tab[*i][*j]=D;   /** (v) **/
            }
        }
        punto->nivel=punto->nivel+1;
        punto->total=punto->total+1;
    }
    else if(ras=='2')
    {
         if(tab[*i][*j+1]==32)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=46;   /** (PUNTO) **/
            *j=*j+1;
            tab[*i][*j]=D;   /** (>) **/
        }
        else if(tab[*i][*j+1]==46)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=46;
            *j=*j+1;
            tab[*i][*j]=D;
        }
    }
    else if(ras=='3')
    {
        if(tab[*i][*j+1]==32)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=32;   /** (ESPACIO) **/
            *j=*j+1;
            tab[*i][*j]=D;   /** (v) **/
        }
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
    punto.res=IF*JF-punto.nivel;
    printf("\n\n\t\tNOMBRE: %s",nom.nombre);
    printf("\n\n\t\tPUNTOS NIVEL: %d",punto.nivel);
    printf("\n\n\t\tPUNTOS TOTALES: %d",punto.total);
    printf("\n\n\t\tPUNTOS RESTANTES; %d",punto.res);
    printf("\n\n\t\tPASOS HACIA ARRIBA; %d",pasos.arriba);
    printf("\n\n\t\tPASOS HACIA ABAJO; %d",pasos.abajo);
    printf("\n\n\t\tPASOS HACIA DERECHA; %d",pasos.derecha);
    printf("\n\n\t\tPASOS HACIA IZQUIERDA; %d",pasos.izquierda);
    printf("\n\n\t\tPASOS CONTRA UN MURO; %d",pasos.muro);
    printf("\n\n\t\tPASOS CONTRA UN LIMITE; %d",pasos.limite);
    printf("\n\n\t\tPULSE * PARA SALIR");
}
void imprimir_dd (char tablero[ID][JD],jug nom,punt punto,pas pasos,int i,int j)   /**IMPRIMIR DIFICI DIFIL**/
{
    int fil,col;
    system("cls");
    printf("\n\n\n\n\n\n");
    for(fil=i-2;fil<=i+2;fil++)
    {
        printf("\t\t\t");
        for(col=j-2;col<=j+2;col++)
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
    punto.res=JD*ID-punto.nivel;
    printf("\n\n\t\tNOMBRE: %s",nom.nombre);
    printf("\n\n\t\tPUNTOS NIVEL: %d",punto.nivel);
    printf("\n\n\t\tPUNTOS TOTALES: %d",punto.total);
    printf("\n\n\t\tPUNTOS RESTANTES; %d",punto.res);
    printf("\n\n\t\tPASOS HACIA ARRIBA; %d",pasos.arriba);
    printf("\n\n\t\tPASOS HACIA ABAJO; %d",pasos.abajo);
    printf("\n\n\t\tPASOS HACIA DERECHA; %d",pasos.derecha);
    printf("\n\n\t\tPASOS HACIA IZQUIERDA; %d",pasos.izquierda);
    printf("\n\n\t\tPASOS CONTRA UN MURO; %d",pasos.muro);
    printf("\n\n\t\tPASOS CONTRA UN LIMITE; %d",pasos.limite);
    printf("\n\n\t\tPULSE * PARA SALIR");
}
void imprimir_df (char tablero[ID][JD],jug nom,punt punto,pas pasos,int i,int j)   /**IMPRIMIR DIFICIL FACIL**/
{
    int fil,col;
    system("cls");
    printf("\n\n\n\n\n\n");
    for(fil=i-4;fil<=i+4;fil++)
    {
        printf("\t\t\t");
        for(col=j-4;col<=j+4;col++)
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
    punto.res=JD*ID-punto.nivel;
    printf("\n\n\t\tNOMBRE: %s",nom.nombre);
    printf("\n\n\t\tPUNTOS NIVEL: %d",punto.nivel);
    printf("\n\n\t\tPUNTOS TOTALES: %d",punto.total);
    printf("\n\n\t\tPUNTOS RESTANTES; %d",punto.res);
    printf("\n\n\t\tPASOS HACIA ARRIBA; %d",pasos.arriba);
    printf("\n\n\t\tPASOS HACIA ABAJO; %d",pasos.abajo);
    printf("\n\n\t\tPASOS HACIA DERECHA; %d",pasos.derecha);
    printf("\n\n\t\tPASOS HACIA IZQUIERDA; %d",pasos.izquierda);
    printf("\n\n\t\tPASOS CONTRA UN MURO; %d",pasos.muro);
    printf("\n\n\t\tPASOS CONTRA UN LIMITE; %d",pasos.limite);
    printf("\n\n\t\tPULSE * PARA SALIR");
}
void imprimir_dm (char tablero[ID][JD],jug nom,punt punto,pas pasos,int i,int j)   /**IMPRIMIR DIFICIL MEDIO**/
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
    punto.res=JD*ID-punto.nivel;
    printf("\n\n\t\tNOMBRE: %s",nom.nombre);
    printf("\n\n\t\tPUNTOS NIVEL: %d",punto.nivel);
    printf("\n\n\t\tPUNTOS TOTALES: %d",punto.total);
    printf("\n\n\t\tPUNTOS RESTANTES; %d",punto.res);
    printf("\n\n\t\tPASOS HACIA ARRIBA; %d",pasos.arriba);
    printf("\n\n\t\tPASOS HACIA ABAJO; %d",pasos.abajo);
    printf("\n\n\t\tPASOS HACIA DERECHA; %d",pasos.derecha);
    printf("\n\n\t\tPASOS HACIA IZQUIERDA; %d",pasos.izquierda);
    printf("\n\n\t\tPASOS CONTRA UN MURO; %d",pasos.muro);
    printf("\n\n\t\tPASOS CONTRA UN LIMITE; %d",pasos.limite);
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
    punto.res=IF*JF-punto.nivel;
    printf("\n\n\t\tNOMBRE: %s",nom.nombre);
    printf("\n\n\t\tPUNTOS NIVEL: %d",punto.nivel);
    printf("\n\n\t\tPUNTOS TOTALES: %d",punto.total);
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
    punto.res=IF*JF-punto.nivel;
    printf("\n\n\t\tNOMBRE: %s",nom.nombre);
    printf("\n\n\t\tPUNTOS NIVEL: %d",punto.nivel);
    printf("\n\n\t\tPUNTOS TOTALES: %d",punto.total);
    printf("\n\n\t\tPUNTOS RESTANTES; %d",punto.res);
    printf("\n\n\t\tPASOS HACIA ARRIBA; %d",pasos.arriba);
    printf("\n\n\t\tPASOS HACIA ABAJO; %d",pasos.abajo);
    printf("\n\n\t\tPASOS HACIA DERECHA; %d",pasos.derecha);
    printf("\n\n\t\tPASOS HACIA IZQUIERDA; %d",pasos.izquierda);
    printf("\n\n\t\tPASOS CONTRA UN MURO; %d",pasos.muro);
    printf("\n\n\t\tPASOS CONTRA UN LIMITE; %d",pasos.limite);
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
    punto.res=IM*JM-punto.nivel;
    printf("\n\n\t\tNOMBRE: %s",nom.nombre);
    printf("\n\n\t\tPUNTOS NIVEL: %d",punto.nivel);
    printf("\n\n\t\tPUNTOS TOTALES: %d",punto.total);
    printf("\n\n\t\tPUNTOS RESTANTES; %d",punto.res);
    printf("\n\n\t\tPASOS HACIA ARRIBA; %d",pasos.arriba);
    printf("\n\n\t\tPASOS HACIA ABAJO; %d",pasos.abajo);
    printf("\n\n\t\tPASOS HACIA DERECHA; %d",pasos.derecha);
    printf("\n\n\t\tPASOS HACIA IZQUIERDA; %d",pasos.izquierda);
    printf("\n\n\t\tPASOS CONTRA UN MURO; %d",pasos.muro);
    printf("\n\n\t\tPASOS CONTRA UN LIMITE; %d",pasos.limite);
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
    punto.res=IM*JM-punto.nivel;
    printf("\n\n\t\tNOMBRE: %s",nom.nombre);
    printf("\n\n\t\tPUNTOS NIVEL: %d",punto.nivel);
    printf("\n\n\t\tPUNTOS TOTALES: %d",punto.total);
    printf("\n\n\t\tPUNTOS RESTANTES; %d",punto.res);
    printf("\n\n\t\tPASOS HACIA ARRIBA; %d",pasos.arriba);
    printf("\n\n\t\tPASOS HACIA ABAJO; %d",pasos.abajo);
    printf("\n\n\t\tPASOS HACIA DERECHA; %d",pasos.derecha);
    printf("\n\n\t\tPASOS HACIA IZQUIERDA; %d",pasos.izquierda);
    printf("\n\n\t\tPASOS CONTRA UN MURO; %d",pasos.muro);
    printf("\n\n\t\tPASOS CONTRA UN LIMITE; %d",pasos.limite);
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
    punto.res=IM*JM-punto.nivel;
    printf("\n\n\t\tNOMBRE: %s",nom.nombre);
    printf("\n\n\t\tPUNTOS NIVEL: %d",punto.nivel);
    printf("\n\n\t\tPUNTOS TOTALES: %d",punto.total);
    printf("\n\n\t\tPUNTOS RESTANTES; %d",punto.res);
    printf("\n\n\t\tPASOS HACIA ARRIBA; %d",pasos.arriba);
    printf("\n\n\t\tPASOS HACIA ABAJO; %d",pasos.abajo);
    printf("\n\n\t\tPASOS HACIA DERECHA; %d",pasos.derecha);
    printf("\n\n\t\tPASOS HACIA IZQUIERDA; %d",pasos.izquierda);
    printf("\n\n\t\tPASOS CONTRA UN MURO; %d",pasos.muro);
    printf("\n\n\t\tPASOS CONTRA UN LIMITE; %d",pasos.limite);
    printf("\n\n\t\tPULSE * PARA SALIR");
}
void iniciar_v (jug*jugador,punt*puntos,pas*pasos)
{
    jugador->puntaje=0;
    puntos->nivel=0;
    puntos->res=0;
    pasos->derecha=0;
    pasos->izquierda=0;
    pasos->arriba=0;
    pasos->abajo=0;
    pasos->muro=0;
    pasos->limite=0;
}
void izquierda_d (char tab[ID][JD],jug nom,punt*punto,pas*pasos,int*i,int*j,char niv,char ras,char*ant,char*pos)
{
    system("cls");
    if(tab[*i][*j-1]==P)        /**  LIMITE  **/
    {
        pasos->limite=pasos->limite+1;
        punto->nivel=punto->nivel+5;
        punto->total=punto->total+5;
        tab[*i][*j]=A;   /** (<) **/
    }
    else if(tab[*i][*j-1]==M)   /**  MURO  **/
    {
        pasos->muro=pasos->muro+1;
        punto->nivel=punto->nivel+3;
        punto->total=punto->total+3;
        tab[*i][*j]=A;   /** (<) **/
    }
    else if(tab[*i][*j-1]==70)   /**  FINAL  **/
    {
        punto->nivel=punto->nivel+1;
        punto->total=punto->total+1;
        tab[*i][*j]=D;   /** (>) **/
    }
    if(ras=='1')        /** RASTRO FACIL  **/
    {
        if(*ant==0)
        {
            if(tab[*i][*j-1]!=P&&tab[*i][*j-1]!=M)
            {
                *ant=32;
                *pos=tab[*i][*j-1];
            }
            if (*ant==32)
            {
                tab[*i][*j]=46;
                *ant=*pos;
                *j=*j-1;
                tab[*i][*j]=A;   /** (v) **/
            }
        }
        else if(*ant==32)
        {
            if(tab[*i][*j-1]!=P&&tab[*i][*j-1]!=M)
            {
                *pos=tab[*i][*j-1];
                tab[*i][*j]=46;
                *ant=*pos;
                *j=*j-1;
                tab[*i][*j]=A;   /** (v) **/
            }
        }
        else if(*ant==46)
        {
            if(tab[*i][*j-1]!=P&&tab[*i][*j-1]!=M)
            {
                *pos=tab[*i][*j-1];
                tab[*i][*j]=50;
                *ant=*pos;
                *j=*j-1;
                tab[*i][*j]=A;   /** (v) **/
            }
        }
        else if(*ant==50)
        {
            if(tab[*i][*j-1]!=P&&tab[*i][*j-1]!=M)
            {
                *pos=tab[*i][*j-1];
                tab[*i][*j]=51;
                *ant=*pos;
                *j=*j-1;
                tab[*i][*j]=A;   /** (v) **/
            }
        }
        else if(*ant==51)
        {
            if(tab[*i][*j-1]!=P&&tab[*i][*j-1]!=M)
            {
                *pos=tab[*i][*j-1];
                tab[*i][*j]=52;
                *ant=*pos;
                *j=*j-1;
                tab[*i][*j]=A;   /** (v) **/
            }
        }
        else if(*ant==52)
        {
            if(tab[*i][*j-1]!=P&&tab[*i][*j-1]!=M)
            {
                *pos=tab[*i][*j-1];
                tab[*i][*j]=53;
                *ant=*pos;
                *j=*j-1;
                tab[*i][*j]=A;   /** (v) **/
            }
        }
        else if(*ant==53)
        {
            if(tab[*i][*j-1]!=P&&tab[*i][*j-1]!=M)
            {
                *pos=tab[*i][*j-1];
                tab[*i][*j]=54;
                *ant=*pos;
                *j=*j-1;
                tab[*i][*j]=A;   /** (v) **/
            }
        }
        else if(*ant==54)
        {
            if(tab[*i][*j-1]!=P&&tab[*i][*j-1]!=M)
            {
                *pos=tab[*i][*j-1];
                tab[*i][*j]=55;
                *ant=*pos;
                *j=*j-1;
                tab[*i][*j]=A;   /** (v) **/
            }
        }
        else if(*ant==55)
        {
            if(tab[*i][*j-1]!=P&&tab[*i][*j-1]!=M)
            {
                *pos=tab[*i][*j-1];
                tab[*i][*j]=56;
                *ant=*pos;
                *j=*j-1;
                tab[*i][*j]=A;   /** (v) **/
            }
        }
        else if(*ant==56)
        {
            if(tab[*i][*j+1]!=P&&tab[*i][*j-1]!=M)
            {
                *pos=tab[*i-1][*j];
                tab[*i][*j]=57;
                *ant=*pos;
                *j=*j-1;
                tab[*i][*j]=A;   /** (v) **/
            }
        }
        else if(*ant==57)
        {
            if(tab[*i-1][*j]!=P&&tab[*i][*j-1]!=M)
            {
                *pos=tab[*i][*j-1];
                tab[*i][*j]=43;
                *ant=*pos;
                *j=*j-1;
                tab[*i][*j]=A;   /** (v) **/
            }
        }
        else if(*ant==43)
        {
            if(tab[*i][*j-1]!=P&&tab[*i][*j-1]!=M)
            {
                *pos=tab[*i][*j-1];
                tab[*i][*j]=43;
                *ant=*pos;
                *j=*j-1;
                tab[*i][*j]=A;   /** (v) **/
            }
        }
        punto->nivel=punto->nivel+1;
        punto->total=punto->total+1;
    }
    if(ras=='2')
    {
         if(tab[*i][*j-1]==32)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=46;   /** (PUNTO) **/
            *j=*j-1;
            tab[*i][*j]=A;   /** (<) **/
        }
        else if(tab[*i][*j-1]==46)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=46;
            *j=*j-1;
            tab[*i][*j]=A;
        }
    }
    else if(ras=='3')
    {
        if(tab[*i][*j-1]==32)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=32;   /** (ESPACIO) **/
            *j=*j-1;
            tab[*i][*j]=A;   /** (<) **/
        }
    }
    pasos->izquierda=pasos->izquierda+1;
    if(niv=='1')
        imprimir_df (tab,nom,*punto,*pasos,*i,*j);
    else if(niv=='2')
        imprimir_dm (tab,nom,*punto,*pasos,*i,*j);
    else if(niv=='3')
        imprimir_dd (tab,nom,*punto,*pasos,*i,*j);
}
void izquierda_f (char tab[IF][JF],jug nom,punt*punto,pas*pasos,int*i,int*j,char niv,char ras,char*ant,char*pos)
{
    system("cls");
    if(tab[*i][*j-1]==P)        /**  LIMITE  **/
    {
        pasos->limite=pasos->limite+1;
        punto->nivel=punto->nivel+5;
        punto->total=punto->total+5;
        tab[*i][*j]=A;   /** (<) **/
    }
    else if(tab[*i][*j-1]==M)   /**  MURO  **/
    {
        pasos->muro=pasos->muro+1;
        punto->nivel=punto->nivel+3;
        punto->total=punto->total+3;
        tab[*i][*j]=A;   /** (<) **/
    }
    else if(tab[*i][*j-1]==70)   /**  FINAL  **/
    {
        punto->nivel=punto->nivel+1;
        punto->total=punto->total+1;
        tab[*i][*j]=D;   /** (>) **/
    }
    if(ras=='1')        /** RASTRO FACIL  **/
    {
        if(*ant==0)
        {
            if(tab[*i][*j-1]!=P&&tab[*i][*j-1]!=M)
            {
                *ant=32;
                *pos=tab[*i][*j-1];
            }
            if (*ant==32)
            {
                tab[*i][*j]=46;
                *ant=*pos;
                *j=*j-1;
                tab[*i][*j]=A;   /** (v) **/
            }
        }
        else if(*ant==32)
        {
            if(tab[*i][*j-1]!=P&&tab[*i][*j-1]!=M)
            {
                *pos=tab[*i][*j-1];
                tab[*i][*j]=46;
                *ant=*pos;
                *j=*j-1;
                tab[*i][*j]=A;   /** (v) **/
            }
        }
        else if(*ant==46)
        {
            if(tab[*i][*j-1]!=P&&tab[*i][*j-1]!=M)
            {
                *pos=tab[*i][*j-1];
                tab[*i][*j]=50;
                *ant=*pos;
                *j=*j-1;
                tab[*i][*j]=A;   /** (v) **/
            }
        }
        else if(*ant==50)
        {
            if(tab[*i][*j-1]!=P&&tab[*i][*j-1]!=M)
            {
                *pos=tab[*i][*j-1];
                tab[*i][*j]=51;
                *ant=*pos;
                *j=*j-1;
                tab[*i][*j]=A;   /** (v) **/
            }
        }
        else if(*ant==51)
        {
            if(tab[*i][*j-1]!=P&&tab[*i][*j-1]!=M)
            {
                *pos=tab[*i][*j-1];
                tab[*i][*j]=52;
                *ant=*pos;
                *j=*j-1;
                tab[*i][*j]=A;   /** (v) **/
            }
        }
        else if(*ant==52)
        {
            if(tab[*i][*j-1]!=P&&tab[*i][*j-1]!=M)
            {
                *pos=tab[*i][*j-1];
                tab[*i][*j]=53;
                *ant=*pos;
                *j=*j-1;
                tab[*i][*j]=A;   /** (v) **/
            }
        }
        else if(*ant==53)
        {
            if(tab[*i][*j-1]!=P&&tab[*i][*j-1]!=M)
            {
                *pos=tab[*i][*j-1];
                tab[*i][*j]=54;
                *ant=*pos;
                *j=*j-1;
                tab[*i][*j]=A;   /** (v) **/
            }
        }
        else if(*ant==54)
        {
            if(tab[*i][*j-1]!=P&&tab[*i][*j-1]!=M)
            {
                *pos=tab[*i][*j-1];
                tab[*i][*j]=55;
                *ant=*pos;
                *j=*j-1;
                tab[*i][*j]=A;   /** (v) **/
            }
        }
        else if(*ant==55)
        {
            if(tab[*i][*j-1]!=P&&tab[*i][*j-1]!=M)
            {
                *pos=tab[*i][*j-1];
                tab[*i][*j]=56;
                *ant=*pos;
                *j=*j-1;
                tab[*i][*j]=A;   /** (v) **/
            }
        }
        else if(*ant==56)
        {
            if(tab[*i][*j+1]!=P&&tab[*i][*j-1]!=M)
            {
                *pos=tab[*i-1][*j];
                tab[*i][*j]=57;
                *ant=*pos;
                *j=*j-1;
                tab[*i][*j]=A;   /** (v) **/
            }
        }
        else if(*ant==57)
        {
            if(tab[*i-1][*j]!=P&&tab[*i][*j-1]!=M)
            {
                *pos=tab[*i][*j-1];
                tab[*i][*j]=43;
                *ant=*pos;
                *j=*j-1;
                tab[*i][*j]=A;   /** (v) **/
            }
        }
        else if(*ant==43)
        {
            if(tab[*i][*j-1]!=P&&tab[*i][*j-1]!=M)
            {
                *pos=tab[*i][*j-1];
                tab[*i][*j]=43;
                *ant=*pos;
                *j=*j-1;
                tab[*i][*j]=A;   /** (v) **/
            }
        }
        punto->nivel=punto->nivel+1;
        punto->total=punto->total+1;
    }
    if(ras=='2')
    {
         if(tab[*i][*j-1]==32)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=46;   /** (PUNTO) **/
            *j=*j-1;
            tab[*i][*j]=A;   /** (<) **/
        }
        else if(tab[*i][*j-1]==46)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=46;
            *j=*j-1;
            tab[*i][*j]=A;
        }
    }
    else if(ras=='3')
    {
        if(tab[*i][*j-1]==32)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=32;   /** (ESPACIO) **/
            *j=*j-1;
            tab[*i][*j]=A;   /** (<) **/
        }
    }
    pasos->izquierda=pasos->izquierda+1;
    if(niv=='1')
        imprimir_f (tab,nom,*punto,*pasos,*i,*j);
    else if(niv=='2')
        imprimir_m (tab,nom,*punto,*pasos,*i,*j);
    else if(niv=='3')
        imprimir_d (tab,nom,*punto,*pasos,*i,*j);
}
void izquierda_m (char tab[IM][JM],jug nom,punt*punto,pas*pasos,int*i,int*j,char niv,char ras,char*ant,char*pos)
{
    system("cls");
    if(tab[*i][*j-1]==P)        /**  LIMITE  **/
    {
        pasos->limite=pasos->limite+1;
        punto->nivel=punto->nivel+5;
        punto->total=punto->total+5;
        tab[*i][*j]=A;   /** (<) **/
    }
    else if(tab[*i][*j-1]==M)   /**  MURO  **/
    {
        pasos->muro=pasos->muro+1;
        punto->nivel=punto->nivel+3;
        punto->total=punto->total+3;
        tab[*i][*j]=A;   /** (<) **/
    }
    else if(tab[*i][*j-1]==70)   /**  FINAL  **/
    {
        punto->nivel=punto->nivel+1;
        punto->total=punto->total+1;
        tab[*i][*j]=D;   /** (>) **/
    }
    if(ras=='1')        /** RASTRO FACIL  **/
    {
        if(*ant==0)
        {
            if(tab[*i][*j-1]!=P&&tab[*i][*j-1]!=M)
            {
                *ant=32;
                *pos=tab[*i][*j-1];
            }
            if (*ant==32)
            {
                tab[*i][*j]=46;
                *ant=*pos;
                *j=*j-1;
                tab[*i][*j]=A;   /** (v) **/
            }
        }
        else if(*ant==32)
        {
            if(tab[*i][*j-1]!=P&&tab[*i][*j-1]!=M)
            {
                *pos=tab[*i][*j-1];
                tab[*i][*j]=46;
                *ant=*pos;
                *j=*j-1;
                tab[*i][*j]=A;   /** (v) **/
            }
        }
        else if(*ant==46)
        {
            if(tab[*i][*j-1]!=P&&tab[*i][*j-1]!=M)
            {
                *pos=tab[*i][*j-1];
                tab[*i][*j]=50;
                *ant=*pos;
                *j=*j-1;
                tab[*i][*j]=A;   /** (v) **/
            }
        }
        else if(*ant==50)
        {
            if(tab[*i][*j-1]!=P&&tab[*i][*j-1]!=M)
            {
                *pos=tab[*i][*j-1];
                tab[*i][*j]=51;
                *ant=*pos;
                *j=*j-1;
                tab[*i][*j]=A;   /** (v) **/
            }
        }
        else if(*ant==51)
        {
            if(tab[*i][*j-1]!=P&&tab[*i][*j-1]!=M)
            {
                *pos=tab[*i][*j-1];
                tab[*i][*j]=52;
                *ant=*pos;
                *j=*j-1;
                tab[*i][*j]=A;   /** (v) **/
            }
        }
        else if(*ant==52)
        {
            if(tab[*i][*j-1]!=P&&tab[*i][*j-1]!=M)
            {
                *pos=tab[*i][*j-1];
                tab[*i][*j]=53;
                *ant=*pos;
                *j=*j-1;
                tab[*i][*j]=A;   /** (v) **/
            }
        }
        else if(*ant==53)
        {
            if(tab[*i][*j-1]!=P&&tab[*i][*j-1]!=M)
            {
                *pos=tab[*i][*j-1];
                tab[*i][*j]=54;
                *ant=*pos;
                *j=*j-1;
                tab[*i][*j]=A;   /** (v) **/
            }
        }
        else if(*ant==54)
        {
            if(tab[*i][*j-1]!=P&&tab[*i][*j-1]!=M)
            {
                *pos=tab[*i][*j-1];
                tab[*i][*j]=55;
                *ant=*pos;
                *j=*j-1;
                tab[*i][*j]=A;   /** (v) **/
            }
        }
        else if(*ant==55)
        {
            if(tab[*i][*j-1]!=P&&tab[*i][*j-1]!=M)
            {
                *pos=tab[*i][*j-1];
                tab[*i][*j]=56;
                *ant=*pos;
                *j=*j-1;
                tab[*i][*j]=A;   /** (v) **/
            }
        }
        else if(*ant==56)
        {
            if(tab[*i][*j+1]!=P&&tab[*i][*j-1]!=M)
            {
                *pos=tab[*i-1][*j];
                tab[*i][*j]=57;
                *ant=*pos;
                *j=*j-1;
                tab[*i][*j]=A;   /** (v) **/
            }
        }
        else if(*ant==57)
        {
            if(tab[*i-1][*j]!=P&&tab[*i][*j-1]!=M)
            {
                *pos=tab[*i][*j-1];
                tab[*i][*j]=43;
                *ant=*pos;
                *j=*j-1;
                tab[*i][*j]=A;   /** (v) **/
            }
        }
        else if(*ant==43)
        {
            if(tab[*i][*j-1]!=P&&tab[*i][*j-1]!=M)
            {
                *pos=tab[*i][*j-1];
                tab[*i][*j]=43;
                *ant=*pos;
                *j=*j-1;
                tab[*i][*j]=A;   /** (v) **/
            }
        }
        punto->nivel=punto->nivel+1;
        punto->total=punto->total+1;
    }
    if(ras=='2')
    {
         if(tab[*i][*j-1]==32)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=46;   /** (PUNTO) **/
            *j=*j-1;
            tab[*i][*j]=A;   /** (<) **/
        }
        else if(tab[*i][*j-1]==46)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=46;
            *j=*j-1;
            tab[*i][*j]=A;
        }
    }
    else if(ras=='3')
    {
        if(tab[*i][*j-1]==32)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=32;   /** (ESPACIO) **/
            *j=*j-1;
            tab[*i][*j]=A;   /** (<) **/
        }
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
    printf("\n\n\n\n\n\n\t\t\t%s ESCOJA EL NIVEL DE JUEGO\n\n\n\t\t\t1.FACIL\n\n\n\t\t\t2.MEDIO\n\n\n\t\t\t3.DIFICIL\n\n\n\t\t\t4.VOLVER AL MENU ANTERIOR\n\n\n\t\t\t",jugador.nombre);
    opc=getch();
    return(opc);
}
void nombre (jug jugador)
{
    int i;
    printf("\n\n\n\n\n\t\t\tPOR FAVOR DIGITE SU NOMBRE: \n\n\t\t\t");
    gets(jugador.nombre);
    for(i = 0; i!=strlen(jugador.nombre); i++)
    {
        jugador.nombre[i] = toupper(jugador.nombre[i]);
    }
    printf("%s",jugador.nombre);
    getch();
}
char rastro (jug jugador)
{
    char opc;
    do
    {
        system("cls");
        printf("\n\n\n\n\n\n\t\t\t%s ESCOJA EL TIPO DE RASTRO\n\n\n\t\t\t1.FACIL\n\n\n\t\t\t2.MEDIO\n\n\n\t\t\t3.DIFICIL\n\n\n\t\t\t4.VOLVER AL MENU ANTERIOR\n\n\n\t\t\t",jugador.nombre);
        opc=getch();
    }while(opc=='1'&&opc=='2'&&opc=='3'&&opc=='4');
    return(opc);
    system("cls");
}
char tama_o (jug jugador)
{
    char opc;
    system("cls");
    printf("\n\n\n\n\n\n\t\t\t%s ESCOJA EL TAMAnO DEL JUEGO\n\n\n\t\t\t1.FACIL\n\n\n\t\t\t2.MEDIO\n\n\n\t\t\t3.DIFICIL\n\n\n\t\t\t4.VOLVER AL MENU ANTERIOR\n\n\n\t\t\t",jugador.nombre);
    opc=getch();
    return(opc);
    system("cls");
}
