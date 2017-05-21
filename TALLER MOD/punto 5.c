/*+**************
*  BIBLIOTECAS  *
**************+*/
#include <stdio.h>
/*+**************
*  CONSTANTES   *
**************+*/
# define C 50
/*+*********************************
*  PROTOTIPOS DE LOS SUBPROGRAMAS  *
*********************************+*/
int suma_par (int num,int vec[C]);
main()
/*+********************
*  PROGRAMA PRINCIPAL *
********************+*/
{
    int j, num, vec[C], suma;
    printf("\nHOLA\n\nESTE PROGRAMA TE VA A PEDIR 'n' NUMEROS,\nTE SUMARA LO NUMEROS PARES\nMOSTRANDOTE LOS NUMEROS INGRESADOS.\n");
    printf("\nDIGITE EL NUMERO DE NUMOERS QUE QUIERE INGRESAR. (MAXIMO 50)\n");
    scanf("%d%*c",&num);
    if(num>=1<=50)
    {
        for(j=0;j<num;j++)
        {
            printf("\nDIGITE EL VALOR %d: ",j+1);
            scanf("%d%*c",&vec[j]);
        }
        suma=suma_par (num,vec);
        printf("\n\nESTOS SON LOS NUMEROS QUE INGRESASTE.\n\n");
        for(j=0;j<num;j++)
        {
            printf(" %d ",vec[j]);
        }
        printf("\n\nLA SUMA DE LOS NUMEROS PARES DIGITADOS ES: %d\n\n",suma);
    }
}
/*+***************
*  SUBPROGRAMAS  *
***************+*/
int suma_par (int num,int vec[C])
{
    int resp, j;
    for(j=0,resp=0;j<num;j++)
    {
        if(vec[j]%2==0)
            resp=resp+vec[j];
    }
    return(resp);
}
