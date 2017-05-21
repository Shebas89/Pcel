#include <stdio.h>
#include <conio.h>
#define FC 5
#define L 64      ///Limites
#define P 42      ///Paredes
#define CMF 5     ///Coumnas del tablero Muy Facil
#define FMF 5     ///Filas del tableero Muy Facil
#define CF 20     ///Coumnas del tablero Facil
#define FF 70     ///Filas del tableero Facil
#define CM 20     ///Coumnas del tablero Mediano
#define FM 70     ///Filas del tableero Mediano
#define CD 20     ///Coumnas del tablero Dificil
#define FD 70     ///Filas del tableero Dificil
#define CE 20     ///Coumnas del tablero Experto
#define FE 70     ///Filas del tableero Experto
#define NOM 50    ///Nombre
#define INI 73    ///Inicio
#define FIN 70    ///Fin
#define L 64      ///Limites
#define P 42      ///Paredes
#define W 94      ///Arriba
#define S 118     ///Abajo
#define D 62      ///Derecha
#define A 60      ///Izquirda
#define E 32      ///Espacio
void cargar_juego (char [FC][FC]);
char movimiento ();
main()
{
    int i,j;
    char mat[FC][FC], opc;
    cargar_juego (mat);
    do
    {
        opc=movimiento();
        switch(opc)
        {
            case 'a':
            break;
        }
    }while(mat[1][3]==FIN);
}
void cargar_juego (char mat[FC][FC])
{
    int i,j;
    printf("\n\n\n\t\t");
    for(i=0;i<FC;i++)
    {
        for(j=0;j<FC;j++)
            mat[i][j]=E;
    }
    for(i=0,j=0;j<FC;j++)
        mat[i][j]=L;
    for(i=0,j=0;i<FC;i++)
        mat[i][j]=L;
    for(i=FC-1,j=0;j<FC;j++)
        mat[i][j]=L;
    for(i=0,j=FC-1;i<FC;i++)
        mat[i][j]=L;
    mat[1][2]=P;
    mat[2][2]=P;
    mat[1][1]=INI;
    mat[1][3]=FIN;
    for(i=0;i<FC;i++)
    {
        for(j=0;j<FC;j++)
            printf("%c",mat[i][j]);
        printf("\n\t\t");
    }
}
char movimiento ()
{
    char opc;
    opc=getch();
    return(opc);
}
