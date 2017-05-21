# include <stdio.h>
# include <conio.h>
# include <stdlib.h>
/**CONSTANTES**/
# define MAX 10
# define MAX_NOM 50
/**PROTOTIPOS**/
char opc_menu (void);
void instrucciones (void);
void iniciar_tablero (char [MAX][MAX],int*punt);
void cargar_tablero (char [MAX][MAX]);
void imprimir_tablero (char [MAX][MAX],char [MAX_NOM],int,int,int,int,int,int,int);
void mover_arriba (char [MAX][MAX],char [MAX_NOM],int*punt,int*,int*,int*,int*,int*,int*);
void mover_abajo (char [MAX][MAX],char nom[MAX_NOM],int*punt,int*,int*,int*,int*,int*,int*);
void mover_derecha (char [MAX][MAX],char nom[MAX_NOM],int*punt,int*,int*,int*,int*,int*,int*);
void mover_izquierda (char [MAX][MAX],char nom[MAX_NOM],int*punt,int*,int*,int*,int*,int*,int*);
void despedida (void);
/**PROGRAMAS**/
int main (void)
{
    int opc,punt,cont2,i,j,der,izq,arr,aba;
    char tablero[MAX][MAX], mov, nom[MAX_NOM];
    do
    {
    opc=opc_menu();
        switch(opc)
        {
            case '1':

                iniciar_tablero (tablero,&punt);
                printf("\n\n\n\n\n\n\n\n\t\t\tDIGITE SU NOMBRE\n");
                printf("\n\t\t\t");
                gets(nom);
                system("cls");
                cargar_tablero (tablero);
                i=1,j=1,arr=0,aba=0,der=0,izq=0;
                imprimir_tablero (tablero,nom,punt,i,j,der,izq,arr,aba);
                i=1,j=1;
                do
                {
                    mov=getch();    /**MOVER MACEL**/
                    if(mov=='w' || mov=='W')    /** ARIBA **/
                    {
                        mover_arriba(tablero,nom,&punt,&i,&j,&der,&izq,&arr,&aba);
                    }
                    else    if(mov=='d' || mov=='D')    /** DERECHA **/
                    {
                        mover_derecha (tablero,nom,&punt,&i,&j,&der,&izq,&arr,&aba);
                    }
                    else    if(mov=='s' || mov=='S')    /** ABAJO **/
                    {
                        mover_abajo (tablero,nom,&punt,&i,&j,&der,&izq,&arr,&aba);
                    }
                    else    if(mov=='a' || mov=='A')    /** IZQUIERDA **/
                    {
                        mover_izquierda (tablero,nom,&punt,&i,&j,&der,&izq,&arr,&aba);
                    }
                }while(tablero[8][1]==70&&punt<100);
                if(tablero[8][1]!=70)
                {
                    system("cls");
                    printf("\n\n\n\n\n\n\t\tFELIZITACIONES..... JUEGO COMPLETO\n\n\n\n\n");
                    getch();

                }
                if(punt>=100)
                {
                    system("cls");
                    printf("\n\n\n\n\n\n\t\tJUEGO INCOMPLETO....INTENTELO DE NUEVO\n\n\n\n\n");
                    getch();
                }
            break;

            case '2':

            instrucciones ();

            break;

            case '3':

            despedida();
            break;
        }
    }while (opc!='3');

}
/**SUBPROGRAMAS**/
char opc_menu (void)    /**MENU**/
{
    char opc;
    system("cls");
    printf("\n\n\n\n\n\n\t\t\tESCOGE UNA OPCION""\n\n\t\t\t1. JUGAR""\n\n\t\t\t2. AYUDA""\n\n\t\t\t3. SALIR\n\n");
    opc=getch();
    system("cls");
    return(opc);
}
void instrucciones (void)   /**AYUDA**/
{
    system("cls");
    printf("\n\n\n\t\t\tBIENVENIDO A CRAZY MACEL....\n\n\nESTE JUEGO CONSISTE EN MOVER EL MACEL POR MEDIO DEL LAVERINTO CON EL FIN DE\nLLEGAR A LA META LA CUAL ES LA 'F'.\nCUANDO EL MACEL HALLA LLEGADO A LA 'F' EL TABLERO HABRA FINALIZADO Y PASARA AL  SIGUIENTE NIVEL.\n\nCADA DESPLAZAMIENTO DEL MACEL PRODUCE UN PUNTO, AL CHOCARCE CON UNA PARED\nAUMENTARA 5 PUNTOS Y AL CHOCARCE CON UN MURO AUENTARA 3 PUNTOS.\n\nEL OBJETIVO ES PASAR EL LABERINTO CON EL MENOR NUMERO DE PUNTOS POSIBLES.\n\n\nUD TIENE TRS OPCIONES DE SALIDA:\n\n1.JUEGO COMPLETO\n2.JUEGO ABANDONADO\n3.JUEGO INCOMPLETO\n\nJUEGO IMPLETO: ES CUANDO EL JUGADOR EXCEDE EL NUMERO DE PUNTOS PERMITIDOS EN EL TABLERO.\n\n\nPARA PODER MOVER AL MACEL TIENE LAS SIGUIENTES OPCIONES:\n\nW=DESPLAZARCE HACIA ARRIBA\nS=DESPLAZARCE HACIA ABAJO\nA=DESPLAZARCE A LA IZQUIERDA\nD=DESPLAZARCE A LA DERECHA\n\n\n\n\t\t\tMUCHA SUERTE.....\n\n\n");
    getch();
        system("cls");
}
void iniciar_tablero (char tablero[MAX][MAX],int*punt)   /**INICIALIZAR EL TABLERO**/
{
    int i, j;
    for(i=0;i<MAX;i++)
    {
        for(j=0;j<MAX;j++)
        {
            tablero[i][j]=32;   /** (ESPACIO) **/
        }
    }
    tablero[1][1]=73;   /** (I) **/
    tablero[8][1]=70;   /** (F) **/
    *punt=0;
}
void imprimir_tablero (char tablero[MAX][MAX],char nom[MAX_NOM],int punt,int i,int j,int der,int izq,int arr,int aba)   /**IMPRIMIR**/
{
    int res,fil,col;
    system("cls");
    printf("\n\n\n\n\n\n");
    for(fil=i-1;fil<=i+1;fil++)
    {
        printf("\t\t\t");
        for(col=j-1;col<j+2;col++)
        {
            printf("%2c",tablero[fil][col]);
        }
        printf("\n");
    }
    res=100-punt;
    printf("\n\n\t\tNOMBRE: %s",nom);
    printf("\n\n\t\tPUNTOS: %d",punt);
    printf("\n\n\t\tEL TAMAÑO DEL LABERINTO ES DE %d POR %d.",MAX,MAX);
    printf("\n\n\t\tPUNTOS RESTANTES; %d",res);
    printf("\n\n\t\tPASOS A LA DERECHA: %d",der);
    printf("\n\n\t\tPASOS A LA IZQUIERDA: %d",izq);
    printf("\n\n\t\tPASOS HACIA ARRIBA :%d",arr);
    printf("\n\n\t\tPASOS HACIA ABAJO: %d",aba);
    printf("\n\n\n\n\t\t\tPULSE * PARA SALIR");
}
void cargar_tablero (char tablero[MAX][MAX])    /**CARGAR TABLERO**/
{
    int i, j;
    tablero[5][3]=42,tablero[5][3]=42,tablero[4][6]=42;  /** (*) **/
    for(i=0;i<1;i++)   /** (@) **/
    {
        for(j=0;j<MAX;j++)
        {
            tablero[i][j]=64;
        }
    }
    for(i=9;i<10;i++)   /** (@) **/
    {
        for(j=0;j<MAX;j++)
        {
            tablero[i][j]=64;
        }
    }
    for(j=0;j<1;j++)   /** (@) **/
    {
        for(i=0;i<MAX;i++)
        {
            tablero[i][j]=64;
        }
    }
    for(j=9;j<MAX;j++)   /** (@) **/
    {
        for(i=0;i<10;i++)
        {
            tablero[i][j]=64;
        }
    }
    for(i=2,j=1;j<6;j++)  /** (*) **/
    {
        tablero[i][j]=42;
    }
    for(i=4,j=2;j<5;j++)  /** (*) **/
    {
        tablero[i][j]=42;
    }
    for(j=7,i=2;i<8;i++)  /** (*) **/
    {
        tablero[i][j]=42;
    }
    for(i=8,j=2;j<6;j++)  /** (*) **/
    {
        tablero[i][j]=42;
    }
    for(j=5,i=6;i<9;i++)  /** (*) **/
    {
        tablero[i][j]=42;
    }
    for(i=6,j=1;j<4;j++)  /** (*) **/
    {
        tablero[i][j]=42;
    }
}
void mover_arriba (char tab[MAX][MAX],char nom[MAX_NOM],int*punt,int*i,int*j,int*der,int*izq,int*arr,int*aba)
{
    int temp;
    system("cls");
    if(tab[*i-1][*j]==64)
    {
        *punt=*punt+5;
        tab[*i][*j]=94;   /** (^) **/
    }
    else if(tab[*i-1][*j]==42)
    {
        *punt=*punt+3;
        tab[*i][*j]=94;   /** (^) **/
    }
    else if(tab[*i-1][*j]==32)
    {
        *punt=*punt+1;
        tab[*i][*j]=32;   /** (ESPACIO) **/
        *i=*i-1;
        tab[*i][*j]=94;   /** (^) **/
    }
    *arr=*arr+1;
    imprimir_tablero (tab,nom,*punt,*i,*j,*der,*izq,*arr,*aba);
}
void mover_abajo (char tab[MAX][MAX],char nom[MAX_NOM],int*punt,int*i,int*j,int*der,int*izq,int*arr,int*aba)
{
    int temp;
    system("cls");
    if(tab[*i+1][*j]==64)
    {
        *punt=*punt+5;
        tab[*i][*j]=118;   /** (v) **/
    }
    else if(tab[*i+1][*j]==42)
    {
        *punt=*punt+3;
        tab[*i][*j]=118;   /** (v) **/
    }
    else if(tab[*i+1][*j]==32)
    {
        *punt=*punt+1;
        tab[*i][*j]=32;   /** (ESPACIO) **/
        *i=*i+1;
        tab[*i][*j]=118;   /** (v) **/
    }
    else if(tab[*i+1][*j]==70)
    {
        *i=*i+1;
        tab[*i][*j]=118;   /** (v) **/
    }
    *aba=*aba+1;
    imprimir_tablero (tab,nom,*punt,*i,*j,*der,*izq,*arr,*aba);
}
void mover_derecha (char tab[MAX][MAX],char nom[MAX_NOM],int*punt,int*i,int*j,int*der,int*izq,int*arr,int*aba)
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
    *der=*der+1;
    imprimir_tablero (tab,nom,*punt,*i,*j,*der,*izq,*arr,*aba);
}
void mover_izquierda (char tab[MAX][MAX],char nom[MAX_NOM],int*punt,int*i,int*j,int*der,int*izq,int*arr,int*aba)
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
    *izq=*izq+1;
    imprimir_tablero (tab,nom,*punt,*i,*j,*der,*izq,*arr,*aba);
}
void despedida (void)
{
    system("cls");
    printf("\n\n\n\n\n\n\tGRACIAS POR JUGAR CRAZY MACEL... CUANDO QUIERAS VUELVE A INTENTALO\n\n\n\n\n");
}
