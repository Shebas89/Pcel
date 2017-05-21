/******************************************************************************
*                            PROGRAMA PACCEL                                  *
*******************************************************************************
* PROPOSITO : Desarrollar un juego similar al popular PACMAN utilizando todos *
*             los conocimientos adquiridos durante el semestre en el curso de *
*             programacion.                                                   *
*                                                                             *
* AUTOR(ES) : Andres Camilo Bohorquez Castillo                                *
* FECHA     : 26/04/08                                                        *
* ASIGNATURA: PCEL - 5                                                        *
******************************************************************************/

/******************************************************************************
*                      ENCABEZADO DE LAS BIBLIOTECAS                          *
******************************************************************************/
# include<stdio.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

/******************************************************************************
*                                CONSTANTES                                   *
******************************************************************************/
# define C 50  //CARACTERES
# define I 20  //FILAS
# define J 50  //COLUMNAS
# define JU 20 //MAXIMO DE JUGADORES
# define G 46  //galletas
# define PA 1  //paccel
# define F 2   //Fantasmas
# define V 36  // vitaminas
# define P 42  //paredes
# define EV 32 // ESPACIO VACIO




/*****************************************************************************
*                       ESTRUCTURAS Y TIPOS DE DATOS                         *
*****************************************************************************/
struct datos_jugador
{
    char nombre[C];
    int puntaje;
    int fecha;
    int duracion;
        int tablero_de_juego[I][J];
};

struct puntajes
{
    char nombre[C];
    int puntaje;
    int fecha;
    double duracion;
    int ultimo_tablero_de_juego[I][J];
};

struct juego_guardado
{
    char nombre[C];
    int puntaje;
    char fecha;
    double duracion;
    char partida_guardada[I][J];
    int numero_de_estado_del_ultimo_tablero;
    int num_galletas;
    int vidas;
    int f,c,ff1,cf1,ff2,cf2,ff3,cf3,ff4,cf4;
    char v_o_g1,v_o_g2,v_o_g3,v_o_g4;
    int cont_de_puntaje;
};

struct tablero
{
    char tablerito[I][J];
};

struct admon
{
    struct datos_jugador players[JU];
    struct puntajes mejores_5_puntajes[5];
    struct juego_guardado partida[JU];
    struct tablero boards[5];
};

struct tm *fechaComienzoPtr, *fechafinalPtr;


/*****************************************************************************
*                     PROTOTIPOS DE LOS SUBPROGRAMAS                         *
*****************************************************************************/

void ayuda(void);
void cargar_tablero(struct tablero *,int);
int contar_galletas(struct tablero *);
void imprimir_tablero(struct tablero );
void inicializar_cont_de_mejores_puntajes(int *);
void movimiento_fantasmas(struct tablero *t,int *ff,int *cf,int *vidas,char *v_o_g,int *f,int *c,int band_de_fantasma,int *ff1,int *cf1,int *ff2,int *cf2,int *ff3,int *cf3,int *ff4,int *cf4,char *v_o_g1,char *v_o_g2,char *v_o_g3,char *v_o_g4);
int mover_arriba(struct tablero *t,int *f,int *c,int *num_galletas,int *puntaje,int *cont_de_puntaje,int *vidas,char *v_o_g1,char *v_o_g2,char *v_o_g3,char *v_o_g4,int *ff1,int *cf1,int *ff2,int *cf2,int *ff3,int *cf3,int *ff4,int *cf4);
int mover_izquierda(struct tablero *t,int *f,int *c,int *num_galletas,int *puntaje,int *cont_de_puntaje,int *vidas,char *v_o_g1,char *v_o_g2,char *v_o_g3,char *v_o_g4,int *ff1,int *cf1,int *ff2,int *cf2,int *ff3,int *cf3,int *ff4,int *cf4);
int mover_derecha(struct tablero *t,int *f,int *c,int *num_galletas,int *puntaje,int *cont_de_puntaje,int *vidas,char *v_o_g1,char *v_o_g2,char *v_o_g3,char *v_o_g4,int *ff1,int *cf1,int *ff2,int *cf2,int *ff3,int *cf3,int *ff4,int *cf4);
int mover_abajo(struct tablero *t,int *f,int *c,int *num_galletas,int *puntaje,int *cont_de_puntaje,int *vidas,char *v_o_g1,char *v_o_g2,char *v_o_g3,char *v_o_g4,int *ff1,int *cf1,int *ff2,int *cf2,int *ff3,int *cf3,int *ff4,int *cf4);
void abrir_cont_de_juegos_guardados(int *cont_de_partidas_guardadas);
void guardar_cont_de_juegos_guardados(int cont_de_partidas_guardadas);
void guardar_partida(struct juego_guardado t);
void recargar_partida(struct juego_guardado t[JU],int cont_de_partidas_guardadas,char nom[C],int *band_de_carga,int *f,int *c,int *ff1,int *cf1,int *ff2,int *cf2,int *ff3,int *cf3,int *ff4,int *cf4,char *v_o_g1,char *v_o_g2,char *v_o_g3,char *v_o_g4,int *vidas,int *cont,int *cont_de_puntaje,struct tablero [5],int *puntaje,int *num_galletas);
void validar_mejores_puntajes(int punt,struct puntajes m[5],char nom[C],time_t final,time_t comienzo,struct tablero ultimo_tablero,int);
void ordenar_mejores_puntajes(struct puntajes m[5],int ,int punt,char nom[C],struct tablero ultimo_tablero,time_t final,time_t comienzo);
void ver_mejores_puntajes(struct puntajes m[5],int*);
void despedida();

/*****************************************************************************
*                        PROGRAMA PRINCIPAL                                  *
*****************************************************************************/

int main (void)
{
        struct admon paccel ;
		struct tm *tmPtr;
        int cont,num_galletas,f,c,vidas,puntaje,cont_de_puntaje,band,opc,band2,cont2,x,ff1,cf1,ff2,cf2,ff3,cf3,ff4,cf4,cont_de_partidas_guardadas,i,j,band_de_fantasma,num_limite,band_de_kbjit,band_de_carga;
        char mov,v_o_g1,v_o_g2,v_o_g3,v_o_g4,opc2,nom[C],info_tiempo_inicial[C],info_tiempo_final[C];
        time_t comienzo, final,inicio_fan,final_fan,tiempo_juego;

        band=0;
        cont=0;         //INICIALIZO VARIABLES PRINCIPALES
        vidas=3;
        puntaje=0;
		band_de_carga=0;

        inicializar_cont_de_mejores_puntajes(&num_limite);

        while(band==0)
        {
			if(band_de_carga==0)
			{

                system("cls");
                for(cont2=0;cont2<5;cont2++)
                {
                        cargar_tablero(&paccel.boards[cont2],cont2);    //CARGO LOS 5 TABLEROS POR ARCHIVOS DE TEXTO
                }
			}

                printf("\n\n\n\n\n\n\t\t\tESCOJA UNA OPCION\n\n\n\t\t\t1.EMPEZAR A JUGAR\n\n\n\t\t\t2.AYUDA\n\n\n\t\t\t3.PARTIDAS GUARDADAS\n\n\n\t\t\t4.MEJORES PUNTAJES\n\n\n\t\t\t5.SALIR\n");
                opc=getch();
                switch(opc)
                {
                        case '1':		band_de_kbjit=0;
										if(band_de_carga==0)
										{
											system("cls");
											cont=0;
											vidas=3;
											puntaje=0;
											cont_de_puntaje=5000;

											num_galletas=20/*contar_galletas(&paccel.boards[cont])*/;
											f=15;
											c=17;
											ff1=8;
											cf1=14;
											ff2=8;
											cf2=18;
											ff3=9;
											cf3=14;
											ff4=9;
											cf4=18;
											v_o_g1=EV;
											v_o_g2=EV;
											v_o_g3=EV;
											v_o_g4=EV;
											band2=0;
											printf("\n\n\n\t\t\tPor favor digite su nombre\n\t\t\t");
											gets(nom);
											system("cls");
										}
										system("cls");
											imprimir_tablero(paccel.boards[cont]);
											printf("\n\t\tgalletas:%d\n",num_galletas);
											printf("\t\tpuntaje:%d\n",puntaje);
											printf("\t\tvidas:%d\n",vidas);
											printf("\t\ttablero: %d\n",cont+1);
											printf("\n\n\nOprima p para pausar el juego                    Oprima g para guardar el juego\n\n\t\t\t\tOprima s para salir\n");
                                comienzo = time( NULL );
								tiempo_juego = time(NULL);
								tmPtr = localtime(& tiempo_juego);
								strftime( info_tiempo_inicial, C, "%H:%M.%S, %A de %B de %Y", tmPtr );

                                while(vidas>0 && cont<5)  //CICLO DE JUEGO
                                {
                                        if(opc2=='r')
                                        {
                                                imprimir_tablero(paccel.boards[cont]);
                                                printf("\n\tgalletas:%d\n",num_galletas);
                                                printf("\tpuntaje:%d\n",puntaje);
                                                printf("\t\tvidas:%d\n",vidas);
                                                printf("\t\ttablero: %d\n",cont+1);
                                                printf("\n\n\nOprima p para pausar el juego                    Oprima g para guardar el juego\n\n\t\t\t\tOprima s para salir\n");

                                                opc2='t';
                                        }

                                        mov=getch();
                                        //printf("mov:%c\n",mov);


                                                        switch(mov)
                                                        {                                //MOVIMIENTO HACIA ARRIBA
                                                                case 'i':       system("cls");
                                                                                x=mover_arriba(&paccel.boards[cont],&f,&c,&num_galletas,&puntaje,&cont_de_puntaje,&vidas,&v_o_g1,&v_o_g2,&v_o_g3,&v_o_g4,&ff1,&cf1,&ff2,&cf2,&ff3,&cf3,&ff4,&cf4);
                                                                                if(x==1)
                                                                                {
                                                                                        cont++;
                                                                                        num_galletas=20/*contar_galletas(&paccel.boards[cont])*/;
                                                                                        f=15;
                                                                                        c=17;
                                                                                        ff1=8;
                                                                                        cf1=14;

                                                                                        ff2=8;
                                                                                        cf2=18;

                                                                                        ff3=9;
                                                                                        cf3=14;

                                                                                        ff4=9;
                                                                                        cf4=18;
                                                                                        v_o_g1=EV;
                                                                                        v_o_g2=EV;
                                                                                        v_o_g3=EV;
                                                                                        v_o_g4=EV;
                                                                                }
                                                                                if(cont<5)
                                                                                {

                                                                                        imprimir_tablero(paccel.boards[cont]);

                                                                                        printf("\n\t\tgalletas:%d\n",num_galletas);
                                                                                        printf("\t\tpuntaje:%d\n",puntaje);
                                                                                        printf("\t\tvidas:%d\n",vidas);
                                                                                        printf("\t\ttablero: %d\n",cont+1);
                                                                                        printf("\n\n\nOprima p para pausar el juego                    Oprima g para guardar el juego\n\n\t\t\t\tOprima s para salir\n");
                                                                                }




                                                                break;
                                                                case 'j':  //MOVIMIENTO HACIA ABAJO
                                                                                system("cls");

                                                                                x=mover_izquierda(&paccel.boards[cont],&f,&c,&num_galletas,&puntaje,&cont_de_puntaje,&vidas,&v_o_g1,&v_o_g2,&v_o_g3,&v_o_g4,&ff1,&cf1,&ff2,&cf2,&ff3,&cf3,&ff4,&cf4);
                                                                                if(x==1)
                                                                                {
                                                                                        cont++;
                                                                                        num_galletas=20/*contar_galletas(&paccel.boards[cont])*/;
                                                                                        f=15;
                                                                                        c=17;
                                                                                        ff1=8;
                                                                                        cf1=14;

                                                                                        ff2=8;
                                                                                        cf2=18;

                                                                                        ff3=9;
                                                                                        cf3=14;

                                                                                        ff4=9;
                                                                                        cf4=18;
                                                                                        v_o_g1=EV;
                                                                                        v_o_g2=EV;
                                                                                        v_o_g3=EV;
                                                                                        v_o_g4=EV;
                                                                                }
                                                                                if(cont<5)
                                                                                {
                                                                                        imprimir_tablero(paccel.boards[cont]);

                                                                                        printf("\n\t\tgalletas:%d\n",num_galletas);
                                                                                        printf("\t\tpuntaje:%d\n",puntaje);
                                                                                        printf("\t\tvidas:%d\n",vidas);
                                                                                        printf("\t\ttablero: %d\n",cont+1);
                                                                                        printf("\n\n\nOprima p para pausar el juego                    Oprima g para guardar el juego\n\n\t\t\t\tOprima s para salir\n");

                                                                                }



                                                                break;
                                                                case 'l':   ////MOVIMIENTO HACIA LA DERECHA

                                                                                system("cls");

                                                                                x=mover_derecha(&paccel.boards[cont],&f,&c,&num_galletas,&puntaje,&cont_de_puntaje,&vidas,&v_o_g1,&v_o_g2,&v_o_g3,&v_o_g4,&ff1,&cf1,&ff2,&cf2,&ff3,&cf3,&ff4,&cf4);
                                                                                if(x==1)
                                                                                {
                                                                                        cont++;
                                                                                        num_galletas=20/*contar_galletas(&paccel.boards[cont])*/;
                                                                                        f=15;
                                                                                        c=17;
                                                                                        ff1=8;
                                                                                        cf1=14;

                                                                                        ff2=8;
                                                                                        cf2=18;

                                                                                        ff3=9;
                                                                                        cf3=14;

                                                                                        ff4=9;
                                                                                        cf4=18;
                                                                                        v_o_g1=EV;
                                                                                        v_o_g2=EV;
                                                                                        v_o_g3=EV;
                                                                                        v_o_g4=EV;
                                                                                }
                                                                                if(cont<5)
                                                                                {
                                                                                        imprimir_tablero(paccel.boards[cont]);

                                                                                        printf("\n\t\tgalletas:%d\n",num_galletas);
                                                                                        printf("\t\tpuntaje:%d\n",puntaje);
                                                                                        printf("\t\tvidas:%d\n",vidas);
                                                                                        printf("\t\ttablero: %d\n",cont+1);
                                                                                        printf("\n\n\nOprima p para pausar el juego                    Oprima g para guardar el juego\n\n\t\t\t\tOprima s para salir\n");

                                                                                }



                                                                break;
                                                                case 'k':  //MOVIMIENTO HACIA LA IZQUIERDA

                                                                                system("cls");
                                                                                x=mover_abajo(&paccel.boards[cont],&f,&c,&num_galletas,&puntaje,&cont_de_puntaje,&vidas,&v_o_g1,&v_o_g2,&v_o_g3,&v_o_g4,&ff1,&cf1,&ff2,&cf2,&ff3,&cf3,&ff4,&cf4);
                                                                                if(x==1)
                                                                                {
                                                                                        cont++;
                                                                                        num_galletas=20/*contar_galletas(&paccel.boards[cont])*/;
                                                                                        f=15;
                                                                                        c=17;
                                                                                        ff1=8;
                                                                                        cf1=14;

                                                                                        ff2=8;
                                                                                        cf2=18;

                                                                                        ff3=9;
                                                                                        cf3=14;

                                                                                        ff4=9;
                                                                                        cf4=18;
                                                                                        v_o_g1=EV;
                                                                                        v_o_g2=EV;
                                                                                        v_o_g3=EV;
                                                                                        v_o_g4=EV;
                                                                                }
                                                                                if(cont<5)
                                                                                {
                                                                                        imprimir_tablero(paccel.boards[cont]);

                                                                                        printf("\n\t\tgalletas:%d\n",num_galletas);
                                                                                        printf("\t\tpuntaje:%d\n",puntaje);
                                                                                        printf("\t\tvidas:%d\n",vidas);
                                                                                        printf("\t\ttablero: %d\n",cont+1);
                                                                                        printf("\n\n\nOprima p para pausar el juego                    Oprima g para guardar el juego\n\n\t\t\t\tOprima s para salir\n");

                                                                                }


                                                                break;
                                                                case 'p':  //OPCION DE PAUSA
                                                                                  system("cls");



                                                                                  while(opc2!='r')
                                                                                  {
                                                                                          while(kbhit()==0)
                                                                                          {
                                                                                                  system("cls");
                                                                                                  printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tEl juego ha sido pausado\n\n\n\t\t\tPara reanudarlo oprima r\n");
                                                                                          }
                                                                                          opc2=getch();

                                                                                          system("cls");
                                                                                  }

                                                                break;
                                                                case 'g':				final = time( NULL );
                                                                                        /*SE ABRE EL CONTADOR DONDE ESTA EL NUMERO EN EL QUE SE GUARDARA LA PARTIDA*/
                                                                                        abrir_cont_de_juegos_guardados(&cont_de_partidas_guardadas);
                                                                                        printf("el juego se guardara en la casilla:%d\n",cont_de_partidas_guardadas);
                                                                                        printf("puntaje:%d\n",puntaje);
                                                                                        paccel.partida[cont_de_partidas_guardadas].puntaje=puntaje;
                                                                                        printf("puntaje:%d\n",paccel.partida[cont_de_partidas_guardadas].puntaje);

                                                                                        for(i=0;i<I;i++)
                                                                                        {
                                                                                                for(j=0;j<J;j++)
                                                                                                {
                                                                                                        paccel.partida[cont_de_partidas_guardadas].partida_guardada[i][j]=paccel.boards[cont].tablerito[i][j];
                                                                                                }
                                                                                        }
                                                                                        paccel.partida[cont_de_partidas_guardadas].numero_de_estado_del_ultimo_tablero=cont;

                                                                                        paccel.partida[cont_de_partidas_guardadas].duracion=difftime(final, comienzo);

                                                                                                strcpy(paccel.partida[cont_de_partidas_guardadas].nombre,nom);

																						paccel.partida[cont_de_partidas_guardadas].f=f;
																						paccel.partida[cont_de_partidas_guardadas].c=c;
																						paccel.partida[cont_de_partidas_guardadas].ff1=ff1;
																						paccel.partida[cont_de_partidas_guardadas].cf1=cf1;
																						paccel.partida[cont_de_partidas_guardadas].ff2=ff2;
																						paccel.partida[cont_de_partidas_guardadas].cf2=cf2;
																						paccel.partida[cont_de_partidas_guardadas].ff3=ff3;
																						paccel.partida[cont_de_partidas_guardadas].cf3=cf3;
																						paccel.partida[cont_de_partidas_guardadas].ff4=ff4;
																						paccel.partida[cont_de_partidas_guardadas].cf4=cf4;
																						paccel.partida[cont_de_partidas_guardadas].v_o_g1=v_o_g1;
																						paccel.partida[cont_de_partidas_guardadas].v_o_g2=v_o_g2;
																						paccel.partida[cont_de_partidas_guardadas].v_o_g3=v_o_g3;
																						paccel.partida[cont_de_partidas_guardadas].v_o_g4=v_o_g4;
																						paccel.partida[cont_de_partidas_guardadas].vidas=vidas;
																						paccel.partida[cont_de_partidas_guardadas].cont_de_puntaje=cont_de_puntaje;
																						paccel.partida[cont_de_partidas_guardadas].num_galletas=num_galletas;



                                                                                        guardar_partida(paccel.partida[cont_de_partidas_guardadas]);

																						cont_de_partidas_guardadas++;
																						guardar_cont_de_juegos_guardados(cont_de_partidas_guardadas);

																						system("cls");
                                                                                        printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tEl juego ha sido guardado\n\n\n\t\t\tPara reanudarlo oprima enter\n");
																						getchar();







                                                                break;

                                                                case 's':   //SALIDA DEL JUEGO
                                                                                        vidas=0;
                                                                break;

                                                        }

										inicio_fan=time(NULL);

                                        while(kbhit()==0 && band_de_kbjit==0)
                                        {
                                                final_fan=time(NULL);

                                                if(difftime(final_fan,inicio_fan>20))
                                                {
                                                        band_de_fantasma=rand()%8;
                                                        movimiento_fantasmas(&paccel.boards[cont],&ff1,&cf1,&vidas,&v_o_g1,&f,&c,band_de_fantasma,&ff1,&cf1,&ff2,&cf2,&ff3,&cf3,&ff4,&cf4,&v_o_g1,&v_o_g2,&v_o_g3,&v_o_g4);
                                                        band_de_fantasma=rand()%8;
                                                        movimiento_fantasmas(&paccel.boards[cont],&ff2,&cf2,&vidas,&v_o_g2,&f,&c,band_de_fantasma,&ff1,&cf1,&ff2,&cf2,&ff3,&cf3,&ff4,&cf4,&v_o_g1,&v_o_g2,&v_o_g3,&v_o_g4);
                                                        band_de_fantasma=rand()%8;
                                                        movimiento_fantasmas(&paccel.boards[cont],&ff3,&cf3,&vidas,&v_o_g3,&f,&c,band_de_fantasma,&ff1,&cf1,&ff2,&cf2,&ff3,&cf3,&ff4,&cf4,&v_o_g1,&v_o_g2,&v_o_g3,&v_o_g4);
                                                        band_de_fantasma=rand()%8;
                                                        movimiento_fantasmas(&paccel.boards[cont],&ff4,&cf4,&vidas,&v_o_g4,&f,&c,band_de_fantasma,&ff1,&cf1,&ff2,&cf2,&ff3,&cf3,&ff4,&cf4,&v_o_g1,&v_o_g2,&v_o_g3,&v_o_g4);

                                                        if(vidas>0 && cont<5)
                                                        {
                                                                system("cls");

                                                                imprimir_tablero(paccel.boards[cont]);

                                                                printf("\n\t\tgalletas:%d\n",num_galletas);
                                                                printf("\t\tpuntaje:%d\n",puntaje);
                                                                printf("\t\tvidas:%d\n",vidas);
                                                                printf("\t\ttablero: %d\n",cont+1);
                                                                printf("\n\n\nOprima p para pausar el juego                    Oprima g para guardar el juego\n\n\t\t\t\tOprima s para salir\n");
                                                                system("cls");
                                                        }

														else
														{
															band_de_kbjit=1;
														}
														inicio_fan=time(NULL);
                                                }
                                        }



                                }


                                final = time( NULL );
                                printf("\n\n\nel programa ha tenido una duracion de %.1f segundos\n",difftime(final, comienzo));
								if(cont>=5)
								{
									 validar_mejores_puntajes(puntaje,paccel.mejores_5_puntajes,nom,final,comienzo,paccel.boards[cont-1],num_limite);
								}
								else
								{
									validar_mejores_puntajes(puntaje,paccel.mejores_5_puntajes,nom,final,comienzo,paccel.boards[cont],num_limite);
								}

								tiempo_juego = time(NULL);
								tmPtr = localtime(& tiempo_juego);
								strftime( info_tiempo_final, C, "%H:%M.%S, %A de %B de %Y", tmPtr );


								printf( "La hora y fecha de comienzo del juego fue: %s\nLa hora y fecha en que finalizo el juego fue: %s\n", info_tiempo_inicial,info_tiempo_final );



                                despedida();
                                getchar();
								band_de_carga=0;
                                system("cls");

                                break;
                                case '2':  //OPCION DE AYUDA E INSTRUCCIONES AL USUARIO
                                           system("cls");
                                           ayuda();
                                           printf("presione enter para salir");
                                           getchar();
										   system("cls");
                                break;
                                case '3': //CARGA DE JUEGOS GUARDADOS


                                           abrir_cont_de_juegos_guardados(&cont_de_partidas_guardadas);
										   if(cont_de_partidas_guardadas==0)
										   {
											   printf("no hay juegos guardados\n");
											   getchar();

										   }
										   else
										   {

											   printf("digite su nombre\n");
											   gets(nom);
											   recargar_partida(paccel.partida,cont_de_partidas_guardadas,nom,&band_de_carga,&f,&c,&ff1,&cf1,&ff2,&cf2,&ff3,&cf3,&ff4,&cf4,&v_o_g1,&v_o_g2,&v_o_g3,&v_o_g4,&vidas,&cont,&cont_de_puntaje,paccel.boards,&puntaje,&num_galletas);
										   }









                                break;
                                case '4':  //OPCION DE CONSULTA MEJORES PUNTAJES
                                                        system("cls");
                                                        ver_mejores_puntajes(paccel.mejores_5_puntajes,&num_limite);
                                                        printf("presione enter para salir");
                                                        getchar();
														system("cls");



                                break;
                                case '5'://DESPEDIDA
                                                 despedida();
                                                 band=1;
                                break;

                }
        }


}


/*****************************************************************************
*                           SUBPROGRAMAS                                     *
*****************************************************************************/

/*---------------------------------------------------------------------------+
| Encabezado del subprograma : ayuda
+----------------------------------------------------------------------------+
| DES     : Muestra al usuario una breve explicacion de lo que es el juego,su
            objetivo y sus posibilidades y le explica que opciones tiene para
            desplazarse por el tablero.
| PRE     : ninguna.
| POS     : imprime por pantalla una explicacion del juego al usuario.
+---------------------------------------------------------------------------*/

void ayuda(void)
{
        printf("\n\t\t\tBIENVENIDO A PACCEL!!!!!\nEste juego consiste en desplazar a PACCEL por medio de un laberinto con el fin de comerse todas las galletas que estan distribuidas al interior de este.\nCuando PACCEL se ha comido la totalidad de las galletas, el juego pasa al siguiente nivel.\nOJO:Hay que tener en cuenta que cuatro fantasmas rondan el laberinto y siempre estan intentando atrapar a PACCEL.\nSi un fantasma toca a PACCEL, se pierde una vida de las tres iniciales.\n\nCada galleta tiene un valor de 100 puntos y cuando ud. y su habilidad alcancen un puntaje de 5000 PACCEL obtendra una vida adicional.\n\n\nPara mover al PACCEL ud tiene las siguientes opciones:\n\n-oprima i para moverlo hacia arriba\n-oprima k para moverlo hacia abajo\n-oprima j para moverlo hacia la izquierda\n-oprima l para moverlo hacia la derecha\n\n\n\n\t\t\tMUCHA SUERTE!!!!\n\n\n");
}

/*---------------------------------------------------------------------------+
| Encabezado del subprograma : cargar_tablero
+----------------------------------------------------------------------------+
| DES     : Carga los 5 tableros de juego del PACCEL desde archivos de texto
            y valida las posiciones especificas de los fantasmas y el PACCEL.
| PRE     : Necesita la estructura de tablero en sus 5 espacios para asi
            modificar y cargar los 5 tableros dejuego.
| POS     : Modifica los tableros que hay en los 5 "boards" para poder
            cargarlos a la hora del juego.
+---------------------------------------------------------------------------*/

void cargar_tablero(struct tablero *tableros,int cont)
{
        FILE *tablero;
        int i,j;

		if(cont==0)
		{

			tablero=fopen("tablero.txt","r");
			if(tablero==NULL)
			{
					printf("error\n");
			}
			else
			{
					for(i=0;i<20;i++)
					{
							for(j=0;j<50;j++)
							{
									tableros->tablerito[i][j]=fgetc(tablero);

							}

							fgetc(tablero);

					}



			}
		}
		if(cont==1)
		{
			tablero=fopen("tablero2.txt","r");
			if(tablero==NULL)
			{
					printf("error\n");
			}
			else
			{
					for(i=0;i<20;i++)
					{
							for(j=0;j<50;j++)
							{
									tableros->tablerito[i][j]=fgetc(tablero);

							}

							fgetc(tablero);

					}



			}
		}
		if(cont==2)
		{
			tablero=fopen("tablero3.txt","r");
			if(tablero==NULL)
			{
					printf("error\n");
			}
			else
			{
					for(i=0;i<20;i++)
					{
							for(j=0;j<50;j++)
							{
									tableros->tablerito[i][j]=fgetc(tablero);

							}

							fgetc(tablero);

					}



			}
		}
		if(cont==3)
		{
			tablero=fopen("tablero4.txt","r");
			if(tablero==NULL)
			{
					printf("error\n");
			}
			else
			{
					for(i=0;i<20;i++)
					{
							for(j=0;j<50;j++)
							{
									tableros->tablerito[i][j]=fgetc(tablero);

							}

							fgetc(tablero);

					}


			}
		}
		if(cont==4)
		{
			tablero=fopen("tablero5.txt","r");
			if(tablero==NULL)
			{
					printf("error\n");
			}
			else
			{
					for(i=0;i<20;i++)
					{
							for(j=0;j<50;j++)
							{
									tableros->tablerito[i][j]=fgetc(tablero);

							}

							fgetc(tablero);

					}


			}
		}
		//DEFINICION DE POSICION DE PACCEL Y FANTASMAS
		tableros->tablerito[8][14]=F;
		tableros->tablerito[8][18]=F;
		tableros->tablerito[9][14]=F;
		tableros->tablerito[9][18]=F;
		tableros->tablerito[15][17]=PA;


}

/*---------------------------------------------------------------------------+
| Encabezado del subprograma : contar_galletas
+----------------------------------------------------------------------------+
| DES     : Cuenta el numero de galletas que existen en cada tablero para
                        posteriormente validar la permanencia en un cilo o no,
                        especificamente para permanecer en un tablero o pasar al siguiente.
                        Este numero de galletas se ira descontando en el principal para
                        validar dicha operacion de cambio de tablero.
| PRE     : Necesita cada tablero en el que el usuario se encuentre actualmente
                        jugando.
| POS     : Retorna el valor de la cantidad de galletas a un contador .
+---------------------------------------------------------------------------*/


int contar_galletas(struct tablero *t)
{
        int num_galletas,i,j;

        num_galletas=0;
        for(i=0;i<I;i++)
        {
                for(j=0;j<J;j++)
                {
                        if(t->tablerito[i][j]==G)
                        {
                                num_galletas++;
                        }

                }

        }
        return(num_galletas);
}

/*---------------------------------------------------------------------------+
| Encabezado del subprograma : imprimir_tablero
+----------------------------------------------------------------------------+
| DES     : Imprime el tablero por pantalla para que en el principal se
                        visualize el estado del tablero, es decir el numero de galletas,
                        de vitaminas, la posicion de los fantasmas y la del PACCEL.
| PRE     : Necesita una copia de cada tablero en el que el usuario se encuentre
                        actualmente jugando.
| POS     : Imprime por pantalla el tablero en el que se encuentre el jugador.
+---------------------------------------------------------------------------*/


void imprimir_tablero(struct tablero t)
{
        int i,j;
        printf("\n\n\n\t\t");
        for(i=0;i<I;i++)
        {
           for(j=0;j<J;j++)
           {
               printf("%c",t.tablerito[i][j]);

           }
           printf("\n\t\t");


        }
}

/*---------------------------------------------------------------------------+
| Encabezado del subprograma :inicializar_cont_de_mejores_puntajes
+----------------------------------------------------------------------------+
| DES     : inicializa una variable que llevara el control de los mejores
			puntajes en cuanto a la totalidad.
| PRE     : Necesita la variable num_limite para modificarla y que sirva de
			limite en un ciclo en el que se guardan los mejores puntajes.
| POS     : modifica la varable num_limite.
+---------------------------------------------------------------------------*/


void inicializar_cont_de_mejores_puntajes(int *num_limite)
{
        FILE *validar_numero_juegos;

        validar_numero_juegos=fopen("limite de juegos guardados.txt","r");
        if(validar_numero_juegos==NULL)
        {
                *num_limite=0;

        }
        else
        {
                fscanf(validar_numero_juegos,"%d",&*num_limite);
                fclose(validar_numero_juegos);
        }
}

/*---------------------------------------------------------------------------+
| Encabezado del subprograma :inicializar_cont_de_mejores_puntajes
+----------------------------------------------------------------------------+
| DES     : inicializa una variable que llevara el control de los mejores
			puntajes en cuanto a la totalidad.
| PRE     : Necesita la variable num_limite para modificarla y que sirva de
			limite en un ciclo en el que se guardan los mejores puntajes.
| POS     : modifica la varable num_limite.
+---------------------------------------------------------------------------*/


void abrir_cont_de_juegos_guardados(int *cont_de_partidas_guardadas)
{
        FILE *numero_de_partidas_guardadas;

        numero_de_partidas_guardadas=fopen("numero de partidas guardadas.txt","r");
        if(numero_de_partidas_guardadas==NULL)
        {
                *cont_de_partidas_guardadas=0;
        }
        else
        {
                fscanf(numero_de_partidas_guardadas,"%d",&*cont_de_partidas_guardadas);
                fclose(numero_de_partidas_guardadas);
        }


}

/*---------------------------------------------------------------------------+
| Encabezado del subprograma :guardar_cont_de_juegos_guardados
+----------------------------------------------------------------------------+
| DES     : guarda un contador que llevara el control de los juegos que se
			guardan en el programa.
| PRE     : Necesita la variable cont_de_partidas_guardadas para guardarla en un archivo de texto.
| POS     : guarda la variable cont_de_partidas_guardadas en un archivo de texto.
+---------------------------------------------------------------------------*/

void guardar_cont_de_juegos_guardados(int cont_de_partidas_guardadas)
{
        FILE *numero_de_partidas_guardadas;

        numero_de_partidas_guardadas=fopen("numero de partidas guardadas.txt","w");
        if(numero_de_partidas_guardadas==NULL)
        {
                printf("error al guardar contador de juegos guardados\n");
        }
        else
        {
                fprintf(numero_de_partidas_guardadas,"%d",cont_de_partidas_guardadas);
                fclose(numero_de_partidas_guardadas);
        }
}

/*---------------------------------------------------------------------------+
| Encabezado del subprograma :guardar_partida
+----------------------------------------------------------------------------+
| DES     : guarda la partida que el jugador ha decidido guardar.
| PRE     : Necesita la estructura juego_guardado para guardar su informacion
			en un archivo de texto bianrio .
| POS     : guarda la estructura juego_guardado en un archivo de texto.
+---------------------------------------------------------------------------*/


void guardar_partida(struct juego_guardado t)
{
        FILE *juegos_guardados;

        juegos_guardados=fopen("juegos guardados.txt","ab");
        if(juegos_guardados==NULL)
        {
                printf("error al guardar juego\n");
        }
        else
        {
                fwrite(&t,sizeof(struct juego_guardado),1,juegos_guardados);
                fclose(juegos_guardados);
        }
}

/*---------------------------------------------------------------------------+
| Encabezado del subprograma :recargar_partida
+----------------------------------------------------------------------------+
| DES     : abre el archivo de texto binario juegos guardados parra leer de el
			las partidas guardadas.
| PRE     : Necesita la estructura juego_guardado para guardar en ellaa los
			juegos que se leen dela rchivo de texto juegos guardados,necesita
			la variable cont_de_partidas_guardadas para tener un limite de
			lectura de las partidas guardadas, necesita la variable nom que
			es donde el usuario digito el nombre de la partida para comparar
			esta variable con la que se encuentra en la que se guardo, y
			poder cargarla, necesita la variable band_de_carga para
			modificarla y para que se pueda generar la partida guardada y
			jugar en ella, necesita las variables de la posicion de los
			fantasmas y del PACCEL para modificarlas de modo que coincidan
			con las especiicaciones que se guardaron del juego anterior,necesita
			la variable vidas para modificarla y asignar a ella las vidas que
			se guardaron del juego anterior, se necesita el cont para modificarlo
			y asi llevar el control de los tableros del juego, se necesita la
			variable cont_de_puntaje para asiganarle a ella el contador que
			asigna al PACCEL una vida adicional cada 5000 puntos,necesita la
			estructura de tableros para cargar el tablero guardado a dicha
			estructura, y por ultimo, las variables de num_galletas y puntaje
			para modificarlas de acuerdo con las especificaciones que se guardaron  .
| POS     : modifica las variables que se describieron en la precondicion.
+---------------------------------------------------------------------------*/

void recargar_partida(struct juego_guardado t[JU],int cont_de_partidas_guardadas,char nom[C],int *band_de_carga,int *f,int *c,int *ff1,int *cf1,int *ff2,int *cf2,int *ff3,int *cf3,int *ff4,int *cf4,char *v_o_g1,char *v_o_g2,char *v_o_g3,char *v_o_g4,int *vidas,int *cont,int *cont_de_puntaje,struct tablero tab[5],int *puntaje,int *num_galletas)
{
        int cont1,i,j;

        FILE *juegos_guardados;

        juegos_guardados=fopen("juegos guardados.txt","rb");
        if(juegos_guardados==NULL)
        {
                printf("error al leer el juego\n");
				getchar();
        }
        else
        {
                for(cont1=0;cont1<cont_de_partidas_guardadas;cont1++)
                {
                   fread(&t[cont1],sizeof(struct juego_guardado),1,juegos_guardados);
                }

                fclose(juegos_guardados);
        }


        for(cont1=0;cont1<cont_de_partidas_guardadas;cont1++)
        {
			if(strcmp(t[cont1].nombre,nom)==0)
			{
				*f=t[cont1].f;
				*c=t[cont1].c;

				*ff1=t[cont1].ff1;
				*cf1=t[cont1].cf1;

				*ff2=t[cont1].ff2;
				*cf2=t[cont1].cf2;

				*ff3=t[cont1].ff3;
				*cf3=t[cont1].cf3;

				*ff4=t[cont1].ff4;
				*cf4=t[cont1].cf4;

				*v_o_g1=t[cont1].v_o_g1;
				*v_o_g2=t[cont1].v_o_g2;
				*v_o_g3=t[cont1].v_o_g3;
				*v_o_g4=t[cont1].v_o_g4;

				*vidas=t[cont1].vidas;

				*cont=t[cont1].numero_de_estado_del_ultimo_tablero;

				*cont_de_puntaje=t[cont1].cont_de_puntaje;

				*puntaje=t[cont1].puntaje;

				*band_de_carga=1;

				*cont=t[cont1].numero_de_estado_del_ultimo_tablero;

				*num_galletas=t[cont1].num_galletas;

				for(i=0;i<I;i++)
				{
					for(j=0;j<J;j++)
					{
						tab[*cont].tablerito[i][j]=t[cont1].partida_guardada[i][j];

					}

				}
				printf("\nel juego ha sido cargado\n presione enter y luego uno para empezar\n");


			getchar();
			system("cls");



			}
			else
			{
				printf("no existe una partida con ese nombre\n");
				cont1=cont_de_partidas_guardadas+1;
				getchar();
			}
		}






}


/*---------------------------------------------------------------------------+
| Encabezado del subprograma : movimiento_fantasmas
+----------------------------------------------------------------------------+
| DES     : Valida el movimiento de los fantasmas dentro de la matriz y las
                        condiciones que tiene para con las galletas,las vitaminas y el PACCEL .
| PRE     : Necesita la matriz en la que se este jugando en el momento,para
                        modificar la posicion de los fantasmas dentro de la misma,las filas
                        y las columnas de los fantasmas,para modificarlas segun se mueva
                        el fantasma,las vidas del PACCEL,para modificarlas si el fantasma
                        llega a estar en la misma posicion del PACCEL,asi mismo la fila y
                        columna del PACCEL para modificar su posicion si es alcanzado por
                        un fantasma,y una variable v_o_g que sirve para saber que habia
                        antes en la casilla en la que ahora se encuentra el fantasma para
                        que cuando el fantasma valla a otra posicion deje lo que habia alli
                        (galletas o espacio vacio).
| POS     : Imprime por pantalla el tablero modificado segun las validaciones
                        del programa.
+---------------------------------------------------------------------------*/


void movimiento_fantasmas(struct tablero *t,int *ff,int *cf,int *vidas,char *v_o_g,int *f,int *c,int band_de_fantasma,int *ff1,int *cf1,int *ff2,int *cf2,int *ff3,int *cf3,int *ff4,int *cf4,char *v_o_g1,char *v_o_g2,char *v_o_g3,char *v_o_g4)
{
        int band;

        band=0;
        if(band_de_fantasma==0 || band_de_fantasma==4)
        {
                if(t->tablerito[*ff-1][*cf]!=P)
                {
                        if(band==0)
                        {
                                if(t->tablerito[*ff-1][*cf]==G)
                                {
                                        t->tablerito[*ff-1][*cf]=F;
                                        t->tablerito[*ff][*cf]=*v_o_g;
                                        *v_o_g=G;
                                        *ff=*ff-1;
                                        band=1;
                                }
                        }
                        if(band==0)
                        {
                                if(t->tablerito[*ff-1][*cf]==EV)
                                {
                                        t->tablerito[*ff-1][*cf]=F;
                                        t->tablerito[*ff][*cf]=*v_o_g;
                                        *v_o_g=EV;
                                        *ff=*ff-1;
                                        band=1;
                                }
                        }
                        if(band==0)
                        {

                                if(t->tablerito[*ff-1][*cf]==PA)
                                {

                                        t->tablerito[*ff-1][*cf]=EV;
                                        t->tablerito[*ff][*cf]=*v_o_g;
                                        t->tablerito[*ff1][*cf1]=*v_o_g1;
                                        t->tablerito[*ff2][*cf2]=*v_o_g2;
                                        t->tablerito[*ff3][*cf3]=*v_o_g3;
                                        t->tablerito[*ff4][*cf4]=*v_o_g4;

                                        t->tablerito[8][14]=F;
                                        t->tablerito[8][18]=F;
                                        t->tablerito[9][14]=F;
                                        t->tablerito[9][18]=F;
                                        t->tablerito[15][17]=PA;
                                        *v_o_g=EV;
                                        *f=15;
                                        *c=17;
                                        *ff=8;
                                        *cf=14;

                                        *ff1=8;
                                        *cf1=14;
                                        *ff2=8;
                                        *cf2=18;
                                        *ff3=9;
                                        *cf3=14;
                                        *ff4=9;
                                        *cf4=18;
                                        *v_o_g1=EV;
                                        *v_o_g2=EV;
                                        *v_o_g3=EV;
                                        *v_o_g4=EV;

                                        *vidas=*vidas-1;
                                }
                        }

                }
        }
                if(band_de_fantasma==1 || band_de_fantasma==5)
                {
                        if(t->tablerito[*ff][*cf-1]!=P)
                        {
                                if(band==0)
                                {
                                        if(t->tablerito[*ff][*cf-1]==G)
                                        {
                                                t->tablerito[*ff][*cf-1]=F;
                                                t->tablerito[*ff][*cf]=*v_o_g;
                                                *v_o_g=G;
                                                *cf=*cf-1;
                                                band=1;
                                        }
                                }
                                if(band==0)
                                {
                                        if(t->tablerito[*ff][*cf-1]==EV)
                                        {
                                                t->tablerito[*ff][*cf-1]=F;
                                                t->tablerito[*ff][*cf]=*v_o_g;
                                                *v_o_g=EV;
                                                *cf=*cf-1;
                                                band=1;
                                        }
                                }
                                if(band==0)
                                {

                                        if(t->tablerito[*ff][*cf-1]==PA)
                                        {

                                                t->tablerito[*ff][*cf-1]=EV;
                                                t->tablerito[*ff][*cf]=*v_o_g;
                                                t->tablerito[*ff1][*cf1]=*v_o_g1;
                                                t->tablerito[*ff2][*cf2]=*v_o_g2;
                                                t->tablerito[*ff3][*cf3]=*v_o_g3;
                                                t->tablerito[*ff4][*cf4]=*v_o_g4;
                                                t->tablerito[8][14]=F;
                                                t->tablerito[8][18]=F;
                                                t->tablerito[9][14]=F;
                                                t->tablerito[9][18]=F;
                                                t->tablerito[15][17]=PA;
                                                *v_o_g=EV;
                                                *f=15;
                                                *c=17;
                                                *ff=8;
                                                *cf=14;
                                                *ff1=8;
                                                *cf1=14;
                                                *ff2=8;
                                                *cf2=18;
                                                *ff3=9;
                                                *cf3=14;
                                                *ff4=9;
                                                *cf4=18;

                                                *v_o_g1=EV;
                                                *v_o_g2=EV;
                                                *v_o_g3=EV;
                                                *v_o_g4=EV;
                                                *vidas=*vidas-1;
                                        }
                                }

                        }
                }
                if(band_de_fantasma==2 || band_de_fantasma==6)
                {
                        if(t->tablerito[*ff][*cf+1]!=P)
                        {
                                if(band==0)
                                {
                                        if(t->tablerito[*ff][*cf+1]==G)
                                        {
                                                t->tablerito[*ff][*cf+1]=F;
                                                t->tablerito[*ff][*cf]=*v_o_g;
                                                *v_o_g=G;
                                                *cf=*cf+1;
                                                band=1;
                                        }
                                }
                                if(band==0)
                                {
                                        if(t->tablerito[*ff][*cf+1]==EV)
                                        {
                                                t->tablerito[*ff][*cf+1]=F;
                                                t->tablerito[*ff][*cf]=*v_o_g;
                                                *v_o_g=EV;
                                                *cf=*cf+1;
                                                band=1;
                                        }
                                }
                                if(band==0)
                                {

                                        if(t->tablerito[*ff][*cf+1]==PA)
                                        {

                                                t->tablerito[*ff][*cf+1]=EV;
                                                t->tablerito[*ff][*cf]=*v_o_g;
                                                t->tablerito[*ff1][*cf1]=*v_o_g1;
                                                t->tablerito[*ff2][*cf2]=*v_o_g2;
                                                t->tablerito[*ff3][*cf3]=*v_o_g3;
                                                t->tablerito[*ff4][*cf4]=*v_o_g4;
                                                t->tablerito[8][14]=F;
                                                t->tablerito[8][18]=F;
                                                t->tablerito[9][14]=F;
                                                t->tablerito[9][18]=F;
                                                t->tablerito[15][17]=PA;
                                                *v_o_g=EV;
                                                *f=15;
                                                *c=17;
                                                *ff=8;
                                                *cf=14;
                                                *ff1=8;
                                                *cf1=14;
                                                *ff2=8;
                                                *cf2=18;
                                                *ff3=9;
                                                *cf3=14;
                                                *ff4=9;
                                                *cf4=18;

                                                *v_o_g1=EV;
                                                *v_o_g2=EV;
                                                *v_o_g3=EV;
                                                *v_o_g4=EV;
                                                *vidas=*vidas-1;
                                        }
                                }

                        }
                }
                if(band_de_fantasma==3 || band_de_fantasma==7)
                {
                        if(t->tablerito[*ff+1][*cf]!=P)
                        {
                                if(band==0)
                                {
                                        if(t->tablerito[*ff+1][*cf]==G)
                                        {
                                                t->tablerito[*ff+1][*cf]=F;
                                                t->tablerito[*ff][*cf]=*v_o_g;
                                                *v_o_g=G;
                                                *ff=*ff+1;
                                                band=1;
                                        }
                                }
                                if(band==0)
                                {
                                        if(t->tablerito[*ff+1][*cf]==EV)
                                        {
                                                t->tablerito[*ff+1][*cf]=F;
                                                t->tablerito[*ff][*cf]=*v_o_g;
                                                *v_o_g=EV;
                                                *ff=*ff+1;
                                                band=1;
                                        }
                                }
                                if(band==0)
                                {

                                        if(t->tablerito[*ff+1][*cf]==PA)
                                        {

                                                t->tablerito[*ff+1][*cf]=EV;
                                                t->tablerito[*ff][*cf]=*v_o_g;
                                                t->tablerito[*ff1][*cf1]=*v_o_g1;
                                                t->tablerito[*ff2][*cf2]=*v_o_g2;
                                                t->tablerito[*ff3][*cf3]=*v_o_g3;
                                                t->tablerito[*ff4][*cf4]=*v_o_g4;
                                                t->tablerito[8][14]=F;
                                                t->tablerito[8][18]=F;
                                                t->tablerito[9][14]=F;
                                                t->tablerito[9][18]=F;
                                                t->tablerito[15][17]=PA;
                                                *v_o_g=EV;
                                                *f=15;
                                                *c=17;
                                                *ff=8;
                                                *cf=14;
                                                *ff1=8;
                                                *cf1=14;
                                                *ff2=8;
                                                *cf2=18;
                                                *ff3=9;
                                                *cf3=14;
                                                *ff4=9;
                                                *cf4=18;

                                                *v_o_g1=EV;
                                                *v_o_g2=EV;
                                                *v_o_g3=EV;
                                                *v_o_g4=EV;
                                                *vidas=*vidas-1;
                                        }
                                }

                        }
                }
}

/*---------------------------------------------------------------------------+
| Encabezado del subprograma : validar_mejores_puntajes
+----------------------------------------------------------------------------+
| DES     : Valida los mejores puntajes que se van registrando en el programa.
                        Cada ves que el usuario ha perdido el numero total de sus vidas este
                        subprograma valida si el puntaje alcanzado del usuario es de los
                        mejores que se halla registrado hasta el momento y lo asigna en un
                        archivo de texto.
| PRE     : Necesita el puntaje del jugador que ha perdido el numero total de
                        vidas y la estructura de puntajes para copiar el puntaje en ella,
                        si es mayor que alguno que este alli, para luego copiarlo a un
                        archivo de texto.
| POS     : modifica la estructura de "mejores_5_puntajes"con los mejores
                        puntajes alcanzados.
+---------------------------------------------------------------------------*/

void validar_mejores_puntajes(int punt,struct puntajes m[5],char nom[C],time_t final,time_t comienzo,struct tablero ultimo_tablero,int num_limite)
{
        int cont,i,j,band2;
        FILE *ver_puntajes,*validar_numero_juegos/**validar_numero_juegos2*/;





        ver_puntajes=fopen("mejores puntajes.txt","rb");
        if(ver_puntajes==NULL)
        {
                m[0].puntaje=punt;

                 strcpy(m[0].nombre,nom);

                m[0].duracion=difftime(final,comienzo);
                for(i=0;i<I;i++)
                {
                        for(j=0;j<J;j++)
                        {
                                m[0].ultimo_tablero_de_juego[i][j]=ultimo_tablero.tablerito[i][j];
                        }
                }

				for(cont=1;cont<5;cont++)
				{
					m[cont].puntaje=0;
				}




        }
        else
        {
                for(cont=0;cont<5;cont++)
                {
                        fread(&m[cont],sizeof(struct puntajes),1,ver_puntajes);
                }

                if(punt>=m[4].puntaje)
                {
                        if(punt>=m[3].puntaje)
                        {
                                if(punt>=m[2].puntaje)
                                {
                                        if(punt>=m[1].puntaje)
                                        {
                                                if(punt>=m[0].puntaje)
                                                {
													band2=4;

													ordenar_mejores_puntajes(m,band2,punt,nom,ultimo_tablero,final,comienzo);



                                                }
                                                else
                                                {
													band2=3;
													ordenar_mejores_puntajes(m,band2,punt,nom,ultimo_tablero,final,comienzo);

                                                }
                                        }
                                        else
                                        {
											band2=2;
											ordenar_mejores_puntajes(m,band2,punt,nom,ultimo_tablero,final,comienzo);

                                        }

                                }
                                else
                                {
									band2=1;
									ordenar_mejores_puntajes(m,band2,punt,nom,ultimo_tablero,final,comienzo);

                                }

                        }
                        else
                        {
							band2=0;
							ordenar_mejores_puntajes(m,band2,punt,nom,ultimo_tablero,final,comienzo);

                        }


                }

                fclose(ver_puntajes);

        }
        ver_puntajes=fopen("mejores puntajes.txt","wb");
        if(ver_puntajes==NULL)
        {
                printf("error al crear el archivo -ver puntajes-");
        }
        else
        {
                for(cont=0;cont<5;cont++)
                {
                        fwrite(&m[cont],sizeof(struct puntajes),1,ver_puntajes);
                }

                fclose(ver_puntajes);
        }



        validar_numero_juegos=fopen("limite de juegos guardados.txt","w");
        if(validar_numero_juegos!=NULL)
        {

                if(num_limite<5)
                {

                        fprintf(validar_numero_juegos,"%d",num_limite+1);
                        fclose(validar_numero_juegos);

                }


        }




}

/*---------------------------------------------------------------------------+
| Encabezado del subprograma :ordenar_mejores_puntajes
+----------------------------------------------------------------------------+
| DES     : modifica la estructura de puntajes de manera que quede lista para
			la impresion en forma descendente de acuerdo a los puntajes.
| PRE     : Necesita la estructura puntajes para modificarla de acuerdo con
			el puntaje, necesita la variable band que indica una condicion
			que se valida en el subprograma validar mejores puntajes, y en
			general necesita las especificaciones del jugador que ha terminado
			su partida para modificar la estrctura puntajes .
| POS     : oredena descendentemente las especificaiones del los jugadores
			con los mejores 5 puntajes de la existencia del juego.
+---------------------------------------------------------------------------*/


void ordenar_mejores_puntajes(struct puntajes m[5],int band,int punt,char nom[C],struct tablero ultimo_tablero,time_t final,time_t comienzo)
{
	int cont,i,j;

	if(band==4)
	{
		for(cont=4;cont>=0;cont--)
		{
			if(cont==0)
			{
				m[0].puntaje=punt;

				strcpy(m[0].nombre,nom);

                m[0].duracion=difftime(final,comienzo);
                for(i=0;i<I;i++)
                {
                   for(j=0;j<J;j++)
                   {
                      m[0].ultimo_tablero_de_juego[i][j]=ultimo_tablero.tablerito[i][j];
                   }
                }
			}
			else
			{
				m[cont].puntaje=m[cont-1].puntaje;
				strcpy(m[cont].nombre,m[cont-1].nombre);
				m[cont].duracion=m[cont-1].duracion;
				for(i=0;i<I;i++)
				{
				   for(j=0;j<J;j++)
				   {
					   m[cont].ultimo_tablero_de_juego[i][j]=m[cont-1].ultimo_tablero_de_juego[i][j];
				   }
				}
			}



		}
	}
	if(band==3)
	{
		for(cont=4;cont>=1;cont--)
		{
			if(cont==1)
			{
				m[1].puntaje=punt;

				strcpy(m[1].nombre,nom);

                m[1].duracion=difftime(final,comienzo);
                for(i=0;i<I;i++)
                {
                   for(j=0;j<J;j++)
                   {
                      m[1].ultimo_tablero_de_juego[i][j]=ultimo_tablero.tablerito[i][j];
                   }
                }
			}
			else
			{
				m[cont].puntaje=m[cont-1].puntaje;
				strcpy(m[cont].nombre,m[cont-1].nombre);
				m[cont].duracion=m[cont-1].duracion;
				for(i=0;i<I;i++)
				{
				   for(j=0;j<J;j++)
				   {
					   m[cont].ultimo_tablero_de_juego[i][j]=m[cont-1].ultimo_tablero_de_juego[i][j];
				   }
				}
			}



		}
	}
	if(band==2)
	{
		for(cont=4;cont>=2;cont--)
		{
			if(cont==2)
			{
				m[2].puntaje=punt;

				strcpy(m[2].nombre,nom);

                m[2].duracion=difftime(final,comienzo);
                for(i=0;i<I;i++)
                {
                   for(j=0;j<J;j++)
                   {
                      m[2].ultimo_tablero_de_juego[i][j]=ultimo_tablero.tablerito[i][j];
                   }
                }
			}
			else
			{
				m[cont].puntaje=m[cont-1].puntaje;
				strcpy(m[cont].nombre,m[cont-1].nombre);
				m[cont].duracion=m[cont-1].duracion;
				for(i=0;i<I;i++)
				{
				   for(j=0;j<J;j++)
				   {
					   m[cont].ultimo_tablero_de_juego[i][j]=m[cont-1].ultimo_tablero_de_juego[i][j];
				   }
				}
			}



		}
	}
	if(band==1)
	{
		for(cont=4;cont>=3;cont--)
		{
			if(cont==3)
			{
				m[3].puntaje=punt;

				strcpy(m[3].nombre,nom);

                m[3].duracion=difftime(final,comienzo);
                for(i=0;i<I;i++)
                {
                   for(j=0;j<J;j++)
                   {
                      m[3].ultimo_tablero_de_juego[i][j]=ultimo_tablero.tablerito[i][j];
                   }
                }
			}
			else
			{
				m[cont].puntaje=m[cont-1].puntaje;
				strcpy(m[cont].nombre,m[cont-1].nombre);
				m[cont].duracion=m[cont-1].duracion;
				for(i=0;i<I;i++)
				{
				   for(j=0;j<J;j++)
				   {
					   m[cont].ultimo_tablero_de_juego[i][j]=m[cont-1].ultimo_tablero_de_juego[i][j];
				   }
				}
			}



		}
	}
	if(band==0)
	{
				m[4].puntaje=punt;

				strcpy(m[4].nombre,nom);

                m[4].duracion=difftime(final,comienzo);
                for(i=0;i<I;i++)
                {
                   for(j=0;j<J;j++)
                   {
                      m[4].ultimo_tablero_de_juego[i][j]=ultimo_tablero.tablerito[i][j];
                   }
                }

	}



}

/*---------------------------------------------------------------------------+
| Encabezado del subprograma : ver_mejores_puntajes
+----------------------------------------------------------------------------+
| DES     : Es un procedimiento en el que se puede observar los mejores 5
                        puntajes del juego.
| PRE     : Necesita la estrutura de "mejores_5_puntajes" para copiar a ella
                        un archivo de texto que tiene los mejores 5 puntajes, y asi leer
                        de la estructura los mejores puntajes.
| POS     : imprime por pantalla los mejores 5 puntajes.
+---------------------------------------------------------------------------*/

void ver_mejores_puntajes(struct puntajes m[5],int *num_limite)
{
        int cont,i,j;
        FILE *ver_puntajes,*validar_numero_juegos;

        validar_numero_juegos=fopen("limite de juegos guardados.txt","r");
        if(validar_numero_juegos==NULL)
        {
                printf("error al leer el archivo limite de juegos guardados.txt\n");
        }
        else
        {
                fscanf(validar_numero_juegos,"%d",&*num_limite);
                fclose(validar_numero_juegos);
        }

                        ver_puntajes=fopen("mejores puntajes.txt","rb");
                        if(ver_puntajes==NULL)
                        {
                                printf("error al abrir el archivo -mejores puntajes-\n");
                        }
                        else
                        {
                                for(cont=0;cont<5;cont++)
                                {
                                           fread(&m[cont],sizeof(struct puntajes),1,ver_puntajes);
                                }
                                fclose(ver_puntajes);

                                printf("LOS MEJORES PUNTAJES SON:\n");

                                for(cont=0;cont<*num_limite;cont++)
                                {
                                                 printf("%d.NOMBRE:%s\nPUNTAJE:%d\n",cont+1,m[cont].nombre,m[cont].puntaje);
                                                 printf("EL TABLERO JUGADO FUE:\n");
                                                 printf("\n\n\n\t\t");
                                                for(i=0;i<I;i++)
                                                {
                                                        for(j=0;j<J;j++)
                                                        {
                                                                printf("%c",m[cont].ultimo_tablero_de_juego[i][j]);

                                                        }
                                                        printf("\n\t\t");


                                                }
                                                printf("\nla duracion fue:%.2f segundos\n\n\n",m[cont].duracion);
                                }


                        }






                validar_numero_juegos=fopen("limite de juegos guardados.txt","w");
                if(validar_numero_juegos==NULL)
                {
                        printf("error al sobreescribir el archivo limite de juegos guardados.txt\n");
                }
                else
                {
                        fprintf(validar_numero_juegos,"%d",*num_limite);
                        fclose(validar_numero_juegos);
                }



}

/*---------------------------------------------------------------------------+
| Encabezado del subprograma : mover_arriba
+----------------------------------------------------------------------------+
| DES     : Valida una serie de condiciones para mover el PACCEl hacia arriba
            de la matriz(especificamente,se mantiene la columna del PACCEL y se
            modifica la fila restandole una,[*f-1][*c]).
| PRE     : Necesita el tablero que se este jugando en el momento para modificar
                        la posicion del PACCEL en él,necesita la fila y la columna del
                        paccel para hacer un seguimiento de su posicion y para que este
                        y los demas subprogramas sepan en donde esta el PACCEL,tambien
                        necesita el numero de galletas que hay en el tablero para descontarlas
                        a medida que el PACCEL se las valla comiendo.Necesita el puntaje para
                        incrementarlo cada vez que el PACCEL se coma una galleta.Necesita
                        un contador de puntaje para validar que cada 5000 puntos, el PACCEL
                        obtenga una nueva vida.Necsita el numero de vidas para descontarlas
                        cada vez que el PACCEL se encuentre en una misma casilla con algun
                        fantasma.Necesita la variable v_o_g para modificar su contenido a
                        espacio vacio(EV), cuando el PACCEL se encuentre con un fantasma y
                        volver a modificar las filas y columnas del PACCEL y de los fantsmas,
                        asi mismo se necesita la fila y la columna de del fantasma que esta
                        en movimiento para modificarlas y saber su posicion.
| POS     : Modifica la matriz tablero en la que el jugador se encuentra,validando
                        todas las condiciones del subprograma,y retorna un valor que sirve
                        para validar el cambio de tablero o no.
+---------------------------------------------------------------------------*/

int mover_arriba(struct tablero *t,int *f,int *c,int *num_galletas,int *puntaje,int *cont_de_puntaje,int *vidas,char *v_o_g1,char *v_o_g2,char *v_o_g3,char *v_o_g4,int *ff1,int *cf1,int *ff2,int *cf2,int *ff3,int *cf3,int *ff4,int *cf4)
{
        int band2,i,j;

        band2=0;


        if(t->tablerito[*f-1][*c]!=P)
        {
                if(band2==0)
                {
                        if(t->tablerito[*f-1][*c]==G)
                        {
                                t->tablerito[*f][*c]=EV;
                                t->tablerito[*f-1][*c]=PA;
                                *num_galletas=*num_galletas-1;
                                *puntaje=*puntaje+100;
                                if(*puntaje==*cont_de_puntaje)
                                {
                                        *vidas=*vidas+1;
                                        *cont_de_puntaje=*cont_de_puntaje+5000;
                                }
                                *f=*f-1;
                                band2=1;
                        }
                }
                if(band2==0)
                {
                        if(t->tablerito[*f-1][*c]==EV)
                        {
                                t->tablerito[*f][*c]=EV;
                                t->tablerito[*f-1][*c]=PA;
                                *f=*f-1;
                                band2=1;
                        }
                }
                if(band2==0)
                {
                        if(t->tablerito[*f-1][*c]==V)
                        {
                                t->tablerito[*f][*c]=EV;
                                t->tablerito[*f-1][*c]=PA;
                                *f=*f-1;
                                for(i=0;i<I;i++)
                                {
                                        for(j=0;j<J;j++)
                                        {
                                                if(t->tablerito[i][j]==F)
                                                {
                                                        t->tablerito[i][j]=EV;
                                                }
                                        }
                                }


                                band2=1;
                        }
                }
                if(band2==0)
                {
                        if(t->tablerito[*f-1][*c]==F)
                        {


                                t->tablerito[*f][*c]=EV;
                                t->tablerito[*ff1][*cf1]=*v_o_g1;
                                t->tablerito[*ff2][*cf2]=*v_o_g2;
                                t->tablerito[*ff3][*cf3]=*v_o_g3;
                                t->tablerito[*ff4][*cf4]=*v_o_g4;

                                t->tablerito[8][14]=F;
                                t->tablerito[8][18]=F;
                                t->tablerito[9][14]=F;
                                t->tablerito[9][18]=F;
                                t->tablerito[15][17]=PA;
                                *f=15;
                                *c=17;
                                *ff1=8;
                                *cf1=14;

                                *ff2=8;
                                *cf2=18;

                                *ff3=9;
                                *cf3=14;

                                *ff4=9;
                                *cf4=18;

                                *v_o_g1=EV;
                                *v_o_g2=EV;
                                *v_o_g3=EV;
                                *v_o_g4=EV;
                                *vidas=*vidas-1;
                        }

                }
        }
        if(*num_galletas==0)
        {
                return(1);
        }
        return(0);
}

/*--------------------------------------------------------------------------+
| Encabezado del subprograma : mover_izquierda
+----------------------------------------------------------------------------+
| DES     : Valida una serie de condiciones para mover el PACCEl hacia la izquierda
                        de la matriz(especificamente,se mantiene la fila del PACCEL y se
                        modifica la columna restandole una,[*f][*c-1]).
| PRE     : Necesita el tablero que se este jugando en el momento para modificar
                        la posicion del PACCEL en él,necesita la fila y la columna del
                        paccel para hacer un seguimiento de su posicion y para que este
                        y los demas subprogramas sepan en donde esta el PACCEL,tambien
                        necesita el numero de galletas que hay en el tablero para descontarlas
                        a medida que el PACCEL se las valla comiendo.Necesita el puntaje para
                        incrementarlo cada vez que el PACCEL se coma una galleta.Necesita
                        un contador de puntaje para validar que cada 5000 puntos, el PACCEL
                        obtenga una nueva vida.Necsita el numero de vidas para descontarlas
                        cada vez que el PACCEL se encuentre en una misma casilla con algun
                        fantasma.Necesita la variable v_o_g para modificar su contenido a
                        espacio vacio(EV), cuando el PACCEL se encuentre con un fantasma y
                        volver a modificar las filas y columnas del PACCEL y de los fantsmas,
                        asi mismo se necesita la fila y la columna de del fantasma que esta
                        en movimiento para modificarlas y saber su posicion.
| POS     : Modifica la matriz tablero en la que el jugador se encuentra,validando
                        todas las condiciones del subprograma,y retorna un valor que sirve
                        para validar el cambio de tablero o no.
+---------------------------------------------------------------------------*/

int mover_izquierda(struct tablero *t,int *f,int *c,int *num_galletas,int *puntaje,int *cont_de_puntaje,int *vidas,char *v_o_g1,char *v_o_g2,char *v_o_g3,char *v_o_g4,int *ff1,int *cf1,int *ff2,int *cf2,int *ff3,int *cf3,int *ff4,int *cf4)
{
        int band2,i,j;

        band2=0;



        if (t->tablerito[*f][*c-1]!=P)
        {
                if(band2==0)
                {
                        if(t->tablerito[*f][*c-1]==G)
                        {
                                t->tablerito[*f][*c]=EV;
                                t->tablerito[*f][*c-1]=PA;
                                *num_galletas=*num_galletas-1;
                                *puntaje=*puntaje+100;
                                if(*puntaje==*cont_de_puntaje)
                                {
                                        *vidas=*vidas+1;
                                        *cont_de_puntaje=*cont_de_puntaje+5000;
                                }
                                *c=*c-1;
                                band2=1;
                        }
                }
                if(band2==0)
                {
                        if(t->tablerito[*f][*c-1]==EV)
                        {
                                t->tablerito[*f][*c]=EV;
                                t->tablerito[*f][*c-1]=PA;
                                *c=*c-1;
                                band2=1;
                        }
                }
                if(band2==0)
                {
                        if(t->tablerito[*f][*c-1]==V)
                        {
                                t->tablerito[*f][*c]=EV;
                                t->tablerito[*f][*c-1]=PA;
                                *c=*c-1;
                                for(i=0;i<I;i++)
                                {
                                        for(j=0;j<J;j++)
                                        {
                                                if(t->tablerito[i][j]==F)
                                                {
                                                        t->tablerito[i][j]=EV;
                                                }
                                        }
                                }



                                band2=1;
                        }
                }
                if(band2==0)
                {
                        if(t->tablerito[*f][*c-1]==F)
                        {

                                t->tablerito[*f][*c]=EV;
                                t->tablerito[*ff1][*cf1]=*v_o_g1;
                                t->tablerito[*ff2][*cf2]=*v_o_g2;
                                t->tablerito[*ff3][*cf3]=*v_o_g3;
                                t->tablerito[*ff4][*cf4]=*v_o_g4;
                                t->tablerito[8][14]=F;
                                t->tablerito[8][18]=F;
                                t->tablerito[9][14]=F;
                                t->tablerito[9][18]=F;
                                t->tablerito[15][17]=PA;
                                *f=15;
                                *c=17;
                                *ff1=8;
                                *cf1=14;
                                *ff2=8;
                                *cf2=18;

                                *ff3=9;
                                *cf3=14;

                                *ff4=9;
                                *cf4=18;
                                *v_o_g1=EV;
                                *v_o_g2=EV;
                                *v_o_g3=EV;
                                *v_o_g4=EV;
                                *vidas=*vidas-1;
                        }
                }
        }
        if(*num_galletas==0)
        {
                return(1);
        }
        return(0);
}

/*---------------------------------------------------------------------------+
| Encabezado del subprograma : mover_derecha
+----------------------------------------------------------------------------+
| DES     : Valida una serie de condiciones para mover el PACCEl hacia la izquierda
                        de la matriz(especificamente,se mantiene la fila del PACCEL y se
                        modifica la columna sumandole una,[*f][*c+1]).
| PRE     : Necesita el tablero que se este jugando en el momento para modificar
                        la posicion del PACCEL en él,necesita la fila y la columna del
                        paccel para hacer un seguimiento de su posicion y para que este
                        y los demas subprogramas sepan en donde esta el PACCEL,tambien
                        necesita el numero de galletas que hay en el tablero para descontarlas
                        a medida que el PACCEL se las valla comiendo.Necesita el puntaje para
                        incrementarlo cada vez que el PACCEL se coma una galleta.Necesita
                        un contador de puntaje para validar que cada 5000 puntos, el PACCEL
                        obtenga una nueva vida.Necsita el numero de vidas para descontarlas
                        cada vez que el PACCEL se encuentre en una misma casilla con algun
                        fantasma.Necesita la variable v_o_g para modificar su contenido a
                        espacio vacio(EV), cuando el PACCEL se encuentre con un fantasma y
                        volver a modificar las filas y columnas del PACCEL y de los fantsmas,
                        asi mismo se necesita la fila y la columna de del fantasma que esta
                        en movimiento para modificarlas y saber su posicion.
| POS     : Modifica la matriz tablero en la que el jugador se encuentra,validando
                        todas las condiciones del subprograma,y retorna un valor que sirve
                        para validar el cambio de tablero o no.
+---------------------------------------------------------------------------*/

int mover_derecha(struct tablero *t,int *f,int *c,int *num_galletas,int *puntaje,int *cont_de_puntaje,int *vidas,char *v_o_g1,char *v_o_g2,char *v_o_g3,char *v_o_g4,int *ff1,int *cf1,int *ff2,int *cf2,int *ff3,int *cf3,int *ff4,int *cf4)
{
        int band2,i,j;

        band2=0;


        if (t->tablerito[*f][*c+1]!=P)
        {
                if(band2==0)
                {
                        if(t->tablerito[*f][*c+1]==G)
                        {
                                t->tablerito[*f][*c]=EV;
                                t->tablerito[*f][*c+1]=PA;
                                *num_galletas=*num_galletas-1;
                                *puntaje=*puntaje+100;
                                if(*puntaje==*cont_de_puntaje)
                                {
                                        *vidas=*vidas+1;
                                        *cont_de_puntaje=*cont_de_puntaje+5000;
                                }
                                *c=*c+1;
                                band2=1;
                        }
                }
                if(band2==0)
                {
                        if(t->tablerito[*f][*c+1]==EV)
                        {
                                t->tablerito[*f][*c]=EV;
                                t->tablerito[*f][*c+1]=PA;
                                *c=*c+1;
                                band2=1;
                        }
                }
                if(band2==0)
                {
                        if(t->tablerito[*f][*c+1]==V)
                        {
                                t->tablerito[*f][*c]=EV;
                                t->tablerito[*f][*c+1]=PA;
                                *c=*c+1;
                                for(i=0;i<I;i++)
                                {
                                        for(j=0;j<J;j++)
                                        {
                                                if(t->tablerito[i][j]==F)
                                                {
                                                        t->tablerito[i][j]=EV;
                                                }
                                        }
                                }



                                band2=1;
                        }
                }
                if(band2==0)
                {
                        if(t->tablerito[*f][*c+1]==F)
                        {

                                t->tablerito[*f][*c]=EV;
                                t->tablerito[*ff1][*cf1]=*v_o_g1;
                                t->tablerito[*ff2][*cf2]=*v_o_g2;
                                t->tablerito[*ff3][*cf3]=*v_o_g3;
                                t->tablerito[*ff4][*cf4]=*v_o_g4;
                                t->tablerito[8][14]=F;
                                t->tablerito[8][18]=F;
                                t->tablerito[9][14]=F;
                                t->tablerito[9][18]=F;
                                t->tablerito[15][17]=PA;
                                *f=15;
                                *c=17;
                                *ff1=8;
                                *cf1=14;
                                *ff2=8;
                                *cf2=18;

                                *ff3=9;
                                *cf3=14;

                                *ff4=9;
                                *cf4=18;
                                *v_o_g1=EV;
                                *v_o_g2=EV;
                                *v_o_g3=EV;
                                *v_o_g4=EV;
                                *vidas=*vidas-1;
                                band2=1;
                        }
                }
  }
  if(*num_galletas==0)
  {
                return(1);
        }
return(0);
}


/*---------------------------------------------------------------------------+
| Encabezado del subprograma : mover_abajo
+----------------------------------------------------------------------------+
| DES     : Valida una serie de condiciones para mover el PACCEl hacia la izquierda
                        de la matriz(especificamente,se mantiene la columna del PACCEL y se
                        modifica la fila sumandole una,[*f+1][*c]).
| PRE     : Necesita el tablero que se este jugando en el momento para modificar
                        la posicion del PACCEL en él,necesita la fila y la columna del
                        paccel para hacer un seguimiento de su posicion y para que este
                        y los demas subprogramas sepan en donde esta el PACCEL,tambien
                        necesita el numero de galletas que hay en el tablero para descontarlas
                        a medida que el PACCEL se las valla comiendo.Necesita el puntaje para
                        incrementarlo cada vez que el PACCEL se coma una galleta.Necesita
                        un contador de puntaje para validar que cada 5000 puntos, el PACCEL
                        obtenga una nueva vida.Necsita el numero de vidas para descontarlas
                        cada vez que el PACCEL se encuentre en una misma casilla con algun
                        fantasma.Necesita la variable v_o_g para modificar su contenido a
                        espacio vacio(EV), cuando el PACCEL se encuentre con un fantasma y
                        volver a modificar las filas y columnas del PACCEL y de los fantsmas,
                        asi mismo se necesita la fila y la columna de del fantasma que esta
                        en movimiento para modificarlas y saber su posicion.
| POS     : Modifica la matriz tablero en la que el jugador se encuentra,validando
                        todas las condiciones del subprograma,y retorna un valor que sirve
                        para validar el cambio de tablero o no.
+---------------------------------------------------------------------------*/

int mover_abajo(struct tablero *t,int *f,int *c,int *num_galletas,int *puntaje,int *cont_de_puntaje,int *vidas,char *v_o_g1,char *v_o_g2,char *v_o_g3,char *v_o_g4,int *ff1,int *cf1,int *ff2,int *cf2,int *ff3,int *cf3,int *ff4,int *cf4)
{
        int band2,i,j;

        band2=0;


        if(t->tablerito[*f+1][*c]!=P)
        {
                if(band2==0)
                {
                        if(t->tablerito[*f+1][*c]==G)
                        {
                                t->tablerito[*f][*c]=EV;
                                t->tablerito[*f+1][*c]=PA;
                                *num_galletas=*num_galletas-1;
                                *puntaje=*puntaje+100;
                                if(*puntaje==*cont_de_puntaje)
                                {
                                        *vidas=*vidas+1;
                                        *cont_de_puntaje=*cont_de_puntaje+5000;
                                }
                                *f=*f+1;
                                band2=1;
                        }
                }
                if(band2==0)
                {
                        if(t->tablerito[*f+1][*c]==EV)
                        {
                                t->tablerito[*f][*c]=EV;
                                t->tablerito[*f+1][*c]=PA;
                                *f=*f+1;
                                band2=1;
                        }
                }
                if(band2==0)
                {
                        if(t->tablerito[*f+1][*c]==V)
                        {
                                t->tablerito[*f][*c]=EV;
                                t->tablerito[*f+1][*c]=PA;
                                *f=*f+1;
                                for(i=0;i<I;i++)
                                {
                                        for(j=0;j<J;j++)
                                        {
                                                if(t->tablerito[i][j]==F)
                                                {
                                                        t->tablerito[i][j]=EV;
                                                }
                                        }
                                }



                                band2=1;
                        }
                }
        }
        if(band2==0)
        {
                if(t->tablerito[*f+1][*c]==F)
                {

                        t->tablerito[*f][*c]=EV;
                        t->tablerito[*ff1][*cf1]=*v_o_g1;
                        t->tablerito[*ff2][*cf2]=*v_o_g2;
                        t->tablerito[*ff3][*cf3]=*v_o_g3;
                        t->tablerito[*ff4][*cf4]=*v_o_g4;
                        t->tablerito[8][14]=F;
                        t->tablerito[8][18]=F;
                        t->tablerito[9][14]=F;
                        t->tablerito[9][18]=F;
                        t->tablerito[15][17]=PA;
                        *f=15;
                        *c=17;
                        *ff1=8;
                        *cf1=14;
                        *ff2=8;
                        *cf2=18;
                        *ff3=9;
                        *cf3=14;
                        *ff4=9;
                        *cf4=18;
                        *v_o_g1=EV;
                        *v_o_g2=EV;
                        *v_o_g3=EV;
                        *v_o_g4=EV;
                        *vidas=*vidas-1;
                        band2=1;
                }
}
if(*num_galletas==0)
{
        return(1);
}
return(0);
}

/*---------------------------------------------------------------------------+
| Encabezado del subprograma : despedida
+----------------------------------------------------------------------------+
| DES     : Da un mensaje de despedida al usuario cuando se acaba el juego.
| PRE     : Ninguna.
| POS     : Imprime por pantalla el mensaje de despedida.
+---------------------------------------------------------------------------*/

void despedida(void)
{
        printf("Gracias por jugar PACCEL...intentalo de nuevo\n");
}

