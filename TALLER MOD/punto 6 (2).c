/*+**************
*  BIBLIOTECAS  *
**************+*/
#include <stdio.h>
#include <stdlib.h>
/*+**************
*  CONSTANTES   *
**************+*/
# define F 20
# define C 30
/*+*********************************
*  PROTOTIPOS DE LOS SUBPROGRAMAS  *
*********************************+*/
int cambia_neg (int mat[F][C], int f,int c);
main()
/*+********************
*  PROGRAMA PRINCIPAL *
********************+*/
{
    int mat[F][C], f, c, i, j, cero;
    printf("\nHOLA\n\nESTE PROGRAMA CAMBIA LOS NUMEROS NEGATIVOS QUE INGRESES EN UNA MATRIZ DE 'f' FILAS Y 'c' COLUMNAS POR '0'.\n");
    printf("\nDIGITE EL NUMERO DE FILAS\n");
    scanf("%d%*c",&f);
    if(f>=1 && f<=20)
    {
        printf("\nDIGITE EL NUMERO DE COLUMNAS\n");
        scanf("%d%*c",&c);
        if(c>=1 && c<=30)
        {
            for(i=0;i<f;i++)
            {
                for(j=0;j<c;j++)
                {
                    printf("\nDIGITE EL VALOR DE LA FILA %d COLUMNA %d: ",i+1,j+1);
                    scanf("%d%*c",&mat[i][j]);
                }
            }
            system("cls");
            printf("\nNUMEROS INGRESADOS:\n");
            for(i=0;i<f;i++)
            {
                for(j=0;j<c;j++)
                {
                    printf("%4d",mat[i][j]);
                }
                printf("\n");
            }
            cambia_neg (mat,f,c);
            printf("\n\n\nNUMEROS CON CAMBIO:\n");
            for(i=0;i<f;i++)
            {
                for(j=0;j<c;j++)
                {
                    printf("%4d",mat[i][j]);
                }
                printf("\n");
            }
        }
    }
}
/*+***************
*  SUBPROGRAMAS  *
***************+*/
int cambia_neg (int mat[F][C], int f,int c)
{
    int i, j;
    for(i=0;i<f;i++)
    {
        for(j=0;j<c;j++)
        {
            if(mat[i][j]<0)
                mat[i][j]=0;
        }
    }
}
