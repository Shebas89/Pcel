

/*********************+
*     LIBRERIAS       *
+*********************/

# include <time.h>          /**   TIEMPO       **/
# include <conio.h>        /**   TECLADO      **/
# include <stdio.h>       /**   BASICA       **/
# include <ctype.h>      /**   MAYUSCULAS   **/
# include <stdlib.h>    /**   LIMPIAR      **/
# include <string.h>   /**   CADENAS      **/

/*********************+
*     CONSTANTES      *
+*********************/

# define JF 10                              /**  Columnas Facil    **/
# define IF 10                             /**  Filas Facil       **/
# define JM 15                            /**  Columnas Mediano  **/
# define IM 40                           /**  Filas Mediano     **/
# define JD 40                          /**  Columnas Dificil  **/
# define ID 60                         /**  Filas Dificil     **/
# define W 94                         /**  Arriba            **/
# define P 64                        /**  Paredes           **/
# define M 42                       /**  Muros             **/
# define S 118                     /**  Abajo             **/
# define A 60                     /**  Derecha           **/
# define D 62                    /**  Izquierda         **/
# define E 32                   /**  Espacio Vacio     **/
# define NOM 50                /**  Nombre            **/
# define NUM 30               /**  Jugadores         **/
# define UNO 49              /**  ("1")             **/
# define DOS 50             /**  ("2")             **/
# define TRES 51           /**  ("3")             **/
# define CUATRO 52        /**  ("4")             **/
# define CINCO 53        /**  ("5")             **/
# define SEIS 54        /**  ("6")             **/
# define SIETE 55      /**  ("7")             **/
# define OCHO 56      /**  ("8")             **/
# define NUEVE 57    /**  ("9")             **/
# define PUNTO 46   /**  (".")             **/
# define F 70      /**  ("FINAL")         **/
# define MAS 43   /**  ("+")             **/
# define PAR 16  /**  Partidas Niveles  **/

/*********************+
*     ESTRUCTURAS     *
+*********************/

struct jugador      /** DATOS DEL JUGADOR  **/
{
    char nombre[NOM];
    int puntaje;
    int fecha;
    int duracion;
};

typedef struct jugador jug ;        /**-- TIPO DE VARIABLE "jug" --**/

struct puntaje     /** PUNTAJES DEL JUEGO **/
{
    int total;
    int nivel;
    int res;
};

typedef struct puntaje punt;        /**-- TIPO DE VARIABLE "punt" --**/

struct pasos      /** PASOS EN EL JUEGO  **/
{
    int derecha;
    int izquierda;
    int arriba;
    int abajo;
    int muro;
    int limite;
};

typedef struct pasos pas;        /**-- TIPO DE VARIABLE "pas" ---*/

struct mejores_puntos      /** mejores puntajes EN EL JUEGO  **/
{
    int m_puntos_n;
    int m_puntos_t;
    char nom[NOM];
};

typedef struct mejores_puntos puntos;

struct juego
{
    puntos puntajes[PAR];
    jug jugadores[NUM];
    puntos punta[6];
    int table;
    int niveles[3];
    int unico;
};

typedef struct juego adm;

/*********************+
*     PROTOTIPOS      *
+*********************/

void abajo_d (char [ID][JD],jug,punt*,pas*,int*,int*,char,char);
void abajo_f (char [IF][JF],jug,punt*,pas*,int*,int*,char,char);
void abajo_m (char [IM][JM],jug,punt*,pas*,int*,int*,char,char);
void arriba_d (char [ID][JD],jug,punt*,pas*,int*,int*,char,char);
void arriba_f (char [IF][JF],jug,punt*,pas*,int*,int*,char,char);
void arriba_m (char [IM][JM],jug,punt*,pas*,int*,int*,char,char);
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
void cargar_puntajes (adm*);
void c_m_p (adm*);
void derecha_d (char [ID][JD],jug,punt*,pas*,int*,int*,char,char);
void derecha_f (char [IF][JF],jug,punt*,pas*,int*,int*,char,char);
void derecha_m (char [IM][JM],jug,punt*,pas*,int*,int*,char,char);
void despedida (void);
void g_p_j (adm);
void guardar_puntos(adm);
void guardar5puntos(adm);
void imprimir_d (char [IF][JF],jug,punt,pas,int,int);
void imprimir_dd (char [ID][JD],jug,punt,pas,int,int);
void imprimir_df (char [ID][JD],jug,punt,pas,int,int);
void imprimir_dm (char [ID][JD],jug,punt,pas,int,int);
void imprimir_f (char [IF][JF],jug,punt,pas,int,int);
void imprimir_m (char [IF][JF],jug,punt,pas,int,int);
void imprimir_md (char [IM][JM],jug,punt,pas,int,int);
void imprimir_mf (char [IM][JM],jug,punt,pas,int,int);
void imprimir_mm (char [IM][JM],jug,punt,pas,int,int);
void iniciar_mp (adm *);
void iniciar_v (jug*,punt*,pas*);
void izquierda_d (char [ID][JD],jug,punt*,pas*,int*,int*,char,char);
void izquierda_f (char [IF][JF],jug,punt*,pas*,int*,int*,char,char);
void izquierda_m (char [IM][JM],jug,punt*,pas*,int*,int*,char,char);
void mejores (adm *, punt,jug);
void mejores5 (adm *, punt,jug);
char menu (void);
char nivel (jug);
void ordenar_mejores(adm *);
void ordenar_mejores5(adm *);
char rastro (jug);
char tama_o (jug);

/*****************************+
*     PROGRAMA PRONCOPAL      *
+*****************************/

main ()
{
    system ("color 1f");
    int i,j,paso;
    char nom[NOM],opc,tam,niv,tab_f[IF][JF],mov,tab_m[IM][JM],tab_d[ID][JD],ras,tos;
    pas pasos;
    jug jugador;
    punt puntos;
    adm juego;
    iniciar_mp(&juego);
    c_m_p (&juego);
    cargar_puntajes (&juego);
    do
    {
        opc=menu();
        switch(opc)
        {
            case UNO:    /** JUGAR **/

                printf("\n\n\n\n\n\t\t\tPOR FAVOR DIGITE SU NOMBRE: \n\n\t\t\t");
                gets(nom);
                puntos.total=0;
                for(i = 0; i < strlen(nom); i++)
                {
                    nom[i] = toupper(nom[i]);
                }
    //          buscar_nom ();
                if(opc==UNO) /**  OJO  **/
                    strcpy(jugador.nombre,nom);

                do
                {
                    tam=tama_o(jugador);
                    switch(tam)
                    {
                        case UNO:         /** TAMAÑO FACIL **/

                            do
                            {
                                niv=nivel(jugador);
                                switch(niv)
                                {
                                    case UNO:        /** NIVEL FACIL **/

                                        iniciar_v(&jugador,&puntos,&pasos);
                                        cargar1(tab_f);
                                        i=1,j=1;        /**  POSICION INICIAL FF  **/
                                        ras=rastro(jugador);
                                        if (ras==CUATRO)
                                            break;
                                        imprimir_f (tab_f,jugador,puntos,pasos,i,j);
                                        do
                                        {
                                            mov=getch();
                                            if(mov=='w'||mov=='W')
                                            {
                                                arriba_f(tab_f,jugador,&puntos,&pasos,&i,&j,niv,ras);
                                            }
                                            else if(mov=='s'||mov=='S')
                                            {
                                                abajo_f(tab_f,jugador,&puntos,&pasos,&i,&j,niv,ras);
                                            }
                                            else if(mov=='d'||mov=='D')
                                            {
                                                derecha_f(tab_f,jugador,&puntos,&pasos,&i,&j,niv,ras);
                                            }
                                            else if(mov=='a'||mov=='A')
                                            {
                                                izquierda_f(tab_f,jugador,&puntos,&pasos,&i,&j,niv,ras);
                                            }
                                        }while(tab_f[8][1]==70&&mov!=42&&puntos.nivel<(IF*JF)/3);

                                        if(tab_f[8][1]!=F)
                                        {
                                            system("cls");
                                            printf("\n\n\n\n\n\n\n\n\n\t\t\tFELICITACIONES.... NIVEL COMPLETO");
                                            paso=1,juego.table=1;
                                            getch();
                                            mejores (&juego,puntos,jugador);
                                        }
                                        else if(puntos.nivel>(IF*JF)/3)
                                        {
                                            system("cls");
                                            printf("\n\n\n\n\n\n\n\n\n\t\tJUEGO INCOMPLETO....INTENTELO DE NUEVO\n\n\n\n\n");
                                            paso=0;
                                            getch();
                                        }
                                        else if(mov==M)
                                        {
                                            system("cls");
                                            printf("\n\n\n\n\n\n\n\n\n\t\tJUEGO INCOMPLETO....INTENTELO DE NUEVO\n\n\n\n\n");
                                            paso=0;
                                            getch();
                                        }
                                        if(paso==0)
                                            break;

                                    case DOS:        /** NIVEL MEDIO **/

                                        if(paso==1)
                                            niv=DOS;
                                        iniciar_v(&jugador,&puntos,&pasos);
                                        cargar2(tab_f);
                                        i=8,j=1;        /**  POSICION INICIAL FM  **/
                                        ras=rastro(jugador);
                                        if (ras==CUATRO)
                                            break;
                                        imprimir_m (tab_f,jugador,puntos,pasos,i,j);
                                        do
                                        {
                                            mov=getch();
                                            if(mov=='w'||mov=='W')
                                            {
                                                arriba_f(tab_f,jugador,&puntos,&pasos,&i,&j,niv,ras);
                                            }
                                            else if(mov=='s'||mov=='S')
                                            {
                                                abajo_f(tab_f,jugador,&puntos,&pasos,&i,&j,niv,ras);
                                            }
                                            else if(mov=='d'||mov=='D')
                                            {
                                                derecha_f(tab_f,jugador,&puntos,&pasos,&i,&j,niv,ras);
                                            }
                                            else if(mov=='a'||mov=='A')
                                            {
                                                izquierda_f(tab_f,jugador,&puntos,&pasos,&i,&j,niv,ras);
                                            }
                                        }while(tab_f[1][8]==70&&mov!=42&&puntos.nivel<(IF*JF)/3);
                                        if(tab_f[1][8]!=F)
                                        {
                                            system("cls");
                                            printf("\n\n\n\n\n\n\n\n\n\t\tFELICITACIONES.... NIVEL COMPLETO");
                                            paso=1,juego.table=1;
                                            getch();
                                            mejores (&juego,puntos,jugador);
                                        }
                                        else if(puntos.nivel>(IF*JF)/3)
                                        {
                                            system("cls");
                                            printf("\n\n\n\n\n\n\n\n\n\t\tJUEGO INCOMPLETO....INTENTELO DE NUEVO\n\n\n\n\n");
                                            paso=0;
                                            getch();
                                        }
                                        else if(mov==M)
                                        {
                                            system("cls");
                                            printf("\n\n\n\n\n\n\n\n\n\t\tJUEGO INCOMPLETO....INTENTELO DE NUEVO\n\n\n\n\n");
                                            paso=0;
                                            getch();
                                        }

                                        if(paso==0)
                                            break;

                                    case TRES:        /** NIVEL DIFICIL **/

                                        if(paso==1)
                                            niv=TRES;
                                        iniciar_v(&jugador,&puntos,&pasos);
                                        cargar3(tab_f);
                                        i=3,j=8;        /**  POSICION INICIAL FD  **/
                                        ras=rastro(jugador);
                                        if (ras==CUATRO)
                                            break;
                                        imprimir_d (tab_f,jugador,puntos,pasos,i,j);
                                        do
                                        {
                                            mov=getch();
                                            if(mov=='w'||mov=='W')
                                            {
                                                arriba_f(tab_f,jugador,&puntos,&pasos,&i,&j,niv,ras);
                                            }
                                            else if(mov=='s'||mov=='S')
                                            {
                                                abajo_f(tab_f,jugador,&puntos,&pasos,&i,&j,niv,ras);
                                            }
                                            else if(mov=='d'||mov=='D')
                                            {
                                                derecha_f(tab_f,jugador,&puntos,&pasos,&i,&j,niv,ras);
                                            }
                                            else if(mov=='a'||mov=='A')
                                            {
                                                izquierda_f(tab_f,jugador,&puntos,&pasos,&i,&j,niv,ras);
                                            }
                                        }while(tab_f[8][2]==70&&mov!=42&&puntos.nivel<(IF*JF)/3);
                                        if(tab_f[8][2]!=F)
                                        {
                                            system("cls");
                                            printf("\n\n\n\n\n\n\n\n\n\t\tFELICITACIONES.... NIVEL COMPLETO");
                                            paso=2,juego.table=1;
                                            getch();
                                            mejores (&juego,puntos,jugador);
                                        }
                                        else if(puntos.nivel>(IF*JF)/3)
                                        {
                                            system("cls");
                                            printf("\n\n\n\n\n\n\n\n\n\t\tJUEGO INCOMPLETO....INTENTELO DE NUEVO\n\n\n\n\n");
                                            paso=0;
                                            getch();
                                        }
                                        else if(mov==M)
                                        {
                                            system("cls");
                                            printf("\n\n\n\n\n\n\n\n\n\t\tJUEGO INCOMPLETO....INTENTELO DE NUEVO\n\n\n\n\n");
                                            paso=0;
                                            getch();
                                        }
                                        if(paso==2)
                                        {
                                            niv=CUATRO;
                                            break;
                                        }
                                        else if(paso==0)
                                            break;
                                }
                            }while(niv!=CUATRO);

                        break;

                        case DOS:       /** TAMAÑO MEDIO **/

                            do
                            {

                                niv=nivel(jugador);
                                switch(niv)
                                {
                                    case UNO:        /** NIVEL FACIL **/

                                        cargar4(tab_m);
                                        iniciar_v(&jugador,&puntos,&pasos);
                                        i=18,j=1;        /**  POSICION INICIAL MF  **/
                                        ras=rastro(jugador);
                                        if (ras==CUATRO)
                                            break;
                                        imprimir_mf (tab_m,jugador,puntos,pasos,i,j);
                                        do
                                        {
                                            mov=getch();
                                            if(mov=='w'||mov=='W')
                                            {
                                                arriba_m(tab_m,jugador,&puntos,&pasos,&i,&j,niv,ras);
                                            }
                                            else if(mov=='s'||mov=='S')
                                            {
                                                abajo_m(tab_m,jugador,&puntos,&pasos,&i,&j,niv,ras);
                                            }
                                            else if(mov=='d'||mov=='D')
                                            {
                                                derecha_m(tab_m,jugador,&puntos,&pasos,&i,&j,niv,ras);
                                            }
                                            else if(mov=='a'||mov=='A')
                                            {
                                                izquierda_m(tab_m,jugador,&puntos,&pasos,&i,&j,niv,ras);
                                            }
                                        }while(tab_m[1][1]==70&&mov!=42&&puntos.nivel<(IM*JM)/3);
                                        if(tab_f[1][1]!=F)
                                        {
                                            system("cls");
                                            printf("\n\n\n\n\n\n\n\n\n\t\tFELICITACIONES.... NIVEL COMPLETO");
                                            paso=2,juego.table=2;
                                            getch();
                                            mejores (&juego,puntos,jugador);
                                        }
                                        else if(puntos.nivel>(IM*JM)/3)
                                        {
                                            system("cls");
                                            printf("\n\n\n\n\n\n\n\n\n\t\tJUEGO INCOMPLETO....INTENTELO DE NUEVO\n\n\n\n\n");
                                            paso=0;
                                            getch();
                                        }
                                        else if(mov==M)
                                        {
                                            system("cls");
                                            printf("\n\n\n\n\n\n\n\n\n\t\tJUEGO INCOMPLETO....INTENTELO DE NUEVO\n\n\n\n\n");
                                            paso=0;
                                            getch();
                                        }
                                        if (paso==0)
                                            break;

                                    case DOS:        /** NIVEL MEDIO **/

                                        if(paso==2)
                                            niv=DOS;
                                        cargar5(tab_m);
                                        i=38,j=7;        /**  POSICION INICIAL MM  **/
                                        ras=rastro(jugador);
                                        iniciar_v(&jugador,&puntos,&pasos);
                                        if (ras==CUATRO)
                                            break;
                                        imprimir_mm (tab_m,jugador,puntos,pasos,i,j);
                                        do
                                        {
                                            mov=getch();
                                            if(mov=='w'||mov=='W')
                                            {
                                                arriba_m(tab_m,jugador,&puntos,&pasos,&i,&j,niv,ras);
                                            }
                                            else if(mov=='s'||mov=='S')
                                            {
                                                abajo_m(tab_m,jugador,&puntos,&pasos,&i,&j,niv,ras);
                                            }
                                            else if(mov=='d'||mov=='D')
                                            {
                                                derecha_m(tab_m,jugador,&puntos,&pasos,&i,&j,niv,ras);
                                            }
                                            else if(mov=='a'||mov=='A')
                                            {
                                                izquierda_m(tab_m,jugador,&puntos,&pasos,&i,&j,niv,ras);
                                            }
                                        }while(tab_m[15][7]==70&&mov!=42&&puntos.nivel<(IM*JM)/3);
                                        if(tab_f[15][7]!=F)
                                        {
                                            system("cls");
                                            printf("\n\n\n\n\n\n\n\n\n\t\tFELICITACIONES.... NIVEL COMPLETO");
                                            paso=2,juego.table=2;
                                            getch();
                                            mejores (&juego,puntos,jugador);
                                        }
                                        else if(puntos.nivel>(IM*JM)/3)
                                        {
                                            system("cls");
                                            printf("\n\n\n\n\n\n\n\n\n\t\tJUEGO INCOMPLETO....INTENTELO DE NUEVO\n\n\n\n\n");
                                            paso=0;
                                            getch();
                                        }
                                        else if(mov==M)
                                        {
                                            system("cls");
                                            printf("\n\n\n\n\n\n\n\n\n\t\tJUEGO INCOMPLETO....INTENTELO DE NUEVO\n\n\n\n\n");
                                            paso=0;
                                            getch();
                                        }

                                        if(paso==0)
                                            break;

                                    case TRES:        /** NIVEL DIFICIL **/

                                        if(paso==2)
                                            niv=TRES;
                                        cargar6(tab_m);
                                        iniciar_v(&jugador,&puntos,&pasos);
                                        i=19,j=7;        /**  POSICION INICIAL MD  **/
                                        ras=rastro(jugador);
                                        if (ras==CUATRO)
                                            break;
                                        imprimir_md (tab_m,jugador,puntos,pasos,i,j);
                                        do
                                        {
                                            mov=getch();
                                            if(mov=='w'||mov=='W')
                                            {
                                                arriba_m(tab_m,jugador,&puntos,&pasos,&i,&j,niv,ras);
                                            }
                                            else if(mov=='s'||mov=='S')
                                            {
                                                abajo_m(tab_m,jugador,&puntos,&pasos,&i,&j,niv,ras);
                                            }
                                            else if(mov=='d'||mov=='D')
                                            {
                                                derecha_m(tab_m,jugador,&puntos,&pasos,&i,&j,niv,ras);
                                            }
                                            else if(mov=='a'||mov=='A')
                                            {
                                                izquierda_m(tab_m,jugador,&puntos,&pasos,&i,&j,niv,ras);
                                            }
                                        }while(tab_m[1][13]==70&&mov!=42&&puntos.nivel<(IM*JM)/3);
                                        if(tab_f[1][13]!=F)
                                        {
                                            system("cls");
                                            printf("\n\n\n\n\n\n\n\n\n\t\tFELICITACIONES.... NIVEL COMPLETO");
                                            paso=2,juego.table=2;
                                            getch();
                                            mejores (&juego,puntos,jugador);
                                        }
                                        else if(puntos.nivel>(IM*JM)/3)
                                        {
                                            system("cls");
                                            printf("\n\n\n\n\n\n\n\n\n\t\tJUEGO INCOMPLETO....INTENTELO DE NUEVO\n\n\n\n\n");
                                            paso=0;
                                            getch();
                                        }
                                        else if(mov==M)
                                        {
                                            system("cls");
                                            printf("\n\n\n\n\n\n\n\n\n\t\tJUEGO INCOMPLETO....INTENTELO DE NUEVO\n\n\n\n\n");
                                            paso=0;
                                            getch();
                                        }
                                        if(paso==2)
                                        {
                                            niv=CUATRO;
                                            break;
                                        }
                                        else if(paso==0)
                                            break;
                                }

                            }while(niv!=CUATRO);

                        break;

                        case TRES:       /** TAMAÑO DIFICIL **/

                            do
                            {

                                niv=nivel(jugador);
                                switch(niv)
                                {
                                    case UNO:        /** NIVEL FACIL **/

                                        cargar7(tab_d);
                                        iniciar_v(&jugador,&puntos,&pasos);
                                        i=1,j=1;        /**  POSICION INICIAL DF  **/
                                        ras=rastro(jugador);
                                        if (ras==CUATRO)
                                            break;
                                        imprimir_df (tab_d,jugador,puntos,pasos,i,j);
                                        do
                                        {
                                            mov=getch();
                                            if(mov=='w'||mov=='W')
                                            {
                                                arriba_d(tab_d,jugador,&puntos,&pasos,&i,&j,niv,ras);
                                            }
                                            else if(mov=='s'||mov=='S')
                                            {
                                                abajo_d(tab_d,jugador,&puntos,&pasos,&i,&j,niv,ras);
                                            }
                                            else if(mov=='d'||mov=='D')
                                            {
                                                derecha_d(tab_d,jugador,&puntos,&pasos,&i,&j,niv,ras);
                                            }
                                            else if(mov=='a'||mov=='A')
                                            {
                                                izquierda_d(tab_d,jugador,&puntos,&pasos,&i,&j,niv,ras);
                                            }
                                        }while(tab_d[50][19]==70&&mov!=42&&puntos.nivel<(ID*JD)/2);
                                        if(tab_d[50][19]!=F)
                                        {
                                            system("cls");
                                            printf("\n\n\n\n\n\n\n\n\n\t\tFELICITACIONES.... NIVEL COMPLETO");
                                            paso=3,juego.table=3;
                                            getch();
                                            mejores (&juego,puntos,jugador);
                                        }
                                        else if(mov!=M)
                                        {
                                            system("cls");
                                            printf("\n\n\n\n\n\n\n\n\n\t\tJUEGO INCOMPLETO....INTENTELO DE NUEVO");
                                            paso=0;
                                            getch();
                                        }
                                        else if(puntos.nivel>(ID*JD)/2)
                                        {
                                            system("cls");
                                            printf("\n\n\n\n\n\n\n\n\n\t\tJUEGO INCOMPLETO....INTENTELO DE NUEVO\n\n\n\n\n");
                                            getch();
                                            paso=0;
                                        }

                                        if(paso==0)
                                            break;

                                    case DOS:        /** NIVEL MEDIO **/

                                        if(paso==3)
                                            niv=DOS;
                                        cargar8(tab_d);
                                        i=58,j=1;
                                        ras=rastro(jugador);
                                        iniciar_v(&jugador,&puntos,&pasos);
                                        if (ras==CUATRO)
                                                break;
                                        imprimir_dm (tab_d,jugador,puntos,pasos,i,j);
                                        do
                                        {
                                            mov=getch();
                                            if(mov=='w'||mov=='W')
                                            {
                                                arriba_d(tab_d,jugador,&puntos,&pasos,&i,&j,niv,ras);
                                            }
                                            else if(mov=='s'||mov=='S')
                                            {
                                                abajo_d(tab_d,jugador,&puntos,&pasos,&i,&j,niv,ras);
                                            }
                                            else if(mov=='d'||mov=='D')
                                            {
                                                derecha_d(tab_d,jugador,&puntos,&pasos,&i,&j,niv,ras);
                                            }
                                            else if(mov=='a'||mov=='A')
                                            {
                                                izquierda_d(tab_d,jugador,&puntos,&pasos,&i,&j,niv,ras);
                                            }
                                        }while(tab_d[13][32]==70&&mov!=M&&puntos.nivel<(ID*JD)/2);
                                        if(tab_d[50][19]!=F)
                                        {
                                            system("cls");
                                            printf("\n\n\n\n\n\n\n\n\n\t\tFELICITACIONES.... NIVEL COMPLETO");
                                            paso=3,juego.table=3;
                                            getch();
                                            mejores (&juego,puntos,jugador);
                                        }
                                        else if(mov!=M)
                                        {
                                            system("cls");
                                            printf("\n\n\n\n\n\n\n\n\n\t\tJUEGO INCOMPLETO....INTENTELO DE NUEVO");
                                            paso=0;
                                            getch();
                                        }
                                        else if(puntos.nivel>(ID*JD)/2)
                                        {
                                            system("cls");
                                            printf("\n\n\n\n\n\n\n\n\n\t\tJUEGO INCOMPLETO....INTENTELO DE NUEVO\n\n\n\n\n");
                                            getch();
                                            paso=0;
                                        }

                                        if(paso==0)
                                            break;

                                    case TRES:        /** NIVEL DIFICIL **/

                                        if(paso==3)
                                            niv=TRES;
                                        cargar9(tab_d);
                                        i=52,j=7;        /**  POSICION INICIAL DD  **/
                                        ras=rastro(jugador);
                                        iniciar_v(&jugador,&puntos,&pasos);
                                        if (ras==CUATRO)
                                            break;
                                        imprimir_dm (tab_d,jugador,puntos,pasos,i,j);
                                        do
                                        {
                                            mov=getch();
                                            if(mov=='w'||mov=='W')
                                            {
                                                arriba_d(tab_d,jugador,&puntos,&pasos,&i,&j,niv,ras);
                                            }
                                            else if(mov=='s'||mov=='S')
                                            {
                                                abajo_d(tab_d,jugador,&puntos,&pasos,&i,&j,niv,ras);
                                            }
                                            else if(mov=='d'||mov=='D')
                                            {
                                                derecha_d(tab_d,jugador,&puntos,&pasos,&i,&j,niv,ras);
                                            }
                                            else if(mov=='a'||mov=='A')
                                            {
                                                izquierda_d(tab_d,jugador,&puntos,&pasos,&i,&j,niv,ras);
                                            }
                                        }while(tab_d[1][38]==70&&mov!=42&&puntos.nivel<(ID*JD)/2);
                                        if(tab_d[1][38]!=F)
                                        {
                                            system("cls");
                                            printf("\n\n\n\n\n\n\n\n\n\t\tFELICITACIONES.... NIVEL COMPLETO");
                                            paso=3,juego.table=3;
                                            getch();
                                            mejores (&juego,puntos,jugador);
                                        }
                                        else if(mov==M)
                                        {
                                            system("cls");
                                            printf("\n\n\n\n\n\n\n\n\n\t\tJUEGO INCOMPLETO....INTENTELO DE NUEVO");
                                            paso=0;
                                            getch();
                                        }
                                        else if(puntos.nivel>(ID*JD)/2)
                                        {
                                            system("cls");
                                            printf("\n\n\n\n\n\n\n\n\n\t\tJUEGO INCOMPLETO....INTENTELO DE NUEVO\n\n\n\n\n");
                                            getch();
                                            paso=0;
                                        }
                                        if(paso==0)
                                            break;
                                        if(paso==3)
                                        {
                                            niv=CUATRO;
                                            break;
                                        }

                                }

                            }while(niv!=CUATRO);

                        break;

                    }


                }while(tam!=CUATRO);

                mejores5(&juego,puntos,jugador);

            break;

            case DOS:

            break;

            case TRES:          /**  PUNTAJES ALTOS  **/


                do
                {
                    system("cls");
                    printf("\n\n\n\n\n\n\t\t\tESCOJA UNA OPCION\n\n\t\t\t1.PUNTAJES DE NIVELES\n\n\t\t\t2.PUNTAJES TOTALES\n\n\t\t\t3.VOLVER AL MENU\n\n\t\t\t");
                    tos=getch();
                    switch(tos)
                    {
                        case UNO:

                            system("cls");
                            printf("\n\n\n    \t\t(\"CINCO MEJORES PUNTAJES DE LOS NIVELES\")\n\n\n\n\n");
                            printf("\t    NIVEL FACIL\t  \t  \tNIVEL MEDIO\n\n\n\n");
                            printf("\t    1. %d  %s\t\t\t1. %d  %s\n\n",juego.puntajes[0].m_puntos_n,juego.puntajes[0].nom,juego.puntajes[5].m_puntos_n,juego.puntajes[5].nom);
                            printf("\t    2. %d  %s\t\t\t2. %d  %s\n\n",juego.puntajes[1].m_puntos_n,juego.puntajes[1].nom,juego.puntajes[6].m_puntos_n,juego.puntajes[6].nom);
                            printf("\t    3. %d  %s\t\t\t3. %d  %s\n\n",juego.puntajes[2].m_puntos_n,juego.puntajes[2].nom,juego.puntajes[7].m_puntos_n,juego.puntajes[7].nom);
                            printf("\t    4. %d  %s\t\t\t4. %d  %s\n\n",juego.puntajes[3].m_puntos_n,juego.puntajes[3].nom,juego.puntajes[8].m_puntos_n,juego.puntajes[8].nom);
                            printf("\t    5. %d  %s\t\t\t5. %d  %s\n\n",juego.puntajes[4].m_puntos_n,juego.puntajes[4].nom,juego.puntajes[9].m_puntos_n,juego.puntajes[9].nom);
                            printf("\n\n\n\n\t\t\tNIVEL DIFiCIL\n\n\n\n\t\t\t");
                            printf("1.%d  %s\n\n\t\t\t",juego.puntajes[10].m_puntos_n,juego.puntajes[10].nom);
                            printf("2.%d  %s\n\n\t\t\t",juego.puntajes[11].m_puntos_n,juego.puntajes[11].nom);
                            printf("3.%d  %s\n\n\t\t\t",juego.puntajes[12].m_puntos_n,juego.puntajes[12].nom);
                            printf("4.%d  %s\n\n\t\t\t",juego.puntajes[13].m_puntos_n,juego.puntajes[13].nom);
                            printf("5.%d  %s\n\n\t\t\t",juego.puntajes[14].m_puntos_n,juego.puntajes[14].nom);

                            getch();

                            break;

                        case DOS:

                            ordenar_mejores5(&juego);
                            system("cls");
                            printf("\n\n\n    \t\t(\"CINCO MEJORES PUNTAJES\")\n\n\n");
                            printf("\n\n\n    \t\t1. %d %s",juego.punta[0].m_puntos_t);
                            printf("\n\n\n    \t\t2. %d %s",juego.punta[1].m_puntos_t);
                            printf("\n\n\n    \t\t3. %d %s",juego.punta[2].m_puntos_t);
                            printf("\n\n\n    \t\t4. %d %s",juego.punta[3].m_puntos_t);
                            printf("\n\n\n    \t\t5. %d %s",juego.punta[4].m_puntos_t);
                            getch();

                        break;

                    }

                }while(tos!=TRES);

            break;

            case CUATRO:         /**  AYUDA   **/

                ayuda();

            break;

            case CINCO:        /**  SALIR  **/

                despedida();
                g_p_j (juego);
                guardar_puntos(juego);
                guardar5puntos(juego);

            break;

        }

    }while(opc!=CINCO);
    getch();
}

/*************************+
*     SUBPROGRAMAS        *
+*************************/

void abajo_d (char tab[ID][JD],jug nom,punt*punto,pas*pasos,int*i,int*j,char niv,char ras)
{
    system("cls");
    if(tab[*i+1][*j]==P)                  /**  LIMITE           **/
    {
        pasos->limite=pasos->limite+1;
        punto->nivel=punto->nivel+5;
        punto->total=punto->total+5;
        tab[*i][*j]=S;                   /** (v) **/
    }
    else if(tab[*i+1][*j]==M)            /**  MURO             **/
    {
        pasos->muro=pasos->muro+1;
        punto->nivel=punto->nivel+3;
        punto->total=punto->total+3;
        tab[*i][*j]=S;
    }
    else if(tab[*i+1][*j]==F)           /**  FINAL            **/
    {
        punto->nivel=punto->nivel+1;
        punto->total=punto->total+1;
        tab[*i][*j]=E;
        *i=*i+1;
        tab[*i][*j]=S;
    }
    if(ras==UNO)                       /**  RASTRO AVANZADO  **/
    {
        if(tab[*i+1][*j]==E)
        {
            tab[*i][*j]=PUNTO;
            *i=*i+1;
            tab[*i][*j]=S;
        }
         if(tab[*i+1][*j]==PUNTO)
        {
            tab[*i][*j]=DOS;
            *i=*i+1;
            tab[*i][*j]=S;
        }
        if(tab[*i+1][*j]==DOS)
        {
            tab[*i][*j]=TRES;
            *i=*i+1;
            tab[*i][*j]=S;
        }
         if(tab[*i+1][*j]==TRES)
        {
            tab[*i][*j]=CUATRO;
            *i=*i+1;
            tab[*i][*j]=S;
        }
        if(tab[*i+1][*j]==CUATRO)
        {
            tab[*i][*j]=CINCO;
            *i=*i+1;
            tab[*i][*j]=S;
        }
        if(tab[*i+1][*j]==CINCO)
        {
            tab[*i][*j]=SEIS;
            *i=*i+1;
            tab[*i][*j]=S;
        }
        if(tab[*i+1][*j]==SEIS)
        {
            tab[*i][*j]=SIETE;
            *i=*i+1;
            tab[*i][*j]=S;
        }
        if(tab[*i+1][*j]==SIETE)
        {
            tab[*i][*j]=OCHO;
            *i=*i+1;
            tab[*i][*j]=S;
        }
        if(tab[*i+1][*j]==OCHO)
        {
            tab[*i][*j]=NUEVE;
            *i=*i+1;
            tab[*i][*j]=S;
        }
        if(tab[*i+1][*j]==NUEVE)
        {
            tab[*i][*j]=MAS;
            *i=*i+1;
            tab[*i][*j]=S;
        }
        if(tab[*i+1][*j]==MAS)
        {
            tab[*i][*j]=MAS;
            *i=*i+1;
            tab[*i][*j]=S;
        }
        punto->nivel=punto->nivel+1;
        punto->total=punto->total+1;
    }
    else if(ras==DOS)                 /**  RASTRO MEDIO     **/
    {
         if(tab[*i+1][*j]==E)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=PUNTO;          /** (PUNTO) **/
            *i=*i+1;
            tab[*i][*j]=S;             /** (v) **/
        }
        else if(tab[*i+1][*j]==PUNTO)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=PUNTO;           /** (PUNTO) **/
            *i=*i+1;
            tab[*i][*j]=S;
        }
    }
    else if(ras==TRES)               /**  RASTRO DIFICIL   **/
    {
        if(tab[*i+1][*j]==E)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=E;    /** (ESPACIO) **/
            *i=*i+1;
            tab[*i][*j]=S;   /** (v)       **/
        }
    }
    pasos->abajo=pasos->abajo+1;
    if(niv==UNO)
        imprimir_df (tab,nom,*punto,*pasos,*i,*j);
    else if(niv==DOS)
        imprimir_dm (tab,nom,*punto,*pasos,*i,*j);
    else if(niv==TRES)
        imprimir_dd (tab,nom,*punto,*pasos,*i,*j);
}
void abajo_f (char tab[IF][JF],jug nom,punt*punto,pas*pasos,int*i,int*j,char niv,char ras)
{
    system("cls");
    if(tab[*i+1][*j]==P)                  /**  LIMITE           **/
    {
        pasos->limite=pasos->limite+1;
        punto->nivel=punto->nivel+5;
        punto->total=punto->total+5;
        tab[*i][*j]=S;                   /** (v) **/
    }
    else if(tab[*i+1][*j]==M)            /**  MURO             **/
    {
        pasos->muro=pasos->muro+1;
        punto->nivel=punto->nivel+3;
        punto->total=punto->total+3;
        tab[*i][*j]=S;                  /** (v) **/
    }
    else if(tab[*i+1][*j]==F)           /**  FINAL            **/
    {
        punto->nivel=punto->nivel+1;
        punto->total=punto->total+1;
        tab[*i][*j]=E;
        *i=*i+1;
        tab[*i][*j]=S;                 /** (v) **/
    }
    if(ras==UNO)                       /**  RASTRO AVANZADO  **/
    {
        if(tab[*i+1][*j]==E)
        {
            tab[*i][*j]=PUNTO;
            *i=*i+1;
            tab[*i][*j]=S;
        }
         if(tab[*i+1][*j]==PUNTO)
        {
            tab[*i][*j]=DOS;
            *i=*i+1;
            tab[*i][*j]=S;
        }
        if(tab[*i+1][*j]==DOS)
        {
            tab[*i][*j]=TRES;
            *i=*i+1;
            tab[*i][*j]=S;
        }
         if(tab[*i+1][*j]==TRES)
        {
            tab[*i][*j]=CUATRO;
            *i=*i+1;
            tab[*i][*j]=S;
        }
        if(tab[*i+1][*j]==CUATRO)
        {
            tab[*i][*j]=CINCO;
            *i=*i+1;
            tab[*i][*j]=S;
        }
        if(tab[*i+1][*j]==CINCO)
        {
            tab[*i][*j]=SEIS;
            *i=*i+1;
            tab[*i][*j]=S;
        }
        if(tab[*i+1][*j]==SEIS)
        {
            tab[*i][*j]=SIETE;
            *i=*i+1;
            tab[*i][*j]=S;
        }
        if(tab[*i+1][*j]==SIETE)
        {
            tab[*i][*j]=OCHO;
            *i=*i+1;
            tab[*i][*j]=S;
        }
        if(tab[*i+1][*j]==OCHO)
        {
            tab[*i][*j]=NUEVE;
            *i=*i+1;
            tab[*i][*j]=S;
        }
        if(tab[*i+1][*j]==NUEVE)
        {
            tab[*i][*j]=MAS;
            *i=*i+1;
            tab[*i][*j]=S;
        }
        if(tab[*i+1][*j]==MAS)
        {
            tab[*i][*j]=MAS;
            *i=*i+1;
            tab[*i][*j]=S;
        }
        punto->nivel=punto->nivel+1;
        punto->total=punto->total+1;
    }
    else if(ras==DOS)                 /**  RASTRO MEDIO     **/
    {
         if(tab[*i+1][*j]==E)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=PUNTO;          /** (PUNTO) **/
            *i=*i+1;
            tab[*i][*j]=S;             /** (v) **/
        }
        else if(tab[*i+1][*j]==PUNTO)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=PUNTO;           /** (PUNTO) **/
            *i=*i+1;
            tab[*i][*j]=S;
        }
    }
    else if(ras==TRES)               /**  RASTRO DIFICIL   **/
    {
        if(tab[*i+1][*j]==E)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=E;    /** (ESPACIO) **/
            *i=*i+1;
            tab[*i][*j]=S;   /** (v)       **/
        }
    }
    pasos->abajo=pasos->abajo+1;
    if(niv==UNO)
        imprimir_f (tab,nom,*punto,*pasos,*i,*j);
    else if(niv==DOS)
        imprimir_m (tab,nom,*punto,*pasos,*i,*j);
    else if(niv==TRES)
        imprimir_d (tab,nom,*punto,*pasos,*i,*j);
}
void abajo_m (char tab[IM][JM],jug nom,punt*punto,pas*pasos,int*i,int*j,char niv,char ras)
{
    system("cls");
    if(tab[*i+1][*j]==P)                  /**  LIMITE           **/
    {
        pasos->limite=pasos->limite+1;
        punto->nivel=punto->nivel+5;
        punto->total=punto->total+5;
        tab[*i][*j]=S;                   /** (v) **/
    }
    else if(tab[*i+1][*j]==M)            /**  MURO             **/
    {
        pasos->muro=pasos->muro+1;
        punto->nivel=punto->nivel+3;
        punto->total=punto->total+3;
        tab[*i][*j]=S;
    }
    else if(tab[*i+1][*j]==F)           /**  FINAL            **/
    {
        punto->nivel=punto->nivel+1;
        punto->total=punto->total+1;
        tab[*i][*j]=E;
        *i=*i+1;
        tab[*i][*j]=S;
    }
    if(ras==UNO)                       /**  RASTRO AVANZADO  **/
    {
        if(tab[*i+1][*j]==E)
        {
            tab[*i][*j]=PUNTO;
            *i=*i+1;
            tab[*i][*j]=S;
        }
         if(tab[*i+1][*j]==PUNTO)
        {
            tab[*i][*j]=DOS;
            *i=*i+1;
            tab[*i][*j]=S;
        }
        if(tab[*i+1][*j]==DOS)
        {
            tab[*i][*j]=TRES;
            *i=*i+1;
            tab[*i][*j]=S;
        }
         if(tab[*i+1][*j]==TRES)
        {
            tab[*i][*j]=CUATRO;
            *i=*i+1;
            tab[*i][*j]=S;
        }
        if(tab[*i+1][*j]==CUATRO)
        {
            tab[*i][*j]=CINCO;
            *i=*i+1;
            tab[*i][*j]=S;
        }
        if(tab[*i+1][*j]==CINCO)
        {
            tab[*i][*j]=SEIS;
            *i=*i+1;
            tab[*i][*j]=S;
        }
        if(tab[*i+1][*j]==SEIS)
        {
            tab[*i][*j]=SIETE;
            *i=*i+1;
            tab[*i][*j]=S;
        }
        if(tab[*i+1][*j]==SIETE)
        {
            tab[*i][*j]=OCHO;
            *i=*i+1;
            tab[*i][*j]=S;
        }
        if(tab[*i+1][*j]==OCHO)
        {
            tab[*i][*j]=NUEVE;
            *i=*i+1;
            tab[*i][*j]=S;
        }
        if(tab[*i+1][*j]==NUEVE)
        {
            tab[*i][*j]=MAS;
            *i=*i+1;
            tab[*i][*j]=S;
        }
        if(tab[*i+1][*j]==MAS)
        {
            tab[*i][*j]=MAS;
            *i=*i+1;
            tab[*i][*j]=S;
        }
        punto->nivel=punto->nivel+1;
        punto->total=punto->total+1;
    }
    else if(ras==DOS)                 /**  RASTRO MEDIO     **/
    {
         if(tab[*i+1][*j]==E)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=PUNTO;          /** (PUNTO) **/
            *i=*i+1;
            tab[*i][*j]=S;             /** (v) **/
        }
        else if(tab[*i+1][*j]==PUNTO)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=PUNTO;           /** (PUNTO) **/
            *i=*i+1;
            tab[*i][*j]=S;
        }
    }
    else if(ras==TRES)               /**  RASTRO DIFICIL   **/
    {
        if(tab[*i+1][*j]==E)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=E;    /** (ESPACIO) **/
            *i=*i+1;
            tab[*i][*j]=S;   /** (v)       **/
        }
    }
    pasos->abajo=pasos->abajo+1;
    if(niv==UNO)
        imprimir_mf (tab,nom,*punto,*pasos,*i,*j);
    else if(niv==DOS)
        imprimir_mm (tab,nom,*punto,*pasos,*i,*j);
    else if(niv==TRES)
        imprimir_md (tab,nom,*punto,*pasos,*i,*j);
}
void arriba_d (char tab[ID][JD],jug nom,punt*punto,pas*pasos,int*i,int*j,char niv,char ras)
{
    system("cls");
    if(tab[*i-1][*j]==P)                  /**  LIMITE           **/
    {
        pasos->limite=pasos->limite+1;
        punto->nivel=punto->nivel+5;
        punto->total=punto->total+5;
        tab[*i][*j]=W;                   /** (^) **/
    }
    else if(tab[*i-1][*j]==M)            /**  MURO             **/
    {
        pasos->muro=pasos->muro+1;
        punto->nivel=punto->nivel+3;
        punto->total=punto->total+3;
        tab[*i][*j]=W;
    }
    else if(tab[*i-1][*j]==F)           /**  FINAL            **/
    {
        punto->nivel=punto->nivel+1;
        punto->total=punto->total+1;
        tab[*i][*j]=E;
        *i=*i-1;
        tab[*i][*j]=W;
    }
    else if(ras==UNO)                  /**  RASTRO AVANZADO  **/
    {
         if(tab[*i-1][*j]==E)
        {
            tab[*i][*j]=PUNTO;
            *i=*i-1;
            tab[*i][*j]=W;
        }
        else if(tab[*i-1][*j]==PUNTO)
        {
            tab[*i][*j]=DOS;
            *i=*i-1;
            tab[*i][*j]=W;
        }
        else if(tab[*i-1][*j]==DOS)
        {
            tab[*i][*j]=TRES;
            *i=*i-1;
            tab[*i][*j]=W;
        }
        else if(tab[*i-1][*j]==TRES)
        {
            tab[*i][*j]=CUATRO;
            *i=*i-1;
            tab[*i][*j]=W;
        }
        else if(tab[*i-1][*j]==CUATRO)
        {
            tab[*i][*j]=CINCO;
            *i=*i-1;
            tab[*i][*j]=W;
        }
        else if(tab[*i-1][*j]==CINCO)
        {
            tab[*i][*j]=SEIS;
            *i=*i-1;
            tab[*i][*j]=W;
        }
        else if(tab[*i-1][*j]==SEIS)
        {
            tab[*i][*j]=SIETE;
            *i=*i-1;
            tab[*i][*j]=W;
        }
        else if(tab[*i-1][*j]==SIETE)
        {
            tab[*i][*j]=OCHO;
            *i=*i-1;
            tab[*i][*j]=W;
        }
        else if(tab[*i-1][*j]==OCHO)
        {
            tab[*i][*j]=NUEVE;
            *i=*i-1;
            tab[*i][*j]=W;
        }
        else if(tab[*i-1][*j]==NUEVE)
        {
            tab[*i][*j]=MAS;
            *i=*i-1;
            tab[*i][*j]=W;
        }
        else if(tab[*i-1][*j]==MAS)
        {
            tab[*i][*j]=MAS;
            *i=*i-1;
            tab[*i][*j]=W;
        }
        punto->nivel=punto->nivel+1;
        punto->total=punto->total+1;
    }
    else if(ras==DOS)                 /**  RASTRO MEDIO     **/
    {
         if(tab[*i-1][*j]==E)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=PUNTO;
            *i=*i-1;
            tab[*i][*j]=W;
        }
        else if(tab[*i-1][*j]==PUNTO)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=PUNTO;
            *i=*i-1;
            tab[*i][*j]=W;
        }
    }
    else if(ras==TRES)               /**  RASTRO DIFICIL   **/
    {
        if(tab[*i-1][*j]==E)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=E;
            *i=*i-1;
            tab[*i][*j]=W;
        }
    }
    pasos->arriba=pasos->arriba+1;
    if(niv==UNO)
        imprimir_df (tab,nom,*punto,*pasos,*i,*j);
    else if(niv==DOS)
        imprimir_dm (tab,nom,*punto,*pasos,*i,*j);
    else if(niv==TRES)
        imprimir_dd (tab,nom,*punto,*pasos,*i,*j);
}
void arriba_f (char tab[IF][JF],jug nom,punt*punto,pas*pasos,int*i,int*j,char niv,char ras)
{
    system("cls");
    if(tab[*i-1][*j]==P)                  /**  LIMITE           **/
    {
        pasos->limite=pasos->limite+1;
        punto->nivel=punto->nivel+5;
        punto->total=punto->total+5;
        tab[*i][*j]=W;                   /** (^) **/
    }
    else if(tab[*i-1][*j]==M)            /**  MURO             **/
    {
        pasos->muro=pasos->muro+1;
        punto->nivel=punto->nivel+3;
        punto->total=punto->total+3;
        tab[*i][*j]=W;
    }
    else if(tab[*i-1][*j]==F)           /**  FINAL            **/
    {
        punto->nivel=punto->nivel+1;
        punto->total=punto->total+1;
        tab[*i][*j]=E;
        *i=*i-1;
        tab[*i][*j]=W;
    }
    else if(ras==UNO)                  /**  RASTRO AVANZADO  **/
    {
         if(tab[*i-1][*j]==E)
        {
            tab[*i][*j]=PUNTO;
            *i=*i-1;
            tab[*i][*j]=W;
        }
        else if(tab[*i-1][*j]==PUNTO)
        {
            tab[*i][*j]=DOS;
            *i=*i-1;
            tab[*i][*j]=W;
        }
        else if(tab[*i-1][*j]==DOS)
        {
            tab[*i][*j]=TRES;
            *i=*i-1;
            tab[*i][*j]=W;
        }
        else if(tab[*i-1][*j]==TRES)
        {
            tab[*i][*j]=CUATRO;
            *i=*i-1;
            tab[*i][*j]=W;
        }
        else if(tab[*i-1][*j]==CUATRO)
        {
            tab[*i][*j]=CINCO;
            *i=*i-1;
            tab[*i][*j]=W;
        }
        else if(tab[*i-1][*j]==CINCO)
        {
            tab[*i][*j]=SEIS;
            *i=*i-1;
            tab[*i][*j]=W;
        }
        else if(tab[*i-1][*j]==SEIS)
        {
            tab[*i][*j]=SIETE;
            *i=*i-1;
            tab[*i][*j]=W;
        }
        else if(tab[*i-1][*j]==SIETE)
        {
            tab[*i][*j]=OCHO;
            *i=*i-1;
            tab[*i][*j]=W;
        }
        else if(tab[*i-1][*j]==OCHO)
        {
            tab[*i][*j]=NUEVE;
            *i=*i-1;
            tab[*i][*j]=W;
        }
        else if(tab[*i-1][*j]==NUEVE)
        {
            tab[*i][*j]=MAS;
            *i=*i-1;
            tab[*i][*j]=W;
        }
        else if(tab[*i-1][*j]==MAS)
        {
            tab[*i][*j]=MAS;
            *i=*i-1;
            tab[*i][*j]=W;
        }
        punto->nivel=punto->nivel+1;
        punto->total=punto->total+1;
    }
    else if(ras==DOS)                 /**  RASTRO MEDIO     **/
    {
         if(tab[*i-1][*j]==E)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=PUNTO;
            *i=*i-1;
            tab[*i][*j]=W;
        }
        else if(tab[*i-1][*j]==PUNTO)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=PUNTO;
            *i=*i-1;
            tab[*i][*j]=W;
        }
    }
    else if(ras==TRES)               /**  RASTRO DIFICIL   **/
    {
        if(tab[*i-1][*j]==E)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=E;
            *i=*i-1;
            tab[*i][*j]=W;
        }
    }
    pasos->arriba=pasos->arriba+1;
    if(niv==UNO)
        imprimir_f (tab,nom,*punto,*pasos,*i,*j);
    else if(niv==DOS)
        imprimir_m (tab,nom,*punto,*pasos,*i,*j);
    else if(niv==TRES)
        imprimir_d (tab,nom,*punto,*pasos,*i,*j);
}
void arriba_m (char tab[IM][JM],jug nom,punt*punto,pas*pasos,int*i,int*j,char niv,char ras)
{
    system("cls");
    if(tab[*i-1][*j]==P)                  /**  LIMITE           **/
    {
        pasos->limite=pasos->limite+1;
        punto->nivel=punto->nivel+5;
        punto->total=punto->total+5;
        tab[*i][*j]=W;                   /** (^) **/
    }
    else if(tab[*i-1][*j]==M)            /**  MURO             **/
    {
        pasos->muro=pasos->muro+1;
        punto->nivel=punto->nivel+3;
        punto->total=punto->total+3;
        tab[*i][*j]=W;
    }
    else if(tab[*i-1][*j]==F)           /**  FINAL            **/
    {
        punto->nivel=punto->nivel+1;
        punto->total=punto->total+1;
        tab[*i][*j]=E;
        *i=*i-1;
        tab[*i][*j]=W;
    }
    else if(ras==UNO)                  /**  RASTRO AVANZADO  **/
    {
         if(tab[*i-1][*j]==E)
        {
            tab[*i][*j]=PUNTO;
            *i=*i-1;
            tab[*i][*j]=W;
        }
        else if(tab[*i-1][*j]==PUNTO)
        {
            tab[*i][*j]=DOS;
            *i=*i-1;
            tab[*i][*j]=W;
        }
        else if(tab[*i-1][*j]==DOS)
        {
            tab[*i][*j]=TRES;
            *i=*i-1;
            tab[*i][*j]=W;
        }
        else if(tab[*i-1][*j]==TRES)
        {
            tab[*i][*j]=CUATRO;
            *i=*i-1;
            tab[*i][*j]=W;
        }
        else if(tab[*i-1][*j]==CUATRO)
        {
            tab[*i][*j]=CINCO;
            *i=*i-1;
            tab[*i][*j]=W;
        }
        else if(tab[*i-1][*j]==CINCO)
        {
            tab[*i][*j]=SEIS;
            *i=*i-1;
            tab[*i][*j]=W;
        }
        else if(tab[*i-1][*j]==SEIS)
        {
            tab[*i][*j]=SIETE;
            *i=*i-1;
            tab[*i][*j]=W;
        }
        else if(tab[*i-1][*j]==SIETE)
        {
            tab[*i][*j]=OCHO;
            *i=*i-1;
            tab[*i][*j]=W;
        }
        else if(tab[*i-1][*j]==OCHO)
        {
            tab[*i][*j]=NUEVE;
            *i=*i-1;
            tab[*i][*j]=W;
        }
        else if(tab[*i-1][*j]==NUEVE)
        {
            tab[*i][*j]=MAS;
            *i=*i-1;
            tab[*i][*j]=W;
        }
        else if(tab[*i-1][*j]==MAS)
        {
            tab[*i][*j]=MAS;
            *i=*i-1;
            tab[*i][*j]=W;
        }
        punto->nivel=punto->nivel+1;
        punto->total=punto->total+1;
    }
    else if(ras==DOS)                 /**  RASTRO MEDIO     **/
    {
         if(tab[*i-1][*j]==E)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=PUNTO;
            *i=*i-1;
            tab[*i][*j]=W;
        }
        else if(tab[*i-1][*j]==PUNTO)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=PUNTO;
            *i=*i-1;
            tab[*i][*j]=W;
        }
    }
    else if(ras==TRES)               /**  RASTRO DIFICIL   **/
    {
        if(tab[*i-1][*j]==E)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=E;
            *i=*i-1;
            tab[*i][*j]=W;
        }
    }
    pasos->arriba=pasos->arriba+1;
    if(niv==UNO)
        imprimir_mf (tab,nom,*punto,*pasos,*i,*j);
    else if(niv==DOS)
        imprimir_mm (tab,nom,*punto,*pasos,*i,*j);
    else if(niv==TRES)
        imprimir_md (tab,nom,*punto,*pasos,*i,*j);
}
void ayuda (void)
{
    system("cls");
    printf("\n\n\n\t\t\tBIENVENIDO A CRAZY MACEL....\n\n\nESTE JUEGO CONSISTE EN MOVER EL MACEL POR MEDIO DEL LAVERINTO CON EL FIN DE\nLLEGAR A LA META LA CUAL ES LA 'F'.\nCUANDO EL MACEL HALLA LLEGADO A LA 'F' EL TABLERO HABRA FINALIZADO Y PASARA AL  SIGUIENTE NIVEL.\n\nCADA DESPLAZAMIENTO DEL MACEL PRODUCE UN PUNTO, AL CHOCARCE CON UNA PARED\nAUMENTARA 5 PUNTOS Y AL CHOCARCE CON UN MURO AUENTARA 3 PUNTOS.\n\nEL OBJETIVO ES PASAR EL LABERINTO CON EL MENOR NUMERO DE PUNTOS POSIBLES.\n\n\nUD TIENE TRS OPCIONES DE SALIDA:\n\n1.JUEGO COMPLETO\n2.JUEGO ABANDONADO\n3.JUEGO INCOMPLETO\n\nJUEGO IMPLETO: ES CUANDO EL JUGADOR EXCEDE EL NUMERO DE PUNTOS PERMITIDOS EN EL TABLERO.\n\n\nPARA PODER MOVER AL MACEL TIENE LAS SIGUIENTES OPCIONES:\n\nW=DESPLAZARCE HACIA ARRIBA\nS=DESPLAZARCE HACIA ABAJO\nA=DESPLAZARCE A LA IZQUIERDA\nD=DESPLAZARCE A LA DERECHA\n\n\n\n\t\t\tMUCHA SUERTE.....\n\n\n");
    getch();
    system("cls");
}
/**int buscar_nom (char nom[],struct marca c[],int max)
{
    int i,band,op;
    for (i=0,band=-1;i<max && band==-1;i++)
    {
        op=strcmp(mc,c[i].marca);
        if(op==0)
        {
                 band=i;
        }
    }
    return (band);
}**/
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
void cargar_puntajes (adm*niv)
{
    FILE *arch;
    int i,j,l,t;
    arch=fopen("mej_puntos.txt","r");
    if(arch!=NULL)
    {
        for(j=0;j<=3;j++)
            if(j==0)
                for(i=0;i<niv->niveles[j];i++)
                {
                    fgets(niv->puntajes[i].nom,NOM,arch);
                    fscanf(arch,"\n%d\n",&niv->puntajes[i].m_puntos_n);
                    l=strlen(niv->puntajes[i].nom);
                    if(niv->puntajes[i].nom[l-1]=='\n')
                        niv->puntajes[i].nom[l-1]=0;
                }
            else if(j==1)
                for(t=5,i=0;i<niv->niveles[j];i++)
                {
                    fgets(niv->puntajes[t].nom,NOM,arch);
                    fscanf(arch,"\n%d\n",&niv->puntajes[t].m_puntos_n);
                    l=strlen(niv->puntajes[t].nom);
                    if(niv->puntajes[t].nom[l-1]=='\n')
                        niv->puntajes[t].nom[l-1]=0;
                }
            else if(j==2)
                for(t=10,i=0;i<niv->niveles[j];i++)
                {
                    fgets(niv->puntajes[t].nom,NOM,arch);
                    fscanf(arch,"\n%d\n",&niv->puntajes[t].m_puntos_n);
                    l=strlen(niv->puntajes[t].nom);
                    if(niv->puntajes[t].nom[l-1]=='\n')
                        niv->puntajes[t].nom[l-1]=0;
                }
    }
    fclose(arch);
}
void c_m_p (adm*nivel)
{
    FILE *arch;
    int i;
    arch=fopen("mejore_partidas.txt","r");
    if(arch!=NULL)
    {
        for(i=0;i<3;i++)
        {
            fscanf(arch,"%d ",&nivel->niveles[i]);
        }
        fclose(arch);
    }
}
void derecha_d (char tab[ID][JD],jug nom,punt*punto,pas*pasos,int*i,int*j,char niv,char ras)
{
    system("cls");
    if(tab[*i][*j+1]==P)                  /**  LIMITE           **/
    {
        pasos->limite=pasos->limite+1;
        punto->nivel=punto->nivel+5;
        punto->total=punto->total+5;
        tab[*i][*j]=D;                   /** (>) **/
    }
    else if(tab[*i][*j+1]==M)            /**  MURO             **/
    {
        pasos->muro=pasos->muro+1;
        punto->nivel=punto->nivel+3;
        punto->total=punto->total+3;
        tab[*i][*j]=D;

    }
    else if(tab[*i][*j+1]==F)           /**  FINAL            **/
    {
        punto->nivel=punto->nivel+1;
        punto->total=punto->total+1;
        tab[*i][*j]=E;
        *j=*j+1;
        tab[*i][*j]=D;
    }
    if(ras==UNO)                       /**  RASTRO AVANZADO  **/
    {
        if(tab[*i][*j+1]==E)
        {
            tab[*i][*j]=PUNTO;
            *j=*j+1;
            tab[*i][*j]=D;
        }
        if(tab[*i][*j+1]==PUNTO)
        {
            tab[*i][*j]=DOS;
            *j=*j+1;
            tab[*i][*j]=D;
        }
        if(tab[*i][*j+1]==DOS)
        {
            tab[*i][*j]=TRES;
            *j=*j+1;
            tab[*i][*j]=D;
        }
        if(tab[*i][*j+1]==TRES)
        {
            tab[*i][*j]=CUATRO;
            *j=*j+1;
            tab[*i][*j]=D;
        }
        if(tab[*i][*j+1]==CUATRO)
        {
            tab[*i][*j]=CINCO;
            *j=*j+1;
            tab[*i][*j]=D;
        }
        if(tab[*i][*j+1]==CINCO)
        {
            tab[*i][*j]=SEIS;
            *j=*j+1;
            tab[*i][*j]=D;
        }
        if(tab[*i][*j+1]==SEIS)
        {
            tab[*i][*j]=SIETE;
            *j=*j+1;
            tab[*i][*j]=D;
        }
        if(tab[*i][*j+1]==SIETE)
        {
            tab[*i][*j]=OCHO;
            *j=*j+1;
            tab[*i][*j]=D;
        }
        if(tab[*i][*j+1]==OCHO)
        {
            tab[*i][*j]=NUEVE;
            *j=*j+1;
            tab[*i][*j]=D;
        }
        if(tab[*i][*j+1]==NUEVE)
        {
            tab[*i][*j]=MAS;
            *j=*j+1;
            tab[*i][*j]=D;
        }
        if(tab[*i][*j+1]==MAS)
        {
            tab[*i][*j]=MAS;
            *j=*j+1;
            tab[*i][*j]=D;
        }
        punto->nivel=punto->nivel+1;
        punto->total=punto->total+1;
    }
    else if(ras==DOS)                 /**  RASTRO MEDIO     **/
    {
         if(tab[*i][*j+1]==E)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=PUNTO;
            *j=*j+1;
            tab[*i][*j]=D;
        }
        else if(tab[*i][*j+1]==PUNTO)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=PUNTO;
            *j=*j+1;
            tab[*i][*j]=D;
        }
    }
    else if(ras==TRES)               /**  RASTRO DIFICIL   **/
    {
        if(tab[*i][*j+1]==E)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=E;
            *j=*j+1;
            tab[*i][*j]=D;
        }
    }
    pasos->derecha=pasos->derecha+1;
    if(niv==UNO)
        imprimir_df (tab,nom,*punto,*pasos,*i,*j);
    else if(niv==DOS)
        imprimir_dm (tab,nom,*punto,*pasos,*i,*j);
    else if(niv==TRES)
        imprimir_dd (tab,nom,*punto,*pasos,*i,*j);
}
void derecha_f (char tab[IF][JF],jug nom,punt*punto,pas*pasos,int*i,int*j,char niv,char ras)
{
    system("cls");
    if(tab[*i][*j+1]==P)                  /**  LIMITE           **/
    {
        pasos->limite=pasos->limite+1;
        punto->nivel=punto->nivel+5;
        punto->total=punto->total+5;
        tab[*i][*j]=D;                   /** (>) **/
    }
    else if(tab[*i][*j+1]==M)            /**  MURO             **/
    {
        pasos->muro=pasos->muro+1;
        punto->nivel=punto->nivel+3;
        punto->total=punto->total+3;
        tab[*i][*j]=D;

    }
    else if(tab[*i][*j+1]==F)           /**  FINAL            **/
    {
        punto->nivel=punto->nivel+1;
        punto->total=punto->total+1;
        tab[*i][*j]=E;
        *j=*j+1;
        tab[*i][*j]=D;
    }
    if(ras==UNO)                       /**  RASTRO AVANZADO  **/
    {
        if(tab[*i][*j+1]==E)
        {
            tab[*i][*j]=PUNTO;
            *j=*j+1;
            tab[*i][*j]=D;
        }
        if(tab[*i][*j+1]==PUNTO)
        {
            tab[*i][*j]=DOS;
            *j=*j+1;
            tab[*i][*j]=D;
        }
        if(tab[*i][*j+1]==DOS)
        {
            tab[*i][*j]=TRES;
            *j=*j+1;
            tab[*i][*j]=D;
        }
        if(tab[*i][*j+1]==TRES)
        {
            tab[*i][*j]=CUATRO;
            *j=*j+1;
            tab[*i][*j]=D;
        }
        if(tab[*i][*j+1]==CUATRO)
        {
            tab[*i][*j]=CINCO;
            *j=*j+1;
            tab[*i][*j]=D;
        }
        if(tab[*i][*j+1]==CINCO)
        {
            tab[*i][*j]=SEIS;
            *j=*j+1;
            tab[*i][*j]=D;
        }
        if(tab[*i][*j+1]==SEIS)
        {
            tab[*i][*j]=SIETE;
            *j=*j+1;
            tab[*i][*j]=D;
        }
        if(tab[*i][*j+1]==SIETE)
        {
            tab[*i][*j]=OCHO;
            *j=*j+1;
            tab[*i][*j]=D;
        }
        if(tab[*i][*j+1]==OCHO)
        {
            tab[*i][*j]=NUEVE;
            *j=*j+1;
            tab[*i][*j]=D;
        }
        if(tab[*i][*j+1]==NUEVE)
        {
            tab[*i][*j]=MAS;
            *j=*j+1;
            tab[*i][*j]=D;
        }
        if(tab[*i][*j+1]==MAS)
        {
            tab[*i][*j]=MAS;
            *j=*j+1;
            tab[*i][*j]=D;
        }
        punto->nivel=punto->nivel+1;
        punto->total=punto->total+1;
    }
    else if(ras==DOS)                 /**  RASTRO MEDIO     **/
    {
         if(tab[*i][*j+1]==E)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=PUNTO;
            *j=*j+1;
            tab[*i][*j]=D;
        }
        else if(tab[*i][*j+1]==PUNTO)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=PUNTO;
            *j=*j+1;
            tab[*i][*j]=D;
        }
    }
    else if(ras==TRES)               /**  RASTRO DIFICIL   **/
    {
        if(tab[*i][*j+1]==E)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=E;
            *j=*j+1;
            tab[*i][*j]=D;
        }
    }
    pasos->derecha=pasos->derecha+1;
    if(niv==UNO)
        imprimir_f (tab,nom,*punto,*pasos,*i,*j);
    else if(niv==DOS)
        imprimir_m (tab,nom,*punto,*pasos,*i,*j);
    else if(niv==TRES)
        imprimir_d (tab,nom,*punto,*pasos,*i,*j);
}
void derecha_m (char tab[IM][JM],jug nom,punt*punto,pas*pasos,int*i,int*j,char niv,char ras)
{
    system("cls");
    if(tab[*i][*j+1]==P)                  /**  LIMITE           **/
    {
        pasos->limite=pasos->limite+1;
        punto->nivel=punto->nivel+5;
        punto->total=punto->total+5;
        tab[*i][*j]=D;                   /** (>) **/
    }
    else if(tab[*i][*j+1]==M)            /**  MURO             **/
    {
        pasos->muro=pasos->muro+1;
        punto->nivel=punto->nivel+3;
        punto->total=punto->total+3;
        tab[*i][*j]=D;

    }
    else if(tab[*i][*j+1]==F)           /**  FINAL            **/
    {
        punto->nivel=punto->nivel+1;
        punto->total=punto->total+1;
        tab[*i][*j]=E;
        *j=*j+1;
        tab[*i][*j]=D;
    }
    if(ras==UNO)                       /**  RASTRO AVANZADO  **/
    {
        if(tab[*i][*j+1]==E)
        {
            tab[*i][*j]=PUNTO;
            *j=*j+1;
            tab[*i][*j]=D;
        }
        if(tab[*i][*j+1]==PUNTO)
        {
            tab[*i][*j]=DOS;
            *j=*j+1;
            tab[*i][*j]=D;
        }
        if(tab[*i][*j+1]==DOS)
        {
            tab[*i][*j]=TRES;
            *j=*j+1;
            tab[*i][*j]=D;
        }
        if(tab[*i][*j+1]==TRES)
        {
            tab[*i][*j]=CUATRO;
            *j=*j+1;
            tab[*i][*j]=D;
        }
        if(tab[*i][*j+1]==CUATRO)
        {
            tab[*i][*j]=CINCO;
            *j=*j+1;
            tab[*i][*j]=D;
        }
        if(tab[*i][*j+1]==CINCO)
        {
            tab[*i][*j]=SEIS;
            *j=*j+1;
            tab[*i][*j]=D;
        }
        if(tab[*i][*j+1]==SEIS)
        {
            tab[*i][*j]=SIETE;
            *j=*j+1;
            tab[*i][*j]=D;
        }
        if(tab[*i][*j+1]==SIETE)
        {
            tab[*i][*j]=OCHO;
            *j=*j+1;
            tab[*i][*j]=D;
        }
        if(tab[*i][*j+1]==OCHO)
        {
            tab[*i][*j]=NUEVE;
            *j=*j+1;
            tab[*i][*j]=D;
        }
        if(tab[*i][*j+1]==NUEVE)
        {
            tab[*i][*j]=MAS;
            *j=*j+1;
            tab[*i][*j]=D;
        }
        if(tab[*i][*j+1]==MAS)
        {
            tab[*i][*j]=MAS;
            *j=*j+1;
            tab[*i][*j]=D;
        }
        punto->nivel=punto->nivel+1;
        punto->total=punto->total+1;
    }
    else if(ras==DOS)                 /**  RASTRO MEDIO     **/
    {
         if(tab[*i][*j+1]==E)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=PUNTO;
            *j=*j+1;
            tab[*i][*j]=D;
        }
        else if(tab[*i][*j+1]==PUNTO)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=PUNTO;
            *j=*j+1;
            tab[*i][*j]=D;
        }
    }
    else if(ras==TRES)               /**  RASTRO DIFICIL   **/
    {
        if(tab[*i][*j+1]==E)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=E;
            *j=*j+1;
            tab[*i][*j]=D;
        }
    }
    pasos->derecha=pasos->derecha+1;
    if(niv==UNO)
        imprimir_mf (tab,nom,*punto,*pasos,*i,*j);
    else if(niv==DOS)
        imprimir_mm (tab,nom,*punto,*pasos,*i,*j);
    else if(niv==TRES)
        imprimir_md (tab,nom,*punto,*pasos,*i,*j);
}
void despedida (void)
{
        system("cls");
        system ("color 1f");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tGRACIAS POR JUGAR CRAZY MACEL... CUANDO QUIERAS VUELVE A INTENTALO\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t");
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
    punto.res=(IF*JF)/3-punto.nivel;
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
    punto.res=(ID*JD)/3-punto.nivel;
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
    punto.res=(ID*JD)/3-punto.nivel;
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
    punto.res=(ID*JD)/3-punto.nivel;
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
    punto.res=(IF*JF)/3-punto.nivel;
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
    punto.res=(IF*JF)/3-punto.nivel;
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
    punto.res=(IM*JM)/3-punto.nivel;
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
    punto.res=(IM*JM)/3-punto.nivel;
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
    punto.res=(IM*JM)/3-punto.nivel;
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
void iniciar_mp (adm *partidas)
{
    int i;
    char p[3];
    for(i=0;i<=15;i++)
        partidas->puntajes[i].m_puntos_n=0;
    for(i=0;i<=5;i++)
        partidas->punta[i].m_puntos_t=0;
    for(i=0;i<=3;i++)
        partidas->niveles[i]=0;
    partidas->unico=0;
    p[0]='N';
    p[1]='.';
    p[2]='N';
    for(i=0;i<=15;i++)
        strcpy(partidas->puntajes[i].nom,p);
    for(i=0;i<=5;i++)
    {
        strcpy(partidas->punta[i].nom,p);
    }
}
void izquierda_d (char tab[ID][JD],jug nom,punt*punto,pas*pasos,int*i,int*j,char niv,char ras)
{
    system("cls");
    if(tab[*i][*j-1]==P)                  /**  LIMITE           **/
    {
        pasos->limite=pasos->limite+1;
        punto->nivel=punto->nivel+5;
        punto->total=punto->total+5;
        tab[*i][*j]=A;                   /** (<) **/
    }
    else if(tab[*i][*j-1]==M)            /**  MURO             **/
    {
        pasos->muro=pasos->muro+1;
        punto->nivel=punto->nivel+3;
        punto->total=punto->total+3;
        tab[*i][*j]=A;
    }
    else if(tab[*i][*j-1]==F)           /**  FINAL            **/
    {
        punto->nivel=punto->nivel+1;
        punto->total=punto->total+1;
        tab[*i][*j]=E;
        *j=*j-1;
        tab[*i][*j]=D;
    }
    if(ras==UNO)                       /**  RASTRO AVANZADO  **/
    {
        if(tab[*i][*j-1]==E)
        {
            tab[*i][*j]=PUNTO;
            *j=*j-1;
            tab[*i][*j]=A;
        }
        else if(tab[*i][*j-1]==PUNTO)
        {
            tab[*i][*j]=DOS;
            *j=*j-1;
            tab[*i][*j]=A;
        }
        else if(tab[*i][*j-1]==DOS)
        {
            tab[*i][*j]=TRES;
            *j=*j-1;
            tab[*i][*j]=A;
        }
        else if(tab[*i][*j-1]==TRES)
        {
            tab[*i][*j]=CUATRO;
            *j=*j-1;
            tab[*i][*j]=A;
        }
        else if(tab[*i][*j-1]==CUATRO)
        {
            tab[*i][*j]=CINCO;
            *j=*j-1;
            tab[*i][*j]=A;
        }
        else if(tab[*i][*j-1]==CINCO)
        {
            tab[*i][*j]=SEIS;
            *j=*j-1;
            tab[*i][*j]=A;
        }
        else if(tab[*i][*j-1]==SEIS)
        {
            tab[*i][*j]=SIETE;
            *j=*j-1;
            tab[*i][*j]=A;
        }
        else if(tab[*i][*j-1]==SIETE)
        {
            tab[*i][*j]=OCHO;
            *j=*j-1;
            tab[*i][*j]=A;
        }
        else if(tab[*i][*j-1]==OCHO)
        {
            tab[*i][*j]=NUEVE;
            *j=*j-1;
            tab[*i][*j]=A;
        }
        else if(tab[*i][*j-1]==NUEVE)
        {
            tab[*i][*j]=MAS;
            *j=*j-1;
            tab[*i][*j]=A;
        }
        else if(tab[*i][*j-1]==MAS)
        {
            tab[*i][*j]=MAS;
            *j=*j-1;
            tab[*i][*j]=A;
        }
        punto->nivel=punto->nivel+1;
        punto->total=punto->total+1;
    }
    else if(ras==DOS)                 /**  RASTRO MEDIO     **/
    {
         if(tab[*i][*j-1]==E)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=PUNTO;
            *j=*j-1;
            tab[*i][*j]=A;
        }
        else if(tab[*i][*j-1]==PUNTO)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=PUNTO;
            *j=*j-1;
            tab[*i][*j]=A;
        }
    }
    else if(ras==TRES)               /**  RASTRO DIFICIL   **/
    {
        if(tab[*i][*j-1]==E)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=E;
            *j=*j-1;
            tab[*i][*j]=A;
        }
    }
    pasos->izquierda=pasos->izquierda+1;
    if(niv==UNO)
        imprimir_df (tab,nom,*punto,*pasos,*i,*j);
    else if(niv==DOS)
        imprimir_dm (tab,nom,*punto,*pasos,*i,*j);
    else if(niv==TRES)
        imprimir_dd (tab,nom,*punto,*pasos,*i,*j);
}
void izquierda_f (char tab[IF][JF],jug nom,punt*punto,pas*pasos,int*i,int*j,char niv,char ras)
{
    system("cls");
    if(tab[*i][*j-1]==P)                  /**  LIMITE           **/
    {
        pasos->limite=pasos->limite+1;
        punto->nivel=punto->nivel+5;
        punto->total=punto->total+5;
        tab[*i][*j]=A;                   /** (<) **/
    }
    else if(tab[*i][*j-1]==M)            /**  MURO             **/
    {
        pasos->muro=pasos->muro+1;
        punto->nivel=punto->nivel+3;
        punto->total=punto->total+3;
        tab[*i][*j]=A;
    }
    else if(tab[*i][*j-1]==F)           /**  FINAL            **/
    {
        punto->nivel=punto->nivel+1;
        punto->total=punto->total+1;
        tab[*i][*j]=E;
        *j=*j-1;
        tab[*i][*j]=D;
    }
    if(ras==UNO)                       /**  RASTRO AVANZADO  **/
    {
        if(tab[*i][*j-1]==E)
        {
            tab[*i][*j]=PUNTO;
            *j=*j-1;
            tab[*i][*j]=A;
        }
        else if(tab[*i][*j-1]==PUNTO)
        {
            tab[*i][*j]=DOS;
            *j=*j-1;
            tab[*i][*j]=A;
        }
        else if(tab[*i][*j-1]==DOS)
        {
            tab[*i][*j]=TRES;
            *j=*j-1;
            tab[*i][*j]=A;
        }
        else if(tab[*i][*j-1]==TRES)
        {
            tab[*i][*j]=CUATRO;
            *j=*j-1;
            tab[*i][*j]=A;
        }
        else if(tab[*i][*j-1]==CUATRO)
        {
            tab[*i][*j]=CINCO;
            *j=*j-1;
            tab[*i][*j]=A;
        }
        else if(tab[*i][*j-1]==CINCO)
        {
            tab[*i][*j]=SEIS;
            *j=*j-1;
            tab[*i][*j]=A;
        }
        else if(tab[*i][*j-1]==SEIS)
        {
            tab[*i][*j]=SIETE;
            *j=*j-1;
            tab[*i][*j]=A;
        }
        else if(tab[*i][*j-1]==SIETE)
        {
            tab[*i][*j]=OCHO;
            *j=*j-1;
            tab[*i][*j]=A;
        }
        else if(tab[*i][*j-1]==OCHO)
        {
            tab[*i][*j]=NUEVE;
            *j=*j-1;
            tab[*i][*j]=A;
        }
        else if(tab[*i][*j-1]==NUEVE)
        {
            tab[*i][*j]=MAS;
            *j=*j-1;
            tab[*i][*j]=A;
        }
        else if(tab[*i][*j-1]==MAS)
        {
            tab[*i][*j]=MAS;
            *j=*j-1;
            tab[*i][*j]=A;
        }
        punto->nivel=punto->nivel+1;
        punto->total=punto->total+1;
    }
    else if(ras==DOS)                 /**  RASTRO MEDIO     **/
    {
         if(tab[*i][*j-1]==E)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=PUNTO;
            *j=*j-1;
            tab[*i][*j]=A;
        }
        else if(tab[*i][*j-1]==PUNTO)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=PUNTO;
            *j=*j-1;
            tab[*i][*j]=A;
        }
    }
    else if(ras==TRES)               /**  RASTRO DIFICIL   **/
    {
        if(tab[*i][*j-1]==E)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=E;
            *j=*j-1;
            tab[*i][*j]=A;
        }
    }
    pasos->izquierda=pasos->izquierda+1;
    if(niv==UNO)
        imprimir_f (tab,nom,*punto,*pasos,*i,*j);
    else if(niv==DOS)
        imprimir_m (tab,nom,*punto,*pasos,*i,*j);
    else if(niv==TRES)
        imprimir_d (tab,nom,*punto,*pasos,*i,*j);
}
void izquierda_m (char tab[IM][JM],jug nom,punt*punto,pas*pasos,int*i,int*j,char niv,char ras)
{
    system("cls");
    if(tab[*i][*j-1]==P)                  /**  LIMITE           **/
    {
        pasos->limite=pasos->limite+1;
        punto->nivel=punto->nivel+5;
        punto->total=punto->total+5;
        tab[*i][*j]=A;                   /** (<) **/
    }
    else if(tab[*i][*j-1]==M)            /**  MURO             **/
    {
        pasos->muro=pasos->muro+1;
        punto->nivel=punto->nivel+3;
        punto->total=punto->total+3;
        tab[*i][*j]=A;
    }
    else if(tab[*i][*j-1]==F)           /**  FINAL            **/
    {
        punto->nivel=punto->nivel+1;
        punto->total=punto->total+1;
        tab[*i][*j]=E;
        *j=*j-1;
        tab[*i][*j]=D;
    }
    if(ras==UNO)                       /**  RASTRO AVANZADO  **/
    {
        if(tab[*i][*j-1]==E)
        {
            tab[*i][*j]=PUNTO;
            *j=*j-1;
            tab[*i][*j]=A;
        }
        else if(tab[*i][*j-1]==PUNTO)
        {
            tab[*i][*j]=DOS;
            *j=*j-1;
            tab[*i][*j]=A;
        }
        else if(tab[*i][*j-1]==DOS)
        {
            tab[*i][*j]=TRES;
            *j=*j-1;
            tab[*i][*j]=A;
        }
        else if(tab[*i][*j-1]==TRES)
        {
            tab[*i][*j]=CUATRO;
            *j=*j-1;
            tab[*i][*j]=A;
        }
        else if(tab[*i][*j-1]==CUATRO)
        {
            tab[*i][*j]=CINCO;
            *j=*j-1;
            tab[*i][*j]=A;
        }
        else if(tab[*i][*j-1]==CINCO)
        {
            tab[*i][*j]=SEIS;
            *j=*j-1;
            tab[*i][*j]=A;
        }
        else if(tab[*i][*j-1]==SEIS)
        {
            tab[*i][*j]=SIETE;
            *j=*j-1;
            tab[*i][*j]=A;
        }
        else if(tab[*i][*j-1]==SIETE)
        {
            tab[*i][*j]=OCHO;
            *j=*j-1;
            tab[*i][*j]=A;
        }
        else if(tab[*i][*j-1]==OCHO)
        {
            tab[*i][*j]=NUEVE;
            *j=*j-1;
            tab[*i][*j]=A;
        }
        else if(tab[*i][*j-1]==NUEVE)
        {
            tab[*i][*j]=MAS;
            *j=*j-1;
            tab[*i][*j]=A;
        }
        else if(tab[*i][*j-1]==MAS)
        {
            tab[*i][*j]=MAS;
            *j=*j-1;
            tab[*i][*j]=A;
        }
        punto->nivel=punto->nivel+1;
        punto->total=punto->total+1;
    }
    else if(ras==DOS)                 /**  RASTRO MEDIO     **/
    {
         if(tab[*i][*j-1]==E)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=PUNTO;
            *j=*j-1;
            tab[*i][*j]=A;
        }
        else if(tab[*i][*j-1]==PUNTO)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=PUNTO;
            *j=*j-1;
            tab[*i][*j]=A;
        }
    }
    else if(ras==TRES)               /**  RASTRO DIFICIL   **/
    {
        if(tab[*i][*j-1]==E)
        {
            punto->nivel=punto->nivel+1;
            punto->total=punto->total+1;
            tab[*i][*j]=E;
            *j=*j-1;
            tab[*i][*j]=A;
        }
    }
    pasos->izquierda=pasos->izquierda+1;
    if(niv==UNO)
        imprimir_mf (tab,nom,*punto,*pasos,*i,*j);
    else if(niv==DOS)
        imprimir_mm (tab,nom,*punto,*pasos,*i,*j);
    else if(niv==TRES)
        imprimir_md (tab,nom,*punto,*pasos,*i,*j);
}
void guardar_puntos (adm puntos)
{
    FILE *arch;
    int i,j,t;
    arch=fopen("mej_puntos.txt","w");
    i=0;
    if(arch!=NULL)
    {
        for(j=0;j<=3;j++)
            if(j==0)
                for(i=0;i<puntos.niveles[j];i++)
                {
                    fprintf(arch,"%s\n%d\n",puntos.puntajes[i].nom,puntos.puntajes[i].m_puntos_n);
                }
            else if(j==1)
                for(t=5,i=0;i<puntos.niveles[j];i++)
                {
                    fprintf(arch,"%s\n%d\n",puntos.puntajes[t].nom,puntos.puntajes[t].m_puntos_n);
                }
            else if(j==2)
                for(t=10,i=0;i<puntos.niveles[j];i++)
                {
                    fprintf(arch,"%s\n%d\n",puntos.puntajes[t].nom,puntos.puntajes[t].m_puntos_n);
                }
    }
    fclose(arch);
}
void guardar5puntos (adm puntos)
{
    FILE *arch;
    int i,j,t;
    arch=fopen("mej5puntos.txt","w");
    i=0;
    if(arch!=NULL)
    {
                for(i=0;i<puntos.unico;i++)
                {
                    fprintf(arch,"%s\n%d\n",puntos.punta[i].nom,puntos.punta[i].m_puntos_t);
                }
    }
    fclose(arch);
}
void g_p_j (adm nivel)
{
    FILE *arch;
    int i;
    arch=fopen("mejore_partidas.txt","w");
    if (arch != NULL)
	{
	    for(i=0;i<3;i++)
            fprintf(arch,"%d ",nivel.niveles[i]);
		fclose(arch);
	}
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
void mejores (adm *juegos,punt puntos,jug nom)
{
    if(juegos->table==1)         /**  5 MEJORES FACIL    **/
    {
        if (juegos->niveles[0]==0)
        {
            juegos->puntajes[0].m_puntos_n=puntos.nivel;
            strcpy(juegos->puntajes[0].nom,nom.nombre);
        }
        else if (juegos->niveles[0]==1)
        {
            juegos->puntajes[1].m_puntos_n=puntos.nivel;
            strcpy(juegos->puntajes[1].nom,nom.nombre);
        }
        else if (juegos->niveles[0]==2)
        {
            juegos->puntajes[2].m_puntos_n=puntos.nivel;
            strcpy(juegos->puntajes[2].nom,nom.nombre);
        }
        else if (juegos->niveles[0]==3)
        {
            juegos->puntajes[3].m_puntos_n=puntos.nivel;
            strcpy(juegos->puntajes[3].nom,nom.nombre);
        }
        else if (juegos->niveles[0]==4)
        {
            juegos->puntajes[4].m_puntos_n=puntos.nivel;
            strcpy(juegos->puntajes[4].nom,nom.nombre);
        }
        juegos->niveles[0]++;
    }
    if(juegos->table==2)        /**  5 MEJORES MEDIO    **/
    {
        if (juegos->niveles[1]==0)
        {
            juegos->puntajes[5].m_puntos_n=puntos.nivel;
            strcpy(juegos->puntajes[5].nom,nom.nombre);
        }
        else if (juegos->niveles[1]==1)
        {
            juegos->puntajes[6].m_puntos_n=puntos.nivel;
            strcpy(juegos->puntajes[6].nom,nom.nombre);
        }
        else if (juegos->niveles[1]==2)
        {
            juegos->puntajes[7].m_puntos_n=puntos.nivel;
            strcpy(juegos->puntajes[7].nom,nom.nombre);
        }
        else if (juegos->niveles[1]==3)
        {
            juegos->puntajes[8].m_puntos_n=puntos.nivel;
            strcpy(juegos->puntajes[8].nom,nom.nombre);
        }
        else if (juegos->niveles[1]==4)
        {
            juegos->puntajes[9].m_puntos_n=puntos.nivel;
            strcpy(juegos->puntajes[9].nom,nom.nombre);
        }
        juegos->niveles[1]=juegos->niveles[0]+1;
    }
    if(juegos->table==3)       /**  5 MEJORES DIFICIL  **/
    {
        if (juegos->niveles[2]==0)
        {
            juegos->puntajes[10].m_puntos_n=puntos.nivel;
            strcpy(juegos->puntajes[10].nom,nom.nombre);
        }
        else if (juegos->niveles[2]==1)
        {
            juegos->puntajes[11].m_puntos_n=puntos.nivel;
            strcpy(juegos->puntajes[11].nom,nom.nombre);
        }
        else if (juegos->niveles[2]==2)
        {
            juegos->puntajes[12].m_puntos_n=puntos.nivel;
            strcpy(juegos->puntajes[12].nom,nom.nombre);
        }
        else if (juegos->niveles[2]==3)
        {
            juegos->puntajes[13].m_puntos_n=puntos.nivel;
            strcpy(juegos->puntajes[13].nom,nom.nombre);
        }
        else if (juegos->niveles[2]==4)
        {
            juegos->puntajes[14].m_puntos_n=puntos.nivel;
            strcpy(juegos->puntajes[14].nom,nom.nombre);
        }
        juegos->niveles[2]=juegos->niveles[0]+1;
    }
    ordenar_mejores(juegos);
}
void mejores5 (adm *juegos,punt puntos,jug nom)
{
    if (juegos->unico==0)
    {
        juegos->punta[0].m_puntos_t=puntos.nivel;
        strcpy(juegos->punta[0].nom,nom.nombre);
    }
    else if (juegos->unico==1)
    {
        juegos->punta[1].m_puntos_t=puntos.nivel;
        strcpy(juegos->punta[1].nom,nom.nombre);
    }
    else if (juegos->unico==2)
    {
        juegos->punta[2].m_puntos_t=puntos.nivel;
        strcpy(juegos->punta[2].nom,nom.nombre);
    }
    else if (juegos->unico==3)
    {
        juegos->punta[3].m_puntos_t=puntos.nivel;
        strcpy(juegos->punta[3].nom,nom.nombre);
    }
    else if (juegos->unico==4)
    {
        juegos->punta[4].m_puntos_t=puntos.nivel;
        strcpy(juegos->punta[4].nom,nom.nombre);
    }
    juegos->unico++;

}
void ordenar_mejores(adm *juegos)
{
    int i,m,j,l;

    for(l=0;l<5;l++)
    {
        for(m=0;m<3;m++)
            for(i=0;i<=juegos->niveles[m]&&i!=5;i++)
            {
                if(juegos->puntajes[i].m_puntos_n>juegos->puntajes[i+1].m_puntos_n&&juegos->puntajes[i+1].m_puntos_n!=0)
                {
                    juegos->puntajes[16].m_puntos_n=juegos->puntajes[i].m_puntos_n;
                    strcpy(juegos->puntajes[16].nom,juegos->puntajes[i].nom);
                    juegos->puntajes[i].m_puntos_n=juegos->puntajes[i+1].m_puntos_n;
                    strcpy(juegos->puntajes[i].nom,juegos->puntajes[i+1].nom);
                    juegos->puntajes[i+1].m_puntos_n=juegos->puntajes[16].m_puntos_n;
                    strcpy(juegos->puntajes[i+1].nom,juegos->puntajes[16].nom);
                }
            }
    }
}
void ordenar_mejores5(adm *juegos)
{
    int i,j,l;
    for(l=0;l<5;l++)
    {
            for(i=0;i<=juegos->unico&&i!=5;i++)
            {
                if(juegos->punta[i].m_puntos_t>juegos->punta[i+1].m_puntos_t&&juegos->punta[i+1].m_puntos_t!=0)
                {
                    juegos->punta[6].m_puntos_t=juegos->punta[i].m_puntos_t;
                    strcpy(juegos->punta[6].nom,juegos->punta[i].nom);
                    juegos->punta[i].m_puntos_t=juegos->punta[i+1].m_puntos_t;
                    strcpy(juegos->punta[i].nom,juegos->punta[i+1].nom);
                    juegos->punta[i+1].m_puntos_t=juegos->punta[6].m_puntos_t;
                    strcpy(juegos->punta[i+1].nom,juegos->punta[6].nom);
                }
            }
    }
}

char rastro (jug jugador)
{
    char opc, j;
    do
    {
        system("cls");
        printf("\n\n\n\n\n\n\t\t\t%s ESCOJA EL TIPO DE RASTRO\n\n\n\t\t\t1.FACIL\n\n\n\t\t\t2.MEDIO\n\n\n\t\t\t3.DIFICIL\n\n\n\t\t\t4.VOLVER AL MENU ANTERIOR\n\n\n\t\t\t",jugador.nombre);
        opc=getch();
        switch(opc)
        {
            case UNO:
                return(UNO);
                j=1;
            break;
            case DOS:
                return(DOS);
                j=1;
            break;
            case TRES:
                return(TRES);
                j=1;
            break;
            case CUATRO:
                return(CUATRO);
                j=1;
            break;
        }
    }while(j!=0);

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
