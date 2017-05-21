/*+**************
*  BIBLIOTECAS  *
**************+*/
#include <stdio.h>
/*+**************
*  CONSTANTES   *
**************+*/
# define FC 100
/*+*********************************
*  PROTOTIPOS DE LOS SUBPROGRAMAS  *
*********************************+*/
void cuenta_ceros (int mat[FC][FC], int f,int c,int *cero);
main()
/*+********************
*  PROGRAMA PRINCIPAL *
********************+*/
{
    int mat[FC][FC], f, c, i, j, cero;
    printf("\nHOLA\n\nESTE PROGRAMA TE CUENTA LOS NUMEROS '0' QUE INGRESES EN UNA MATRIZ DE 'f' FILAS Y 'c' COLUMNAS.\n");
    printf("\nDIGITE EL NUMERO DE FILAS\n");
    scanf("%d%*c",&f);
    if(f>=1 && f<=100)
    {
        printf("\nDIGITE EL NUMERO DE COLUMNAS\n");
        scanf("%d%*c",&c);
        if(c>=1 && c<=100)
        {
            for(i=0;i<f;i++)
            {
                for(j=0;j<c;j++)
                {
                    printf("\nDigite el valor de la fila %d columna %d: ",i+1,j+1);
                    scanf("%d%*c",&mat[i][j]);
                }
            }
            cuenta_ceros (mat,f,c,&cero);
            printf("\n\nLA CANTIDAD DE CEROS ESCRITOS EN LA MATRIZ SON: %d",cero);
        }
    }
    printf("\n\n'GRACIAS POR UTILIZAR ESTE PROGRAMA'\n");
}
/*+***************
*  SUBPROGRAMAS  *
***************+*/
void cuenta_ceros (int mat[FC][FC], int f,int c,int *cero)
{
    int i, j;
    for(i=0,*cero=0;i<f;i++)
    {
        for(j=0;j<c;j++)
        {
            if(mat[i][j]==0)
                *cero=*cero+1;
        }
    }
}

